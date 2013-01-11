#!/usr/bin/groovy

//2007 Domestic A
def judge(int n,Scanner z){ //no global vars
	int ma=0,mi=1000,s=0
	(1..n).each{
		int x=z.nextInt()
		if(x<mi)mi=x
		if(x>ma)ma=x
		s+=x
	}
	println((int)((s-ma-mi)/(n-2)))
}

Scanner z=new Scanner(System.in)
while(true){
	int n=z.nextInt()
	if(n==0)break
	judge(n,z)
}

/*
class Main{
	static Scanner z=new Scanner(System.in)

	static def judge(int n){
		int ma=0
		int mi=1000
		int s=0
		(1..n).each{
			int x=z.nextInt()
			if(x<mi)mi=x
			if(x>ma)ma=x
			s+=x
		}
		println((s-ma-mi)/(n-2))
	}

	static def main(){
		while(true){
			int n=z.nextInt()
			if(n==0)break
			judge(n)
		}
	}
}

Main.main()
*/