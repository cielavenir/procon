#!/usr/bin/clj
(let [lines (line-seq (java.io.BufferedReader. *in*))] (println(count(
;answer
(fn ! [n] (if (= n 0) '() (cons n (! (- n 1)))))
;until here
(Integer. (first lines))))))