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
  bundledCode: "#line 1 \"string/manacher.hpp\"\n#include<bits/stdc++.h>\r\nusing\
    \ namespace std;\r\nvector<int> manacher(string S){\r\n  vector<int> R(S.size());\r\
    \n  int i = 0, j = 0;\r\n  while (i < S.size()) {\r\n    while (i-j >= 0 && i+j\
    \ < S.size() && S[i-j] == S[i+j]) ++j;\r\n    R[i] = j;\r\n    int k = 1;\r\n\
    \    while (i-k >= 0 && k+R[i-k] < j) R[i+k] = R[i-k], ++k;\r\n    i += k; j -=\
    \ k;\r\n  }\r\n  return R;\r\n}\n"
  code: "#include<bits/stdc++.h>\r\nusing namespace std;\r\nvector<int> manacher(string\
    \ S){\r\n  vector<int> R(S.size());\r\n  int i = 0, j = 0;\r\n  while (i < S.size())\
    \ {\r\n    while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;\r\n   \
    \ R[i] = j;\r\n    int k = 1;\r\n    while (i-k >= 0 && k+R[i-k] < j) R[i+k] =\
    \ R[i-k], ++k;\r\n    i += k; j -= k;\r\n  }\r\n  return R;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
