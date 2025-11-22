#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

// Класс прямоугольника, наследуется от Shape
class Rectangle : public Shape
{
private:
    int m_width;   // Ширина прямоугольника
    int m_height;  // Высота прямоугольника

public:
    Rectangle(const QPoint& center, int width = 60, int height = 40);

    // Реализация виртуальных методов
    void draw(QPainter& painter) override;
    bool contains(const QPoint& point) override;
    QRect getBoundingRect() override;
    void resize(int delta) override;

    int getWidth() const;   // Получение ширины
    int getHeight() const;  // Получение высоты
};

#endif // RECTANGLE_H