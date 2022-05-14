#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        
    }
}

void Widget::mouseMoveEvent(QMouseEvent* event)
{
    if ((event->buttons() & Qt::LeftButton) )
    {
        QPoint point = event->pos();
        current_line.push_back(point);
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton )
    {
        lines.push_back(current_line);
        current_line.clear();
       // scribbling = false;

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
            painter.drawLine(line[i], line[i + 1]);
    }
    for (int i = 1; i < current_line.size(); i++)
        painter.drawLine(current_line[i - 1], current_line[i]);
     /* colorButton = new QPushButton("Change color", this);
     colorButton->show();*/
}

void Widget::onClickedColorButton()
{

}