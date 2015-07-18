#!/usr/bin/env gosh

(define calc (lambda(r i n k)
	(if (= i n) r (calc (modulo (+ r k) i) (+ i 1) n k))
))

(define ma (lambda()
	(let ((n (read (current-input-port))) (k (read (current-input-port))) (m (read (current-input-port))))
		(if (not (zero? n)) (begin
			(write (+ (modulo (+ (calc 0 1 n k) m) n) 1))
			(newline)
			(ma)
		))
	)
))
(ma)