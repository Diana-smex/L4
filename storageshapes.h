#ifndef STORAGESHAPES_H
#define STORAGESHAPES_H

#include <QVector>
#include "shape.h"

// Класс-контейнер для хранения и управления коллекцией фигур
class StorageShapes
{
private:
    QVector<Shape*> m_shapes;  // Вектор для хранения указателей на фигуры

public:
    StorageShapes();
    ~StorageShapes();

    // Запрещаем копирование для безопасности
    StorageShapes(const StorageShapes&) = delete;
    StorageShapes& operator=(const StorageShapes&) = delete;

    // Основные методы работы с контейнером
    int getCount() const;                    // Получение количества фигур
    Shape* getShape(int index);              // Получение фигуры по индексу
    void addShape(Shape* shape);             // Добавление новой фигуры
    void removeShape(int index);             // Удаление фигуры по индексу
    void clear();                            // Очистка контейнера

    // Работа с выделенными объектами
    QVector<Shape*> getSelectedShapes() const;  // Получение всех выделенных фигур
    void clearSelection();                      // Снятие выделения со всех фигур
};

#endif // STORAGESHAPES_H