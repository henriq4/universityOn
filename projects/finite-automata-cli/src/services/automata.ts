/* eslint-disable @typescript-eslint/no-non-null-assertion */
import { AutomataModel } from "../models";
import { createStateName } from "../utils/createStateName";

export class Automata {
  constructor(private automata: AutomataModel) {}

  delta(state: number, symbol: string): number {
    const key = createStateName(state, symbol);

    if (this.automata.transitions.has(key)) {
      return this.automata.transitions.get(key)!;
    }

    return -1;
  }

  extendedTransition(state: number, input: string): number {
    if (input.length <= 0) {
      return state;
    }

    const letter: string = input[0];

    const nextState = this.delta(state, letter);

    if (nextState !== -1) {
      return this.extendedTransition(nextState, input.slice(1));
    }

    return -1;
  }

  run(input: string): 0 | 1 {
    const finalState = this.extendedTransition(this.automata.initial, input);
    return this.automata.final.has(finalState) === true ? 1 : 0;
  }
}
