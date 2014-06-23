#!/usr/bin/ruby
#coding:utf-8
Encoding.default_external='UTF-8'
S=$<.read
#S='bddsowntdntdtthnhynhjweoaaabtmntdaaatddbtbnhjsefbbdsetvsdweontd'
s=''
freq=Hash.new(0)
i=0
while i<S.size
	if ('a'..'z').include?(S[i])
		freq[S[i..i+2]]+=1
		s+='['+S[i..i+2]+']'
		i+=3
	else
		s+=S[i]
		i+=1
	end
end
#p freq.sort_by{|k,v|-v};exit
#[["aaa", 547], ["soq", 382], ["sow", 256], ["nhj", 236], ["ntd", 228], ["svs", 227], ["sef", 225], ["btm", 210], ["nhy", 205], ["bas", 146], ["weo", 144], ["bmg", 140], ["ngf", 116], ["bdd", 110], ["vsd", 88], ["rgb", 84], ["mfl", 59], ["tok", 51], ["btr", 51], ["fjd", 44], ["tth", 40], ["set", 38], ["bbd", 21], ["cmk", 9], ["zhy", 2], ["btb", 1]]
#3660
#3113
#12.2% / 8.2% / 7.6%

=begin
s.gsub!('[aaa]',' ')
s.gsub!('[soq]','e')
s.gsub!('[sow]','t')
s.gsub!('[nhj]','a')
s.gsub!('[ntd]','o')
s.gsub!('[svs]','i')
s.gsub!('[sef]','n')
s.gsub!('[btm]','s')
s.gsub!('[nhy]','h')
=end
s.gsub!('[aaa]',' ')
s.gsub!('[soq]','e')
s.gsub!('[sow]','n')
s.gsub!('[nhj]','i')
s.gsub!('[ntd]','s')
s.gsub!('[svs]','r')
s.gsub!('[sef]','a')
s.gsub!('[btm]','t')
s.gsub!('[nhy]','d')
#a=s.split
#a.sort_by{|e|[e.length,e]}.each{|e|p e}

puts s