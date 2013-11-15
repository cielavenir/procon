#!/usr/bin/runhugs
mysum :: Int -> Int -> Int -> Int -> Int -> IO Int
mysum 0 ma mi s z = return (div (s-ma-mi) (z-2)) --(floor(fromIntegral(s-ma-mi)/fromIntegral(z-2)))
mysum n ma mi s z = do
	x <- readLn
	y <- mysum (n-1) (max ma x) (min mi x) (s+x) z
	return (y)

main = do
	n <- readLn
	if n/=0 then do
		s <- mysum n 0 1000 0 n
		print s
		main
	else return ()