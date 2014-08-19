#!/usr/bin/ruby
require 'mechanize'
mech=Mechanize.new
id=gets.chomp
mech.get('http://www.uniprot.org/uniprot/'+id+'.txt')
mech.page.body.split("\n").each{|l|
	puts $1 if l=~/DR   GO; GO:\d+; P:([^;]+);/
}