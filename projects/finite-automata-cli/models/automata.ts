import { Transitions } from "./transition.js";

export interface Automata {
  initial: number;
  final: number[];
  transitions: Transitions[];
  alphabet?: string | null;
  hasEmptyElement: boolean;
}
