#include "square.h"

// Конструктор квадрата
Square::Square(const QPoint& center, int size)
    : Shape(center), m_size(size)
{
}

// Рисование квадрата
void Square::draw(QPainter& painter)
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
    // Создание квадрата с центром в заданной точке
    QRect rect(m_center.x() - m_size / 2, m_center.y() - m_size / 2, m_size, m_size);
    painter.drawRect(rect);
}

// Проверка попадания точки в квадрат
bool Square::contains(const QPoint& point)
{
    QRect rect(m_center.x() - m_size / 2, m_center.y() - m_size / 2, m_size, m_size);
    return rect.contains(point);
}

// Получение ограничивающего прямоугольника
QRect Square::getBoundingRect()
{
    return QRect(m_center.x() - m_size / 2, m_center.y() - m_size / 2, m_size, m_size);
}

// Изменение размера квадрата
void Square::resize(int delta)
{
    m_size += delta;
    // Минимальный размер 10 пикселей
    if (m_size < 10) {
        m_size = 10;
    }
}

// Получение размера стороны квадрата
int Square::getSize() const
{
    return m_size;
}