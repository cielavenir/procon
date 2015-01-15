/*
H3rg8Qmg4Xf7NDFG

-- 正解です！ 爆弾を解除しました (^o^) --

経過時間 9.945 sec

確認回数 1 回
*/

// ANSER_START
[1, 1, 2, 0, 2, 0, 1, 2]
// ANSER_END

console.log(
// CODE_START
(function() { 
    // 変数の初期化 
    var pw = "";    // パスワード 
 
    // 使用する文字セットを作成 
    var strSet = genStr(["09", "az", "AZ"]); 
 
    // 文字列生成関数（文字コードがfrom～toの文字列） 
    function genStr(arr) { 
        var res = ""; 
 
        // 0文字目を開始位置、1文字目を終了位置 
        var from = arr[0].charCodeAt(0); 
        var to   = arr[0].charCodeAt(1); 
 
        // 文字列を作成 
        for (var i = from; i <= to; i ++) { 
            var chr = String.fromCharCode(i); 
            res += chr; 
        } 
 
        // 配列が2以上なら同じ処理をして末尾に追加 
        if (arr.length >= 2) { 
            var arr2 = arr.slice(1); 
            res += arguments.callee(arr2); 
        } 
 
        return res; 
    } 
 
    // パスワード生成 
    while (pw.length < 100) { 
        // Math.logで生成した浮動小数点数をひっくり返す 
        var n = Math.log(pw.length + 2); 
        n = String(n).replace(/^(.{8}).*$/, "$1"); 
        n = n.split("").reverse().join(""); 
 
        // 四捨五入して文字セットから文字を取り出し 
        n = Math.round(n); 
        pw += strSet[n % strSet.length]; 
    } 
 
    // 長い文字列から、一部を取り出し 
    pw = pw.substr(pw.length / 2 | 0, 16); 
 
    return pw; 
})() 
// CODE_END
);

// {{2014/10/20 15:37:9}}