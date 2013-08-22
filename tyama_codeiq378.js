//【点数は「1 / 順位 * 100」の式で求めています。そして、各ラウンドの得点を合計して(総合)順位を求めています。】
//この情報が事前にわかっていたらもう少し頑張ったと思います。なので、少し残念な感はあります。

//interface:yourCode(Object arg) -> Object arg
//in:w         横 (500)
//in:h         縦 (500)
//in:cnt       今までに倒した数
//in:rngOut    爆弾降下で見える視界範囲(半径) (50 -> 75 -> 80 -> 80)
//in:rngIn     爆弾降下で敵を倒せる範囲(半径) (20 -> 25 -> 20 -> 25)
//io:saveDat   保存用データ(初期値はnull)
//in:hitEnemy
//in:viewEnemy 配列 {x: number, y: number, hit: boolean}
//out:x,y      砲撃座標
if(arg.saveDat==null){
	arg.saveDat={history:[{x:arg.w/2,y:arg.h/2}],next:[]};
	arg.x=arg.w/2;
	arg.y=arg.h/2;
}else{
	var last=arg.saveDat.history[arg.saveDat.history.length-1];
	//チューニングするべきパラメータ
	var N=60;
	var max=30; //10;
	var d=2.0;  //1.8; //2.0<=d<=rngOut/rngIn. 円の切れ目を気にする場合は1.5-2.0も可
	//N方向調べてmax以上のジャームが存在する方向がなければランダムジャンプする
	//todo: 三角形を作っていく？
	var max2=max;
	var max_idx=-1;
	var max_idx2=-1;
	for(var i=0;i<N;i++){
		var x=last.x+arg.rngIn*d*Math.cos(2*Math.PI*i/N);
		var y=last.y+arg.rngIn*d*Math.sin(2*Math.PI*i/N);
		var enemycnt=0;
		for(var j=0;j<arg.viewEnemy.length;j++){
			if(arg.viewEnemy[j].hit)continue;
			if((arg.viewEnemy[j].x-x)*(arg.viewEnemy[j].x-x)+(arg.viewEnemy[j].y-y)*(arg.viewEnemy[j].y-y)<=arg.rngIn*arg.rngIn)enemycnt++;
		}
		if(max2<enemycnt){
			if(max<enemycnt){
				if(i-max_idx>=N/4){
					max2=max;
					max_idx2=max_idx;
				}
				max=enemycnt;
				max_idx=i;
			}else if(i-max_idx>=N/4){ //tune
				max2=enemycnt;
				max_idx2=i;
			}
		}
	}
	var x,y;
	if(max_idx==-1){
		if(arg.saveDat.next.length){
			var next=arg.saveDat.next.shift();
			x=next.x;
			y=next.y;
		}else{
			for(;;){
				x=arg.rngIn+Math.random()*(arg.w-2*arg.rngIn);
				y=arg.rngIn+Math.random()*(arg.h-2*arg.rngIn);
				//avoid useless jump
				var j=0;
				for(;j<arg.saveDat.history.length;j++){
					if((arg.saveDat.history[j].x-x)*(arg.saveDat.history[j].x-x)+(arg.saveDat.history[j].y-y)*(arg.saveDat.history[j].y-y)<arg.rngOut*arg.rngOut)break;
				}
				if(j==arg.saveDat.history.length)break; //this (x,y) is meaningful jump.
			}
		}
	}else{
		if(max_idx2!=-1){
			x=last.x+arg.rngIn*d*Math.cos(2*Math.PI*max_idx/N);
			y=last.y+arg.rngIn*d*Math.sin(2*Math.PI*max_idx/N);
			arg.saveDat.next.push({x:x,y:y}); //this strategy isn't working very well...
		}
		x=last.x+arg.rngIn*d*Math.cos(2*Math.PI*max_idx/N);
		y=last.y+arg.rngIn*d*Math.sin(2*Math.PI*max_idx/N);
	}
	arg.x=x,arg.y=y;
	arg.saveDat.history.push({x:x,y:y});
}
return arg;