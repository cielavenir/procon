#!/usr/bin/env python
#coding:utf-8
#This code is compatible both on Python2 and Python3.
import sys,time,random,hmac,hashlib,json,time
from collections import Counter
if sys.version_info[0]<3:
	import urllib,urllib2,codecs
	urllib.build_opener=urllib2.build_opener
	sys.stdout = codecs.getwriter('utf-8')(sys.stdout)
else:
	import base64,urllib.request,urllib.parse
	urllib.build_opener=urllib.request.build_opener
	urllib.quote=urllib.parse.quote
	urllib.urlencode=urllib.parse.urlencode

#oauth
consumer_key = 'p5QG3KTa3Oli4MW83Y5KA'
consumer_secret = '9mjIkfPrDSZIeRTBt8SXSxhcCVQleNRScDGVyIL4Y'
#Hard coded token. Use one of:
#https://www.dropbox.com/s/mj92ccgvwoit746/oauth_oob.cgi
#https://www.dropbox.com/s/mj92ccgvwoit746/oauth_oob.pl
#https://www.dropbox.com/s/mj92ccgvwoit746/oauth.cgi
oauth_token = ''
oauth_token_secret = ''

oauth={
	'oauth_consumer_key': consumer_key,
	'oauth_token': oauth_token,
	'oauth_signature_method': 'HMAC-SHA1',
	'oauth_version': '1.0',
}

#API params
#「過去のつぶやき」とは？自分のつぶやきか検索のことか。
method='GET'
url='https://api.twitter.com/1.1/statuses/user_timeline.json'
max_tweet = 3200
count = 200
page = max_tweet // count
params={'count':str(count)}
urls=[]

for i in range(page):
	oauth['oauth_timestamp']=str(int(time.time())) #unixtime
	oauth['oauth_nonce']=str(random.getrandbits(64)) #random
	# --- cited from http://d.hatena.ne.jp/Yoshiori/touch/20100929/1285727199 ---
	# --- slightly modified to support both GET and POST APIS ---
	# パラメータの値が unicode だったらエンコードします
	for k,v in params.items():
		if i==0 and (sys.version_info[0]>=3 or isinstance(v, unicode)): params[k] = v.encode('utf8')
		oauth[k]=params[k]
	# パラメータをソートし，URIエンコードした key=value の形にして & で繋げます
	oauth_str='&'.join([urllib.quote(key,'')+'='+urllib.quote(oauth[key],'~') for key in sorted(oauth)])
	for k in params.keys(): del oauth[k] #Fixed on Jun 6
	# メソッド，URIエンコードした URL,上で作ったパラメータ文字列を & で繋げます
	message=method+'&'+urllib.quote(url,'')+'&'+urllib.quote(oauth_str,'')
	# キーを元に message で hmac を作成します
	signature=hmac.new((consumer_secret+'&'+oauth_token_secret).encode('utf8'),message.encode('utf8'),hashlib.sha1).digest()
	if sys.version_info[0]<3:
		oauth['oauth_signature'] = signature.encode('base64').strip()
	else:
		oauth['oauth_signature'] = base64.b64encode(signature)
	# パラメータをソートし，URIエンコードした key=value の形にして , で繋げます
	header_oauth_str=','.join([urllib.quote(k,'')+'='+urllib.quote(oauth[k],'~') for k in sorted(oauth)])
	del oauth['oauth_signature'] #oauthオブジェクトを使いまわせるよう、signatureは破棄する必要があります。Fixed on Jul 5
	# ヘッダに Authorization:OAuth + 上で作成した文字列を追加します
	opener = urllib.build_opener()
	opener.addheaders = [('Authorization','OAuth '+header_oauth_str)]
	# あとは普通に API を呼び出します
	if method=='POST':
		tweets=json.loads(opener.open(url,urllib.urlencode(params)).read().decode('utf8'))
	else:
		tweets=json.loads(opener.open(url+'?'+urllib.urlencode(params)).read().decode('utf8'))
	# --- cite end, my own scraping code follows ---
	if url=='https://api.twitter.com/1.1/search/tweets.json': tweets=tweets['statuses']
	for tweet in tweets:
		if tweet['entities'] and tweet['entities']['urls']:
			urls+=[e['expanded_url'] or e['url'] for e in tweet['entities']['urls']]
		params['max_id']=str(int(tweet['id'])-1)

print('url,tweet_count')
counter=Counter(urls)
for k,v in counter.most_common():
	print(k+','+str(v))