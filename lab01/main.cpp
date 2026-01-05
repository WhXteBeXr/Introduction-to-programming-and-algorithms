#include <iostream>
#include <string>
#include <cmath>
#include <set>

using namespace std;

// Заданаие 0 - посмотреть что выведет программа
void whatWordWouldBe() {
    string A = "jqmspo";
    for (int i = 0; i < A.size(); ++i) {
        A[i] = (A[i] - i) ^ 25;
    }
    cout << A << endl;
}

// Задание 1 - факториал
void factorial() {
    long long fact = 1;
    for (int i = 1; i <= 10; i++) {
        fact *= i;
    }
    cout << fact << endl;
}

// Задание 2 - уточки
void ducks() {
    cout << " _       _      _" << endl;
    cout << ">(.)__ <(.)__ =(.)__" << endl;
    cout << " (___/  (___/  (___/" << endl;
}

// Задание 3 - палиндром
/*bool isPalindrome(const string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

bool containsAllDigits(const string &s) {
    set<char> digits(s.begin(), s.end());
    return digits.size() == 10; // должно быть 0-9
}

int main() {
    long long n = 1000000000; // минимальное 10-значное число
    while (true) {
        string s = to_string(n);
        if (isPalindrome(s) && n % 9 == 0 && containsAllDigits(s)) {
            cout << n << endl;
            break;
        }
        n++;
    }
    return 0;
}*/

// Задание 4.1 - количество слов длинной 10
void wordsOfLengthTen() {
    long long result = pow(3, 10); // 3^10
    cout << result << endl;
}

// Задание 4.2 - вывод 2 + 2
void twoPlusTwo() {
    int a = 1 + 1; // вместо числа 2
    cout << a << " + " << a << " = " << a + a << endl;
}

// Задание 5 - Составить программу вычисления матемитического выражения
void mathMagic() {
    double p, z, x;
    cout << "Введите p, z и x: ";
    cin >> p >> z >> x;

    // Вычисляем Y
    double Y = p + pow(z, 2);

    // Вычисляем Q
    double Q = sin(3 * M_PI / 2 + x) / (x + sqrt(fabs(3 * M_PI / 2 + x)));

    // Вычисляем W
    double W = (pow(sin(x), 2) / (pow(x, 2) - 4)) + (cos(pow(x, 2)) / ((x - 3) * (x - 5)));

    cout << "Y = " << Y << endl;
    cout << "Q = " << Q << endl;
    cout << "W = " << W << endl;
}

// Задание 6 - гипотенуза и катеты
void squareMath() {
    double a, b;
    cout << "Введите катеты a и b: ";
    cin >> a >> b;

    double c = sqrt(a * a + b * b); // гипотенуза
    double S = 0.5 * a * b;         // площадь

    cout << "Гипотенуза = " << c << endl;
    cout << "Площадь = " << S << endl;
}

int main() {
    int choice;

    cout << "Выберите задание для исполнения кода:"
            "\n(1 - файториал)"
            "\n(2 - уточки)"
            "\n(3 - \"2 + 2\")"
            "\n(4 - вычисление математического выражения)"
            "\n(5 - гипотенуза и площадь)"
            "\n(6 - какое слово будет?)" << endl;

    cin >> choice;
    switch (choice) {
        case 1:
            factorial();
            break;
        case 2:
            ducks();
            break;
        case 3:
            cout << "Задание 3.1 - количество слов длинной 10" << endl;
            wordsOfLengthTen();
            cout << "\nЗадание 3.2 - \"2 + 2\"" << endl;
            twoPlusTwo();
            break;
        case 4:
            mathMagic();
            break;
        case 5:
            squareMath();
            break;
        case 6:
            whatWordWouldBe();
            break;
        default:
            cout << "Такого в выборе не было";
            break;
    }

    return 0;
}