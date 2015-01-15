var target='.GILNOSTUX_'
//var dict={}
var s=''
var t=''
var table=document.querySelector('#qCphrCd tbody').children
for(var i=0;i<table.length;i++){
	if(target.indexOf(table[i].children[0].textContent)<0)continue
	//dict[table[i].children[1].textContent.substr(0,2)]=table[i].children[0].textContent
	s+=table[i].children[1].textContent.substr(0,2)
	t+=table[i].children[0].textContent
}
//console.log(JSON.stringify(dict))
console.log(s)
console.log(t)