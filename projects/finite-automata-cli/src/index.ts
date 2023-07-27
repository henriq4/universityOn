/* eslint-disable import-helpers/order-imports */
/* eslint-disable no-restricted-syntax */
import process from "node:process";

import { AutomataDTO } from "./dtos/automata";
import { Automata } from "./services/automata";

const aut = process.argv[2];
const encoded = process.argv[3];

if (!encoded || !aut) {
  console.log("any word was informed... exiting");
  process.exit(1);
}

const automataDTO = AutomataDTO.fromJson(aut);
const inputs = AutomataDTO.fromCsv(aut);

const automata = new Automata(automataDTO);

for (const { input, expected } of inputs) {
  console.table({
    input,
    result: automata.run(input),
    expected,
  });
}
