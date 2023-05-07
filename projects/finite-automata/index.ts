import process from "node:process";

import {table, final_w, initial_w} from "./table";

const encoded = process.argv[2];

if (!encoded) {
  console.log("not informed word");
  process.exit(1);
}

function delta(w: string, state: string): any {
  if (w.length <= 0) {
    return state;
  }

  let letter: string = w[0];
  let newState = table.get(state).get(letter);

  switch (letter) {
    case "a":
      return delta(w.slice(1), newState);
    case "b":
      return delta(w.slice(1), newState);
    default:
      console.log("error");
      process.exit(2);
  }
}

const f_state = delta(encoded, initial_w);

f_state === final_w
  ? console.log("match! final state: " + f_state)
  : console.log("don't match, final state: " + f_state)
