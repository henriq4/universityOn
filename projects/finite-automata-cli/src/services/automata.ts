/* eslint-disable no-restricted-syntax */
import { AutomataModel } from "../models";
import { createStateName } from "../utils/createStateName";

export class Automata {
  constructor(private automata: AutomataModel) {}

  delta(state: number, symbol: string): number[] | -1 {
    const key = createStateName(state, symbol);

    if (this.automata.transitions.has(key) === false) {
      return -1;
    }

    return this.automata.transitions.get(key)!;
  }

  extendedTransition(state: number, input: string): number {
    if (input.length <= 0) {
      return state;
    }

    const letter: string = input[0];

    const nextStates = this.delta(state, letter);

    if (nextStates === -1) return -1;

    for (const nextState of nextStates) {
      if (input.length === 1) {
        for (const r of nextStates) {
          if (this.automata.final.has(r) === true) {
            return r;
          }
        }
      }

      const result = this.extendedTransition(nextState, input.slice(1));
      if (result !== -1) {
        return result;
      }
    }

    return -1;
  }

  run(input: string): { obtained: 0 | 1; timeMilliseconds: number } {
    const startTime = process.hrtime();
    const finalState = this.extendedTransition(this.automata.initial, input);

    const endTime = process.hrtime(startTime);
    const elapsedTimeInMs = endTime[0] * 1000 + endTime[1] / 1000000;

    return {
      obtained: this.automata.final.has(finalState) === true ? 1 : 0,
      timeMilliseconds: elapsedTimeInMs,
    };
  }
}
