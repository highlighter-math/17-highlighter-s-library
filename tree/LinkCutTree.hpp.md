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
  bundledCode: "#line 2 \"tree/LinkCutTree.hpp\"\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()>\r\nstruct LinkCutTree {\r\n    struct Node {\r\n        int id;\r\n\
    \        Node *l = nullptr, *r = nullptr, *p = nullptr;\r\n        bool rev =\
    \ false;\r\n        S val, sum_ltr, sum_rtl;\r\n        Node(int _id, const S&\
    \ v = e()) : id(_id), val(v), sum_ltr(v), sum_rtl(v) {}\r\n        bool isRoot()\
    \ const { return !p || (p->l != this && p->r != this); }\r\n    };\r\n\r\n   \
    \ vector<Node> pool;\r\n    vector<Node*> nodes;\r\n    vector<Node*> stk;\r\n\
    \r\n    LinkCutTree(int n) {\r\n        pool.reserve(n);\r\n        nodes.reserve(n);\r\
    \n        stk.reserve(n);\r\n        for (int i = 0; i < n; i++) {\r\n       \
    \     pool.emplace_back(i);\r\n            nodes.push_back(&pool.back());\r\n\
    \        }\r\n    }\r\n\r\n    inline void apply_rev(Node* t) {\r\n        swap(t->l,\
    \ t->r);\r\n        swap(t->sum_ltr, t->sum_rtl);\r\n        t->rev ^= 1;\r\n\
    \    }\r\n\r\n    inline void push(Node* t) {\r\n        if (t && t->rev) {\r\n\
    \            if (t->l) apply_rev(t->l);\r\n            if (t->r) apply_rev(t->r);\r\
    \n            t->rev = false;\r\n        }\r\n    }\r\n\r\n    inline void pull(Node*\
    \ t) {\r\n        S a = e(), b = e();\r\n        if (t->l) a = t->l->sum_ltr;\r\
    \n        a = op(a, t->val);\r\n        if (t->r) t->sum_ltr = op(a, t->r->sum_ltr);\r\
    \n        else t->sum_ltr = a;\r\n\r\n        if (t->r) b = t->r->sum_rtl;\r\n\
    \        b = op(b, t->val);\r\n        if (t->l) t->sum_rtl = op(b, t->l->sum_rtl);\r\
    \n        else t->sum_rtl = b;\r\n    }\r\n\r\n    void rotate(Node* t) {\r\n\
    \        Node* p = t->p;\r\n        Node* g = p->p;\r\n        push(g); push(p);\
    \ push(t);\r\n        bool isR = (t == p->r);\r\n        Node* b = isR ? t->l\
    \ : t->r;\r\n        if (!p->isRoot()) {\r\n            if (p == g->l) g->l =\
    \ t;\r\n            else g->r = t;\r\n        }\r\n        t->p = g;\r\n     \
    \   if (isR) { t->l = p; p->r = b; }\r\n        else     { t->r = p; p->l = b;\
    \ }\r\n        if (b) b->p = p;\r\n        p->p = t;\r\n        pull(p);\r\n \
    \       pull(t);\r\n    }\r\n\r\n    void splay(Node* t) {\r\n        stk.clear();\
    \ stk.push_back(t);\r\n        for (Node* x = t; !x->isRoot(); x = x->p) stk.push_back(x->p);\r\
    \n        for (auto it = stk.rbegin(); it != stk.rend(); ++it) push(*it);\r\n\
    \        while (!t->isRoot()) {\r\n            Node* p = t->p;\r\n           \
    \ Node* g = p->p;\r\n            if (!p->isRoot()) {\r\n                if ((t\
    \ == p->l) == (p == g->l)) rotate(p);\r\n                else rotate(t);\r\n \
    \           }\r\n            rotate(t);\r\n        }\r\n    }\r\n\r\n    void\
    \ access(Node* t) {\r\n        Node* last = nullptr;\r\n        for (Node* x =\
    \ t; x; x = x->p) {\r\n            splay(x);\r\n            x->r = last;\r\n \
    \           pull(x);\r\n            last = x;\r\n        }\r\n        splay(t);\r\
    \n    }\r\n\r\n    void makeRoot(int u) {\r\n        Node* t = nodes[u];\r\n \
    \       access(t);\r\n        apply_rev(t);\r\n        push(t);\r\n    }\r\n\r\
    \n    int findRoot(int u) {\r\n        Node* t = nodes[u];\r\n        access(t);\r\
    \n        while (true) {\r\n            push(t);\r\n            if (!t->l) break;\r\
    \n            t = t->l;\r\n        }\r\n        splay(t);\r\n        return t->id;\r\
    \n    }\r\n\r\n    bool isConnected(int u, int v) {\r\n        if (u < 0 || u\
    \ >= (int)nodes.size() || v < 0 || v >= (int)nodes.size()) return false;\r\n \
    \       return findRoot(u) == findRoot(v);\r\n    }\r\n\r\n    void link(int u,\
    \ int v) {\r\n        makeRoot(u);\r\n        if (isConnected(u, v)) return;\r\
    \n        nodes[u]->p = nodes[v];\r\n    }\r\n\r\n    void cut(int u, int v) {\r\
    \n        makeRoot(u);\r\n        access(nodes[v]);\r\n        if (nodes[v]->l\
    \ == nodes[u]) {\r\n            nodes[v]->l->p = nullptr;\r\n            nodes[v]->l\
    \ = nullptr;\r\n            pull(nodes[v]);\r\n        } else {\r\n          \
    \  makeRoot(v);\r\n            access(nodes[u]);\r\n            if (nodes[u]->l\
    \ == nodes[v]) {\r\n                nodes[u]->l->p = nullptr;\r\n            \
    \    nodes[u]->l = nullptr;\r\n                pull(nodes[u]);\r\n           \
    \ }\r\n        }\r\n    }\r\n\r\n    void update(int u, const S& v) {\r\n    \
    \    Node* t = nodes[u];\r\n        access(t);\r\n        t->val = v;\r\n    \
    \    pull(t);\r\n    }\r\n\r\n    S pathQuery(int u, int v) {\r\n        if (!isConnected(u,\
    \ v)) return e();\r\n        makeRoot(u);\r\n        access(nodes[v]);\r\n   \
    \     return nodes[v]->sum_ltr;\r\n    }\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class S, S (*op)(S, S), S (*e)()>\r\nstruct LinkCutTree\
    \ {\r\n    struct Node {\r\n        int id;\r\n        Node *l = nullptr, *r =\
    \ nullptr, *p = nullptr;\r\n        bool rev = false;\r\n        S val, sum_ltr,\
    \ sum_rtl;\r\n        Node(int _id, const S& v = e()) : id(_id), val(v), sum_ltr(v),\
    \ sum_rtl(v) {}\r\n        bool isRoot() const { return !p || (p->l != this &&\
    \ p->r != this); }\r\n    };\r\n\r\n    vector<Node> pool;\r\n    vector<Node*>\
    \ nodes;\r\n    vector<Node*> stk;\r\n\r\n    LinkCutTree(int n) {\r\n       \
    \ pool.reserve(n);\r\n        nodes.reserve(n);\r\n        stk.reserve(n);\r\n\
    \        for (int i = 0; i < n; i++) {\r\n            pool.emplace_back(i);\r\n\
    \            nodes.push_back(&pool.back());\r\n        }\r\n    }\r\n\r\n    inline\
    \ void apply_rev(Node* t) {\r\n        swap(t->l, t->r);\r\n        swap(t->sum_ltr,\
    \ t->sum_rtl);\r\n        t->rev ^= 1;\r\n    }\r\n\r\n    inline void push(Node*\
    \ t) {\r\n        if (t && t->rev) {\r\n            if (t->l) apply_rev(t->l);\r\
    \n            if (t->r) apply_rev(t->r);\r\n            t->rev = false;\r\n  \
    \      }\r\n    }\r\n\r\n    inline void pull(Node* t) {\r\n        S a = e(),\
    \ b = e();\r\n        if (t->l) a = t->l->sum_ltr;\r\n        a = op(a, t->val);\r\
    \n        if (t->r) t->sum_ltr = op(a, t->r->sum_ltr);\r\n        else t->sum_ltr\
    \ = a;\r\n\r\n        if (t->r) b = t->r->sum_rtl;\r\n        b = op(b, t->val);\r\
    \n        if (t->l) t->sum_rtl = op(b, t->l->sum_rtl);\r\n        else t->sum_rtl\
    \ = b;\r\n    }\r\n\r\n    void rotate(Node* t) {\r\n        Node* p = t->p;\r\
    \n        Node* g = p->p;\r\n        push(g); push(p); push(t);\r\n        bool\
    \ isR = (t == p->r);\r\n        Node* b = isR ? t->l : t->r;\r\n        if (!p->isRoot())\
    \ {\r\n            if (p == g->l) g->l = t;\r\n            else g->r = t;\r\n\
    \        }\r\n        t->p = g;\r\n        if (isR) { t->l = p; p->r = b; }\r\n\
    \        else     { t->r = p; p->l = b; }\r\n        if (b) b->p = p;\r\n    \
    \    p->p = t;\r\n        pull(p);\r\n        pull(t);\r\n    }\r\n\r\n    void\
    \ splay(Node* t) {\r\n        stk.clear(); stk.push_back(t);\r\n        for (Node*\
    \ x = t; !x->isRoot(); x = x->p) stk.push_back(x->p);\r\n        for (auto it\
    \ = stk.rbegin(); it != stk.rend(); ++it) push(*it);\r\n        while (!t->isRoot())\
    \ {\r\n            Node* p = t->p;\r\n            Node* g = p->p;\r\n        \
    \    if (!p->isRoot()) {\r\n                if ((t == p->l) == (p == g->l)) rotate(p);\r\
    \n                else rotate(t);\r\n            }\r\n            rotate(t);\r\
    \n        }\r\n    }\r\n\r\n    void access(Node* t) {\r\n        Node* last =\
    \ nullptr;\r\n        for (Node* x = t; x; x = x->p) {\r\n            splay(x);\r\
    \n            x->r = last;\r\n            pull(x);\r\n            last = x;\r\n\
    \        }\r\n        splay(t);\r\n    }\r\n\r\n    void makeRoot(int u) {\r\n\
    \        Node* t = nodes[u];\r\n        access(t);\r\n        apply_rev(t);\r\n\
    \        push(t);\r\n    }\r\n\r\n    int findRoot(int u) {\r\n        Node* t\
    \ = nodes[u];\r\n        access(t);\r\n        while (true) {\r\n            push(t);\r\
    \n            if (!t->l) break;\r\n            t = t->l;\r\n        }\r\n    \
    \    splay(t);\r\n        return t->id;\r\n    }\r\n\r\n    bool isConnected(int\
    \ u, int v) {\r\n        if (u < 0 || u >= (int)nodes.size() || v < 0 || v >=\
    \ (int)nodes.size()) return false;\r\n        return findRoot(u) == findRoot(v);\r\
    \n    }\r\n\r\n    void link(int u, int v) {\r\n        makeRoot(u);\r\n     \
    \   if (isConnected(u, v)) return;\r\n        nodes[u]->p = nodes[v];\r\n    }\r\
    \n\r\n    void cut(int u, int v) {\r\n        makeRoot(u);\r\n        access(nodes[v]);\r\
    \n        if (nodes[v]->l == nodes[u]) {\r\n            nodes[v]->l->p = nullptr;\r\
    \n            nodes[v]->l = nullptr;\r\n            pull(nodes[v]);\r\n      \
    \  } else {\r\n            makeRoot(v);\r\n            access(nodes[u]);\r\n \
    \           if (nodes[u]->l == nodes[v]) {\r\n                nodes[u]->l->p =\
    \ nullptr;\r\n                nodes[u]->l = nullptr;\r\n                pull(nodes[u]);\r\
    \n            }\r\n        }\r\n    }\r\n\r\n    void update(int u, const S& v)\
    \ {\r\n        Node* t = nodes[u];\r\n        access(t);\r\n        t->val = v;\r\
    \n        pull(t);\r\n    }\r\n\r\n    S pathQuery(int u, int v) {\r\n       \
    \ if (!isConnected(u, v)) return e();\r\n        makeRoot(u);\r\n        access(nodes[v]);\r\
    \n        return nodes[v]->sum_ltr;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/LinkCutTree.hpp
  requiredBy: []
  timestamp: '2025-05-16 01:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/LinkCutTree.hpp
layout: document
redirect_from:
- /library/tree/LinkCutTree.hpp
- /library/tree/LinkCutTree.hpp.html
title: tree/LinkCutTree.hpp
---
