import fs from "fs";

import { FromJsonToTuringMachine } from "./mappers/JsonToTuringMachine";
import { TuringMachineService } from "./services/TuringMachineService";
import { loader } from "./utils/loader";

export default function main() {
  const { tapePath, turingMachinePath } = loader();

  const machine = new TuringMachineService(
    FromJsonToTuringMachine.fromJson(turingMachinePath),
  );

  const tape = fs.readFileSync(tapePath, "utf-8").toString().trim();

  return machine.execute(tape);
}
