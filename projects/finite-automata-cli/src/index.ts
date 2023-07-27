/* eslint-disable import-helpers/order-imports */
/* eslint-disable no-restricted-syntax */
import process from "node:process";

import { AutomataDTO } from "./dtos/automata";
import { Automata } from "./services/automata";
import { Output } from "./models";

const aut = process.argv[2];
const encoded = process.argv[3];
const output = process.argv[4];

if (!encoded || !aut || !output) {
  console.log("any word was informed... exiting");
  process.exit(1);
}

const automataInput = AutomataDTO.fromJson(aut);
const inputs = AutomataDTO.fromCsv(encoded);
const outputs: Output[] = [];

const automata = new Automata(automataInput);

for (const { input, expected } of inputs) {
  outputs.push({
    input,
    expected,
    obtained: automata.run(input),
    timeMilliseconds: "0ms",
  });
}

AutomataDTO.generateOutput(outputs);
console.table(outputs);
