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
  bundledCode: "#line 2 \"data_structure/LiChaoTree.hpp\"\ntemplate<typename T, typename\
    \ U, size_t sz = (1LL<<20), U eps = 1>\r\nstruct LiChaoTree{\r\n  template <class\
    \ P, class Q>\r\n  inline bool chmax(P &a, const Q &b) {\r\n    return (a < b\
    \ ? a = b, 1 : 0);\r\n  }\r\n  template <class P, class Q>\r\n  inline bool chmin(P\
    \ &a, const Q &b) {\r\n    return (a > b ? a = b, 1 : 0);\r\n  }\r\n  struct Line{\r\
    \n    T a, b;\r\n    constexpr Line(T a, T b):a(a), b(b){};\r\n    constexpr Line():Line(0,\
    \ numeric_limits<T>::max()){};\r\n    T operator()(U x) const {return a*x+b;};\r\
    \n  };\r\n  struct Node{\r\n    Line f;\r\n    Node *l, *r;\r\n  };\r\n  int index;\r\
    \n  Node *NODE, *root;\r\n  U L, R;\r\n  LiChaoTree(U L, U R):index(0),root(nullptr),L(L),R(R){\r\
    \n    NODE = new Node[sz];\r\n  };\r\n  Node *new_node(){\r\n  \tNODE[index].f\
    \ = Line();\r\n    return &(NODE[index++]);\r\n  }\r\n  void insert_segment(U\
    \ xl, U xr, T a, T b){\r\n  \tassert(L <= xl && xl < xr && xr <= R);\r\n    Line\
    \ f(a, b);\r\n    if(!root) root = new_node();\r\n    insert_segment_sub(root,\
    \ xl, xr, f, L, R);\r\n  }\r\n  void insert_line(T a, T b){insert_segment(L, R,\
    \ a, b);}\r\n  T get_min(U x){\r\n  \tassert(L <= x && x < R);\r\n    if(!root)\
    \ return numeric_limits<T>::max();\r\n    return min_sub(root, x, L, R);\r\n \
    \ }\r\nprivate:\r\n  void insert_segment_sub(Node *rt, U xl, U xr, const Line\
    \ &f, U l, U r){\r\n  \tchmax(xl, l);\r\n    chmin(xr, r);\r\n    if(xl >= xr)\
    \ return;\r\n    if(l < xl || xr < r){\r\n      U mid = (l+r)/2;\r\n      if(!rt->l)\
    \ rt->l = new_node();\r\n      if(!rt->r) rt->r = new_node();\r\n      insert_segment_sub(rt->l,\
    \ xl, xr, f, l, mid);\r\n      insert_segment_sub(rt->r, xl, xr, f, mid, r);\r\
    \n    }else{\r\n      insert_line_sub(rt, f, l, r);\r\n    }\r\n  }\r\n  void\
    \ insert_line_sub(Node *rt, const Line &f, U l, U r){\r\n    T fl = f(l), fr =\
    \ f(r-eps);\r\n    Line g = rt->f;\r\n    T gl = g(l), gr = g(r-eps);\r\n    if(fl\
    \ >= gl && fr >= gr) return;\r\n    if(fl <= gl && fr <= gr){\r\n      rt->f =\
    \ f;\r\n      return;\r\n    }\r\n    U mid = (l+r)/2;\r\n    T fm = f(mid), gm\
    \ = g(mid);\r\n    if(fm <= gm){\r\n      rt->f = f;\r\n      if(fl < gl){\r\n\
    \        if(!rt->r) rt->r = new_node();\r\n        insert_line_sub(rt->r, g, mid,\
    \ r);\r\n      }else{\r\n        if(!rt->l) rt->l = new_node();\r\n        insert_line_sub(rt->l,\
    \ g, l, mid);\r\n      }\r\n    }else{\r\n      if(gl < fl){\r\n        if(!rt->r)\
    \ rt->r = new_node();\r\n        insert_line_sub(rt->r, f, mid, r);\r\n      }else{\r\
    \n        if(!rt->l) rt->l = new_node();\r\n        insert_line_sub(rt->l, f,\
    \ l, mid);\r\n      }\r\n    }\r\n  }\r\n  T min_sub(Node *rt, U x, U l, U r){\r\
    \n    T ret = rt->f(x);\r\n    U mid = (l+r)/2;\r\n    if(x < mid && rt->l) return\
    \ min(ret, min_sub(rt->l, x, l, mid));\r\n    if(x >= mid && rt->r) return min(ret,\
    \ min_sub(rt->r, x, mid, r));\r\n    return ret;\r\n  }\r\n};\n"
  code: "#pragma once\r\ntemplate<typename T, typename U, size_t sz = (1LL<<20), U\
    \ eps = 1>\r\nstruct LiChaoTree{\r\n  template <class P, class Q>\r\n  inline\
    \ bool chmax(P &a, const Q &b) {\r\n    return (a < b ? a = b, 1 : 0);\r\n  }\r\
    \n  template <class P, class Q>\r\n  inline bool chmin(P &a, const Q &b) {\r\n\
    \    return (a > b ? a = b, 1 : 0);\r\n  }\r\n  struct Line{\r\n    T a, b;\r\n\
    \    constexpr Line(T a, T b):a(a), b(b){};\r\n    constexpr Line():Line(0, numeric_limits<T>::max()){};\r\
    \n    T operator()(U x) const {return a*x+b;};\r\n  };\r\n  struct Node{\r\n \
    \   Line f;\r\n    Node *l, *r;\r\n  };\r\n  int index;\r\n  Node *NODE, *root;\r\
    \n  U L, R;\r\n  LiChaoTree(U L, U R):index(0),root(nullptr),L(L),R(R){\r\n  \
    \  NODE = new Node[sz];\r\n  };\r\n  Node *new_node(){\r\n  \tNODE[index].f =\
    \ Line();\r\n    return &(NODE[index++]);\r\n  }\r\n  void insert_segment(U xl,\
    \ U xr, T a, T b){\r\n  \tassert(L <= xl && xl < xr && xr <= R);\r\n    Line f(a,\
    \ b);\r\n    if(!root) root = new_node();\r\n    insert_segment_sub(root, xl,\
    \ xr, f, L, R);\r\n  }\r\n  void insert_line(T a, T b){insert_segment(L, R, a,\
    \ b);}\r\n  T get_min(U x){\r\n  \tassert(L <= x && x < R);\r\n    if(!root) return\
    \ numeric_limits<T>::max();\r\n    return min_sub(root, x, L, R);\r\n  }\r\nprivate:\r\
    \n  void insert_segment_sub(Node *rt, U xl, U xr, const Line &f, U l, U r){\r\n\
    \  \tchmax(xl, l);\r\n    chmin(xr, r);\r\n    if(xl >= xr) return;\r\n    if(l\
    \ < xl || xr < r){\r\n      U mid = (l+r)/2;\r\n      if(!rt->l) rt->l = new_node();\r\
    \n      if(!rt->r) rt->r = new_node();\r\n      insert_segment_sub(rt->l, xl,\
    \ xr, f, l, mid);\r\n      insert_segment_sub(rt->r, xl, xr, f, mid, r);\r\n \
    \   }else{\r\n      insert_line_sub(rt, f, l, r);\r\n    }\r\n  }\r\n  void insert_line_sub(Node\
    \ *rt, const Line &f, U l, U r){\r\n    T fl = f(l), fr = f(r-eps);\r\n    Line\
    \ g = rt->f;\r\n    T gl = g(l), gr = g(r-eps);\r\n    if(fl >= gl && fr >= gr)\
    \ return;\r\n    if(fl <= gl && fr <= gr){\r\n      rt->f = f;\r\n      return;\r\
    \n    }\r\n    U mid = (l+r)/2;\r\n    T fm = f(mid), gm = g(mid);\r\n    if(fm\
    \ <= gm){\r\n      rt->f = f;\r\n      if(fl < gl){\r\n        if(!rt->r) rt->r\
    \ = new_node();\r\n        insert_line_sub(rt->r, g, mid, r);\r\n      }else{\r\
    \n        if(!rt->l) rt->l = new_node();\r\n        insert_line_sub(rt->l, g,\
    \ l, mid);\r\n      }\r\n    }else{\r\n      if(gl < fl){\r\n        if(!rt->r)\
    \ rt->r = new_node();\r\n        insert_line_sub(rt->r, f, mid, r);\r\n      }else{\r\
    \n        if(!rt->l) rt->l = new_node();\r\n        insert_line_sub(rt->l, f,\
    \ l, mid);\r\n      }\r\n    }\r\n  }\r\n  T min_sub(Node *rt, U x, U l, U r){\r\
    \n    T ret = rt->f(x);\r\n    U mid = (l+r)/2;\r\n    if(x < mid && rt->l) return\
    \ min(ret, min_sub(rt->l, x, l, mid));\r\n    if(x >= mid && rt->r) return min(ret,\
    \ min_sub(rt->r, x, mid, r));\r\n    return ret;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2025-05-16 01:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/LiChaoTree.hpp
layout: document
redirect_from:
- /library/data_structure/LiChaoTree.hpp
- /library/data_structure/LiChaoTree.hpp.html
title: data_structure/LiChaoTree.hpp
---
