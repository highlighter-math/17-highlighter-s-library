struct Static_Deletable_CHT{
	private:
	struct LiChao{
		private:
		vector<pair<long long,long long>> que;
		public:
		void push_back(pair<long long,long long> p){
			while(true){
				if(que.size()<2){
					que.emplace_back(p);
					return;
				}
				pair<long long,long long> q=que.back();
				if(p.first==q.first){
					if(q.first>=p.first){
						return;
					}
					que.pop_back();
					que.emplace_back(p);
					return;
				}
				que.pop_back();
				pair<long long,long long> r=que.back();
				if((r.second-q.second)/(q.first-r.first)<=(q.second-p.second)/(p.first-q.first)){
					que.emplace_back(q);
					que.emplace_back(p);
					return;
				}
			}
		}
		long long get_max(int x){
			if(que.empty()){
				return 0LL;
			}
			while(que.size()>1){
				pair<long long,long long> p=que.back();
				pair<long long,long long> q=que[(int)(que.size())-2];
				if(p.first*x+p.second<=q.first*x+q.second){
					que.pop_back();
				}
				else{
					return p.first*x+p.second;
				}
			}
			pair<long long,long long> p=que.back();
			return p.first*x+p.second;
		}
	};
	vector<LiChao> vec;
	int N;
	vector<tuple<pair<long long,long long>,int,int>> mem;
	public:
	Static_Deletable_CHT(int Q) : vec(Q*2-1),N(Q){}
	void add_line(int l,int r,pair<long long,long long> p){
		//[l,r)にpを追加
		//後でまとめて行う
		if(l>=r) return;
		mem.emplace_back(make_tuple(p,l,r));
	}
	void build(){
		//memをソート
		sort(mem.begin(),mem.end());
		for(tuple<pair<long long,long long>,int,int> t : mem){
			pair<long long,long long> p;
			int l,r;
			tie(p,l,r)=t;
			l+=N;
			r+=N;
			for(;l<r;l>>=1,r>>=1){
				if(l&1){
					vec[l-1].push_back(p);
					l++;
				}
				if(r&1){
					r--;
					vec[r-1].push_back(p);
				}
			}
		}
	}
	long long get_max(int p,int x){
		//時刻pのmax
		p+=N;
		long long res=vec[p-1].get_max(x);
		while(p>1){
			p>>=1;
			res=max(res,vec[p-1].get_max(x));
		}
		return res;
	}
};