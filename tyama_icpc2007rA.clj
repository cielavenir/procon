#!/usr/bin/clojure

(defn calc [r i n k]
	(if (= i n) r (recur (rem (+ r k) i) (+ i 1) n k))
)

(defn ma []
	(let [n (read) k (read) m (read)]
		(if (not (zero? n)) (do
			(println (+ (rem (+ (calc 0 1 n k) m) n) 1))
			(recur)
		))
	)
)
(ma)