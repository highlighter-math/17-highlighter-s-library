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
  bundledCode: "#line 1 \"data_structure/RollbackDsu.hpp\"\n/*\r\n\u57FA\u672C\u7684\
    \u306A\u95A2\u6570\u306Fdsu\u3068\u540C\u3058\r\n\r\nundo() 1\u500B\u524D\u306E\
    \u64CD\u4F5C\u3092\u53D6\u308A\u6D88\u3059\r\nsnapshot() dsu\u306E\u72B6\u614B\
    \u3092\u4FDD\u5B58\u3059\u308B\r\nrollback(int state = -1) \r\n  state = -1\u306E\
    \u6642snapshot()\u3067\u4FDD\u5B58\u3057\u305F\u72B6\u614B\u306B\u623B\u308B\r\
    \n  state >= 0\u306E\u6642merge\u304Cstate\u56DE\u547C\u3070\u308C\u305F\u6642\
    \u306E\u72B6\u614B\u306B\u623B\u308B\r\nget_state() \u73FE\u5728\u306Emerge\u304C\
    \u547C\u3070\u308C\u305F\u56DE\u6570\u3092\u8FD4\u3059\r\n*/\r\nstruct rollback_dsu{\r\
    \n  rollback_dsu():n(0), cnt(0), inner_snap(0){}\r\n  explicit rollback_dsu(int\
    \ _n):n(_n), cnt(_n), inner_snap(0), p(_n, -1){}\r\n  int merge(int a, int b){\r\
    \n    assert(0 <= a && a < n);\r\n    assert(0 <= b && b < n);\r\n    int x =\
    \ leader(a), y = leader(b);\r\n    history.emplace(x, p[x]);\r\n    history.emplace(y,\
    \ p[y]);\r\n    history2.emplace(cnt);\r\n    if(x == y) return x;\r\n    cnt--;\r\
    \n    if(-p[x] < -p[y]) swap(x, y);\r\n    p[x] += p[y];\r\n    p[y] = x;\r\n\
    \    return x;\r\n  }\r\n  bool same(int a, int b){\r\n    assert(0 <= a && a\
    \ < n);\r\n    assert(0 <= b && b < n);\r\n    return leader(a) == leader(b);\r\
    \n  }\r\n  int size(int a){\r\n    assert(0 <= a && a < n);\r\n    return -p[leader(a)];\r\
    \n  }\r\n  int leader(int a){\r\n    assert(0 <= a && a < n);\r\n    if(p[a] <\
    \ 0) return a;\r\n    return p[a] = leader(p[a]);\r\n  }\r\n  void undo(){\r\n\
    \    p[history.top().first] = history.top().second;\r\n    history.pop();\r\n\
    \    p[history.top().first] = history.top().second;\r\n    history.pop();\r\n\
    \    cnt = history2.top();\r\n    history2.pop();\r\n  }\r\n  void snapshot(){\r\
    \n    inner_snap = (int)history2.size();\r\n  }\r\n  int get_state(){\r\n    return\
    \ (int)history2.size();\r\n  }\r\n  void rollback(int state = -1){\r\n    if(state\
    \ == -1) state = inner_snap;\r\n    assert(state <= (int)history2.size());\r\n\
    \    while(state < (int)history2.size()) undo();\r\n  }\r\n  vector<vector<int>>\
    \ groups(){\r\n    vector<int> lb(n), gs(n);\r\n    for(int i = 0; i < n; i++){\r\
    \n      lb[i] = leader(i);\r\n      gs[lb[i]]++;\r\n    }\r\n    vector<vector<int>>\
    \ res(n), res2;\r\n    for(int i = 0; i < n; i++) res[i].reserve(gs[i]);\r\n \
    \   for(int i = 0; i < n; i++) res[lb[i]].push_back(i);\r\n    for(auto x:res)\
    \ if(x.size() > 0) res2.push_back(x);\r\n    return res2;\r\n  }\r\n  int count(){\r\
    \n    return cnt;\r\n  }\r\n  private:\r\n  int n, cnt;\r\n  int inner_snap;\r\
    \n  vector<int> p;\r\n  stack<pair<int, int>> history;\r\n  stack<int> history2;\r\
    \n};\n"
  code: "/*\r\n\u57FA\u672C\u7684\u306A\u95A2\u6570\u306Fdsu\u3068\u540C\u3058\r\n\
    \r\nundo() 1\u500B\u524D\u306E\u64CD\u4F5C\u3092\u53D6\u308A\u6D88\u3059\r\nsnapshot()\
    \ dsu\u306E\u72B6\u614B\u3092\u4FDD\u5B58\u3059\u308B\r\nrollback(int state =\
    \ -1) \r\n  state = -1\u306E\u6642snapshot()\u3067\u4FDD\u5B58\u3057\u305F\u72B6\
    \u614B\u306B\u623B\u308B\r\n  state >= 0\u306E\u6642merge\u304Cstate\u56DE\u547C\
    \u3070\u308C\u305F\u6642\u306E\u72B6\u614B\u306B\u623B\u308B\r\nget_state() \u73FE\
    \u5728\u306Emerge\u304C\u547C\u3070\u308C\u305F\u56DE\u6570\u3092\u8FD4\u3059\r\
    \n*/\r\nstruct rollback_dsu{\r\n  rollback_dsu():n(0), cnt(0), inner_snap(0){}\r\
    \n  explicit rollback_dsu(int _n):n(_n), cnt(_n), inner_snap(0), p(_n, -1){}\r\
    \n  int merge(int a, int b){\r\n    assert(0 <= a && a < n);\r\n    assert(0 <=\
    \ b && b < n);\r\n    int x = leader(a), y = leader(b);\r\n    history.emplace(x,\
    \ p[x]);\r\n    history.emplace(y, p[y]);\r\n    history2.emplace(cnt);\r\n  \
    \  if(x == y) return x;\r\n    cnt--;\r\n    if(-p[x] < -p[y]) swap(x, y);\r\n\
    \    p[x] += p[y];\r\n    p[y] = x;\r\n    return x;\r\n  }\r\n  bool same(int\
    \ a, int b){\r\n    assert(0 <= a && a < n);\r\n    assert(0 <= b && b < n);\r\
    \n    return leader(a) == leader(b);\r\n  }\r\n  int size(int a){\r\n    assert(0\
    \ <= a && a < n);\r\n    return -p[leader(a)];\r\n  }\r\n  int leader(int a){\r\
    \n    assert(0 <= a && a < n);\r\n    if(p[a] < 0) return a;\r\n    return p[a]\
    \ = leader(p[a]);\r\n  }\r\n  void undo(){\r\n    p[history.top().first] = history.top().second;\r\
    \n    history.pop();\r\n    p[history.top().first] = history.top().second;\r\n\
    \    history.pop();\r\n    cnt = history2.top();\r\n    history2.pop();\r\n  }\r\
    \n  void snapshot(){\r\n    inner_snap = (int)history2.size();\r\n  }\r\n  int\
    \ get_state(){\r\n    return (int)history2.size();\r\n  }\r\n  void rollback(int\
    \ state = -1){\r\n    if(state == -1) state = inner_snap;\r\n    assert(state\
    \ <= (int)history2.size());\r\n    while(state < (int)history2.size()) undo();\r\
    \n  }\r\n  vector<vector<int>> groups(){\r\n    vector<int> lb(n), gs(n);\r\n\
    \    for(int i = 0; i < n; i++){\r\n      lb[i] = leader(i);\r\n      gs[lb[i]]++;\r\
    \n    }\r\n    vector<vector<int>> res(n), res2;\r\n    for(int i = 0; i < n;\
    \ i++) res[i].reserve(gs[i]);\r\n    for(int i = 0; i < n; i++) res[lb[i]].push_back(i);\r\
    \n    for(auto x:res) if(x.size() > 0) res2.push_back(x);\r\n    return res2;\r\
    \n  }\r\n  int count(){\r\n    return cnt;\r\n  }\r\n  private:\r\n  int n, cnt;\r\
    \n  int inner_snap;\r\n  vector<int> p;\r\n  stack<pair<int, int>> history;\r\n\
    \  stack<int> history2;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/RollbackDsu.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/RollbackDsu.hpp
layout: document
redirect_from:
- /library/data_structure/RollbackDsu.hpp
- /library/data_structure/RollbackDsu.hpp.html
title: data_structure/RollbackDsu.hpp
---
