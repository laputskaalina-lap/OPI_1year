#include <iostream>
#include <string>
#include <windows.h>
#include <clocale>

using namespace std;

// Именованные константы (избегаем магических чисел)
const char LATIN_LOWER_START = 'a';
const char LATIN_LOWER_END = 'z';
const char LATIN_UPPER_START = 'A';
const char LATIN_UPPER_END = 'Z';
const int ASCII_CASE_DIFF = 32;

const unsigned char WIN1251_RU_UPPER_START = 0xC0;
const unsigned char WIN1251_RU_UPPER_END = 0xDF;
const unsigned char WIN1251_RU_LOWER_START = 0xE0;
const unsigned char WIN1251_RU_LOWER_END = 0xFF;
const int WIN1251_RU_CASE_DIFF = 0x20;

const char DIGIT_START = '0';
const char DIGIT_END = '9';

void printMenu() {
    cout << "\n=== МЕНЮ ===\n";
    cout << "1 - Разница кодов латинской буквы (ASCII)\n";
    cout << "2 - Разница кодов русской буквы (Windows-1251)\n";
    cout << "3 - Вывод кода цифры в Windows-1251\n";
    cout << "4 - Выход из программы\n";
    cout << "Выберите пункт меню (1-4): ";
}

int readChoice() {
    int choice = 0;
    while (true) {
        if (cin >> choice && choice >= 1 && choice <= 4) {
            cin.ignore(32767, '\n');
            return choice;
        }
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Ошибка: введите число от 1 до 4.\n";
        cout << "Выберите пункт меню (1-4): ";
    }
}

void processLatin() {
    cout << "\n--- Пункт 1. Латинские буквы (ASCII) ---\n";
    cout << "Введите последовательность символов: ";

    string line;
    getline(cin, line);

    for (char ch : line) {
        bool isLower = (ch >= LATIN_LOWER_START && ch <= LATIN_LOWER_END);
        bool isUpper = (ch >= LATIN_UPPER_START && ch <= LATIN_UPPER_END);

        if (isLower || isUpper) {
            unsigned char uc = static_cast<unsigned char>(ch);
            unsigned char upper = isUpper ? uc : uc - ASCII_CASE_DIFF;
            unsigned char lower = isLower ? uc : uc + ASCII_CASE_DIFF;
            int diff = static_cast<int>(lower) - static_cast<int>(upper);

            cout << "Символ: " << ch
                << " | Прописной: " << static_cast<char>(upper) << " (" << static_cast<int>(upper) << ")"
                << " | Строчный: " << static_cast<char>(lower) << " (" << static_cast<int>(lower) << ")"
                << " | Разница: " << diff << "\n";
        }
    }
}

void processRussian() {
    cout << "\n--- Пункт 2. Русские буквы (Windows-1251) ---\n";
    cout << "Введите последовательность символов: ";

    string line;
    getline(cin, line);

    for (char ch : line) {
        unsigned char uc = static_cast<unsigned char>(ch);
        bool isUpper = (uc >= WIN1251_RU_UPPER_START && uc <= WIN1251_RU_UPPER_END);
        bool isLower = (uc >= WIN1251_RU_LOWER_START && uc <= WIN1251_RU_LOWER_END);

        if (isUpper || isLower) {
            unsigned char upper = isUpper ? uc : uc - WIN1251_RU_CASE_DIFF;
            unsigned char lower = isLower ? uc : uc + WIN1251_RU_CASE_DIFF;
            int diff = static_cast<int>(lower) - static_cast<int>(upper);

            cout << "Символ: " << ch
                << " | Прописной: " << static_cast<char>(upper) << " (" << static_cast<int>(upper) << ")"
                << " | Строчный: " << static_cast<char>(lower) << " (" << static_cast<int>(lower) << ")"
                << " | Разница: " << diff << "\n";
        }
    }
}

void processDigits() {
    cout << "\n--- Пункт 3. Цифры в Windows-1251 ---\n";
    cout << "Введите последовательность символов: ";

    string line;
    getline(cin, line);

    for (char ch : line) {
        if (ch >= DIGIT_START && ch <= DIGIT_END) {
            unsigned char code = static_cast<unsigned char>(ch);
            cout << "Символ: " << ch << " | Код: " << static_cast<int>(code) << "\n";
        }
    }
}

int main() {
    // Установка кодировки консоли для корректного отображения и ввода русского языка (Windows-1251)
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    int choice = 0;

    do {
        printMenu();
        choice = readChoice();

        switch (choice) {
        case 1:
            processLatin();
            break;
        case 2:
            processRussian();
            break;
        case 3:
            processDigits();
            break;
        case 4:
            cout << "Завершение работы программы.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}