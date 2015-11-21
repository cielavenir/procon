#!/usr/bin/ruby
def dfs(current_string,current_digit,current_start)
	if current_string==N
		puts R[1..-1]
		exit
	elsif (A[current_string][0].size-current_digit)*3<A[current_string][1].size-current_start
	elsif A[current_string][0].size==current_digit
		dfs(current_string+1,0,0) if A[current_string][1].size==current_start
	elsif s=R[A[current_string][0][current_digit].to_i]
		if A[current_string][1][current_start,s.size]==s
			dfs(current_string,current_digit+1,current_start+s.size)
		end
	else
		3.downto(1){|i|
			next if current_start+i>A[current_string][1].size
			R[A[current_string][0][current_digit].to_i]=A[current_string][1][current_start,i]
			dfs(current_string,current_digit+1,current_start+i)
			R[A[current_string][0][current_digit].to_i]=nil
		}
	end
end

K,N=gets.split.map(&:to_i)
R=[nil]*(K+1)
A=N.times.map{gets.split}.sort_by{|v,w|v.size}
dfs(0,0,0)