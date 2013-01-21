#!/usr/bin/ruby
require 'mechanize'
mech=Mechanize.new
while gets
id=$_.chomp
mech.get('http://www.uniprot.org/uniprot/'+id+'.fasta')
seq=mech.page.body.split("\n")[1..-1].join
a=(0..seq.length-4).find_all{|i|seq[i,4]=~/N[^P][ST][^P]/}.map{|e|e+1}
if a.size>0
	puts id
	puts a.join' '
end
end