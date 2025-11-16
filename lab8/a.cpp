#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const long long MOD = 1e9 + 7;

string hashing(const string&s){
    long long h = 0;
    long long p = 1;

    for(char c:s){
        h = (h + ((c - 47) * p) % MOD) % MOD; 
        p = (p * 11) % MOD; 
    }
    // ASCII '1' = 49 
    // 49-47 = 2
    // (49-47) * 11 = 22
    // (49-47) * 11^2 = 2* 121 = 242
    // h = 2 + 22 + 242 = 266

    return to_string(h);
}

int main(){
    int n; cin >> n;
    vector<string> v;
    unordered_set<string> st;

    for(int i=0;i<n*2;i++){
        string s; cin >> s;
        v.push_back(s);
        st.insert(s);
    }

    int cnt = 0;
    for(int i=0;i<v.size();i++){
        if(cnt==n) break;
        string hs = hashing(v[i]);
        if(st.find(hs) != st.end()){
            cout << "Hash of string \"" << v[i] << "\" is " << hs << endl;
            cnt++;
        }
    }
    return 0;
}