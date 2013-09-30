#!/usr/bin/ruby
a=$<.read.split('class="question-summary"')
a.shift
a.each{|e|
	e=~/question-summary-(\d+)/
	id=$1
	e=~/ class="question-hyperlink"\>([^\<]+)\<\/a\>\<\/h3\>/
	article=$1
	e=~/ class="relativetime"\>([^\<]+)\<\/span\>/
	time=$1
	puts [id,article,time]*';'
}