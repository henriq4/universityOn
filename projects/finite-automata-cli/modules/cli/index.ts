import inquirer from "inquirer";

export const answer = await inquirer.prompt([
  {
    message: "aaaaaaaaaa?",
    type: "input",
    name: "saber",
  },
  {
    message: "aaaaaaaaaa?",
    type: "input",
    name: "saber2",
  },
]);
