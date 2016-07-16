#!/usr/bin/ruby
s=gets.chomp;puts s==s.tr('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ','#d#b##########oqp####vwx##A######HI###M#O####TUVWXY#').reverse ? :TAK : :NIE