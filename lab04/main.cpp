#include <iostream>
#include <numbers>
#include <cmath>
#include <string>

using namespace std;

void task1() {
    cout << "Введите число:" << endl;
    string strNumber;
    cin >> strNumber;

    for (int i = strNumber.length() - 1; i >= 0; i--) {
        cout << strNumber[i] << " ";
    }
}

void task2() {
    double borderA, borderB, pointsN;

    cout << "Введите границу a и b: ";
    cin >> borderA >> borderB;

    cout << "Введите количество точек для интервала [a, b]: ";
    cin >> pointsN;

    double step = (borderB -borderA) / (pointsN - 1);

    for (int i = 0; i < pointsN; i++) {
        double currentPoint = borderA + i * step;
        double mathResY = 5 * (1 - exp(-0.5 * currentPoint)) * cos(pow(2, numbers::pi) * currentPoint);
        cout << mathResY << endl;
    }
}

void task3() {
    int currentMaxInt = -999, maxLength = -999, currentLength = 0;
    int currentInput, previousInput, nextInput;

    cout << "Введите последовательность оканчивающуюся 0 ниже:" << endl;
    cin >> previousInput >> currentInput;
    // Получим первое значение и не будем ничего с ним делать, так как оно может быть локальным максимумом по условию
    while (true) {
        cin >> nextInput;

        if (nextInput == 0) {
            cout << "Максимальное расстояние между локальными максимумами: " << maxLength << endl;
            break;
        }

        if (currentInput > currentMaxInt) {
            currentMaxInt = currentInput; // Замена максимума
            currentLength = 0; // Если сменился максимум, то обнуляем длину
        }

        if (currentInput < currentMaxInt) currentLength++;

        if ((currentInput == currentMaxInt) && (currentLength > maxLength)) {
            maxLength = currentLength;
            currentLength = 0;
        }

        if (currentInput > currentMaxInt) {
            currentMaxInt = currentInput; // Замена текущего максимального числа
            currentLength = 0; // Обнуление длины из-за смены предыдущего максимального значения
            maxLength = 0;
            // Обнуление максимума из-за того, что он был таковым лишь для предыдущих максимальных значений
        }

        previousInput = currentInput;
        currentInput = nextInput;
    }
}

int main() {
    int choice;

    cout << "Выберите задание 1 - 3 ";
    cin >> choice;

    switch (choice) {
        case 1: task1();
            break;
        case 2: task2();
            break;
        case 3: task3();
            break;
        default: cout << "Введен не верный вариант";
    }

    return 0;
}
