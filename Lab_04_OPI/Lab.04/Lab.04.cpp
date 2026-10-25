#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    unsigned char symbol;

    cout << "Введите один символ: ";
    cin >> symbol;
    if (symbol >= '0' && symbol <= '9') {
        cout << "Это цифра '" << symbol << "', код ASCII = 0x"
            << hex << (int)symbol << endl;
    }
    else if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
        cout << "Это латинская буква '" << symbol << "', код ASCII = 0x"
            << hex << (int)symbol << endl;
    }
    else if (symbol >= 0xC0 && symbol <= 0xFF) {
        cout << "Это русская буква '" << symbol << "', код Windows-1251 = 0x"
            << hex << (int)symbol << endl;
    }
    else {
        cout << "Это не цифра и не буква '" << symbol << "', код Windows-1251 = 0x"
            << hex << (int)symbol << endl;
    }

    system("pause");
    return 0;
}
