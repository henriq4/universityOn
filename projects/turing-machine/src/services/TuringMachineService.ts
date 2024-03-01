/* eslint-disable no-loop-func */
import { TuringMachine } from "../models/TuringMachine";

export class TuringMachineService {
  constructor(private turingMachine: TuringMachine) {}

  execute(input: string): boolean {
    const tape = input.split("");

    let head = 0;
    let state = this.turingMachine.initial;

    while (!this.turingMachine.final.includes(state)) {
      const current = tape[head] || this.turingMachine.white;

      const transition = this.turingMachine.transitions.find(
        t => t.from === state && t.read === current,
      );

      if (!transition) {
        return false;
      }

      tape[head] = transition.write;
      state = transition.to;

      head = transition.dir === "R" ? head + 1 : head - 1;
    }

    return true;
  }
}
