#!/usr/bin/env gosh

(let ((a (read (current-input-port))) (b (read (current-input-port))) (s (read (current-input-port))))
	(write (+ a b))
	(display " ")
	(write s)
	(newline)
)