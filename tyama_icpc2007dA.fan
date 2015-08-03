#!/usr/bin/env fan
class icpc2007dA{
	static Void main(){
		while(true){
			Int ma:=0
			Int mi:=1000
			Int sum:=0
			Int n:=Env.cur.in.readLine.toInt
			if(n==0)return
			for(Int i:=0;i<n;i++){
				Int s:=Env.cur.in.readLine.toInt
				ma=ma>s?ma:s
				mi=mi<s?mi:s
				sum+=s
			}
			echo((sum-ma-mi)/(n-2))
		}
	}
}