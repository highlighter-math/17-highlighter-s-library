#pragma once
template<class S>
S power(S a,S b,int p=-1){
	S mul=a;
	S res=1;
	while(b){
		if(b&1){
			res*=mul;
			if(p!=-1) res%=p;
		}
		mul*=mul;
		if(p!=-1) mul%=p;
		b>>=1;
	}
	if(res<0)res+=p;
	return res;
}