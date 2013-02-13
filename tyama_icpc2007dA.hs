#!/usr/bin/runhugs
-- mysum :: Int -> Int -> Int -> Int -> Int -> IO Int
mysum n ma mi s z = do
	if n==0
		then
			return (div (s-ma-mi) (z-2)) --(floor(fromIntegral(s-ma-mi)/fromIntegral(z-2)))
		else do
			x <- readLn
			y <- mysum (n-1) (max ma x) (min mi x) (s+x) z
			return (y)

main = do
	n <- readLn
	if n/=0
		then do
			s <- mysum n 0 1000 0 n
			putStrLn (show s)
			main
		else putStr "" --dummy