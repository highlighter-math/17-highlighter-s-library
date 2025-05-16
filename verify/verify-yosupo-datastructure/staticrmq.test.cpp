#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include<bits/stdc++.h>
using namespace std;

#include "../../data_structure/segtree.hpp"

int op(int a,int b){
	return min(a,b);
}

int e(){
	return 1000000000;
}

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	int N,Q;
	cin >> N >> Q;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin >> A[i];
	segtree<int,op,e> seg(A);
	for(;Q--;){
		int l,r;
		cin >> l >> r;
		cout << seg.prod(l,r) << '\n';
	}
}