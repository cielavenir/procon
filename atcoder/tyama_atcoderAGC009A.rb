#!/usr/bin/ruby
r=0;gets;$<.to_a.reverse_each{|_|m,v=_.split.map &:to_i;x=(m+r)%v;x>0&&r+=v-x};p r
__END__
n=gets.to_i;a=n.times.map{gets.split.map &:to_i};r=0;n.times{|i|m,v=a[n-i-1];x=(m+r)%v;x>0&&r+=v-x};p r
