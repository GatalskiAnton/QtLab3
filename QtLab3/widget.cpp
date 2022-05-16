#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    pen = QPen(Qt::black, 1);
    dlg = new QColorDialog(this);
    colorButton = new QPushButton("Change color", this);
    saveButton = new QPushButton("Save", this);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    slider = new QSlider(Qt::Horizontal,this);
    slider->setMinimum(0);
    slider->setMaximum(20);
    mainLayout->addWidget(colorButton);
    mainLayout->addWidget(slider);
    mainLayout->addWidget(saveButton);
    connect(colorButton, SIGNAL(clicked()), SLOT(onClickedColorButton()));
    connect(slider, SIGNAL(valueChanged(int)), SLOT(sliderMoved()));
    connect(saveButton, SIGNAL(clicked()), SLOT(onClickedSaveButton()));
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
    }
}

void Widget::paintEvent(QPaintEvent* event)
{
    
    QPainter painter(this);
    painter.setPen(pen);
    if (lines.empty() && current_line.empty())
        return;

    for (auto& line : lines)
    {
        for (int i = 0; i < line.size() - 1; i++)
            painter.drawLine(line[i], line[i + 1]);
    }
    for (int i = 1; i < current_line.size(); i++)
        painter.drawLine(current_line[i - 1], current_line[i]);
}

void Widget::onClickedColorButton()
{
    pen.setColor(QColorDialog::getColor());
}

void Widget::onClickedSaveButton()
{
    /*QString fileName("C:/example/customPlot.png");
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly))
    {

    }
    else 
    {
        
    }*/
}

void Widget::sliderMoved()
{
    pen.setWidth(slider->value());
}
