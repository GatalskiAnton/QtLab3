#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    pen = QPen(Qt::black, 1);
    dlg = new QColorDialog(this);
    colorButton = new QPushButton("Change color", this);
    saveButton = new QPushButton("Save", this);
    clearButton = new QPushButton("Clear", this);
    openButton = new QPushButton("Open", this);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignBottom);
    slider = new QSlider(Qt::Horizontal,this);
    slider->setMinimum(0);
    slider->setMaximum(20);
    mainLayout->addWidget(slider);
    mainLayout->addWidget(colorButton);
    mainLayout->addWidget(saveButton);
    mainLayout->addWidget(openButton);
    mainLayout->addWidget(clearButton);
    connect(colorButton, SIGNAL(clicked()), SLOT(onClickedColorButton()));
    connect(slider, SIGNAL(valueChanged(int)), SLOT(sliderMoved()));
    connect(saveButton, SIGNAL(clicked()), SLOT(onClickedSaveButton()));
    connect(clearButton, SIGNAL(clicked()), SLOT(onClickedClearButton()));
    connect(openButton, SIGNAL(clicked()), SLOT(onClickedOpenButton()));

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
    painter.drawTiledPixmap(0, 0, width(), 0.7 * height(), pix);
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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as"), "img.png");
    int nIndex = fileName.lastIndexOf('.');
    nIndex++;
    int nLen = fileName.length() - nIndex;
    QString strSuffix = fileName.right(nLen);
   QPixmap pixmap = QPixmap::grabWidget(this, 0, 0, width(), 0.75* height());
   pixmap.save(fileName, strSuffix.toUpper().toUtf8());
}

void Widget::sliderMoved()
{
    pen.setWidth(slider->value());
}

void Widget::onClickedClearButton()
{
    lines.clear();
    update();
}

void Widget::onClickedOpenButton()
{
    QString fileName = QFileDialog::getOpenFileName();
    QImage img;
    img.load(fileName);
    pix = QPixmap::fromImage(img);
    pix = pix.scaled(width(), 0.75 * height());
    update();
}
