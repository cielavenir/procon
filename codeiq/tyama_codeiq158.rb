#!/usr/bin/ruby
256.times{|i|$><<"%08b"%[i^i>>1]}