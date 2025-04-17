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
  bundledCode: "#line 2 \"math/power.hpp\"\ntemplate<class S>\nS power(S a,S b,int\
    \ p=-1){\n\tS mul=a;\n\tS res=1;\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=mul;\n\
    \t\t\tif(p!=-1) res%=p;\n\t\t}\n\t\tmul*=mul;\n\t\tif(p!=-1) mul%=p;\n\t\tb>>=1;\n\
    \t}\n\tif(res<0)res+=p;\n\treturn res;\n}\n"
  code: "#pragma once\ntemplate<class S>\nS power(S a,S b,int p=-1){\n\tS mul=a;\n\
    \tS res=1;\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=mul;\n\t\t\tif(p!=-1) res%=p;\n\
    \t\t}\n\t\tmul*=mul;\n\t\tif(p!=-1) mul%=p;\n\t\tb>>=1;\n\t}\n\tif(res<0)res+=p;\n\
    \treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy: []
  timestamp: '2025-04-17 22:12:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
