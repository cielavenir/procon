#!/usr/bin/ruby
combo=0
damage=0

kaburin=5
queue=[]
charge=0

#ここをeach_charにするとTLEします
gets.chomp.each_byte.with_index{|c,i|
	if charge>0
		charge-=1
	elsif c==78
		if kaburin>=1
			queue<<7
			damage+=10+combo/10*1
			kaburin-=1
		end
	elsif c==67
		if kaburin>=3
			queue+=[9]*3
			damage+=50+combo/10*5
			charge=2
			kaburin-=3
		end
	end

	#kaburin's return
	queue2=queue
	queue=[]
	fcombo=0
	queue2.each{|e|
		n=e-1
		fcombo=1 if n==5
		if n==0
			kaburin+=1
		else
			queue<<n
		end
	}
	combo+=fcombo
}
puts damage