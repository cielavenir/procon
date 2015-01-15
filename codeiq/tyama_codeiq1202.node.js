/*
TfUAvLejwRTFwVmtznEj

-- 正解です！ 爆弾を解除しました (^o^) --

経過時間 9.180 sec

確認回数 1 回
*/

// ANSER_START
[1, 2, 2, 0, 1, 2, 1, 0]
// ANSER_END

console.log(
// CODE_START
(function() { 
    // 変数の初期化 
    var pw = "";  // パスワード 
    var key = 12.3456789;  // キー 
    var tbl = genTbl(100);  // テーブル 
 
    // 数字を8つ並べた文字列を返す 
    function str8(n) { 
        var res = "" + n;  // 引数の数値を文字列に 
        res = res.replace(/\D/g, "");  // 数字以外を削除 
        res = res.replace(/^0+/, "");  // 先頭の0を削除 
        res = (res + "00000000").substr(0, 8);  // 8文字入手 
        return res 
    } 
 
    // 文字列テーブルを作る 
    function genTbl(n) { 
        var str = "abcdefghijklmnopqrstuvwxyz"; 
        var res = str + str.toUpperCase();  // 大文字に 
        while (res.length < n){res += res;} 
        res = res.substr(0, n); 
        return res; 
    } 
 
    // 数字8つを連結していく 
    pw += str8(Math.cos(key));  // コサイン 
    pw += str8(Math.sin(key));  // サイン 
    pw += str8(Math.tan(key));  // タンジェント 
    pw += str8(Math.exp(key));  // eを累乗 
    pw += str8(Math.log(key));  // 自然対数 
 
    // 数字を2つずつ使い文字列テーブルで変換 
    pw = pw.replace(/../g, function(s) { 
        return tbl[+s]; 
    }); 
 
    // 生成したパスワードを戻す 
    return pw; 
})() 
// CODE_END
);

// {{2014/11/25 13:53:20}}