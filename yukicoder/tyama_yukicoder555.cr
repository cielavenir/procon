#!/usr/bin/env crystal
M={[0,0]=>0}
def f(a,b,e);n,c,v=e;M[[a,b]]||=a<n ?[f(2*a,a,e)+c,f(a+b,b,e)].min+v: c end
p f 1,1,ARGF.gets_to_end.split.map &.to_i
