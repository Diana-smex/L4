#include "circle.h"

// Конструктор круга
Circle::Circle(const QPoint& center, int radius)
    : Shape(center), m_radius(radius)
{
}

// Рисование круга
void Circle::draw(QPainter& painter)
{
    // Установка цвета в зависимости от выделения
    if (m_selected) {
        painter.setPen(QPen(Qt::red, 2));  // Красный для выделенных
    }
    else {
        painter.setPen(QPen(m_color, 2));  // Обычный цвет для невыделенных
    }

    // Заливка фигуры
    painter.setBrush(QBrush(m_color, Qt::Dense4Pattern));
    // Рисование эллипса (круга)
    painter.drawEllipse(m_center, m_radius, m_radius);
}

// Проверка попадания точки в круг
bool Circle::contains(const QPoint& point)
{
    int dx = point.x() - m_center.x();
    int dy = point.y() - m_center.y();
    // Проверка расстояния от центра до точки
    return (dx * dx + dy * dy) <= (m_radius * m_radius);
}

// Получение ограничивающего прямоугольника
QRect Circle::getBoundingRect()
{
    return QRect(m_center.x() - m_radius, m_center.y() - m_radius,
        m_radius * 2, m_radius * 2);
}

// Изменение размера круга
void Circle::resize(int delta)
{
    m_radius += delta;
    // Минимальный радиус 10 пикселей
    if (m_radius < 10) {
        m_radius = 10;
    }
}

// Получение радиуса круга
int Circle::getRadius() const
{
    return m_radius;
}