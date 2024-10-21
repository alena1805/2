#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Класс для представления имени
class Name {
public:
    std::string surname;      // Фамилия
    std::string first_name;   // Имя
    std::string patronymic;   // Отчество

    // Конструктор для создания имени только с именем
    Name(const std::string& first_name) : first_name(first_name) {}

    // Конструктор для создания имени с именем и фамилией
    Name(const std::string& first_name, const std::string& surname) 
        : first_name(first_name), surname(surname) {}

    // Конструктор для создания полного имени с фамилией, именем и отчеством
    Name(const std::string& surname, const std::string& first_name, const std::string& patronymic) 
        : surname(surname), first_name(first_name), patronymic(patronymic) {}

    // Метод для получения строкового представления имени
    std::string toString() const {
        std::ostringstream oss; // Используем строковый поток для формирования строки
        if (!surname.empty()) oss << surname << " "; // Добавляем фамилию, если она не пустая
        if (!first_name.empty()) oss << first_name;   // Добавляем имя, если оно не пустое
        if (!patronymic.empty()) oss << " " << patronymic; // Добавляем отчество, если оно не пустое
        return oss.str(); // Возвращаем сформированную строку
    }
};

// Класс для представления дома
class House {
public:
    int floors;  // Количество этажей в доме

    // Конструктор для создания дома с заданным количеством этажей
    House(int floors) : floors(floors) {}

    // Метод для получения строкового представления дома с учетом правил русского языка
    std::string toString() const {
        // Формируем строку в зависимости от количества этажей
        if (floors % 10 == 1 && floors % 100 != 11) {
            return "дом с " + std::to_string(floors) + " этажом"; // 1 этаж
        } else if (2 <= floors % 10 && floors % 10 <= 4 && !(12 <= floors % 100 && floors % 100 <= 14)) {
            return "дом с " + std::to_string(floors) + " этажами"; // 2-4 этажа
        } else {
            return "дом с " + std::to_string(floors) + " этажами"; // 5 и более этажей
        }
    }
};

// Класс для представления отдела
class Department {
public:
    std::string name;      // Название отдела
    std::string chief;     // Начальник отдела
    std::vector<std::string> employees;  // Список сотрудников отдела

    // Конструктор для создания отдела с названием и начальником
    Department(const std::string& name, const std::string& chief)
        : name(name), chief(chief) {}

    // Метод для добавления сотрудника в отдел
    void addEmployee(const std::string& employeeName) {
        employees.push_back(employeeName); // Добавляем имя сотрудника в вектор сотрудников
    }

    // Метод для вывода списка сотрудников отдела
    void listEmployees() const {
        std::cout << "Сотрудники отдела " << name << ":n"; // Выводим заголовок списка сотрудников
        for (const auto& emp : employees) { // Проходим по всем сотрудникам
            std::cout << "- " << emp << "n"; // Выводим имя каждого сотрудника
        }
    }
};

// Класс для представления сотрудника
class Employee {
public:
    Name name;             // Имя сотрудника (объект класса Name)
    Department* department; // Указатель на отдел, в котором работает сотрудник

    // Конструктор для создания сотрудника с именем и указателем на отдел
    Employee(const Name& name, Department* department)
        : name(name), department(department) {
        department->addEmployee(name.toString()); // Добавляем сотрудника в отдел при создании
    }

    // Метод для получения строкового представления сотрудника
    std::string toString() const {
        // Проверяем, является ли сотрудник начальником отдела и формируем соответствующую строку
        if (department->chief == name.toString()) {
            return name.toString() + " начальник отдела " + department->name; // Начальник отдела
        } else {            return name.toString() + " работает в отделе " + department->name +
                   ", начальник которого " + department->chief; // Обычный сотрудник
        }
    }
};

// Класс для представления дроби
class Fraction {
public:
    int numerator;   // Числитель дроби
    int denominator; // Знаменатель дроби

    // Конструктор для создания дроби с числителем и знаменателем
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    // Метод для получения строкового представления дроби
    std::string toString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator); // Формируем строку вида "числитель/знаменатель"
    }

    // Метод для сложения дробей
    Fraction sum(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
        // Возвращаем новую дробь, полученную в результате сложения дробей
    }

    // Метод для вычитания целого числа из дроби
    Fraction minus(int value) const {
        return Fraction(numerator - value * denominator, denominator); 
        // Возвращаем новую дробь после вычитания целого числа из числителя
    }

    // Метод для умножения дробей
    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
        // Возвращаем новую дробь, полученную в результате умножения дробей
    }

    // Метод для деления дробей
    Fraction divide(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
        // Возвращаем новую дробь, полученную в результате деления дробей
    }
};

int main() {
    // Создание имен с использованием различных конструкторов класса Name
    Name cleopatra("Клеопатра"); // Имя без фамилии и отчества
    Name pushkin("Александр", "Сергеевич"); // Имя и фамилия без отчества
    Name mayakovsky("Маяковский", "Владимир"); // Имя и фамилия без отчества
    Name bonifatievich("Бонифатьевич", "Христофор"); // Имя и фамилия без отчества

    // Вывод имен на экран с использованием метода toString()
    std::cout << cleopatra.toString() << std::endl;
    std::cout << pushkin.toString() << std::endl;
    std::cout << mayakovsky.toString() << std::endl;
    std::cout << bonifatievich.toString() << std::endl;

    // Создание домов с различным количеством этажей с использованием класса House
    House house1(1);  // Один этаж
    House house2(5);  // Пять этажей
    House house3(23); // Двадцать три этажа

    // Вывод информации о домах на экран с использованием метода toString()
    std::cout << house1.toString() << std::endl;
    std::cout << house2.toString() << std::endl;
    std::cout << house3.toString() << std::endl;

    // Создание отдела IT и указание начальника отдела
    Department it_department("IT", "Козлов");
    
    // Создание сотрудников и добавление их в отдел IT через конструктор Employee
    Employee petrov(Name("Петров"), &it_department);
    Employee kozlov(Name("Козлов"), &it_department);
    Employee sidorov(Name("Сидоров"), &it_department);

    // Вывод информации о каждом сотруднике на экран с использованием метода toString()
    std::cout << petrov.toString() << std::endl;
    std::cout << kozlov.toString() << std::endl;
    std::cout << sidorov.toString() << std::endl;

    // Вывод списка сотрудников отдела IT на экран с использованием метода listEmployees()
    it_department.listEmployees();

    // Примеры использования класса Fraction для работы с дробями
    Fraction f1(1, 3);   // Первая дробь: 1/3
    Fraction f2(2, 3);   // Вторая дробь: 2/3
    Fraction f3(1, 2);   // Третья дробь: 1/2

    // Примеры использования методов класса Fraction для выполнения операций над дробями
    Fraction result1 = f1.multiply(f2);  // Умножение первой и второй дробей
    Fraction result2 = f1.sum(f2).divide(f3).minus(5);  // Сложение двух дробей, деление на третью и вычитание целого числа
        // Вывод результатов операций с дробями на экран с использованием метода toString()
    std::cout << f1.toString() << " * " << f2.toString() << " = " << result1.toString() << std::endl;
    std::cout << "Результат f1.sum(f2).divide(f3).minus(5): " << result2.toString() << std::endl;

    return 0; // Завершение программы
}
