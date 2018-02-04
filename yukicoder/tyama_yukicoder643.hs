#!/usr/bin/env runghc
import Control.Applicative
main = do
	[x,y] <- map read . words <$> getLine
	print $ case () of _
				| x==y -> 0
				| y==0 -> 1
				| x==0 -> 2
				| -x==y -> 3
				| otherwise -> -1
