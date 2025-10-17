#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n ; cin >> n;
    vector<char> wov;
    vector<char> con;
    string s;
    cin >> s;
    for(char&c:s){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u'){
            wov.push_back(c);
        }
        else{
            con.push_back(c);
        }
    }
    sort(wov.begin(), wov.end());
    sort(con.begin(), con.end());

    string w = "";
    for(char&c:wov){
        w+=c;
    }
    for(char&c:con){
        w+=c;
    }
    cout << w << endl;

    return 0;

}