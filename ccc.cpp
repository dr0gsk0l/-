#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long LINF=1e18;
/*
端を消す
3つ消して左右の和を作る
結局使用するのは連続区間
長さ2k+1の連続区間でありこの時順番は変わら無い　そんなことなかった
k回の足し合わせが起こるンァーわかった
*/
signed main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  int ans=-LINF;
  int a,b;
  for(int i=0;i<n;i++){
    int res=v[i];
    for(int j=i+2;j<n;j+=2){
      if(ans<res+v[j]){
        ans=res+v[j];
        a=i,b=j;
      }
      if(v[j]>0)res+=v[j];
    }
  }
  int T=(b-a)>>1;
  int Q=-1;
  for(int i=0;i<n;i++){
    if(ans<v[i]){
      ans=v[i];
      Q=i;
    }
  }
  if(~Q){
    cout<<ans<<endl;
    cout<<n-1<<endl;
    for(int i=0;i<Q;i++)cout<<1<<endl;
    for(int i=0;i<n-1-Q;i++)cout<<2<<endl;
    return 0;
  }
  cout<<ans<<endl;
  cout<<n-1-T<<endl;
  vector<int> PPP;
  for(int i=0;i<a;i++)PPP.push_back(1);
  for(int i=a+2;i<b;i+=2){
    if(v[i]>0)PPP.push_back(2);
    else PPP.push_back(3);
  }
  PPP.push_back(2);
  for(int i=b;i<n-1;i++)PPP.push_back(2);
  assert(PPP.size()==n-1-T);
  for(int p:PPP)cout<<p<<endl;
}
