#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    map<int, pair<int,int>> child;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    int root = vect[0];
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
    int X;
    cin >> X; // узел, чей размер поддерева считаем

    int count = 0;
    queue<int> q;
    q.push(X);

    while(!q.empty()){
        int cur = q.front();  // берём следующий узел из очереди
        q.pop();              // удаляем его из очереди
        count++;              // считаем узел

        if(child[cur].first != 0) q.push(child[cur].first);   // добавляем левого потомка
        if(child[cur].second != 0) q.push(child[cur].second); // добавляем правого потомка
    }

    cout << count << endl;

    return 0;
}
