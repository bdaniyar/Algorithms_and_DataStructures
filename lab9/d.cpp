#include <iostream>
#include <vector>

using namespace std;

vector<int> build_lps(const string&pat){
    int m = pat.size();
    vector<int> lps(m,0);
    int len = 0;
    int i = 1;
    while(i < m){
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
    string prev;
    int k; 
    cin >> prev >> k;
    string prev_lower = prev;
    for (char &c : prev_lower) c = tolower(c);

    vector<string> cities(k);
    for(int i=0;i<k;i++){
        cin >> cities[i];
        string city_lower = cities[i];
        for (char &c : city_lower) c = tolower(c);
    }

    int best_len = 0;
    vector<string> ans;
    for (int i = 0; i < k; i++) {
        string city = cities[i];
        string city_lower = city;
        for (char &c : city_lower) c = tolower(c);

        string combined = city_lower + "#" + prev_lower;
        vector<int> lps = build_lps(combined);

        int match_len = lps.back();   // длина суффикс(prev) == префикс(city)

        if (match_len > best_len) {
            best_len = match_len;
            ans.clear();
            ans.push_back(city);
        } 
        else if (match_len == best_len && match_len > 0) {
            ans.push_back(city);
        }
    }

    cout << ans.size() << "\n";
    for (auto &s : ans)
        cout << s << "\n";
}