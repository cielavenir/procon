#!/usr/bin/ruby
class String
	def transcript
		#self.tr("ATGCU","UACGA")
		self.tr('T','U')
	end
	def complement
		self.reverse.tr("ATGC","TACG")
	end
	def indexes(str)
		(0..self.length-str.length).select{|i|self[i,str.length]==str}
	end
end
codon={"UUU"=>"F","UUC"=>"F","UUA"=>"L","UUG"=>"L","UCU"=>"S","UCC"=>"S","UCA"=>"S","UCG"=>"S","UAU"=>"Y","UAC"=>"Y","UGU"=>"C","UGC"=>"C","UGG"=>"W","CUU"=>"L","CUC"=>"L","CUA"=>"L","CUG"=>"L","CCU"=>"P","CCC"=>"P","CCA"=>"P","CCG"=>"P","CAU"=>"H","CAC"=>"H","CAA"=>"Q","CAG"=>"Q","CGU"=>"R","CGC"=>"R","CGA"=>"R","CGG"=>"R","AUU"=>"I","AUC"=>"I","AUA"=>"I","AUG"=>"M","ACU"=>"T","ACC"=>"T","ACA"=>"T","ACG"=>"T","AAU"=>"N","AAC"=>"N","AAA"=>"K","AAG"=>"K","AGU"=>"S","AGC"=>"S","AGA"=>"R","AGG"=>"R","GUU"=>"V","GUC"=>"V","GUA"=>"V","GUG"=>"V","GCU"=>"A","GCC"=>"A","GCA"=>"A","GCG"=>"A","GAU"=>"D","GAC"=>"D","GAA"=>"E","GAG"=>"E","GGU"=>"G","GGC"=>"G","GGA"=>"G","GGG"=>"G","UAG"=>:stop,"UGA"=>:stop,"UAA"=>:stop}
h={}
s=gets.chomp

s.transcript.indexes('AUG').each{|i|
	z=''
	zz=''
	s[i..-1].transcript.chomp.each_slice(3){|e|
		if codon[x=e.join]==:stop then zz=z;break end
		break if !codon[x]
		z<<codon[x]
	}
	h[zz]=1 if zz!=''
}
s=s.complement
s.transcript.indexes('AUG').each{|i|
	z=''
	zz=''
	s[i..-1].transcript.chomp.each_slice(3){|e|
		if codon[x=e.join]==:stop then zz=z;break end
		break if !codon[x]
		z<<codon[x]
	}
	h[zz]=1 if zz!=''
}
h.keys.each{|e|puts e}