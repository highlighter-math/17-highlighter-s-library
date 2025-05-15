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
  bundledCode: "#line 2 \"data_structure/SegtreeBeats.hpp\"\n/*\r\nutility::lazysegtree_utility\
    \ seg(n):\r\n\u3059\u3079\u30660\u3067\u521D\u671F\u5316\u3055\u308C\u305Fn\u8981\
    \u7D20\u306Esegtree beats\u3092\u5BA3\u8A00\r\nseg.set(i, x):\r\nai = x\r\nseg.chmin(l,\
    \ r, x):\r\ni \u2208 [l, r) \u306B\u5BFE\u3057\u3066 ai = min(ai, x)\r\nseg.chmax(l,\
    \ r, x):\r\ni \u2208 [l, r) \u306B\u5BFE\u3057\u3066 ai = max(ai, x)\r\n\u307E\
    \u305F\u3001chmin\u3068chmax\u3092\u3059\u308B\u3053\u3068\u3067i \u2208 [l, r)\
    \ \u306B\u5BFE\u3057\u3066 ai = x \u3068\u3059\u308B\u3053\u3068\u3082\u53EF\u80FD\
    \r\nseg.add(l, r, x):\r\ni \u2208 [l, r) \u306B\u5BFE\u3057\u3066 ai += x\r\n\
    seg.get(i):\r\nai\u3092\u8FD4\u3059\r\nseg.get_max(l, r):\r\n[l, r)\u306E\u6700\
    \u5927\u5024\u3092\u8FD4\u3059\r\nseg.get_min(l, r):\r\n[l, r)\u306E\u6700\u5C0F\
    \u5024\u3092\u8FD4\u3059\r\nseg.get_sum(l, r):\r\n[l, r)\u306E\u7DCF\u548C\u3092\
    \u8FD4\u3059\r\nseg.max_right_max(l, x):\r\nl <= r\u3067\u3042\u3063\u3066 a[r]\
    \ >= x\u3067\u3042\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Er(\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070n)\u3092\u8FD4\u3059\r\nseg.max_right_min(l, x):\r\nl\
    \ <= r\u3067\u3042\u3063\u3066 a[r] <= x\u3067\u3042\u308B\u3088\u3046\u306A\u6700\
    \u5C0F\u306Er(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070n)\u3092\u8FD4\u3059\r\
    \nseg.max_right_sum_lq(l, x):\r\nl <= r\u3067\u3042\u3063\u3066 a[l] + a[l+1]\
    \ ... a[r] <= x\u3067\u3042\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Er(\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070n)\u3092\u8FD4\u3059(\u7D2F\u7A4D\u548C\u304C\u5358\
    \u8ABF\u3058\u3083\u306A\u3044\u3068\u58CA\u308C\u308B)\r\nseg.max_right_sum_gq(l,\
    \ x):\r\nl <= r\u3067\u3042\u3063\u3066 a[l] + a[l+1] ... a[r] >= x\u3067\u3042\
    \u308B\u3088\u3046\u306A\u6700\u5C0F\u306Er(\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070n)\u3092\u8FD4\u3059(\u7D2F\u7A4D\u548C\u304C\u5358\u8ABF\u3058\u3083\u306A\
    \u3044\u3068\u58CA\u308C\u308B)\r\nseg.min_left_max(r, x):\r\nl <= r\u3067\u3042\
    \u3063\u3066 a[l-1] >= x\u3067\u3042\u308B\u3088\u3046\u306A\u6700\u5927\u306E\
    l(\u5B58\u5728\u3057\u306A\u3051\u308C\u30700)\u3092\u8FD4\u3059\r\nseg.min_left_min(r,\
    \ x):\r\nl <= r\u3067\u3042\u3063\u3066 a[l-1] <= x\u3067\u3042\u308B\u3088\u3046\
    \u306A\u6700\u5927\u306El(\u5B58\u5728\u3057\u306A\u3051\u308C\u30700)\u3092\u8FD4\
    \u3059\r\nseg.min_left_sum_lq(r, x):\r\nl <= r\u3067\u3042\u3063\u3066 a[l-1]\
    \ + a[l] ... a[r-1] <= x\u3067\u3042\u308B\u3088\u3046\u306A\u6700\u5927\u306E\
    l(\u5B58\u5728\u3057\u306A\u3051\u308C\u30700)\u3092\u8FD4\u3059(\u7D2F\u7A4D\u548C\
    \u304C\u5358\u8ABF\u3058\u3083\u306A\u3044\u3068\u58CA\u308C\u308B)\r\nseg.min_left_sum_gq(r,\
    \ x):\r\nl <= r\u3067\u3042\u3063\u3066 a[l-1] + a[l] ... a[r-1] >= x\u3067\u3042\
    \u308B\u3088\u3046\u306A\u6700\u5927\u306El(\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u30700)\u3092\u8FD4\u3059(\u7D2F\u7A4D\u548C\u304C\u5358\u8ABF\u3058\u3083\u306A\
    \u3044\u3068\u58CA\u308C\u308B)\r\n*/\r\nnamespace utility{\r\n  const long long\
    \ BINF = 1LL << 61;\r\n  struct lazysegtree_utility{\r\n    const long long second_lowest(long\
    \ long a, long long a2, long long b, long long b2){\r\n      if(a == b) return\
    \ min(a2, b2);\r\n      if(a2 <= b) return a2;\r\n      if(b2 <= a) return b2;\r\
    \n      return max(a, b);\r\n    }\r\n    const long long second_highest(long\
    \ long a, long long a2, long long b, long long b2){\r\n      if(a == b) return\
    \ max(a2, b2);\r\n      if(a2 >= b) return a2;\r\n      if(b2 >= a) return b2;\r\
    \n      return min(a, b);\r\n    }\r\n    struct S{\r\n      long long lo, hi,\
    \ lo2, hi2, sum;\r\n      unsigned int sz, nlo, nhi;\r\n      bool fail;\r\n \
    \     S():lo(BINF), lo2(BINF), hi(-BINF), hi2(-BINF), sum(0), sz(0), nlo(0), nhi(0),\
    \ fail(false){}\r\n      S(long long x, unsigned int sz_ = 1):lo(x), lo2(BINF),\
    \ hi(x), hi2(-BINF), sum(x*sz_), sz(sz_), nlo(sz_), nhi(sz_), fail(false){}\r\n\
    \    };\r\n    S e(){return S();}\r\n    S op(S l, S r){\r\n      S ret;\r\n \
    \     ret.lo = min(l.lo, r.lo), ret.hi = max(l.hi, r.hi);\r\n      ret.lo2 = second_lowest(l.lo,\
    \ l.lo2, r.lo, r.lo2);\r\n      ret.hi2 = second_highest(l.hi, l.hi2, r.hi, r.hi2);\r\
    \n      ret.sum = l.sum + r.sum, ret.sz = l.sz + r.sz;\r\n      ret.nlo = l.nlo\
    \ * (l.lo <= r.lo) + r.nlo * (r.lo <= l.lo);\r\n      ret.nhi = l.nhi * (l.hi\
    \ >= r.hi) + r.nhi * (r.hi >= l.hi);\r\n      return ret;\r\n    }\r\n    struct\
    \ F{\r\n      long long lb, ub, bias;\r\n      F(long long lb_ = -BINF, long long\
    \ ub_ = BINF, long long bias_ = 0):lb(lb_), ub(ub_), bias(bias_){}\r\n      static\
    \ F chmin(long long x){\r\n        return F(-BINF, x, 0LL);\r\n      }\r\n   \
    \   static F chmax(long long x){\r\n        return F(x, BINF, 0LL);\r\n      }\r\
    \n      static F add(long long x){\r\n        return F(-BINF, BINF, x);\r\n  \
    \    }\r\n    };\r\n    F composition(F a, F b){\r\n      F ret;\r\n      ret.lb\
    \ = max(min(b.lb + b.bias, a.ub), a.lb) - b.bias;\r\n      ret.ub = min(max(b.ub\
    \ + b.bias, a.lb), a.ub) - b.bias;\r\n      ret.bias = a.bias + b.bias;\r\n  \
    \    return ret;\r\n    }\r\n    F id(){return F();}\r\n    S mapping(F f, S x){\r\
    \n      if(x.sz == 0) return e();\r\n      if(x.lo == x.hi || f.lb == f.ub ||\
    \ f.lb >= x.hi || f.ub <= x.lo){\r\n        return S(min(max(x.lo, f.lb), f.ub)\
    \ + f.bias, x.sz);\r\n      }\r\n      if(x.lo2 == x.hi){\r\n        x.lo = x.hi2\
    \ = max(x.lo, f.lb) + f.bias;\r\n        x.hi = x.lo2 = min(x.hi, f.ub) + f.bias;\r\
    \n        x.sum = x.lo * x.nlo + x.hi * x.nhi;\r\n        return x;\r\n      }\r\
    \n      if(f.lb < x.lo2 && f.ub > x.hi2){\r\n        long long nxt_lo = max(x.lo,\
    \ f.lb), nxt_hi = min(x.hi, f.ub);\r\n        x.sum += (nxt_lo - x.lo) * x.nlo\
    \ + (nxt_hi - x.hi) * x.nhi + f.bias * x.sz;\r\n        x.lo = nxt_lo + f.bias,\
    \ x.hi = nxt_hi + f.bias, x.lo2 += f.bias, x.hi2 += f.bias;\r\n        return\
    \ x;\r\n      }\r\n      x.fail = true;\r\n      return x;\r\n    }\r\n    lazysegtree_utility():lazysegtree_utility(0){}\r\
    \n    explicit lazysegtree_utility(int n):lazysegtree_utility(vector<S>(n, e())){};\r\
    \n    explicit lazysegtree_utility(const vector<S> &v):n((int)v.size()){\r\n \
    \     lg = 1;\r\n      while((1 << lg) < n) lg++;\r\n      size = 1 << lg;\r\n\
    \      dat.assign(2*size, e());\r\n      lazy.assign(2*size, id());\r\n      for(int\
    \ i = 0; i < n; i++) dat[i+size] = v[i];\r\n      for(int i = size - 1; i > 0;\
    \ i--) update(i);\r\n    };\r\n    void set(int p, S x){\r\n      assert(0 <=\
    \ p && p < n);\r\n      p += size;\r\n      for(int i = lg; i > 0; i--) push(p\
    \ >> i);\r\n      dat[p] = x;\r\n      for(int i = 1; i <= lg; i++) update(p >>\
    \ i);\r\n    }\r\n    S get(int p){\r\n      assert(0 <= p && p < n);\r\n    \
    \  p += size;\r\n      for(int i = lg; i > 0; i--) push(p >> i);\r\n      return\
    \ dat[p];\r\n    }\r\n    S prod(int l, int r){\r\n      assert(0 <= l && l <=\
    \ r && r <= n);\r\n      if(l == r) return e();\r\n      l += size;\r\n      r\
    \ += size;\r\n      for(int i = lg; i >= 1; i--){\r\n        if(((l >> i) << i)\
    \ != l) push(l >> i);\r\n        if(((r >> i) << i) != r) push((r - 1) >> i);\r\
    \n      }\r\n      S sml = e(), smr = e();\r\n      while(l < r){\r\n        if(l\
    \ & 1) sml = op(sml, dat[l++]);\r\n        if(r & 1) smr = op(dat[--r], smr);\r\
    \n        l >>= 1;\r\n        r >>= 1;\r\n      }\r\n      return op(sml, smr);\r\
    \n    }\r\n    long long get_sum(int l, int r){\r\n      assert(0 <= l && l <=\
    \ r && r <= n);\r\n      return prod(l, r).sum;\r\n    }\r\n    long long get_max(int\
    \ l, int r){\r\n      assert(0 <= l && l <= r && r <= n);\r\n      return prod(l,\
    \ r).hi;\r\n    }\r\n    long long get_min(int l, int r){\r\n      assert(0 <=\
    \ l && l <= r && r <= n);\r\n      return prod(l, r).lo;\r\n    }\r\n    void\
    \ apply(int p, F f){\r\n      assert(0 <= p && p < n);\r\n      p += size;\r\n\
    \      for(int i = lg; i > 0; i--) push(p >> i);\r\n      dat[p] = mapping(f,\
    \ dat[p]);\r\n      for(int i = 1; i <= lg; i++) update(p >> i);\r\n    }\r\n\
    \    void apply(int l, int r, F f){\r\n      assert(0 <= l && l <= r && r <= n);\r\
    \n      if(l == r) return;\r\n      l += size;\r\n      r += size;\r\n      for(int\
    \ i = lg; i > 0; i--){\r\n        if(((l >> i) << i) != l) push(l >> i);\r\n \
    \       if(((r >> i) << i) != r) push((r - 1) >> i);\r\n      }\r\n      int l2\
    \ = l, r2 = r;\r\n      while(l2 < r2){\r\n        if(l2 & 1) all_apply(l2++,\
    \ f);\r\n        if(r2 & 1) all_apply(--r2, f);\r\n        l2 >>= 1, r2 >>= 1;\r\
    \n      }\r\n      for(int i = 1; i <= lg; i++){\r\n        if(((l >> i) << i)\
    \ != l) update(l >> i);\r\n        if(((r >> i) << i) != r) update((r - 1) >>\
    \ i);\r\n      }\r\n    }\r\n    void chmin(int l, int r, long long x){\r\n  \
    \    assert(0 <= l && l <= r && r <= n);\r\n      apply(l, r, F::chmin(x));\r\n\
    \    }\r\n    void chmin(int p, long long x){\r\n      assert(0 <= p && p < n);\r\
    \n      apply(p, F::chmin(x));\r\n    }\r\n    void chmax(int l, int r, long long\
    \ x){\r\n      assert(0 <= l && l <= r && r <= n);\r\n      apply(l, r, F::chmax(x));\r\
    \n    }\r\n    void chmax(int p, long long x){\r\n      assert(0 <= p && p < n);\r\
    \n      apply(p, F::chmax(x));\r\n    }\r\n    void add(int l, int r, long long\
    \ x){\r\n      assert(0 <= l && l <= r && r <= n);\r\n      apply(l, r, F::add(x));\r\
    \n    }\r\n    void add(int p, long long x){\r\n      assert(0 <= p && p < n);\r\
    \n      apply(p, F::add(x));\r\n    }\r\n    template<bool (*g)(S)>\r\n    int\
    \ max_right(int l){\r\n      return max_right(l, [](S x){return g(x);});\r\n \
    \   }\r\n    template<class G>\r\n    int max_right(int l, G g){\r\n      assert(0\
    \ <= l && l <= n);\r\n      assert(g(e()));\r\n      if(l == n) return n;\r\n\
    \      l += size;\r\n      for(int i = lg; i >= 1; i--) push(l >> i);\r\n    \
    \  S sm = e();\r\n      do{\r\n        while((l & 1) == 0) l >>= 1;\r\n      \
    \    if(!g(op(sm, dat[l]))){\r\n            while(l < size){\r\n             \
    \ push(l);\r\n              l *= 2;\r\n              if(g(op(sm, dat[l]))){\r\n\
    \                sm = op(sm, dat[l]);\r\n                l++;\r\n            \
    \  }\r\n            }\r\n          return l - size;\r\n        }\r\n        sm\
    \ = op(sm, dat[l]);\r\n        l++;\r\n      }while((l & -l) != l);\r\n      return\
    \ n;\r\n    }\r\n    template <bool (*g)(S)>\r\n    int min_left(int r){\r\n \
    \     return min_left(r, [](S x){return g(x);});\r\n    }\r\n    template<class\
    \ G>\r\n    int min_left(int r, G g){\r\n      assert(0 <= r && r <= n);\r\n \
    \     assert(g(e()));\r\n      if(r == 0) return 0;\r\n      r += size;\r\n  \
    \    for(int i = lg; i >= 1; i--) push((r - 1) >> i);\r\n      S sm = e();\r\n\
    \      do{\r\n        r--;\r\n        while(r > 1 && (r % 2)) r >>= 1;\r\n   \
    \     if(!g(op(dat[r], sm))){\r\n            while(r < size){\r\n            \
    \  push(r);\r\n              r *= 2;\r\n              r++;\r\n              if(g(op(dat[r],\
    \ sm))){\r\n                sm = op(dat[r], sm);\r\n                r--;\r\n \
    \             }\r\n            }\r\n          return r + 1 - size;\r\n       \
    \ }\r\n        sm = op(dat[r], sm);\r\n      }while((r & -r) != r);\r\n      return\
    \ 0;\r\n    }\r\n    int max_right_max(int l, long long target){\r\n      return\
    \ max_right(l, [&](S x){return target > x.hi;});\r\n    }\r\n    int max_right_min(int\
    \ l, long long target){\r\n      return max_right(l, [&](S x){return target <\
    \ x.lo;});\r\n    }\r\n    int max_right_sum_lq(int l, long long target){\r\n\
    \      return max_right(l, [&](S x){return target < x.sum;});\r\n    }\r\n   \
    \ int max_right_sum_gq(int l, long long target){\r\n      return max_right(l,\
    \ [&](S x){return target > x.sum;});\r\n    }\r\n    int min_left_max(int r, long\
    \ long target){\r\n      return min_left(r, [&](S x){return target > x.hi;});\r\
    \n    }\r\n    int min_left_min(int r, long long target){\r\n      return min_left(r,\
    \ [&](S x){return target < x.lo;});\r\n    }\r\n    int min_left_sum_lq(int r,\
    \ long long target){\r\n      return min_left(r, [&](S x){return target < x.sum;});\r\
    \n    }\r\n    int min_left_sum_gq(int r, long long target){\r\n      return min_left(r,\
    \ [&](S x){return target > x.sum;});\r\n    }\r\n    private:\r\n    void update(int\
    \ k){dat[k] = op(dat[2 * k], dat[2 * k + 1]);}\r\n    void all_apply(int k, F\
    \ f){\r\n      dat[k] = mapping(f, dat[k]);\r\n      if(k < size){\r\n       \
    \ lazy[k] = composition(f, lazy[k]);\r\n        if(dat[k].fail) push(k), update(k);\r\
    \n      }\r\n    }\r\n    void push(int k) {\r\n      all_apply(2 * k, lazy[k]);\r\
    \n      all_apply(2 * k + 1, lazy[k]);\r\n      lazy[k] = id();\r\n    }\r\n \
    \   int n, size, lg;\r\n    vector<S> dat;\r\n    vector<F> lazy;\r\n  };\r\n\
    };\n"
  code: "#pragma once\r\n/*\r\nutility::lazysegtree_utility seg(n):\r\n\u3059\u3079\
    \u30660\u3067\u521D\u671F\u5316\u3055\u308C\u305Fn\u8981\u7D20\u306Esegtree beats\u3092\
    \u5BA3\u8A00\r\nseg.set(i, x):\r\nai = x\r\nseg.chmin(l, r, x):\r\ni \u2208 [l,\
    \ r) \u306B\u5BFE\u3057\u3066 ai = min(ai, x)\r\nseg.chmax(l, r, x):\r\ni \u2208\
    \ [l, r) \u306B\u5BFE\u3057\u3066 ai = max(ai, x)\r\n\u307E\u305F\u3001chmin\u3068\
    chmax\u3092\u3059\u308B\u3053\u3068\u3067i \u2208 [l, r) \u306B\u5BFE\u3057\u3066\
    \ ai = x \u3068\u3059\u308B\u3053\u3068\u3082\u53EF\u80FD\r\nseg.add(l, r, x):\r\
    \ni \u2208 [l, r) \u306B\u5BFE\u3057\u3066 ai += x\r\nseg.get(i):\r\nai\u3092\u8FD4\
    \u3059\r\nseg.get_max(l, r):\r\n[l, r)\u306E\u6700\u5927\u5024\u3092\u8FD4\u3059\
    \r\nseg.get_min(l, r):\r\n[l, r)\u306E\u6700\u5C0F\u5024\u3092\u8FD4\u3059\r\n\
    seg.get_sum(l, r):\r\n[l, r)\u306E\u7DCF\u548C\u3092\u8FD4\u3059\r\nseg.max_right_max(l,\
    \ x):\r\nl <= r\u3067\u3042\u3063\u3066 a[r] >= x\u3067\u3042\u308B\u3088\u3046\
    \u306A\u6700\u5C0F\u306Er(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070n)\u3092\u8FD4\
    \u3059\r\nseg.max_right_min(l, x):\r\nl <= r\u3067\u3042\u3063\u3066 a[r] <= x\u3067\
    \u3042\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Er(\u5B58\u5728\u3057\u306A\u3051\
    \u308C\u3070n)\u3092\u8FD4\u3059\r\nseg.max_right_sum_lq(l, x):\r\nl <= r\u3067\
    \u3042\u3063\u3066 a[l] + a[l+1] ... a[r] <= x\u3067\u3042\u308B\u3088\u3046\u306A\
    \u6700\u5C0F\u306Er(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070n)\u3092\u8FD4\u3059\
    (\u7D2F\u7A4D\u548C\u304C\u5358\u8ABF\u3058\u3083\u306A\u3044\u3068\u58CA\u308C\
    \u308B)\r\nseg.max_right_sum_gq(l, x):\r\nl <= r\u3067\u3042\u3063\u3066 a[l]\
    \ + a[l+1] ... a[r] >= x\u3067\u3042\u308B\u3088\u3046\u306A\u6700\u5C0F\u306E\
    r(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070n)\u3092\u8FD4\u3059(\u7D2F\u7A4D\u548C\
    \u304C\u5358\u8ABF\u3058\u3083\u306A\u3044\u3068\u58CA\u308C\u308B)\r\nseg.min_left_max(r,\
    \ x):\r\nl <= r\u3067\u3042\u3063\u3066 a[l-1] >= x\u3067\u3042\u308B\u3088\u3046\
    \u306A\u6700\u5927\u306El(\u5B58\u5728\u3057\u306A\u3051\u308C\u30700)\u3092\u8FD4\
    \u3059\r\nseg.min_left_min(r, x):\r\nl <= r\u3067\u3042\u3063\u3066 a[l-1] <=\
    \ x\u3067\u3042\u308B\u3088\u3046\u306A\u6700\u5927\u306El(\u5B58\u5728\u3057\u306A\
    \u3051\u308C\u30700)\u3092\u8FD4\u3059\r\nseg.min_left_sum_lq(r, x):\r\nl <= r\u3067\
    \u3042\u3063\u3066 a[l-1] + a[l] ... a[r-1] <= x\u3067\u3042\u308B\u3088\u3046\
    \u306A\u6700\u5927\u306El(\u5B58\u5728\u3057\u306A\u3051\u308C\u30700)\u3092\u8FD4\
    \u3059(\u7D2F\u7A4D\u548C\u304C\u5358\u8ABF\u3058\u3083\u306A\u3044\u3068\u58CA\
    \u308C\u308B)\r\nseg.min_left_sum_gq(r, x):\r\nl <= r\u3067\u3042\u3063\u3066\
    \ a[l-1] + a[l] ... a[r-1] >= x\u3067\u3042\u308B\u3088\u3046\u306A\u6700\u5927\
    \u306El(\u5B58\u5728\u3057\u306A\u3051\u308C\u30700)\u3092\u8FD4\u3059(\u7D2F\u7A4D\
    \u548C\u304C\u5358\u8ABF\u3058\u3083\u306A\u3044\u3068\u58CA\u308C\u308B)\r\n\
    */\r\nnamespace utility{\r\n  const long long BINF = 1LL << 61;\r\n  struct lazysegtree_utility{\r\
    \n    const long long second_lowest(long long a, long long a2, long long b, long\
    \ long b2){\r\n      if(a == b) return min(a2, b2);\r\n      if(a2 <= b) return\
    \ a2;\r\n      if(b2 <= a) return b2;\r\n      return max(a, b);\r\n    }\r\n\
    \    const long long second_highest(long long a, long long a2, long long b, long\
    \ long b2){\r\n      if(a == b) return max(a2, b2);\r\n      if(a2 >= b) return\
    \ a2;\r\n      if(b2 >= a) return b2;\r\n      return min(a, b);\r\n    }\r\n\
    \    struct S{\r\n      long long lo, hi, lo2, hi2, sum;\r\n      unsigned int\
    \ sz, nlo, nhi;\r\n      bool fail;\r\n      S():lo(BINF), lo2(BINF), hi(-BINF),\
    \ hi2(-BINF), sum(0), sz(0), nlo(0), nhi(0), fail(false){}\r\n      S(long long\
    \ x, unsigned int sz_ = 1):lo(x), lo2(BINF), hi(x), hi2(-BINF), sum(x*sz_), sz(sz_),\
    \ nlo(sz_), nhi(sz_), fail(false){}\r\n    };\r\n    S e(){return S();}\r\n  \
    \  S op(S l, S r){\r\n      S ret;\r\n      ret.lo = min(l.lo, r.lo), ret.hi =\
    \ max(l.hi, r.hi);\r\n      ret.lo2 = second_lowest(l.lo, l.lo2, r.lo, r.lo2);\r\
    \n      ret.hi2 = second_highest(l.hi, l.hi2, r.hi, r.hi2);\r\n      ret.sum =\
    \ l.sum + r.sum, ret.sz = l.sz + r.sz;\r\n      ret.nlo = l.nlo * (l.lo <= r.lo)\
    \ + r.nlo * (r.lo <= l.lo);\r\n      ret.nhi = l.nhi * (l.hi >= r.hi) + r.nhi\
    \ * (r.hi >= l.hi);\r\n      return ret;\r\n    }\r\n    struct F{\r\n      long\
    \ long lb, ub, bias;\r\n      F(long long lb_ = -BINF, long long ub_ = BINF, long\
    \ long bias_ = 0):lb(lb_), ub(ub_), bias(bias_){}\r\n      static F chmin(long\
    \ long x){\r\n        return F(-BINF, x, 0LL);\r\n      }\r\n      static F chmax(long\
    \ long x){\r\n        return F(x, BINF, 0LL);\r\n      }\r\n      static F add(long\
    \ long x){\r\n        return F(-BINF, BINF, x);\r\n      }\r\n    };\r\n    F\
    \ composition(F a, F b){\r\n      F ret;\r\n      ret.lb = max(min(b.lb + b.bias,\
    \ a.ub), a.lb) - b.bias;\r\n      ret.ub = min(max(b.ub + b.bias, a.lb), a.ub)\
    \ - b.bias;\r\n      ret.bias = a.bias + b.bias;\r\n      return ret;\r\n    }\r\
    \n    F id(){return F();}\r\n    S mapping(F f, S x){\r\n      if(x.sz == 0) return\
    \ e();\r\n      if(x.lo == x.hi || f.lb == f.ub || f.lb >= x.hi || f.ub <= x.lo){\r\
    \n        return S(min(max(x.lo, f.lb), f.ub) + f.bias, x.sz);\r\n      }\r\n\
    \      if(x.lo2 == x.hi){\r\n        x.lo = x.hi2 = max(x.lo, f.lb) + f.bias;\r\
    \n        x.hi = x.lo2 = min(x.hi, f.ub) + f.bias;\r\n        x.sum = x.lo * x.nlo\
    \ + x.hi * x.nhi;\r\n        return x;\r\n      }\r\n      if(f.lb < x.lo2 &&\
    \ f.ub > x.hi2){\r\n        long long nxt_lo = max(x.lo, f.lb), nxt_hi = min(x.hi,\
    \ f.ub);\r\n        x.sum += (nxt_lo - x.lo) * x.nlo + (nxt_hi - x.hi) * x.nhi\
    \ + f.bias * x.sz;\r\n        x.lo = nxt_lo + f.bias, x.hi = nxt_hi + f.bias,\
    \ x.lo2 += f.bias, x.hi2 += f.bias;\r\n        return x;\r\n      }\r\n      x.fail\
    \ = true;\r\n      return x;\r\n    }\r\n    lazysegtree_utility():lazysegtree_utility(0){}\r\
    \n    explicit lazysegtree_utility(int n):lazysegtree_utility(vector<S>(n, e())){};\r\
    \n    explicit lazysegtree_utility(const vector<S> &v):n((int)v.size()){\r\n \
    \     lg = 1;\r\n      while((1 << lg) < n) lg++;\r\n      size = 1 << lg;\r\n\
    \      dat.assign(2*size, e());\r\n      lazy.assign(2*size, id());\r\n      for(int\
    \ i = 0; i < n; i++) dat[i+size] = v[i];\r\n      for(int i = size - 1; i > 0;\
    \ i--) update(i);\r\n    };\r\n    void set(int p, S x){\r\n      assert(0 <=\
    \ p && p < n);\r\n      p += size;\r\n      for(int i = lg; i > 0; i--) push(p\
    \ >> i);\r\n      dat[p] = x;\r\n      for(int i = 1; i <= lg; i++) update(p >>\
    \ i);\r\n    }\r\n    S get(int p){\r\n      assert(0 <= p && p < n);\r\n    \
    \  p += size;\r\n      for(int i = lg; i > 0; i--) push(p >> i);\r\n      return\
    \ dat[p];\r\n    }\r\n    S prod(int l, int r){\r\n      assert(0 <= l && l <=\
    \ r && r <= n);\r\n      if(l == r) return e();\r\n      l += size;\r\n      r\
    \ += size;\r\n      for(int i = lg; i >= 1; i--){\r\n        if(((l >> i) << i)\
    \ != l) push(l >> i);\r\n        if(((r >> i) << i) != r) push((r - 1) >> i);\r\
    \n      }\r\n      S sml = e(), smr = e();\r\n      while(l < r){\r\n        if(l\
    \ & 1) sml = op(sml, dat[l++]);\r\n        if(r & 1) smr = op(dat[--r], smr);\r\
    \n        l >>= 1;\r\n        r >>= 1;\r\n      }\r\n      return op(sml, smr);\r\
    \n    }\r\n    long long get_sum(int l, int r){\r\n      assert(0 <= l && l <=\
    \ r && r <= n);\r\n      return prod(l, r).sum;\r\n    }\r\n    long long get_max(int\
    \ l, int r){\r\n      assert(0 <= l && l <= r && r <= n);\r\n      return prod(l,\
    \ r).hi;\r\n    }\r\n    long long get_min(int l, int r){\r\n      assert(0 <=\
    \ l && l <= r && r <= n);\r\n      return prod(l, r).lo;\r\n    }\r\n    void\
    \ apply(int p, F f){\r\n      assert(0 <= p && p < n);\r\n      p += size;\r\n\
    \      for(int i = lg; i > 0; i--) push(p >> i);\r\n      dat[p] = mapping(f,\
    \ dat[p]);\r\n      for(int i = 1; i <= lg; i++) update(p >> i);\r\n    }\r\n\
    \    void apply(int l, int r, F f){\r\n      assert(0 <= l && l <= r && r <= n);\r\
    \n      if(l == r) return;\r\n      l += size;\r\n      r += size;\r\n      for(int\
    \ i = lg; i > 0; i--){\r\n        if(((l >> i) << i) != l) push(l >> i);\r\n \
    \       if(((r >> i) << i) != r) push((r - 1) >> i);\r\n      }\r\n      int l2\
    \ = l, r2 = r;\r\n      while(l2 < r2){\r\n        if(l2 & 1) all_apply(l2++,\
    \ f);\r\n        if(r2 & 1) all_apply(--r2, f);\r\n        l2 >>= 1, r2 >>= 1;\r\
    \n      }\r\n      for(int i = 1; i <= lg; i++){\r\n        if(((l >> i) << i)\
    \ != l) update(l >> i);\r\n        if(((r >> i) << i) != r) update((r - 1) >>\
    \ i);\r\n      }\r\n    }\r\n    void chmin(int l, int r, long long x){\r\n  \
    \    assert(0 <= l && l <= r && r <= n);\r\n      apply(l, r, F::chmin(x));\r\n\
    \    }\r\n    void chmin(int p, long long x){\r\n      assert(0 <= p && p < n);\r\
    \n      apply(p, F::chmin(x));\r\n    }\r\n    void chmax(int l, int r, long long\
    \ x){\r\n      assert(0 <= l && l <= r && r <= n);\r\n      apply(l, r, F::chmax(x));\r\
    \n    }\r\n    void chmax(int p, long long x){\r\n      assert(0 <= p && p < n);\r\
    \n      apply(p, F::chmax(x));\r\n    }\r\n    void add(int l, int r, long long\
    \ x){\r\n      assert(0 <= l && l <= r && r <= n);\r\n      apply(l, r, F::add(x));\r\
    \n    }\r\n    void add(int p, long long x){\r\n      assert(0 <= p && p < n);\r\
    \n      apply(p, F::add(x));\r\n    }\r\n    template<bool (*g)(S)>\r\n    int\
    \ max_right(int l){\r\n      return max_right(l, [](S x){return g(x);});\r\n \
    \   }\r\n    template<class G>\r\n    int max_right(int l, G g){\r\n      assert(0\
    \ <= l && l <= n);\r\n      assert(g(e()));\r\n      if(l == n) return n;\r\n\
    \      l += size;\r\n      for(int i = lg; i >= 1; i--) push(l >> i);\r\n    \
    \  S sm = e();\r\n      do{\r\n        while((l & 1) == 0) l >>= 1;\r\n      \
    \    if(!g(op(sm, dat[l]))){\r\n            while(l < size){\r\n             \
    \ push(l);\r\n              l *= 2;\r\n              if(g(op(sm, dat[l]))){\r\n\
    \                sm = op(sm, dat[l]);\r\n                l++;\r\n            \
    \  }\r\n            }\r\n          return l - size;\r\n        }\r\n        sm\
    \ = op(sm, dat[l]);\r\n        l++;\r\n      }while((l & -l) != l);\r\n      return\
    \ n;\r\n    }\r\n    template <bool (*g)(S)>\r\n    int min_left(int r){\r\n \
    \     return min_left(r, [](S x){return g(x);});\r\n    }\r\n    template<class\
    \ G>\r\n    int min_left(int r, G g){\r\n      assert(0 <= r && r <= n);\r\n \
    \     assert(g(e()));\r\n      if(r == 0) return 0;\r\n      r += size;\r\n  \
    \    for(int i = lg; i >= 1; i--) push((r - 1) >> i);\r\n      S sm = e();\r\n\
    \      do{\r\n        r--;\r\n        while(r > 1 && (r % 2)) r >>= 1;\r\n   \
    \     if(!g(op(dat[r], sm))){\r\n            while(r < size){\r\n            \
    \  push(r);\r\n              r *= 2;\r\n              r++;\r\n              if(g(op(dat[r],\
    \ sm))){\r\n                sm = op(dat[r], sm);\r\n                r--;\r\n \
    \             }\r\n            }\r\n          return r + 1 - size;\r\n       \
    \ }\r\n        sm = op(dat[r], sm);\r\n      }while((r & -r) != r);\r\n      return\
    \ 0;\r\n    }\r\n    int max_right_max(int l, long long target){\r\n      return\
    \ max_right(l, [&](S x){return target > x.hi;});\r\n    }\r\n    int max_right_min(int\
    \ l, long long target){\r\n      return max_right(l, [&](S x){return target <\
    \ x.lo;});\r\n    }\r\n    int max_right_sum_lq(int l, long long target){\r\n\
    \      return max_right(l, [&](S x){return target < x.sum;});\r\n    }\r\n   \
    \ int max_right_sum_gq(int l, long long target){\r\n      return max_right(l,\
    \ [&](S x){return target > x.sum;});\r\n    }\r\n    int min_left_max(int r, long\
    \ long target){\r\n      return min_left(r, [&](S x){return target > x.hi;});\r\
    \n    }\r\n    int min_left_min(int r, long long target){\r\n      return min_left(r,\
    \ [&](S x){return target < x.lo;});\r\n    }\r\n    int min_left_sum_lq(int r,\
    \ long long target){\r\n      return min_left(r, [&](S x){return target < x.sum;});\r\
    \n    }\r\n    int min_left_sum_gq(int r, long long target){\r\n      return min_left(r,\
    \ [&](S x){return target > x.sum;});\r\n    }\r\n    private:\r\n    void update(int\
    \ k){dat[k] = op(dat[2 * k], dat[2 * k + 1]);}\r\n    void all_apply(int k, F\
    \ f){\r\n      dat[k] = mapping(f, dat[k]);\r\n      if(k < size){\r\n       \
    \ lazy[k] = composition(f, lazy[k]);\r\n        if(dat[k].fail) push(k), update(k);\r\
    \n      }\r\n    }\r\n    void push(int k) {\r\n      all_apply(2 * k, lazy[k]);\r\
    \n      all_apply(2 * k + 1, lazy[k]);\r\n      lazy[k] = id();\r\n    }\r\n \
    \   int n, size, lg;\r\n    vector<S> dat;\r\n    vector<F> lazy;\r\n  };\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/SegtreeBeats.hpp
  requiredBy: []
  timestamp: '2025-05-16 01:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/SegtreeBeats.hpp
layout: document
redirect_from:
- /library/data_structure/SegtreeBeats.hpp
- /library/data_structure/SegtreeBeats.hpp.html
title: data_structure/SegtreeBeats.hpp
---
