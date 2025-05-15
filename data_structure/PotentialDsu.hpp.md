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
  bundledCode: "#line 1 \"data_structure/PotentialDsu.hpp\"\n/*\r\n\u57FA\u672C\u7684\
    \u306A\u95A2\u6570\u306Fdsu\u3068\u540C\u3058\r\n\r\nT potential(int x) x\u306E\
    \u91CD\u307F\u3092\u6C42\u3081\u308B\r\nT diff(int x, int y) (weight[x]-weight[y])\u3092\
    \u8FD4\u3059\r\n  x\u3068y\u304C\u9023\u7D50\u3067\u306A\u3044\u5834\u5408\u306F\
    \u672A\u5B9A\u7FA9\r\nint merge(int x, int y, T p) \r\n  weight[x] = weight[y]\
    \ + p \u306B\u306A\u308B\u3088\u3046\u306Bmerge\u3092\u3059\u308B\r\n*/\r\ntemplate<class\
    \ T>\r\nstruct potential_dsu{\r\n  potential_dsu():n(0), cnt(0){}\r\n  explicit\
    \ potential_dsu(int _n):n(_n), cnt(_n), p(_n, -1), weight(_n, T()){}\r\n  int\
    \ merge(int a, int b, T pt){\r\n    assert(0 <= a && a < n);\r\n    assert(0 <=\
    \ b && b < n);\r\n    pt += potential(b) - potential(a);\r\n    a = leader(a),\
    \ b = leader(b);\r\n    if(a == b) return a;\r\n    cnt--;\r\n    if(p[a] < p[b])\
    \ swap(a, b), pt = -pt;\r\n    p[b] += p[a];\r\n    p[a] = b;\r\n    weight[a]\
    \ = pt;\r\n    return a;\r\n  }\r\n  bool same(int a, int b){\r\n    assert(0\
    \ <= a && a < n);\r\n    assert(0 <= b && b < n);\r\n    return leader(a) == leader(b);\r\
    \n  }\r\n  int size(int a){\r\n    assert(0 <= a && a < n);\r\n    return -p[leader(a)];\r\
    \n  }\r\n  int leader(int a){\r\n    assert(0 <= a && a < n);\r\n    if(p[a] <\
    \ 0) return a;\r\n    int r = leader(p[a]);\r\n    weight[a] += weight[p[a]];\r\
    \n    return p[a] = r;\r\n  }\r\n  T potential(int a){\r\n    leader(a);\r\n \
    \   return weight[a];\r\n  }\r\n  T diff(int a, int b){\r\n    return potential(a)\
    \ - potential(b);\r\n  }\r\n  vector<vector<int>> groups(){\r\n    vector<int>\
    \ lb(n), gs(n);\r\n    for(int i = 0; i < n; i++){\r\n      lb[i] = leader(i);\r\
    \n      gs[lb[i]]++;\r\n    }\r\n    vector<vector<int>> res(n), res2;\r\n   \
    \ for(int i = 0; i < n; i++) res[i].reserve(gs[i]);\r\n    for(int i = 0; i <\
    \ n; i++) res[lb[i]].push_back(i);\r\n    for(auto x:res) if(x.size() > 0) res2.push_back(x);\r\
    \n    return res2;\r\n  }\r\n  int count(){\r\n    return cnt;\r\n  }\r\n  private:\r\
    \n  int n, cnt;\r\n  vector<int> p;\r\n  vector<T> weight;\r\n};\n"
  code: "/*\r\n\u57FA\u672C\u7684\u306A\u95A2\u6570\u306Fdsu\u3068\u540C\u3058\r\n\
    \r\nT potential(int x) x\u306E\u91CD\u307F\u3092\u6C42\u3081\u308B\r\nT diff(int\
    \ x, int y) (weight[x]-weight[y])\u3092\u8FD4\u3059\r\n  x\u3068y\u304C\u9023\u7D50\
    \u3067\u306A\u3044\u5834\u5408\u306F\u672A\u5B9A\u7FA9\r\nint merge(int x, int\
    \ y, T p) \r\n  weight[x] = weight[y] + p \u306B\u306A\u308B\u3088\u3046\u306B\
    merge\u3092\u3059\u308B\r\n*/\r\ntemplate<class T>\r\nstruct potential_dsu{\r\n\
    \  potential_dsu():n(0), cnt(0){}\r\n  explicit potential_dsu(int _n):n(_n), cnt(_n),\
    \ p(_n, -1), weight(_n, T()){}\r\n  int merge(int a, int b, T pt){\r\n    assert(0\
    \ <= a && a < n);\r\n    assert(0 <= b && b < n);\r\n    pt += potential(b) -\
    \ potential(a);\r\n    a = leader(a), b = leader(b);\r\n    if(a == b) return\
    \ a;\r\n    cnt--;\r\n    if(p[a] < p[b]) swap(a, b), pt = -pt;\r\n    p[b] +=\
    \ p[a];\r\n    p[a] = b;\r\n    weight[a] = pt;\r\n    return a;\r\n  }\r\n  bool\
    \ same(int a, int b){\r\n    assert(0 <= a && a < n);\r\n    assert(0 <= b &&\
    \ b < n);\r\n    return leader(a) == leader(b);\r\n  }\r\n  int size(int a){\r\
    \n    assert(0 <= a && a < n);\r\n    return -p[leader(a)];\r\n  }\r\n  int leader(int\
    \ a){\r\n    assert(0 <= a && a < n);\r\n    if(p[a] < 0) return a;\r\n    int\
    \ r = leader(p[a]);\r\n    weight[a] += weight[p[a]];\r\n    return p[a] = r;\r\
    \n  }\r\n  T potential(int a){\r\n    leader(a);\r\n    return weight[a];\r\n\
    \  }\r\n  T diff(int a, int b){\r\n    return potential(a) - potential(b);\r\n\
    \  }\r\n  vector<vector<int>> groups(){\r\n    vector<int> lb(n), gs(n);\r\n \
    \   for(int i = 0; i < n; i++){\r\n      lb[i] = leader(i);\r\n      gs[lb[i]]++;\r\
    \n    }\r\n    vector<vector<int>> res(n), res2;\r\n    for(int i = 0; i < n;\
    \ i++) res[i].reserve(gs[i]);\r\n    for(int i = 0; i < n; i++) res[lb[i]].push_back(i);\r\
    \n    for(auto x:res) if(x.size() > 0) res2.push_back(x);\r\n    return res2;\r\
    \n  }\r\n  int count(){\r\n    return cnt;\r\n  }\r\n  private:\r\n  int n, cnt;\r\
    \n  vector<int> p;\r\n  vector<T> weight;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/PotentialDsu.hpp
  requiredBy: []
  timestamp: '2025-05-16 01:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/PotentialDsu.hpp
layout: document
redirect_from:
- /library/data_structure/PotentialDsu.hpp
- /library/data_structure/PotentialDsu.hpp.html
title: data_structure/PotentialDsu.hpp
---
