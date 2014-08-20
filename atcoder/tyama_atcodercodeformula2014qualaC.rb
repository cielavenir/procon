#!/usr/bin/ruby
#最高順位=行番号+(行数*列番号)
n,k=gets.split.map(&:to_i)
m=n.times.map{gets.split.map(&:to_i)}
next_idx=[0]*n
winner={}
n.times{|i_heat|
	winner_in_this_heat=[]
	begin
		k_prev=k
		(i_heat+1).times{|current_search|
			while current_search+n*next_idx[current_search]<k
				person=m[current_search][next_idx[current_search]]
				if winner.include?(person)
					k+=1
				else
					winner_in_this_heat<<person
					winner[person]=1
				end
				next_idx[current_search]+=1
			end
		}
	end while k_prev!=k
	puts winner_in_this_heat.sort*' '
}