// https://www.youtube.com/watch?v=YbY8cVwWAvw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=42
// striver playlist

// multi source shortest path algorithm, also detects negative weight cycles

// we use adjacency matrix representation for simplicity
// if distance between node i and j is t be calculated then [i][j] = [i][k] + [j][k] and it's said as relaxation and pronounced as from i to j via k.

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9; // A large value representing infinity

void floydwarshall(int n, vector<vector<int>>& adjmat){

    for(int k=0; k<n; k++){ //via node
        for(int i=0; i<n; i++){ // from node
            for(int j=0; j<n; j++){ // to node
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
            }
        }
    }
}
