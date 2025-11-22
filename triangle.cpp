#include "triangle.h"

// Конструктор треугольника
Triangle::Triangle(const QPoint& center, int size)
    : Shape(center), m_size(size)
{
}

// Рисование треугольника
void Triangle::draw(QPainter& painter)
{
    // Установка цвета в зависимости от выделения
    if (m_selected) {
        painter.setPen(QPen(Qt::red, 2));
    }
    else {
        painter.setPen(QPen(m_color, 2));
    }

    // Заливка фигуры
    painter.setBrush(QBrush(m_color, Qt::Dense4Pattern));

    // Создание полигона треугольника (равносторонний)
    QPolygon triangle;
    triangle << QPoint(m_center.x(), m_center.y() - m_size / 2)        // Верхняя вершина
        << QPoint(m_center.x() - m_size / 2, m_center.y() + m_size / 2)  // Левая нижняя
        << QPoint(m_center.x() + m_size / 2, m_center.y() + m_size / 2); // Правая нижняя

    painter.drawPolygon(triangle);
}

// Проверка попадания точки в треугольник
bool Triangle::contains(const QPoint& point)
{
    QPolygon triangle;
    triangle << QPoint(m_center.x(), m_center.y() - m_size / 2)
        << QPoint(m_center.x() - m_size / 2, m_center.y() + m_size / 2)
        << QPoint(m_center.x() + m_size / 2, m_center.y() + m_size / 2);

    return triangle.containsPoint(point, Qt::OddEvenFill);
}

// Получение ограничивающего прямоугольника
QRect Triangle::getBoundingRect()
{
    return QRect(m_center.x() - m_size / 2, m_center.y() - m_size / 2, m_size, m_size);
}

// Изменение размера треугольника
void Triangle::resize(int delta)
{
    m_size += delta;
    // Минимальный размер 10 пикселей
    if (m_size < 10) {
        m_size = 10;
    }
}

// Получение размера треугольника
int Triangle::getSize() const
{
    return m_size;
}