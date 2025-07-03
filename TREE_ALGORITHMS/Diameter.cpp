#include<bit/stdc++.h>
using namespace std;

struct Node {
    int data ;
    struct Node* left ;
    struct Node* right;
    Node (int data ) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};



Node* createTree ( int n   ) {
    vector<pair<int,int>> NodeMap(n+1, {-1,-1} );
     for ( int i=1; i<=n; i++ ) {
        //   nodeMap[i] = new Node(i);

     }
}

int main () {
    int n ;
    cin >> n;
    // vector<pair<int,int>> tree (n-1);
    Node* root = createTree(n, tree);
}