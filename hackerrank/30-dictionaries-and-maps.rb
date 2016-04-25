#!/usr/bin/ruby
h={}
gets.to_i.times{
	h.store(*gets.split)
}
$<.each{|e|
	e.chomp!
	puts h.has_key?(e) ? "#{e}=#{h[e]}" : "Not found"
}