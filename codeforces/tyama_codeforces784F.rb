#!/usr/bin/ruby
require 'timeout'
begin
	timeout(1){loop{}}
rescue Timeout::Error
	puts gets.split.map(&:to_i)[1..-1].sort*' '
end
