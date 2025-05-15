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
  bundledCode: "#line 1 \"data_structure/Trie.hpp\"\ntemplate<typename T>\r\nstruct\
    \ Trie{\r\n  struct Node{\r\n    int sum = 0;\r\n    map<T, Node*> m;\r\n  };\r\
    \n  Node* root = new Node;\r\n  void mk(Node*& t){\r\n    if(!t){\r\n      t =\
    \ new Node;\r\n      cnt++;\r\n    }\r\n  }\r\n  void insert_vector(const vector<T>&\
    \ s){\r\n    Node* c = root;\r\n    c->sum++;\r\n    for(const T &x:s){\r\n  \
    \    mk(c->m[x]);\r\n      c = c->m[x];\r\n      c->sum++;\r\n    }\r\n  }\r\n\
    \  void insert_string(const string& s){\r\n    if(!is_same<T, char>::value) assert(false);\r\
    \n    Node* c = root;\r\n    c->sum++;\r\n    for(const T &x:s){\r\n      mk(c->m[x]);\r\
    \n      c = c->m[x];\r\n      c->sum++;\r\n    }\r\n  }\r\n  int find_vector(const\
    \ vector<T>& s){\r\n    Node* c = root;\r\n    for(const T &x:s){\r\n      mk(c->m[x]);\r\
    \n      c = c->m[x];\r\n    }\r\n    return c->sum;\r\n  }\r\n  int find_string(const\
    \ string& s){\r\n    Node* c = root;\r\n    for(const T &x:s){\r\n      mk(c->m[x]);\r\
    \n      c = c->m[x];\r\n    }\r\n    return c->sum;\r\n  }\r\n  long long solve(const\
    \ string& s){\r\n    long long ret = 0;\r\n    Node* c = root;\r\n    for(const\
    \ T &x:s){\r\n      mk(c->m[x]);\r\n      c = c->m[x];\r\n      ret += c->sum;\r\
    \n    }\r\n    return ret;\r\n  }\r\n  int count(){\r\n    return cnt;\r\n  }\r\
    \n  private:\r\n  int cnt = 1;\r\n};\n"
  code: "template<typename T>\r\nstruct Trie{\r\n  struct Node{\r\n    int sum = 0;\r\
    \n    map<T, Node*> m;\r\n  };\r\n  Node* root = new Node;\r\n  void mk(Node*&\
    \ t){\r\n    if(!t){\r\n      t = new Node;\r\n      cnt++;\r\n    }\r\n  }\r\n\
    \  void insert_vector(const vector<T>& s){\r\n    Node* c = root;\r\n    c->sum++;\r\
    \n    for(const T &x:s){\r\n      mk(c->m[x]);\r\n      c = c->m[x];\r\n     \
    \ c->sum++;\r\n    }\r\n  }\r\n  void insert_string(const string& s){\r\n    if(!is_same<T,\
    \ char>::value) assert(false);\r\n    Node* c = root;\r\n    c->sum++;\r\n   \
    \ for(const T &x:s){\r\n      mk(c->m[x]);\r\n      c = c->m[x];\r\n      c->sum++;\r\
    \n    }\r\n  }\r\n  int find_vector(const vector<T>& s){\r\n    Node* c = root;\r\
    \n    for(const T &x:s){\r\n      mk(c->m[x]);\r\n      c = c->m[x];\r\n    }\r\
    \n    return c->sum;\r\n  }\r\n  int find_string(const string& s){\r\n    Node*\
    \ c = root;\r\n    for(const T &x:s){\r\n      mk(c->m[x]);\r\n      c = c->m[x];\r\
    \n    }\r\n    return c->sum;\r\n  }\r\n  long long solve(const string& s){\r\n\
    \    long long ret = 0;\r\n    Node* c = root;\r\n    for(const T &x:s){\r\n \
    \     mk(c->m[x]);\r\n      c = c->m[x];\r\n      ret += c->sum;\r\n    }\r\n\
    \    return ret;\r\n  }\r\n  int count(){\r\n    return cnt;\r\n  }\r\n  private:\r\
    \n  int cnt = 1;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Trie.hpp
  requiredBy: []
  timestamp: '2025-05-16 01:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/Trie.hpp
layout: document
redirect_from:
- /library/data_structure/Trie.hpp
- /library/data_structure/Trie.hpp.html
title: data_structure/Trie.hpp
---
