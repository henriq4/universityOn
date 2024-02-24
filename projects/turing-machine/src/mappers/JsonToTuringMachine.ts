import fs from "fs";

import { TuringMachine } from "../models/TuringMachine";

export class FromJsonToTuringMachine {
  static fromJson(path: string): TuringMachine {
    const tm: TuringMachine = JSON.parse(
      fs.readFileSync(path, "utf-8").toString(),
    );

    return tm;
  }
}
