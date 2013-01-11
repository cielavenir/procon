#!/usr/bin/env clisp

(defun run (n)
	(if (not (= n 0))
		(let ((y (read)) (m (read)) (d (read)))
			(write (- 196471 (+ (* (- y 1) 195 ) (* (truncate (- y 1) 3) 5) (* (- m 1) 20) (- (if (= (mod y 3) 0) 0 (truncate (- m 1) 2))) d)))
			(fresh-line)
			(run (- n 1))
		)
	)
)

(let ((n (read)))
	(run n)
)