#以下において、#で始まっていない行がコードとして意味を持つものとする。
#【使用OSおよびバージョン】
#Mac OSX 10.9
#【使用言語およびバージョン】
#Ruby 2.0
#【解答】
ruby -e '[40,50,77].repeated_combination(11).find{|e|e.reduce(:+)==601}.chunk{|e|e}.each{|k,v|puts k.to_s+" "+v.size.to_s}'
#40 3
#50 5
#77 3