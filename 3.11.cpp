#include <iostream>
#include <list>
#include <limits>

// Функция для заполнения списка целыми числами
void fillList(std::list<int>& L, const std::string& name) {
    int number;
    std::cout << "Введите целые числа для списка " << name << " (введите 'q' для завершения ввода):" << std::endl;
    // Чтение чисел из ввода до тех пор, пока не введён некорректный ввод
    while (std::cin >> number) L.push_back(number);
    std::cin.clear(); // Сброс состояния потока ввода
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование оставшегося ввода
}

// Функция для комбинирования двух списков
void combineLists(std::list<int>& L1, std::list<int>& L2) {
    // Переменные-итераторы для обоих списков
    for (auto i1 = L1.begin(), i2 = L2.begin(); i1 != L1.end(); ++i1, ++i2) {
        // Перемещение элемента из L1 в L2
        L2.splice(++i2, L1, i1);
    }
}

// Функция для вывода списка (с возможностью вывода в обратном порядке)
void printList(const std::list<int>& L, bool reverse = false) {
    if (reverse) {
        // Вывод элементов в обратном порядке
        for (auto it = L.rbegin(); it != L.rend(); ++it) std::cout << *it << " ";
    } else {
        // Обычный вывод элементов
        for (const auto& elem : L) std::cout << elem << " ";
    }
    std::cout << std::endl; // Переход на новую строку после вывода
}

int main() {
    std::list<int> L1, L2; // Создание двух списков
    fillList(L1, "L1"); // Заполнение первого списка
    fillList(L2, "L2"); // Заполнение второго списка

    // Проверка на равенство размеров списков
    if (L1.size() != L2.size()) {
        std::cerr << "Списки должны содержать одинаковое количество элементов!" << std::endl;
        return 1; // Завершение программы с ошибкой
    }

    combineLists(L1, L2); // Комбинирование списков
    std::cout << "Комбинированный список L2: ";
    printList(L2); // Вывод комбинированного списка
    std::cout << "Комбинированный список L2 в обратном порядке: ";
    printList(L2, true); // Вывод комбинированного списка в обратном порядке

    return 0; // Успешное завершение программы
}
