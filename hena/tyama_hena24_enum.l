#!/usr/bin/sbcl --script
;http://nabetani.sakura.ne.jp/hena/ord24eliseq/

(defun isqrt_impl (n x y)
	(if (or (= x y) (= (+ x 1) y)) x
		(isqrt_impl n y (truncate (+ (truncate n y) y) 2))
	)
)

(defun myisqrt (n)
	(if (<= n 0) 0
		(if (< n 4) 1
			(isqrt_impl n 0 n)
		)
	)
)

(defun icbrt_impl (n x y)
	(if (or (= x y) (= (+ x 1) y)) x
		(icbrt_impl n y (truncate (+ (truncate (truncate n y) y) (* y 2)) 3))
	)
)

(defun icbrt (n)
	(if (< n 0) (- 0 (icbrt (- 0 n)))
		(if (= n 0) 0
			(if (< n 8) 1
				(icbrt_impl n 0 n)
			)
		)
	)
)

(defun generate ()
	(let ((i 0))
		(lambda ()
			(setf i (+ i 1))
			i
		)
	)
)

(defun drop_prev (check prev)
	(let ((a 0) (b (funcall prev)))
		(lambda ()
			(setf a b)
			(setf b (funcall prev))
			(loop while (funcall check b) do
				(setf a b)
				(setf b (funcall prev))
			)
			a
		)
	)
)

(defun drop_next (check prev)
	(let ((a 0) (b 0) (first t))
		(lambda ()
			(setf a b)
			(setf b (funcall prev))
			(loop while (and (not first) (funcall check a)) do
				(setf a b)
				(setf b (funcall prev))
			)
			(setf first nil)
			b
		)
	)
)

(defun drop_n (check n prev)
	(let ((i 0) (a 0))
		(lambda ()
			(setf i (+ i 1))
			(setf a (funcall prev))
			(loop while (funcall check i n) do
				(setf i (+ i 1))
				(setf a (funcall prev))
			)
			a
		)
	)
)

(defun is_sq (n)
	(= (expt (myisqrt n) 2) n)
)
(defun is_cb (n)
	(= (expt (icbrt n) 3) n)
)
(defun is_multiple (i n)
	(= (mod i n) 0)
)
(defun is_le (i n)
	(<= i n)
)

(let ((f (make-hash-table)))
	(setf (gethash #\S f) (lambda (prev) (drop_next 'is_sq prev)))
	(setf (gethash #\s f) (lambda (prev) (drop_prev 'is_sq prev)))
	(setf (gethash #\C f) (lambda (prev) (drop_next 'is_cb prev)))
	(setf (gethash #\c f) (lambda (prev) (drop_prev 'is_cb prev)))
	(setf (gethash #\h f) (lambda (prev) (drop_n 'is_le 100 prev)))
	(setf (gethash #\2 f) (lambda (prev) (drop_n 'is_multiple 2 prev)))
	(setf (gethash #\3 f) (lambda (prev) (drop_n 'is_multiple 3 prev)))
	(setf (gethash #\4 f) (lambda (prev) (drop_n 'is_multiple 4 prev)))
	(setf (gethash #\5 f) (lambda (prev) (drop_n 'is_multiple 5 prev)))
	(setf (gethash #\6 f) (lambda (prev) (drop_n 'is_multiple 6 prev)))
	(setf (gethash #\7 f) (lambda (prev) (drop_n 'is_multiple 7 prev)))
	(setf (gethash #\8 f) (lambda (prev) (drop_n 'is_multiple 8 prev)))
	(setf (gethash #\9 f) (lambda (prev) (drop_n 'is_multiple 9 prev)))

	(loop
		(let ((line (read-line *standard-input* nil nil)))
			(if (not line) (exit))
			(let ((g (reduce (lambda (s e) (funcall (gethash e f) s)) (coerce line 'list) :initial-value (generate))))
				(let ((i 0))
					(loop while (< i 10) do
						(if (> i 0) (princ #\,))
						(write (funcall g))
						(setf i (+ i 1))
					)
				)
	  			(fresh-line)
			)
		)
	)
)
