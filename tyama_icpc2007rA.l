#!/usr/bin/env clisp

(defun calc (r i n k)
	(if (= i n) r (calc (mod (+ r k) i) (+ i 1) n k))
)

(defun ma ()
	(let ((n (read)) (k (read)) (m (read)))
		(if (not (= n 0)) (progn
			(write (+ (mod (+ (calc 0 1 n k) m) n) 1))
			(fresh-line)
			(ma)
		))
	)
)
(ma)