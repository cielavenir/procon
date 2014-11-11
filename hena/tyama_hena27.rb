#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
#http://nabetani.sakura.ne.jp/hena/ord27raswi/

T=[
	[
		["abc","gc","gh"],
		["ab","ge"],
		["abc","gc","ghi"],
	],[
		["dc","h"],
		["de"],
		["hi","dc"],
	],[
		["bc","fgc","fgh"],
		["b","fge"],
		["bc","fgc","fghi"],
	],
]

require 'lambda_driver'
module Enumerable
	def none_with_proc?(proc) none?(&proc) end
end

if $0==__FILE__
	STDOUT.sync=true
	while gets
		result=T.flat_map.with_index(1){|e,i|
			e.map.with_index(4).select{|f,j|
				f.any?(&:chars >> (:none_with_proc?.with_args($_._(:include?))))
				#f.any?{|g|g.chars.none?(&$_.method(:include?))}
			}.map{|f,j|i.to_s+j.to_s}
		}*','
		puts result.empty? ? '-' : result
	end
end