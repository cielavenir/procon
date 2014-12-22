#!/usr/bin/node

function yourCode() {
	// 問題用配列の作成
	var q = n = [], s = "123456789".split(""), r;
	for (var i = x = 0; i < 3200; i ++) {
		if (! n.length) n = s.concat();
		r = (x >> 16) & 32767;
		q.push(n.splice(r % n.length, 1));
		x = (x * 1103515245 + 12345)|0;
	}
	q = q.join("").match(/.{8}/g).map(parseFloat);

	// 問題部分
	var arr = [];
	for (var i = 0; i < q.length; i ++) {
		var n = q[i];
		arr.push(
			//Level1
			//111111110-n //11
			//Level2
			//111111110+n*~0 //14
			//111111111+~n //12
			//Level3
			//22222222*5+n*String.fromCharCode(45,49) //39
			//22222222*5+n*Math.log(1/Math.E) //31
			//22222222*5+n*Math.cos(Math.PI) //30
			//22222222*5+n*''.indexOf(2) //26
			22222222*5+n*''.indexOf() //25
		);
	}
	return arr;
}

console.log(yourCode().join(','));
//MD5  eeb8fb99d7cb00c5b04cbd0de77331de
//SHA1 76c3f4b62f0bfcb476c8d0f2b979eb5c232cf32f