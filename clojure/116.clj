(fn [number]
  (if (> 5 number)
  false
  (let [mod-pow (fn mod-pow [a b c]
        (loop [ans 1
               dega a
               nowb b]
          (if (zero? nowb) ans
            (if (even? nowb) (recur ans (mod (* dega dega) c) (quot nowb 2))
              (recur (mod (* ans dega) c) (mod (* dega dega) c) (quot nowb 2))
              ))))
       prime? (fn [x]
       (every? true? 
        (map (fn [_] (= 1 
         	 	(mod-pow (inc (rand-int (dec x))) (dec x) x)))
             (range 10))))
        primelist (filter prime? (range 2 (* 2 number)))
        get-index (fn [val arr] 
          (count (take-while #(not (= val %)) arr)))
        ]
    (if (prime? number)
    (let [index (get-index number primelist)] 
    (= (* 2 number) (+ 
      (nth primelist (dec index))
      (nth primelist (inc index)))))
    false))))
   
;4clojure.com/problem/116
