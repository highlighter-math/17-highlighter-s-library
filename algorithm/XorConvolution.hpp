constexpr int LOG = 20;
template<typename T>
void Fast_WalshHadamard_Transform(vector<T> &v){
  for(int i=1;i<(1<<LOG);i<<=1){
    int mask=~i;
    for(int j=i;j<(1<<LOG);j=(j+1)|i){
      T a=v[j&mask];
      T &b=v[j];
      v[j&mask]=(v[j&mask]+b)%mod;
      b=(a-b+mod)%mod;
    }
  }
}
template<typename T>
vector<T> xor_convolution(vector<T> a,vector<T> b){
  Fast_WalshHadamard_Transform(a);
  Fast_WalshHadamard_Transform(b);
  for(int i=0;i<(1<<LOG);i++) a[i]=a[i]*b[i]%mod;
  Fast_WalshHadamard_Transform(a);
  long long x=modpow((mod+1)/2,LOG);
  for(auto &i:a) i=i*x%mod;
  return a;
}