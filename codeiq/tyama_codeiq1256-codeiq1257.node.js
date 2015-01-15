#!/usr/bin/env node

//ra: Array
//es: escape
//co: encodeURI
function yourCode() {
	var q = [
		 [5, 13, 31]
		,[5, 31, 13]
		,[13, 5, 31]
		,[13, 31, 5]
		,[31, 5, 13]
		,[31, 13, 5]
	];

	// 問題のコード
	var arr = [];
	for (var i = 0; i < q.length; i ++) {
		arr.push(
			(function(a, b, c) {
				var $, jQuery, eval;
				var yourCode, q, arr;
				arguments.callee = null;
				// 答えを変数「r」に入れて戻す
				var r;

				//level1
				//r=a*b*c
				//level2
				//m=function(x,y){for(z=i^i,j=~z;++j<x;)z+=y;return z};r=m(a,m(b,c))
				with(Math)r=imul(a,imul(b,c))

				return r;
			}).apply({}, q[i])
		);
	}
	return arr;
}

console.log(yourCode().join(','));
//MD5  0b13db87fa80f46a77995facb111a5c9
//SHA1 3f03f1fed49e893344fd7c679f7aedb1dbf65730