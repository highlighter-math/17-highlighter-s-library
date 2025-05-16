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
  bundledCode: "#line 1 \"algorithm/XorConvolution.hpp\"\nconstexpr int LOG = 20;\r\
    \ntemplate<typename T>\r\nvoid Fast_WalshHadamard_Transform(vector<T> &v){\r\n\
    \  for(int i=1;i<(1<<LOG);i<<=1){\r\n    int mask=~i;\r\n    for(int j=i;j<(1<<LOG);j=(j+1)|i){\r\
    \n      T a=v[j&mask];\r\n      T &b=v[j];\r\n      v[j&mask]=(v[j&mask]+b)%mod;\r\
    \n      b=(a-b+mod)%mod;\r\n    }\r\n  }\r\n}\r\ntemplate<typename T>\r\nvector<T>\
    \ xor_convolution(vector<T> a,vector<T> b){\r\n  Fast_WalshHadamard_Transform(a);\r\
    \n  Fast_WalshHadamard_Transform(b);\r\n  for(int i=0;i<(1<<LOG);i++) a[i]=a[i]*b[i]%mod;\r\
    \n  Fast_WalshHadamard_Transform(a);\r\n  long long x=modpow((mod+1)/2,LOG);\r\
    \n  for(auto &i:a) i=i*x%mod;\r\n  return a;\r\n}\n"
  code: "constexpr int LOG = 20;\r\ntemplate<typename T>\r\nvoid Fast_WalshHadamard_Transform(vector<T>\
    \ &v){\r\n  for(int i=1;i<(1<<LOG);i<<=1){\r\n    int mask=~i;\r\n    for(int\
    \ j=i;j<(1<<LOG);j=(j+1)|i){\r\n      T a=v[j&mask];\r\n      T &b=v[j];\r\n \
    \     v[j&mask]=(v[j&mask]+b)%mod;\r\n      b=(a-b+mod)%mod;\r\n    }\r\n  }\r\
    \n}\r\ntemplate<typename T>\r\nvector<T> xor_convolution(vector<T> a,vector<T>\
    \ b){\r\n  Fast_WalshHadamard_Transform(a);\r\n  Fast_WalshHadamard_Transform(b);\r\
    \n  for(int i=0;i<(1<<LOG);i++) a[i]=a[i]*b[i]%mod;\r\n  Fast_WalshHadamard_Transform(a);\r\
    \n  long long x=modpow((mod+1)/2,LOG);\r\n  for(auto &i:a) i=i*x%mod;\r\n  return\
    \ a;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/XorConvolution.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/XorConvolution.hpp
layout: document
redirect_from:
- /library/algorithm/XorConvolution.hpp
- /library/algorithm/XorConvolution.hpp.html
title: algorithm/XorConvolution.hpp
---
