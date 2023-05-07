let table = new Map();

let initial_w = "q0"
let final_w = "q2"

table.set(
  "q0",
  new Map([
    ["a", "q1"],
    ["b", "q3"],
  ])
);

table.set(
  "q1",
  new Map([
    ["a", "q2"],
    ["b", "q3"],
  ])
);

table.set(
  "q2",
  new Map([
    ["a", "q2"],
    ["b", "q2"],
  ])
);

table.set(
  "q3",
  new Map([
    ["a", "q1"],
    ["b", "q2"],
  ])
);

export {
  table,
  initial_w,
  final_w
};
