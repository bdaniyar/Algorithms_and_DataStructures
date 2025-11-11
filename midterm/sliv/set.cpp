#include <iostream>
#include <set>

using namespace std;

int main(){

    set<int> s;

    // Добавление
    s.insert(5);        // вставка элемента

    // Проверка наличия
    s.count(5);         // 1 если есть, 0 если нет
    s.find(5);          // возвращает итератор на элемент или s.end()

    // Удаление
    s.erase(5);         // удаляет элемент

    // Размер
    s.size();

    // Итерация
    for(int x : s) cout << x << " ";

    return 0;
}