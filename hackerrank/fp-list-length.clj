#!/usr/bin/clj
(let [lines (line-seq (java.io.BufferedReader. *in*))] (println (
;answer
(fn ! [lst] (if (= lst '()) 0 (+ 1 (! (rest lst)))))
;until here
lines)))