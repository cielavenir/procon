#!/usr/bin/env runghc
main = readLn >>= \n -> print $ if n>2 then n-2 else n+2
