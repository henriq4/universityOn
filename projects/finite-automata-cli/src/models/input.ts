export interface AutomataInput {
  initial: number;
  final: Array<number>;
  transitions: {
    from: number;
    read: string;
    to: number;
  }[];
}

export interface Input {
  text: string;
  expected: boolean;
}
