#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Шаблон для универсальности. T - тип массива, N - размер, size_t - тип данных, хранящий длины
template<typename T, size_t N>
// Будем в функции получать ссылку на массив с типом элементов T и размером N
void arrayInput(T (&arrToFill)[N]) {
  cout << endl << "Заполните массив длинной " << N << " значениями" << endl;
  for (size_t i = 0; i < N; i++) {
    // Пройдем по всем элементам массива
    cout << "Значение элемента " << i + 1 << ": ";
    cin >> arrToFill[i]; // Записываем введенные значения под каждым индексом массива
  }
  cout << endl;
}

void taskOne() {
  // constexpr - константа известная на этапе компиляции
  // size_t - беззнаковый целочисленный тип данных, используемый для представления размеров объектов и индексов
  constexpr size_t arrayLength = 8;
  int taskOneArray[arrayLength]; // Массив размером 8
  arrayInput(taskOneArray); // Передадим ссылку на массив для его заполнения

  double arrayElementsSum = 0; // Сумма элементов
  // Используем ссылку на оригинальные элементы массива просто для того, чтобы избежать копирования
  // (не то что бы это было прям нужно, но почему бы и нет?)
  for (const int &element: taskOneArray) {
    // Пройдем по всем элементам и просуммируем
    arrayElementsSum += element;
  }

  // Вычислим среднее арифметическое во второй строке
  cout << "Сумма всех элементов массива: " << arrayElementsSum <<
      "\nСреднее арифметическое значений массива: " << arrayElementsSum / arrayLength << endl;
}

void taskTwo() {
  constexpr size_t arrayLength = 10; // constexpr - константа известная на этапе компиляции
  int taskTwoArray[arrayLength]; // Массив размером 10
  arrayInput(taskTwoArray); // Заполним массив
  sort(taskTwoArray, taskTwoArray + arrayLength); // Сортируем по возрастанию массив

  // Флаги: найдено ли хоть раз повторяющееся и есть ли дубликат на данный момент
  bool foundDuplicates = false, foundAtLeatOnce = false;
  for (size_t i = 0; i < arrayLength; i++) {
    if (taskTwoArray[i] == taskTwoArray[i + 1]) {
      // Если следующий дубликат
      cout << taskTwoArray[i] << " ";
      foundDuplicates = true, foundAtLeatOnce = true; // Дубль найден
    } else if (foundDuplicates) {
      // Учтем и выведем последнее дублирующееся число последовательности
      cout << taskTwoArray[i] << endl;
      foundDuplicates = false; // Так как дальше в массиве нет одинакового числа
    }
  }
  if (!foundAtLeatOnce) cout << endl << "Дублирующихся членов массива не было найдено";
}

template<typename T, size_t N>
void shiftArray(T (&arrayToShift)[N], T (&shiftedArray)[N], const int arrayLength) {
  int shift; // Длина сдвига

  cout << "Введите сдвиг: ";
  cin >> shift;
  // Так как сдвиг циклический, то будем брать остаток от деления, если сдвиг больше размера массива
  if (fabs(shift) > arrayLength) shift %= arrayLength;

  if (shift < 0) {
    // Сдвиг налево
    shift = arrayLength + shift; // Левый сдвиг это (длина массива - сдвиг)
  }
  // Перепишем значения исходного массива со сдвигом в новый
  for (int i = 0; i < arrayLength; i++) {
    shiftedArray[(i + shift) % arrayLength] = arrayToShift[i];
  }
}

void taskThree() {
  constexpr size_t arrayLength = 10; // constexpr - константа известная на этапе компиляции
  int taskThreeArray[arrayLength], shiftedArray[arrayLength]; // Массивы длиной 10

  arrayInput(taskThreeArray); // Заполним массив
  shiftArray(taskThreeArray, shiftedArray, arrayLength); // Произведем сдвиг массива

  cout << endl << "Исходный массив: ";
  for (const int &element: taskThreeArray) { cout << element << " "; }; // Вывод массива
  cout << endl << "Массив со сдвигом: ";
  for (const int &element: shiftedArray) { cout << element << " "; };
}

int main() {
  int userChoice;
  cout << "Выберите задание:\n"
      "(1 - Сумма и среднее арифметическое)\n"
      "(2 - Поиск повторяющихся элементов)\n"
      "(3 - Циклический сдвиг массива)" << endl;
  cin >> userChoice;

  switch (userChoice) {
    case 1: taskOne();
      break;
    case 2: taskTwo();
      break;
    case 3: taskThree();
      break;
    default: cout << "Выбранного задания нет в списке";
  }
  return 0;
}
