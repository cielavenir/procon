def f(n) r=1.0;(1..1/0.0).find{|i|(r=r*(n-i)/n)<=0.5}+1 end
p f(10000)