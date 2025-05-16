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
  bundledCode: "#line 1 \"data_structure/scc.hpp\"\n\n\n\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <vector>\r\n\r\n#ifndef ATCODER_INTERNAL_SCC_HPP\r\
    \n#define ATCODER_INTERNAL_SCC_HPP 1\r\n\r\n#line 12 \"data_structure/scc.hpp\"\
    \n#include <utility>\r\n#line 14 \"data_structure/scc.hpp\"\n\r\n#ifndef ATCODER_INTERNAL_CSR_HPP\r\
    \n#define ATCODER_INTERNAL_CSR_HPP 1\r\n\r\n#line 19 \"data_structure/scc.hpp\"\
    \n#include <utility>\r\n#line 21 \"data_structure/scc.hpp\"\n\r\nnamespace atcoder\
    \ {\r\nnamespace internal {\r\n\r\ntemplate <class E> struct csr {\r\n    std::vector<int>\
    \ start;\r\n    std::vector<E> elist;\r\n    explicit csr(int n, const std::vector<std::pair<int,\
    \ E>>& edges)\r\n        : start(n + 1), elist(edges.size()) {\r\n        for\
    \ (auto e : edges) {\r\n            start[e.first + 1]++;\r\n        }\r\n   \
    \     for (int i = 1; i <= n; i++) {\r\n            start[i] += start[i - 1];\r\
    \n        }\r\n        auto counter = start;\r\n        for (auto e : edges) {\r\
    \n            elist[counter[e.first]++] = e.second;\r\n        }\r\n    }\r\n\
    };\r\n\r\n}  // namespace internal\r\n\r\n}  // namespace atcoder\r\n\r\n#endif\
    \  // ATCODER_INTERNAL_CSR_HPP\r\n\r\nnamespace atcoder {\r\nnamespace internal\
    \ {\r\n\r\n// Reference:\r\n// R. Tarjan,\r\n// Depth-First Search and Linear\
    \ Graph Algorithms\r\nstruct scc_graph {\r\n  public:\r\n    explicit scc_graph(int\
    \ n) : _n(n) {}\r\n\r\n    int num_vertices() { return _n; }\r\n\r\n    void add_edge(int\
    \ from, int to) { edges.push_back({from, {to}}); }\r\n\r\n    // @return pair\
    \ of (# of scc, scc id)\r\n    std::pair<int, std::vector<int>> scc_ids() {\r\n\
    \        auto g = csr<edge>(_n, edges);\r\n        int now_ord = 0, group_num\
    \ = 0;\r\n        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);\r\n\
    \        visited.reserve(_n);\r\n        auto dfs = [&](auto self, int v) -> void\
    \ {\r\n            low[v] = ord[v] = now_ord++;\r\n            visited.push_back(v);\r\
    \n            for (int i = g.start[v]; i < g.start[v + 1]; i++) {\r\n        \
    \        auto to = g.elist[i].to;\r\n                if (ord[to] == -1) {\r\n\
    \                    self(self, to);\r\n                    low[v] = std::min(low[v],\
    \ low[to]);\r\n                } else {\r\n                    low[v] = std::min(low[v],\
    \ ord[to]);\r\n                }\r\n            }\r\n            if (low[v] ==\
    \ ord[v]) {\r\n                while (true) {\r\n                    int u = visited.back();\r\
    \n                    visited.pop_back();\r\n                    ord[u] = _n;\r\
    \n                    ids[u] = group_num;\r\n                    if (u == v) break;\r\
    \n                }\r\n                group_num++;\r\n            }\r\n     \
    \   };\r\n        for (int i = 0; i < _n; i++) {\r\n            if (ord[i] ==\
    \ -1) dfs(dfs, i);\r\n        }\r\n        for (auto& x : ids) {\r\n         \
    \   x = group_num - 1 - x;\r\n        }\r\n        return {group_num, ids};\r\n\
    \    }\r\n\r\n    std::vector<std::vector<int>> scc() {\r\n        auto ids =\
    \ scc_ids();\r\n        int group_num = ids.first;\r\n        std::vector<int>\
    \ counts(group_num);\r\n        for (auto x : ids.second) counts[x]++;\r\n   \
    \     std::vector<std::vector<int>> groups(ids.first);\r\n        for (int i =\
    \ 0; i < group_num; i++) {\r\n            groups[i].reserve(counts[i]);\r\n  \
    \      }\r\n        for (int i = 0; i < _n; i++) {\r\n            groups[ids.second[i]].push_back(i);\r\
    \n        }\r\n        return groups;\r\n    }\r\n\r\n  private:\r\n    int _n;\r\
    \n    struct edge {\r\n        int to;\r\n    };\r\n    std::vector<std::pair<int,\
    \ edge>> edges;\r\n};\r\n\r\n}  // namespace internal\r\n\r\n}  // namespace atcoder\r\
    \n\r\n#endif  // ATCODER_INTERNAL_SCC_HPP\r\n\r\nnamespace atcoder {\r\n\r\nstruct\
    \ scc_graph {\r\n  public:\r\n    scc_graph() : internal(0) {}\r\n    explicit\
    \ scc_graph(int n) : internal(n) {}\r\n\r\n    void add_edge(int from, int to)\
    \ {\r\n        int n = internal.num_vertices();\r\n        assert(0 <= from &&\
    \ from < n);\r\n        assert(0 <= to && to < n);\r\n        internal.add_edge(from,\
    \ to);\r\n    }\r\n\r\n    std::vector<std::vector<int>> scc() { return internal.scc();\
    \ }\r\n\r\n  private:\r\n    internal::scc_graph internal;\r\n};\r\n\r\n}  //\
    \ namespace atcoder\r\n\r\n\n"
  code: "#ifndef ATCODER_SCC_HPP\r\n#define ATCODER_SCC_HPP 1\r\n\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <vector>\r\n\r\n#ifndef ATCODER_INTERNAL_SCC_HPP\r\
    \n#define ATCODER_INTERNAL_SCC_HPP 1\r\n\r\n#include <algorithm>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\n#ifndef ATCODER_INTERNAL_CSR_HPP\r\n#define ATCODER_INTERNAL_CSR_HPP\
    \ 1\r\n\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\n\
    \r\nnamespace atcoder {\r\nnamespace internal {\r\n\r\ntemplate <class E> struct\
    \ csr {\r\n    std::vector<int> start;\r\n    std::vector<E> elist;\r\n    explicit\
    \ csr(int n, const std::vector<std::pair<int, E>>& edges)\r\n        : start(n\
    \ + 1), elist(edges.size()) {\r\n        for (auto e : edges) {\r\n          \
    \  start[e.first + 1]++;\r\n        }\r\n        for (int i = 1; i <= n; i++)\
    \ {\r\n            start[i] += start[i - 1];\r\n        }\r\n        auto counter\
    \ = start;\r\n        for (auto e : edges) {\r\n            elist[counter[e.first]++]\
    \ = e.second;\r\n        }\r\n    }\r\n};\r\n\r\n}  // namespace internal\r\n\r\
    \n}  // namespace atcoder\r\n\r\n#endif  // ATCODER_INTERNAL_CSR_HPP\r\n\r\nnamespace\
    \ atcoder {\r\nnamespace internal {\r\n\r\n// Reference:\r\n// R. Tarjan,\r\n\
    // Depth-First Search and Linear Graph Algorithms\r\nstruct scc_graph {\r\n  public:\r\
    \n    explicit scc_graph(int n) : _n(n) {}\r\n\r\n    int num_vertices() { return\
    \ _n; }\r\n\r\n    void add_edge(int from, int to) { edges.push_back({from, {to}});\
    \ }\r\n\r\n    // @return pair of (# of scc, scc id)\r\n    std::pair<int, std::vector<int>>\
    \ scc_ids() {\r\n        auto g = csr<edge>(_n, edges);\r\n        int now_ord\
    \ = 0, group_num = 0;\r\n        std::vector<int> visited, low(_n), ord(_n, -1),\
    \ ids(_n);\r\n        visited.reserve(_n);\r\n        auto dfs = [&](auto self,\
    \ int v) -> void {\r\n            low[v] = ord[v] = now_ord++;\r\n           \
    \ visited.push_back(v);\r\n            for (int i = g.start[v]; i < g.start[v\
    \ + 1]; i++) {\r\n                auto to = g.elist[i].to;\r\n               \
    \ if (ord[to] == -1) {\r\n                    self(self, to);\r\n            \
    \        low[v] = std::min(low[v], low[to]);\r\n                } else {\r\n \
    \                   low[v] = std::min(low[v], ord[to]);\r\n                }\r\
    \n            }\r\n            if (low[v] == ord[v]) {\r\n                while\
    \ (true) {\r\n                    int u = visited.back();\r\n                \
    \    visited.pop_back();\r\n                    ord[u] = _n;\r\n             \
    \       ids[u] = group_num;\r\n                    if (u == v) break;\r\n    \
    \            }\r\n                group_num++;\r\n            }\r\n        };\r\
    \n        for (int i = 0; i < _n; i++) {\r\n            if (ord[i] == -1) dfs(dfs,\
    \ i);\r\n        }\r\n        for (auto& x : ids) {\r\n            x = group_num\
    \ - 1 - x;\r\n        }\r\n        return {group_num, ids};\r\n    }\r\n\r\n \
    \   std::vector<std::vector<int>> scc() {\r\n        auto ids = scc_ids();\r\n\
    \        int group_num = ids.first;\r\n        std::vector<int> counts(group_num);\r\
    \n        for (auto x : ids.second) counts[x]++;\r\n        std::vector<std::vector<int>>\
    \ groups(ids.first);\r\n        for (int i = 0; i < group_num; i++) {\r\n    \
    \        groups[i].reserve(counts[i]);\r\n        }\r\n        for (int i = 0;\
    \ i < _n; i++) {\r\n            groups[ids.second[i]].push_back(i);\r\n      \
    \  }\r\n        return groups;\r\n    }\r\n\r\n  private:\r\n    int _n;\r\n \
    \   struct edge {\r\n        int to;\r\n    };\r\n    std::vector<std::pair<int,\
    \ edge>> edges;\r\n};\r\n\r\n}  // namespace internal\r\n\r\n}  // namespace atcoder\r\
    \n\r\n#endif  // ATCODER_INTERNAL_SCC_HPP\r\n\r\nnamespace atcoder {\r\n\r\nstruct\
    \ scc_graph {\r\n  public:\r\n    scc_graph() : internal(0) {}\r\n    explicit\
    \ scc_graph(int n) : internal(n) {}\r\n\r\n    void add_edge(int from, int to)\
    \ {\r\n        int n = internal.num_vertices();\r\n        assert(0 <= from &&\
    \ from < n);\r\n        assert(0 <= to && to < n);\r\n        internal.add_edge(from,\
    \ to);\r\n    }\r\n\r\n    std::vector<std::vector<int>> scc() { return internal.scc();\
    \ }\r\n\r\n  private:\r\n    internal::scc_graph internal;\r\n};\r\n\r\n}  //\
    \ namespace atcoder\r\n\r\n#endif  // ATCODER_SCC_HPP"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/scc.hpp
  requiredBy: []
  timestamp: '2025-05-16 23:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/scc.hpp
layout: document
redirect_from:
- /library/data_structure/scc.hpp
- /library/data_structure/scc.hpp.html
title: data_structure/scc.hpp
---
