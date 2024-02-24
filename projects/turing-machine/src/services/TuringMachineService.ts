import { TuringMachine } from "../models/TuringMachine";

export class TuringMachineService {
  constructor(private turingMachine: TuringMachine) {}

  run(input: string): boolean {
    const tape = input.split("");
    let head = 0;
    let state = this.turingMachine.initial;

    while (!this.turingMachine.final.includes(state) && tape[head]) {
      const current = tape[head];
      const transition = this.turingMachine.transitions.find(
        // eslint-disable-next-line no-loop-func
        t => t.from === state && t.read === current,
      );

      if (!transition) {
        return false;
      }

      tape[head] = transition.write;
      state = transition.to;

      if (transition.dir === "R") {
        head += 1;
      } else {
        head -= 1;
      }
    }

    return true;
  }
}
