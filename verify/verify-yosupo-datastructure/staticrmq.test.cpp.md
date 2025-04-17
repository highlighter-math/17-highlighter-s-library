---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: data_structure/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/verify-yosupo-datastructure/staticrmq.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"data_structure/segtree.hpp\"\ntemplate<class\
    \ S,auto op,auto e> struct segtree{\n\tprivate:\n\tint N;\n\tvector<S> val;\n\t\
    public:\n\tsegtree(int siz) : N(siz),val(2*siz-1,e()){}\n\tsegtree(vector<S> v){\n\
    \t\tN=(int)(v.size());\n\t\tval.resize(2*N-1);\n\t\tfor(int i=N;i<2*N;i++){\n\t\
    \t\tval[i-1]=v[i-N];\n\t\t}\n\t\tfor(int i=N-1;i>0;i--){\n\t\t\tval[i-1]=op(val[(i<<1)-1],val[i<<1]);\n\
    \t\t}\n\t}\n\tvoid set(int p,S x){\n\t\tp+=N;\n\t\tval[p-1]=x;\n\t\twhile(p>1){\n\
    \t\t\tp>>=1;\n\t\t\tval[p-1]=op(val[(p<<1)-1],val[p<<1]);\n\t\t}\n\t}\n\tS get(int\
    \ p){\n\t\treturn val[p+N-1];\n\t}\n\tS prod(int l,int r){\n\t\tl+=N;\n\t\tr+=N;\n\
    \t\tS lret=e();\n\t\tS rret=e();\n\t\tfor(;l<r;l>>=1,r>>=1){\n\t\t\tif(l&1){\n\
    \t\t\t\tlret=op(lret,val[l-1]);\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif(r&1){\n\t\t\t\
    \tr--;\n\t\t\t\trret=op(val[r-1],rret);\n\t\t\t}\n\t\t}\n\t\treturn op(lret,rret);\n\
    \t}\n};\n#line 6 \"verify/verify-yosupo-datastructure/staticrmq.test.cpp\"\n\n\
    int op(int a,int b){\n\treturn min(a,b);\n}\n\nint e(){\n\treturn 1000000000;\n\
    }\n\nint main(){\n\tcin.tie(0)->ios::sync_with_stdio(0);\n\tint N,Q;\n\tcin >>\
    \ N >> Q;\n\tvector<int> A(N);\n\tfor(int i=0;i<N;i++) cin >> A[i];\n\tsegtree<int,op,e>\
    \ seg(A);\n\tfor(;Q--;){\n\t\tint l,r;\n\t\tcin >> l >> r;\n\t\tcout << seg.prod(l,r)\
    \ << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../data_structure/segtree.hpp\"\n\nint op(int\
    \ a,int b){\n\treturn min(a,b);\n}\n\nint e(){\n\treturn 1000000000;\n}\n\nint\
    \ main(){\n\tcin.tie(0)->ios::sync_with_stdio(0);\n\tint N,Q;\n\tcin >> N >> Q;\n\
    \tvector<int> A(N);\n\tfor(int i=0;i<N;i++) cin >> A[i];\n\tsegtree<int,op,e>\
    \ seg(A);\n\tfor(;Q--;){\n\t\tint l,r;\n\t\tcin >> l >> r;\n\t\tcout << seg.prod(l,r)\
    \ << '\\n';\n\t}\n}"
  dependsOn:
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-datastructure/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 22:12:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-datastructure/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-datastructure/staticrmq.test.cpp
- /verify/verify/verify-yosupo-datastructure/staticrmq.test.cpp.html
title: verify/verify-yosupo-datastructure/staticrmq.test.cpp
---
