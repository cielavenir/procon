#include <complex>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef complex<int> point;

struct kdtree {
  struct node {
    point p;
	int id;
    node *l, *r;
    node(const point &p,int _id)
      : p(p), l(NULL), r(NULL), id(_id) { }
  } *root;
  int id;
  kdtree() : root(NULL), id(0) { }

#define compare(d, p, q) (d ? real(p) < real(q) : imag(p) < imag(q))
  void insert(const point &p) {
    root = insert(root, 0, p);
  }
  node *insert(node *t, int d, const point &p) {
    if (t == NULL) return new node(p,id++);
    if (compare(d,p,t->p)) t->l = insert(t->l, !d, p);
    else                   t->r = insert(t->r, !d, p);
    return t;
  }
  void search(const point &ld, const point &ru, vector<int> &out) {
    search(root, 0, ld, ru, out);
  }
  void search(node *t, int d, const point &ld, const point &ru, vector<int> &out) {
    if (t == NULL) return;
    const point &p = t->p;
    if (real(ld) <= real(p) && real(p) <= real(ru) &&
        imag(ld) <= imag(p) && imag(p) <= imag(ru)) out.push_back(t->id);
    if (!compare(d,p,ld)) search(t->l, !d, ld, ru, out);
    if (!compare(d,ru,p)) search(t->r, !d, ld, ru, out);
  }
};

int main(){
	int n,x1,x2,y1,y2;
	kdtree kd;
	for(scanf("%d",&n);n--;){
		scanf("%d%d",&x1,&y1);
		kd.insert(point(x1,y1));
	}
	for(scanf("%d",&n);n--;){
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		vector<int>out;
		kd.search(point(x1,y1),point(x2,y2),out);
		sort(out.begin(),out.end());
		for(int i=0;i<out.size();i++)printf("%d\n",out[i]);
		puts("");
	}
}