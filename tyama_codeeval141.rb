#!/usr/bin/ruby
require 'time'

# MultiSAX: Ruby Gem to handle multiple SAX libraries
# https://github.com/cielavenir/multisax
module MultiSAX # minimal version
	class SAX
		@parser=nil
		def open(*list)
			list=[:libxml,:rexmlstream] if list.size==0
			list.each{|e_module|
				case e_module
					when :libxml
						begin
							require 'rubygems'
							require 'libxml'
						rescue LoadError;next end
						@parser=e_module;break
					when :rexmlstream
						require 'rexml/document'
						require 'rexml/parsers/streamparser'
						require 'rexml/streamlistener'
						@parser=e_module;break
				end
			}
			@parser
		end
		def reset() @parser=nil;@saxmodule=nil end

		def parse(source,listener)
			open if !@parser
			case @parser
				when :libxml
					listener.instance_eval{
						extend LibXML::XML::SaxParser::Callbacks
						alias :on_start_element :sax_tag_start
						alias :on_end_element :sax_tag_end
						alias :on_cdata_block :sax_cdata
						alias :on_characters :sax_text
						alias :on_comment :sax_comment
					}
				when :rexmlstream
					listener.instance_eval{
						extend REXML::StreamListener
						alias :tag_start :sax_tag_start
						alias :tag_end :sax_tag_end
						alias :cdata :sax_cdata
						alias :text :sax_text
						alias :comment :sax_comment
					}
			end

			if source.is_a?(String)
				case @parser
					when :libxml       then parser=LibXML::XML::SaxParser.string(source);parser.callbacks=listener;parser.parse
					when :rexmlstream  then REXML::Parsers::StreamParser.new(source,listener).parse
				end
			else
				case @parser
					when :libxml       then parser=LibXML::XML::SaxParser.io(source);parser.callbacks=listener;parser.parse
					when :rexmlstream  then REXML::Parsers::StreamParser.new(source,listener).parse
				end
			end
			listener
		end

	end
	Sax=SAX.new

	module Callbacks
		def sax_tag_start(tag,attrs) end
		def sax_tag_end(tag) end
		def sax_comment(text) end
		def sax_cdata(text) end
		def sax_text(text) end
	end
end

query=[]
while gets
	break if $_.start_with?('<?xml')
	a=$_.split('; (')
	query<<[a[0].to_f,a[1].split(', ').map{|e|e.to_f*Math::PI/180}]
end

listener=MultiSAX::Sax.parse($_+$<.read,Class.new{
	include MultiSAX::Callbacks
	def initialize
		@ids=[]
		@names=[]
		@confirmation=[]
		@timestamp=[]
		@coor=[]
		@current_tag=[]
	end
	attr_reader :ids,:names,:confirmation,:timestamp,:coor

	def sax_tag_start(tag,attrs)
		@current_tag.push(tag)
		@ids<<attrs['id'].to_i if tag=='Placemark'
	end
	def sax_tag_end(tag)
		if (t=@current_tag.pop)!=tag then raise "xml is malformed /#{t}" end
	end
	def sax_text(txt)
		if @current_tag==['kml','Document','Folder','Placemark','name']
			@names<<txt
		elsif @current_tag==['kml','Document','Folder','Placemark','TimeStamp','when']
			@timestamp<<Time.parse(txt).to_f
		elsif @current_tag==['kml','Document','Folder','Placemark','Point','coordinates']
			@coor<<txt.split(',').map{|e|e.to_f*Math::PI/180}
		end
	end
	def sax_cdata(txt)
		if @current_tag==['kml','Document','Folder','Placemark','description']
			if !(txt=~/Confirmation: \<b\>(\d+)\<\/b\> people/)
				raise txt
			end
			@confirmation<<$1.to_i
		end
	end
}.new)
a=listener.confirmation.zip(listener.timestamp,listener.ids,listener.coor,listener.names).sort_by{|confirmation,timestamp,id,coor2,name|
	[-confirmation,-timestamp,id]
}
query.each{|radius,coor1|
	result=[]
	num=nil
	a.each{|confirmation,timestamp,id,coor2,name|
		if radius>=6378.137*Math::acos( (Math::sin(coor1[1])*Math::sin(coor2[1])+Math::cos(coor1[1])*Math::cos(coor2[1])*Math::cos(coor1[0]-coor2[0])) )
			break if num&&num>confirmation
			result<<name
			num=confirmation
		end
	}
	if result.empty?
		puts :None
	else
		puts result*', '
	end
}