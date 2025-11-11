#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int,int> mp;

    // Добавление / обновление
    mp[5] = 10;         // создаёт ключ 5 со значением 10
    mp[3]++;            // увеличивает значение ключа 3 на 1 (если ключа нет — создаётся со значением 0)

    // Проверка наличия
    mp.count(5);        // 1 если есть, 0 если нет
    mp.find(5);         // итератор на элемент или mp.end()

    // Удаление
    mp.erase(5);

    // Размер
    mp.size();

    // Итерация
    for(auto&x:mp){
        cout << x.first << " " << x.second;
    }
    return 0;
}