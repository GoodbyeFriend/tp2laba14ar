#pragma once
#include "note.h"

class Keeper {
public:
    struct container {
        NOTE obj;
        container* next;
    };
    int counter = 0;
    container* first;
    container* last;

    Keeper();
    ~Keeper();

    bool empty();// Проверка на пустоту
    void push_back(NOTE obj); // Добавление объекта в контейнер
    void displayAll(); // Вывод всех объектов, отсортированных по номеру рейса 
    void search();//функция поиска
    void remove_id();// Удаление элемента по его индексу
    void redact_id();//редактирование элемента
};


