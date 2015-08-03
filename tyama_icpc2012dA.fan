#!/usr/bin/env fan
class icpc2012dA{
	static Void main(){
		Int n:=Env.cur.in.readLine.toInt
		for(Int i:=0;i<n;i++){
			Int[] a:=Env.cur.in.readLine.split.map{it.toInt}
			a[0]-=1;a[1]-=1;
			echo(196471-a[0]*195-a[0]/3*5-a[1]*20+(a[0]%3!=2?a[1]/2:0)-a[2]);
		}
	}
}