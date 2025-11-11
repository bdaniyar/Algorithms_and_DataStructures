#include <iostream>
#include <map>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    map<int,pair<int,int>> child;
    int root = vect[0];
    for(int i=1;i<n;i++){
        int cur = root;
        while(true){
            if(cur > vect[i]){
                if (child[cur].first == 0){
                    child[cur].first = vect[i];
                    break;
                }
                cur = child[cur].first;
            }
            else{
                if (child[cur].second==0){
                    child[cur].second = vect[i];
                    break;
                }
                cur = child[cur].second;
            }
        }
    }
    for(int i=0;i<n;i++){
        int cur = vect[i];
        if(child[cur].first == 0 && child[cur].second ==0){
            cout << cur << " ";
        }
    }

    return 0;
}