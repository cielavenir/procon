#!/usr/bin/ruby
a=[]
gets.to_i.times{
	x,y=gets.chomp.split('-')
	x=(x.to_i/100*60+x.to_i%100)/5
	y=(y.to_i/100*60+y.to_i%100+4)/5
	a[x*2]=true
	(x*2+1).step(y*2-1,2){|i|a[i]=true}
}
i=0
while i<962
	if a[i]
		j=i+1
		while a[j] do j+=2 end
		j-=1
		puts "%02d%02d-%02d%02d\n"%[i/2/12,i/2%12*5,j/2/12,j/2%12*5]
		i=j
	end
	i+=2
end