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
  bundledCode: "#line 1 \"math/dlp.hpp\"\n//\u30E2\u30CE\u30A4\u30C9\u306E\u578B,\
    \ \u96C6\u5408\u306E\u578B, \u30E2\u30CE\u30A4\u30C9\u306E\u6F14\u7B97, \u30E2\
    \u30CE\u30A4\u30C9\u306E\u4F5C\u7528, \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\r\ntemplate<class S, class T>\r\nstruct DLP{\r\n  int m;\r\n  S f;\r\n\
    \  T s, t;\r\n  long long n;\r\n  DLP(S _f, long long N, T _s, T _t):\r\n    n(N),\
    \ f(_f), s(_s), t(_t)\r\n    {m = sqrt(N);}\r\n  DLP(S _f, long long N, T _s,\
    \ T _t, long long _m):\r\n    n(N), f(_f), s(_s), t(_t)\r\n    {m = _m;}\r\n \
    \ template<S (*op)(S, S), T (*apply)(S, T), S (*e)()> int solve() const {\r\n\
    \    T t2 = t;\r\n    //unordered_map\u306B\u3059\u308B\u3068log\u304C\u843D\u3061\
    \u308B\r\n    map<T, bool> H;\r\n    for(int i = 0; i < m; i++){\r\n      t2 =\
    \ apply(f, t2);\r\n      H[t2] = true;\r\n    }\r\n    S g = e();\r\n    S f2\
    \ = f;\r\n    int m2 = m;\r\n    while(m2){\r\n      if(m2&1) g = op(g, f2);\r\
    \n      f2 = op(f2, f2);\r\n      m2 >>= 1;\r\n    }\r\n    //pow(f, m);\r\n \
    \   S g2 = g;\r\n    S g3 = e();\r\n    int isok = 2;\r\n    long long k = 0;\r\
    \n    while(++k && isok > 0 && (k-1)*m <= n){\r\n      if(H.contains(apply(g2,\
    \ s))){\r\n        isok--;\r\n        S g4 = g3;\r\n        for(int i = 0; i <=\
    \ m; i++){\r\n          if(apply(g4, s) == t) return (k-1)*m+i;\r\n          g4\
    \ = op(g4, f);\r\n        }\r\n      }\r\n      g2 = op(g2, g);\r\n      g3 =\
    \ op(g3, g);\r\n    }\r\n    return -1;\r\n  }\r\n};\r\n/*verify\r\nstruct S{\r\
    \n  long long a;\r\n  long long b;\r\n};\r\nusing T = long long;\r\nlong long\
    \ p;\r\nS op(S x, S y){\r\n  S ret;\r\n  ret.a = x.a*y.a%p;\r\n  ret.b = (x.b*y.a+y.b)%p;\r\
    \n  return ret;\r\n}\r\nT apply(S x, T y){\r\n  return (y*x.a+x.b)%p;\r\n}\r\n\
    S e(){\r\n  S ret;\r\n  ret.a = 1;\r\n  ret.b = 0;\r\n  return ret;\r\n}\r\nint\
    \ main(){\r\n  int t;\r\n  cin >> t;\r\n  while(t--){\r\n    long long a, b, s,\
    \ g;\r\n    cin >> p >> a >> b >> s >> g;\r\n    S f(a, b);\r\n    DLP<S, T> d(f,\
    \ p, s, g);\r\n    cout << d.solve<op, apply, e>() << endl;\r\n  }\r\n}\r\n*/\n"
  code: "//\u30E2\u30CE\u30A4\u30C9\u306E\u578B, \u96C6\u5408\u306E\u578B, \u30E2\u30CE\
    \u30A4\u30C9\u306E\u6F14\u7B97, \u30E2\u30CE\u30A4\u30C9\u306E\u4F5C\u7528, \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\r\ntemplate<class S, class T>\r\nstruct\
    \ DLP{\r\n  int m;\r\n  S f;\r\n  T s, t;\r\n  long long n;\r\n  DLP(S _f, long\
    \ long N, T _s, T _t):\r\n    n(N), f(_f), s(_s), t(_t)\r\n    {m = sqrt(N);}\r\
    \n  DLP(S _f, long long N, T _s, T _t, long long _m):\r\n    n(N), f(_f), s(_s),\
    \ t(_t)\r\n    {m = _m;}\r\n  template<S (*op)(S, S), T (*apply)(S, T), S (*e)()>\
    \ int solve() const {\r\n    T t2 = t;\r\n    //unordered_map\u306B\u3059\u308B\
    \u3068log\u304C\u843D\u3061\u308B\r\n    map<T, bool> H;\r\n    for(int i = 0;\
    \ i < m; i++){\r\n      t2 = apply(f, t2);\r\n      H[t2] = true;\r\n    }\r\n\
    \    S g = e();\r\n    S f2 = f;\r\n    int m2 = m;\r\n    while(m2){\r\n    \
    \  if(m2&1) g = op(g, f2);\r\n      f2 = op(f2, f2);\r\n      m2 >>= 1;\r\n  \
    \  }\r\n    //pow(f, m);\r\n    S g2 = g;\r\n    S g3 = e();\r\n    int isok =\
    \ 2;\r\n    long long k = 0;\r\n    while(++k && isok > 0 && (k-1)*m <= n){\r\n\
    \      if(H.contains(apply(g2, s))){\r\n        isok--;\r\n        S g4 = g3;\r\
    \n        for(int i = 0; i <= m; i++){\r\n          if(apply(g4, s) == t) return\
    \ (k-1)*m+i;\r\n          g4 = op(g4, f);\r\n        }\r\n      }\r\n      g2\
    \ = op(g2, g);\r\n      g3 = op(g3, g);\r\n    }\r\n    return -1;\r\n  }\r\n\
    };\r\n/*verify\r\nstruct S{\r\n  long long a;\r\n  long long b;\r\n};\r\nusing\
    \ T = long long;\r\nlong long p;\r\nS op(S x, S y){\r\n  S ret;\r\n  ret.a = x.a*y.a%p;\r\
    \n  ret.b = (x.b*y.a+y.b)%p;\r\n  return ret;\r\n}\r\nT apply(S x, T y){\r\n \
    \ return (y*x.a+x.b)%p;\r\n}\r\nS e(){\r\n  S ret;\r\n  ret.a = 1;\r\n  ret.b\
    \ = 0;\r\n  return ret;\r\n}\r\nint main(){\r\n  int t;\r\n  cin >> t;\r\n  while(t--){\r\
    \n    long long a, b, s, g;\r\n    cin >> p >> a >> b >> s >> g;\r\n    S f(a,\
    \ b);\r\n    DLP<S, T> d(f, p, s, g);\r\n    cout << d.solve<op, apply, e>() <<\
    \ endl;\r\n  }\r\n}\r\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/dlp.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dlp.hpp
layout: document
redirect_from:
- /library/math/dlp.hpp
- /library/math/dlp.hpp.html
title: math/dlp.hpp
---
