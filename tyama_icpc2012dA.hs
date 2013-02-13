#!/usr/bin/runhugs
import Control.Applicative

run n = do
	if n>0
		then do
			[y,m,d] <- map read . words <$> getLine
			putStrLn (show (196471-((y-1)*195)-(div (y-1) 3)*5-(m-1)*20+(if ((mod y 3)==0) then 0 else (div (m-1) 2))-d))
			run (n-1)
		else putStr ""

main = do
	n <- readLn
	run n