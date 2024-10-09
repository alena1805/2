#include <iostream>
#include <vector>
#include <set>
#include <limits>

// Функция для ввода вектора
void inputVector(std::vector<int>& vec) {
    int n;
    std::cout << "Введите количество элементов в векторе: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cerr << "Ошибка ввода. Пожалуйста, введите положительное целое число." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    vec.resize(n);
    std::cout << "Введите элементы вектора:" << std::endl;
    for (int& elem : vec) {
        while (!(std::cin >> elem)) {
            std::cerr << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Функция для подсчета количества векторов, содержащих все элементы V0
int countVectorsContainingV0(const std::vector<int>& V0, const std::vector<std::vector<int>>& vectors) {
    std::multiset<int> multisetV0(V0.begin(), V0.end());
    int count = 0;

    for (const auto& vec : vectors) {
        std::multiset<int> multisetCurrent(vec.begin(), vec.end());
        bool containsAll = true;

        // Проверяем наличие всех элементов V0
        for (const auto& elem : multisetV0) {
            if (multisetCurrent.count(elem) < multisetV0.count(elem)) {
                containsAll = false;
                break;
            }
        }

        if (containsAll) count++; // Увеличиваем счетчик
    }

    return count;
}

// Функция для вывода результата
void printResult(int count) {
    std::cout << "Количество векторов, содержащих все элементы V0: " << count << std::endl;
}

// Главная функция
int main() {
    std::vector<int> V0;
    inputVector(V0); // Ввод V0

    int N;
    std::cout << "Введите количество векторов V1, ..., VN: ";
    while (!(std::cin >> N) || N <= 0) {
        std::cerr << "Ошибка ввода. Пожалуйста, введите положительное целое число." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Ввод всех векторов
    std::vector<std::vector<int>> vectors(N);
    for (auto& vec : vectors) {
        std::cout << "Вектор:" << std::endl;
        inputVector(vec);
    }

    printResult(countVectorsContainingV0(V0, vectors)); // Подсчет и вывод результата
    return 0; // Успешное завершение программы
}
