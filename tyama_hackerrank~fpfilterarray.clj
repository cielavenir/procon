#!/usr/bin/clj
(let [lines (line-seq (java.io.BufferedReader. *in*))] (println (apply str (map (fn [x] (str x "\n"))(
;answer
(fn ! [delim lst] (if (= lst '()) '() (
	if (< (first lst) delim) (cons (first lst) (! delim (rest lst))) (! delim (rest lst))
)))
;until here
(Integer. (first lines)) (map #(Integer. %) (rest lines)))))))