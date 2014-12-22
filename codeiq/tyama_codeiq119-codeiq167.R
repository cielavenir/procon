#!/usr/bin/Rscript
#cf: http://d.hatena.ne.jp/isseing333/20121224/1356279424
#問1
t=read.table('DataScience_ML1.csv',header=T,sep=',')
l=lm(y~x1+x2,t)
#問2
#(1)
pdf("167_1.pdf")
plot(t)
dev.off()
#(2)
cat(summary(l)$adj.r.squared)
cat("\n")
#(3)
pdf("167_2.pdf")
plot(l$fitted,l$resid)
dev.off()
#(4)
pdf("167_3.pdf")
plot(l$fitted,l$y)
dev.off()
#pdftk 167_1.pdf 167_2.pdf 167_3.pdf cat output 167.pdf
#rm -f 167_1.pdf 167_2.pdf 167_3.pdf