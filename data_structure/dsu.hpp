struct dsu{
  dsu():n(0), cnt(0){}
  explicit dsu(int _n):n(_n), cnt(_n), p(_n, -1){}
  int merge(int a, int b){
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    int x = leader(a), y = leader(b);
    if(x == y) return x;
    cnt--;
    if(-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return x;
  }
  bool same(int a, int b){
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    return leader(a) == leader(b);
  }
  int size(int a){
    assert(0 <= a && a < n);
    return -p[leader(a)];
  }
  int leader(int a){
    assert(0 <= a && a < n);
    if(p[a] < 0) return a;
    return p[a] = leader(p[a]);
  }
  vector<vector<int>> groups(){
    vector<int> lb(n), gs(n);
    for(int i = 0; i < n; i++){
      lb[i] = leader(i);
      gs[lb[i]]++;
    }
    vector<vector<int>> res(n), res2;
    for(int i = 0; i < n; i++) res[i].reserve(gs[i]);
    for(int i = 0; i < n; i++) res[lb[i]].push_back(i);
    for(auto x:res) if(x.size() > 0) res2.push_back(x);
    return res2;
  }
  int count(){
    return cnt;
  }
  private:
  int n, cnt;
  vector<int> p;
};