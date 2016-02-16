#!/usr/bin/ruby
z=->(n){n<=N&&A<<n&&z[n*10+10/(n%10)]};d=->(n){M[n]||=A.map{|e|d[n/e]+n%e}.min};M={0=>0};N=gets.to_i;A=[];z[2];z[5];p d[N]