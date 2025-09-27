#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int t; cin >> t;
    vector<int> arr(t);
    for(int i=0;i<t;i++){
        cin >> arr[i];
    }
    int n,m;
    cin >> n >> m;
    unordered_map<int, pair<int,int>> pos;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
            pos[matrix[i][j]] = {i,j};
        }
    }

    for(int a=0;a<t;a++){
        if(pos.count(arr[a])){
            cout << pos[arr[a]].first << " " << pos[arr[a]].second << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    
}
