#include <iostream>
#include <string>
#include <algorithm>

/* Задание 1.
1) strlen(cчитает количество символов в строке )
- С: size
- С++: std::strlen

2) strcpy(копирует символы изодной строки в другую)
- С: assign
- С++: std::strcpy

3) strcmp (сравнивает две строки )
- С: compare
- С++: std::strcmp

4) strcat (добавляет символы одной строки в конец другой)
- С: append
- С++: std::strcat

5) someString[index] (дает доступ к строке и ее символу по индексу)
- С: at[index]
- С++: std::someString[index]

6) push_back ( добавляет ячейку в конец вектора)
- С: Нет прямого эквивалента в С
- С++: std::vector::push_back

7) pop_back (добавляет ячейку в начало вектора)
- С: Нет прямого эквивалента в С
- С++: std::vector::pop_back*/

int main() {
    std::string stroka;
    std::cout << "введите строку: ";
    std::getline(std::cin, stroka);
    stroka.erase(std::remove_if(stroka.begin(), stroka.end(), [](char c) { /* удаляем пробелы и знаки препинания*/
            return std::isspace(c) || std::ispunct(c);
            }), stroka.end());
    std::sort(stroka.begin(), stroka.end()); /* сортируем в алфавитном порядке */
    std::cout << "Результат: " << stroka << std::endl;
    
    return 0;

}
