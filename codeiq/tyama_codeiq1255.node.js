/*
HappyXmas

-- 正解です！ 爆弾を解除しました (^o^) --

経過時間 7.212 sec

確認回数 1 回
*/

// ANSER_START
[2, 0, 1, 1, 2]
// ANSER_END

console.log(
// CODE_START
(function () { 
    // テーブル 
    var tbl = "" 
        + "aKqxPkhWcfWHwFgkRqsN" 
        + "QasShuWpwWaaSpzLpzEo" 
        + "czXdbDsmWteHrgByjUvn" 
        + "iZXrTuyYksVhiCcyTmtG" 
        + "MabGpjDvnAoqZedQifPs"; 
 
    // パスワード 
    var pw = ""; 
 
    // 参照位置の計算 
    var old = 1; 
    for (var i = 0; i < 100; i ++) { 
        // 3種類のコサインカーブを合成 
        var a = Math.cos(i / 7); 
        var b = Math.cos(i / 13); 
        var c = Math.cos(i / 17); 
        var now = a * b * c; 
 
        // グラフの正負が入れ替わるタイミングを判定 
        if (old * now < 0) { 
            pw += tbl[i]; 
        } 
        old = now; 
    } 
 
    // 生成したパスワードを戻す 
    return pw; 
})();
// CODE_END
);

// {{2014/12/22 10:0:14}}