#!/usr/bin/env rdmd
// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

import std.stdio,std.string,std.math;
import std.algorithm,std.concurrency;

int isqrt(int n){
	if(n<=0)return 0;
	if(n<4)return 1;
	int x=0,y=n;
	for(;x!=y&&x+1!=y;)x=y,y=(n/y+y)/2;
	return x;
}
int icbrt(int n){
	if(n<0)return icbrt(-n);
	if(n==0)return 0;
	if(n<8)return 1;
	int x=0,y=n;
	for(;x!=y&&x+1!=y;)x=y,y=(n/y/y+y*2)/3;
	return x;
}

auto generate(){
	return new Generator!int({
		int i=1;
		for(;;){
			yield(i);
			i+=1;
		}
	});
}
auto drop_prev(bool delegate(int) check,Generator!int prev){
	return new Generator!int({
		int a=prev.front;
		prev.popFront();
		int b=prev.front;
		for(;;){
			if(!check(b))yield(a);
			a=b;
			prev.popFront();
			b=prev.front;
		}
	});
}
auto drop_next(bool delegate(int) check,Generator!int prev){
	return new Generator!int({
		int a=prev.front;
		prev.popFront();
		int b=prev.front;
		yield(a);
		for(;;){
			if(!check(a))yield(b);
			a=b;
			prev.popFront();
			b=prev.front;
		}
	});
}
auto drop_n(bool delegate(int,int) check,int n,Generator!int prev){
	return new Generator!int({
		int i=0;
		for(;;){
			i++;
			int a=prev.front;
			if(!check(i,n))yield(a);
			prev.popFront();
		}
	});
}

void main(){
	bool is_sq(int n){
		//int x=cast(int)sqrt(cast(real)n);
		int x=isqrt(n);
		return x*x==n;
	}
	bool is_cb(int n){
		//int x=cast(int)cbrt(cast(real)n);
		int x=icbrt(n);
		return x*x*x==n;
	}
	bool is_multiple(int i,int n){return i%n==0;}
	bool is_le(int i,int n){return i<=n;}

	Generator!int delegate(Generator!int)[char] f=[
		'S':e => drop_next(&is_sq,e),
		's':e => drop_prev(&is_sq,e),
		'C':e => drop_next(&is_cb,e),
		'c':e => drop_prev(&is_cb,e),
		'h':e => drop_n(&is_le,100,e),
	];
	for(int i=2;i<10;i++){
		f[cast(char)('0'+i)] = delegate(int i){return (Generator!int e)=>drop_n(&is_multiple,i,e);}(i);
	}
	string line;
	for(;(line=stdin.readln()) !is null;){
		line=chomp(line);
		bool first=true;
		//cS => f['S'](f['c'](generate()))
		//auto z=reduce!((s,e)=>f[e](s))(generate(),line);

		auto z=generate();
		foreach(char e;line)z=f[e](z);

		for(int i=0;i<10;i++){
			int n=z.front;
			z.popFront();
			if(!first)write(',');
			first=false;
			write(n);
		}
		writeln();
		stdout.flush();
	}
}
