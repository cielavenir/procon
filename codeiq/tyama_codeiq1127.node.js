#!/usr/bin/env node

// ● 実行情報：
/*
Order: 0,7,12,9,3,4,8,2,1,5,10,13,11,6,14
Drag Count: 8
Move Log: id9 -> pos3, id5 -> pos9, id6 -> pos13, id11 -> pos12, id12 -> pos3, id1 -> pos8, id2 -> pos7, id7 -> pos1
*/

// ● 実行コード：

function yourCode() {
    var n = 4, peg = {A:[], B:[], C:[]};
    for (var i = n; i --;) peg.A[i] = i + 1;
    var res = [JSON.stringify(peg)];
    var hanoi = function(n, from, to, tmp) {
        if (n >= 1){
            hanoi(n-1, from, tmp, to);
            peg[to].unshift(peg[from].shift());
            res.push(JSON.stringify(peg));
            hanoi(n-1, tmp, to, from);
        }
    }
    hanoi(n, "A", "C", "B");
    return res.join(",\n");
}

// {{2014/10/20 15:55:18}}

/// node.js ///
console.log(yourCode());