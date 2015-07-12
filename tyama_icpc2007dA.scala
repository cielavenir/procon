//usr/bin/env scala $0 $@;exit

object Main{
	def judge(n:Int){
		var ma=0;var mi=1000;var s=0
		for(i <- 0 until n){
			var x=Integer.parseInt(readLine())
			if(x<mi)mi=x
			if(x>ma)ma=x
			s+=x
		}
		printf("%d\n",(s-ma-mi)/(n-2))
	}

	def main(args: Array[String]){
		while(true){
			var n=Integer.parseInt(readLine())
			if(n==0)return
			judge(n)
		}
	}
}