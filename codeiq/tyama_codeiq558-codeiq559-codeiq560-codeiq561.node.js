#!/usr/bin/node

function yourCode() {
	var arr = [];
	for (var i = 1; i <= 100; i ++) {
		arr.push([i, "fizz", "buzz", "fizzbuzz"][
			//Level2
			//2*!(i%5)+!(i%3) //15
			//Level3
			//2*isNaN(0/(i%5))+isNaN(0/(i%3)) //31
			//3-2*Boolean(i%5)-Boolean(i%3) //29
			//Level4
			//2*isNaN(0/(i-5*parseInt(i/5)))+isNaN(0/(i-3*parseInt(i/3))) //59
			//3-2*Boolean(i-5*parseInt(i/5))-Boolean(i-3*parseInt(i/3)) //57
			3-2*/\./.test(i/5)-/\./.test(i/3) //33
		]);
	}
	return arr;
}

console.log(yourCode().join(','));