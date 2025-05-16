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
  bundledCode: "#line 1 \"tree/AuxiliaryTree.hpp\"\n#include<vector>\r\n#include<algorithm>\r\
    \nusing namespace std;\r\n\r\n#define N 100000\r\n#define NL 18\r\n \r\nint fs[N],\
    \ ls[N];\r\nint depth[N];\r\nint st[NL][3*N], lg[3*N];\r\n \r\nint cur;\r\nvector<int>\
    \ g[N];\r\nvector<int> g0[N];\r\n \r\nvoid ett_dfs(int v, int p, int d) {\r\n\
    \  st[0][fs[v] = cur++] = v;\r\n  depth[v] = d;\r\n  for(int w : g[v]) {\r\n \
    \   if(w == p) continue;\r\n    ett_dfs(w, v, d+1);\r\n    st[0][cur++] = v;\r\
    \n  }\r\n  ls[v] = cur-1;\r\n}\r\n \r\nvoid construct() {\r\n  cur = 0;\r\n  //\
    \ Euler tour technique\r\n  ett_dfs(0, -1, 0);\r\n  lg[0] = lg[1] = 0;\r\n  for(int\
    \ i=2; i<=cur; ++i) lg[i] = lg[i >> 1] + 1;\r\n \r\n  // Sparse Table\r\n  for(int\
    \ i=0, b=1; i<lg[cur]; ++i, b<<=1) {\r\n    for(int j=0; j<(cur - (b<<1) + 1);\
    \ ++j) {\r\n      st[i+1][j] = (depth[st[i][j]] <= depth[st[i][j+b]] ? st[i][j]\
    \ : st[i][j+b]);\r\n    }\r\n  }\r\n}\r\n \r\nbool cmp_at(int x, int y) {\r\n\
    \  return fs[x] < fs[y];\r\n}\r\n \r\ninline int lca(int u, int v) {\r\n  int\
    \ x = fs[u], y = fs[v];\r\n  if(x > y) swap(x, y);\r\n  int l = lg[y - x + 1];\r\
    \n  return (depth[st[l][x]] <= depth[st[l][y - (1 << l) + 1]] ? st[l][x] : st[l][y\
    \ - (1 << l) + 1]);\r\n}\r\n\r\n// \u9802\u70B9vs\u3092\u542B\u3080Auxiliary Tree\u3092\
    \u69CB\u7BC9\u3059\u308B\r\n// \u7D50\u679C\u306Fg0\u306B\u5165\u308B\r\n// \u8FD4\
    \u308A\u5024\u306FAuxiliary Tree\u306E\u6839\u9802\u70B9\r\nint stk[2*N];\r\n\
    inline int auxiliary_tree(vector<int> &vs, vector<int> g0[N]) {\r\n  sort(vs.begin(),\
    \ vs.end(), cmp_at);\r\n  int k = vs.size();\r\n  for(int i=0; i<k-1; ++i) {\r\
    \n    vs.push_back(lca(vs[i], vs[i+1]));\r\n  }\r\n  sort(vs.begin(), vs.end(),\
    \ cmp_at);\r\n  int prv = -1;\r\n  int cur = 0;\r\n  for(int i=0; i<vs.size();\
    \ ++i) {\r\n    int v = vs[i];\r\n    if(prv == v) continue;\r\n    while(cur\
    \ > 0 && ls[stk[cur-1]] < fs[v]) --cur;\r\n    if(cur > 0) {\r\n      g0[stk[cur-1]].push_back(v);\r\
    \n    }\r\n    g0[v].clear();\r\n    stk[cur++] = v;\r\n    prv = v;\r\n  }\r\n\
    \  return stk[0];\r\n}\n"
  code: "#include<vector>\r\n#include<algorithm>\r\nusing namespace std;\r\n\r\n#define\
    \ N 100000\r\n#define NL 18\r\n \r\nint fs[N], ls[N];\r\nint depth[N];\r\nint\
    \ st[NL][3*N], lg[3*N];\r\n \r\nint cur;\r\nvector<int> g[N];\r\nvector<int> g0[N];\r\
    \n \r\nvoid ett_dfs(int v, int p, int d) {\r\n  st[0][fs[v] = cur++] = v;\r\n\
    \  depth[v] = d;\r\n  for(int w : g[v]) {\r\n    if(w == p) continue;\r\n    ett_dfs(w,\
    \ v, d+1);\r\n    st[0][cur++] = v;\r\n  }\r\n  ls[v] = cur-1;\r\n}\r\n \r\nvoid\
    \ construct() {\r\n  cur = 0;\r\n  // Euler tour technique\r\n  ett_dfs(0, -1,\
    \ 0);\r\n  lg[0] = lg[1] = 0;\r\n  for(int i=2; i<=cur; ++i) lg[i] = lg[i >> 1]\
    \ + 1;\r\n \r\n  // Sparse Table\r\n  for(int i=0, b=1; i<lg[cur]; ++i, b<<=1)\
    \ {\r\n    for(int j=0; j<(cur - (b<<1) + 1); ++j) {\r\n      st[i+1][j] = (depth[st[i][j]]\
    \ <= depth[st[i][j+b]] ? st[i][j] : st[i][j+b]);\r\n    }\r\n  }\r\n}\r\n \r\n\
    bool cmp_at(int x, int y) {\r\n  return fs[x] < fs[y];\r\n}\r\n \r\ninline int\
    \ lca(int u, int v) {\r\n  int x = fs[u], y = fs[v];\r\n  if(x > y) swap(x, y);\r\
    \n  int l = lg[y - x + 1];\r\n  return (depth[st[l][x]] <= depth[st[l][y - (1\
    \ << l) + 1]] ? st[l][x] : st[l][y - (1 << l) + 1]);\r\n}\r\n\r\n// \u9802\u70B9\
    vs\u3092\u542B\u3080Auxiliary Tree\u3092\u69CB\u7BC9\u3059\u308B\r\n// \u7D50\u679C\
    \u306Fg0\u306B\u5165\u308B\r\n// \u8FD4\u308A\u5024\u306FAuxiliary Tree\u306E\u6839\
    \u9802\u70B9\r\nint stk[2*N];\r\ninline int auxiliary_tree(vector<int> &vs, vector<int>\
    \ g0[N]) {\r\n  sort(vs.begin(), vs.end(), cmp_at);\r\n  int k = vs.size();\r\n\
    \  for(int i=0; i<k-1; ++i) {\r\n    vs.push_back(lca(vs[i], vs[i+1]));\r\n  }\r\
    \n  sort(vs.begin(), vs.end(), cmp_at);\r\n  int prv = -1;\r\n  int cur = 0;\r\
    \n  for(int i=0; i<vs.size(); ++i) {\r\n    int v = vs[i];\r\n    if(prv == v)\
    \ continue;\r\n    while(cur > 0 && ls[stk[cur-1]] < fs[v]) --cur;\r\n    if(cur\
    \ > 0) {\r\n      g0[stk[cur-1]].push_back(v);\r\n    }\r\n    g0[v].clear();\r\
    \n    stk[cur++] = v;\r\n    prv = v;\r\n  }\r\n  return stk[0];\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/tree/AuxiliaryTree.hpp
- /library/tree/AuxiliaryTree.hpp.html
title: tree/AuxiliaryTree.hpp
---
