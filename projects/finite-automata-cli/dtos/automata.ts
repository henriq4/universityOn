/* eslint-disable no-continue, no-restricted-syntax, guard-for-in */
import { Automata } from "../models/automata.js";

export class AutomataDTO {
  automata: Automata;

  constructor(automata: Automata) {
    this.automata = automata;
  }

  createAlphabet(): string | null {
    const alphabet: Array<string | null> = [];
    const { transitions } = this.automata;

    for (const t in transitions) {
      const c = transitions[t].read;

      if (alphabet.find(e => e === null)) {
        this.automata.hasEmptyElement = true;
      }

      if (alphabet.find(e => e === c)) {
        continue;
      }

      alphabet[t] = c;
    }

    return alphabet.join("");
  }

  toMap(): Automata {
    return {
      initial: this.automata.initial,
      final: this.automata.final,
      transitions: this.automata.transitions,
      alphabet: this.createAlphabet(),
      hasEmptyElement: this.automata.hasEmptyElement,
    };
  }
}
