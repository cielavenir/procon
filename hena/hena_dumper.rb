#!/usr/bin/env ruby
#usage: ./val hena/hena_dumper.rb 2>&1 >/dev/null | pbcopy
while gets
	STDERR.puts $_
	puts
	STDOUT.flush
end
