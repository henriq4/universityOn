/* eslint-disable eqeqeq */
/* eslint-disable import-helpers/order-imports */
/* eslint-disable guard-for-in */
/* eslint-disable no-console */
/* eslint-disable no-restricted-syntax */
/* eslint-disable no-empty */
import fs from "node:fs";

import { AutomataModel, AutomataInput, Input, Output } from "../models";
import { createStateName } from "../utils/createStateName";

export class AutomataDTO {
  static fromJson(automataPath: string): AutomataModel {
    const automata: AutomataInput = JSON.parse(
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

    for (const f in automata.final) {
      final.add(automata.final[f]);
    }

    for (const transition in automata.transitions) {
      transitions.set(
        createStateName(
          automata.transitions[transition].from,
          automata.transitions[transition].read,
        ),
        automata.transitions[transition].to,
      );
    }

    return {
      initial: automata.initial,
      final,
      transitions,
    };
  }

  static fromCsv(inputPath: string): Input[] {
    const inputs: Input[] = [];

    const inputRaw: string = fs
      .readFileSync(
        "/home/henriq/code/universityOn/projects/finite-automata-cli/src/input/ex1/ex1_input.in",
        // inputPath,
        "utf-8",
      )
      .toString();

    const lines = inputRaw.trim().split("\n");

    for (const line in lines) {
      const [input, expectedStr] = lines[line].split(";");

      const expected = expectedStr.trim() === "1" ? 1 : 0;

      inputs.push({ input, expected });
    }

    return inputs;
  }

  static generateOutput(outputs: Output[]): void {
    let content = "";

    for (const output in outputs) {
      content += `${outputs[output].input};${outputs[output].expected};${outputs[output].obtained};${outputs[output].timeMilliseconds}\n`;
    }

    fs.writeFileSync(
      "/home/henriq/code/universityOn/projects/finite-automata-cli/src/output/output.out",
      content,
    );
  }
}
