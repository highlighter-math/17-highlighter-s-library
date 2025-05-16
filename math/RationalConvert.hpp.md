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
  bundledCode: "#line 1 \"math/RationalConvert.hpp\"\npair<long long, long long> rational_convert(long\
    \ long x, long long m, long long d = 1000){\r\n  long long n = m / (2 * d);\r\n\
    \  pair<long long, long long> u = make_pair(m, 0);\r\n  pair<long long, long long>\
    \ v = make_pair(x, 1);\r\n  while(v.first != 0 && (v.first >= n || v.second >=\
    \ d)){\r\n    long long q = u.first / v.first;\r\n    pair<long long, long long>\
    \ r = make_pair(u.first - q * v.first, u.second + q * v.second);\r\n    u = v;\r\
    \n    v = r;\r\n  }\r\n  if(v.first < n && v.second < d) return v;\r\n}\n"
  code: "pair<long long, long long> rational_convert(long long x, long long m, long\
    \ long d = 1000){\r\n  long long n = m / (2 * d);\r\n  pair<long long, long long>\
    \ u = make_pair(m, 0);\r\n  pair<long long, long long> v = make_pair(x, 1);\r\n\
    \  while(v.first != 0 && (v.first >= n || v.second >= d)){\r\n    long long q\
    \ = u.first / v.first;\r\n    pair<long long, long long> r = make_pair(u.first\
    \ - q * v.first, u.second + q * v.second);\r\n    u = v;\r\n    v = r;\r\n  }\r\
    \n  if(v.first < n && v.second < d) return v;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/RationalConvert.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/RationalConvert.hpp
layout: document
redirect_from:
- /library/math/RationalConvert.hpp
- /library/math/RationalConvert.hpp.html
title: math/RationalConvert.hpp
---
