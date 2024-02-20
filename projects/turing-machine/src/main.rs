use std::collections::{HashMap, LinkedList};
use std::{fs, process};
use serde::Deserialize;

#[derive(Debug, Deserialize)]
struct Transition {
    from_state: Box<str>,
    read: char,
    write: char,
    to_state: Box<str>,
    move_direction: char,
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

fn process_turing_machine(mt: &TuringMachine) -> HashMap<String, TransitionValue> {
    let mut aa = HashMap::new();

    for b in &mt.transitions {
        aa.insert(Transition::key(b), Transition::value(b));
    }

    return aa;
}

fn process_tape(tape: &str) -> LinkedList<char> {
    let mut tapeLL: LinkedList<char> = LinkedList::new();

    for c in tape.chars() {
        tapeLL.push_back(c);
    }

    return tapeLL;
}

fn delta<'a>(s: &'a str, r: char, aa: &'a HashMap<String, TransitionValue>) -> &'a TransitionValue {
    let key = generate_key(s, r);

    match aa.get(&key) {
        Some(value) => value,
        None => process::exit(1) // Não tem transition, exit.
    }
}

fn main() {
    let mt = read_turing_machine("./tests/mt.json");
    let relation_state_transition = process_turing_machine(&mt);

    let tape = read_tape("./tests/tape.txt");
    let mut bb = &mut process_tape(&*tape);

    let mut current_state = &mt.initial_state;
    let mut iter = &mut bb.iter();

    let mut worker;

    for input in tape.chars() {
        worker = delta(&*current_state, input, &relation_state_transition);

        for aaaa in &mt.final_states {
            if (&worker.to_state == aaaa) {
                println!("Estado final");
                process::exit(0);
            }
        } // Se o to_state for igual a um dos estados finais, encerra

        if (worker.write == input) {
            if worker.move_direction == 'r' {
                println!("hello");
                // &iter.next();
            }

            if worker.move_direction == 'l' {
                println!("hello 2");
                // &iter.next_back();
            }
        } // Se o write for igual ao input, não precisa sobreescrever

        if (worker.write != input) {
            if worker.move_direction == 'r' {
                println!("hello 3");
                // &iter.next();
            }

            if worker.move_direction == 'l' {
                println!("hello 4");
                // &iter.next_back();
            }
        }

        bb.back_mut().replace(&mut 'H');

        println!("{:?}", bb);

        current_state = &worker.to_state;

        println!("Var: {:?}", worker);
    }
}
