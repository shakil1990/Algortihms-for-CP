#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+2;

int parent[N],treeSize[N];

void make_set(int v){
    parent[v] = v;
    treeSize[v] = 1;
}

int find_parent(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find_parent(parent[v]);/// changing parents of nodes in the path
}

void union_sets(int a,int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a != b){
        if(treeSize[a] < treeSize[b]){
            swap(a,b); ///identifying smaller tree
        }
        parent[b] = a;///parent of smaller tree is parent of bigger tree
        treeSize[a] += treeSize[b];
    }
}

int main(){

    int n,i,j,k,a,b,m;

    cout << "Enter tree size and No. of edge" << endl;
    cin >> n >> m;
    for(i=1; i<=n; i++){
        make_set(i);
    }

    while(m--){
        cin >> a >> b;
        union_sets(a,b);
    }
    cout << "Enter number of operation" << endl;
    cin >> k;
    while(k--){
        cin >> a >> b;

        if(parent[a] == parent[b]){
            cout << "Same tree" << endl;
        }else cout << "Different tree" << endl;
    }
    return 0;
}

