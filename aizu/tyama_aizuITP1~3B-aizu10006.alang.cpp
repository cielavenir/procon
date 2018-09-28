const char *CODE= 
	"Ai0"
	"AnId"
	"W"
	" POSCase \\"
	" POAi+i1"
	" POS: \\"
	" POn"
	" POMc10"
	" AnId"
;

// https://github.com/snukent/a
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;

class Interpreter {
 public:
  void Run(const std::string& code,
                 std::istream* input,
                 std::ostream* output);
 private:
  enum Type { NONE, DEF, INT, FLOAT, STR, ARRAY};
  typedef std::string::const_iterator State;
  struct Data {
    Type type;
    void* p;
    Data();
    Data(Type type, void* p);
    bool operator<(const Data& x) const;
    bool operator==(const Data& x) const;
    inline long long& Int() const { return *(long long*)p;}
    inline double& Float() const { return *(double*)p;}
    inline std::string& Str() const { return *(std::string*)p;}
    inline std::vector<Data>& Array() const { return *(std::vector<Data>*)p;}
  };
  static const double EPS;
  static const int MAX_POOL_INT;
  static const int MAX_POOL_FLOAT;
  static const int MAX_POOL_STR;
  static const int MAX_POOL_ARRAY;
  std::vector<long long> pool_int_;
  std::vector<double> pool_float_;
  std::vector<std::string> pool_str_;
  std::vector<std::vector<Data> > pool_array_;
  std::istream* input_;
  std::ostream* output_;
  std::ostringstream error_;
  std::vector<Data> vars_;
  void InitVars();
  Data NewInt(long long x);
  Data NewFloat(double x);
  Data NewStr(const std::string& x);
  Data NewArray(const std::vector<Data>& x);
  Data Expr(State& cur);
  Data& Vector(State& cur, Data& x);
  Data& Var(State& cur);
  Data Defined(State& cur);
  Data Exec(State& cur, State& fcur);
  Data Func(State& cur);
  Data Num(State& cur);
  Data Str(State& cur);
  Data SubStr(State& cur);
  Data EditStr(State& cur);
  Data Assign(State& cur);
  Data Input(State& cur);
  Data Length(State& cur);
  char tmp_s[128];
  Data Format(State& cur);
  Data Pair(State& cur);
  void Print(Data x);
  Data Output(State& cur);
  void Skip(State& cur);
  Data Cond(State& cur);
  Data Repeat(State& cur);
  Data Loop(State& cur);
  Data Operate(State& cur);
};

const int Interpreter::MAX_POOL_INT   = 10000000;
const int Interpreter::MAX_POOL_FLOAT = 1000000;
const int Interpreter::MAX_POOL_STR   = 1000000;
const int Interpreter::MAX_POOL_ARRAY = 1000000;

Interpreter::Data::Data() : type(NONE), p(NULL) {}
Interpreter::Data::Data(Type type, void* p) : type(type), p(p) {}

bool Interpreter::Data::operator<(const Data& x) const {
  if (type == NONE || x.type == NONE) return false;
  if (type == INT) {
    if (x.type == INT) return Int() < x.Int();
    else return Int() < x.Float() + EPS;
  } else if (type == FLOAT) {
    if (x.type == INT) return Float() < x.Int() + EPS;
    else return Float() < x.Float() + EPS;
  } else if (type == ARRAY) return Array() < x.Array();
  else return Str() < x.Str();
}

bool Interpreter::Data::operator==(const Data& x) const {
  if (type == NONE && x.type == NONE) return true;
  if (type == NONE || x.type == NONE) return false;
  if (type == INT) {
    if (x.type == INT) return Int() == x.Int();
    else return abs(Int() - x.Float()) < EPS;
  } else if (type == FLOAT) {
    if (x.type == INT) return abs(Float() - x.Int()) < EPS;
    else return abs(Float() - x.Float()) < EPS;
  } else if (type == ARRAY) return Array() == x.Array();
  else return Str() == x.Str();
}

const double Interpreter::EPS = 1e-10;

void Interpreter::Run(const std::string& code,
                            std::istream* input,
                            std::ostream* output) {
  input_ = input;
  output_ = output;
  InitVars();
  State cur = code.begin();
  while (*cur != '\0') Expr(cur);
}

void Interpreter::InitVars() {
  pool_int_.reserve(MAX_POOL_INT);
  pool_float_.reserve(MAX_POOL_FLOAT);
  pool_str_.reserve(MAX_POOL_STR);
  pool_array_.reserve(MAX_POOL_ARRAY);
  vars_ = std::vector<Data>(256);
  std::string defs = "AFILMOPRSTUVW?!~-+*/%&|^{}<>=#";
  for (int i = 0; i < (int)defs.size(); ++i) vars_[defs[i]].type = DEF;
}

Interpreter::Data Interpreter::NewInt(long long x) {
  pool_int_.push_back(x);
  return Data(INT, &pool_int_.back());
}

Interpreter::Data Interpreter::NewFloat(double x) {
  pool_float_.push_back(x);
  return Data(FLOAT, &pool_float_.back());
}

Interpreter::Data Interpreter::NewStr(const std::string& x) {
  pool_str_.push_back(x);
  return Data(STR, &pool_str_.back());
}

Interpreter::Data Interpreter::NewArray(const std::vector<Data>& x) {
  pool_array_.push_back(x);
  return Data(ARRAY, &pool_array_.back());
}

Interpreter::Data Interpreter::Expr(State& cur) {
  if (isdigit(*cur)) {
    return Num(cur);
  } else {
    if (vars_[*cur].type == NONE) {
      ++cur;
      if (*cur == '\0') return Data();
      return Expr(cur);
    }
    if (vars_[*cur].type == DEF && *cur != 'V') return Defined(cur);
    return Var(cur);
  }
}

Interpreter::Data& Interpreter::Vector(State& cur, Data& x) {
  if (*cur == ':') {
    ++cur;
    return x;
  }
  int i = Expr(cur).Int();
  if (x.type != ARRAY) {
    x = NewArray(std::vector<Data>());
  }
  std::vector<Data>& v = x.Array();
  if ((int)v.size() <= i) {
    std::vector<Data> new_v(i - (int)v.size() + 1);
    v.insert(v.end(), new_v.begin(), new_v.end());
  }
  return Vector(cur, v[i]);
}

Interpreter::Data& Interpreter::Var(State& cur) {
  if(*cur == 'V' && vars_['V'].type == DEF) {
    ++cur;
    char name = *cur; ++cur;
    return Vector(cur, vars_[name]);
  } else {
    Data& res = vars_[*cur];
    ++cur;
    return res;
  }
}

Interpreter::Data Interpreter::Defined(State& cur) {
  if (*cur == 'A') return Assign(cur);
  if (*cur == 'F') return Func(cur);
  if (*cur == 'I') return Input(cur);
  if (*cur == 'L') return Length(cur);
  if (*cur == 'M') return Format(cur);
  if (*cur == 'O') return Output(cur);
  if (*cur == 'P') return Pair(cur);
  if (*cur == 'R') return Repeat(cur);
  if (*cur == 'S') return Str(cur);
  if (*cur == 'T') return SubStr(cur);
  if (*cur == 'U') return EditStr(cur);
  if (*cur == 'W') return Loop(cur);
  if (*cur == '?') return Cond(cur);
  return Operate(cur);
}

Interpreter::Data Interpreter::Exec(State& cur, State& fcur) {
  if (*fcur == ':') {
    ++fcur;
    return Expr(fcur);
  } else {
    char name = *fcur; ++fcur;
    Data pre = vars_[name];
    vars_[name] = Expr(cur);
    Data res = Exec(cur, fcur);
    vars_[name] = pre;
    return res;
  }
}

Interpreter::Data Interpreter::Func(State& cur) {
  ++cur;
  State fcur = Expr(cur).Str().begin();
  return Exec(cur, fcur);
}

Interpreter::Data Interpreter::Num(State& cur) {
  int d = 0;
  while (isdigit(*cur)) {
    d = d * 10 + (*cur - '0');
    ++cur;
  }
  if (*cur == '.') {
    ++cur;
    double f = d;
    double a = 0.1;
    while (isdigit(*cur)) {
      f += (*cur - '0') * a;
      a /= 10;
      ++cur;
    }
    return NewFloat(f);
  } else return NewInt(d);
}

Interpreter::Data Interpreter::Str(State& cur) {
  std::string s;
  ++cur;
  while (true) {
    if (*cur == '\\') {
      ++cur;
      if (*cur == '\\') s += '\\', ++cur;
      else break;
    } else {
      s += *cur;
      ++cur;
    }
  }
  return NewStr(s);
}

Interpreter::Data Interpreter::SubStr(State& cur) {
  ++cur;
  int pos = Expr(cur).Int();
  int len = Expr(cur).Int();
  std::string s = Expr(cur).Str().substr(pos, len);
  return NewStr(s);
}

Interpreter::Data Interpreter::EditStr(State& cur) {
  ++cur;
  Data s = Expr(cur);
  int pos = Expr(cur).Int();
  std::string& t = Expr(cur).Str();
  for (int i = 0; i < (int)t.size(); ++i) s.Str()[pos + i] = t[i];
  return s;
}

Interpreter::Data Interpreter::Assign(State& cur) {
  ++cur;
  Data& x = Var(cur);
  x = Expr(cur);
  return x;
}

Interpreter::Data Interpreter::Input(State& cur) {
  ++cur;
  char id = *cur; ++cur;
  if (id == 'd') {
    long long d;
    (*input_) >> d;
    return NewInt(d);
  }
  if (id == 'f') {
    double f;
    (*input_) >> f;
    return NewFloat(f);
  }
  if (id == 's') {
    std::string s;
    (*input_) >> s;
    return NewStr(s);
  }
  return Data();
}

Interpreter::Data Interpreter::Length(State& cur) {
  ++cur;
  Data x = Expr(cur);
  if (x.type == STR) return NewInt(x.Str().size());
  if (x.type == ARRAY) return NewInt(x.Array().size());
  return NewInt(-1);
}

Interpreter::Data Interpreter::Format(State& cur) {
  ++cur;
  std::string form = "%";
  while (!islower(*cur)) form += *cur, ++cur;
  if (*cur == 'd') form += "ll";
  form += *cur; ++cur;
  Data x = Expr(cur);
  if (x.type == INT) sprintf(tmp_s, form.c_str(), x.Int());
  else if (x.type == FLOAT) sprintf(tmp_s, form.c_str(), x.Float());
  else sprintf(tmp_s, form.c_str(), x.Str().c_str());
  std::string s = tmp_s;
  return NewStr(s);
}

Interpreter::Data Interpreter::Pair(State& cur) {
  ++cur;
  Expr(cur);
  return Expr(cur);
}

void Interpreter::Print(Data x) {
  if (x.type == INT) (*output_) << x.Int();
  if (x.type == FLOAT) (*output_) << x.Float();
  if (x.type == STR) (*output_) << x.Str();
  if (x.type == ARRAY) {
    for (int i = 0; i < (int)x.Array().size(); ++i) {
      Print(x.Array()[i]);
      if (x.Array()[i].type != ARRAY) {
        if (i + 1 == (int)x.Array().size()) (*output_) << "\n";
        else (*output_) << " ";
      }
    }
  }
}

Interpreter::Data Interpreter::Output(State& cur) {
  ++cur;
  Data x = Expr(cur);
  Print(x);
  return x;
}

void Interpreter::Skip(State& cur) {
  bool t = false;
  int cnt = 0;
  while (true) {
    if (t) {
      if (*cur == '\\') {
        t = false;
        ++cur;
        if (*cur == '\\') t = true, ++cur;
      } else ++cur;
    } else {
      if (*cur == ':') {
        if (cnt) --cnt;
        else break;
      }
      if (*cur == 'S' && vars_['S'].type == DEF) t = true;
      if (*cur == 'V' && vars_['V'].type == DEF) ++cnt;
      if (*cur == '?' && vars_['?'].type == DEF) cnt += 2;
      ++cur;
    }
  }
  ++cur;
}

Interpreter::Data Interpreter::Cond(State& cur) {
  ++cur;
  long long x = Expr(cur).Int();
  if (x) {
    Data res = Expr(cur);
    Skip(cur);
    Skip(cur);
    return res;
  } else {
    Skip(cur);
    Data res = Expr(cur);
    Skip(cur);
    return res;
  }
}

Interpreter::Data Interpreter::Repeat(State& cur) {
  ++cur;
  Data& i = Var(cur);
  int r = Expr(cur).Int();
  State start = cur;
  Data res;
  for (i = NewInt(0); i.Int() < r; i = NewInt(i.Int() + 1)) {
    cur = start;
    res = Expr(cur);
  }
  return res;
}

Interpreter::Data Interpreter::Loop(State& cur) {
  ++cur;
  State start = cur;
  Data res;
  while (true) {
    cur = start;
    res = Expr(cur);
    if (res.type == INT && res.Int() == 0) break;
  }
  return res;
}

Interpreter::Data Interpreter::Operate(State& cur) {
  char sign = *cur; ++cur;
  Data x = Expr(cur);
  if (sign == '!') return NewInt(!x.Int());
  if (sign == '~') {
    if (x.type == INT) return NewInt(~x.Int());
    else if (x.type == STR) sort(x.Str().begin(), x.Str().end());
    else sort(x.Array().begin(), x.Array().end());
    return x;
  }
  if (sign == '-') {
    if (x.type == INT) return NewInt(-x.Int());
    else if (x.type == FLOAT)  return NewFloat(-x.Float());
    else if (x.type == STR) reverse(x.Str().begin(), x.Str().end());
    else reverse(x.Array().begin(), x.Array().end());
    return x;
  }
  Data y = Expr(cur);
  if (sign == '+') {
    if (x.type == INT) {
      if (y.type == INT) return NewInt(x.Int() + y.Int());
      else return NewInt(x.Int() + y.Float());
    } else if (x.type == FLOAT) {
      if (y.type == INT) return NewFloat(x.Float() + y.Int());
      else return NewFloat(x.Float() + y.Float());
    } else if (x.type == STR) x.Str() += y.Str();
    else x.Array().insert(x.Array().end(), y.Array().begin(), y.Array().end());
    return x;
  }
  if (sign == '*') {
    if (x.type == INT) {
      if (y.type == INT) return NewInt(x.Int() * y.Int());
      else return NewInt(x.Int() * y.Float());
    } else {
      if (y.type == INT) return NewFloat(x.Float() * y.Int());
      else return NewFloat(x.Float() * y.Float());
    }
  }
  if (sign == '/') {
    if (x.type == INT) {
      if (y.type == INT) return NewInt(x.Int() / y.Int());
      else return NewInt(x.Int() / y.Float());
    } else {
      if (y.type == INT) return NewFloat(x.Float() / y.Int());
      else return NewFloat(x.Float() / y.Float());
    }
  }
  if (sign == '%') return NewInt(x.Int() % y.Int());
  if (sign == '&') return NewInt(x.Int() & y.Int());
  if (sign == '|') return NewInt(x.Int() | y.Int());
  if (sign == '^') return NewInt(x.Int() ^ y.Int());
  if (sign == '{') return NewInt(x.Int() << y.Int());
  if (sign == '}') return NewInt(x.Int() >> y.Int());
  if (sign == '<') return NewInt(x < y);
  if (sign == '>') return NewInt(y < x);
  if (sign == '=') return NewInt(x == y);
  if (sign == '#') return NewInt(!(x == y));
  return x;
}

int main() {
  Interpreter interpreter;
  interpreter.Run(CODE, &cin, &cout);
  return 0;
}