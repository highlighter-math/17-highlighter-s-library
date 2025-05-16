template<typename T>
struct Trie{
  struct Node{
    int sum = 0;
    map<T, Node*> m;
  };
  Node* root = new Node;
  void mk(Node*& t){
    if(!t){
      t = new Node;
      cnt++;
    }
  }
  void insert_vector(const vector<T>& s){
    Node* c = root;
    c->sum++;
    for(const T &x:s){
      mk(c->m[x]);
      c = c->m[x];
      c->sum++;
    }
  }
  void insert_string(const string& s){
    if(!is_same<T, char>::value) assert(false);
    Node* c = root;
    c->sum++;
    for(const T &x:s){
      mk(c->m[x]);
      c = c->m[x];
      c->sum++;
    }
  }
  int find_vector(const vector<T>& s){
    Node* c = root;
    for(const T &x:s){
      mk(c->m[x]);
      c = c->m[x];
    }
    return c->sum;
  }
  int find_string(const string& s){
    Node* c = root;
    for(const T &x:s){
      mk(c->m[x]);
      c = c->m[x];
    }
    return c->sum;
  }
  long long solve(const string& s){
    long long ret = 0;
    Node* c = root;
    for(const T &x:s){
      mk(c->m[x]);
      c = c->m[x];
      ret += c->sum;
    }
    return ret;
  }
  int count(){
    return cnt;
  }
  private:
  int cnt = 1;
};