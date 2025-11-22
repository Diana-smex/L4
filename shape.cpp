#include "shape.h"

// Конструктор базового класса фигуры
Shape::Shape(const QPoint& center)
    : m_center(center), m_selected(false), m_color(Qt::blue)
{
}

// Перемещение фигуры
void Shape::moveBy(int dx, int dy)
{
    m_center.setX(m_center.x() + dx);
    m_center.setY(m_center.y() + dy);
}

// Установка выделения фигуры
void Shape::setSelected(bool selected)
{
    m_selected = selected;
}

// Проверка выделена ли фигура
bool Shape::isSelected() const
{
    return m_selected;
}

// Установка цвета фигуры
void Shape::setColor(const QColor& color)
{
    m_color = color;
}

// Получение цвета фигуры
QColor Shape::getColor() const
{
    return m_color;
}

// Получение центра фигуры
QPoint Shape::getCenter() const
{
    return m_center;
}

// Проверка выхода фигуры за границы
bool Shape::isOutOfBounds(const QRect& bounds)
{
    QRect shapeRect = getBoundingRect();
    return !bounds.contains(shapeRect);
}

// Коррекция позиции фигуры чтобы она оставалась внутри границ
void Shape::ensureInsideBounds(const QRect& bounds)
{
    QRect shapeRect = getBoundingRect();

    if (shapeRect.left() < bounds.left()) {
        m_center.setX(m_center.x() + (bounds.left() - shapeRect.left()));
    }
    if (shapeRect.right() > bounds.right()) {
        m_center.setX(m_center.x() - (shapeRect.right() - bounds.right()));
    }
    if (shapeRect.top() < bounds.top()) {
        m_center.setY(m_center.y() + (bounds.top() - shapeRect.top()));
    }
    if (shapeRect.bottom() > bounds.bottom()) {
        m_center.setY(m_center.y() - (shapeRect.bottom() - bounds.bottom()));
    }
}