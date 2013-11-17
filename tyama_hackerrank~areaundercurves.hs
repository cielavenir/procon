import Text.Printf (printf)

d = 0.001

poly :: [Double] -> [Double] -> Double -> Double
poly [] [] z = 0
poly a  b  z = (head a)*z**(head b)+(poly (tail a) (tail b) z)

solve2 :: Double -> Double -> [Double] -> [Double] -> [Double]
solve2 l r a b
  | l<=r = [(poly a b l)+(head $ solve2 (l+d) r a b), (poly a b l)**2+(head $ tail $ solve2 (l+d) r a b)]
  | otherwise = [0,0]

solve :: Double -> Double -> [Double] -> [Double] -> [Double]
solve l r a b = do
  let x = solve2 l r a b
  [d*x!!0,d*pi*x!!1]

--main = getContents >>= mapM_ (printf "%.1f\n") . (\[a, b, [l, r]] -> solve (l*1.0) r a b) . map (map read . words) . lines
main = do
  a <- fmap (map read . words) getLine
  b <- fmap (map read . words) getLine
  [l,r] <- fmap (map read . words) getLine
  mapM (printf "%.1f\n") $ solve (l*1.0) r a b