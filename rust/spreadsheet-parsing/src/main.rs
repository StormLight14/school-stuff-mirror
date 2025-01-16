use std::fs::read_to_string;

fn main() {
    let spreadsheet_file = match read_to_string("cs2550_people.tsv") {
        Ok(file) => file,
        Err(why) => {
            println!("There was an error reading the spreadsheet file: {:?}", why);
            return;
        }
    };

    let mut people: Vec<Vec<String>> = Vec::new();

    for (i, line) in spreadsheet_file.lines().enumerate() {
        if i == 0 {
            continue; // don't add column titles
        }

        let mut person: Vec<String> = Vec::new();

        for item in line.split("\t") { // split by tabs
            person.push(item.to_string());
        }

        people.push(person);
    }

    let mut names: Vec<&str> = Vec::new();
    
    println!("People who have any type of green as their favorite color: ");
    for person in people.iter() {
        if person[4].to_ascii_lowercase().contains("green") {
            println!("{}", person[0]);
        }

        names.push(&person[0]);
    }
    
    println!("\nNames in alphabetical order:");
    names.sort_by(|a, b| a.to_lowercase().cmp(&b.to_lowercase()));
    for (i, name) in names.iter().enumerate() {
        println!("{}. {}", i+1, name);
    }

    println!("\nPeople who have children:");
    for person in people.iter() {
        if person[5] != "0" && !person[5].to_lowercase().contains("none") {
            println!("{} has {} child(ren).", person[0], person[5]);
        }
    }
}
