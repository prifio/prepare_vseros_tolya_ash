(fn [number]
  (let [mod-pow (fn mod-pow [a b c]
        (loop [ans 1
               dega a
               nowb b
               ]
          (if (zero? nowb) ans
            (if (even? nowb) (recur ans (mod (* dega dega) c) (quot nowb 2))
              (recur (mod (* ans dega) c) (mod (* dega dega) c) (quot nowb 2))
              )
            )
        ))
       prime? (fn [x]
       (every? true? 
        (map (fn [_] (= 1 
         	 	(mod-pow (inc (rand-int (dec x))) (dec number) number)))
             (range 10))
       ))
        ]
    ()
    )
)
		
(defn mod-pow [a b c]
        (loop [ans 1
               dega a
               nowb b
               ]
          (if (zero? nowb) ans
            (if (even? nowb) (recur ans (mod (* dega dega) c) (quot nowb 2))
              (recur (mod (* ans dega) c) (mod (* dega dega) c) (quot nowb 2))
              )
            )
        ))
   
(def number 911)
   
(defn prime? [x]
       (every? true? 
        (map (fn [_] (= 1 
         	 	(mod-pow (inc (rand-int (dec x))) (dec x) x)))
             (range 10))
       ))    