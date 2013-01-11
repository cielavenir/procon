#!/usr/bin/ruby
gets;s=1;gets.split.map(&:to_i).sort.all?{|e|e<=s&&s+=e};p s