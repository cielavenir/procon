#!/usr/bin/ruby
n,i=gets.to_i+1,0;n=(n+i^=1)/2 while n>1;puts [:Takahashi,:Aoki][i]