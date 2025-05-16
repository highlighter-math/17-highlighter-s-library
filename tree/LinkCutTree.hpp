#pragma once
template <class S, S (*op)(S, S), S (*e)()>
struct LinkCutTree {
    struct Node {
        int id;
        Node *l = nullptr, *r = nullptr, *p = nullptr;
        bool rev = false;
        S val, sum_ltr, sum_rtl;
        Node(int _id, const S& v = e()) : id(_id), val(v), sum_ltr(v), sum_rtl(v) {}
        bool isRoot() const { return !p || (p->l != this && p->r != this); }
    };

    vector<Node> pool;
    vector<Node*> nodes;
    vector<Node*> stk;

    LinkCutTree(int n) {
        pool.reserve(n);
        nodes.reserve(n);
        stk.reserve(n);
        for (int i = 0; i < n; i++) {
            pool.emplace_back(i);
            nodes.push_back(&pool.back());
        }
    }

    inline void apply_rev(Node* t) {
        swap(t->l, t->r);
        swap(t->sum_ltr, t->sum_rtl);
        t->rev ^= 1;
    }

    inline void push(Node* t) {
        if (t && t->rev) {
            if (t->l) apply_rev(t->l);
            if (t->r) apply_rev(t->r);
            t->rev = false;
        }
    }

    inline void pull(Node* t) {
        S a = e(), b = e();
        if (t->l) a = t->l->sum_ltr;
        a = op(a, t->val);
        if (t->r) t->sum_ltr = op(a, t->r->sum_ltr);
        else t->sum_ltr = a;

        if (t->r) b = t->r->sum_rtl;
        b = op(b, t->val);
        if (t->l) t->sum_rtl = op(b, t->l->sum_rtl);
        else t->sum_rtl = b;
    }

    void rotate(Node* t) {
        Node* p = t->p;
        Node* g = p->p;
        push(g); push(p); push(t);
        bool isR = (t == p->r);
        Node* b = isR ? t->l : t->r;
        if (!p->isRoot()) {
            if (p == g->l) g->l = t;
            else g->r = t;
        }
        t->p = g;
        if (isR) { t->l = p; p->r = b; }
        else     { t->r = p; p->l = b; }
        if (b) b->p = p;
        p->p = t;
        pull(p);
        pull(t);
    }

    void splay(Node* t) {
        stk.clear(); stk.push_back(t);
        for (Node* x = t; !x->isRoot(); x = x->p) stk.push_back(x->p);
        for (auto it = stk.rbegin(); it != stk.rend(); ++it) push(*it);
        while (!t->isRoot()) {
            Node* p = t->p;
            Node* g = p->p;
            if (!p->isRoot()) {
                if ((t == p->l) == (p == g->l)) rotate(p);
                else rotate(t);
            }
            rotate(t);
        }
    }

    void access(Node* t) {
        Node* last = nullptr;
        for (Node* x = t; x; x = x->p) {
            splay(x);
            x->r = last;
            pull(x);
            last = x;
        }
        splay(t);
    }

    void makeRoot(int u) {
        Node* t = nodes[u];
        access(t);
        apply_rev(t);
        push(t);
    }

    int findRoot(int u) {
        Node* t = nodes[u];
        access(t);
        while (true) {
            push(t);
            if (!t->l) break;
            t = t->l;
        }
        splay(t);
        return t->id;
    }

    bool isConnected(int u, int v) {
        if (u < 0 || u >= (int)nodes.size() || v < 0 || v >= (int)nodes.size()) return false;
        return findRoot(u) == findRoot(v);
    }

    void link(int u, int v) {
        makeRoot(u);
        if (isConnected(u, v)) return;
        nodes[u]->p = nodes[v];
    }

    void cut(int u, int v) {
        makeRoot(u);
        access(nodes[v]);
        if (nodes[v]->l == nodes[u]) {
            nodes[v]->l->p = nullptr;
            nodes[v]->l = nullptr;
            pull(nodes[v]);
        } else {
            makeRoot(v);
            access(nodes[u]);
            if (nodes[u]->l == nodes[v]) {
                nodes[u]->l->p = nullptr;
                nodes[u]->l = nullptr;
                pull(nodes[u]);
            }
        }
    }

    void update(int u, const S& v) {
        Node* t = nodes[u];
        access(t);
        t->val = v;
        pull(t);
    }

    S pathQuery(int u, int v) {
        if (!isConnected(u, v)) return e();
        makeRoot(u);
        access(nodes[v]);
        return nodes[v]->sum_ltr;
    }
};
