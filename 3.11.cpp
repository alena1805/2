#include <iostream>
#include <list>
#include <limits>

// Функция для заполнения списка целыми числами
void fillList(std::list<int>& L, const std::string& name) {
    int number;
    std::cout << "Введите целые числа для списка " << name << " (введите 'q' для завершения ввода):" << std::endl;

    while (std::cin >> number) {
        L.push_back(number);
    }

    // Очистка состояния потока и игнорирование некорректного ввода
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Функция для комбинирования элементов списков
void combineLists(std::list<int>& L1, std::list<int>& L2) {
    auto i1 = L1.begin(); // Итератор для первого списка
    auto i2 = L2.begin(); // Итератор для второго списка

    // Количество элементов в списках
    size_t N = L1.size();

    for (size_t count = 0; count < N; ++count) {
        // Вставляем элемент из L1 перед текущим элементом в L2
        L2.splice(++i2, L1, i1++);
        // Увеличиваем итератор i2 для следующей вставки
    }
}

// Функция для вывода элементов списка
void printList(const std::list<int>& L) {
    for (const auto& elem : L) {
        std::cout << elem << " "; // Вывод каждого элемента
    }
    std::cout << std::endl; // Переход на новую строку
}

// Функция для вывода элементов списка в обратном порядке
void printListReverse(const std::list<int>& L) {
    for (auto it = L.rbegin(); it != L.rend(); ++it) {
        std::cout << *it << " "; // Вывод каждого элемента в обратном порядке
    }
    std::cout << std::endl; // Переход на новую строку
}

// Главная функция программы
int main() {
    std::list<int> L1; // Первый список
    std::list<int> L2; // Второй список

    fillList(L1, "L1"); // Заполнение первого списка
    fillList(L2, "L2"); // Заполнение второго списка

    if (L1.size() != L2.size()) {
        std::cerr << "Списки должны содержать одинаковое количество элементов!" << std::endl;
        return 1; // Завершение программы с ошибкой
    }

    combineLists(L1, L2); // Комбинирование списков

    std::cout << "Комбинированный список L2: ";
    printList(L2); // Вывод комбинированного списка
    std::cout << "Комбинированный список L2 в обратном порядке: ";
    printListReverse(L2); // Вывод комбинированного списка в обратном порядке

    return 0; // Завершение программы
}
