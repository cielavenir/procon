fn getline() -> String{
	let mut __ret=String::new();
	std::io::stdin().read_line(&mut __ret).ok();
	return __ret;
}

fn main(){
	let mut s=getline();
	let n:i32=s.trim().parse().unwrap();
	for _ in 0..n {
		s=getline();
		let a:Vec<_>=s.trim().split(' ').collect();
		let y:i32=a[0].parse().unwrap();
		let m:i32=a[1].parse().unwrap();
		let d:i32=a[2].parse().unwrap();
		let mut r:i32=0;
		if y%3>0 {r=(m-1)/2;}
		println!("{}",196471-(y-1)*195-(y-1)/3*5-(m-1)*20+r-d);
	}
}