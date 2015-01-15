#!/usr/bin/env node

function yourCode() {
	var arr = [];
	for (var i = 0; i < 1000; i ++) {
		arr.push(
			(function() {
				var $, jQuery, eval;
				var yourCode, arr;
				arguments.callee = null;

				// 答えを変数「r」に入れて戻す
				var r;
				//level1
//for(j=i,r=i?'':'00';j;j=j/10^0)r=[j/5&1]+j%5+r //46
//j=i,r='';do r=[j/5&1]+j%5+r,j=j/10^0;while(j); //46
//for(x in i+=r='')r+=[i[x]/5&1]+i[x]%5 //37
				//level2
				//71
r=[i/5&1]+i%5
j=i/10^0
r=j?[j/5&1]+j%5+r:r
j=j/10^0
r=j?[j/5&1]+j%5+r:r
				//				
				return r;
			}).apply({})
		);
	}
	return arr;
}

console.log(yourCode().join(','));
//MD5  0b13db87fa80f46a77995facb111a5c9
//SHA1 3f03f1fed49e893344fd7c679f7aedb1dbf65730