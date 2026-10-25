#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double wallet, m, b, r;
    cout << "Введите сумму в кошельке: ";
    cin >> wallet;
    cout << "Стоимость молока: ";
    cin >> m;
    cout << "Стоимость ботинок: ";
    cin >> b;
    cout << "Стоимость линейки: ";
    cin >> r;

    if (wallet < m) {
        cout << "Денег не хватает" << endl;
        return 0;
    }
    wallet -= m;  

    if (wallet < b) {
        cout << "Хватило только на молоко" << endl;
        return 0;
    }
    wallet -= b;
 
    if (wallet < r) {
        cout << "Хватило только на молоко и ботинки" << endl;
        return 0;
    }
    wallet -= r;

    cout << "Все покупки совершены. Вот остаток суммы: " << wallet << endl;

    return 0;
}
