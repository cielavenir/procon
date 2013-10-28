#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/5c10c132e1f78131563f
#http://nabetani.sakura.ne.jp/hena/ord5dahimi/

# Since this requires special validator, grader version 1 is not applicable.
STDOUT.sync=true
T={'3'=>3,'4'=>4,'5'=>5,'6'=>6,'7'=>7,'8'=>8,'9'=>9,'T'=>10,'J'=>11,'Q'=>12,'K'=>13,'A'=>14,'2'=>15}
#S={'S'=>1,'D'=>2,'H'=>3,'C'=>4}
def pokersort(_a)
	_a.sort{|a,b|
		if a=='Jo'
			1
		elsif b=='Jo'
			-1
		else
			x=T[a[1,1]]<=>T[b[1,1]]
			#x!=0 ? x : S[a[0,1]]<=>S[b[0,1]]
		end
	}
end
def cards(s)
	pokersort(s.scan(/../))
end
while gets
	a=$_.split(',')
	if !a[1]|a[1]==''
		puts '-'
		next
	end
	field=cards(a[0])
	if field.size==1&&field[0]=='Jo'
		puts '-'
		next
	end
	fieldsize=field.size;fieldnum=T[field[0][1,1]]
	hand=cards(a[1])
	joker=false
	if hand.last=='Jo'
		joker=true
		hand.pop
	end
	result=[]
	group=hand.group_by{|e|T[e[1,1]]}
	(fieldnum+1).step(15){|i|
		if group[i]
			result+=group[i].combination(fieldsize).to_a+(joker&&fieldsize>1 ?group[i].combination(fieldsize-1).map{|e|e+['Jo']}:[])
		end
	}
	result<<['Jo'] if fieldsize==1&&joker
	puts result.empty? ? '-' : result.map(&:join)*','
end