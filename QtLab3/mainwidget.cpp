#include "mainwidget.h"
#include <QLabel>

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent)
{
    drawingPanel = new DrawingPanel(this);
  //editX = new QLineEdit(this);
    
  //connect(editX, SIGNAL(textChanged(const QString & )), SLOT(onChangedEditX()));

  //editY = new QLineEdit(this);
  //editY->setDisabled(true);
    /*QLabel* lblX =  new QLabel("x",this);
    QLabel* lblY = new QLabel("y",this);
    *///button = new QPushButton("F(x)",this);
    startButton = new QPushButton("Start", this);
    colorButton = new QPushButton("Change Color", this);
    connect(colorButton, SIGNAL(clicked()), SLOT(onClickedColorButton()));
  //connect(button, SIGNAL(clicked()), SLOT(onClickedColor()));
    connect(startButton, SIGNAL(clicked()), SLOT(onClickedStartButton()));
    dlg = new QColorDialog(this);
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(drawingPanel);
    mainLayout->addWidget(colorButton);
    
    /*lblX->setFixedSize(10, 10);
    lblY->setFixedSize(10, 10);*/

    mainLayout->addWidget(startButton);
    
  /*  mainLayout->addWidget(lblX);
    mainLayout->addWidget(editX);
    mainLayout->addWidget(button);
    mainLayout->addWidget(lblY);
    mainLayout->addWidget(editY);
    */
    setLayout(mainLayout);
}

MainWidget::~MainWidget()
{
    
}

//void MainWidget::onChangedEditX()
//{
//    editY->setText(editX->text());
//}
//void MainWidget::onClickedColor()
//{
//   // editY->setText(editX->text());
//}

void MainWidget::onClickedStartButton()
{
    if (drawingPanel->isActive())
    {
        startButton->setText("Start");
        drawingPanel->stopTimer();
    }
    else
    {
        startButton->setText("Stop");
        drawingPanel->startTimer();
    }
}

void MainWidget::onClickedColorButton()
{
    drawingPanel->setColor(dlg->getColor());
    drawingPanel->update();
}

