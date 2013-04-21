#!/usr/bin/ruby
class String
	def complement
		self.reverse.tr("ATGC","TACG")
	end
end
a=$<.map(&:chomp)
b=a.map(&:complement)
l=a[0].length
(l-1).downto(1){|k|
	h1={}
	h2={}
	#de Brujin graph
	a.each{|s|(l-k).times{|i|h1[s[i,k]]=s[i+1,k]}}
	b.each{|s|(l-k).times{|i|h2[s[i,k]]=s[i+1,k]}}
	f=x=h1.keys[0]
	s=''
	while h1[x]||h2[x]
		s+=x[-1,1]
		x = h1[x] ? h1.delete(x) : h2.delete(x)
		if x==f
			puts s
			exit
		end
	end
}
raise 'some of reads are corrupted'