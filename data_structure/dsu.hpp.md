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
  bundledCode: "#line 1 \"data_structure/dsu.hpp\"\nstruct dsu{\r\n  dsu():n(0), cnt(0){}\r\
    \n  explicit dsu(int _n):n(_n), cnt(_n), p(_n, -1){}\r\n  int merge(int a, int\
    \ b){\r\n    assert(0 <= a && a < n);\r\n    assert(0 <= b && b < n);\r\n    int\
    \ x = leader(a), y = leader(b);\r\n    if(x == y) return x;\r\n    cnt--;\r\n\
    \    if(-p[x] < -p[y]) swap(x, y);\r\n    p[x] += p[y];\r\n    p[y] = x;\r\n \
    \   return x;\r\n  }\r\n  bool same(int a, int b){\r\n    assert(0 <= a && a <\
    \ n);\r\n    assert(0 <= b && b < n);\r\n    return leader(a) == leader(b);\r\n\
    \  }\r\n  int size(int a){\r\n    assert(0 <= a && a < n);\r\n    return -p[leader(a)];\r\
    \n  }\r\n  int leader(int a){\r\n    assert(0 <= a && a < n);\r\n    if(p[a] <\
    \ 0) return a;\r\n    return p[a] = leader(p[a]);\r\n  }\r\n  vector<vector<int>>\
    \ groups(){\r\n    vector<int> lb(n), gs(n);\r\n    for(int i = 0; i < n; i++){\r\
    \n      lb[i] = leader(i);\r\n      gs[lb[i]]++;\r\n    }\r\n    vector<vector<int>>\
    \ res(n), res2;\r\n    for(int i = 0; i < n; i++) res[i].reserve(gs[i]);\r\n \
    \   for(int i = 0; i < n; i++) res[lb[i]].push_back(i);\r\n    for(auto x:res)\
    \ if(x.size() > 0) res2.push_back(x);\r\n    return res2;\r\n  }\r\n  int count(){\r\
    \n    return cnt;\r\n  }\r\n  private:\r\n  int n, cnt;\r\n  vector<int> p;\r\n\
    };\n"
  code: "struct dsu{\r\n  dsu():n(0), cnt(0){}\r\n  explicit dsu(int _n):n(_n), cnt(_n),\
    \ p(_n, -1){}\r\n  int merge(int a, int b){\r\n    assert(0 <= a && a < n);\r\n\
    \    assert(0 <= b && b < n);\r\n    int x = leader(a), y = leader(b);\r\n   \
    \ if(x == y) return x;\r\n    cnt--;\r\n    if(-p[x] < -p[y]) swap(x, y);\r\n\
    \    p[x] += p[y];\r\n    p[y] = x;\r\n    return x;\r\n  }\r\n  bool same(int\
    \ a, int b){\r\n    assert(0 <= a && a < n);\r\n    assert(0 <= b && b < n);\r\
    \n    return leader(a) == leader(b);\r\n  }\r\n  int size(int a){\r\n    assert(0\
    \ <= a && a < n);\r\n    return -p[leader(a)];\r\n  }\r\n  int leader(int a){\r\
    \n    assert(0 <= a && a < n);\r\n    if(p[a] < 0) return a;\r\n    return p[a]\
    \ = leader(p[a]);\r\n  }\r\n  vector<vector<int>> groups(){\r\n    vector<int>\
    \ lb(n), gs(n);\r\n    for(int i = 0; i < n; i++){\r\n      lb[i] = leader(i);\r\
    \n      gs[lb[i]]++;\r\n    }\r\n    vector<vector<int>> res(n), res2;\r\n   \
    \ for(int i = 0; i < n; i++) res[i].reserve(gs[i]);\r\n    for(int i = 0; i <\
    \ n; i++) res[lb[i]].push_back(i);\r\n    for(auto x:res) if(x.size() > 0) res2.push_back(x);\r\
    \n    return res2;\r\n  }\r\n  int count(){\r\n    return cnt;\r\n  }\r\n  private:\r\
    \n  int n, cnt;\r\n  vector<int> p;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dsu.hpp
  requiredBy: []
  timestamp: '2025-05-16 01:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/dsu.hpp
layout: document
redirect_from:
- /library/data_structure/dsu.hpp
- /library/data_structure/dsu.hpp.html
title: data_structure/dsu.hpp
---
