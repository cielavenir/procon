//usr/bin/env node $0 $@;exit 
var main=function(){
	var a=readline().split(' ').map(Number);
	print(a[0]+a[1]+' '+readline());
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