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
  bundledCode: "#line 1 \"algorithm/parser.hpp\"\n#include<bits/stdc++.h>\r\nusing\
    \ namespace std;\r\nusing ll = long long;\r\nstruct parser{\r\n  string s;\r\n\
    \  parser(string _s):s(_s){};\r\n  long long get(){\r\n    int i = 0;\r\n    return\
    \ f1(i);\r\n  }\r\n  ll f1(int &i){\r\n    ll val = f2(i);\r\n    while(s[i] ==\
    \ '+' || s[i] == '-'){\r\n      char op = s[i];\r\n      i++;\r\n      ll val2\
    \ = f2(i);\r\n      if(op == '+') val += val2;\r\n      else val -= val2;\r\n\
    \    }\r\n    return val;\r\n  }\r\n  ll f2(int &i){\r\n    ll val = f3(i);\r\n\
    \    while(s[i] == '*' || s[i] == '/'){\r\n      char op = s[i];\r\n      i++;\r\
    \n      ll val2 = f3(i);\r\n      if(op == '*') val *= val2;\r\n      else val\
    \ /= val2;\r\n    }\r\n    return val;\r\n  }\r\n  ll f3(int &i){\r\n    if(isdigit(s[i]))\
    \ return f4(i);\r\n    i++; //'('\r\n    ll val = f1(i);\r\n    i++; //')'\r\n\
    \    return val;\r\n  }\r\n  ll f4(int &i){\r\n    long long val = s[i++]-'0';\r\
    \n    while(isdigit(s[i])) val = val*10+s[i++]-'0';\r\n    return val;\r\n  }\r\
    \n};\n"
  code: "#include<bits/stdc++.h>\r\nusing namespace std;\r\nusing ll = long long;\r\
    \nstruct parser{\r\n  string s;\r\n  parser(string _s):s(_s){};\r\n  long long\
    \ get(){\r\n    int i = 0;\r\n    return f1(i);\r\n  }\r\n  ll f1(int &i){\r\n\
    \    ll val = f2(i);\r\n    while(s[i] == '+' || s[i] == '-'){\r\n      char op\
    \ = s[i];\r\n      i++;\r\n      ll val2 = f2(i);\r\n      if(op == '+') val +=\
    \ val2;\r\n      else val -= val2;\r\n    }\r\n    return val;\r\n  }\r\n  ll\
    \ f2(int &i){\r\n    ll val = f3(i);\r\n    while(s[i] == '*' || s[i] == '/'){\r\
    \n      char op = s[i];\r\n      i++;\r\n      ll val2 = f3(i);\r\n      if(op\
    \ == '*') val *= val2;\r\n      else val /= val2;\r\n    }\r\n    return val;\r\
    \n  }\r\n  ll f3(int &i){\r\n    if(isdigit(s[i])) return f4(i);\r\n    i++; //'('\r\
    \n    ll val = f1(i);\r\n    i++; //')'\r\n    return val;\r\n  }\r\n  ll f4(int\
    \ &i){\r\n    long long val = s[i++]-'0';\r\n    while(isdigit(s[i])) val = val*10+s[i++]-'0';\r\
    \n    return val;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/parser.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/parser.hpp
layout: document
redirect_from:
- /library/algorithm/parser.hpp
- /library/algorithm/parser.hpp.html
title: algorithm/parser.hpp
---
