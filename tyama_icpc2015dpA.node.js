//usr/bin/env node $0 $@;exit
var hypot=function(a,b){
	//return Math.hypot(a,b);
	return Math.sqrt(a*a+b*b);
}
var main=function(){
	var arg;
	for(;(arg=readline().split(' ').map(Number))[0];){
		var a=arg[0],b=arg[1];
		print(Math.min.apply(null,Array.apply(null,{length:1+(a/2^0)}).map(function(_,i){return Math.abs(b-hypot(i,a-i));})));
	}
};

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