#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include <QWidget>
#include <QColor>
#include <QTimer>

class DrawingPanel : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingPanel(QWidget* parent = nullptr);
    void setColor(const QColor& color_) { color = color_; }
    void stopTimer();
    void startTimer();
    bool isActive();
protected:
    void paintEvent(QPaintEvent*);

protected slots:
    void slotTimerAlarm();

private:

    QColor color;
    QTimer* timer;
    int currentI;

};

#endif // DRAWINGPANEL_H
