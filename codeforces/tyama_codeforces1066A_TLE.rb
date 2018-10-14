#!/usr/bin/ruby
gets;$<.read.split.map(&:to_i).each_slice(4){|_,v,l,r|p _/v-r/v+(l-1)/v}
