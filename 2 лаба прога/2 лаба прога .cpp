#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <clocale>

void printVectorRangeBased(const std::vector<int>& vec) {
    for (const auto& value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void printVectorIterator(const std::vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printVectorIndex(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

double calculateMean(const std::vector<int>& vec) {
    int sum = 0;
    for (int value : vec) {
        sum += value;
    }
    return static_cast<double>(sum) / vec.size();
}

double calculateMedian(std::vector<int> vec) {
    std::sort(vec.begin(), vec.end());
    size_t size = vec.size();
    if (size % 2 == 0) {
        return (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
    }
    else {
        return vec[size / 2];
    }
}

std::vector<int> calculateMode(const std::vector<int>& vec) {
    std::map<int, int> counts;
    for (int value : vec) {
        counts[value]++;
    }

    int maxCount = 0;
    for (const auto& pair : counts) {
        maxCount = std::max(maxCount, pair.second);
    }

    std::vector<int> modes;
    for (const auto& pair : counts) {
        if (pair.second == maxCount) {
            modes.push_back(pair.first);
        }
    }

    return modes;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    std::vector<std::string> names;
    std::vector<int> scores;


    int choice;
    std::cout << "Выберите способ инициализации векторов:" << std::endl;
    std::cout << "1. Демонстрационный анализ на дефолтных входных значениях" << std::endl;
    std::cout << "2. Анализ на случайных входных значениях" << std::endl;
    std::cout << "3. Анализ на входных значениях от пользователя" << std::endl;
    std::cin >> choice;

    if (choice == 1) {

        names = { "Nadezda", "Stepan", "Egor", "Filipp", "Aleksandra", "Nikita", "Ignat", "Elena", "Igor", "Slava" };
        scores = { 85, 93, 76, 88, 91, 82, 90, 87, 89, 94 };
    }
    else if (choice == 2) {
        
        int size;
        std::cout << "Введите желаемый размер выборки: ";
        std::cin >> size;
        
    }
    else if (choice == 3) {
        
        int size;
        std::cout << "Введите количество студентов: ";
        std::cin >> size;
        for (int i = 0; i < size; ++i) {
            std::string name;
            int score;
            std::cout << "Введите имя студента: ";
            std::cin >> name;
            names.push_back(name);
            std::cout << "Введите оценку студента: ";
            std::cin >> score;
            scores.push_back(score);
        }
    }

    
    printVectorRangeBased(scores);

    
    double mean = calculateMean(scores);
    std::cout << "Среднее значение оценок: " << mean << std::endl;

    
    double median = calculateMedian(scores);
    std::cout << "Медиана оценок:" << median << std::endl;
   
    std::vector<int> mode = calculateMode(scores);
    std::cout << "Мода оценок: ";
    for (int value : mode) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Студенты с модальными оценками: ";
    for (size_t i = 0; i < scores.size(); ++i) {
        if (std::find(mode.begin(), mode.end(), scores[i]) != mode.end()) {
            std::cout << names[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}