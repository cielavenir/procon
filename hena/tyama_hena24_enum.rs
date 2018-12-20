// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

#![feature(generators, generator_trait)]
use std::ops::{Generator, GeneratorState};

use std::io::BufRead;
use std::collections::HashMap;

type BoxGeneratorI32Send = Box<dyn Generator<Yield=i32,Return=()>+Send>;

fn isqrt(n:i32) -> i32{
	if n<=0 {
		return 0;
	}
	if n<4 {
		return 1;
	}
	let mut x=0;
	let mut y=n;
	while x!=y&&x+1!=y {
		x=y;
		y=(n/y+y)/2;
	}
	return x;
}

fn icbrt(n:i32) -> i32{
	if n<0 {
		return icbrt(-n);
	}
	if n==0 {
		return 0;
	}
	if n<8 {
		return 1;
	}
	let mut x=0;
	let mut y=n;
	while x!=y&&x+1!=y {
		x=y;
		y=(n/y/y+y*2)/3;
	}
	return x;
}

fn is_sq(n:i32) -> bool{
	let x=isqrt(n);
	return x*x==n;
}
fn is_cb(n:i32) -> bool{
	let x=icbrt(n);
	return x*x*x==n;
}
fn is_multiple(i:i32,n:i32) -> bool{i%n==0}
fn is_le(i:i32,n:i32) -> bool{i<=n}

fn next<T>(mut gen:impl Generator<Yield=T,Return=()>) -> Option<T>{
	// acknowledgement: https://github.com/tinaun/gen-iter/blob/master/src/lib.rs
	match unsafe {gen.resume()} {
		GeneratorState::Yielded(n) => Some(n),
		GeneratorState::Complete(_) => None,
	}
}

fn generate() -> BoxGeneratorI32Send{
	return Box::new(|| { // move is optional in this line
		let mut i=1;
		loop{
			yield i;
			i+=1;
		}
	});
}

fn drop_prev(check:fn(i32)->bool,mut prev:BoxGeneratorI32Send) -> BoxGeneratorI32Send{
	return Box::new(move || {
		let mut a=next(&mut prev).unwrap();
		let mut b=next(&mut prev).unwrap();
		loop{
			if !check(b) {
				yield a;
			}
			a=b;
			b=next(&mut prev).unwrap();
		}
	});
}

fn drop_next(check:fn(i32)->bool,mut prev:BoxGeneratorI32Send) -> BoxGeneratorI32Send{
	return Box::new(move || {
		let mut a=next(&mut prev).unwrap();
		let mut b=next(&mut prev).unwrap();
		yield a;
		loop{
			if !check(a) {
				yield b;
			}
			a=b;
			b=next(&mut prev).unwrap();
		}
	});
}

fn drop_n(check:fn(i32,i32)->bool,n:i32,mut prev:BoxGeneratorI32Send) -> BoxGeneratorI32Send{
	return Box::new(move || {
		let mut i=0;
		loop{
			i+=1;
			let a=next(&mut prev).unwrap();
			if !check(i,n) {
				yield a;
			}
		}
	});
}

fn main() {
	// cannot initialize Generator trait's HashMap using vec![].into_iter().collect() [E0277]
	let mut f:HashMap<char,fn(BoxGeneratorI32Send)->BoxGeneratorI32Send> = HashMap::new();
	f.insert('S',|e|{drop_next(is_sq,e)});
	f.insert('s',|e|{drop_prev(is_sq,e)});
	f.insert('C',|e|{drop_next(is_cb,e)});
	f.insert('c',|e|{drop_prev(is_cb,e)});
	f.insert('h',|e|{drop_n(is_le,100,e)});

	//due to complicated lifetime, for now I don't use for-loop here
	f.insert('2',|e|{drop_n(is_multiple,2,e)});
	f.insert('3',|e|{drop_n(is_multiple,3,e)});
	f.insert('4',|e|{drop_n(is_multiple,4,e)});
	f.insert('5',|e|{drop_n(is_multiple,5,e)});
	f.insert('6',|e|{drop_n(is_multiple,6,e)});
	f.insert('7',|e|{drop_n(is_multiple,7,e)});
	f.insert('8',|e|{drop_n(is_multiple,8,e)});
	f.insert('9',|e|{drop_n(is_multiple,9,e)});

	let stdin = std::io::stdin();
	for line in stdin.lock().lines() {
	match line {
		Ok(s) => {
			let mut z=generate();
			for c in s.trim().chars() {
				z=f[&c](z);
			}
			for i in 0..10 {
				if i>0 {
					print!(",");
				}
				print!("{}", next(&mut z).unwrap());
			}
			println!("");
		},
		Err(_) => ()
	}}
}
