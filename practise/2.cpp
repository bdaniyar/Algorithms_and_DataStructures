#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        int k = a.length();
        if (k>10){
            int l = a.length() - 2;
            string ans = string(1,a[0]) + to_string(l) + string(1,a[l+1]);
            arr[i] = ans;
        }
        else{
            arr[i] = a;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << endl;
    }

}