#!/usr/bin/ruby
h={
9=>'thinking about cool hay in the summertime',
16=>'thinking of a handsome bull she once met'
}
h.default='thinking something'
puts h[gets.to_i]