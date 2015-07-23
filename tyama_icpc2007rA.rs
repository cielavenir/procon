fn getline() -> String{
	let mut __ret=String::new();
	std::io::stdin().read_line(&mut __ret).ok();
	return __ret;
}

fn main(){
	loop{
		let s=getline();
		let a:Vec<_>=s.trim().split(' ').collect();
		let n:i32=a[0].parse().unwrap();
		let k:i32=a[1].parse().unwrap();
		let m:i32=a[2].parse().unwrap();
		let mut r:i32=0;
		if n==0 {break;}
		for i in 1..n {r=(r+k)%i;}
		println!("{}",(r+m)%n+1);
	}
}