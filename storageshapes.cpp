#include "storageshapes.h"

// Конструктор контейнера
StorageShapes::StorageShapes()
{
}

// Деструктор контейнера - освобождает память
StorageShapes::~StorageShapes()
{
    clear();
}

// Получение количества фигур в контейнере
int StorageShapes::getCount() const
{
    return m_shapes.size();
}

// Получение фигуры по индексу
Shape* StorageShapes::getShape(int index)
{
    if (index >= 0 && index < m_shapes.size()) {
        return m_shapes[index];
    }
    return nullptr;  // Возвращаем nullptr если индекс невалидный
}

// Добавление новой фигуры в контейнер
void StorageShapes::addShape(Shape* shape)
{
    if (shape) {
        m_shapes.append(shape);
    }
}

// Удаление фигуры по индексу
void StorageShapes::removeShape(int index)
{
    if (index >= 0 && index < m_shapes.size()) {
        delete m_shapes[index];  // Освобождаем память
        m_shapes.remove(index);  // Удаляем из вектора
    }
}

// Полная очистка контейнера
void StorageShapes::clear()
{
    // Освобождаем память для всех фигур
    for (Shape* shape : m_shapes) {
        delete shape;
    }
    m_shapes.clear();  // Очищаем вектор
}

// Получение всех выделенных фигур
QVector<Shape*> StorageShapes::getSelectedShapes() const
{
    QVector<Shape*> selected;
    for (Shape* shape : m_shapes) {
        if (shape->isSelected()) {
            selected.append(shape);
        }
    }
    return selected;
}

// Снятие выделения со всех фигур
void StorageShapes::clearSelection()
{
    for (Shape* shape : m_shapes) {
        shape->setSelected(false);
    }
}