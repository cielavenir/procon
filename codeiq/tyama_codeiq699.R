#!/usr/bin/Rscript
myhist <- function(x,..., breaks="Sturges",
                   main = paste("Histogram of", xname),
                   xlab = xname,
                   ylab = "Frequency") {
  h = hist(x, breaks=breaks, plot=FALSE)
  plot(h$breaks, c(NA,h$counts), type='S', main=main,
       xlab=xlab, ylab=ylab, axes=FALSE, ...)
  #axis(1)
  axis(2)
  lines(h$breaks, c(h$counts,NA), type='s')
  lines(h$breaks, c(NA,h$counts), type='h')
  lines(h$breaks, c(h$counts,NA), type='h')
  lines(h$breaks, rep(0,length(h$breaks)), type='S')
  invisible(h)
}

data=read.csv('Homicides_by_sex2.csv',header=T,nrows=193)
male=data[,10]
female=data[,11]
#print(max(male)) # 131.7
pdf('homicide.pdf',family='Japan1')
#1A
hist(male,breaks=seq(0,150,30),xaxt='n',main='男性殺人被害者数のヒストグラム',xlab='人数',ylab='頻度')
axis(1, at=seq(0,150,30))
#1B
#対数ヒストグラムってy軸のことだろうか。x軸を対数だったらbreaksを指数にしないといけないし。
myhist(male,breaks=seq(0,150,30),xaxt='n',main='男性殺人被害者数のヒストグラム(対数表示)',xlab='人数',ylab='頻度',log='y')
axis(1, at=seq(0,150,30))

#2A
plot(female,male,main='女性と男性の殺人被害者数の散布図',xlab='女性',ylab='男性')
#2B
#0を対数表示させる方法はいくつかあると思うのだけど、今回は+0.1する方針。
plot(female+0.1,male+0.1,main='女性と男性の殺人被害者数の散布図 (対数表示)',xlab='女性',ylab='男性',log='xy')
dev.off()