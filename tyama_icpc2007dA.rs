//tested on rustc 1.0.0

fn getint() -> i32{
	let mut __str=String::new();
	std::io::stdin().read_line(&mut __str);
	let l=__str.len();
	__str.truncate(l-1);
	return i32::from_str_radix(&__str,10).unwrap();
}

fn judge(n:i32){
	let mut ma:i32=0;
	let mut mi:i32=1000;
	let mut s:i32=0;
	let mut i:i32=0;
	while i<n{
		let x:i32=getint();
		if x<mi{mi=x;}
		if x>ma{ma=x;}
		s+=x;
		i+=1;
	}
	println!("{}",(s-ma-mi)/(n-2));
}

fn main(){
	loop{
		let n=getint();
		if n==0{break;}
		judge(n);
	}
}