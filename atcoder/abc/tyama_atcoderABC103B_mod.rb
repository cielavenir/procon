#!/usr/bin/ruby
a,b=$<.map(&:chop);puts (a+a).index(b)?:Yes: :No
