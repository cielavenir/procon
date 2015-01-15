#!/usr/bin/env node

function yourCode() {
	// 問題用配列の作成
	var q = (function() {
		var rnd = (function(x) {
			return function() {
				x = (x * 1103515245 + 12345)|0;
				return (x >> 16) & 32767;
			}
		})(123456789);

		var a = [];
		for (var i = 0; i < 1000; i ++) {
			var n = rnd() % 800 + 100;
			var a2 = [0,0,0,0,0]
			.map(function() {
				n += rnd() % 8 + 1;
				return [n, rnd()];
			})
			.sort(function(a, b) {
				return a[1] - b[1];
			})
			.map(function(e) {
				return e[0];
			});
			a.push(a2);
		}
		return a;
	})();

	// 問題部分
	var arr = [];
	for (var i = 0; i < q.length; i ++) {
		arr.push(
			(function(a, b, c, d, e) {
				var q, i, arr, yourCode;
				//level1
				//return [a,b,c,d,e].sort()[2]
				//level2
				return function(){z=[a,b,c,d,e];for(i=5;i--;)for(j=5;j--;)if(z[i]>z[j])t=z[i],z[i]=z[j],z[j]=t;return z[2]}()
			}).apply(null, q[i])
		);
	}

	return arr;
}

console.log(yourCode().join(','));
//MD5  341c361370f9d3084eb789254da073f3
//SHA1 bfbac69fd1c734c2b9fd31b4470bf1cc3a25f933