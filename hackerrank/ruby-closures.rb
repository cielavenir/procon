#!/usr/bin/ruby
def block_message_printer
	message = "Welcome to Block Message Printer"
	if block_given?
		yield
	end
	puts "But in this function/method message is :: #{message}"
end

message = gets
block_message_printer { puts "This message remembers message :: #{message}" }

#####################################################################################

def proc_message_printer(my_proc)
	message = "Welcome to Proc Message Printer"
	my_proc[]
	puts "But in this function/method message is :: #{message}"
end

my_proc = proc { puts "This message remembers message :: #{message}" }
proc_message_printer(my_proc)

######################################################################################
	
def lambda_message_printer(my_lambda)
	message = "Welcome to Lambda Message Printer"
	my_lambda[]
	puts "But in this function/method message is :: #{message}"
end

my_lambda = -> { puts "This message remembers message :: #{message}" }
lambda_message_printer(my_lambda)

######################################################################################