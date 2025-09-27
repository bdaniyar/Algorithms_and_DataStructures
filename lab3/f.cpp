#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    int k; cin >> k;
    vector<int> vect2(k);
    for(int i=0;i<k;i++){
        cin >> vect2[i];
    }
    sort(vect.begin(), vect.end());
    for(int i=0;i<k;i++){
        int cnt = 0;
        int sum = 0;
        for(int j=0;j<n;j++){
            if(vect2[i] >= vect[j]){
                cnt++;
                sum+=vect[j];
            }
        }
        cout << cnt << " " << sum << endl;
    }
}