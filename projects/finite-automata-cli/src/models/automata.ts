export interface AutomataModel {
  initial: number;
  final: Set<number>;
  transitions: Map<string, number[]>;
}
