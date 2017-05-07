//usr/bin/env node --harmony $0 $@;exit
//http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
//http://nabetani.sakura.ne.jp/hena/ord24eliseq/

var isqrt=function(n){
	if(n<=0)return 0;
	if(n<4)return 1;
	var x=0,y=n;
	for(;x!=y&&x+1!=y;){x=y;y=Math.floor((Math.floor(n/y)+y)/2);}
	return x;
}
var icbrt=function(n){
	if(n<0)return icbrt(-n);
	if(n==0)return 0;
	if(n<8)return 1;
	var x=0,y=n;
	for(;x!=y&&x+1!=y;){x=y;y=Math.floor( (Math.floor(Math.floor(n/y)/y)+y*2)/3 );}
	return x;
}

var generate=function*(){
	var i=1;
	for(;;){
		yield i;
		i++;
	}
};

var drop_prev=function*(check,prev){
	//var {value: a}=prev.next(); //not working yet
	var a=prev.next().value;
	var b=prev.next().value;
	for(;;){
		if(!check(b))yield a;
		a=b;
		b=prev.next().value;
	}
};
var drop_next=function*(check,prev){
	var a=prev.next().value;
	var b=prev.next().value;
	yield a;
	for(;;){
		if(!check(a))yield b;
		a=b;
		b=prev.next().value;
	}
};
var drop_n=function*(check,n,prev){
	var i=0;
	for(;;){
		i+=1
		a=prev.next().value;
		if(!check(i,n))yield a;
	}
};

var is_sq=function(n){
	//var x=Math.sqrt(n)^0;
	var x=isqrt(n);
	return x*x==n;
};
var is_cb=function(n){
	//var x=cbrt(n)^0;
	var x=icbrt(n);
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

var solve=function(s){
	//cS => f['S'](f['c'](generate()))
	var z=s.split('').reduce(function(s,e){return f[e](s);},generate());
	var a=[];
	for(var j=0;j<10;j++)a[j]=z.next().value;
	return a.join(',');
}

//var cbrt=(typeof Math.cbrt==='function') ? Math.cbrt : function(n){return Math.pow(n,1-2/3);};

var main=function(){
	for(var line;line=readline();)print(solve(line));
}

/// IO ///
if(typeof process!=='undefined'){
	//node.js
	var print=function(x){
		console.log(x);
	}
	var readline=(function(){
		var T=[],cnt=0;
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
			main();
		});

		return function(){
			if(T.length<=cnt)return null;
			return T[cnt++];
		};
	})();
}else{
	//v8
	main();
}
