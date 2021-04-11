#!/usr/bin/ruby
t=gets.to_i
t.times{|i|
	print 'Case #%d: '%(i+1)
	r=0
	x,y,s=gets.split.zip([:to_i,:to_i,:to_s]).map{|x,y|x.send y}
	s=s.gsub(/\?+/,'?').gsub('C?C','C').gsub('J?J','J')
	s=s.sub(/^\?C/,'C').sub(/^\?J/,'J').sub(/C\?$/,'C').sub(/J\?$/,'J')
	s=s.gsub('C?J','CJ').gsub('J?C','JC')
	s=s.gsub(/C+/,'C').gsub(/J+/,'J')
	s.chars.each_cons(2){|a|s=a*'';r+=s=='CJ'?x:s=='JC'?y:0}
	p r
}
