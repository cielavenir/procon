#!/usr/bin/env runghc
calc 0 a b c = a
calc 1 a b c = b
calc 2 a b c = c
calc n a b c = calc (n-1) b c (a+b+c)
main = print $ calc 19 100 100 200