(message "Elisp:")
(let ((a (number-sequence 0 (1- (ceiling 1e7))))
      (b (number-sequence 0 (1- (ceiling 1e7))))
      c
      (sum 0))
  (message
   "%S"
   (car
    (benchmark-run 1
      (setq c (append a b)))))
  (message
   "%S"
   (car (benchmark-run 1
          (message "sum: %d" (apply #'+ c))))))
