#!/usr/bin/runhugs
import Control.Monad

mysum :: [Int] -> Int -> Int -> Int -> Int -> Int
mysum [] ma mi s z = (div (s-ma-mi) (z-2))
mysum a  ma mi s z = mysum (tail a) (max ma $ head a) (min mi $ head a) (s+(head a)) z

main = do
	n<-readLn
	if n/=0 then do
		a<-replicateM n readLn
		print $ mysum a 0 1000 0 n
		main
	else return ()