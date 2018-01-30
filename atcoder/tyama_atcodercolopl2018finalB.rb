#!/usr/bin/ruby
o=[];gets.chars{|c|c==?,?$><<o[-1]:'+-*/'.index(c)?o<<c :$><<c;c==?)&&o.pop}
