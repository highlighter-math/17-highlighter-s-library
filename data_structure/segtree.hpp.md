---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-datastructure/staticrmq.test.cpp
    title: verify/verify-yosupo-datastructure/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segtree.hpp\"\ntemplate<class S,auto op,auto\
    \ e> struct segtree{\n\tprivate:\n\tint N;\n\tvector<S> val;\n\tpublic:\n\tsegtree(int\
    \ siz) : N(siz),val(2*siz-1,e()){}\n\tsegtree(vector<S> v){\n\t\tN=(int)(v.size());\n\
    \t\tval.resize(2*N-1);\n\t\tfor(int i=N;i<2*N;i++){\n\t\t\tval[i-1]=v[i-N];\n\t\
    \t}\n\t\tfor(int i=N-1;i>0;i--){\n\t\t\tval[i-1]=op(val[(i<<1)-1],val[i<<1]);\n\
    \t\t}\n\t}\n\tvoid set(int p,S x){\n\t\tp+=N;\n\t\tval[p-1]=x;\n\t\twhile(p>1){\n\
    \t\t\tp>>=1;\n\t\t\tval[p-1]=op(val[(p<<1)-1],val[p<<1]);\n\t\t}\n\t}\n\tS get(int\
    \ p){\n\t\treturn val[p+N-1];\n\t}\n\tS prod(int l,int r){\n\t\tl+=N;\n\t\tr+=N;\n\
    \t\tS lret=e();\n\t\tS rret=e();\n\t\tfor(;l<r;l>>=1,r>>=1){\n\t\t\tif(l&1){\n\
    \t\t\t\tlret=op(lret,val[l-1]);\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif(r&1){\n\t\t\t\
    \tr--;\n\t\t\t\trret=op(val[r-1],rret);\n\t\t\t}\n\t\t}\n\t\treturn op(lret,rret);\n\
    \t}\n};\n"
  code: "#pragma once\ntemplate<class S,auto op,auto e> struct segtree{\n\tprivate:\n\
    \tint N;\n\tvector<S> val;\n\tpublic:\n\tsegtree(int siz) : N(siz),val(2*siz-1,e()){}\n\
    \tsegtree(vector<S> v){\n\t\tN=(int)(v.size());\n\t\tval.resize(2*N-1);\n\t\t\
    for(int i=N;i<2*N;i++){\n\t\t\tval[i-1]=v[i-N];\n\t\t}\n\t\tfor(int i=N-1;i>0;i--){\n\
    \t\t\tval[i-1]=op(val[(i<<1)-1],val[i<<1]);\n\t\t}\n\t}\n\tvoid set(int p,S x){\n\
    \t\tp+=N;\n\t\tval[p-1]=x;\n\t\twhile(p>1){\n\t\t\tp>>=1;\n\t\t\tval[p-1]=op(val[(p<<1)-1],val[p<<1]);\n\
    \t\t}\n\t}\n\tS get(int p){\n\t\treturn val[p+N-1];\n\t}\n\tS prod(int l,int r){\n\
    \t\tl+=N;\n\t\tr+=N;\n\t\tS lret=e();\n\t\tS rret=e();\n\t\tfor(;l<r;l>>=1,r>>=1){\n\
    \t\t\tif(l&1){\n\t\t\t\tlret=op(lret,val[l-1]);\n\t\t\t\tl++;\n\t\t\t}\n\t\t\t\
    if(r&1){\n\t\t\t\tr--;\n\t\t\t\trret=op(val[r-1],rret);\n\t\t\t}\n\t\t}\n\t\t\
    return op(lret,rret);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy: []
  timestamp: '2025-05-16 01:10:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-datastructure/staticrmq.test.cpp
documentation_of: data_structure/segtree.hpp
layout: document
redirect_from:
- /library/data_structure/segtree.hpp
- /library/data_structure/segtree.hpp.html
title: data_structure/segtree.hpp
---
