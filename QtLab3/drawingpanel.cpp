#include "drawingpanel.h"

#include <QPainter>

DrawingPanel::DrawingPanel(QWidget* parent)
    : QWidget{ parent }
{
    color = Qt::blue;
    currentI = -170;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
}

void DrawingPanel::stopTimer()
{
    timer->stop();
}

void DrawingPanel::startTimer()
{
    timer->start(20);
}

bool DrawingPanel::isActive()
{
    return timer->isActive();
}

// ������_5_������ ���������
void DrawingPanel::paintEvent(QPaintEvent*)
{
    int w = width();  // ������ � ������ ����
    int h = height();
    int margin = 20; // ������ �� ���� ����

    QPainter painter(this);
    QPen pen(color, 3);
    QPen currentPen(Qt::red, 3);

    QPoint originOfCoordinates(w / 2 + margin, (h - 2 * margin) / 2);  // ���������� ����� ������ ���������
    painter.translate(originOfCoordinates);                // ���������� ������ ���������

    for (int i = -w / 2; i < w / 2; i++) {
        QPointF coord;
        coord.rx() = i;
        coord.ry() = (-1) * coord.rx() * coord.rx() * 0.01;

        if (i == currentI) {
            painter.setPen(currentPen);
            painter.drawEllipse(coord.rx() - 5, coord.ry() - 5, 10, 10);
        }
        else {
            painter.setPen(pen);
            painter.drawPoint(QPointF(coord.rx(), coord.ry()));
        }
    }
}

void DrawingPanel::slotTimerAlarm()
{
    ++currentI;
    if (currentI == 170)
        currentI = -170;
    update();
}
