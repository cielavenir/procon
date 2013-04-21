#!/usr/bin/ruby
require 'mechanize'
mech=Mechanize.new
id=gets.chomp
mech.get('http://www.uniprot.org/uniprot/'+id+'.txt')
r=[]
mech.page.body.split("\n").each{|l|
	r<<$1 if l=~/DR   GO; GO:\d+; P:([^;]+);/
}
puts r