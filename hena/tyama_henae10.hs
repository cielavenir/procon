#!/usr/bin/env runghc
-- http://mtsmfm.github.io/2016/12/03/doukaku-e10.html
-- http://qiita.com/mtsmfm/items/8a78b895910a89e3012d

import System.IO (isEOF,hFlush,stdout)
rec x o l ('X':xs) = rec (x+1) (o+l) 0 xs
rec x o l ('O':xs) = rec x o (l+1) xs
rec x o l [] = ((2^l)-1)*4*2^o + case x of
	0 -> 0
	1 -> 5+(if o==0 then 0 else 5^o)
	otherwise -> 1+4^(x-1)*5^o

main = do
	eof <- isEOF
	if not eof then do
		getLine >>= print . rec 0 0 0
		hFlush stdout
		main
	else return ()
