#!/usr/bin/env gosh
;(define % (lambda(a b) (modulo a b)))
;(define ! (lambda(a) (not a)))

(define year (lambda(y)
	(if (= y 1000)
		0
		(+ (year (+ y 1)) (if (not (zero? (modulo y 3))) 195 200))
	)
))

(define month (lambda(y m)
	(if (= m 11)
		0
		(+ (month y (+ m 1)) (if (and (not (zero? (modulo y 3))) (zero? (modulo m 2))) 19 20))
	)
))

(define run (lambda(n)
	(if (not (zero? n))
		(let ((y (read (current-input-port))) (m (read (current-input-port))) (d (read (current-input-port))))
			(write (+ (- (if (and (not (zero? (modulo y 3))) (zero? (modulo m 2))) 20 21) d) (month y (+ m 1)) (year (+ y 1)))) ;add 3 numbers
			(newline)
			(run (- n 1))
		)
	)
))

(let ((n (read (current-input-port))))
	(run n)
)