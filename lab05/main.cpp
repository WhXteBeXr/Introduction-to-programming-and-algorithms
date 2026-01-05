#include <iostream>
#include <cmath>

using namespace std;

double taskOnePointTwoNSum(const int nTermsCount) {
    // Для этой задачи запрещены cmath и if else
    double answerSum = 0, parityIndex = -1; // Переменные ответа и текущей уже посчитанной степени числа -1

    for (int i = 1; i <= nTermsCount; i++) {
        answerSum += parityIndex * (i + 1) / (i * i * i + 1); // Преобразованная формула

        parityIndex *= -1; // Возводим в степень (-1)^n для следующей итерации цикла
    }
    return answerSum;
}

double taskOnePointOne(const int nTermsCount) {
    double answerSum = 0; // переменная для в будущем вычисленной суммы

    for (int i = 1; i <= nTermsCount; i++) {
        answerSum += 1 / (pow(i, 2) + 10); // Преобразованная формула
    }
    return answerSum;
}

double taskOnePointTwoEpsSum(const double epsilon) {
    // Для этой задачи запрещены cmath и if else
    double answerSum = 0, parityIndex = -1, difference = 1, previousSum = 0;
    int i = 1; // n из данной формулы

    // Будем выполнять цикл до тех пор, пока модель разности
    while (difference > epsilon || -difference > epsilon) {
        answerSum += parityIndex * (i + 1) / (i * i * i + 1); // Преобразованная формула

        i++;
        parityIndex *= -1; // Возводим в степень (-1)^n для следующей итерации цикла
        difference = answerSum - previousSum; // Подсчет разницы для дальнейшей проверки на то, дошли ли мы до эпсилона
        previousSum = answerSum; // Запоминаем текущее значение для следующего подсчета
    }
    return answerSum;
}

double taskOnePointThreeNSum(const double x, const int nTermsCount) {
    /*Запрещается использование условных операторов if и «? :», функции pow(),
     *вторичное вычисление факториала и возведение в степень на каждом шаге
     *итерации (использовать рекуррентные соотношения n!=n·(n-1)!, an =a·an-1).*/

    double answerSum = 0, factorial = 1, parityIndex = -1, numberPower = 3;

    for (int i = 1; i <= nTermsCount; i++) {
        answerSum += x * (parityIndex * (i + 1) / (numberPower * factorial)); // x * a(n)

        parityIndex *= -1; // -1 из-ка константы в исходной формуле
        numberPower *= 3; // 3 из-за константы в исходной формуле
        factorial *= (i + 1); // подсчет факториала
    }
    return answerSum;
}

double taskOnePointThreeEpsSum(const double x, const double epsilon) {
    /*Запрещается использование условных операторов if и «? :», функции pow(),
     *вторичное вычисление факториала и возведение в степень на каждом шаге
     *итерации (использовать рекуррентные соотношения n!=n·(n-1)!, an =a·an-1).*/

    double answerSum = 0, previousSum = 0, difference = 1, factorial = 1, parityIndex = -1, numberPower = 3;
    int i = 1; // n из данной формулы

    while (difference > epsilon || -difference > epsilon) {
        answerSum += x * (parityIndex * (i + 1) / (numberPower * factorial));

        i++;
        parityIndex *= -1; // Возводим в степень (-1)^n для следующей итерации цикла
        numberPower *= 3; // 3 из-за константы в исходной формуле
        factorial *= (i + 1); // подсчет факториала
        difference = answerSum - previousSum; // Подсчет разницы для дальнейшей проверки на то, дошли ли мы до эпсилона
        previousSum = answerSum; // Запоминаем текущее значение для следующего подсчета
    }
    return answerSum;
}

void taskTwoPointOneFindAll() {
    int currentInput; // Переменная будет содержать поочередно введенные члены последовательности
    int maxOddElement = -999, minEvenElement = 999, maxSequenceElement = -999,
            maxElementPosition = 0, minElementPosition = 0, currentElementPosition = 1;
    // Считать позицию элемента будем со значения 1
    // Малые и большие числа присвоены для того, чтобы сравнения в дальнейшем выполнялись корректно

    while (true) {
        cout << "Введите член последовательности: ";
        cin >> currentInput;

        if (currentInput == 0) break; // Конец последовательности - 0

        if (currentInput >= maxSequenceElement) maxSequenceElement = currentInput;
        // >= из-за условия "напечатать в обратном порядке". Мы при равенстве будем брать значение
        // стоящее ближе к концу последовательности, из-за это в переменной будет содержаться число,
        // которые мы сможем напечатать и при этом технически оно будет являться максимальным с конца

        if ((currentInput < minEvenElement) && (currentInput % 2 == 0)) {
            // Минимальный четный элемент
            minEvenElement = currentInput;
            minElementPosition = currentElementPosition;
        } else if ((currentInput > maxOddElement) && (currentInput % 2 != 0)) {
            // Максимальный нечетный элемент
            maxOddElement = currentInput;
            maxElementPosition = currentElementPosition;
        }
        currentElementPosition++; // Двигаем текущий индекс
    }
    cout << endl << "Максимальный элемент последовательности с конца: " << maxSequenceElement << endl;

    cout << "Максимальный нечетный элемент: " << maxOddElement << ", позиция этого элемента: " << maxElementPosition
            << endl << "Минимальный четный элемент: " << minEvenElement << ", позиция этого элемента: " <<
            minElementPosition << endl;
}

bool isPrime(const int currentNum) {
    if (currentNum <= 1) return false; // 1 не простое

    for (int i = 2; i <= sqrt(currentNum); i++) {
        // Будем проверять делится ли число на какой-либо до его квадратного корня
        if (currentNum % i == 0) return false;
    }
    return true; // Делители не были найдены, число простое
}

void taskTwoPointTwoMaxNumSequence() {
    int currentInput;
    int maxLengthSequenceWithCondition = 0, currentLengthWithCondition = 0,
            maxLengthSequenceWithoutCondition = 0, currentLengthWithoutCondition = 0;

    while (true) {
        cout << "Введите член последовательности: ";
        cin >> currentInput;

        if (isPrime(currentInput)) {
            currentLengthWithCondition++; // Добавляем длину, если число простое
            // Последовательность нечетных чисел оборвалась, сделаем проверку, была ли она максимальной длины
            if (currentLengthWithoutCondition > maxLengthSequenceWithoutCondition) {
                    maxLengthSequenceWithoutCondition = currentLengthWithoutCondition;
            }
            currentLengthWithoutCondition = 0; // Обнулим текущую длину для последовательности не простых чисел
        } else {
            currentLengthWithoutCondition++; // Добавляем длину, если число не простое
            // Последовательность четных чисел оборвалась, сделаем проверку, была ли она максимальной длины
            if (currentLengthWithCondition > maxLengthSequenceWithCondition) {
                maxLengthSequenceWithCondition = currentLengthWithCondition;
            }
            currentLengthWithCondition = 0; // Обнулим текущую длину для последовательности простых чисел
        }
        if (currentInput == 0) {
            if (currentLengthWithoutCondition > maxLengthSequenceWithoutCondition) {
                maxLengthSequenceWithoutCondition = currentLengthWithoutCondition - 1;
                // -1 так как 0 не является частью последовательности

                // Делаем дополнительную проверку по завершении последовательности, так как в случае,
                // если isPrime вернет значение false, то максимальная длина последовательности
                // не удовлетворяющей условию может быть не записана в переменную
            }
            break;
        }
    }
    cout << endl << "Максимальная длина последовательности удовлетворяющей условию Q (число является простым): "
            << maxLengthSequenceWithCondition << endl <<
            "Максимальная длина последовательности не удовлетворяющей условию Q (число не является простым): "
            << maxLengthSequenceWithoutCondition << endl;
}

int enterNTermsCount() {
    int nTermsCount; // Количество членов последовательности
    cout << "Введите число n для которых будет посчитана сумма в func(int n): ";
    cin >> nTermsCount;

    return nTermsCount;
}

double enterEpsilon() {
    double epsilon; // Точность эпсилон
    cout << "Введите значение эпсилона для func(double eps): ";
    cin >> epsilon;

    return epsilon;
}

int enterX() {
    int x;
    cout << "Введите значение X для func(double x): ";
    cin >> x;

    return x;
}

int main() {
    int taskChoice;
    // Для избежания повторений
    const string answerNString = "Посчитанная сумма для n членов: ",
            answerEpsString = "Посчитанная сумма с точностью до эпсилона: ",
            answerMaxElementString = "Максимальное число с конца в последовательности: ";

    cout << "Выберите задание:\n"
            "1 - (задание 1.1): сумма для n членов\n"
            "2 - (задание 1.2): сумма для n членов и сумма для точности эпсилона\n"
            "3 - (задание 1.3): сумма для n членов и сумма для точности эпсилона\n"
            "4 - (задание 2.1): найти максимальные числа и их индексы\n"
            "5 - (задание 2.2): максимальное количество идущих подряд" << endl;
    cin >> taskChoice;

    switch (taskChoice) {
        /*Сразу в выводе будем вызывать ф-и подсчета для заданий,
         *в которые будем передавать ф-и, которые запросят ввод у пользователя*/
        case 1: {
            // (задание 1.1)
            int nTermsCount = enterNTermsCount();

            cout << endl << answerNString << taskOnePointOne(nTermsCount) << endl;
            break;
        }
        case 2: {
            // (задание 1.2)
            int nTermsCount = enterNTermsCount();
            double epsilon = enterEpsilon();

            cout << endl << answerNString << taskOnePointTwoNSum(nTermsCount)
                    << endl << answerEpsString << taskOnePointTwoEpsSum(epsilon) << endl;
            break;
        }
        case 3: {
            // (задание 1.3)
            int x = enterX();
            int nTermsCount = enterNTermsCount();
            double epsilon = enterEpsilon();

            cout << endl << answerNString << taskOnePointThreeNSum(x, nTermsCount)
                    << endl << answerEpsString << taskOnePointThreeEpsSum(x, epsilon) << endl;
            break;
        }
        case 4: {
            // (задание 2.1)
            taskTwoPointOneFindAll();
            break;
        }
        case 5: {
            // (задание 2.2)
            taskTwoPointTwoMaxNumSequence();
            break;
        }
        default: cout << "Выбранного задания не существует" << endl;
    }
}
