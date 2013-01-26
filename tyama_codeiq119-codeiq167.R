#cf: http://d.hatena.ne.jp/isseing333/20121224/1356279424
#問1
t=read.table('DataScience_ML1.csv',header=T,sep=',')
l=lm(y~x1+x2,t)
#問2
#(1)
plot(t)
#(2)
summary(l)$adj.r.squared
#(3)
plot(l$fitted,l$resid)
#(4)
plot(l$fitted,l$y)