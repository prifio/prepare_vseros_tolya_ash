(defn read-int [] (Long. (read-line)))

(defn read-array [n]
	(->>
	(range n)
	(map (fn [_] (read-int)))
	(vec))
)

(defn read-array-index [n]
(->>
  (range n)
  (map (fn [x] [(read-int) x]))
  (vec))
)

(defn lower-bound [a le r hei]
	(if (= le (- r 1))
		r
		(let [mid (/ (+ le r) 2)]
			(if (>= (nth a mid) hei) 
				(lower-bound a le mid hei)
				(lower-bound a mid r hei)))))

;ToliJIDEA - https://yadi.sk/d/gXbJe_1Ls5wN2
;doc
'(
(drop 3 '(1 2 3 4 5))
>>>4 5

(take 3 '(1 2 3 4 5))
>>1 2 3

(min 1 2 3 4)
>> 1

(apply comand vec) = (command a[0] a[1] a[2] a[3])
(reduce comand vec) = (command(comand a[0] a[1]) a[2])

(into [3 2 2] [2 2 8])
>>> 3 2 2 2 2 8

(merge [1 2 3] 4)
>>> 1 2 3 4

(keep)mda

???cond - switch
(cond 
	(> x 10) "big"
	(= x 10) "10"
	(< x 10) "smool"
	:else "WHATISIT??"
)

(every? true? [true true])
true
(every? true? [false true])
false

some - like every. see NAME

(even? (* 2 k))
true
(even? (+ 1 (* 2 k)))
false

(contains? {:k1 lol :k2 vov} :k1)
true
(contains? {:k1 lol :k2 vov} :k3)
false

(sequential? [1 2 3])
true

(flatten [1 [2] [[3 4] [5 6]]])
>> 1 2 3 4 5 6

(map-index (fn [ind elem]) arr)
)