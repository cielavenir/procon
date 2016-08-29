//param
var ssl=true;
var formnum=0;

//code
var form=document.getElementsByTagName('form')[formnum];
var data='';
var tag=['input','select','textarea'];
for(var j=0;j<tag.length;j++){
	var elems=form.querySelectorAll(tag[j]);
	for(var i=0;i<elems.length;i++){
		if(data)data+='&';
		data+=encodeURIComponent(elems[i].name)+'='+encodeURIComponent(elems[i].value);
	}
}

//var parser1=document.createElement('a');
//parser1.href=location.href;
var parser2=document.createElement('a');
parser2.href=form.action;
var ret='';
ret+="require 'cgi'\n";
ret+="require 'net/https'\n";
ret+="http=Net::HTTP.new('"+parser2.hostname+"',"+(parser2.port||(ssl?443:80))+")\n";
if(ssl)ret+="http.use_ssl=true\n";
//if(ssl)ret+="http.verify_mode=OpenSSL::SSL::VERIFY_NONE\n"; //lol
ret+="http.start{|http|\n";
ret+="resp=http.post(\n";
ret+="'"+parser2.pathname+parser2.search+"',\n";
ret+="'"+data+"',\n";
ret+="{\n";
ret+="'Cookie'=>'"+document.cookie+"',\n";
ret+="'User-Agent'=>'"+navigator.userAgent+"',\n";
ret+="'Referer'=>'"+location.href+"',\n";
ret+="}\n";
ret+=")\n";
ret+="resp.header.each{|k,v|puts k+': '+v}\n";
ret+="puts resp.body\n";
ret+="}\n";

if(true){
	var textarea=document.createElement('textarea');
	textarea.textContent=ret;
	document.documentElement.appendChild(textarea);
	textarea.select();
	document.execCommand('copy');
	document.documentElement.removeChild(textarea);
}else{
	console.log(ret);
}