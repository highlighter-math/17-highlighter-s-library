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
  bundledCode: "#line 1 \"tree/Centroid.hpp\"\nclass CentroidDecomposition\r\n{\r\n\
    private:\r\n    int V;\r\n    vector<vector<int> > G;\r\n    vector<bool> used;\r\
    \n    //sz:\u91CD\u5FC3\u5206\u89E3\u5F8C\u306E\u6700\u5927\u90E8\u5206\u6728\u306B\
    \u542B\u307E\u308C\u308B\u9802\u70B9\u306E\u6570(\u81EA\u5206\u3092\u542B\u3081\
    \u308B)\r\n    //par:\u91CD\u5FC3\u5206\u89E3\u5F8C\u306E\u89AA\u306E\u9802\u70B9\
    \r\n    vector<int> sz, par;\r\n    //\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\
    \u3092\u8A08\u7B97\r\n    void calcSize(int u,int p){\r\n        sz[u] = 1;\r\n\
    \        for(int v : G[u]){\r\n            if(!used[v] && v != p){\r\n       \
    \         calcSize(v,u);\r\n                sz[u] += sz[v];\r\n            }\r\
    \n        }\r\n    }\r\n    void cdBuild(int u,int p){\r\n        calcSize(u,-1);\r\
    \n        int tot = sz[u];\r\n        bool ok = false;\r\n        int pp = -1;\r\
    \n        //\u3044\u307E\u898B\u3066\u3044\u308B\u90E8\u5206\u6728\u3067\u306E\
    \u91CD\u5FC3\u3092\u898B\u3064\u3051\u308B\r\n        while(!ok){\r\n        \
    \    ok = true;\r\n            for(int v : G[u]){\r\n                if(!used[v]\
    \ && v != pp && 2*sz[v] > tot){\r\n                    pp = u, u = v, ok = false;\r\
    \n                    break;\r\n                }\r\n            }\r\n       \
    \ }\r\n        par[u] = p;\r\n        //\u4F55\u3089\u304B\u306E\u64CD\u4F5C\r\
    \n        used[u] = true;\r\n        //\u6DF1\u3055\u512A\u5148\u3067\u305F\u3069\
    \u308B\r\n        for(int v : G[u]){\r\n            if(!used[v]){\r\n        \
    \        cdBuild(v,u);\r\n            }\r\n        }\r\n    }\r\npublic:\r\n \
    \   CentroidDecomposition(int node_size) : V(node_size), G(V), used(V, false)\r\
    \n                                                , sz(V, 0), par(V, -1){}\r\n\
    \    void add_edge(int u,int v){\r\n        G[u].push_back(v), G[v].push_back(u);\r\
    \n    }\r\n    void build(){\r\n        cdBuild(0,-1);\r\n    }\r\n};\n"
  code: "class CentroidDecomposition\r\n{\r\nprivate:\r\n    int V;\r\n    vector<vector<int>\
    \ > G;\r\n    vector<bool> used;\r\n    //sz:\u91CD\u5FC3\u5206\u89E3\u5F8C\u306E\
    \u6700\u5927\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\u306E\
    \u6570(\u81EA\u5206\u3092\u542B\u3081\u308B)\r\n    //par:\u91CD\u5FC3\u5206\u89E3\
    \u5F8C\u306E\u89AA\u306E\u9802\u70B9\r\n    vector<int> sz, par;\r\n    //\u90E8\
    \u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\u8A08\u7B97\r\n    void calcSize(int\
    \ u,int p){\r\n        sz[u] = 1;\r\n        for(int v : G[u]){\r\n          \
    \  if(!used[v] && v != p){\r\n                calcSize(v,u);\r\n             \
    \   sz[u] += sz[v];\r\n            }\r\n        }\r\n    }\r\n    void cdBuild(int\
    \ u,int p){\r\n        calcSize(u,-1);\r\n        int tot = sz[u];\r\n       \
    \ bool ok = false;\r\n        int pp = -1;\r\n        //\u3044\u307E\u898B\u3066\
    \u3044\u308B\u90E8\u5206\u6728\u3067\u306E\u91CD\u5FC3\u3092\u898B\u3064\u3051\
    \u308B\r\n        while(!ok){\r\n            ok = true;\r\n            for(int\
    \ v : G[u]){\r\n                if(!used[v] && v != pp && 2*sz[v] > tot){\r\n\
    \                    pp = u, u = v, ok = false;\r\n                    break;\r\
    \n                }\r\n            }\r\n        }\r\n        par[u] = p;\r\n \
    \       //\u4F55\u3089\u304B\u306E\u64CD\u4F5C\r\n        used[u] = true;\r\n\
    \        //\u6DF1\u3055\u512A\u5148\u3067\u305F\u3069\u308B\r\n        for(int\
    \ v : G[u]){\r\n            if(!used[v]){\r\n                cdBuild(v,u);\r\n\
    \            }\r\n        }\r\n    }\r\npublic:\r\n    CentroidDecomposition(int\
    \ node_size) : V(node_size), G(V), used(V, false)\r\n                        \
    \                        , sz(V, 0), par(V, -1){}\r\n    void add_edge(int u,int\
    \ v){\r\n        G[u].push_back(v), G[v].push_back(u);\r\n    }\r\n    void build(){\r\
    \n        cdBuild(0,-1);\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/Centroid.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/Centroid.hpp
layout: document
redirect_from:
- /library/tree/Centroid.hpp
- /library/tree/Centroid.hpp.html
title: tree/Centroid.hpp
---
