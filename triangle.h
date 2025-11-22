#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

// Класс треугольника, наследуется от Shape
class Triangle : public Shape
{
private:
    int m_size;  // Размер треугольника

public:
    Triangle(const QPoint& center, int size = 50);

    // Реализация виртуальных методов
    void draw(QPainter& painter) override;
    bool contains(const QPoint& point) override;
    QRect getBoundingRect() override;
    void resize(int delta) override;

    int getSize() const;  // Получение размера треугольника
};

#endif // TRIANGLE_H