//usr/bin/env node $0 $@;exit
//https://gist.github.com/mtsmfm/4b8ffb53ffac055f5843

var N=8;
var fill_table=function(a,n){
	for(var st=0;st<N;st++){
		var i=0;
		for(;i<n;i++)if(a[(st+i)%N])break;
		if(i==n){
			for(i=0;i<n;i++)a[(st+i)%N]=1;
			return true;
		}
	}
	return false;
}
var clear_table=function(a){
	for(var i=0;i<N;i++){
		if(a[i]==4)a[i]=0;
	}
}
var take_turn=function(a){
	for(var i=0;i<N;i++){
		if(a[i])a[i]++;
	}
}
var test=function(s){
	var a=Array.apply(null,Array(N)).map(Number.prototype.valueOf,0);
	for(var i=0;i<s.length;i++){
		for(;;){
			clear_table(a);
			var f=fill_table(a,Number(s[i]));
			take_turn(a);
			if(f)break;
		}
	}
	return a.map(function(e){return Number(!!e);}).join('');
}
var main=function(){
	for(var s;s=readline();)print(test(s));
}
/// paste above to http://esm.xii.jp/ ///

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