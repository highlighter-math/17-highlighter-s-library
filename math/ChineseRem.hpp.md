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
  bundledCode: "#line 1 \"math/ChineseRem.hpp\"\nll mod(ll a, ll mod) {\r\n    return\
    \ (a%mod+mod)%mod;\r\n}\r\nll extGcd(ll a, ll b, ll &p, ll &q) {  \r\n    if (b\
    \ == 0) { p = 1; q = 0; return a; }  \r\n    ll d = extGcd(b, a%b, q, p);  \r\n\
    \    q -= a/b * p;  \r\n    return d;  \r\n}\r\nP ChineseRem(const vector<ll>\
    \ &b, const vector<ll> &m) {\r\n  ll r = 0, M = 1;\r\n  for (int i = 0; i < (int)b.size();\
    \ ++i) {\r\n    ll p, q;\r\n    ll d = extGcd(M, m[i], p, q);\r\n    if ((b[i]\
    \ - r) % d != 0) return make_pair(0, -1);\r\n    ll tmp = (b[i] - r) / d * p %\
    \ (m[i]/d);\r\n    r += M * tmp;\r\n    M *= m[i]/d;\r\n  }\r\n  return make_pair(mod(r,\
    \ M), M);\r\n}\n"
  code: "ll mod(ll a, ll mod) {\r\n    return (a%mod+mod)%mod;\r\n}\r\nll extGcd(ll\
    \ a, ll b, ll &p, ll &q) {  \r\n    if (b == 0) { p = 1; q = 0; return a; }  \r\
    \n    ll d = extGcd(b, a%b, q, p);  \r\n    q -= a/b * p;  \r\n    return d; \
    \ \r\n}\r\nP ChineseRem(const vector<ll> &b, const vector<ll> &m) {\r\n  ll r\
    \ = 0, M = 1;\r\n  for (int i = 0; i < (int)b.size(); ++i) {\r\n    ll p, q;\r\
    \n    ll d = extGcd(M, m[i], p, q);\r\n    if ((b[i] - r) % d != 0) return make_pair(0,\
    \ -1);\r\n    ll tmp = (b[i] - r) / d * p % (m[i]/d);\r\n    r += M * tmp;\r\n\
    \    M *= m[i]/d;\r\n  }\r\n  return make_pair(mod(r, M), M);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ChineseRem.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ChineseRem.hpp
layout: document
redirect_from:
- /library/math/ChineseRem.hpp
- /library/math/ChineseRem.hpp.html
title: math/ChineseRem.hpp
---
