#include <iostream>
#include <list>
#include <iterator>
#include <limits>

void fillList(std::list<int>& L) {
    int number;
    std::cout << "Введите целые числа (введите 'q' для завершения ввода):" << std::endl;

    while (true) {
        std::cout << "> ";
        if (std::cin >> number) {
            L.push_back(number);
        } else if (std::cin.fail()) {
            std::cin.clear(); // сбрасываем флаг ошибки
            std::string input;
            std::cin >> input;
            if (input == "q") {
                break; // выход из цикла при вводе 'q'
            } else {
                std::cout << "Некорректный ввод. Пожалуйста, введите целое число или 'q'." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищаем буфер
            }
        }
    }
}

void printList(const std::list<int>& L) {
    std::cout << "Элементы списка в исходном порядке:" << std::endl;
    for (const auto& elem : L) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void printListReverse(const std::list<int>& L) {
    std::cout << "Элементы списка в обратном порядке:" << std::endl;
    for (auto it = L.rbegin(); it != L.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> L;

    fillList(L);
    printList(L);
    printListReverse(L);

    return 0;
}
