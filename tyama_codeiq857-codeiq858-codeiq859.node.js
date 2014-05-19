#!/usr/bin/node

function yourCode() {
	// 問題用配列の作成
	var q = (function() {
		var a = n = [], s = ["a","b","c","d","g","u","bug"], r;
		for (var i = x = 0; i < 3200; i ++) {
			if (! n.length) n = s.concat();
			r = (x >> 16) & 32767;
			a.push(n.splice(r % n.length, 1));
			x = (x * 1103515245 + 12345)|0;
		}
		return a.join("").match(/.{16}/g);
	})();

	// 問題部分
	var arr = [];
	for (var i = 0; i < q.length; i ++) {
		arr.push(
			(function(t, q, i, arr) {
				//level1
				//return t.split('bug').join('000') //26
				//level2
				//return f=String.fromCharCode,t.split(f(98,117,103)).join(f(48,48,48)) //62
				//return t.split(String.fromCharCode(98,117,103)).join(String(0)+0+0) //60
				//level3
				//return f=String.fromCharCode,function(){for(j=0;j<t.length-2;j++)if(t.substr(j,3)==f(98,117,103))t=t.substr(0,j)+f(48,48,48)+t.substr(j+3);return t;}() //144
				return function(){for(j=0;j<t.length-2;j++)if(t.substr(j,3)==String.fromCharCode(98,117,103))t=t.substr(0,j)+String(0)+0+0+t.substr(j+3);return t;}() //142
			})(q[i])
		);
	}
	return arr;
}


console.log(yourCode().join(','));
//MD5  7cd8ad54618310a83456ba6ae8c34517
//SHA1 2c943ec9c660b35feb2339795748346c52390af2