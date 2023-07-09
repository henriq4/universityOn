/* eslint-disable no-unused-expressions */
/* eslint-disable no-console */
import process from "node:process";

import { table, final_w, initial_w, alphabet } from "./database/table";

const encoded = process.argv[2];

if (!encoded) {
  console.log("any word was informed... exiting");
  process.exit(1);
}

function delta(w: string, state: string): any {
  if (w.length <= 0) {
    return state;
  }

  const letter: string = w[0];
  const newState = table.get(state).get(letter);

  if (alphabet.includes(letter)) {
    return delta(w.slice(1), newState);
  }

  console.log("exception: letter don't containg in alphabet");
  return process.exit(2);
}

const f_state = delta(encoded, initial_w);

f_state === final_w
  ? console.log(`match! final state: ${f_state}`)
  : console.log(`don't match, final state: ${f_state}`);
