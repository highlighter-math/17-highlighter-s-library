#pragma once
template<class S,auto op,auto e> struct segtree{
	private:
	int N;
	vector<S> val;
	public:
	segtree(int siz) : N(siz),val(2*siz-1,e()){}
	segtree(vector<S> v){
		N=(int)(v.size());
		val.resize(2*N-1);
		for(int i=N;i<2*N;i++){
			val[i-1]=v[i-N];
		}
		for(int i=N-1;i>0;i--){
			val[i-1]=op(val[(i<<1)-1],val[i<<1]);
		}
	}
	void set(int p,S x){
		p+=N;
		val[p-1]=x;
		while(p>1){
			p>>=1;
			val[p-1]=op(val[(p<<1)-1],val[p<<1]);
		}
	}
	S get(int p){
		return val[p+N-1];
	}
	S prod(int l,int r){
		l+=N;
		r+=N;
		S lret=e();
		S rret=e();
		for(;l<r;l>>=1,r>>=1){
			if(l&1){
				lret=op(lret,val[l-1]);
				l++;
			}
			if(r&1){
				r--;
				rret=op(val[r-1],rret);
			}
		}
		return op(lret,rret);
	}
};