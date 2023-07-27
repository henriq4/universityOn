/* eslint-disable eqeqeq */
/* eslint-disable import-helpers/order-imports */
/* eslint-disable guard-for-in */
/* eslint-disable no-console */
/* eslint-disable no-restricted-syntax */
/* eslint-disable no-empty */
import fs from "node:fs";

import { AutomataModel, AutomataInput } from "../models";
import { createStateName } from "../utils/createStateName";

export class AutomataDTO {
  static fromJson(automataPath: string): AutomataModel {
    const aut: AutomataInput = JSON.parse(
      fs
        .readFileSync(
          "/home/henriq/code/universityOn/projects/finite-automata-cli/src/input/ex1/ex1.aut",
          // automataPath,
          "utf-8",
        )
        .toString(),
    );

    const final: Set<number> = new Set();
    const transitions = new Map();

    for (const f in aut.final) {
      final.add(aut.final[f]);
    }

    for (const transition in aut.transitions) {
      transitions.set(
        createStateName(
          aut.transitions[transition].from,
          aut.transitions[transition].read,
        ),
        aut.transitions[transition].to,
      );
    }

    return {
      initial: aut.initial,
      final,
      transitions,
    };
  }
}
