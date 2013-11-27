#!/usr/bin/runhugs
-- http://jutememo.blogspot.jp/2008/06/haskell-join-listdata-intersperse.html
join :: String -> [Int] -> String
join sep [] = []
join sep [x] = show x
join sep (x:xs) = (show x) ++ sep ++ join sep xs

combination :: Int -> Int -> Int
--combination n k
--	| k==0 = 1
--	| k==n = 1
--	| otherwise = (combination (n-1) k) + (combination (n-1) (k-1))
combination n k = combination2 n k 0 1 where
		combination2 n k i o
					| k==i = o
					| otherwise = combination2 n k (i+1) $ div (o*(n-i)) (i+1)

main2 i n
	| i<n = do
		putStrLn $ join " " (map (combination i) [0..i])
		main2 (i+1) n
	| otherwise = return ()

main = readLn >>= main2 0