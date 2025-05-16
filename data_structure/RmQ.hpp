template<typename T>
struct SparseTable{
  function<T(T,T)> f;
  vector<T> a;
  vector<vector<T>> ST;
  int n;
  T id;
  SparseTable(){}
  SparseTable(vector<T> _a,auto _f,T _id=0):a(_a),f(_f),id(_id){
    build();
  }
  void build(){
    n=a.size();
    int k=32-__builtin_clz(n);
    ST.resize(n,vector<T>(k));
    for(int p=0;p<k;p++){
      for(int i=0;i<n;i++){
        if(p==0) ST[i][p]=a[i];
        else{
          ST[i][p]=f(ST[i][p-1],ST[min(i+(1<<(p-1)),n-1)][p-1]);
        }
      }
    }
  }
  T range_query(int l,int r){
    if(l>=r) return id;
    int p=31-__builtin_clz(r-l);
    return f(ST[l][p],ST[r-(1<<p)][p]);
  }
};
template<typename T>
struct RmQ{
  const function<T(T,T)> f=[](T x,T y){return min(x,y);};
  T id=numeric_limits<T>::max();
  vector<T> a;
  vector<T> M;
  vector<T> g;
  vector<vector<int>> le;
  SparseTable<T> ST;
  int n,m;
  RmQ(vector<T> _a):a(_a){
    build();
  }
  void build(){
    n=a.size();
    m=(31-__builtin_clz(n))/2;
    m=max(1,m);
    M.resize((n+m-1)/m,id);
    g.resize(n);
    le.resize((n+m-1)/m,vector<int>(m));
    for(int i=0;i<n;i++) M[i/m]=min(M[i/m],a[i]);
    ST.a=M,ST.f=f,ST.id=id;
    ST.build();
    for(int i=0;i<(n+m-1)/m;i++){
      stack<T> s;
      for(int j=0;j<m;j++){
        if(i*m+j==n) break;
        while(!s.empty()&&a[s.top()]>=a[i*m+j]) s.pop();
        if(s.empty()) g[i*m+j]=-1;
        else g[i*m+j]=s.top();
        s.push(i*m+j);
        if(g[i*m+j]==-1) le[i][j]=0;
        else le[i][j]=le[i][g[i*m+j]%m]|(1<<(g[i*m+j]%m));
      }
    }
  }
  T range_query(int l,int r){
    if(l>=r) return id;
    if(l/m==(r-1)/m){
      int ret=le[l/m][(r-1)%m]&((1<<m)-(1<<(l%m)));
      if(ret==0) return a[r-1];
      else return a[(l/m)*m+__builtin_ctz(ret)];
    }else{
      int ret=min(range_query(l,(l/m+1)*m),range_query((r/m)*m,r));
      ret=min(ret,ST.range_query(l/m+1,r/m));
      return ret;
    }
  }
};
template<typename T>
struct RMQ{
  const function<T(T,T)> f=[](T x,T y){return max(x,y);};
  T id=numeric_limits<T>::min();
  vector<T> a;
  vector<T> M;
  vector<T> g;
  vector<vector<int>> le;
  SparseTable<T> ST;
  int n,m;
  RMQ(vector<T> _a):a(_a){
    build();
  }
  void build(){
    n=a.size();
    m=(31-__builtin_clz(n))/2;
    m=max(1,m);
    M.resize((n+m-1)/m,id);
    g.resize(n);
    le.resize((n+m-1)/m,vector<int>(m));
    for(int i=0;i<n;i++) M[i/m]=max(M[i/m],a[i]);
    ST.a=M,ST.f=f,ST.id=id;
    ST.build();
    for(int i=0;i<(n+m-1)/m;i++){
      stack<T> s;
      for(int j=0;j<m;j++){
        if(i*m+j==n) break;
        while(!s.empty()&&a[s.top()]<=a[i*m+j]) s.pop();
        if(s.empty()) g[i*m+j]=-1;
        else g[i*m+j]=s.top();
        s.push(i*m+j);
        if(g[i*m+j]==-1) le[i][j]=0;
        else le[i][j]=le[i][g[i*m+j]%m]|(1<<(g[i*m+j]%m));
      }
    }
  }
  T range_query(int l,int r){
    if(l>=r) return id;
    if(l/m==(r-1)/m){
      int ret=le[l/m][(r-1)%m]&((1<<m)-(1<<(l%m)));
      if(ret==0) return a[r-1];
      else return a[(l/m)*m+__builtin_ctz(ret)];
    }else{
      int ret=max(range_query(l,(l/m+1)*m),range_query((r/m)*m,r));
      ret=max(ret,ST.range_query(l/m+1,r/m));
      return ret;
    }
  }
};