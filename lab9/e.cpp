#include <iostream>
#include <vector>

using namespace std;

vector<int> build_lps(const string&pat){
    int m = pat.size();
    vector<int> lps(m,0);
    int len = 0;
    int i = 1;
    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string s; int k;
        cin >> s >> k;
        vector<int> lps = build_lps(s);
        int n = s.size();
        int p = lps[lps.size()-1];
        int min_res = n + (k-1) * (n-p);
        cout << min_res << endl;
    }
}