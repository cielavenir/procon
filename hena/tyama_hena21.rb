#!/usr/bin/env ruby
#http://qiita.com/torazuka/items/cbdb6b581a57e4754dd4
#http://d.hatena.ne.jp/torazuka/20140509/yhpg
WEEKDAYS=5
STDOUT.sync=true
while gets
	cls=WEEKDAYS.times.map{[]}
	input=$_.chomp.split('|').map{|e|
		a=e.split('_')
		[a[0].to_i,a[1].chars.map{|e|e.to_i-1}]
	}
	WEEKDAYS.times{|i|
		j=0
		while j<input.size
			if cls[input[j][1][i]].size<4
				cls[input[j][1][i]]<< input[j][0]
				input.delete_at(j)
			else
				j+=1
			end
		end
	}
	ret=[]
	cls.each_with_index{|e,i|ret<< ((i+1).to_s+'_'+e.sort*':') if !e.empty?}
	#STDERR.puts ret*'|'
	puts ret*'|'
end