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
  bundledCode: "#line 1 \"data_structure/WaveletMatrix.hpp\"\n\r\n#include <immintrin.h>\r\
    \n\r\nstruct bit_vector {\r\n  using u32 = uint32_t;\r\n  using i64 = int64_t;\r\
    \n  using u64 = uint64_t;\r\n\r\n  static constexpr u32 w = 64;\r\n  vector<u64>\
    \ block;\r\n  vector<u32> count;\r\n  u32 n, zeros;\r\n\r\n  inline u32 get(u32\
    \ i) const { return u32(block[i / w] >> (i % w)) & 1u; }\r\n  inline void set(u32\
    \ i) { block[i / w] |= 1LL << (i % w); }\r\n\r\n  bit_vector() {}\r\n  bit_vector(int\
    \ _n) { init(_n); }\r\n  __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\r\n    n = zeros = _n;\r\n    block.resize(n / w + 1, 0);\r\n\
    \    count.resize(block.size(), 0);\r\n  }\r\n\r\n  __attribute__((target(\"popcnt\"\
    ))) void build() {\r\n    for (u32 i = 1; i < block.size(); ++i)\r\n      count[i]\
    \ = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\r\n    zeros = rank0(n);\r\n\
    \  }\r\n\r\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\r\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\r\n    return count[i / w] +\
    \ _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));\r\n  }\r\n};\r\n\r\ntemplate\
    \ <typename T>\r\nstruct WaveletMatrix {\r\n  using u32 = uint32_t;\r\n  using\
    \ i64 = int64_t;\r\n  using u64 = uint64_t;\r\n\r\n  int n, lg;\r\n  vector<T>\
    \ a;\r\n  vector<bit_vector> bv;\r\n\r\n  WaveletMatrix(u32 _n) : n(max<u32>(_n,\
    \ 1)), a(n) {}\r\n  WaveletMatrix(const vector<T>& _a) : n(_a.size()), a(_a) {\
    \ build(); }\r\n\r\n  __attribute__((optimize(\"O3\"))) void build() {\r\n   \
    \ lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\r\n    bv.assign(lg,\
    \ n);\r\n    vector<T> cur = a, nxt(n);\r\n    for (int h = lg - 1; h >= 0; --h)\
    \ {\r\n      for (int i = 0; i < n; ++i)\r\n        if ((cur[i] >> h) & 1) bv[h].set(i);\r\
    \n      bv[h].build();\r\n      array<decltype(begin(nxt)), 2> it{begin(nxt),\
    \ begin(nxt) + bv[h].zeros};\r\n      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++\
    \ = cur[i];\r\n      swap(cur, nxt);\r\n    }\r\n    return;\r\n  }\r\n\r\n  void\
    \ set(u32 i, const T& x) { \r\n    assert(x >= 0);\r\n    a[i] = x; \r\n  }\r\n\
    \r\n  inline pair<u32, u32> succ0(int l, int r, int h) const {\r\n    return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\r\n  }\r\n\r\n  inline pair<u32, u32> succ1(int l, int r, int\
    \ h) const {\r\n    u32 l0 = bv[h].rank0(l);\r\n    u32 r0 = bv[h].rank0(r);\r\
    \n    u32 zeros = bv[h].zeros;\r\n    return make_pair(l + zeros - l0, r + zeros\
    \ - r0);\r\n  }\r\n\r\n  // return a[k]\r\n  T access(u32 k) const {\r\n    T\
    \ ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      u32 f = bv[h].get(k);\r\
    \n      ret |= f ? T(1) << h : 0;\r\n      k = f ? bv[h].rank1(k) + bv[h].zeros\
    \ : bv[h].rank0(k);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // k-th (0-indexed)\
    \ smallest number in a[l, r)\r\n  T kth_smallest(u32 l, u32 r, u32 k) const {\r\
    \n    T res = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      u32 l0 =\
    \ bv[h].rank0(l), r0 = bv[h].rank0(r);\r\n      if (k < r0 - l0)\r\n        l\
    \ = l0, r = r0;\r\n      else {\r\n        k -= r0 - l0;\r\n        res |= (T)1\
    \ << h;\r\n        l += bv[h].zeros - l0;\r\n        r += bv[h].zeros - r0;\r\n\
    \      }\r\n    }\r\n    return res;\r\n  }\r\n\r\n  // k-th (0-indexed) largest\
    \ number in a[l, r)\r\n  T kth_largest(int l, int r, int k) {\r\n    return kth_smallest(l,\
    \ r, r - l - k - 1);\r\n  }\r\n\r\n  // count i s.t. (l <= i < r) && (v[i] < upper)\r\
    \n  int range_freq(int l, int r, T upper) {\r\n    if (upper >= (T(1) << lg))\
    \ return r - l;\r\n    int ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\
    \n      bool f = (upper >> h) & 1;\r\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\
    \n      if (f) {\r\n        ret += r0 - l0;\r\n        l += bv[h].zeros - l0;\r\
    \n        r += bv[h].zeros - r0;\r\n      } else {\r\n        l = l0;\r\n    \
    \    r = r0;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  int range_freq(int\
    \ l, int r, T lower, T upper) {\r\n    return range_freq(l, r, upper) - range_freq(l,\
    \ r, lower);\r\n  }\r\n\r\n  // max v[i] s.t. (l <= i < r) && (v[i] < upper)\r\
    \n  T prev_value(int l, int r, T upper) {\r\n    int cnt = range_freq(l, r, upper);\r\
    \n    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\r\n  }\r\n\r\n  //\
    \ min v[i] s.t. (l <= i < r) && (lower <= v[i])\r\n  T next_value(int l, int r,\
    \ T lower) {\r\n    int cnt = range_freq(l, r, lower);\r\n    return cnt == r\
    \ - l ? T(-1) : kth_smallest(l, r, cnt);\r\n  }\r\n};\r\n"
  code: "\r\n#include <immintrin.h>\r\n\r\nstruct bit_vector {\r\n  using u32 = uint32_t;\r\
    \n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\n\r\n  static constexpr\
    \ u32 w = 64;\r\n  vector<u64> block;\r\n  vector<u32> count;\r\n  u32 n, zeros;\r\
    \n\r\n  inline u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u;\
    \ }\r\n  inline void set(u32 i) { block[i / w] |= 1LL << (i % w); }\r\n\r\n  bit_vector()\
    \ {}\r\n  bit_vector(int _n) { init(_n); }\r\n  __attribute__((optimize(\"O3\"\
    , \"unroll-loops\"))) void init(int _n) {\r\n    n = zeros = _n;\r\n    block.resize(n\
    \ / w + 1, 0);\r\n    count.resize(block.size(), 0);\r\n  }\r\n\r\n  __attribute__((target(\"\
    popcnt\"))) void build() {\r\n    for (u32 i = 1; i < block.size(); ++i)\r\n \
    \     count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\r\n    zeros = rank0(n);\r\
    \n  }\r\n\r\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\r\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\r\n    return count[i / w] +\
    \ _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));\r\n  }\r\n};\r\n\r\ntemplate\
    \ <typename T>\r\nstruct WaveletMatrix {\r\n  using u32 = uint32_t;\r\n  using\
    \ i64 = int64_t;\r\n  using u64 = uint64_t;\r\n\r\n  int n, lg;\r\n  vector<T>\
    \ a;\r\n  vector<bit_vector> bv;\r\n\r\n  WaveletMatrix(u32 _n) : n(max<u32>(_n,\
    \ 1)), a(n) {}\r\n  WaveletMatrix(const vector<T>& _a) : n(_a.size()), a(_a) {\
    \ build(); }\r\n\r\n  __attribute__((optimize(\"O3\"))) void build() {\r\n   \
    \ lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\r\n    bv.assign(lg,\
    \ n);\r\n    vector<T> cur = a, nxt(n);\r\n    for (int h = lg - 1; h >= 0; --h)\
    \ {\r\n      for (int i = 0; i < n; ++i)\r\n        if ((cur[i] >> h) & 1) bv[h].set(i);\r\
    \n      bv[h].build();\r\n      array<decltype(begin(nxt)), 2> it{begin(nxt),\
    \ begin(nxt) + bv[h].zeros};\r\n      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++\
    \ = cur[i];\r\n      swap(cur, nxt);\r\n    }\r\n    return;\r\n  }\r\n\r\n  void\
    \ set(u32 i, const T& x) { \r\n    assert(x >= 0);\r\n    a[i] = x; \r\n  }\r\n\
    \r\n  inline pair<u32, u32> succ0(int l, int r, int h) const {\r\n    return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\r\n  }\r\n\r\n  inline pair<u32, u32> succ1(int l, int r, int\
    \ h) const {\r\n    u32 l0 = bv[h].rank0(l);\r\n    u32 r0 = bv[h].rank0(r);\r\
    \n    u32 zeros = bv[h].zeros;\r\n    return make_pair(l + zeros - l0, r + zeros\
    \ - r0);\r\n  }\r\n\r\n  // return a[k]\r\n  T access(u32 k) const {\r\n    T\
    \ ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      u32 f = bv[h].get(k);\r\
    \n      ret |= f ? T(1) << h : 0;\r\n      k = f ? bv[h].rank1(k) + bv[h].zeros\
    \ : bv[h].rank0(k);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // k-th (0-indexed)\
    \ smallest number in a[l, r)\r\n  T kth_smallest(u32 l, u32 r, u32 k) const {\r\
    \n    T res = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      u32 l0 =\
    \ bv[h].rank0(l), r0 = bv[h].rank0(r);\r\n      if (k < r0 - l0)\r\n        l\
    \ = l0, r = r0;\r\n      else {\r\n        k -= r0 - l0;\r\n        res |= (T)1\
    \ << h;\r\n        l += bv[h].zeros - l0;\r\n        r += bv[h].zeros - r0;\r\n\
    \      }\r\n    }\r\n    return res;\r\n  }\r\n\r\n  // k-th (0-indexed) largest\
    \ number in a[l, r)\r\n  T kth_largest(int l, int r, int k) {\r\n    return kth_smallest(l,\
    \ r, r - l - k - 1);\r\n  }\r\n\r\n  // count i s.t. (l <= i < r) && (v[i] < upper)\r\
    \n  int range_freq(int l, int r, T upper) {\r\n    if (upper >= (T(1) << lg))\
    \ return r - l;\r\n    int ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\
    \n      bool f = (upper >> h) & 1;\r\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\
    \n      if (f) {\r\n        ret += r0 - l0;\r\n        l += bv[h].zeros - l0;\r\
    \n        r += bv[h].zeros - r0;\r\n      } else {\r\n        l = l0;\r\n    \
    \    r = r0;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  int range_freq(int\
    \ l, int r, T lower, T upper) {\r\n    return range_freq(l, r, upper) - range_freq(l,\
    \ r, lower);\r\n  }\r\n\r\n  // max v[i] s.t. (l <= i < r) && (v[i] < upper)\r\
    \n  T prev_value(int l, int r, T upper) {\r\n    int cnt = range_freq(l, r, upper);\r\
    \n    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\r\n  }\r\n\r\n  //\
    \ min v[i] s.t. (l <= i < r) && (lower <= v[i])\r\n  T next_value(int l, int r,\
    \ T lower) {\r\n    int cnt = range_freq(l, r, lower);\r\n    return cnt == r\
    \ - l ? T(-1) : kth_smallest(l, r, cnt);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/data_structure/WaveletMatrix.hpp
- /library/data_structure/WaveletMatrix.hpp.html
title: data_structure/WaveletMatrix.hpp
---
