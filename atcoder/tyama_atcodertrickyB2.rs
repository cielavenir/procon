use std::ffi::CString;
#[link="c"]
extern {
	fn scanf(format: *const i8, ...);
	fn printf(format: *const i8, ...);
}

fn getline() -> String{
        let mut __ret=String::new();
        std::io::stdin().read_line(&mut __ret).ok();
        return __ret;
}

fn main(){
	//let mut s=getline();
	let mut t:i32=0;
	//t=s.trim().parse().unwrap();
	unsafe{scanf(CString::new("%d").unwrap().as_ptr(),&t);}
	for _ in 0..t {
		//s=getline();
		//let _a:Vec<_>=s.trim().split(' ').collect();
		let mut a:i64=0;
		let mut b:i64=0;
		let mut c:i64=0;
		//a=_a[0].parse().unwrap();
		//b=_a[1].parse().unwrap();
		//c=_a[2].parse().unwrap();
		unsafe{scanf(CString::new("%lld%lld%lld").unwrap().as_ptr(),&a,&b,&c);}
		if a==0 {
			if b==0 {
				//println!("{}",if c!=0 {0} else {3});
				unsafe{printf(CString::new("%d\n").unwrap().as_ptr(),if c!=0 {0} else {3});}
			} else {
				//println!("1 {:.12}",-(c as f64)/(b as f64));
				unsafe{printf(CString::new("1 %.12f\n").unwrap().as_ptr(),-(c as f64)/(b as f64));}
			}
		}else{
			if a<0 {a=-a;b=-b;c=-c;}
			let d=(b as f64)*(b as f64)-4.0*(a as f64)*(c as f64);
			if d.abs()<1e-9 {
				//println!("1 {:.12}",-(b as f64)/2.0/(a as f64));
				unsafe{printf(CString::new("1 %.12f\n").unwrap().as_ptr(),-(b as f64)/2.0/(a as f64));}
			} else if d<0.0 {
				//println!("0");
				unsafe{printf(CString::new("0\n").unwrap().as_ptr());}
			}
			else{
				// acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
				let mut x=0.0;
				let mut y=0.0;
				if b>0 {
					x = (-(b as f64)-d.sqrt())/2.0/(a as f64);
					y = (c as f64)/(a as f64)/x;
				}else{
					y = (-(b as f64)+d.sqrt())/2.0/(a as f64);
					x = (c as f64)/(a as f64)/y;
				}
				//println!("2 {:.12} {:.12}",x,y);
				unsafe{printf(CString::new("2 %.12f %.12f\n").unwrap().as_ptr(),x,y);}
			}
		}
	}
}
