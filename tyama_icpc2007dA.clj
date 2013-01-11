#!/usr/bin/clojure

(defn exit [] (. System exit 0))

(defn sum [n ma mi s _n]
  (if (= n 0) (quot (- s (+ ma mi)) (- _n 2))
    (let [x (read)]
      (sum (- n 1) (max ma x) (min mi x) (+ s x) _n))))

(while true
  (let [n (read)]
     (if (= n 0) (exit))
     (println (sum n 0 1000 0 n))
  )
)