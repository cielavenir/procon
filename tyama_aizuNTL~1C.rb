require 'rational'
gets
p gets.split.map(&:to_i).reduce{|s,e|s=s/s.gcd(e)*e}