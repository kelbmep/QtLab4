#include "iwidget.h"
#include "cube.h"
#include <QOpenGLFunctions>
#include <QMouseEvent>

IWidget::IWidget(QWidget *centralwidget)
    : QOpenGLWidget(centralwidget)
{
    m_cube = new Cube();

    mousePressed = false;
}

void IWidget::mousePressEvent(QMouseEvent *event)
{
    mousePressed = true;
    m_prevPos = event->pos();
    update();
}

void IWidget::mouseReleaseEvent(QMouseEvent */*event*/)
{
    mousePressed = false;
    update();
}

void IWidget::mouseMoveEvent(QMouseEvent *event)
{
    auto vect = event->pos() - m_prevPos;
    m_prevPos = event->pos();

    m_cube->rotate(-vect.y(), vect.x());

    update();
}

void IWidget::paintEvent(QPaintEvent */*event*/)
{
    m_painter.begin(this);
    drawCube();
    m_painter.end();
}

double topmX(double p) { return p * 150 + 490; }
double topmY(double p) { return p * 150 + 300; }

void IWidget::drawCube()
{
    m_mainPix.fill(Qt::white);

    QPainter tempPainter(&m_mainPix);
    tempPainter.setPen(QPen(Qt::black, 5, Qt::SolidLine));

    for (size_t i = 0; i < m_cube->m_edges.size(); i++)
    {
        //tempPainter.setPen(QPen(QColor::fromHsl(i*30,200,120), 6, Qt::SolidLine));
        auto& e = m_cube->m_edges[i];
        tempPainter.drawLine(QLine(
            topmX(m_cube->m_projection[e.first][0]),
            topmY(m_cube->m_projection[e.first][1]),
            topmX(m_cube->m_projection[e.second][0]),
            topmY(m_cube->m_projection[e.second][1])
        ));
    }

    m_painter.begin(this);
    m_painter.drawPixmap(0, 0, m_mainPix);
    m_painter.end();
}

void IWidget::resetCube()
{
    auto g = geometry();
    h = g.height();
    w = g.width();

    m_mainPix = QPixmap(w, h);
    m_mainPix.fill(Qt::white);

    m_painter.begin(this);
    m_painter.drawPixmap(0, 0, m_mainPix);
    m_painter.end();

    m_cube->reset();
    drawCube();
}
