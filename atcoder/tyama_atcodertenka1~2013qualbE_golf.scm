#!/usr/bin/gosh
(define (run n)
	(if (> n 1) (begin (display n) (display " 0\n") (run (- n 1))))
)
(display "100\n1 0\n")
(run 99)
(display "0 0\n")