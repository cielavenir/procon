#!/usr/bin/env node

// ● 実行情報：
/*
Order: 0,1,9,12,14,6,2,11,7,8,10,4,5,3,13,15
Drag Count: 8
Move Log: id3 -> pos12, id5 -> pos11, id14 -> pos4, id11 -> pos6, id4 -> pos11, id12 -> pos3, id9 -> pos3, id2 -> pos6
*/

// ● 実行コード：

function yourCode() {
    var arr = [11,5,14,8,12,6,7,10,1,2,4,9,13,3,15];
    var i = 1;
    while (i < arr.length) {
        if (arr[i - 1] > arr[i]) {
            var a = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = a;
            i --;
            if (i == 0) {i=2;}
        } else {
            i ++;
        }
    }
    return arr.join(",");
}

/// node.js ///
console.log(yourCode());