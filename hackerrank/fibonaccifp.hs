#!/usr/bin/runhugs
--import Control.Applicative
--import Control.Monad

fib :: Int -> Int
fib 0 = 0
fib n = fibi (n-1) 1 0 where
	fibi 0 a b = a
	fibi n a b = fibi (n-1) (mod (a+b) 100000007) a

main = getContents >>= mapM_ (print . fib . read) . tail . lines
--main = do
--	n <- readLn
--	mapM_ (print . fib) <$> replicateM n readLn