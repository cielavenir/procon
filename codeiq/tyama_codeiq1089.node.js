/*
9acgoNC764QIjD9acgoNC764QIjD9acg

-- 正解です！ 爆弾を解除しました (^o^) --

経過時間 8.586 sec

確認回数 1 回
*/

// ANSER_START
[1, 0, 2, 0, 0, 2, 1, 1]
// ANSER_END

console.log(
// CODE_START
(function() { 
    // 変数の初期化 
    var pw = "";    // パスワード 
    var arrSrc = "abcdefghijklmnopqABCDEFGHIJKLMNOPQ123456789"; 
    var arr = []; 
    var uniqueCount = 1; 
 
    // 配列の作成 
    for (var i = 0; i < 32; i ++) { 
        arr.push((9999991 + Math.pow(2, i))); 
    } 
 
    // 文字列に変換 
    arr = arr.map(function(e) { 
        return arrSrc[e % arrSrc.length] 
    }); 
 
    // 文字列化 
    var rep = function(s) { 
        var i = arrSrc.indexOf(s) + 1; 
        return arrSrc[i % arrSrc.length]; 
    }; 
    pw = arr.join("").replace(/./g, rep); 
 
    return pw; 
})() 
// CODE_END
);