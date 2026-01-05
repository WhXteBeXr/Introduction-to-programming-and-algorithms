#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

using namespace std;

// Функция для ввода и присваивания значений переменным через ссылку

template <typename T>
void variablesInput(T& elementA, T& elementB)
{
  cout << endl << "Введите значение переменной a: ";
  cin >> elementA;
  cout << "Введите значение переменной b: ";
  cin >> elementB;
}

void taskOne()
{
  int userInputA;
  int userInputB;
  int* pointerUserInputA = &userInputA;
  int* pointerUserInputB = &userInputB;

  variablesInput(userInputA, userInputB);

  cout << endl << "Введенные значения: а = " << userInputA << ", b = " << userInputB << endl;

  // Мультипликатор для переменных

  constexpr int multiplicator = 2;

  // Увеличим с помощью указателей значения переменных в n раз

  *pointerUserInputA *= multiplicator;
  *pointerUserInputB *= multiplicator;

  cout << "Переменные умноженные на " << multiplicator << " с помощью указателей теперь равняются: а = " << userInputA
       << ", b = " << userInputB << endl;

  // Меняем местами указатели через временную переменную

  const int tempPointer = *pointerUserInputA;
  *pointerUserInputA = *pointerUserInputB;
  *pointerUserInputB = tempPointer;

  cout << "Переменные поменянные местами с помощью указателей: а = " << userInputA << ", b = " << userInputB << endl;
}

void taskTwo()
{
  // Решение с сырыми указателями и ручным выделением памяти

  // Опишем два указателя и выделим память для двух int

  // int* pointerVariableA = nullptr;
  // int* pointerVariableB = nullptr;
  //
  // pointerVariableA = new int;
  // pointerVariableB = new int;

  // Решение в c++ style с помощью make unique, он мне больше нравится :)

  const auto pointerVariableA = make_unique<int>();
  const auto pointerVariableB = make_unique<int>();

  variablesInput(*pointerVariableA, *pointerVariableB);

  constexpr int divider = 2; // Делитель числа

  *pointerVariableA /= divider;
  cout << endl
       << "Переменные после деления первой на " << divider << ": a = " << *pointerVariableA
       << ", b = " << *pointerVariableB << endl;

  /*
  В задании сказано создать ссылки на целочисленные переменные,
  из-за этого при делении будет откинута дробная часть.

  Решением данной проблемы могло быть:
  auto variableA = make_unique<double>();
  auto variableB = make_unique<double>();

  В паре с шаблоном функции variablesInput() - template <typename T>
  */

  /*
  Для решения с ручным выделением памяти

  delete pointerVariableA;
  delete pointerVariableB;
  pointerVariableA = nullptr;
  pointerVariableB = nullptr;
  */
}

void taskThree()
{
  const auto pointerDynamicArray = make_unique<vector<double>>();

  cout << endl << "Значения элементов массива: ( ";
  for (int i = 1; i < 30; i++)
  {
    double element = i * 0.1; // 0.1 - шаг между элементами
    pointerDynamicArray->push_back(element);
    cout << element;

    if ((i + 1) < 30)
      cout << ", ";
    else
      cout << " )" << endl;
  }

  vector<unsigned int> elementsIds; // Тут будем хранить индексы элементов меньше 1
  double arrayElementsProduct = 1;
  unsigned int elementsLessThenOne = 0;

  for (unsigned int i = 0; i < pointerDynamicArray->size(); i++)
  {
    if ((*pointerDynamicArray)[i] < 1)
    {
      elementsLessThenOne++;
      arrayElementsProduct *= (*pointerDynamicArray)[i];
      elementsIds.push_back(i);
    }
  }

  cout << endl << "id элементов < 1:" << endl;
  for (const unsigned int& id : elementsIds)
    cout << "id: " << id << ". Элемент: " << (*pointerDynamicArray)[id] << endl;

  cout << endl
       << "Элементов < 1 всего: " << elementsLessThenOne
       << ". Произведение всех этих элементов: " << arrayElementsProduct << endl;
}

void taskFour()
{
  // Генератор для дальнейшего заполнения числами массива

  random_device rd;
  mt19937 gen(rd());

  uniform_real_distribution<double> elementsDis(-100, 100);

  constexpr size_t totalOfElements = 15;
  const auto pointerNumbersArray = make_unique<array<double, totalOfElements>>();
  const auto pointerPositiveArray = make_unique<vector<double>>();

  // Заполним массив рандомными значениями

  cout << endl << "Исходный массив: ( ";
  for (double& element : *pointerNumbersArray)
  {
    element = elementsDis(gen);
    cout << element << " ";
  }
  cout << ")" << endl;

  // Запишем в новый массив только положительные элементы умноженные на multiplicator и выведем его

  constexpr int multiplicator = 5;

  cout << "Новый массив положительных чисел: ( ";
  for (const double& element: *pointerNumbersArray)
  {
    if (element > 0)
    {
      pointerPositiveArray->push_back(element * multiplicator);
      cout << element << " ";
    }
  }
  cout << ")" << endl;

  // Сортируем по возрастанию и выводим массив положительных чисел

  ranges::sort(*pointerPositiveArray);

  cout << "Отсортированный по возрастанию массив положительных чисел умноженных на " << multiplicator << ": ( ";
  for (const double& element : *pointerPositiveArray)
    cout << element << " ";
  cout << ")" << endl;
}

int main()
{
  int userChoice;
  cout << "Выберите задания:\n"
          "(1 - Обмен переменных своими значениями и умножение элементов)\n"
          "(2 - Изменение значения переменной по указателю в n раз)\n"
          "(3 - Элементы < 1)\n"
          "(4 - Массив положительных чисел)"
       << endl;
  cin >> userChoice;

  switch (userChoice)
  {
  case 1:
    taskOne();
    break;
  case 2:
    taskTwo();
    break;
  case 3:
    taskThree();
    break;
  case 4:
    taskFour();
    break;
  default:
    cout << endl << "Выбранного задания нет в списке" << endl;
  }

  return 0;
}
