#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

// Класс квадрата, наследуется от Shape
class Square : public Shape
{
private:
    int m_size;  // Размер стороны квадрата

public:
    Square(const QPoint& center, int size = 50);

    // Реализация виртуальных методов
    void draw(QPainter& painter) override;
    bool contains(const QPoint& point) override;
    QRect getBoundingRect() override;
    void resize(int delta) override;

    int getSize() const;  // Получение размера стороны
};

#endif // SQUARE_H