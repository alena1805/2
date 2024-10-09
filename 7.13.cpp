#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Функциональный объект для сравнения
struct Compare {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

// Функция для ввода данных
void inputVector(std::vector<int>& vec) {
    std::cout << "Введите количество элементов (должно делиться на 3): ";
    int n;
    while (!(std::cin >> n) || n % 3 != 0) {
        std::cerr << "Ошибка ввода. Пожалуйста, введите целое число, делящееся на 3." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    vec.resize(n);
    std::cout << "Введите элементы вектора:" << std::endl;
    for (int i = 0; i < n; ++i) {
        while (!(std::cin >> vec[i])) {
            std::cerr << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Функция для слияния отсортированных частей вектора
void mergeSortedParts(std::vector<int>& vec) {
    size_t third = vec.size() / 3;

    // Сначала сливаем первую и вторую треть
    std::inplace_merge(vec.begin(), vec.begin() + third, vec.begin() + 2 * third, Compare());

    // Затем сливаем результат с третьей частью
    std::inplace_merge(vec.begin(), vec.begin() + 2 * third, vec.end(), Compare());
}

// Функция для вывода вектора
void printVector(const std::vector<int>& vec) {
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Главная функция
int main() {
    std::vector<int> V;

    // Ввод данных
    inputVector(V);

    // Слияние отсортированных частей
    mergeSortedParts(V);

    // Вывод результата
    std::cout << "Отсортированный вектор: ";
    printVector(V);

    return 0; // Успешное завершение программы
}
