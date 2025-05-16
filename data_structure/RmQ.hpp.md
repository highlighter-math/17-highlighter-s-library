---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/RmQ.hpp\"\ntemplate<typename T>\r\nstruct\
    \ SparseTable{\r\n  function<T(T,T)> f;\r\n  vector<T> a;\r\n  vector<vector<T>>\
    \ ST;\r\n  int n;\r\n  T id;\r\n  SparseTable(){}\r\n  SparseTable(vector<T> _a,auto\
    \ _f,T _id=0):a(_a),f(_f),id(_id){\r\n    build();\r\n  }\r\n  void build(){\r\
    \n    n=a.size();\r\n    int k=32-__builtin_clz(n);\r\n    ST.resize(n,vector<T>(k));\r\
    \n    for(int p=0;p<k;p++){\r\n      for(int i=0;i<n;i++){\r\n        if(p==0)\
    \ ST[i][p]=a[i];\r\n        else{\r\n          ST[i][p]=f(ST[i][p-1],ST[min(i+(1<<(p-1)),n-1)][p-1]);\r\
    \n        }\r\n      }\r\n    }\r\n  }\r\n  T range_query(int l,int r){\r\n  \
    \  if(l>=r) return id;\r\n    int p=31-__builtin_clz(r-l);\r\n    return f(ST[l][p],ST[r-(1<<p)][p]);\r\
    \n  }\r\n};\r\ntemplate<typename T>\r\nstruct RmQ{\r\n  const function<T(T,T)>\
    \ f=[](T x,T y){return min(x,y);};\r\n  T id=numeric_limits<T>::max();\r\n  vector<T>\
    \ a;\r\n  vector<T> M;\r\n  vector<T> g;\r\n  vector<vector<int>> le;\r\n  SparseTable<T>\
    \ ST;\r\n  int n,m;\r\n  RmQ(vector<T> _a):a(_a){\r\n    build();\r\n  }\r\n \
    \ void build(){\r\n    n=a.size();\r\n    m=(31-__builtin_clz(n))/2;\r\n    m=max(1,m);\r\
    \n    M.resize((n+m-1)/m,id);\r\n    g.resize(n);\r\n    le.resize((n+m-1)/m,vector<int>(m));\r\
    \n    for(int i=0;i<n;i++) M[i/m]=min(M[i/m],a[i]);\r\n    ST.a=M,ST.f=f,ST.id=id;\r\
    \n    ST.build();\r\n    for(int i=0;i<(n+m-1)/m;i++){\r\n      stack<T> s;\r\n\
    \      for(int j=0;j<m;j++){\r\n        if(i*m+j==n) break;\r\n        while(!s.empty()&&a[s.top()]>=a[i*m+j])\
    \ s.pop();\r\n        if(s.empty()) g[i*m+j]=-1;\r\n        else g[i*m+j]=s.top();\r\
    \n        s.push(i*m+j);\r\n        if(g[i*m+j]==-1) le[i][j]=0;\r\n        else\
    \ le[i][j]=le[i][g[i*m+j]%m]|(1<<(g[i*m+j]%m));\r\n      }\r\n    }\r\n  }\r\n\
    \  T range_query(int l,int r){\r\n    if(l>=r) return id;\r\n    if(l/m==(r-1)/m){\r\
    \n      int ret=le[l/m][(r-1)%m]&((1<<m)-(1<<(l%m)));\r\n      if(ret==0) return\
    \ a[r-1];\r\n      else return a[(l/m)*m+__builtin_ctz(ret)];\r\n    }else{\r\n\
    \      int ret=min(range_query(l,(l/m+1)*m),range_query((r/m)*m,r));\r\n     \
    \ ret=min(ret,ST.range_query(l/m+1,r/m));\r\n      return ret;\r\n    }\r\n  }\r\
    \n};\r\ntemplate<typename T>\r\nstruct RMQ{\r\n  const function<T(T,T)> f=[](T\
    \ x,T y){return max(x,y);};\r\n  T id=numeric_limits<T>::min();\r\n  vector<T>\
    \ a;\r\n  vector<T> M;\r\n  vector<T> g;\r\n  vector<vector<int>> le;\r\n  SparseTable<T>\
    \ ST;\r\n  int n,m;\r\n  RMQ(vector<T> _a):a(_a){\r\n    build();\r\n  }\r\n \
    \ void build(){\r\n    n=a.size();\r\n    m=(31-__builtin_clz(n))/2;\r\n    m=max(1,m);\r\
    \n    M.resize((n+m-1)/m,id);\r\n    g.resize(n);\r\n    le.resize((n+m-1)/m,vector<int>(m));\r\
    \n    for(int i=0;i<n;i++) M[i/m]=max(M[i/m],a[i]);\r\n    ST.a=M,ST.f=f,ST.id=id;\r\
    \n    ST.build();\r\n    for(int i=0;i<(n+m-1)/m;i++){\r\n      stack<T> s;\r\n\
    \      for(int j=0;j<m;j++){\r\n        if(i*m+j==n) break;\r\n        while(!s.empty()&&a[s.top()]<=a[i*m+j])\
    \ s.pop();\r\n        if(s.empty()) g[i*m+j]=-1;\r\n        else g[i*m+j]=s.top();\r\
    \n        s.push(i*m+j);\r\n        if(g[i*m+j]==-1) le[i][j]=0;\r\n        else\
    \ le[i][j]=le[i][g[i*m+j]%m]|(1<<(g[i*m+j]%m));\r\n      }\r\n    }\r\n  }\r\n\
    \  T range_query(int l,int r){\r\n    if(l>=r) return id;\r\n    if(l/m==(r-1)/m){\r\
    \n      int ret=le[l/m][(r-1)%m]&((1<<m)-(1<<(l%m)));\r\n      if(ret==0) return\
    \ a[r-1];\r\n      else return a[(l/m)*m+__builtin_ctz(ret)];\r\n    }else{\r\n\
    \      int ret=max(range_query(l,(l/m+1)*m),range_query((r/m)*m,r));\r\n     \
    \ ret=max(ret,ST.range_query(l/m+1,r/m));\r\n      return ret;\r\n    }\r\n  }\r\
    \n};\n"
  code: "template<typename T>\r\nstruct SparseTable{\r\n  function<T(T,T)> f;\r\n\
    \  vector<T> a;\r\n  vector<vector<T>> ST;\r\n  int n;\r\n  T id;\r\n  SparseTable(){}\r\
    \n  SparseTable(vector<T> _a,auto _f,T _id=0):a(_a),f(_f),id(_id){\r\n    build();\r\
    \n  }\r\n  void build(){\r\n    n=a.size();\r\n    int k=32-__builtin_clz(n);\r\
    \n    ST.resize(n,vector<T>(k));\r\n    for(int p=0;p<k;p++){\r\n      for(int\
    \ i=0;i<n;i++){\r\n        if(p==0) ST[i][p]=a[i];\r\n        else{\r\n      \
    \    ST[i][p]=f(ST[i][p-1],ST[min(i+(1<<(p-1)),n-1)][p-1]);\r\n        }\r\n \
    \     }\r\n    }\r\n  }\r\n  T range_query(int l,int r){\r\n    if(l>=r) return\
    \ id;\r\n    int p=31-__builtin_clz(r-l);\r\n    return f(ST[l][p],ST[r-(1<<p)][p]);\r\
    \n  }\r\n};\r\ntemplate<typename T>\r\nstruct RmQ{\r\n  const function<T(T,T)>\
    \ f=[](T x,T y){return min(x,y);};\r\n  T id=numeric_limits<T>::max();\r\n  vector<T>\
    \ a;\r\n  vector<T> M;\r\n  vector<T> g;\r\n  vector<vector<int>> le;\r\n  SparseTable<T>\
    \ ST;\r\n  int n,m;\r\n  RmQ(vector<T> _a):a(_a){\r\n    build();\r\n  }\r\n \
    \ void build(){\r\n    n=a.size();\r\n    m=(31-__builtin_clz(n))/2;\r\n    m=max(1,m);\r\
    \n    M.resize((n+m-1)/m,id);\r\n    g.resize(n);\r\n    le.resize((n+m-1)/m,vector<int>(m));\r\
    \n    for(int i=0;i<n;i++) M[i/m]=min(M[i/m],a[i]);\r\n    ST.a=M,ST.f=f,ST.id=id;\r\
    \n    ST.build();\r\n    for(int i=0;i<(n+m-1)/m;i++){\r\n      stack<T> s;\r\n\
    \      for(int j=0;j<m;j++){\r\n        if(i*m+j==n) break;\r\n        while(!s.empty()&&a[s.top()]>=a[i*m+j])\
    \ s.pop();\r\n        if(s.empty()) g[i*m+j]=-1;\r\n        else g[i*m+j]=s.top();\r\
    \n        s.push(i*m+j);\r\n        if(g[i*m+j]==-1) le[i][j]=0;\r\n        else\
    \ le[i][j]=le[i][g[i*m+j]%m]|(1<<(g[i*m+j]%m));\r\n      }\r\n    }\r\n  }\r\n\
    \  T range_query(int l,int r){\r\n    if(l>=r) return id;\r\n    if(l/m==(r-1)/m){\r\
    \n      int ret=le[l/m][(r-1)%m]&((1<<m)-(1<<(l%m)));\r\n      if(ret==0) return\
    \ a[r-1];\r\n      else return a[(l/m)*m+__builtin_ctz(ret)];\r\n    }else{\r\n\
    \      int ret=min(range_query(l,(l/m+1)*m),range_query((r/m)*m,r));\r\n     \
    \ ret=min(ret,ST.range_query(l/m+1,r/m));\r\n      return ret;\r\n    }\r\n  }\r\
    \n};\r\ntemplate<typename T>\r\nstruct RMQ{\r\n  const function<T(T,T)> f=[](T\
    \ x,T y){return max(x,y);};\r\n  T id=numeric_limits<T>::min();\r\n  vector<T>\
    \ a;\r\n  vector<T> M;\r\n  vector<T> g;\r\n  vector<vector<int>> le;\r\n  SparseTable<T>\
    \ ST;\r\n  int n,m;\r\n  RMQ(vector<T> _a):a(_a){\r\n    build();\r\n  }\r\n \
    \ void build(){\r\n    n=a.size();\r\n    m=(31-__builtin_clz(n))/2;\r\n    m=max(1,m);\r\
    \n    M.resize((n+m-1)/m,id);\r\n    g.resize(n);\r\n    le.resize((n+m-1)/m,vector<int>(m));\r\
    \n    for(int i=0;i<n;i++) M[i/m]=max(M[i/m],a[i]);\r\n    ST.a=M,ST.f=f,ST.id=id;\r\
    \n    ST.build();\r\n    for(int i=0;i<(n+m-1)/m;i++){\r\n      stack<T> s;\r\n\
    \      for(int j=0;j<m;j++){\r\n        if(i*m+j==n) break;\r\n        while(!s.empty()&&a[s.top()]<=a[i*m+j])\
    \ s.pop();\r\n        if(s.empty()) g[i*m+j]=-1;\r\n        else g[i*m+j]=s.top();\r\
    \n        s.push(i*m+j);\r\n        if(g[i*m+j]==-1) le[i][j]=0;\r\n        else\
    \ le[i][j]=le[i][g[i*m+j]%m]|(1<<(g[i*m+j]%m));\r\n      }\r\n    }\r\n  }\r\n\
    \  T range_query(int l,int r){\r\n    if(l>=r) return id;\r\n    if(l/m==(r-1)/m){\r\
    \n      int ret=le[l/m][(r-1)%m]&((1<<m)-(1<<(l%m)));\r\n      if(ret==0) return\
    \ a[r-1];\r\n      else return a[(l/m)*m+__builtin_ctz(ret)];\r\n    }else{\r\n\
    \      int ret=max(range_query(l,(l/m+1)*m),range_query((r/m)*m,r));\r\n     \
    \ ret=max(ret,ST.range_query(l/m+1,r/m));\r\n      return ret;\r\n    }\r\n  }\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/RmQ.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/RmQ.hpp
layout: document
redirect_from:
- /library/data_structure/RmQ.hpp
- /library/data_structure/RmQ.hpp.html
title: data_structure/RmQ.hpp
---
