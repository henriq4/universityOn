import { Transitions } from "./Transitions";

export interface TuringMachine {
  initial: number;
  final: number[];
  white: string;
  transitions: Transitions[];
}
