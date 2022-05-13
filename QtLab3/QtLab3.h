#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtLab3.h"

class QtLab3 : public QMainWindow
{
    Q_OBJECT

public:
    QtLab3(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtLab3Class ui;
};
