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
  bundledCode: "#line 1 \"data_structure/Static_Deletable_CHT.hpp\"\nstruct Static_Deletable_CHT{\n\
    \tprivate:\n\tstruct LiChao{\n\t\tprivate:\n\t\tvector<pair<long long,long long>>\
    \ que;\n\t\tpublic:\n\t\tvoid push_back(pair<long long,long long> p){\n\t\t\t\
    while(true){\n\t\t\t\tif(que.size()<2){\n\t\t\t\t\tque.emplace_back(p);\n\t\t\t\
    \t\treturn;\n\t\t\t\t}\n\t\t\t\tpair<long long,long long> q=que.back();\n\t\t\t\
    \tif(p.first==q.first){\n\t\t\t\t\tif(q.first>=p.first){\n\t\t\t\t\t\treturn;\n\
    \t\t\t\t\t}\n\t\t\t\t\tque.pop_back();\n\t\t\t\t\tque.emplace_back(p);\n\t\t\t\
    \t\treturn;\n\t\t\t\t}\n\t\t\t\tque.pop_back();\n\t\t\t\tpair<long long,long long>\
    \ r=que.back();\n\t\t\t\tif((r.second-q.second)/(q.first-r.first)<=(q.second-p.second)/(p.first-q.first)){\n\
    \t\t\t\t\tque.emplace_back(q);\n\t\t\t\t\tque.emplace_back(p);\n\t\t\t\t\treturn;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tlong long get_max(int x){\n\t\t\tif(que.empty()){\n\
    \t\t\t\treturn 0LL;\n\t\t\t}\n\t\t\twhile(que.size()>1){\n\t\t\t\tpair<long long,long\
    \ long> p=que.back();\n\t\t\t\tpair<long long,long long> q=que[(int)(que.size())-2];\n\
    \t\t\t\tif(p.first*x+p.second<=q.first*x+q.second){\n\t\t\t\t\tque.pop_back();\n\
    \t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\treturn p.first*x+p.second;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\tpair<long long,long long> p=que.back();\n\t\t\treturn p.first*x+p.second;\n\
    \t\t}\n\t};\n\tvector<LiChao> vec;\n\tint N;\n\tvector<tuple<pair<long long,long\
    \ long>,int,int>> mem;\n\tpublic:\n\tStatic_Deletable_CHT(int Q) : vec(Q*2-1),N(Q){}\n\
    \tvoid add_line(int l,int r,pair<long long,long long> p){\n\t\t//[l,r)\u306Bp\u3092\
    \u8FFD\u52A0\n\t\t//\u5F8C\u3067\u307E\u3068\u3081\u3066\u884C\u3046\n\t\tif(l>=r)\
    \ return;\n\t\tmem.emplace_back(make_tuple(p,l,r));\n\t}\n\tvoid build(){\n\t\t\
    //mem\u3092\u30BD\u30FC\u30C8\n\t\tsort(mem.begin(),mem.end());\n\t\tfor(tuple<pair<long\
    \ long,long long>,int,int> t : mem){\n\t\t\tpair<long long,long long> p;\n\t\t\
    \tint l,r;\n\t\t\ttie(p,l,r)=t;\n\t\t\tl+=N;\n\t\t\tr+=N;\n\t\t\tfor(;l<r;l>>=1,r>>=1){\n\
    \t\t\t\tif(l&1){\n\t\t\t\t\tvec[l-1].push_back(p);\n\t\t\t\t\tl++;\n\t\t\t\t}\n\
    \t\t\t\tif(r&1){\n\t\t\t\t\tr--;\n\t\t\t\t\tvec[r-1].push_back(p);\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t}\n\tlong long get_max(int p,int x){\n\t\t//\u6642\u523Bp\u306E\
    max\n\t\tp+=N;\n\t\tlong long res=vec[p-1].get_max(x);\n\t\twhile(p>1){\n\t\t\t\
    p>>=1;\n\t\t\tres=max(res,vec[p-1].get_max(x));\n\t\t}\n\t\treturn res;\n\t}\n\
    };\n"
  code: "struct Static_Deletable_CHT{\n\tprivate:\n\tstruct LiChao{\n\t\tprivate:\n\
    \t\tvector<pair<long long,long long>> que;\n\t\tpublic:\n\t\tvoid push_back(pair<long\
    \ long,long long> p){\n\t\t\twhile(true){\n\t\t\t\tif(que.size()<2){\n\t\t\t\t\
    \tque.emplace_back(p);\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tpair<long long,long\
    \ long> q=que.back();\n\t\t\t\tif(p.first==q.first){\n\t\t\t\t\tif(q.first>=p.first){\n\
    \t\t\t\t\t\treturn;\n\t\t\t\t\t}\n\t\t\t\t\tque.pop_back();\n\t\t\t\t\tque.emplace_back(p);\n\
    \t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tque.pop_back();\n\t\t\t\tpair<long long,long\
    \ long> r=que.back();\n\t\t\t\tif((r.second-q.second)/(q.first-r.first)<=(q.second-p.second)/(p.first-q.first)){\n\
    \t\t\t\t\tque.emplace_back(q);\n\t\t\t\t\tque.emplace_back(p);\n\t\t\t\t\treturn;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tlong long get_max(int x){\n\t\t\tif(que.empty()){\n\
    \t\t\t\treturn 0LL;\n\t\t\t}\n\t\t\twhile(que.size()>1){\n\t\t\t\tpair<long long,long\
    \ long> p=que.back();\n\t\t\t\tpair<long long,long long> q=que[(int)(que.size())-2];\n\
    \t\t\t\tif(p.first*x+p.second<=q.first*x+q.second){\n\t\t\t\t\tque.pop_back();\n\
    \t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\treturn p.first*x+p.second;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\tpair<long long,long long> p=que.back();\n\t\t\treturn p.first*x+p.second;\n\
    \t\t}\n\t};\n\tvector<LiChao> vec;\n\tint N;\n\tvector<tuple<pair<long long,long\
    \ long>,int,int>> mem;\n\tpublic:\n\tStatic_Deletable_CHT(int Q) : vec(Q*2-1),N(Q){}\n\
    \tvoid add_line(int l,int r,pair<long long,long long> p){\n\t\t//[l,r)\u306Bp\u3092\
    \u8FFD\u52A0\n\t\t//\u5F8C\u3067\u307E\u3068\u3081\u3066\u884C\u3046\n\t\tif(l>=r)\
    \ return;\n\t\tmem.emplace_back(make_tuple(p,l,r));\n\t}\n\tvoid build(){\n\t\t\
    //mem\u3092\u30BD\u30FC\u30C8\n\t\tsort(mem.begin(),mem.end());\n\t\tfor(tuple<pair<long\
    \ long,long long>,int,int> t : mem){\n\t\t\tpair<long long,long long> p;\n\t\t\
    \tint l,r;\n\t\t\ttie(p,l,r)=t;\n\t\t\tl+=N;\n\t\t\tr+=N;\n\t\t\tfor(;l<r;l>>=1,r>>=1){\n\
    \t\t\t\tif(l&1){\n\t\t\t\t\tvec[l-1].push_back(p);\n\t\t\t\t\tl++;\n\t\t\t\t}\n\
    \t\t\t\tif(r&1){\n\t\t\t\t\tr--;\n\t\t\t\t\tvec[r-1].push_back(p);\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t}\n\tlong long get_max(int p,int x){\n\t\t//\u6642\u523Bp\u306E\
    max\n\t\tp+=N;\n\t\tlong long res=vec[p-1].get_max(x);\n\t\twhile(p>1){\n\t\t\t\
    p>>=1;\n\t\t\tres=max(res,vec[p-1].get_max(x));\n\t\t}\n\t\treturn res;\n\t}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Static_Deletable_CHT.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/Static_Deletable_CHT.hpp
layout: document
redirect_from:
- /library/data_structure/Static_Deletable_CHT.hpp
- /library/data_structure/Static_Deletable_CHT.hpp.html
title: data_structure/Static_Deletable_CHT.hpp
---
