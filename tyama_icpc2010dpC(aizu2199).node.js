//usr/bin/env node $0 $@;exit 
var main=function(){
	var INF=1<<30;
	var arg;
	for(;(arg=readline().split(' ').map(Number))[0];){
		var n=arg[0],m=arg[1];
		var c=[];
		for(var i=0;i<m;i++)c[i]=Number(readline());
		var prev=[];
		for(var i=0;i<256;i++)prev[i]=INF;
		prev[128]=0;
		var cur=[];
		for(var i=0;i<n;i++){
			var x=Number(readline());
			for(var j=0;j<256;j++)cur[j]=INF;
			for(var j=0;j<256;j++)if(prev[j]<INF){
				for(var k=0;k<m;k++){
					var t=Math.min(255,Math.max(0,j+c[k]));
					var y=prev[j]+(x-t)*(x-t);
					cur[t]=Math.min(cur[t],y);
				}
			}
			var t=prev;prev=cur;cur=t;
		}
		print(Math.min.apply(null,prev));
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