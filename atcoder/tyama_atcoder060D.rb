#!/usr/bin/ruby
f=->b,x{x<b ?x: f[b,x/b]+x%b};n,s=$<.map &:to_i;m=(n**0.5).to_i;p n<s ?-1:n>s ?(2..m).find{|b|f[b,n]==s}||m.downto(1).find{|b|(n-s)%b==0&&f[z=(n-s)/b+1,n]==s&&(break z)}||-1:n+1