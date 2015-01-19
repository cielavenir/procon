//tested on rustc 1.0alpha

fn getint() -> i32{
	let __res=std::io::stdin().read_line();
	let mut __str=__res.unwrap();
	let l=__str.len();
	__str.truncate(l-1);
	return std::num::from_str_radix(__str.as_slice(),10).unwrap();
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
	let mut n:i32=0;
	loop{
		n=getint();
		if n==0{break;}
		judge(n);
	}
}