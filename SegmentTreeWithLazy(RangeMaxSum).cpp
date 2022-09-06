#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int lazy[4*N],t[4*N];

void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v] = a[tl];
    }else{
        int mid = (tl+tr)/2;
        build(a,v*2,tl,mid);
        build(a,v*2+1,mid+1,tr);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}

void push(int v){
    if(lazy[v]){
            t[v*2] += lazy[v];
            t[v*2+1] += lazy[v];///values updated on the tree
            lazy[v*2] += lazy[v];
            lazy[v*2+1] += lazy[v];///add update with existing update in child nodes

            lazy[v] = 0;///updates are passed to child nodes
    }
}

void update(int v,int tl,int tr,int l,int r,int add){
    if(l > r){
        return;
    }else if(tl==l && tr==r){
        t[v] += add;///found relevant segment for range update
        lazy[v] += add;///instead of updating all the nodes we just store the update to pass on childs later
    }else{
        push(v);
        int mid = (tl+tr)/2;
        update(v*2,tl,mid,l,min(r,mid),add);
        update(v*2+1,mid+1,tr,max(l,mid+1),r,add);
        t[v] = max(t[v*2],t[v*2+1]);///for maximum value node after update
    }
}

int query(int v,int tl,int tr,int l,int r){
    if(l > r)
        return INT_MIN;
    if(l<=tl && r >= tr)
        return t[v];
    push(v);
    int mid = (tl+tr)/2;
    return max(query(v*2,tl,mid,l,min(r,mid)),
               (query(v*2+1,mid+1,tr,max(l,mid+1),r)));
}

int main(){

    int n,i,j,k,x;
    cout << "Enter array size and array" << endl;
    cin >> n;
    int a[n+2];
    for(i=1; i<=n*4; i++){
       // t[i] = INT_MIN;///initialized because our array may contain negative numbers
    }

    for(i=1; i<=n; i++){
        cin >> a[i];
    }

    build(a,1,1,n);

    cout << "Enter query number and queries(1 for output(left,right),2 for update(left,right,value))" << endl;
    int q,l,r;
    cin >> q;
    while(q--){
        cin >> k;
        if(k==1){
            cin >> l >> r;
            cout << query(1,1,n,l,r) << endl;
        }else{
            cin >> l >> r >> x;
            update(1,1,n,l,r,x);
        }
    }
    return 0;
}
