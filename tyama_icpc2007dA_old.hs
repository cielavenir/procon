#!/usr/bin/runhugs
module Main where

-- http://d.hatena.ne.jp/g940425/20110804/1312434821
getIntLines :: Int -> IO [Int]
getIntLines 0 = return []
getIntLines n = do
	l <- readLn
	ls <- getIntLines (n-1)
	return (l:ls)

mysum :: [Int] -> Int -> Int -> Int -> Int -> Int
mysum [] ma mi s z = (div (s-ma-mi) (z-2))
mysum a  ma mi s z = mysum (tail a) (max ma $ head a) (min mi $ head a) (s+(head a)) z

main = do
	n<-readLn
	if n/=0 then do
		a<-getIntLines n -- need to use list? lol
		print $ mysum a 0 1000 0 n
		main
	else return ()