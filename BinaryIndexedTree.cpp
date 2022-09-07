#include<bits/stdc++.h>
#define pb push_back

typedef long long ll;
using namespace std;

const ll N = 1e5 + 5;
ll bit[N], n;

void update(ll idx, ll value){
    while(idx <= n){
        bit[idx] += value;
        idx += idx&-idx;
    }
}

ll Query(ll idx){
    ll sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= idx&-idx;
    }
    return sum;
}

ll Range_Update(ll l, ll r, ll value){
    update(l, value);
    update(r+1, -value);
    update(l, value*(l-1));
    update(r+1, -value*r);
}

int main(){

    ll i, j, k, val, index;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> index >> val;
        update(index, val);
    }

    int q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << Query(r) - Query(l-1) << endl;
    }

    return 0;
}
