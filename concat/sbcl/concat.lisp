(defun my-print-time (&key real-time-ms user-run-time-us system-run-time-us
                        gc-run-time-ms processor-cycles eval-calls
                        lambdas-converted page-faults bytes-consed
                        aborted)
  (format t "~ams~%" real-time-ms))

(defmacro my-time (form)
  `(call-with-timing #'my-print-time (lambda () ,form)))

(defun range (max &key (min 0) (step 1))
  (loop for n from min below max by step
     collect n))

(defun make-range (n)
  (make-array
   n
   :initial-contents (range n)
   :element-type 'integer))

(defun main ()
  (format t "sbcl:~%")
  (let ((a (make-range (truncate 1e7)))
        (b (make-range (truncate 1e7)))
        c
        (s 0)
        n)
    (my-time (setq c (concatenate 'vector a b)))
    (my-time
     (progn
       (setq n (array-dimension c 0))
       (dotimes (i n)
         (setq s (+ s (aref c i))))))
    (format t "sum: ~d~%" s)))
(main)
