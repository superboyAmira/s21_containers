#ifndef CPP_S21_CONTAINERS_SRC_S21_LIST_H
#define CPP_S21_CONTAINERS_SRC_S21_LIST_H

#include <iostream>

namespace s21 {
    // TODO
    // Конструкторы деструкторы
    // front back - получение крайних элементов
    // size - размер списка
    // ? empty - пустой ли список (true/false)
    /* resize - изменение размера списка
     *  (n) - простое изменение размера
     *  (n, value) - если размер списка меньше n, все пустые значение инициализируются value */
    /* assign - заменить элементы списка определнным набором
     * имеет много перегрузок */
    // push_back, push_front - нужно указание типа данных (???)
    // emplace_back, emplace_front - хавает все, работает как конструктор (???)
    // emplace(pos, value) - вставляет элемент на указанную позицию
    // insert(pos, value) - возвращает итератор на добавленный элемент (имеет много перегрузок)
    // clear - удаляет все
    // pop_front, pop_back
    // erase(n) - удаляет элемент. возвращает итератор на следующий удаленному элемент или на конец списка
    // erase(begin, end) - удаляет указанный диапозон элементов

    class S21list {
        struct Node {
//            auto value;
            Node *prev;
            Node  *next;

//            Node(): value(value), prev(nullptr), next(nullptr) {}
        };

        public:

        S21list();

        private:

    };
}

#endif // CPP_S21_CONTAINERS_SRC_S21_LIST_H