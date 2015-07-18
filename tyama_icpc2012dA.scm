#!/usr/bin/env gosh

(define run (lambda(n)
	(if (not (zero? n))
		(let ((y (read (current-input-port))) (m (read (current-input-port))) (d (read (current-input-port))))
			(write (- 196471 (+ (* (- y 1) 195 ) (* (quotient (- y 1) 3) 5) (* (- m 1) 20) (- (if (zero? (modulo y 3)) 0 (quotient (- m 1) 2))) d)))
			(newline)
			(run (- n 1))
		)
	)
))

(let ((n (read (current-input-port))))
	(run n)
)