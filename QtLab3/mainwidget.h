#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QColorDialog>
#include <QVBoxLayout>
#include "drawingpanel.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget* parent = nullptr);
    ~MainWidget();

protected slots:
    //void onChangedEditX();
    void onClickedColorButton();
    //void onClickedColor();
    void onClickedStartButton();
private:
    DrawingPanel* drawingPanel;
   // QLineEdit* editX;
    //QPushButton* button;
  //  QLineEdit* editY;
    QColorDialog* dlg;
    QPushButton* colorButton;
    QPushButton* startButton;

};
#endif // MAINWIDGET_H
