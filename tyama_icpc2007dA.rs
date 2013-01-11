//tested on rustc 0.2
import core::io::reader_util;
import core::io::writer_util;

fn getint() -> int{
	ret option::get(int::from_str(core::io::stdin().read_line()));
}

fn judge(n:int){
	let mut ma:int=0,mi:int=1000,s:int=0,i:int=0;
	while i<n{
		let x:int=getint();
		if x<mi{mi=x;}
		if x>ma{ma=x;}
		s+=x;
		i+=1;
	}
	//although there is println function, let's do in primitive way.
	core::io::stdout().write_line(#fmt("%d",(s-ma-mi)/(n-2)));
}

fn main(){
	let mut n:int=0;
	while true{
		n=getint();
		if n==0{break;}
		judge(n);
	}
}