#!/usr/bin/env runghc
run n
	| n>1 = do
		putStr (show n)
		putStrLn " 0"
		run (n-1)
	| otherwise = return ()

main = do
	putStrLn "100\n1 0"
	run 99
	putStrLn "0 0"