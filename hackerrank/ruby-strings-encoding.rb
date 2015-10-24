def transcode(s)
	#s.encode('UTF-8','ISO-8859-1') # wtf?
	s.force_encoding('UTF-8')
end