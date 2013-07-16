#include <math.h>
#include <stdio.h>
#define p2(x) ((x)*(x))
#define UPDATE_H(h,expr) if(H<h){for(m=0;m<n;m++)if((expr)>p2(L[m])+1e-9)break;if(m==n)H=h;}
double X[10],Y[10],L[10],hypot_cache[10][10],PL[10][10],PX[10][10],PY[10][10];
int main(){
	int n,i,j,k,l,m;
	double H,h,px,py,pl,vx,vy,cx,cy,cl,t,d;
	for(;scanf("%d",&n),n;printf("%.7f\n",H)){
		H=-1;
		for(i=0;i<n;i++)scanf("%lf%lf%lf",X+i,Y+i,L+i);
		for(i=0;i<n;i++)for(j=i+1;j<n;j++)hypot_cache[i][j]=hypot_cache[j][i]=hypot(X[i]-X[j],Y[i]-Y[j]);
		for(i=0;i<n;i++)UPDATE_H(L[i],p2(L[i])+p2(hypot_cache[i][m])); //1D
		if(H<0)for(i=0;i<n;i++)for(j=i+1;j<n;j++){ //2D
			//三角形(長さL[i],L[j],hypot)に垂線を下ろす(長さpl)
			//連立方程式L[i]**2=t**2+pl**2,L[k]**2=(hypot-t)**2+pl**2の解は
			t=( p2(L[i])-p2(L[j])+p2(hypot_cache[i][j]) )/( 2*hypot_cache[i][j] );
			PL[i][j]=sqrt(p2(L[i])-p2(t));
			//座標はベクトルを伸縮させることで求まる
			PX[i][j]=X[i]+(X[j]-X[i])*t/hypot_cache[i][j];
			PY[i][j]=Y[i]+(Y[j]-Y[i])*t/hypot_cache[i][j];
			UPDATE_H(PL[i][j],p2(PL[i][j])+p2(PX[i][j]-X[m])+p2(PY[i][j]-Y[m]));
		}
		if(H<0)for(i=0;i<n;i++)for(j=i+1;j<n;j++){ //3D
			//http://topcoder.g.hatena.ne.jp/Mi_Sawa/20130712 ※素直にcomplex使いましょう、はい--;
			//(vx,vy)は(X[i]-X[j],Y[i]-Y[j])に直交する
			vx=Y[j]-Y[i];
			vy=X[i]-X[j];
			for(k=j+1;k<n;k++){
				//(px,py)->(X[k],Y[k])を(vx,vy)に正射影する(cx,cy)
				t=((X[k]-PX[i][j])*vx+(Y[k]-PY[i][j])*vy)/(vx*vx+vy*vy);
				cx=PX[i][j]+t*vx;
				cy=PY[i][j]+t*vy;
				cl=sqrt(p2(L[k])-p2(cx-X[k])-p2(cy-Y[k])); //(cx,cy)から(求める点)までの長さは√(L[k]**2-hypot(cx-X[k],cy-Y[k])**2)
				//(px,py),(cx,cy),(求める点)を通る平面はxy平面に対して垂直なので垂線を下ろせば良い
				d=hypot(cx-PX[i][j],cy-PY[i][j]);
				t=( p2(PL[i][j])-p2(cl)+p2(d) )/( 2*d );
				pl=sqrt(p2(PL[i][j])-p2(t));
				px=PX[i][j]+(cx-PX[i][j])*t/d;
				py=PY[i][j]+(cy-PY[i][j])*t/d;
				UPDATE_H(pl,p2(pl)+p2(px-X[m])+p2(py-Y[m]));
			}
		}
	}
return 0;}