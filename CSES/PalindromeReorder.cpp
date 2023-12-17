#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define nl '\n'
#define pi acos(-1)
#define ll long long
#define For(i,n) for(ll i=0; i<n; i++)
#define all(x) x.begin(), x.end()
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>

typedef unsigned long long  ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
const ll M = 1e9 + 7;
const ll N = 2e5 + 10;
vector<pair<int,int> > movements = { {+1,0},{-1,0},{0,+1},{0,-1} };
ll mod(ll a){ return ((a%M)+M)%M;}



int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("../Input.txt", "r", stdin);
    // freopen("../Output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s; cin>>s;
    int n = s.size();
    vector<int> ch(26,0);

    For(i,n) ch[s[i]-'A']++;
    ll odd_ct=0, pos=0;

    for(int i=0; i<26; ++i){
        if(ch[i] & 1) {
            ++odd_ct;
            pos = i;
        }
    }
    deque<char> dq;
    if(odd_ct>1) cout<<"NO SOLUTION\n";
    else{
        For(i,ch[pos]) dq.push_back(pos+'A');

        for(int i=0; i<26; ++i){
            if(i==pos) continue;
            while(ch[i]>0){
                dq.push_back(i+'A');
                dq.push_front(i+'A');
                ch[i]-=2;

            }
        }
    }

    while(!dq.empty()){
        cout<<dq.front();
        dq.pop_front();
    }cout<<nl;


return 0;
}
