#!/usr/bin/ruby
def fibcycle(div)
  a=b=c=1;i=2
  loop{
    c=(a+b)%div
    a=b;b=c
    break if a==0&&b==1
    i+=1
  }
  puts "f[#{i}]={0,1};main(n){for(n=2;n<#{i};n++)f[n]=(f[n-1]+f[n-2])%#{div};for(;scanf(\"%d\",&n),~n;printf(\"%d\\n\",f[n%#{i}]));}"
end
fibcycle(10000)