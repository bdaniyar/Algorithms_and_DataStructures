#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vect(n);
    map<int, pair<int,int>> child;
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    int root = vect[0];

    // строим BST
    for(int i=1;i<n;i++){
        int cur = root;
        while(true){
            if(vect[i] < cur){
                if(child[cur].first == 0){
                    child[cur].first = vect[i];
                    break;
                }
                cur = child[cur].first;
            }
            else{
                if(child[cur].second == 0){
                    child[cur].second = vect[i];
                    break;
                }
                cur = child[cur].second;
            }
        }
    }

    // BFS для подсчёта сумм по уровням
    queue<pair<int,int>> q; // {узел, уровень}
    q.push({root,0});
    vector<int> sum_levels;

    while(!q.empty()){
        auto [cur, lvl] = q.front(); q.pop();

        if(sum_levels.size() <= lvl) sum_levels.push_back(0); // создаём уровень
        sum_levels[lvl] += cur; // добавляем значение узла

        if(child[cur].first != 0) q.push({child[cur].first, lvl+1});
        if(child[cur].second != 0) q.push({child[cur].second, lvl+1});
    }

    // вывод
    cout << sum_levels.size() << endl;
    for(int s: sum_levels) cout << s << " ";
    cout << endl;

    return 0;
}