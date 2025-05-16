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
  bundledCode: "#line 1 \"algorithm/lowlink.hpp\"\ntemplate< typename G >\r\nstruct\
    \ LowLink {\r\n  const G &g;\r\n  vector< int > used, ord, low;\r\n  vector< int\
    \ > articulation;\r\n  vector< pair< int, int > > bridge;\r\n \r\n  LowLink(const\
    \ G &g) : g(g) {}\r\n \r\n  int dfs(int idx, int k, int par) {\r\n    used[idx]\
    \ = true;\r\n    ord[idx] = k++;\r\n    low[idx] = ord[idx];\r\n    bool is_articulation\
    \ = false;\r\n    int cnt = 0;\r\n    for(auto &to : g[idx]) {\r\n      if(!used[to])\
    \ {\r\n        ++cnt;\r\n        k = dfs(to, k, idx);\r\n        low[idx] = min(low[idx],\
    \ low[to]);\r\n        is_articulation |= ~par && low[to] >= ord[idx];\r\n   \
    \     if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));\r\n \
    \     } else if(to != par) {\r\n        low[idx] = min(low[idx], ord[to]);\r\n\
    \      }\r\n    }\r\n    is_articulation |= par == -1 && cnt > 1;\r\n    if(is_articulation)\
    \ articulation.push_back(idx);\r\n    return k;\r\n  }\r\n \r\n  virtual void\
    \ build() {\r\n    used.assign(g.size(), 0);\r\n    ord.assign(g.size(), 0);\r\
    \n    low.assign(g.size(), 0);\r\n    int k = 0;\r\n    for(int i = 0; i < g.size();\
    \ i++) {\r\n      if(!used[i]) k = dfs(i, k, -1);\r\n    }\r\n  }\r\n};\r\n"
  code: "template< typename G >\r\nstruct LowLink {\r\n  const G &g;\r\n  vector<\
    \ int > used, ord, low;\r\n  vector< int > articulation;\r\n  vector< pair< int,\
    \ int > > bridge;\r\n \r\n  LowLink(const G &g) : g(g) {}\r\n \r\n  int dfs(int\
    \ idx, int k, int par) {\r\n    used[idx] = true;\r\n    ord[idx] = k++;\r\n \
    \   low[idx] = ord[idx];\r\n    bool is_articulation = false;\r\n    int cnt =\
    \ 0;\r\n    for(auto &to : g[idx]) {\r\n      if(!used[to]) {\r\n        ++cnt;\r\
    \n        k = dfs(to, k, idx);\r\n        low[idx] = min(low[idx], low[to]);\r\
    \n        is_articulation |= ~par && low[to] >= ord[idx];\r\n        if(ord[idx]\
    \ < low[to]) bridge.emplace_back(minmax(idx, (int) to));\r\n      } else if(to\
    \ != par) {\r\n        low[idx] = min(low[idx], ord[to]);\r\n      }\r\n    }\r\
    \n    is_articulation |= par == -1 && cnt > 1;\r\n    if(is_articulation) articulation.push_back(idx);\r\
    \n    return k;\r\n  }\r\n \r\n  virtual void build() {\r\n    used.assign(g.size(),\
    \ 0);\r\n    ord.assign(g.size(), 0);\r\n    low.assign(g.size(), 0);\r\n    int\
    \ k = 0;\r\n    for(int i = 0; i < g.size(); i++) {\r\n      if(!used[i]) k =\
    \ dfs(i, k, -1);\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/lowlink.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/lowlink.hpp
layout: document
redirect_from:
- /library/algorithm/lowlink.hpp
- /library/algorithm/lowlink.hpp.html
title: algorithm/lowlink.hpp
---
