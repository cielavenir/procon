#!/usr/bin/env gosh
;Tested using Gauche

;(define max (lambda(x y)
;  (if (< x y) y x)))
;(define min (lambda(x y)
;  (if (< x y) x y)))

(define sum (lambda(n ma mi s _n)
  (if (zero? n) (truncate (/ (- s (+ ma mi)) (- _n 2)))
    (let ((x (read (standard-input-port)))) ;the same as (set! x (...)) (cond ...), but...
      (sum (- n 1) (max ma x) (min mi x) (+ s x) _n)))))

(while #t
  (let ((n (read (standard-input-port))))
     (if (zero? n) (exit))
     (write (sum n 0 1000 0 n))
     (newline)
  )
)