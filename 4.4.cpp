#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>

// Функция для ввода целых чисел с проверкой на корректность
void inputNumbers(std::vector<int>& numbers) {
    std::cout << "Введите целые числа (введите 'q' для завершения ввода):" << std::endl;
    int number;
    while (true) {
        std::cout << "> ";
        if (std::cin >> number) {
            numbers.push_back(number);
        } else {
            std::string input;
            std::cin.clear(); // Сброс состояния потока
            std::cin >> input; // Чтение некорректного ввода
            if (input == "q") {
                break; // Завершение ввода
            } else {
                std::cout << "Некорректный ввод, попробуйте снова." << std::endl;
            }
        }
    }
    std::cin.clear(); // Сброс состояния потока
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование оставшегося ввода
}

// Функция для записи чисел в файл с заменой 0 на 10 и добавлением пробелов
void writeToFile(const std::string& name, const std::vector<int>& numbers) {
    std::ofstream outFile(name);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    // Использование replace_copy для замены 0 на 10
    std::transform(numbers.begin(), numbers.end(), std::ostream_iterator<int>(outFile, "  "), 
                   [](int n) { return n == 0 ? 10 : n; });

    outFile.close(); // Закрытие файла
}

// Главная функция
int main() {
    std::string name;
    std::cout << "Введите имя файла (без расширения): ";
    std::cin >> name;
    name += ".txt"; // Добавление расширения .txt

    std::vector<int> numbers; // Вектор для хранения чисел
    inputNumbers(numbers); // Ввод чисел

    writeToFile(name, numbers); // Запись чисел в файл

    std::cout << "Числа записаны в файл " << name << std::endl;

    return 0; // Успешное завершение программы
}
