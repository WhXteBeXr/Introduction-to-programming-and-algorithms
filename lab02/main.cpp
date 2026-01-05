#include <iostream>
using namespace std;

void task1() {
    int X, Y, Z;
    cout << "Введите значения X Y Z через пробел "
            "\n(программа выведет порядковый номер числа, если то равно нулю)" << endl;
    cin >> X >> Y >> Z;

    if (X == 0) cout << "X (1)" << endl;
    else if (Y == 0) cout << "Y (2)" << endl;
    else if (Z == 0) cout << "Z (3)" << endl;
}

void task2() {
    int year;
    cout << "Введите год: ";
    cin >> year;

    cout << "\nВисокосный ли введенный год?" << endl;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << "YES";
    } else {
        cout << "NO";
    };
}

int main() {
    int inputChoice;
    cout << "Выберите задание: "
            "\n(1 - порядковый номер)"
            "\n(2 - високосный ли год?)" << endl;
    cin >> inputChoice;

    switch (inputChoice) {
        case 1: task1(); break;
        case 2: task2(); break;
        default: cout << "Такого выбора не было";
    }
}
