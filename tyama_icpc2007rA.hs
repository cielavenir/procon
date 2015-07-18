#!/usr/bin/env runghc
import Control.Applicative

calc r i n k
	 | i==n = r
	 | otherwise = calc (mod (r+k) i) (i+1) n k

main = do
	[n,k,m] <- map read . words <$> getLine
	if n/=0 then do
		putStrLn $ show $ ((mod ((calc 0 1 n k)+m) n)+1)
		main
	else return ()