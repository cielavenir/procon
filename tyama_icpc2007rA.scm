#!/usr/bin/env gosh

(define (calc r i n k)
	(if (= i n) r (calc (modulo (+ r k) i) (+ i 1) n k))
)

(define (ma)
	(let ((n (read)) (k (read)) (m (read)))
		(if (not (zero? n)) (begin
			(write (+ (modulo (+ (calc 0 1 n k) m) n) 1))
			(newline)
			(ma)
		))
	)
)
(ma)