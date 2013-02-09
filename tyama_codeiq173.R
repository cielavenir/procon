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

ks.test(scale(heightASmple),"pnorm")$p # 0.9970751
ks.test(scale(heightBSmple),"pnorm")$p # 0.883181
ks.test(scale(heightCSmple),"pnorm")$p # 0.8325801
#(rnormで生成しているので当然ではあるのだが)全て正規性があることを確認
var.test(heightASmple,heightBSmple)$p.value # 0.4786341
var.test(heightASmple,heightCSmple)$p.value # 0.2901904
#母分散は等しい。よってvar.equal=Tである。この条件下で問2は次のようになる。
t.test(heightASmple,heightBSmple,var.equal=T)$p.value # 0.3199286
#heightASmpleとheightBSmpleは群間差がある。
t.test(heightASmple,heightCSmple,var.equal=T)$p.value # 0.003280872
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
length(PvalAC[PvalAC>0.05])/length(PvalAC) # 0.067
#αエラーが発生する確率は6.7%
length(PvalAB[PvalAB<0.05])/length(PvalAB) # 0.051
#βエラーが発生する確率は5.1%