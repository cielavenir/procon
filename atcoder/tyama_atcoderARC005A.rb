#!/usr/bin/ruby
p`tr -d .`.split.count{|e|["TAKAHASHIKUN","Takahashikun","takahashikun"].include? e}