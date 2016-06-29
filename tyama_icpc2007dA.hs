#!/usr/bin/env runghc
mysum :: Int -> Int -> Int -> Int -> Int -> IO Int
mysum 0 ma mi s z = return (div (s-ma-mi) (z-2)) --(floor(fromIntegral(s-ma-mi)/fromIntegral(z-2)))
mysum n ma mi s z = do
	x <- readLn
	y <- mysum (n-1) (max ma x) (min mi x) (s+x) z
	return (y)

main = readLn >>= \n ->
	if n/=0 then
		mysum n 0 1000 0 n >>= print >> main
	else return ()