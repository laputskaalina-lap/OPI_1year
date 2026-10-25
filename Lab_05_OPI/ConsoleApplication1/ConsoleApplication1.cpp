#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);     
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int s = 0;
    while (true) {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1 - Разница кодов латинской буквы (ASCII)\n";
        cout << "2 - Разница кодов русской буквы (Windows-1251)\n";
        cout << "3 - Вывод кода цифры в Windows-1251\n";
        cout << "4 - Выход из программы\n";
        cout << "Выберите пункт меню (1-4): ";

        if (!(cin >> s)) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка: введите число от 1 до 4.\n";
            continue;
        }

        switch (s) {
        case 1: {
            cout << "\n--- Пункт 1. Латинская буква (ASCII) ---\n";
            cout << "Введите латинскую букву: ";
            char ch;
            cin >> ch;

            char isLatin = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
            if (!isLatin) {
                cout << "Ошибка: это не латинская буква!\n";
                continue;
            }

            unsigned char uc = (unsigned char)ch;
            bool isUpper = (uc >= 'A' && uc <= 'Z');
            bool isLower = (uc >= 'a' && uc <= 'z');

            unsigned char upper, lower;
            if (isUpper) {
                upper = uc;
                
                lower = uc + 32;
            }
            else {
                lower = uc;
                
                upper = uc - 32;
            }

            int diff = (int)lower - (int)upper;

            cout << "Прописной символ: " << (char)upper << " (код " << (int)upper << ")\n";
            cout << "Строчный символ:  " << (char)lower << " (код " << (int)lower << ")\n";
            cout << "Разница кодов: " << diff << "\n";
            break;
        }
        case 2: {
            cout << "\n--- Пункт 2. Русская буква (Windows-1251) ---\n";
            cout << "Введите русскую букву (строчную или прописную): ";
            char ch;
            cin >> ch;

            unsigned char uc = (unsigned char)ch;
            
            bool isUpper = (uc >= 0xC0 && uc <= 0xDF);
            bool isLower = (uc >= 0xE0 && uc <= 0xFF);

            if (!(isUpper || isLower)) {
                cout << "Ошибка: это не русская буква в кодировке Windows-1251.\n";
                continue;
            }

            unsigned char upper, lower;
            if (isUpper) {
                upper = uc;
                
                lower = uc + 0x20;
            }
            else {
                lower = uc;
                upper = uc - 0x20;
            }

            int diff = (int)lower - (int)upper;
            cout << "Прописной символ: " << (char)upper << " (код " << (int)upper << ")\n";
            cout << "Строчный символ: " << (char)lower << " (код " << (int)lower << ")\n";
            cout << "Разница кодов: " << diff << "\n";
            break;
        }
        case 3: {
            cout << "\n--- Пункт 3. Код цифры в Windows-1251 ---\n";
            cout << "Введите цифру (0-9): ";
            char digit;
            cin >> digit;

            if (digit < '0' || digit > '9') {
                cout << "Ошибка: это не цифра.\n";
                continue;
            }

            unsigned char code = (unsigned char)digit;
            cout << "Символ: " << digit << "\n";
            cout << "Код в Windows-1251: " << (int)code << "\n";
            break;
        }
        case 4:
            cout << "Program terminated.\n";
            return 0;
        default:
            cout << "Error: no such menu item.\n";
        }
    }
}
