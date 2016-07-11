#!/usr/bin/env runghc
import Text.Printf
import Control.Applicative

sq x = x*x
main = map (read :: String -> Int) . words <$> getLine >>= \[a,b] ->
	if a/=0 then
		printf "%f\n" (minimum (map (\i ->
			abs $ (fromIntegral b)-(sqrt $ fromIntegral $ (sq i)+(sq (a-i)))
		) [0..(div a 2)]) :: Double)
		>> main
	else
		return ()