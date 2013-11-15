module Main where

fib :: Int -> Int
fib 1 = 0
fib 2 = 1
fib n = fib(n-1) + fib(n-2)

main = readLn >>= print . fib