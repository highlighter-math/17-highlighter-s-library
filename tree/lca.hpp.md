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
  bundledCode: "#line 1 \"tree/lca.hpp\"\nstruct edge{\r\n  int to;\r\n  long long\
    \ cost=1;\r\n};\r\nstruct LCA{\r\n  LCA(const vector<vector<edge>> &G,int root=0){\r\
    \n    build(G,root);\r\n  }\r\n  vector<vector<int>> parent;\r\n  vector<pair<int,long\
    \ long>> dist;\r\n  int N,LOG;\r\n  void build(const vector<vector<edge>> &G,int\
    \ root=0){\r\n    N=G.size();\r\n    LOG=32-__builtin_clz(N);\r\n    parent.assign(LOG,vector<int>(N,-1));\r\
    \n    dist.assign(N,{-1,-1});\r\n    dfs(G,root,-1,{0,0});\r\n    for(int i=0;i<LOG-1;i++){\r\
    \n      for(int j=0;j<N;j++){\r\n        if(parent[i][j]==-1){\r\n          parent[i+1][j]=-1;\r\
    \n        }else{\r\n          parent[i+1][j]=parent[i][parent[i][j]];\r\n    \
    \    }\r\n      }\r\n    }\r\n  }\r\n  void dfs(const vector<vector<edge>> &G,int\
    \ v,int p,pair<int,long long> d){\r\n    parent[0][v]=p;\r\n    dist[v]=d;\r\n\
    \    for(auto e:G[v]){\r\n      if(e.to!=p) dfs(G,e.to,v,{d.first+1,d.second+e.cost});\r\
    \n    }\r\n  }\r\n  int lca(int u,int v){\r\n    if(dist[u].first<dist[v].first)\
    \ swap(u,v);\r\n    for(int i=0;i<LOG;i++){\r\n      if((dist[u].first-dist[v].first)&(1<<i))\
    \ u=parent[i][u];\r\n    }\r\n    if(u==v) return u;\r\n    for(int i=LOG-1;i>=0;i--){\r\
    \n      if(parent[i][u]!=parent[i][v]){\r\n        u=parent[i][u];\r\n       \
    \ v=parent[i][v];\r\n      }\r\n    }\r\n    return parent[0][u];\r\n  }\r\n \
    \ long long dis(int u,int v){\r\n    return dist[u].second+dist[v].second-2*dist[lca(u,v)].second;\r\
    \n  }\r\n};\n"
  code: "struct edge{\r\n  int to;\r\n  long long cost=1;\r\n};\r\nstruct LCA{\r\n\
    \  LCA(const vector<vector<edge>> &G,int root=0){\r\n    build(G,root);\r\n  }\r\
    \n  vector<vector<int>> parent;\r\n  vector<pair<int,long long>> dist;\r\n  int\
    \ N,LOG;\r\n  void build(const vector<vector<edge>> &G,int root=0){\r\n    N=G.size();\r\
    \n    LOG=32-__builtin_clz(N);\r\n    parent.assign(LOG,vector<int>(N,-1));\r\n\
    \    dist.assign(N,{-1,-1});\r\n    dfs(G,root,-1,{0,0});\r\n    for(int i=0;i<LOG-1;i++){\r\
    \n      for(int j=0;j<N;j++){\r\n        if(parent[i][j]==-1){\r\n          parent[i+1][j]=-1;\r\
    \n        }else{\r\n          parent[i+1][j]=parent[i][parent[i][j]];\r\n    \
    \    }\r\n      }\r\n    }\r\n  }\r\n  void dfs(const vector<vector<edge>> &G,int\
    \ v,int p,pair<int,long long> d){\r\n    parent[0][v]=p;\r\n    dist[v]=d;\r\n\
    \    for(auto e:G[v]){\r\n      if(e.to!=p) dfs(G,e.to,v,{d.first+1,d.second+e.cost});\r\
    \n    }\r\n  }\r\n  int lca(int u,int v){\r\n    if(dist[u].first<dist[v].first)\
    \ swap(u,v);\r\n    for(int i=0;i<LOG;i++){\r\n      if((dist[u].first-dist[v].first)&(1<<i))\
    \ u=parent[i][u];\r\n    }\r\n    if(u==v) return u;\r\n    for(int i=LOG-1;i>=0;i--){\r\
    \n      if(parent[i][u]!=parent[i][v]){\r\n        u=parent[i][u];\r\n       \
    \ v=parent[i][v];\r\n      }\r\n    }\r\n    return parent[0][u];\r\n  }\r\n \
    \ long long dis(int u,int v){\r\n    return dist[u].second+dist[v].second-2*dist[lca(u,v)].second;\r\
    \n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/lca.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/lca.hpp
layout: document
redirect_from:
- /library/tree/lca.hpp
- /library/tree/lca.hpp.html
title: tree/lca.hpp
---
