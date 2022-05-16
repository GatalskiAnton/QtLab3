#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QSlider>
#include <QColorDialog>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget() = default;

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
protected slots:
    void sliderMoved();
    void onClickedColorButton();
    void onClickedSaveButton();
private:
    QColorDialog* dlg;
    QPen pen;
    QPushButton* colorButton;
    QPushButton* saveButton;
    Widget* wGraphic;
    QSlider* slider;
    std::vector<QPoint> current_line;
    std::vector<std::vector<QPoint>> lines;

};
#endif // WIDGET_H
