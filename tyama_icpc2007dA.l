#!/usr/bin/env clisp

(defun sum (n ma mi s _n)
  (if (= n 0) (truncate (/ (- s (+ ma mi)) (- _n 2)))
    (let ((x (read)))
      (sum (- n 1) (max ma x) (min mi x) (+ s x) _n))))

(loop
  (let ((n (read)))
     (if (= n 0) (exit))
     (write (sum n 0 1000 0 n))
     (fresh-line)
  )
)