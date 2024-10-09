#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// Функция для ввода слов в вектор
void inputWords(std::vector<std::string>& words) {
    std::string word;
    std::cout << "Введите слова (для завершения введите пустую строку):\n";
    
    while (true) {
        std::getline(std::cin, word);
        if (word.empty()) {
            break; // Завершение ввода при пустой строке
        }
        // Проверка на наличие заглавных букв
        if (std::all_of(word.begin(), word.end(), ::isupper)) {
            words.push_back(word);
        } else {
            std::cout << "Слово должно состоять только из заглавных букв. Попробуйте снова.\n";
        }
    }
}

// Функция для группировки слов по последней букве
std::map<char, std::vector<std::string>> groupByLastLetter(const std::vector<std::string>& words) {
    std::map<char, std::vector<std::string>> groupedWords;
    
    for (const auto& word : words) {
        char lastChar = word.back(); // Получаем последнюю букву
        groupedWords[lastChar].push_back(word); // Добавляем слово в соответствующую группу
    }
    
    return groupedWords;
}

// Функция для вывода группированных слов
void printGroupedWords(const std::map<char, std::vector<std::string>>& groupedWords) {
    std::cout << "Группировка по последней букве:\n";
    
    for (const auto& pair : groupedWords) {
        std::cout << pair.first << ": ";
        for (const auto& word : pair.second) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::string> words;
    
    inputWords(words); // Ввод слов
    auto groupedWords = groupByLastLetter(words); // Группировка
    printGroupedWords(groupedWords); // Вывод результатов
    
    return 0;
}
