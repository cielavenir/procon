#!/usr/bin/ruby
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
#end of multisax

listener=MultiSAX::Sax.parse($<,Class.new{
	include MultiSAX::Callbacks
	def initialize
		@content=Hash.new(0)
		@current_tag=[]
	end
	attr_reader :content

	def sax_tag_start(tag,attrs)
		@current_tag.push(tag)
	end
	def sax_tag_end(tag)
		if (t=@current_tag.pop)!=tag then raise "xml is malformed /#{t}" end
	end
	def sax_text(text)
		if
			@current_tag==['root','document','sentences','sentence','tokens','token','lemma'] &&
			text.size>3 &&
			text!='-rrb-'&&text!='-lrb-' # brackets
		then
			@content[text]+=1
		end
	end
}.new)
puts listener.content.sort_by{|k,v|-v}[0,10].map(&:first)

__END__
request
that
response
server
field
header
cache
http/1
this
with

corenlp.shのデフォルトオプションを試みたところ、-Xmx4096m -Xms4096mでも落ちてしまったので、
corenlp.sh -annotators tokenize,ssplit,pos,lemma,ner,parseで2時間かけて解析した。
その出力を本ソースコードで集計した結果が上記である。
その後、corenlp.sh -annotators tokenize,ssplit,pos,lemmaの出力を集計した結果と一致することを確認した(こちらは10秒で結果が出力された)。
なお、http/1は本来は正しくないが、corenlp.xmlでそうなっているので、今回はそのままにした。