(println "Clojure1:")
(def a (vec (range 1e7)))
(def b (vec (range 1e7)))
(time (def c (long-array (concat a b))))
(time
  (let [data ^longs c]
    (areduce data i accum 0
             (+ accum (aget data i)))))
