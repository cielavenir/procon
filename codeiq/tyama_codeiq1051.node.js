/*
APLJESOWXTZFINKUD

-- 正解です！ 爆弾を解除しました (^o^) --

[1, 1, 2, 1, 1, 2, 0, 1]

経過時間 9.084 sec

確認回数 1 回
*/

console.log(
// CODE_START
(function() {
    // 変数の初期化
    var pw = "";    // パスワード
    var arr = [];
    var uniqueCount = 1;

    // 配列の作成
    for (var i = 0; i < 26; i ++) {
        arr.push((Math.sqrt(i) * 9973 | 0) % 26);
    }

    // ユニーク化
    outer:
    for (var i = 1; i < arr.length; i ++) {
        for (var j = 0; j < uniqueCount ; j ++) {
            if (arr[i] == arr[j]) {
                continue  outer;
            }
        }
        arr[uniqueCount++] = arr[i];
    }
    arr.splice(uniqueCount );

    // 文字列化
     for (var i = 0; i < arr.length; i ++) {
        pw += String.fromCharCode(65 + arr[i]);
    }

    return pw;
})()
// CODE_END
);