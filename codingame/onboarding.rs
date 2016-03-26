use std::io;
macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}
fn main() {
	loop {
		let mut input_line = String::new();
		io::stdin().read_line(&mut input_line).unwrap();
		let enemy_1 = input_line.trim().to_string(); // name of enemy 1
		let mut input_line = String::new();
		io::stdin().read_line(&mut input_line).unwrap();
		let dist_1 = parse_input!(input_line, i32); // distance to enemy 1
		let mut input_line = String::new();
		io::stdin().read_line(&mut input_line).unwrap();
		let enemy_2 = input_line.trim().to_string(); // name of enemy 2
		let mut input_line = String::new();
		io::stdin().read_line(&mut input_line).unwrap();
		let dist_2 = parse_input!(input_line, i32); // distance to enemy 2

		println!("{}",if dist_1<dist_2 { enemy_1 } else { enemy_2 });
	}
}