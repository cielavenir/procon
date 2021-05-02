#!/usr/bin/ruby
K=gets.to_i;M=K%Z=50;p Z,*(1..Z).map{|i|K/Z+49+(i<=M ? 1:-M)}
