#!/usr/bin/clj
(let [lines (line-seq (java.io.BufferedReader. *in*))] (println(
;answer
(fn ! [lst] (if (= lst '()) 0 (+ (if (= (rem (first lst) 2) 0) 0 (first lst)) (! (rest lst)))))
;until here
(map #(Integer. %) lines))))