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
  bundledCode: "#line 1 \"tree/hld.hpp\"\n//n=1\u3067\u30D0\u30B0\u308B\r\n//\u6839\
    \u30920\u3068\u3057\u3066HLD\u3092\u884C\u3046\r\n//vertex\u306BHLD\u5F8C\u306E\
    \u9802\u70B9\u306E\u5217\u304C\u683C\u7D0D\u3055\u308C\r\n//ind[v]\u306B\u9802\
    \u70B9v\u306Evertex\u4E0A\u306Eindex\u304C\u683C\u7D0D\u3055\u308C\u308B\u3002\
    \r\n//getsubtree\u3068\u304Bgetpath\u306Fvertex\u4E0A\u306E\u9589\u533A\u9593\u3084\
    \u9589\u533A\u9593\u306E\u5217\u3068\u3057\u3066\u5E30\u3063\u3066\u304F\u308B\
    \r\n//\u8FBA\u306E\u91CD\u307F\u3092\u8F09\u305B\u308B\u6642\u306F\u3001\u6839\
    \u304B\u3089\u9060\u3044\u5074\u306E\u9802\u70B9\u306B\u8F09\u305B\u308B\u306E\
    \u3067\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\u3067\u306FLCA\u3060\u3051\u9664\u5916\
    \u3059\u308B\r\nstruct Edge {\r\n    ll to;\r\n    ll cost;\r\n};\r\nusing Graph=vector<vector<Edge>>;\r\
    \nstruct HLD{\r\n  Graph G;\r\n  vector<int> siz,a,ind,edge,dep,vertex,par;\r\n\
    \  void dfs_sz(int v,int p){\r\n    int ret=1;\r\n    for(auto nv : G[v]){\r\n\
    \      if(nv.to==p) continue;\r\n      dfs_sz(nv.to,v);\r\n      ret+=siz[nv.to];\r\
    \n    }\r\n    siz[v]=ret;\r\n  }\r\n  void Ddfs(int v,int p){\r\n    for(auto\
    \ nv : G[v]){\r\n      if(nv.to==p) continue;\r\n      dep[nv.to]=dep[v]+1;\r\n\
    \      Ddfs(nv.to,v);\r\n    }\r\n  }\r\n  void hld(int v,int k,int p){\r\n  \
    \  ind[v]=vertex.size();\r\n    a[v]=k;\r\n    vertex.push_back(v);\r\n    if(G[v].size()==1&&v!=0)\
    \ return;\r\n    int mxind=-1;\r\n    int mx=0;\r\n    for(int i=0;i<(int)G[v].size();i++){\r\
    \n      auto nv=G[v][i];\r\n      if(nv.to==p) continue;\r\n      if(siz[nv.to]>mx){\r\
    \n        mx=siz[nv.to];\r\n        mxind=i;\r\n      }\r\n    }\r\n    hld(G[v][mxind].to,k,v);\r\
    \n    for(int i=0;i<(int)G[v].size();i++){\r\n      auto nv=G[v][i];\r\n     \
    \ if(nv.to==p) continue;\r\n      if(i!=mxind) hld(nv.to,nv.to,v);\r\n    }\r\n\
    \  }\r\n  void getpar(int v,int p){\r\n    par[v]=p;\r\n    for(auto nv : G[v]){\r\
    \n      if(nv.to==p) continue;\r\n      getpar(nv.to,v);\r\n      edge[ind[nv.to]]=nv.cost;\r\
    \n    }\r\n  }\r\n  HLD(const Graph &g) : siz((int)g.size()), a((int)g.size()),\
    \ ind((int)g.size()), edge((int)g.size()), dep((int)g.size()), par((int)g.size()){\r\
    \n    G=g;\r\n    dfs_sz(0,-1);\r\n    hld(0,0,-1);\r\n    getpar(0,-1);\r\n \
    \   Ddfs(0,-1);\r\n  }\r\n  //[l,r]\r\n  pair<int,int> getsubtree(int v){\r\n\
    \    return make_pair(ind[v],ind[v]+siz[v]-1);\r\n  }\r\n  //[l,r]...\r\n  vector<pair<int,int>>\
    \ getpath(int u,int v){\r\n    vector<pair<int,int>> ret;\r\n    while(a[u]!=a[v]){\r\
    \n      if(dep[a[u]]<=dep[a[v]]){\r\n        ret.push_back({ind[a[v]],ind[v]});\r\
    \n        v=par[a[v]];\r\n      }else{\r\n        ret.push_back({ind[a[u]],ind[u]});\r\
    \n        u=par[a[u]];\r\n      }\r\n    }\r\n    ret.push_back({min(ind[u],ind[v]),max(ind[u],ind[v])});\r\
    \n    return ret;\r\n  }\r\n  int lca(int u,int v){\r\n    vector<pair<int,int>>\
    \ path=getpath(u,v);\r\n    return vertex[path[path.size()-1].first];\r\n  }\r\
    \n};\n"
  code: "//n=1\u3067\u30D0\u30B0\u308B\r\n//\u6839\u30920\u3068\u3057\u3066HLD\u3092\
    \u884C\u3046\r\n//vertex\u306BHLD\u5F8C\u306E\u9802\u70B9\u306E\u5217\u304C\u683C\
    \u7D0D\u3055\u308C\r\n//ind[v]\u306B\u9802\u70B9v\u306Evertex\u4E0A\u306Eindex\u304C\
    \u683C\u7D0D\u3055\u308C\u308B\u3002\r\n//getsubtree\u3068\u304Bgetpath\u306F\
    vertex\u4E0A\u306E\u9589\u533A\u9593\u3084\u9589\u533A\u9593\u306E\u5217\u3068\
    \u3057\u3066\u5E30\u3063\u3066\u304F\u308B\r\n//\u8FBA\u306E\u91CD\u307F\u3092\
    \u8F09\u305B\u308B\u6642\u306F\u3001\u6839\u304B\u3089\u9060\u3044\u5074\u306E\
    \u9802\u70B9\u306B\u8F09\u305B\u308B\u306E\u3067\u3001\u30D1\u30B9\u30AF\u30A8\
    \u30EA\u3067\u306FLCA\u3060\u3051\u9664\u5916\u3059\u308B\r\nstruct Edge {\r\n\
    \    ll to;\r\n    ll cost;\r\n};\r\nusing Graph=vector<vector<Edge>>;\r\nstruct\
    \ HLD{\r\n  Graph G;\r\n  vector<int> siz,a,ind,edge,dep,vertex,par;\r\n  void\
    \ dfs_sz(int v,int p){\r\n    int ret=1;\r\n    for(auto nv : G[v]){\r\n     \
    \ if(nv.to==p) continue;\r\n      dfs_sz(nv.to,v);\r\n      ret+=siz[nv.to];\r\
    \n    }\r\n    siz[v]=ret;\r\n  }\r\n  void Ddfs(int v,int p){\r\n    for(auto\
    \ nv : G[v]){\r\n      if(nv.to==p) continue;\r\n      dep[nv.to]=dep[v]+1;\r\n\
    \      Ddfs(nv.to,v);\r\n    }\r\n  }\r\n  void hld(int v,int k,int p){\r\n  \
    \  ind[v]=vertex.size();\r\n    a[v]=k;\r\n    vertex.push_back(v);\r\n    if(G[v].size()==1&&v!=0)\
    \ return;\r\n    int mxind=-1;\r\n    int mx=0;\r\n    for(int i=0;i<(int)G[v].size();i++){\r\
    \n      auto nv=G[v][i];\r\n      if(nv.to==p) continue;\r\n      if(siz[nv.to]>mx){\r\
    \n        mx=siz[nv.to];\r\n        mxind=i;\r\n      }\r\n    }\r\n    hld(G[v][mxind].to,k,v);\r\
    \n    for(int i=0;i<(int)G[v].size();i++){\r\n      auto nv=G[v][i];\r\n     \
    \ if(nv.to==p) continue;\r\n      if(i!=mxind) hld(nv.to,nv.to,v);\r\n    }\r\n\
    \  }\r\n  void getpar(int v,int p){\r\n    par[v]=p;\r\n    for(auto nv : G[v]){\r\
    \n      if(nv.to==p) continue;\r\n      getpar(nv.to,v);\r\n      edge[ind[nv.to]]=nv.cost;\r\
    \n    }\r\n  }\r\n  HLD(const Graph &g) : siz((int)g.size()), a((int)g.size()),\
    \ ind((int)g.size()), edge((int)g.size()), dep((int)g.size()), par((int)g.size()){\r\
    \n    G=g;\r\n    dfs_sz(0,-1);\r\n    hld(0,0,-1);\r\n    getpar(0,-1);\r\n \
    \   Ddfs(0,-1);\r\n  }\r\n  //[l,r]\r\n  pair<int,int> getsubtree(int v){\r\n\
    \    return make_pair(ind[v],ind[v]+siz[v]-1);\r\n  }\r\n  //[l,r]...\r\n  vector<pair<int,int>>\
    \ getpath(int u,int v){\r\n    vector<pair<int,int>> ret;\r\n    while(a[u]!=a[v]){\r\
    \n      if(dep[a[u]]<=dep[a[v]]){\r\n        ret.push_back({ind[a[v]],ind[v]});\r\
    \n        v=par[a[v]];\r\n      }else{\r\n        ret.push_back({ind[a[u]],ind[u]});\r\
    \n        u=par[a[u]];\r\n      }\r\n    }\r\n    ret.push_back({min(ind[u],ind[v]),max(ind[u],ind[v])});\r\
    \n    return ret;\r\n  }\r\n  int lca(int u,int v){\r\n    vector<pair<int,int>>\
    \ path=getpath(u,v);\r\n    return vertex[path[path.size()-1].first];\r\n  }\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/hld.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/hld.hpp
layout: document
redirect_from:
- /library/tree/hld.hpp
- /library/tree/hld.hpp.html
title: tree/hld.hpp
---
