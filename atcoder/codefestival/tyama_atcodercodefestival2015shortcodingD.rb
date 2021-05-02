#!/usr/bin/ruby
#剰余は環をなすため、貪欲法で解いて問題ない。
a,b=$<.map &:chomp;c=j=0;a.bytes{|x|c=(c+x-48)%10;c.to_s==b[j]&&(j+=1;c=0)};puts b.size-j+c==0?:YES: :NO