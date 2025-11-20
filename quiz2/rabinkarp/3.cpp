#include <iostream>
#include <vector>

using namespace std;

vector<int> rabinkarp(string text, string pattern){
    const int d = 256;
    const int q = 101;

    int n = text.size();
    int m = pattern.size();
    vector<int> ans;
    int p =0; 
    int t = 0;
    int h = 1;

    for(int i=0;i<m-1;i++){
        h = (h*d) % q;
    }

    for(int i=0;i<m;i++){
        p = (p*d + pattern[i]) % q;
        t = (t*d + text[i]) % q;
    }

    for(int i=0;i<= n-m;i++){
        if(p==t){
            if(text.substr(i,m) == pattern){
                ans.push_back(i);
            }
        }
        if(i<n-m){
            t = (d*(t - text[i] * h) + text[i+m] % q);
            if(t<0) t+=q;
        }
    }
    return ans;
}

vector<int> rabinkarp2(string text, string pattern){
    const int d = 256;
    const int q = 101;
    int n = text.size();
    int m = pattern.size();
    int p = 0;
    int t = 0;
    int h = 1;
    vector<int> ans;
    for(int i=0;i<m-1;i++){
        h = (h*d) % q;
    }

    for(int i=0;i<m;i++){
        p = (p*d + pattern[i]) % q;
        t = (t*d + text[i]) % q;
    }

    for(int i=0;i<= n-m;i++){
        if(p==t){
            if(text.substr(i,m) == pattern){
                ans.push_back(i);
            }
        }
        if(i<n-m){
            t = (d* (t - text[i] * h) + text[i+m]) % q;
            if(t <0) t+=q;
        }
    }
    return ans;
}


vector<int> rabinkarp4(string text, string pattern){
    const int d = 256;
    const int q = 101;
    vector<int> ans;
    int n = text.size();
    int m = pattern.size();
    int p = 0;
    int t = 0;
    int h = 1;
    for(int i=0;i<m-1;i++){
        h = (h*d) % q;
    }
    for(int i=0;i<m;i++){
        t = (t*d + text[i]) % q;
        p = (p*d + pattern[i]) % q;
    }

    for(int i=0;i<=n-m;i++){
        if(p==t){
            if(text.substr(i,m) == pattern){
                ans.push_back(i);
            }
        if(i < n - m){
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if(t < 0) t += q;
        }
        }
    }
    return ans;

} 



vector<int> rabinkarp5(string text, string pattern){
    const int d = 256;
    const int q = 101;
    vector<int> ans;
    int t = 0;
    int p = 0;
    int h = 1;
    int n = text.size();
    int m = pattern.size();

    for(int i=0;i<m-1;i++){
        h = (h*d) % q;
    }
    for(int i=0;i<m;i++){
        t = (t*d + text[i]) % q;
        p = (p*d + pattern[i]) % q;
    }

    for(int i=0;i<=n-m;i++){
        if(p==t){
            if(text.substr(i,m) == pattern){
                ans.push_back(i);
            }
        }
        if(i<n-m){
            t = (d*(t-text[i]*h) + text[i+m]) % q;
            if(t<0) t+=q;
        }
    }
    return ans;
}

vector<int> rabinkarp6(string text, string pattern){
    const int d = 256;
    const int q = 101;
    int n = text.size();
    int m = pattern.size();
    int p = 0;
    int t = 0;
    int h =1;
    vector<int> ans;
    for(int i=0;i<m-1;i++){
        h = (h*d) % q;
    }
    for(int i=0;i<m;i++){
        p = (p*d + pattern[i]) % q;
        t = (t*d + text[i]) % q;
    }

    for(int i=0;i<n-m;i++){
        if(p==t){
            if(text.substr(i,m) == pattern){
                ans.push_back(i);
            }
        }
        if(i<n-m){
            t = (d* (t-text[i]*h) + text[i+m]) % q;
            if(t<0) t+=q;
        }
    }
}

