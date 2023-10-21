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
const ll N = 2e6 + 10;
vector<pair<int,int> > movements = { {+1,0},{-1,0},{0,+1},{0,-1} };
ll mod(ll a){ return ((a%M)+M)%M;}

ll rootN,k;
ll cur_ans = 0;
vector<int> v(N),prefix(N),cnt1(N), cnt2(N);

struct Q{
    int idx, l, r;
};
Q q[N];

bool compare(Q q1, Q q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r < q2.r;
    }
    else{
        return q1.l/rootN < q2.l/rootN;
    }
}
void addL(int pos){
    cnt1[prefix[pos-1]]++; cnt2[prefix[pos]]++;
    cur_ans += cnt2[prefix[pos-1]^k];
}
void addR(int pos){
    cnt1[prefix[pos-1]]++; cnt2[prefix[pos]]++;
    cur_ans += cnt1[prefix[pos]^k];
}
void removeL(int pos){
    cur_ans -= cnt2[prefix[pos-1]^k];
    cnt1[prefix[pos-1]]--; cnt2[prefix[pos]]--;
}
void removeR(int pos){
    cur_ans -= cnt1[prefix[pos]^k];
    cnt1[prefix[pos-1]]--; cnt2[prefix[pos]]--;
}
void Mos(){
    int n; cin>>n;
    int queries; cin>>queries;
    cin>>k;
    for(int i=1; i<=n; ++i) cin>>v[i];
    for(int i=1; i<=n; ++i) prefix[i] = v[i]^prefix[i-1];
    rootN = sqrt(n);

    for(int i=1; i<=queries; ++i){
        ll l,r;cin>>l>>r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }

    sort(q+1, q+queries+1, compare);
    vector<ll> ans(queries+2);
    ll cur_l=1, cur_r=0, l, r;

    for(int i=1; i<=queries; ++i){
        l = q[i].l;
        r = q[i].r;
        while(cur_r < r){
            cur_r++;
            addR(cur_r);
        }
        while(cur_l > l){
            --cur_l;
            addL(cur_l);
        }
        while(cur_l < l){
            removeL(cur_l);
            ++cur_l;
        }
        while(cur_r > r){
            removeR(cur_r);
            --cur_r;
        }
        ans[q[i].idx] = cur_ans;
    }
    for(int i=1; i<=queries; ++i){
        cout<<ans[i]<<nl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../Input.txt", "r", stdin);
    freopen("../Output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    Mos();

return 0;
}



