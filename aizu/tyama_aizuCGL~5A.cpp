#include <complex>
#include <vector>
#include <algorithm>
#include <cstdio>
#define sq(n) (n)*(n)
  
typedef std::pair<double, double> point_t;
typedef std::pair<point_t, point_t> points_t;
 
double distance_between(const point_t& a, const point_t& b){
	return sq(b.first-a.first)+sq(b.second-a.second);
}
 
double find_closest_brute(const std::vector<point_t>& points,int xl,int xr){
	int siz=xr-xl;
	if (siz < 2) {
		return 1e9;
	}
	auto minDistance = 1e9;
	for (auto i = xl; i < xr-1; ++i) {
		for (auto j = i + 1; j < xr; ++j) {
			auto newDistance = distance_between(points[i], points[j]);
			if (newDistance < minDistance) {
				minDistance = newDistance;
			}
		}
	}
	return minDistance;
}
 
double find_closest_optimized(
	const std::vector<point_t>& xP,
	int xl,int xr,
	const std::vector<point_t>& yP,
	int yl,int yr
){
	int xsiz=xr-xl;
	int ysiz=yr-yl;
	if (xsiz <= 8) {
		return find_closest_brute(xP,xl,xr);
	}
	if(ysiz==0)return 1e9;
	auto xM = xP[xl+xsiz/2].first;
	auto yL = std::vector<point_t>(ysiz);
	int left = -1, right = ysiz;
	for(int i = yl; i < yr; i++){
		if (yP[i].first < xM) yL[++left] = yP[i];
		else                  yL[--right]= yP[i];
	}
	std::reverse(yL.begin()+right,yL.end());
	auto p1 = find_closest_optimized(xP,xl,xl+xsiz/2,yL,0,left+1);
	auto p2 = find_closest_optimized(xP,xl+xsiz/2,xr,yL,left+1,ysiz);
	auto minD = sqrt((p1 < p2) ? p1 : p2);
	auto yS = std::vector<point_t>();
	std::copy_if(std::begin(yP), std::end(yP), std::back_inserter(yS), [&minD, &xM](const point_t& p) {
		return std::abs(xM - p.first) < minD;
	});
	auto result = minD*minD;
	if(yS.size()>=2)
	for (auto i = std::begin(yS); i != (std::end(yS) - 1); ++i) {
		for (auto k = i + 1; k != std::end(yS) &&
		 ((k->second - i->second) < minD); ++k) {
			auto newDistance = distance_between(*k, *i);
			if (newDistance < result) {
				result = newDistance;
			}
		}
	}
	return result;
}
  
int main(){
	std::vector<point_t> points;
	int i=0,n;
	double x,y;
	for(scanf("%d",&n);i<n;i++){
		scanf("%lf%lf",&x,&y);
		points.emplace_back(x,y);
	}
	std::sort(std::begin(points), std::end(points), [](const point_t& a, const point_t& b) {
		return a.first < b.first;
	});
	auto xP = points;
	std::sort(std::begin(points), std::end(points), [](const point_t& a, const point_t& b) {
		return a.second < b.second;
	});
	auto yP = points;
	auto r = find_closest_optimized(xP,0,n,yP,0,n);
	printf("%.9f\n",sqrt(r));
}