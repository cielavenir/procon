#!/usr/bin/clojure

(defn run [n]
	(if (not (zero? n))
		(let [y (read) m (read) d (read)]
			(println (- 196471 (+ (* (- y 1) 195 ) (* (quot (- y 1) 3) 5) (* (- m 1) 20) (- (if (zero? (rem y 3)) 0 (quot (- m 1) 2))) d)))
			(run (- n 1))
		)
	)
)

(let [n (read)]
	(run n)
)