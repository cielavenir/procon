#!/usr/bin/ruby
s=q=1;gets;gets.split.map{|e|q|=q<<e=e.to_i;s+=e};s/=2;q=(q>>s<<s).to_s 2;p q.size+~q.rindex(?1)
