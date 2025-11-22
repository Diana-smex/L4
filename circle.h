#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Класс круга, наследуется от Shape
class Circle : public Shape
{
private:
    int m_radius;  // Радиус круга

public:
    Circle(const QPoint& center, int radius = 30);

    // Реализация виртуальных методов
    void draw(QPainter& painter) override;
    bool contains(const QPoint& point) override;
    QRect getBoundingRect() override;
    void resize(int delta) override;

    int getRadius() const;  // Получение радиуса
};

#endif // CIRCLE_H