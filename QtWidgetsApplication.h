#ifndef QTWIDGETSAPPLICATION_H
#define QTWIDGETSAPPLICATION_H

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>

#include "storageshapes.h"
#include "shapetype.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

// Главный класс приложения - наследуется от QMainWindow
class QtWidgetsApplication : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget* parent = nullptr);
    ~QtWidgetsApplication();

protected:
    // Обработчики событий Qt
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private slots:
    // Слоты для обработки действий меню
    void createCircle();
    void createRectangle();
    void createSquare();
    void createTriangle();
    void deleteSelected();

private:
    // Приватные методы
    void setupUI();                                      // Настройка интерфейса
    void createShape(ShapeType type, const QPoint& position); // Создание фигуры
    void moveSelectedShapes(int dx, int dy);            // Перемещение выделенных фигур
    void resizeSelectedShapes(int delta);               // Изменение размера выделенных фигур

    // Данные приложения
    StorageShapes m_storage;                            // Контейнер фигур
    ShapeType m_currentShapeType;                       // Текущий тип создаваемой фигуры
    bool m_isDragging;                                  // Флаг перетаскивания
    QPoint m_dragStartPosition;                         // Начальная позиция перетаскивания
    QVector<Shape*> m_draggedShapes;                    // Фигуры в процессе перетаскивания
    QColor m_currentColor;                              // Текущий цвет фигур

    // Элементы интерфейса
    QToolBar* m_toolBar;                                // Панель инструментов
};

#endif // QTWIDGETSAPPLICATION_H