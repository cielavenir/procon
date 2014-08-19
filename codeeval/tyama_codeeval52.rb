#!/usr/bin/ruby
A=['']+%w[One Two Three Four Five Six Seven Eight Nine Ten Eleven Twelve Thirteen Fourteen Fifteen Sixteen Seventeen Eighteen Nineteen]
B=%w[Twenty Thirty Forty Fifty Sixty Seventy Eighty Ninety]
def txt(x)
	s=''
	s+=A[x/100]+'Hundred' if x/100>0
	return s+A[x%100] if x%100<20
	s+B[x/10%10-2]+A[x%10]
end
while gets
	x=$_.to_i
	y=x/1000000000
	print txt(y)+'Billion' if y>0
	y=x/1000000%1000
	print txt(y)+'Million' if y>0
	y=x/1000%1000
	print txt(y)+'Thousand' if y>0
	y=x%1000
	print txt(y) if y>0
	puts 'Dollars'
end