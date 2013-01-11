#!/usr/bin/runhugs
module Main where

-- http://d.hatena.ne.jp/g940425/20110804/1312434821
getIntLine :: IO Int
getIntLine = do
	n <- getLine
	return(read n::Int)
putAnsLn :: (Show a) => a -> IO ()
putAnsLn ans = putStrLn(show ans)
getIntLines :: Int -> IO [Int]
getIntLines n =
	if n>0
		then do
			l <- getIntLine
			ls <- getIntLines (n-1)
			return (l:ls)
		else
			return []

mysum :: [Int] -> Int -> Int -> Int -> Int -> Int -> Int
mysum a n ma mi s z =
	if n==0
		then floor(fromIntegral(s-ma-mi)/fromIntegral(z-2))
		else mysum a (n-1) (max ma (a !! (n-1))) (min mi (a !! (n-1))) (s+(a !! (n-1))) z

main = do
	n<-getIntLine
	if n/=0
		then do
			a<-getIntLines n -- need to use list? lol
			putAnsLn(mysum a n 0 1000 0 n);
			main
		else putStr "" --dummy