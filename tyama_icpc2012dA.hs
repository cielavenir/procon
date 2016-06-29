#!/usr/bin/env runghc
import Control.Applicative

run n
		| n>0 = do
			[y,m,d] <- map read . words <$> getLine
			print $ 196471-((y-1)*195)-(div (y-1) 3)*5-(m-1)*20+(if ((mod y 3)==0) then 0 else (div (m-1) 2))-d
			run (n-1)
		| otherwise = return ()

main = readLn >>= run