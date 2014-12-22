#!/usr/bin/node

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
		for (var i = 0; i < 2000; i ++) {
			var top = rnd() % 90 + 10;
			var typ = rnd() % 2;
			var mv  = rnd() % 9 + 1;
			var nxt = typ == 0 ? (top + mv) : (top * mv);
			a.push([top, nxt]);
		}
		return a;
	})();

	// 問題部分
	var arr = [];
	for (var i = 0; i < q.length; i ++) {
		arr.push(
			(function(a, b) {
				var q, i, arr, yourCode;
				//Level1
				//return b-a>9?b*b/a:b+b-a //17
				//return b%a?2*b-a:b*b/a //15
				//Level2
				//return function(){for(;b-a>9;)return b*b/a;return b+b-a}() //51
				//return function(){for(;b%a;)return b*b/a;return b+b-a}() //49
				//return [b*b/a,2*b-a][b<2*a^0] //22
				//Level3
				//return function(){for(;b<2*a;)return Array(b).slice(a).concat(Array(b)).length;return b*b/a}() //87
				//return function(){for(;b%a;)return Array(2*b).slice(a).length;return b*b/a}() //70
				//return function(){for(t=b*b/a;b%a;b=0)t=Array(2*b).slice(a).length;return t}() //71
				return [b*b/a,Array(2*b).slice(a).length][b<2*a^0] //43
			})(q[i][0], q[i][1])
		);
	}
	return arr;
}

console.log(yourCode().join(','));
//MD5  b41bc507ab6fbe8f227fa22a622d83e5
//SHA1 f91d12d729063276cd917dad962e5b3d28a54be2