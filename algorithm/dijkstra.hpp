struct edge{
  int to;
  //通常の木の場合辺の重みは1
  long long cost=1;
};
struct LCA{
  LCA(const vector<vector<edge>> &G,int root=0){
    build(G,root);
  }
  vector<vector<int>> parent;
  vector<pair<int,long long>> dist;
  int N,LOG;
  void build(const vector<vector<edge>> &G,int root=0){
    N=G.size();
    LOG=32-__builtin_clz(N);
    parent.assign(LOG,vector<int>(N,-1));
    dist.assign(N,{-1,-1});
    dfs(G,root,-1,{0,0});
    for(int i=0;i<LOG-1;i++){
      for(int j=0;j<N;j++){
        if(parent[i][j]==-1){
          parent[i+1][j]=-1;
        }else{
          parent[i+1][j]=parent[i][parent[i][j]];
        }
      }
    }
  }
  void dfs(const vector<vector<edge>> &G,int v,int p,pair<int,long long> d){
    parent[0][v]=p;
    dist[v]=d;
    for(auto e:G[v]){
      if(e.to!=p) dfs(G,e.to,v,{d.first+1,d.second+e.cost});
    }
  }
  int lca(int u,int v){
    if(dist[u].first<dist[v].first) swap(u,v);
    for(int i=0;i<LOG;i++){
      if((dist[u].first-dist[v].first)&(1<<i)) u=parent[i][u];
    }
    if(u==v) return u;
    for(int i=LOG-1;i>=0;i--){
      if(parent[i][u]!=parent[i][v]){
        u=parent[i][u];
        v=parent[i][v];
      }
    }
    return parent[0][u];
  }
  long long dis(int u,int v){
    return dist[u].second+dist[v].second-2*dist[lca(u,v)].second;
  }
};