#!/usr/bin/node

function yourCode() {
	var arr = [];
	for (var i = 1; i <= 100; i ++) {
		arr.push(
			//level2
			//i%7<1||/7/.test(i)||i //21
			//level3
			//i==(i/7|0)*7||/7/.test(i)||i //28
			i/7 in arr||/7/.test(i)||i //ans,26
		);
	}
	return arr;
}

console.log(yourCode().join(','));