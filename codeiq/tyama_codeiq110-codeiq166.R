#!/usr/bin/Rscript
#cf: http://d.hatena.ne.jp/isseing333/20121224/1356279424
#問1
cat("Problem 1\n")
height1 <- c(168, 173, 152, 181, 175)
#(1)
cat(mean(height1)) # 169.8
cat("\n")
#(2)
cat(median(height1)) # 173
cat("\n")
#(3)
variance <- function(x) var(x)*(length(x)-1)/length(x)
cat(variance(height1)) # 96.56
cat("\n")
#(4)
cat(var(height1)) # 120.7
cat("\n")
#(5)
cat(sd(height1)) # 10.98636
cat("\n")
#(6)
se <- function(x) sd(x)/sqrt(length(x))
cat(se(height1)) # 4.913247
cat("\n")
#問2
cat("Problem 2\n")
#(1)
q2 <- function(x){
	cat(variance(x)) #35.48176
	cat("\n")
	cat(var(x)) #44.35221
	cat("\n")
	cat(sd(x)) #6.659745
	cat("\n")
	cat(se(x)) #2.978329
	cat("\n")
}
q2(170 + 10*rnorm(5))
#(2)
#標本分散と不偏分散はともに100に近づく
#不偏偏差は10に近づく
#標準誤差は0に近づく