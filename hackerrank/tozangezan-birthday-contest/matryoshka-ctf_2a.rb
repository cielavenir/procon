#!/usr/bin/ruby
loop{
	system("<data.zip funzip -bf-cbc >data.bin")
	break if File.binread('data.bin',2)!='PK'
	File.rename('data.bin','data.zip')
}