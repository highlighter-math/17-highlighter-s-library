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
  bundledCode: "#line 1 \"algorithm/ReRooting.hpp\"\ntemplate <class E, class V, E\
    \ (*merge)(E, E), E (*e)(), E (*put_edge)(V, int), V (*put_vertex)(E, int)>\r\n\
    struct RerootingDP {\r\n    struct edge {\r\n        int to, idx, xdi;\r\n   \
    \ };\r\n    RerootingDP(int n_ = 0) : n(n_), inner_edge_id(0) {\r\n        es.resize(2*n-2);\r\
    \n        start.resize(2*n-2);\r\n        if (n == 1) es_build();\r\n    }\r\n\
    \    void add_edge(int u, int v, int idx, int xdi){\r\n        start[inner_edge_id]\
    \ = u;\r\n        es[inner_edge_id] = {v,idx,xdi};\r\n        inner_edge_id++;\r\
    \n        start[inner_edge_id] = v;\r\n        es[inner_edge_id] = {u,xdi,idx};\r\
    \n        inner_edge_id++;\r\n        if (inner_edge_id == 2*n-2){\r\n       \
    \     es_build();\r\n        }\r\n    }\r\n    vector<V> build(int root_ = 0){\r\
    \n        root = root_;\r\n        vector<V> subdp(n); subdp[0] = put_vertex(e(),0);\r\
    \n        outs.resize(n);\r\n        vector<int> geta(n+1,0);\r\n        for (int\
    \ i = 0; i < n; i++) geta[i+1] = start[i+1] - start[i] - 1;\r\n        geta[root+1]++;\r\
    \n        for (int i = 0; i < n; i++) geta[i+1] += geta[i];\r\n        auto dfs\
    \ = [&](auto sfs, int v, int f) -> void {\r\n            E val = e();\r\n    \
    \        for (int i = start[v]; i < start[v+1]; i++){\r\n                if (es[i].to\
    \ == f){\r\n                    swap(es[start[v+1]-1],es[i]);\r\n            \
    \    }\r\n                if (es[i].to == f) continue;\r\n                sfs(sfs,es[i].to,v);\r\
    \n                E nval = put_edge(subdp[es[i].to],es[i].idx);\r\n          \
    \      outs[geta[v]++] = nval;\r\n                val = merge(val,nval);\r\n \
    \           }\r\n            subdp[v] = put_vertex(val, v);\r\n        };\r\n\
    \        dfs(dfs,root,-1);\r\n        return subdp;\r\n    }\r\n    vector<V>\
    \ reroot(){\r\n        vector<E> reverse_edge(n);\r\n        reverse_edge[root]\
    \ = e();\r\n        vector<V> answers(n);\r\n        auto dfs = [&](auto sfs,\
    \ int v) -> void {\r\n            int le = outs_start(v);\r\n            int ri\
    \ = outs_start(v+1);\r\n            int siz = ri - le;\r\n            vector<E>\
    \ rui(siz+1);\r\n            rui[siz] = e();\r\n            for (int i = siz-1;\
    \ i >= 0; i--){\r\n                rui[i] = merge(outs[le+i],rui[i+1]);\r\n  \
    \          }\r\n            answers[v] = put_vertex(merge(rui[0],reverse_edge[v]),v);\r\
    \n            E lui = e();\r\n            for (int i = 0; i < siz; i++){\r\n \
    \               V rdp = put_vertex(merge(merge(lui,rui[i+1]),reverse_edge[v]),v);\r\
    \n                reverse_edge[es[start[v]+i].to] = put_edge(rdp,es[start[v]+i].xdi);\r\
    \n                lui = merge(lui,outs[le+i]);\r\n                sfs(sfs,es[start[v]+i].to);\r\
    \n            }\r\n        };\r\n        dfs(dfs,root);\r\n        return answers;\r\
    \n    }\r\n    private:\r\n    int n, root, inner_edge_id;\r\n    vector<E> outs;\r\
    \n    vector<edge> es;\r\n    vector<int> start;\r\n    int outs_start(int v){\r\
    \n        int res = start[v] - v;\r\n        if (root < v) res++;\r\n        return\
    \ res;\r\n    }\r\n    void es_build(){\r\n        vector<edge> nes(2*n-2);\r\n\
    \        vector<int> nstart(n+2,0);\r\n        for (int i = 0; i < 2*n-2; i++)\
    \ nstart[start[i]+2]++;\r\n        for (int i = 0; i < n; i++) nstart[i+1] +=\
    \ nstart[i];\r\n        for (int i = 0; i < 2*n-2; i++) nes[nstart[start[i]+1]++]\
    \ = es[i];\r\n        swap(es,nes);\r\n        swap(start,nstart);\r\n    }\r\n\
    };\r\n"
  code: "template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V,\
    \ int), V (*put_vertex)(E, int)>\r\nstruct RerootingDP {\r\n    struct edge {\r\
    \n        int to, idx, xdi;\r\n    };\r\n    RerootingDP(int n_ = 0) : n(n_),\
    \ inner_edge_id(0) {\r\n        es.resize(2*n-2);\r\n        start.resize(2*n-2);\r\
    \n        if (n == 1) es_build();\r\n    }\r\n    void add_edge(int u, int v,\
    \ int idx, int xdi){\r\n        start[inner_edge_id] = u;\r\n        es[inner_edge_id]\
    \ = {v,idx,xdi};\r\n        inner_edge_id++;\r\n        start[inner_edge_id] =\
    \ v;\r\n        es[inner_edge_id] = {u,xdi,idx};\r\n        inner_edge_id++;\r\
    \n        if (inner_edge_id == 2*n-2){\r\n            es_build();\r\n        }\r\
    \n    }\r\n    vector<V> build(int root_ = 0){\r\n        root = root_;\r\n  \
    \      vector<V> subdp(n); subdp[0] = put_vertex(e(),0);\r\n        outs.resize(n);\r\
    \n        vector<int> geta(n+1,0);\r\n        for (int i = 0; i < n; i++) geta[i+1]\
    \ = start[i+1] - start[i] - 1;\r\n        geta[root+1]++;\r\n        for (int\
    \ i = 0; i < n; i++) geta[i+1] += geta[i];\r\n        auto dfs = [&](auto sfs,\
    \ int v, int f) -> void {\r\n            E val = e();\r\n            for (int\
    \ i = start[v]; i < start[v+1]; i++){\r\n                if (es[i].to == f){\r\
    \n                    swap(es[start[v+1]-1],es[i]);\r\n                }\r\n \
    \               if (es[i].to == f) continue;\r\n                sfs(sfs,es[i].to,v);\r\
    \n                E nval = put_edge(subdp[es[i].to],es[i].idx);\r\n          \
    \      outs[geta[v]++] = nval;\r\n                val = merge(val,nval);\r\n \
    \           }\r\n            subdp[v] = put_vertex(val, v);\r\n        };\r\n\
    \        dfs(dfs,root,-1);\r\n        return subdp;\r\n    }\r\n    vector<V>\
    \ reroot(){\r\n        vector<E> reverse_edge(n);\r\n        reverse_edge[root]\
    \ = e();\r\n        vector<V> answers(n);\r\n        auto dfs = [&](auto sfs,\
    \ int v) -> void {\r\n            int le = outs_start(v);\r\n            int ri\
    \ = outs_start(v+1);\r\n            int siz = ri - le;\r\n            vector<E>\
    \ rui(siz+1);\r\n            rui[siz] = e();\r\n            for (int i = siz-1;\
    \ i >= 0; i--){\r\n                rui[i] = merge(outs[le+i],rui[i+1]);\r\n  \
    \          }\r\n            answers[v] = put_vertex(merge(rui[0],reverse_edge[v]),v);\r\
    \n            E lui = e();\r\n            for (int i = 0; i < siz; i++){\r\n \
    \               V rdp = put_vertex(merge(merge(lui,rui[i+1]),reverse_edge[v]),v);\r\
    \n                reverse_edge[es[start[v]+i].to] = put_edge(rdp,es[start[v]+i].xdi);\r\
    \n                lui = merge(lui,outs[le+i]);\r\n                sfs(sfs,es[start[v]+i].to);\r\
    \n            }\r\n        };\r\n        dfs(dfs,root);\r\n        return answers;\r\
    \n    }\r\n    private:\r\n    int n, root, inner_edge_id;\r\n    vector<E> outs;\r\
    \n    vector<edge> es;\r\n    vector<int> start;\r\n    int outs_start(int v){\r\
    \n        int res = start[v] - v;\r\n        if (root < v) res++;\r\n        return\
    \ res;\r\n    }\r\n    void es_build(){\r\n        vector<edge> nes(2*n-2);\r\n\
    \        vector<int> nstart(n+2,0);\r\n        for (int i = 0; i < 2*n-2; i++)\
    \ nstart[start[i]+2]++;\r\n        for (int i = 0; i < n; i++) nstart[i+1] +=\
    \ nstart[i];\r\n        for (int i = 0; i < 2*n-2; i++) nes[nstart[start[i]+1]++]\
    \ = es[i];\r\n        swap(es,nes);\r\n        swap(start,nstart);\r\n    }\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/ReRooting.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/ReRooting.hpp
layout: document
redirect_from:
- /library/algorithm/ReRooting.hpp
- /library/algorithm/ReRooting.hpp.html
title: algorithm/ReRooting.hpp
---
