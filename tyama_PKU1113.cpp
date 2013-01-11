#include <cstdio>
#include <cmath>

/* class bidirectrical_ring */
template<typename T>class bidirectrical_ring;
template<typename T>
class bidirectrical_elem{
  friend class bidirectrical_ring<T>;
  private:
  T _data;
  bidirectrical_elem<T> *_prev,*_next;
  public:
  bidirectrical_elem(){_prev=_next=this;}
  const T &data() const{return _data;}
  const bidirectrical_elem<T> *prev() const{return _prev;}
  const bidirectrical_elem<T> *next() const{return _next;}
};
template<typename T>
class bidirectrical_ring{
  bidirectrical_elem<T> *head,*cur,*tail;
  unsigned _s;
  public:
  bidirectrical_ring(){head=cur=tail=NULL;_s=0;}
  const unsigned size() const{return _s;}
  const bidirectrical_elem<T> *get(){return cur;}
  void rotate_next(){if(_s)cur=cur->_next;}
  void rotate_prev(){if(_s)cur=cur->_prev;}
  void connect(){
    head->_prev=tail;
    tail->_next=head;
  }
  void insert(const T &d){
    bidirectrical_elem<T> *next=new bidirectrical_elem<T>();
    if(cur==tail)tail=next;
    _s++;
    next->_data=d;
    if(_s==1){head=cur=tail=next;return;}
    next->_prev=cur;next->_next=cur->_next;
    cur->_next->_prev=next;cur->_next=next;
    connect();
  }
  const T &erase(){
    //if(!_s){printf("erase() for empty bidirectrical_ring\n");exit(1);}
    if(_s==1){
      const T &d=cur->data();
      delete cur;head=cur=tail=NULL;_s=0;
      return d;
    }
    bidirectrical_elem<T> *t=cur;
    if(t==head)head=cur->_next;
    if(t==tail)tail=cur->_prev;
    const T &d=cur->data();
    cur=cur->_prev;
    cur->_next->_next->_prev=cur;cur->_next=cur->_next->_next;
    delete t;_s--;
    connect();
    return d;
  }
};

/* main */
struct Point{int x; int y;};
#define op(a1,b1,a2,b2) ((a1)*(b2)-(a2)*(b1))

int main(){
  int n,l,x,y,i,s;
  Point *p;
  bidirectrical_ring<Point*> b;
  scanf("%d%d",&n,&l);
  for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    p=new Point;
    p->x=x;p->y=y;
    b.insert(p);
    b.rotate_next();
  }
  s=n;i=0;
  for(;i<s;b.rotate_next()){
    if(op(b.get()->data()->x - b.get()->prev()->data()->x,
          b.get()->data()->y - b.get()->prev()->data()->y,
          b.get()->next()->data()->x - b.get()->data()->x,
          b.get()->next()->data()->y - b.get()->data()->y)<0)
      i++;
    else{
      b.erase();i=0;s--;
    }
  }
  double d=0;
  for(i=0;i<s;i++,b.rotate_next())
    //printf("%d %d\n",b.get()->data()->x,b.get()->data()->y),
    d+=hypot(b.get()->data()->x - b.get()->prev()->data()->x,
             b.get()->data()->y - b.get()->prev()->data()->y);
  printf("%d\n",(int)(0.5+d+2*l*3.14159));
  return 0;
}