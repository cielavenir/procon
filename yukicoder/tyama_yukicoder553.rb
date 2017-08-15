#!/usr/bin/ruby
def x(a,r,n)
  if n<0
    a/(1-r)
  else
    a*(1-r**n)/(1-r)
  end
end
def f0(n)
  Math.sqrt(x(0.81,0.81,n))/x(0.9,0.9,n)
end
def f(n)
  (f0(n)-f0(-1)) / (f0(1)-f0(-1)) * 1200
end
def g(n)
  2.0 ** (n/800.0)
end
def gi(n)
  800*Math.log(n,2)
end
def h(a)
  s=0
  r=1
  a.size.times{|i|
    r*=0.9
    s+=g(a[i])*r
  }
  gi(s / x(0.9,0.9,a.size)) - f(a.size)
end
p h($<.map(&:to_i).drop(1)).round
