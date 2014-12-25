require 'digest/md5'
require 'zip'
Zip.warn_invalid_date = false # grep -v Invalid
puts DATA.read
(1..20).each{|i|
	puts '>'+i.to_s
	Zip::File.open('%02d.zip'%i){|zip|
		zip.each{|entry|
			#if entry.name.start_with?('test_in/')
				content = entry.get_input_stream.read
				puts Digest::MD5.hexdigest(content.chomp)
			#end
		}
	}
}

__END__
#!/usr/bin/ruby
require 'digest/md5'
def parsefasta(f)
	ret=Hash.new{|h,k|h[k]=[]}
	head=f.gets.chomp[1..-1]
	data=[]
	while line=f.gets
		if line.start_with?('>')
			ret[head.to_i]=data
			head=line.chomp[1..-1]
			data=[]
		else
			data<<line.chomp
		end
	end
	ret
end
data=parsefasta(DATA)
input=Digest::MD5.hexdigest($<.read.chomp)
puts (1..20).select{|e|data[e].include?(input)}*' '

__END__