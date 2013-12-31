#!/usr/bin/runhugs
import Control.Applicative
combination :: Int -> Int -> Int
--combination n k
--	| k==0 = 1
--	| k==n = 1
--	| otherwise = (combination (n-1) k) + (combination (n-1) (k-1))
combination n k = combination2 n k 0 1 where
		combination2 n k i o
					| k==i = o
					| otherwise = combination2 n k (i+1) $ div (o*(n-i)) (i+1)

main2 0 = return ()
main2 x = do
	[n,k] <- (map read . words) <$> getLine
	putStrLn $ show $ mod (combination n k) 100000007 -- this is wrong...
	main2 (x-1)

main = readLn >>= main2
	