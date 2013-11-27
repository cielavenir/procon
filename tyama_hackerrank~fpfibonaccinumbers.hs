#!/usr/bin/runhugs
fib :: Int -> Int
fib 0 = 0
fib 1 = 0
fib n = fibi n 1 0 where
	fibi 0 a b = a
	fibi n a b = fibi (n-1) (a+b) a

main = readLn >>= print . fib