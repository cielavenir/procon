#!/usr/bin/Rscript
set.seed(1)
heightA <- 170 + 10*rnorm(100000)
set.seed(2)
heightB <- 170 + 10*rnorm(100000)
set.seed(3)
heightC <- 175 + 10*rnorm(100000)

#問1
set.seed(11)
heightASmple <- sample(heightA,100) #(1)
set.seed(12)
heightBSmple <- sample(heightB,100) #(2)
set.seed(13)
heightCSmple <- sample(heightC,100) #(3)

cat("Problem 2\n")
cat(ks.test(scale(heightASmple),"pnorm")$p.value) # 0.9970751
cat("\n")
cat(ks.test(scale(heightBSmple),"pnorm")$p.value) # 0.883181
cat("\n")
cat(ks.test(scale(heightCSmple),"pnorm")$p.value) # 0.8325801
cat("\n")
#(rnormで生成しているので当然ではあるのだが)全て正規性があることを確認
cat(var.test(heightASmple,heightBSmple)$p.value) # 0.4786341
cat("\n")
cat(var.test(heightASmple,heightCSmple)$p.value) # 0.2901904
cat("\n")
#0.05より大きい、従って母分散は等しい。よってvar.equal=Tである。この条件下で問2は次のようになる。
cat(t.test(heightASmple,heightBSmple,var.equal=T)$p.value) # 0.3199286
cat("\n")
#heightASmpleとheightBSmpleは群間差がある。
cat(t.test(heightASmple,heightCSmple,var.equal=T)$p.value) # 0.003280872
cat("\n")
#heightASmpleとheightCSmpleは群間差がない。

#問3
PvalAB <- NA
PvalAC <- NA

#(1)
for( i in 1:1000 ){
heightASmple <- sample(heightA,100)
heightBSmple <- sample(heightB,100)
PvalAB[i] = t.test(heightASmple,heightBSmple,var.equal=T)$p.value
}

#(2)
for( i in 1:1000 ){
heightASmple <- sample(heightA,100)
heightCSmple <- sample(heightC,100)
PvalAC[i] = t.test(heightASmple,heightCSmple,var.equal=T)$p.value
}

#問4
cat("Problem 4\n")
cat(length(PvalAB[PvalAB<0.05])/length(PvalAB)) # 0.051
cat("\n")
#αエラーが発生する確率は5.1%
cat(length(PvalAC[PvalAC>0.05])/length(PvalAC)) # 0.067
cat("\n")
#βエラーが発生する確率は6.7%