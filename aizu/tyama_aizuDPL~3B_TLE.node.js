//usr/bin/env node --harmony $0 $@;exit
var main=function(){
	var arg=readline().split(' ').map(Number);
	var y=arg[0],x=arg[1];
	var m=Array(y);
	for(var j=0;j<y;j++){
		arg=readline().split(' ').map(Number);
		r=0;
		m[j]=Array(x);
		for(var i=0;i<x;m[j][i]=r,i++){
			r=arg[i]==0?r+1:0;
		}
	}
	var r=0;
	for(var i=0;i<x;i++)for(var j=0;j<y;j++)for(var M=x,k=j;k<y;k++){
		if(M>m[k][i])M=m[k][i];
		var z=k-j+1;
		if(r<M*z)r=M*z;
	}
	print(r);
}
// 制限時間厳しくないですか… //

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