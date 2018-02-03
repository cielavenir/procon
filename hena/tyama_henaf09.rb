#!/usr/bin/env ruby
#https://qiita.com/Nabetani/items/61e13fa5cf0abe5979be
#http://nabetani.sakura.ne.jp/hena/ordf09rotbox/

T={
'a'=>lambda{|e|e.tap{|_|_[0].rotate!(1)}},
'b'=>lambda{|e|e.tap{|_|_[1].rotate!(1)}},
'c'=>lambda{|e|e.tap{|_|_[2].rotate!(1)}},
'd'=>lambda{|e|e.transpose.tap{|_|_[0].rotate!(-1)}.transpose},
'e'=>lambda{|e|e.transpose.tap{|_|_[1].rotate!(-1)}.transpose},
'f'=>lambda{|e|e.transpose.tap{|_|_[2].rotate!(-1)}.transpose},
'g'=>lambda{|e|e.tap{|_|_[2].rotate!(-1)}},
'h'=>lambda{|e|e.tap{|_|_[1].rotate!(-1)}},
'i'=>lambda{|e|e.tap{|_|_[0].rotate!(-1)}},
'j'=>lambda{|e|e.transpose.tap{|_|_[2].rotate!(1)}.transpose},
'k'=>lambda{|e|e.transpose.tap{|_|_[1].rotate!(1)}.transpose},
'l'=>lambda{|e|e.transpose.tap{|_|_[0].rotate!(1)}.transpose},
}

$<.each{|e|($><<e.chomp.chars.reduce([[1,2,3],[4,5,6],[7,8,9]]){|s,e|T[e][s]}.map{|e|e*''}*'/'+"\n").flush}
