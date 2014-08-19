#!/usr/bin/ruby
class String
	def rotate(count=1)
		count+=self.length if count<0
		self.slice(count,self.length-count)+self.slice(0,count)
	end
end
str=gets.chomp
len=str.size
idx={}
len.times{|i|
	str2=str.rotate(i)
	idx[i]=str.size.times.select{|j|str2[j..j]=='o'}
}
p (1<<len).times.map{|i|
	a=Array.new(len)
	c=len.times.count{|j|
		idx[j].each{|k|a[k]=1} if i&(1<<j)!=0
	}
	a.all? ? c : len+1
}.min