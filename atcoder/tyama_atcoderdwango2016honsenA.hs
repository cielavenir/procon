#!/usr/bin/env runghc

-- http://d.hatena.ne.jp/tanakh/20100411
class MemoIx a where
  index :: a -> Integer
  unindex :: Integer -> a

instance MemoIx Integer where
  index n | n>=0 = n*2
          | otherwise = -n*2-1

  unindex n | n`mod`2==0 = n`div`2
            | otherwise = -((n+1)`div`2)

instance (MemoIx a, MemoIx b) => MemoIx (a, b) where
  index (a, b) = l*(l+1)`div`2 + ib
    where
      ia = index a 
      ib = index b
      l  = ia+ib

  unindex ix = (unindex ia, unindex ib)
    where
      l  = floor ((-1 + sqrt (1 + 8 * fromIntegral ix))/2)
      ib = ix - l*(l+1)`div`2
      ia = l-ib

data Tree a = Tree a (Tree a) (Tree a)

findTree :: MemoIx a => Tree b -> a -> b
findTree tree ix = f (bits $ index ix + 1) tree
  where
    f []     (Tree v _ _) = v
    f (0:bs) (Tree _ l _) = f bs l
    f (_:bs) (Tree _ _ r) = f bs r

    bits = tail . reverse . map (`mod`2). takeWhile (>0) . iterate (`div`2)

genTree :: MemoIx a => (a -> b) -> Tree b
genTree f = gen 0 where
  gen ix = Tree (f $ unindex ix) (gen $ ix*2+1) (gen $ ix*2+2)

memofix :: MemoIx a => ((a -> b) -> (a -> b)) -> (a -> b)
memofix f = memof where
  memof = f $ findTree tbl
  tbl = genTree memof

memo :: MemoIx a => (a -> b) -> (a -> b)
memo f = findTree (genTree f)

-- program
z a n l = if n>l then a else z (n:a) (n*10+10 `div` (n `mod` 10)) l
d::[Integer]->Integer->Integer
d a = memofix $ \f n -> if n==0 then 0 else minimum $ map (\e -> (n `mod` e) + (f (n `div` e))) a

main = readLn >>= \n ->
	let a=(z [] 2 n)++(z [] 5 n) in
	print $ d a n