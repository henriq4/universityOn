export interface Transitions {
  from: number;
  to: number;
  read: string;
  write: string;
  dir: "R" | "L";
}
