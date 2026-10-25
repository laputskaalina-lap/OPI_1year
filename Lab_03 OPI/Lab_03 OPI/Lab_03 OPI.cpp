#include <iostream>

// LaputskaAlina2009
// Windows-1251: 4C 61 70 75 74 73 6B 61 41 6C 69 6E 61 32 30 30 39
// UTF-8:        4C 61 70 75 74 73 6B 61 41 6C 69 6E 61 32 30 30 39
// UTF-16:       004C 0061 0070 0075 0074 0073 006B 0061 0041 006C 0069 006E 0061 0032 0030 0030 0039

// ЛапутькоАлина2009
// Windows-1251: CB E0 EF F3 F2 FC EA EE C0 EB E8 ED E0 32 30 30 39
// UTF-8:        D0 9B D0 B0 D0 BF D1 83 D1 82 D1 8C D0 BA D0 BE D0 90 D0 BB D0 B8 D0 BD D0 B0 32 30 30 39
// UTF-16:       041B 0430 043F 0443 0442 044C 043A 043E 0410 043B 0438 043D 0430 0032 0030 0030 0039

// Лапутько2009Alina
// Windows-1251: CB E0 EF F3 F2 FC EA EE 32 30 30 39 41 6C 69 6E 61
// UTF-8:        D0 9B D0 B0 D0 BF D1 83 D1 82 D1 8C D0 BA D0 BE 32 30 30 39 41 6C 69 6E 61
// UTF-16:       041B 0430 043F 0443 0442 044C 043A 043E 0032 0030 0030 0039 0041 006C 0069 006E 0061

int main()
{
    int number = 0x12345678;
    char hello[] = "Hello, ";
    char lfie[] = "LaputskaAlina2009";
    char rfie[] = "ЛапутькоАлина2009";
    char lr[] = "Лапутько2009Alina";

    wchar_t Lfie[] = L"LaputskaAlina2009";
    wchar_t Rfie[] = L"ЛапутькоАлина2009";
    wchar_t LR[] = L"Лапутько2009Alina";

    std::cout << hello << lfie << std::endl;
    return 0;
}
