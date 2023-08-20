/* eslint-disable no-continue */
/* eslint-disable eqeqeq */
/* eslint-disable import-helpers/order-imports */
/* eslint-disable guard-for-in */
/* eslint-disable no-restricted-syntax */
/* eslint-disable no-empty */
import fs from "node:fs";

import { AutomataModel, AutomataInput, Input, Output } from "../models";
import { createStateName } from "../utils/createStateName";

export class AutomataDTO {
  static fromJson(automataPath: string): AutomataModel {
    const automata: AutomataInput = JSON.parse(
      fs.readFileSync(automataPath, "utf-8").toString(),
    );

    const alphabet: Set<string> = new Set();

    for (const transition in automata.transitions) {
      if (automata.transitions[transition].read === null) {
        continue;
      }

      alphabet.add(automata.transitions[transition].read!);
    }

    const final: Set<number> = new Set();
    const transitions: Map<string, number[]> = new Map();

    const epsolonTransitions: Map<string, number[]> = new Map();

    for (const f in automata.final) {
      final.add(automata.final[f]);
    }

    function getEpsilonClosure(state: number): number[] {
      const epsilonStates: number[] = [];
      const visited: Record<number, boolean> = {};
      const queue: number[] = [state];

      while (queue.length > 0) {
        const currentState = queue.shift()!;
        visited[currentState] = true;
        epsilonStates.push(currentState);

        const epsilonTransitions = automata.transitions.filter(
          t => t.from === currentState && t.read === null,
        );
        for (const transition of epsilonTransitions) {
          if (!visited[transition.to]) {
            queue.push(transition.to);
            visited[transition.to] = true;
          }
        }
      }

      return epsilonStates;
    }

    for (const transition in automata.transitions) {
      if (automata.transitions[transition].read === null) {
        const { from } = automata.transitions[transition];
        const { to } = automata.transitions[transition];

        console.log(to);

        getEpsilonClosure(from).forEach(state => {
          if (epsolonTransitions.has(state.toString())) {
            epsolonTransitions.get(state.toString())!.push(to);
            return;
          }

          epsolonTransitions.set(state.toString(), [to]);
        });

        continue;
      }

      const state = createStateName(
        automata.transitions[transition].from,
        automata.transitions[transition].read!,
      );

      const { to } = automata.transitions[transition];

      if (transitions.has(state)) {
        transitions.get(state)!.push(to);
        continue;
      }

      transitions.set(state, [to]);
    }

    console.log("E", epsolonTransitions);
    console.log("T", transitions);

    return {
      initial: automata.initial,
      final,
      transitions,
    };
  }

  static fromCsv(inputPath: string): Input[] {
    const inputs: Input[] = [];

    const inputRaw: string = fs.readFileSync(inputPath, "utf-8").toString();

    const lines = inputRaw.trim().split("\n");

    for (const line in lines) {
      const [input, expectedStr] = lines[line].split(";");

      const expected = expectedStr.trim() === "1" ? 1 : 0;

      inputs.push({ input, expected });
    }

    return inputs;
  }

  static generateOutput(outputs: Output[], outputPath: string): void {
    let content = "";

    for (const output in outputs) {
      content += `${outputs[output].input};${outputs[output].expected};${outputs[output].obtained};${outputs[output].timeMilliseconds}\n`;
    }

    fs.writeFileSync(outputPath, content);
  }
}
