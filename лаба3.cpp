#include <iostream>
#include <stdexcept>
#include <string>

// Класс для представления дома
class House {
private:
    int floors; // Количество этажей в доме
public:
    // Конструктор класса House с параметром по умолчанию
    House(int floors = 0) : floors(floors) {}

    // Метод для получения строкового представления дома
    std::string toString() const {
        std::string ending; // Переменная для окончания слова "этаж"
        int lastDigit = floors % 10; // Последняя цифра количества этажей
        int lastTwoDigits = floors % 100; // Последние две цифры количества этажей

        // Определяем правильное окончание в зависимости от количества этажей
        if (lastDigit == 1 && lastTwoDigits != 11) {
            ending = "этаж"; // Один этаж
        } else if ((lastDigit >= 2 && lastDigit <= 4) && (lastTwoDigits < 12 || lastTwoDigits > 14)) {
            ending = "этажа"; // Два, три или четыре этажа
        } else {
            ending = "этажей"; // Пять и более этажей
        }
        return "Дом с " + std::to_string(floors) + " " + ending; // Возвращаем строку с информацией о доме
    }
};

// Класс для представления дробей
class Fraction {
private:
    int numerator;   // Числитель
    int denominator; // Знаменатель

    // Метод для упрощения дроби
    void simplify() {
        int gcd = this->gcd(numerator, denominator); // Находим НОД
        numerator /= gcd;                           // Делим числитель на НОД
        denominator /= gcd;                         // Делим знаменатель на НОД
        if (denominator < 0) {                      // Если знаменатель отрицательный
            numerator = -numerator;                 // Меняем знак числителя и знаменателя
            denominator = -denominator;
        }
    }

    // Метод для нахождения НОД (наибольший общий делитель)
    int gcd(int a, int b) const {
        return b == 0 ? a : gcd(b, a % b); // Рекурсивный алгоритм Евклида
    }
public:
    // Конструктор класса Fraction
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) { // Проверка на деление на ноль
            throw std::invalid_argument("Знаменатель не может быть равен нулю");
        }
        simplify(); // Упрощаем дробь сразу после создания
    }

    // Метод для сложения дробей
    Fraction sum(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    // Метод для вычитания дробей
    Fraction minus(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    // Метод для умножения дробей
    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Метод для деления дробей
    Fraction div(const Fraction& other) const {
        if (other.numerator == 0) { // Проверка на деление на ноль
            throw std::invalid_argument("Деление на ноль");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Метод для получения строкового представления дроби
    std::string toString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator); // Возвращаем строку в формате "числитель/знаменатель"
    }
};

// Предварительное объявление класса Employee
class Employee;

// Класс для представления отдела
class Department {
private:
    std::string title;   // Название отдела
    Employee* manager;   // Указатель на менеджера отдела
public:
    // Конструктор класса Department
    Department(const std::string& title, Employee* manager)
        : title(title), manager(manager) {}

    std::string getTitle() const { return title; }  // Метод для получения названия отдела
    Employee* getManager() const { return manager; } // Метод для получения менеджера отдела
    void setManager(Employee* newManager) { manager = newManager; } // Метод для установки нового менеджера
};

// Класс для представления сотрудника
class Employee {
private:
    std::string name;      // Имя сотрудника
    Department* department; // Указатель на отдел, в котором работает сотрудник
public:
    // Конструктор класса Employee
    Employee(const std::string& name, Department* department)
        : name(name), department(department) {}

    std::string getName() const { return name; } // Метод для получения имени сотрудника

    // Метод для получения строкового представления сотрудника
    std::string toString() const {
        if (department->getManager() == this) { // Если сотрудник является менеджером отдела
            return name + " начальник отдела " + department->getTitle();
        } else { // Если сотрудник не является менеджером
            return name + " работает в отделе " + department->getTitle() +
                   ", начальник которого " + department->getManager()->getName();
        }
    }
};

int main() {
    // Работа с домами
    House house1(1);  // Создаем дом с 1 этажом
    House house2(5);  // Создаем дом с 5 этажами
    House house3(23); // Создаем дом с 23 этажами

    std::cout << house1.toString() << std::endl; // Вывод информации о первом доме
    std::cout << house2.toString() << std::endl; // Вывод информации о втором доме
    std::cout << house3.toString() << std::endl; // Вывод информации о третьем доме

    // Работа с дробями
    Fraction f1(1, 3);  // Создаем дробь 1/3
    Fraction f2(2, 3);  // Создаем дробь 2/3
    Fraction f3(1, 2);  // Создаем дробь 1/2

    // Пример сложения двух дробей
    Fraction resultSum = f1.sum(f2); 
    std::cout << f1.toString() << " + " << f2.toString() << " = " << resultSum.toString() << std::endl;

    // Пример вычитания двух дробей
    Fraction resultMinus = f1.minus(f2);
    std::cout << f1.toString() << " - " << f2.toString() << " = " << resultMinus.toString() << std::endl;

    // Пример умножения двух дробей
    Fraction resultMultiply = f1.multiply(f2); // Умножаем дроби f1 и f2
    std::cout << f1.toString() << " * " << f2.toString() << " = " << resultMultiply.toString() << std::endl; // Выводим результат умножения
    
    // Пример деления двух дробей
    Fraction resultDiv = f1.div(f2); // Делим дробь f1 на дробь f2
    std::cout << f1.toString() << " / " << f2.toString() << " = " << resultDiv.toString() << std::endl; // Выводим результат деления
    
    // Вывод результата сложения и деления дробей с последующим вычитанием
    Fraction five(5, 1); // Создаем дробь 5/1
    Fraction resultComplex = f1.sum(f2).div(f3).minus(five); // Сначала складываем f1 и f2, затем делим на f3 и вычитаем 5
    std::cout << "Результат f1.sum(f2).div(f3).minus(5): " << resultComplex.toString() << std::endl; // Выводим итоговый результат
    
    // Создаем отдел IT
    Department itDepartment("IT", nullptr); // Инициализируем отдел IT без менеджера
    
    // Создаем сотрудников
    Employee petrov("Петров", &itDepartment); // Создаем сотрудника Петрова в IT отделе
    Employee kozlov("Козлов", &itDepartment); // Создаем сотрудника Козлова в IT отделе
    Employee sidorov("Сидоров", &itDepartment); // Создаем сотрудника Сидорова в IT отделе
    
    // Назначаем Козлова начальником IT отдела
    itDepartment.setManager(&kozlov); // Устанавливаем Козлова менеджером отдела IT
    
    // Выводим текстовое представление сотрудников
    std::cout << petrov.toString() << std::endl; // Выводим информацию о Петрове
    std::cout << kozlov.toString() << std::endl; // Выводим информацию о Козлове
    std::cout << sidorov.toString() << std::endl; // Выводим информацию о Сидорове
    
    return 0; // Завершение программы
}
