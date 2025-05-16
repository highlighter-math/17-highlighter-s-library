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
  bundledCode: "#line 1 \"math/floor_sum.hpp\"\n// f(n,m,a,b)=sum[i=0,n-1] floor((a*i+b)/m)\r\
    \n// O(log min{n,m,a})\r\nll floor_sum(ll n,ll m,ll a,ll b){\r\n    ll res=0;\r\
    \n    if(a>=m){\r\n        res+=n*(n-1)/2*(a/m);\r\n        a%=m;\r\n    }\r\n\
    \    if(b>=m){\r\n        res+=n*(b/m);\r\n        b%=m;\r\n    }\r\n    ll mx=a*(n-1)+b;\r\
    \n    if(mx>=m){\r\n        res+=mx/m+floor_sum(mx/m,a,m,mx%m);\r\n    }\r\n \
    \   return res;        \r\n}\n"
  code: "// f(n,m,a,b)=sum[i=0,n-1] floor((a*i+b)/m)\r\n// O(log min{n,m,a})\r\nll\
    \ floor_sum(ll n,ll m,ll a,ll b){\r\n    ll res=0;\r\n    if(a>=m){\r\n      \
    \  res+=n*(n-1)/2*(a/m);\r\n        a%=m;\r\n    }\r\n    if(b>=m){\r\n      \
    \  res+=n*(b/m);\r\n        b%=m;\r\n    }\r\n    ll mx=a*(n-1)+b;\r\n    if(mx>=m){\r\
    \n        res+=mx/m+floor_sum(mx/m,a,m,mx%m);\r\n    }\r\n    return res;    \
    \    \r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor_sum.hpp
layout: document
redirect_from:
- /library/math/floor_sum.hpp
- /library/math/floor_sum.hpp.html
title: math/floor_sum.hpp
---
