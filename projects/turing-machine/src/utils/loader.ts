import { question } from "readline-sync";

import { Loader } from "../models/Loader";

export function loader(): Loader {
  const turingMachinePath = question("Path da Máquina de Turing: ");
  const tapePath = question("Path da fita: ");

  return {
    turingMachinePath,
    tapePath,
  };
}
