#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/d819d1e5f2378317511e
#http://nabetani.sakura.ne.jp/hena/ord10pokarest/
STDOUT.sync=true
T={'2'=>2,'3'=>3,'4'=>4,'5'=>5,'6'=>6,'7'=>7,'8'=>8,'9'=>9,'1'=>10,'J'=>11,'Q'=>12,'K'=>13,'A'=>14}
while gets
	a=$_.chomp.gsub('0','').scan(/../).map{|e|[T[e[0,1]],e[1,1]]}.sort
	number=a.map{|e|e[0]}.uniq
	if a.none?{|e|e[1]!=a[0][1]} #flash
		if a[0][0]==10&&a[1][0]==11&&a[2][0]==12&&a[3][0]==13&&a[4][0]==14
			puts 'RF'
		elsif
			a[0][0]==2&&a[1][0]==3&&a[2][0]==4&&a[3][0]==5&&a[4][0]==14 ||
			0.step(3).all?{|i|a[i+1][0]-a[i][0]==a[1][0]-a[0][0]}
			puts 'SF'
		else
			puts 'FL'
		end
	elsif
		a[0][0]==2&&a[1][0]==3&&a[2][0]==4&&a[3][0]==5&&a[4][0]==14 ||
		4.times.all?{|i|a[i+1][0]-a[i][0]==a[1][0]-a[0][0]}
		puts 'ST'
	elsif (f=a.one?{|e|e[1]!=a[0][1]}) || a.one?{|e|e[1]!=a[1][1]} #4flash
		idx=f ? a.index{|e|e[1]!=a[0][1]} : 0
		a.delete_at(idx)
		if
			a[0][0]==2&&a[1][0]==3&&a[2][0]==4&&a[3][0]==14 ||
			0.step(2).all?{|i|a[i+1][0]-a[i][0]==a[1][0]-a[0][0]}
			puts '4SF'
		else
			puts '4F'
		end
	else
		if number.size==5 && (
			number[0]==2&&number[1]==3&&number[2]==4&&number[4]==14 ||
			0.step(2).all?{|i|number[i+1]-number[i]==number[1]-number[0]} ||
			1.step(3).all?{|i|number[i+1]-number[i]==number[2]-number[1]}
		) then puts '4S'
		elsif number.size==4 && (
			number[0]==2&&number[1]==3&&number[2]==4&&number[3]==14 ||
			0.step(2).all?{|i|number[i+1]-number[i]==number[1]-number[0]}
		) then puts '4S'
		else
			puts '-'
		end
	end
end