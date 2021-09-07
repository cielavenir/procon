#!/usr/bin/env clojure
;http://nabetani.sakura.ne.jp/hena/ord24eliseq/

(defn expt_impl [r n k]
	(if (<= k 0) r (recur (* r (if (> (mod k 2) 0) n 1)) (* n n) (quot k 2)))
)

(defn expt [n k]
	(expt_impl 1 n k)
)

(defn isqrt_impl [n x y]
	(if (or (= x y) (= (+ x 1) y)) x
		(recur n y (quot (+ (quot n y) y) 2))
	)
)

(defn isqrt [n]
	(if (<= n 0) 0
		(if (< n 4) 1
			(isqrt_impl n 0 n)
		)
	)
)

(defn icbrt_impl [n x y]
	(if (or (= x y) (= (+ x 1) y)) x
		(recur n y (quot (+ (quot (quot n y) y) (* y 2)) 3))
	)
)

(defn icbrt [n]
	(if (< n 0) (- 0 (icbrt (- 0 n)))
		(if (= n 0) 0
			(if (< n 8) 1
				(icbrt_impl n 0 n)
			)
		)
	)
)

(defn generate []
	(let [i (atom 0)]
		(fn []
			(reset! i (+ @i 1))
			@i
		)
	)
)

(defn drop_prev [check prev]
	(let [a (atom 0) b (atom (prev))]
		(fn []
			(reset! a @b)
			(reset! b (prev))
			(while (check @b)
				(reset! a @b)
				(reset! b (prev))
			)
			@a
		)
	)
)

(defn drop_next [check prev]
	(let [a (atom 0) b (atom 0) first (atom true)]
		(fn []
			(reset! a @b)
			(reset! b (prev))
			(while (and (not @first) (check @a))
				(reset! a @b)
				(reset! b (prev))
			)
			(reset! first false)
			@b
		)
	)
)

(defn drop_n [check n prev]
	(let [i (atom 0) a (atom 0)]
		(fn []
			(reset! i (+ @i 1))
			(reset! a (prev))
			(while (check @i n)
				(reset! i (+ @i 1))
				(reset! a (prev))
			)
			@a
		)
	)
)

(defn is_sq [n]
	(= (expt (isqrt n) 2) n)
)
(defn is_cb [n]
	(= (expt (icbrt n) 3) n)
)
(defn is_multiple [i n]
	(= (mod i n) 0)
)
(defn is_le [i n]
	(<= i n)
)

(def f {
	\S (fn [prev] (drop_next is_sq prev))
	\s (fn [prev] (drop_prev is_sq prev))
	\C (fn [prev] (drop_next is_cb prev))
	\c (fn [prev] (drop_prev is_cb prev))
	\h (fn [prev] (drop_n is_le 100 prev))
	\2 (fn [prev] (drop_n is_multiple 2 prev))
	\3 (fn [prev] (drop_n is_multiple 3 prev))
	\4 (fn [prev] (drop_n is_multiple 4 prev))
	\5 (fn [prev] (drop_n is_multiple 5 prev))
	\6 (fn [prev] (drop_n is_multiple 6 prev))
	\7 (fn [prev] (drop_n is_multiple 7 prev))
	\8 (fn [prev] (drop_n is_multiple 8 prev))
	\9 (fn [prev] (drop_n is_multiple 9 prev))
})

(with-local-vars [line (read-line)]
	(while (not (= @line nil))
		(let [g (reduce (fn [s e] ((get f e) s)) (generate) (seq @line))]
		 	(with-local-vars [i 0]
				(while (< @i 10)
					(if (> @i 0) (print ","))
					(print (g))
					(var-set i (+ @i 1))
				)
				(println)
			)
		)
		(var-set line (read-line))
	)
)
