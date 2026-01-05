#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

void taskOne(mt19937& gen)
{
  // Структура для ребенка

  struct ChildForm
  {
    string name = "None";
    string gender = "None";
    double height = 0.0;
  };

  // Создание распределений для дальнейших генераций случайных чисел

  uniform_int_distribution genderDis(0, 1);
  uniform_int_distribution namesDis(0, 9);
  uniform_real_distribution heightDis(130.0, 190.0);

  const vector<string> maleNames = {"Михаил",    "Анатолий", "Геннадий", "Иван", "Дмитрий",
                                    "Александр", "Тимофей",  "Алексей",  "Илья", "Леонтий"};
  const vector<string> femaleNames = {"Елена",     "Александра", "Виктория",  "Юлия",  "Евгения",
                                      "Екатерина", "Елизавета",  "Анастасия", "Диана", "Алиса"};

  constexpr unsigned int totalOfChildren = 20;
  array<ChildForm, totalOfChildren> children; // Список форм

  // Заполним список структур данными
  // Также выведем весь список детей с их данными
  // Высчитаем средний рост мальчиков
  // В цикле раскроем структуру на 3 переменные

  double maleHeightSum = 0.0;
  unsigned int maleChildren = 0;

  cout << endl;
  for (auto& [name, gender, height] : children)
  {
    height = heightDis(gen);
    if (genderDis(gen))
    {
      gender = "male";
      name = maleNames[namesDis(gen)];
      maleHeightSum += height;
      maleChildren++;
    }
    else
    {
      gender = "female";
      name = femaleNames[namesDis(gen)];
    }

    cout << name << " | " << gender << " | " << height << endl;
  }

  if (maleChildren > 0)
    cout << endl << "Средний рост среди " << maleChildren << " мальчиков: " << maleHeightSum / maleChildren << endl;
  else
    cout << endl << "Мальчиков в списке нет" << endl;
}

void taskTwo(mt19937& gen)
{
  // Структуры для окружности

  struct Point
  {
    double x = 0.0;
    double y = 0.0;
  };

  struct Circle
  {
    double radius = 0.0;
    Point center;
  };

  // Распределение для дальнейших генераций координат центра и радиуса

  uniform_real_distribution radiusDis(10.0, 100.0);
  uniform_int_distribution pointsDis(0, 100);

  // Массив структур описывающих окружности

  constexpr unsigned int totalOfCircles = 10;
  array<Circle, totalOfCircles> circles;

  // Заполним элементами массив и выведем окружности

  cout << endl;
  for (auto& [radius, center] : circles)
  {
    radius = radiusDis(gen);
    center.x = pointsDis(gen);
    center.y = pointsDis(gen);

    cout << center.x << " " << center.y << " " << radius << endl;
  }

  // Найдем окружность с максимальным радиусом

  size_t maxIndex = 0;
  for (size_t i = 0; i < totalOfCircles; i++)
    if (circles[i].radius > circles[maxIndex].radius)
      maxIndex = i;

  cout << endl
       << "Координаты окружности с наибольшим радиусом: (" << circles[maxIndex].center.x << ", "
       << circles[maxIndex].center.y << ")" << endl;
}

void taskThree(mt19937& gen)
{
  struct Address
  {
    string street = "None";
    string building = "None";
    unsigned int apartmentsNumber = 0;
  };

  struct PersonForm
  {
    string surname = "None";
    string city = "None";
    Address address;
  };

  constexpr unsigned int totalOfPersons = 10;

  // -1 так как диапазон включает в себя крайнюю правую границу
  uniform_int_distribution apartmentsNumberDis(1, 100);
  uniform_int_distribution addressDis(0, 4);
  uniform_int_distribution<int> surnamesDis(0, totalOfPersons - 1);

  // Константные значения для заполнения массива в дальнейшем

  const vector<string> citiesNames = {"Москва", "Санкт-Петербург", "Ставрополь", "Новосибирск", "Краснодар"};
  const vector<string> surnames = {"Иванов",  "Петров", "Попов",   "Сидоров",  "Смирнов",
                                   "Лебедев", "Козлов", "Морозов", "Кузнецов", "Стрелов"};
  const vector<string> streets = {"Мира", "Бульвар Менделеева", "Невский проспект", "Ленина", "Садовая"};
  const vector<string> buildings = {"26", "1а", "4в", "376", "9/3"};

  array<PersonForm, totalOfPersons> allPersons; // Массив всех людей
  vector<PersonForm> personsLiveInMoscow; // Массив только москвичей

  // Заполнение данными массива

  unsigned int countOfPersonsLiveInMoscow = 0;
  for (PersonForm& person : allPersons)
  {
    person.surname = surnames[surnamesDis(gen)];
    person.city = citiesNames[addressDis(gen)];
    person.address.street = streets[addressDis(gen)];
    person.address.building = buildings[addressDis(gen)];
    person.address.apartmentsNumber = apartmentsNumberDis(gen);

    if (person.city == "Москва")
    {
      // Запишем в массив москвичей жителей проживающих в ней людей

      personsLiveInMoscow.push_back(person);
      countOfPersonsLiveInMoscow++;
    }

    // Вывод списка людей

    cout << "Фамилия: " << person.surname << " | Город: " << person.city << " | Адрес: " << person.address.street
         << ", " << person.address.building << ", квартира: " << person.address.apartmentsNumber << endl;
  }

  cout << endl << "Информация о людях проживающих в Москве:" << endl;
  for (const auto& [surname, city, address] : personsLiveInMoscow)
  {
    cout << "Фамилия: " << surname << " | Город: " << city << " | Адрес: " << address.street << ", " << address.building
         << ", квартира: " << address.apartmentsNumber << endl;
  }
}

void taskFour(mt19937& gen)
{
  struct HotelRoom
  {
    string hotelName = "None";
    string roomCategory = "None";
    unsigned int hotelRoomNumber = 0;
    unsigned int peopleStaying = 0;
    unsigned int price = 0;
  };

  const vector<string> hotelsNames = {"City Hotel Frankfurt", "City Park Hotel", "The Plaza Hotel", "Marina Bay Sands"};
  const vector<string> roomsCategories = {"Эконом", "Стандарт", "Полулюкс", "Люкс"};

  // Распределения для генерации чисел

  uniform_int_distribution roomsNumberDis(1, 100);
  uniform_int_distribution numberOfPeopleDis(1, 5);
  uniform_int_distribution roomPriceDis(1000, 7000);
  uniform_int_distribution roomCategoriesDis(0, 3);
  uniform_int_distribution hotelNamesDis(0, 3);

  // Массив всех номеров отелей

  constexpr unsigned int totalOfRooms = 10;
  array<HotelRoom, totalOfRooms> allRooms;

  // Массив для комнат в отелях в которых есть "city"

  vector<HotelRoom> chosenNamesHotels;

  // Заполняем массив

  cout << endl;
  for (HotelRoom& room : allRooms)
  {
    room.hotelName = hotelsNames[hotelNamesDis(gen)];
    room.roomCategory = roomsCategories[roomCategoriesDis(gen)];
    room.hotelRoomNumber = roomsNumberDis(gen);
    room.peopleStaying = numberOfPeopleDis(gen);
    room.price = roomPriceDis(gen);

    // Перенесем отели из основного списка в дополнительный при условии наличия "city" в названии

    if (room.hotelName.starts_with("City"))
      chosenNamesHotels.push_back(room);

    // Вывод массива
    cout << "Название: " << room.hotelName << " | Класс: " << room.roomCategory << " | Номер: " << room.hotelRoomNumber
         << " | Людей проживает: " << room.peopleStaying << " | Цена: " << room.price << "$" << endl;
  }

  // Сортировка результирующего вектора по номеру комнаты.
  // ranges::sort получает весь контейнер и извлекает итераторы автоматически.
  // Лямбда-компаратор сравнивает поле hotelRoomNumber двух элементов структуры.

  ranges::sort(chosenNamesHotels,
               [](const HotelRoom& a, const HotelRoom& b) { return a.hotelRoomNumber < b.hotelRoomNumber; });

  // Вывод сортированного массива

  cout << endl;
  for (const auto& [hotelName, roomCategory, hotelRoomNumber, peopleStaying, price] : chosenNamesHotels)
  {
    cout << "Название: " << hotelName << " | Класс: " << roomCategory << " | Номер: " << hotelRoomNumber
         << " | Людей проживает: " << peopleStaying << " | Цена: " << price << "$" << endl;
  }
}

void taskFive(mt19937& gen)
{
  struct MountainPeak
  {
    string peakName = "None";
    unsigned int peakHeight = 0;
  };

  const vector<string> peakNames = {"Очень высокий пик",
                                    "Пик чуть пониже",
                                    "Пик еще чуть ниже",
                                    "Совсем маленький пик",
                                    "Совсем не маленький пик",
                                    "Кривой пик",
                                    "Пик?",
                                    "Отвесный пик",
                                    "Плоский пик",
                                    "Четвертый пик",
                                    "Пик 9 и 3/4"};

  uniform_int_distribution peakNamesDis(0, 10);
  uniform_int_distribution peakHeightDis(1000, 5000);

  constexpr unsigned int totalOfPeaks = 20;
  array<MountainPeak, totalOfPeaks> allPeaks;

  // Заполняем массив
  // Сразу посчитаем общую высоту и выведем все пики

  unsigned int heightsTotalSum = 0;

  cout << endl;
  for (auto& [peakName, peakHeight] : allPeaks)
  {
    peakName = peakNames[peakNamesDis(gen)];
    peakHeight = peakHeightDis(gen);

    heightsTotalSum += peakHeight;

    cout << "\"" << peakName << "\" - " << peakHeight << endl;
  }

  cout << endl << "Средняя высота " << totalOfPeaks << " вершин: " << heightsTotalSum / totalOfPeaks << endl;

  ranges::sort(allPeaks, [](const MountainPeak& a, const MountainPeak& b) { return a.peakHeight < b.peakHeight; });

  cout << endl << "Отсортированные по высоте вершины:" << endl;
  for (const auto& [peakName, peakHeight] : allPeaks)
  {
    heightsTotalSum += peakHeight;
    cout << "\"" << peakName << "\" - " << peakHeight << endl;
  }
}

int main()
{
  // Создание генератора

  random_device rd;
  mt19937 gen(rd());

  int userInput;
  cout << "Выберите номер задания:\n"
          "(1 - Анкеты)\n"
          "(2 - Окружность)\n"
          "(3 - Москвичи)\n"
          "(4 - Номера отелей)\n"
          "(5 - Горные вершины)\n";
  cin >> userInput;

  switch (userInput)
  {
  case 1:
    taskOne(gen);
    break;
  case 2:
    taskTwo(gen);
    break;
  case 3:
    taskThree(gen);
    break;
  case 4:
    taskFour(gen);
    break;
  case 5:
    taskFive(gen);
    break;
  default:
    cout << endl << "Выбранного задания нет в списке" << endl;
  }
  return 0;
}
