#!/usr/bin/env node

// ● 実行情報：
/*
Order: 0,1,9,12,14,6,2,3,7,8,10,4,5,11,13,15
Drag Count: 6
Move Log: id6 -> pos2, id4 -> pos10, id5 -> pos10, id14 -> pos2, id12 -> pos2, id9 -> pos2
*/

// ● 実行コード：

function yourCode() {
    var arr = [];
    var euclidean = function(a, b) {
        while (b > 0) {
            var mod = a % b;
            a = b;
            b = mod;
    }
        return a;
    };
    for (var i = 2; i <= 100; i ++) {
        arr.push("[" + i + ","
            + euclidean(210, i) + "]");
        }
    return arr.join(",");
}

/// node.js ///
console.log(yourCode());