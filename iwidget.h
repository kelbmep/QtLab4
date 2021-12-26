#ifndef CHWIDGET_H
#define CHWIDGET_H

#include <QOpenGLWidget>
#include <QPainter>

class Cube;

class IWidget : public QOpenGLWidget
{
public:
    IWidget(QWidget *centralwidget);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

public:
    void resetCube();
    void drawCube();

private:
    bool mousePressed;

private:
    int h, w;

    QPixmap m_mainPix;
    QPainter m_painter;
    QPoint m_prevPos;

    Cube* m_cube;
};

#endif // CHWIDGET_H
