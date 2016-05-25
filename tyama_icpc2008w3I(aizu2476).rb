#!/usr/bin/ruby
s=1;`sed 1d`.split.map(&:to_i).sort.all?{|e|e<=s&&s+=e};p s