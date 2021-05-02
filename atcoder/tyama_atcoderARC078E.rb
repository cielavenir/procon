#!/usr/bin/ruby
out=->*a{$>.<<("%s %d\n"%a).flush}
ask=->n{out[??,n];gets.chomp=='Y'}
put=->n{out[?!,n];exit}
ask[i=10**9]?(i=1;loop{ask[i*2]&&put[i];i*=10}):loop{ask[i]&&put[(i+1..i*10-1).bsearch{|e|ask[e*10+9]}];i/=10}
