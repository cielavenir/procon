#!/usr/bin/clj
(let [lines (line-seq (java.io.BufferedReader. *in*))] (println (apply str (map (fn [x] (str x "
"))(
;answer
(fn ! [lst] (if (= lst '()) '() (
	cons (if (< (first lst) 0) (* -1 (first lst)) (first lst)) (! (rest lst))
)))
;until here
(map (fn [x] (Integer. x)) lines))))))