#!/usr/bin/ruby
def encode(n) '%02d:%02d'%[n/60,n%60] end
def decode(s)
	h,m=s.split(':').map(&:to_i)
	h*60+m
end
puts encode((decode(gets)+gets.to_i)%1440)