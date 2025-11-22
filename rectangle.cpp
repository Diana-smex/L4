#include "rectangle.h"

// Конструктор прямоугольника
Rectangle::Rectangle(const QPoint& center, int width, int height)
    : Shape(center), m_width(width), m_height(height)
{
}

// Рисование прямоугольника
void Rectangle::draw(QPainter& painter)
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
    // Создание прямоугольника с центром в заданной точке
    QRect rect(m_center.x() - m_width / 2, m_center.y() - m_height / 2, m_width, m_height);
    painter.drawRect(rect);
}

// Проверка попадания точки в прямоугольник
bool Rectangle::contains(const QPoint& point)
{
    QRect rect(m_center.x() - m_width / 2, m_center.y() - m_height / 2, m_width, m_height);
    return rect.contains(point);
}

// Получение ограничивающего прямоугольника
QRect Rectangle::getBoundingRect()
{
    return QRect(m_center.x() - m_width / 2, m_center.y() - m_height / 2, m_width, m_height);
}

// Изменение размера прямоугольника
void Rectangle::resize(int delta)
{
    m_width += delta;
    m_height += delta;

    // Минимальные размеры
    if (m_width < 20) {
        m_width = 20;
    }
    if (m_height < 15) {
        m_height = 15;
    }
}

// Получение ширины прямоугольника
int Rectangle::getWidth() const
{
    return m_width;
}

// Получение высоты прямоугольника
int Rectangle::getHeight() const
{
    return m_height;
}