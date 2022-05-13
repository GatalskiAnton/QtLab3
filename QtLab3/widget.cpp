#include "widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent* event)
{
}

void Widget::mouseMoveEvent(QMouseEvent* event)
{
    if ((event->buttons() & Qt::LeftButton))
    {
        QPoint point = event->pos();
        current_line.push_back(point);
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        lines.push_back(current_line);
        current_line.clear();
        //update();
    }
}

void Widget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    if (lines.empty() && current_line.empty())
        return;

    for (auto& line : lines)
    {
        for (int i = 0; i < line.size() - 1; i++)
        {
            painter.drawLine(line[i], line[i + 1]);
        }
    }
    for (int i = 0; i < current_line.size() - 1; i++)
    {
        painter.drawLine(current_line[i], current_line[i + 1]);
    }

}