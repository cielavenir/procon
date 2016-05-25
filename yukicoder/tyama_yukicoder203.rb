#!/usr/bin/ruby
p`dd`.split.join.scan(/o*/).map(&:size).max
#p`tr -d '\n'`.scan(/o*/).max.size