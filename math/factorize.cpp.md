---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.cpp\"\nnamespace fast_factrize{\r\n  long\
    \ long fast_factrize_pow(long long n,long long k,const long long mod){\r\n   \
    \ __int128_t _n=n;\r\n    __int128_t res=1;\r\n    while(k){\r\n      if(k&1){\r\
    \n        res*=_n;\r\n        res%=mod;\r\n      }\r\n      _n*=_n;\r\n      _n%=mod;\r\
    \n      k>>=1;\r\n    }\r\n    return res;\r\n  }\r\n  bool miller_rabin(long\
    \ long n){\r\n    if(n==2) return true;\r\n    if(~n&1) return false;\r\n    int\
    \ s=__builtin_ctzll(n-1);\r\n    long long d=(n-1)/(1LL<<s);\r\n    vector<long\
    \ long> _a;\r\n    if(n<(1LL<<30)){\r\n      _a={2,7,61};\r\n    }else if(n<(1LL<<40)){\r\
    \n      _a={2,13,23,1662803};\r\n    }else{\r\n      _a={2,325,9375,28178,450775,9780504,1795265022};\r\
    \n    }\r\n    for(auto& a:_a){\r\n      if(n<=a) break;\r\n      long long t=d;\r\
    \n      __int128_t y=fast_factrize_pow(a,t,n);\r\n      while(t!=n-1&&y!=1&&y!=n-1){\r\
    \n        y*=y;\r\n        y%=n;\r\n        t*=2;\r\n      }\r\n      if(y!=n-1&&(~t&1)){\r\
    \n        return false;\r\n      }\r\n    }\r\n    return true;\r\n  }\r\n  long\
    \ long pollard_rho(long long n){\r\n    if(~n&1) return 2;\r\n    if(n%3==0) return\
    \ 3;\r\n    if(n%5==0) return 5;\r\n    if(miller_rabin(n)) return n;\r\n    long\
    \ long c;\r\n    auto f=[&](long long x){return (long long)(((__int128_t)x*(__int128_t)x+(__int128_t)c)%n);};\r\
    \n    for(c=1;c<n;c++){\r\n      long long x=1,y=1,ys=1;\r\n      __int128_t q=1;\r\
    \n      long long g=1;\r\n      constexpr int m=128;\r\n      for(int r=1;g==1;r<<=1){\r\
    \n        x=y;\r\n        for(int i=0;i<r;i++) y=f(y);\r\n        for(int k=0;g==1&&k<r;k+=m){\r\
    \n          ys=y;\r\n          for(int i=0;i<m&&i<r-k;i++){\r\n            q*=abs(x-(y=f(y)));\r\
    \n            q%=n;\r\n          }\r\n          g=gcd(n,(long long)q);\r\n   \
    \     }\r\n      }\r\n      if(g==n){\r\n        do{\r\n          g=gcd(n,abs(x-(ys=f(ys))));\r\
    \n        }while(g==1);\r\n      }\r\n      if(g!=n) return g;  \r\n    }\r\n\
    \  }\r\n  vector<long long> factorize_init(long long n){\r\n    if(n<=1) return\
    \ {};\r\n    long long p=pollard_rho(n);\r\n    if(p==n) return {n};\r\n    auto\
    \ l=factorize_init(p);\r\n    auto r=factorize_init(n/p);\r\n    copy(r.begin(),r.end(),back_inserter(l));\r\
    \n    return l;\r\n  }\r\n  vector<long long> factorize(long long n){\r\n    vector<long\
    \ long> res=factorize_init(n);\r\n    sort(res.begin(),res.end());\r\n    return\
    \ res;\r\n  }\r\n  vector<pair<long long,long long>> factorize_prime(long long\
    \ n){\r\n    vector<long long> res=factorize(n);\r\n    vector<pair<long long,long\
    \ long>> ret;\r\n    for(int i=0;i<res.size();i++){\r\n      if(i==0||res[i]!=res[i-1])\
    \ ret.push_back({res[i],1});\r\n      else ret[ret.size()-1].second++;\r\n   \
    \ }\r\n    return ret;\r\n  }\r\n  vector<long long> divisor(long long n){\r\n\
    \    vector<pair<long long,long long>> v=factorize_prime(n);\r\n    vector<long\
    \ long> ret;\r\n    auto f=[&](auto rc,int i,long long x)->void{\r\n      if(i==(int)v.size()){\r\
    \n        ret.push_back(x);\r\n        return;\r\n      }\r\n      for(int j=0;j<=v[i].second;j++){\r\
    \n        rc(rc,i+1,x);\r\n        x*=v[i].first;\r\n      }\r\n    };\r\n   \
    \ f(f,0,1);\r\n    sort(ret.begin(),ret.end());\r\n    return ret;\r\n  }\r\n\
    };\r\n//using namespace fast_factrize;\n"
  code: "#pragma once\r\nnamespace fast_factrize{\r\n  long long fast_factrize_pow(long\
    \ long n,long long k,const long long mod){\r\n    __int128_t _n=n;\r\n    __int128_t\
    \ res=1;\r\n    while(k){\r\n      if(k&1){\r\n        res*=_n;\r\n        res%=mod;\r\
    \n      }\r\n      _n*=_n;\r\n      _n%=mod;\r\n      k>>=1;\r\n    }\r\n    return\
    \ res;\r\n  }\r\n  bool miller_rabin(long long n){\r\n    if(n==2) return true;\r\
    \n    if(~n&1) return false;\r\n    int s=__builtin_ctzll(n-1);\r\n    long long\
    \ d=(n-1)/(1LL<<s);\r\n    vector<long long> _a;\r\n    if(n<(1LL<<30)){\r\n \
    \     _a={2,7,61};\r\n    }else if(n<(1LL<<40)){\r\n      _a={2,13,23,1662803};\r\
    \n    }else{\r\n      _a={2,325,9375,28178,450775,9780504,1795265022};\r\n   \
    \ }\r\n    for(auto& a:_a){\r\n      if(n<=a) break;\r\n      long long t=d;\r\
    \n      __int128_t y=fast_factrize_pow(a,t,n);\r\n      while(t!=n-1&&y!=1&&y!=n-1){\r\
    \n        y*=y;\r\n        y%=n;\r\n        t*=2;\r\n      }\r\n      if(y!=n-1&&(~t&1)){\r\
    \n        return false;\r\n      }\r\n    }\r\n    return true;\r\n  }\r\n  long\
    \ long pollard_rho(long long n){\r\n    if(~n&1) return 2;\r\n    if(n%3==0) return\
    \ 3;\r\n    if(n%5==0) return 5;\r\n    if(miller_rabin(n)) return n;\r\n    long\
    \ long c;\r\n    auto f=[&](long long x){return (long long)(((__int128_t)x*(__int128_t)x+(__int128_t)c)%n);};\r\
    \n    for(c=1;c<n;c++){\r\n      long long x=1,y=1,ys=1;\r\n      __int128_t q=1;\r\
    \n      long long g=1;\r\n      constexpr int m=128;\r\n      for(int r=1;g==1;r<<=1){\r\
    \n        x=y;\r\n        for(int i=0;i<r;i++) y=f(y);\r\n        for(int k=0;g==1&&k<r;k+=m){\r\
    \n          ys=y;\r\n          for(int i=0;i<m&&i<r-k;i++){\r\n            q*=abs(x-(y=f(y)));\r\
    \n            q%=n;\r\n          }\r\n          g=gcd(n,(long long)q);\r\n   \
    \     }\r\n      }\r\n      if(g==n){\r\n        do{\r\n          g=gcd(n,abs(x-(ys=f(ys))));\r\
    \n        }while(g==1);\r\n      }\r\n      if(g!=n) return g;  \r\n    }\r\n\
    \  }\r\n  vector<long long> factorize_init(long long n){\r\n    if(n<=1) return\
    \ {};\r\n    long long p=pollard_rho(n);\r\n    if(p==n) return {n};\r\n    auto\
    \ l=factorize_init(p);\r\n    auto r=factorize_init(n/p);\r\n    copy(r.begin(),r.end(),back_inserter(l));\r\
    \n    return l;\r\n  }\r\n  vector<long long> factorize(long long n){\r\n    vector<long\
    \ long> res=factorize_init(n);\r\n    sort(res.begin(),res.end());\r\n    return\
    \ res;\r\n  }\r\n  vector<pair<long long,long long>> factorize_prime(long long\
    \ n){\r\n    vector<long long> res=factorize(n);\r\n    vector<pair<long long,long\
    \ long>> ret;\r\n    for(int i=0;i<res.size();i++){\r\n      if(i==0||res[i]!=res[i-1])\
    \ ret.push_back({res[i],1});\r\n      else ret[ret.size()-1].second++;\r\n   \
    \ }\r\n    return ret;\r\n  }\r\n  vector<long long> divisor(long long n){\r\n\
    \    vector<pair<long long,long long>> v=factorize_prime(n);\r\n    vector<long\
    \ long> ret;\r\n    auto f=[&](auto rc,int i,long long x)->void{\r\n      if(i==(int)v.size()){\r\
    \n        ret.push_back(x);\r\n        return;\r\n      }\r\n      for(int j=0;j<=v[i].second;j++){\r\
    \n        rc(rc,i+1,x);\r\n        x*=v[i].first;\r\n      }\r\n    };\r\n   \
    \ f(f,0,1);\r\n    sort(ret.begin(),ret.end());\r\n    return ret;\r\n  }\r\n\
    };\r\n//using namespace fast_factrize;"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize.cpp
  requiredBy: []
  timestamp: '2025-05-16 01:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize.cpp
layout: document
redirect_from:
- /library/math/factorize.cpp
- /library/math/factorize.cpp.html
title: math/factorize.cpp
---
