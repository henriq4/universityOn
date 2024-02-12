use std::collections::{HashMap};
use std::fs;
use serde::Deserialize;

#[derive(Debug, Deserialize)]
struct Transition {
    from_state: Box<str>,
    read: char,
    write: char,
    to_state: Box<str>,
    move_direction: char,
}

#[derive(Debug, Deserialize)]
struct TuringMachine {
    states: Vec<Box<str>>,
    read_alphabet: Vec<char>,
    write_alphabet: Vec<char>,
    blank: char,
    initial_state: Box<str>,
    final_states: Vec<Box<str>>,
    transitions: Vec<Transition>,
}

#[derive(Debug, Deserialize)]
struct TransitionValue {
    write: char,
    to_state: Box<str>,
    move_direction: char,
}

fn read_turing_machine(file_path: &str) -> TuringMachine {
    let file = fs::File::open(file_path).expect("file should be read only");
    serde_json::from_reader(file).expect("JSON was not well-formatted")
}

fn read_tape(file_path: &str) -> String {
    fs::read_to_string(file_path).expect("Unable to read file")
}

fn generate_key(s: &str, r: char) -> String {
    format!("{}{}", s, r)
}

impl Transition {
    pub fn key(&self) -> String {
        generate_key(&*self.from_state, self.read)
    }

    pub fn value(&self) -> TransitionValue {
        TransitionValue {
            move_direction: self.move_direction,
            to_state: Box::from(&*self.to_state),
            write: self.write,
        }
    }
}

fn process_turing_machine(mt: &TuringMachine) -> HashMap<String, TransitionValue> {
    let mut aa = HashMap::new();

    for b in &mt.transitions {
        aa.insert(Transition::key(b), Transition::value(b));
    }

    return aa;
}

fn delta<'a>(s: &'a str, r: char, aa: &'a HashMap<String, TransitionValue>) -> &'a str {
    let key = generate_key(s, r);

    match aa.get(&key) {
        Some(value) => &*value.to_state,
        None => ""
    }
}

fn main() {
    let tape = read_tape("./tests/tape.txt");
    let mt = read_turing_machine("./tests/mt.json");

    let aa = process_turing_machine(&mt);

    let mut state = mt.initial_state;

    for b in tape.chars() {
        delta(&*state, b, &aa);
    }
}