#include <iostream>

using namespace std;

int main() {
    int inputNumber;
    const string answerMessage = "Введенное число в 16-ричной системе: ";

    cout << "Введите число из промежутка 10 - 15 (включительно) ";
    cin >> inputNumber;

    switch (inputNumber) {
        case 10: cout << answerMessage << hex << inputNumber << endl; break;
        case 11: cout << answerMessage << hex << inputNumber << endl; break;
        case 12: cout << answerMessage << hex << inputNumber << endl; break;
        case 13: cout << answerMessage << hex << inputNumber << endl; break;
        case 14: cout << answerMessage << hex << inputNumber << endl; break;
        case 15: cout << answerMessage << hex << inputNumber << endl; break;
        default: cout << "Введеное значение не из указанного промежутка" << endl;
    };

    return 0;
}