#!/usr/bin/env gosh
;Tested using Gauche

;(define (max x y)
;  (if (< x y) y x))
;(define (min x y)
;  (if (< x y) x y))

(define (sum n ma mi s _n)
  (if (zero? n) (truncate (/ (- s (+ ma mi)) (- _n 2)))
    (let ((x (read))) ;the same as (set! x (...)) (begin ...), but...
      (sum (- n 1) (max ma x) (min mi x) (+ s x) _n))))

(while #t
  (let ((n (read)))
     (if (zero? n) (exit))
     (write (sum n 0 1000 0 n))
     (newline)
  )
)