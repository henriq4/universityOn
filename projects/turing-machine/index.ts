import fs from "fs";
import { Worker } from "worker_threads";

import { FromJsonToTuringMachine } from "./src/mappers/JsonToTuringMachine";
import { TuringMachineService } from "./src/services/TuringMachineService";

const aa = new TuringMachineService(
  FromJsonToTuringMachine.fromJson("./tests/mt.json"),
);

const tape1 = fs.readFileSync("./tests/tape-1.in", "utf-8").toString().trim();
const tape2 = fs.readFileSync("./tests/tape-2.in", "utf-8").toString().trim();
const tape3 = fs.readFileSync("./tests/tape-3.in", "utf-8").toString().trim();

console.log(aa.run(tape3));
