#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/84255ac417ef25069a3b
#http://nabetani.sakura.ne.jp/hena/ord9busfare/
STDOUT.sync=true
while gets
	a=$_.chomp.split(':')
	fare=[a[0].to_i]
	fare[1]=(fare[0]/2+9)/10*10
	fare[2]=(fare[1]/2+9)/10*10
	a=a[1].split(',').map{|e|
		if e[0,1]=='A'
			['A',{'n'=>fare[0],'p'=>0,'w'=>fare[1]}[e[1,1]]]
		else
			[e[0,1],{'n'=>fare[1],'p'=>0,'w'=>fare[2]}[e[1,1]]]
		end
	}.group_by{|e|e[0]}
	a.default=[]
	p a['A'].map(&:last).reduce(0,:+)+a['C'].map(&:last).reduce(0,:+)+a['I'].map(&:last).sort[0..-1-a['A'].size*2].reduce(0,:+)
end