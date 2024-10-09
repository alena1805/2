#include <iostream>
#include <list>
#include <vector>
#include <numeric>
#include <iterator>
#include <limits>

// Функциональный объект для вычисления среднего арифметического
struct Average {
    double operator()(int a, int b) const {
        return (a + b) / 2.0;
    }
};

// Функция для ввода данных в список
void inputList(std::list<int>& lst) {
    std::cout << "Введите количество элементов в списке: ";
    int n;
    while (!(std::cin >> n) || n <= 0) {
        std::cerr << "Ошибка ввода. Пожалуйста, введите положительное целое число." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введите элементы списка:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int value;
        while (!(std::cin >> value)) {
            std::cerr << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        lst.push_back(value);
    }
}

// Функция для получения вектора средних арифметических
std::vector<double> calculateAverages(const std::list<int>& lst) {
    std::vector<double> averages;

    if (lst.size() < 2) {
        return averages; // Возвращаем пустой вектор, если недостаточно элементов
    }

    auto it = lst.begin();
    auto next_it = std::next(it);

    while (next_it != lst.end()) {
        averages.push_back(Average()(*it, *next_it));
        ++it;
        ++next_it;
    }

    return averages;
}

// Функция для вывода вектора
void printVector(const std::vector<double>& vec) {
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Главная функция
int main() {
    std::list<int> L;

    // Ввод данных
    inputList(L);

    // Получение вектора средних арифметических
    std::vector<double> V = calculateAverages(L);

    // Вывод результата
    std::cout << "Вектор средних арифметических: ";
    printVector(V);

    return 0; // Успешное завершение программы
}
