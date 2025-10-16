#include "styles.h"

#ifdef max
#undef max
#endif

void pause() {
    setConsoleColor(7);
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clearScreen() {
    system("cls");
}

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}