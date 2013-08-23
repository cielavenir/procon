#!/usr/bin/runhugs

run n = do
	if n>1
		then do
			putStr (show n)
			putStrLn " 0"
			run (n-1)
		else putStr ""

main = do
	putStrLn "100\n1 0"
	run 99
	putStrLn "0 0"