#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/0597bd3af481e5834ae1
#http://nabetani.sakura.ne.jp/hena/ord14linedung/
STDOUT.sync=true
while gets
	l=$_.chomp
	monsters={}
	l.scan(/[A-Z]/).group_by{|e|e}.each{|k,v|monsters[(k.ord-'B'.ord)/2]=v.size}
	weapons={}
	weapons_queue=[]
	l.scan(/[a-z]/).uniq.each{|k,v|
		weapons[(k.ord-'a'.ord)/2]=1
		weapons_queue<<(k.ord-'a'.ord)/2
	}
	# gLDLBgBgHDaD
	# monsters={5=>2, 1=>3, 0=>2, 3=>1}
	# weapons={3=>1, 0=>1}
	# weapons_queue=[3, 0]
	n=0
	while weapons_queue.size>0
		weapon=weapons_queue.shift
		if monsters.has_key?(weapon)
			n+=monsters.delete(weapon)
			weapons_queue<<(weapon+1)%6 if !weapons.has_key?((weapon+1)%6)
		end
	end
	puts n
end