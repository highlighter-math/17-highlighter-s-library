#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct parser{
  string s;
  parser(string _s):s(_s){};
  long long get(){
    int i = 0;
    return f1(i);
  }
  ll f1(int &i){
    ll val = f2(i);
    while(s[i] == '+' || s[i] == '-'){
      char op = s[i];
      i++;
      ll val2 = f2(i);
      if(op == '+') val += val2;
      else val -= val2;
    }
    return val;
  }
  ll f2(int &i){
    ll val = f3(i);
    while(s[i] == '*' || s[i] == '/'){
      char op = s[i];
      i++;
      ll val2 = f3(i);
      if(op == '*') val *= val2;
      else val /= val2;
    }
    return val;
  }
  ll f3(int &i){
    if(isdigit(s[i])) return f4(i);
    i++; //'('
    ll val = f1(i);
    i++; //')'
    return val;
  }
  ll f4(int &i){
    long long val = s[i++]-'0';
    while(isdigit(s[i])) val = val*10+s[i++]-'0';
    return val;
  }
};