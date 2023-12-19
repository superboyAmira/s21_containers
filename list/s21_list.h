#ifndef CPP_S21_CONTAINERS_SRC_S21_LIST_H
#define CPP_S21_CONTAINERS_SRC_S21_LIST_H

#include <iostream>
#include <initializer_list>

namespace s21 {

    template<typename T>
    class S21list {

        public:

        using value_t = T;

        // === constructors === //
        S21list();
        S21list(size_t size);

        ~S21list();

        // === methods === //
        void push_front(T value);
        void push_back(T value);
        void pop_front();
        void pop_back();

        size_t size();
        bool empty();

        private:

        // === list elements === //
        struct Node {
            value_t value;
            Node *prev_;
            Node  *next_;
        };

        size_t size_;
        Node *head_;
        Node *tail_;
        Node *end_;

        // === other methods === //

    };
}

#endif // CPP_S21_CONTAINERS_SRC_S21_LIST_H


// TODO
// Конструкторы деструкторы
// front back - получение крайних элементов
// --- DONE --- size - размер списка
// max size - в лекции(что-то под std::size_max)
// --- DONE --- empty - пустой ли список (true/false)
/* resize - изменение размера списка
 *  (n) - простое изменение размера
 *  (n, value) - если размер списка меньше n, все пустые значение инициализируются value */
/* assign - заменить элементы списка определнным набором
 * имеет много перегрузок */
// --- DONE --- push_back, push_front
// emplace_back, emplace_front - хавает все, работает как конструктор (???)
// emplace(pos, value) - вставляет элемент на указанную позицию
// insert(pos, value) - возвращает итератор на добавленный элемент (имеет много перегрузок)
// clear - удаляет все
// pop_front, pop_back
// erase(n) - удаляет элемент. возвращает итератор на следующий удаленному элемент или на конец списка
// erase(begin, end) - удаляет указанный диапозон элементов
// end - ссылается на последний элемент, которого НЕ существует(он всегда должен быть пустым)
// (begin и end работают на итераторе)

// sort - менять местами узлы, а не содержимое узлов