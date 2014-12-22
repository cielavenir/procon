#!/usr/bin/node

function yourCode() {
	var arr = [];
	for (var i = 10; i <= 100; i ++) {
		arr.push(
			//Level1
			//i%2*i%3*i%5*i%7>0||i //20
			//Level2
			//(Boolean(i-(i/2^0)*2)&&Boolean(i-(i/3^0)*3)&&Boolean(i-(i/5^0)*5)&&Boolean(i-(i/7^0)*7))||i //91
			//!(!(i-(i/2^0)*2)||!(i-(i/3^0)*3)||!(i-(i/5^0)*5)||!(i-(i/7^0)*7))||i //68
			///\./.test(i/2)&&/\./.test(i/3)&&/\./.test(i/5)&&/\./.test(i/7)||i //65
			//(i-(i/2^0)*2)*(i-(i/3^0)*3)*(i-(i/5^0)*5)*(i-(i/7^0)*7)>0||i //60
			//i/2>i/2<<0&&i/3>i/3<<0&&i/5>i/5<<0&&i/7>i/7<<0||i //49
			/(.*\.){4}/.test([i/2]+i/3+i/5+i/7)||i //38
		);
	}
	return arr;
}

console.log(yourCode().join(','));

//i.concat(!0)
//i/3^0,i/3<<0,~~(i/3)
//(i/3).toFixed()
//i&1 == i%2
//.1.toFixed(1)[1] //->'.'
//i/3>i/3<<0