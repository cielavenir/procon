module Main where

-- http://jutememo.blogspot.jp/2008/06/haskell-join-listdata-intersperse.html
join :: String -> [Int] -> String
join sep [] = []
join sep [x] = show x
join sep (x:xs) = (show x) ++ sep ++ join sep xs

combination n k
	| k==0 = 1
	| k==n = 1
	| otherwise = (combination (n-1) k) + (combination (n-1) (k-1))

main2 i n
	| i<n = do
		putStrLn $ join " " (map (combination i) [0..i])
		main2 (i+1) n
	| otherwise = return ()

main = readLn >>= main2 0