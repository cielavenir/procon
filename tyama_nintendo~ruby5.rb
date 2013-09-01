#!/usr/bin/ruby
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
require 'prime'
s='*iszerothblockPicktwentytwogreenboxesOrdinalshavenodivisorsEachpairmeansxandynumn'
grid='154286973738914652692537481923758146861423795475691238516349827389172564247865319'
puts Prime.each.lazy.take(22).to_a.map{|e|
	p grid[e/9*9+e%9,1].to_i-1
}.each_slice(2).map{|x,y|
	s[y*9+(8-x),1]
}*'' # => Primenumber

$key=9
def trans_table
	alphabets = ["A".."Z", "a".."z", "0".."9"].map{|r| r.to_a.join}
	alphabets.map{|ab| [ab, ab[$key%ab.size..-1] + ab[0, $key%ab.size]]}.transpose.map{|a| a.join}
end
puts 'Prim'.tr(*trans_table) # => Yarv (Yet Another Ruby VM) # gee, decode(the(answer='Primenumber')).