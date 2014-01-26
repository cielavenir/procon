#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/373105e7fafd12f5e9fd
#http://nabetani.sakura.ne.jp/hena/ord18mafovafo/
T={'L'=>'RVF','J'=>'FVR','Z'=>'FmRVF','U'=>'RVFVR','S'=>'FVRmF'}
STDOUT.sync=true
while gets
	puts $_.chomp.chars.reduce('F'){|s,e|
		s.chars.map{|c|c=='F' ? T[e] : c=='R' ? T[e].tr('FRmV','RFVm').reverse : c}*''
	}.tr('FR','')
end