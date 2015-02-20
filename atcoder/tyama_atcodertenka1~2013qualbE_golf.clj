#!/usr/bin/clj
(defn run [n]
	(if (> n 1) (do (print n) (print " 0\n") (run (- n 1))))
)
(print "100\n1 0\n")
(run 99)
(print "0 0\n")