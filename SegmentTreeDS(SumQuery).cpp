#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int t[4*N];/// we need tree of size approximately 4n, can be done within 2n depending on implementation

void build(int a[],int v,int tleft,int tright){
    if(tleft == tright){
        t[v] = a[tleft];
    }else{
        int tmid = (tleft+tright)/2;
        build(a, v*2, tleft, tmid);
        build(a, v*2+1, tmid+1, tright);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

int sum(int v,int tleft,int tright,int left,int right){
    if(left > right){
        return 0;
    }
    if(left == tleft && right == tright){
        return t[v];
    }
    int tmid = (tleft+tright)/2;
    return sum(v*2, tleft, tmid, left, min(tmid,right))+
        sum(v*2+1, tmid+1, tright, max(tmid+1,left), right);
}

void update(int v,int tleft,int tright,int pos,int val){///single element update of original array
    if(tleft == tright){
        t[v] = val;
    }else{
        int tmid = (tleft+tright)/2;
        if(pos <= tmid)
            update(v*2, tleft, tmid, pos, val);
        else update(v*2+1, tmid+1, tright, pos, val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main(){

    int n,i,j,k,q;
    cout << "Enter array:" << endl;
    cin >> n;
    int a[n+2];
    for(i=1; i<=n; i++){
        cin >> a[i];
    }
    build(a,1,1,n);///build the tree

    cout << "Enter No. of queries:(1 for update,2 for sum queries)" << endl;
    cin >> q;
    while(q--){
        int x,y,z;
        cin >> k;
        if(k==1){
            cin >> x >> y;
            update(1,1,n,x,y);
        }else{
            cin >> x >> y;
            cout << sum(1,1,n,x,y) << endl;
        }
    }
    return 0;
}
