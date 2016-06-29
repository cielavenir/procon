#!/usr/bin/env runghc
import Control.Applicative
import Data.List

calc n k = foldl' (\r i -> mod (r+k) i) 0 [1..n-1]

main = map read . words <$> getLine >>= \[n,k,m] ->
	if n/=0 then do
		print $ ((mod ((calc n k)+m) n)+1)
		main
	else return ()