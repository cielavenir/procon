#!/usr/bin/ruby
gets;gets.split.zip(gets.split).each_with_index{|(a,b),i|a!=b&&puts(i+1,a,b)}
