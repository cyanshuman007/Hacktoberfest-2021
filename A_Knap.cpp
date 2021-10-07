#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >>n;
    int w;
    cin >> w;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)
    {
        int p; cin >> p;
        v[i] = {p,i};
    }
    sort(v.begin(),v.end());
    int sum = 0;
    vector<int>res;
    for(int i=n-1;i>=0;i--)
    {
        if(sum+v[i].first<=w){
        res.push_back(v[i].second+1);
        sum+=v[i].first;
        if(sum>w/2)break;
        }
    }
    if(sum<w/2 + w%2 or res.size()==0)
    {
        cout<<-1;return;
    }
    if(res.size()){
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(auto it:res)cout<<it<<" ";
    }
    else
    {
        cout<<-1;
    }
}
int32_t main()
{
    int t;
    cin >> t;
    while(t--){solve();cout<<endl;}
    return 0;
}
