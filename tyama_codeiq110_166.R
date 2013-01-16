#cf: http://d.hatena.ne.jp/isseing333/20121224/1356279424
#問1
height1 <- c(168, 173, 152, 181, 175)
#(1)
mean(height1) #[1] 169.8
#(2)
median(height1) #[1] 173
#(3)
variance <- function(x) var(x)*(length(x)-1)/length(x)
variance(height1) #[1] 96.56
#(4)
var(height1) #[1] 120.7
#(5)
sd(height1) #[1] 10.98636
#(6)
se <- function(x) sd(x)/sqrt(length(x))
se(height1) #[1] 4.913247
#問2
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