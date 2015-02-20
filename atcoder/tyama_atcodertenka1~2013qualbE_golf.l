#!/usr/bin/clisp
(defun run (n)
	(if (> n 1) (progn (format t "~D 0~C" n #\newline) (run (- n 1))))
)
(format t "100~C1 0~C" #\newline #\newline)
(run 99)
(format t "0 0~C" #\newline)