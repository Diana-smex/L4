#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QRect>
#include <QPainter>

// Базовый абстрактный класс для всех фигур
class Shape
{
protected:
    QPoint m_center;    // Центр фигуры
    bool m_selected;    // Выделена ли фигура
    QColor m_color;     // Цвет фигуры

public:
    Shape(const QPoint& center);
    virtual ~Shape() {}

    // Виртуальные методы, которые должны быть реализованы в потомках
    virtual void draw(QPainter& painter) = 0;           // Рисование фигуры
    virtual bool contains(const QPoint& point) = 0;     // Проверка попадания точки
    virtual QRect getBoundingRect() = 0;               // Получение ограничивающего прямоугольника
    virtual void resize(int delta) = 0;                // Изменение размера

    // Общие методы для всех фигур
    void moveBy(int dx, int dy);                       // Перемещение
    void setSelected(bool selected);                   // Установка выделения
    bool isSelected() const;                           // Проверка выделения
    void setColor(const QColor& color);                // Установка цвета
    QColor getColor() const;                           // Получение цвета
    QPoint getCenter() const;                          // Получение центра

    // Контроль границ
    bool isOutOfBounds(const QRect& bounds);           // Проверка выхода за границы
    void ensureInsideBounds(const QRect& bounds);      // Коррекция позиции внутри границ
};

#endif // SHAPE_H