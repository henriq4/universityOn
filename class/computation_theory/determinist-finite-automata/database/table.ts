let table = new Map();

let initial_w = "q0"
let final_w = "q2"

let alphabet = ["a", "b"]

table.set(
  "q0",
  new Map([
    [alphabet[0], "q1"],
    [alphabet[1], "q3"],
  ])
);

table.set(
  "q1",
  new Map([
    [alphabet[0], "q2"],
    [alphabet[1], "q3"],
  ])
);

table.set(
  "q2",
  new Map([
    [alphabet[0], "q2"],
    [alphabet[1], "q2"],
  ])
);

table.set(
  "q3",
  new Map([
    [alphabet[0], "q1"],
    [alphabet[1], "q2"],
  ])
);

export {
  table,
  alphabet,
  initial_w,
  final_w
};
