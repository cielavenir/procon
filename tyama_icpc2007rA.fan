#!/usr/bin/env fan
class icpc2007rA{
	static Void main(){
		while(true){
			Int[] a:=Env.cur.in.readLine.split.map{it.toInt}
			Int n:=a[0]
			Int k:=a[1]
			Int m:=a[2]
			if(n==0)return
			Int r:=1
			for(Int i:=1;i<n;i++)r=(r+k)%i
			echo((r+m)%n+1)
		}
	}
}