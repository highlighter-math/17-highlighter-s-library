// f(n,m,a,b)=sum[i=0,n-1] floor((a*i+b)/m)
// O(log min{n,m,a})
ll floor_sum(ll n,ll m,ll a,ll b){
    ll res=0;
    if(a>=m){
        res+=n*(n-1)/2*(a/m);
        a%=m;
    }
    if(b>=m){
        res+=n*(b/m);
        b%=m;
    }
    ll mx=a*(n-1)+b;
    if(mx>=m){
        res+=mx/m+floor_sum(mx/m,a,m,mx%m);
    }
    return res;        
}