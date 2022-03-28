// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

//#![feature(generators, generator_trait)]
//use std::ops::{Generator, GeneratorState};
//type BoxGeneratorI64Send = Box<dyn Generator<Yield=i64,Return=()>+Unpin+Send>;

type BoxFnMutI64 = Box<dyn FnMut()->i64>;

use std::io::BufRead;

fn isqrt(n:i64) -> i64{
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

fn icbrt(n:i64) -> i64{
	if n<0 {
		return -icbrt(-n);
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

fn is_sq(n:i64) -> bool{
	let x=isqrt(n);
	return x*x==n;
}
fn is_cb(n:i64) -> bool{
	let x=icbrt(n);
	return x*x*x==n;
}
fn is_multiple(i:i64,n:i64) -> bool{i%n==0}
fn is_le(i:i64,n:i64) -> bool{i<=n}

/*
fn next<T>(mut gen:impl Generator<Yield=T,Return=()>+Unpin) -> Option<T>{
	// acknowledgement: https://github.com/tinaun/gen-iter/blob/master/src/lib.rs
	match std::pin::Pin::new(&mut gen).resume(()) {
		GeneratorState::Yielded(n) => Some(n),
		GeneratorState::Complete(_) => None,
	}
}

fn generate() -> BoxGeneratorI64Send{
	return Box::new(move || { // move is optional in this line
		let mut i=1;
		loop{
			yield i;
			i+=1;
		}
	});
}

fn drop_prev(check:fn(i64)->bool,mut prev:BoxGeneratorI64Send) -> BoxGeneratorI64Send{
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

fn drop_next(check:fn(i64)->bool,mut prev:BoxGeneratorI64Send) -> BoxGeneratorI64Send{
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

fn drop_n(check:fn(i64,i64)->bool,n:i64,mut prev:BoxGeneratorI64Send) -> BoxGeneratorI64Send{
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
*/

fn generate() -> BoxFnMutI64{
	let mut i=0;
	return Box::new(move || {
		i+=1;
		return i
	})
}

fn drop_prev(check:fn(i64)->bool,mut prev:BoxFnMutI64) -> BoxFnMutI64{
	let mut a = 0;
	let mut b = prev();
	return Box::new(move || {
		loop {
			a = b;
			b = prev();
			if !check(b) {
				return a
			}
		}
	})
}

fn drop_next(check:fn(i64)->bool,mut prev:BoxFnMutI64) -> BoxFnMutI64{
	let mut first = true;
	let mut a = 0;
	let mut b = 0;
	return Box::new(move || {
		loop {
			a = b;
			b = prev();
			if first || !check(a) {
				first = false;
				return b
			}
		}
	})
}

fn drop_n(check:fn(i64,i64)->bool,n:i64,mut prev:BoxFnMutI64) -> BoxFnMutI64{
	let mut i=0;
	return Box::new(move || {
		loop{
			i+=1;
			let a=prev();
			if !check(i,n) {
				return a
			}
		}
	})
}

fn main() {
	// cannot initialize Generator trait's HashMap using vec![].into_iter().collect() [E0277]
	let mut f:std::collections::HashMap<char,fn(BoxFnMutI64)->BoxFnMutI64> = std::collections::HashMap::new();
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
				print!("{}", z()); // next(&mut z).unwrap());
			}
			println!("");
		},
		Err(_) => ()
	}}
}
