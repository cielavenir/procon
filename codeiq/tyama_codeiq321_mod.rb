#!/usr/bin/ruby
id_bits=Hash.new(0)
name_bits=Hash.new(0)
$<.each_with_index{|e,i|
	ids,names=e.split('=').map{|f|f.strip.split}
	ids.each{|id|id_bits[id]|=1<<i}
	names.each{|name|name_bits[name]|=1<<i}
}
table=Hash.new{|h,k|h[k]={:id=>[],:name=>[]}}
id_bits.each{|k,v|table[v][:id]<<k}
name_bits.each{|k,v|table[v][:name]<<k}
puts table.each_value.map{|v|[v[:id].sort,v[:name].sort]}.sort_by{|e|e[1]}.map{|e|e[0]*' '+' = '+e[1]*' '}