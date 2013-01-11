#!/usr/bin/env gosh

(define run (lambda(n)
	(if (not (zero? n))
		(let ((y (read (standard-input-port))) (m (read (standard-input-port))) (d (read (standard-input-port))))
			(write (- 196471 (+ (* (- y 1) 195 ) (* (quotient (- y 1) 3) 5) (* (- m 1) 20) (- (if (zero? (modulo y 3)) 0 (quotient (- m 1) 2))) d)))
			(newline)
			(run (- n 1))
		)
	)
))

(let ((n (read (standard-input-port))))
	(run n)
)