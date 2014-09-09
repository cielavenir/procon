#!/usr/bin/node --harmony
//http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
//http://nabetani.sakura.ne.jp/hena/ord24eliseq/

//分割代入ができないため、汚いコードになってしまっている
//ES6はまだ不安定であることだし、有限リストを扱うことはしないほうが良いだろう

function* generate(){
	var i=1;
	for(;;){
		yield i;
		i++;
	}
}

function* drop_prev(check,prev){
	var a=prev.next().value;
	var b=prev.next().value;
	for(;;){
		if(!check(b))yield a;
		a=b;
		b=prev.next().value;
	}
}
function* drop_next(check,prev){
	var a=prev.next().value;
	var b=prev.next().value;
	yield a;
	for(;;){
		if(!check(a))yield b;
		a=b;
		b=prev.next().value;
	}
}
function* drop_n(check,n,prev){
	var i=0;
	for(;;){
		i+=1
		a=prev.next().value;
		if(!check(i,n))yield a;
	}
}

var is_sq=function(n){
	var x=Math.sqrt(n)^0;
	return x*x==n;
};
var is_cb=function(n){
	var x=Math.cbrt(n)^0;
	return x*x*x==n;
};
var is_multiple=function(i,n){return i%n==0;};
var is_le=function(i,n){return i<=n;};

var f={
	S:function(_enum){return drop_next(is_sq,_enum);},
	s:function(_enum){return drop_prev(is_sq,_enum);},
	C:function(_enum){return drop_next(is_cb,_enum);},
	c:function(_enum){return drop_prev(is_cb,_enum);},
	h:function(_enum){return drop_n(is_le,100,_enum);},
};
for(var i=2;i<=9;i++){
	(function(){
		var j=i;
		f[String(j)]=function(_enum){return drop_n(is_multiple,j,_enum);};
	})()
}

function solve(s){
	//cS => f['S'](f['c'](generate()))
	var z=s.split('').reduce(function(s,e){return f[e](s);},generate());
	var a=[];
	for(var j=0;j<10;j++)a[j]=z.next().value;
	return a.join(',');
}

//main (IO)
var T=[];
var stdin = process.openStdin();
stdin.setEncoding('utf8');

var input_fragment="";
stdin.on('data', function(input) {
	var ref=(input_fragment+input).split("\n");
	input_fragment=ref.pop();
	for(var i=0;i<ref.length;i++){
		if(ref[i]=='')continue;
		T.push(ref[i]);
	}
});

stdin.on('end', function(z) {
	if(input_fragment){
		var ref=(input_fragment+"\n").split("\n");
		input_fragment=ref.pop();
		for(var i=0;i<ref.length;i++){
			if(ref[i]=='')continue;
			T.push(ref[i]);
		}
	}
	for(var i=0;i<T.length;i++)console.log(solve(T[i]));
});