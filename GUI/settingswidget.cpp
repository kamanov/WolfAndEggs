#include "settingswidget.h"

#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QLayout>

SettingsWidget::SettingsWidget(QRect& rect, QWidget *parent)
    : UpdatedWidget(rect, parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    //setFixedSize(807, 529);

   /* int AREA_WIDTH; - от 10 до 200
    int AREA_HEIGHT; от 10 до 200
    int SHIFT_FROM_BORDER; от 10 до 100

    int MAX_DEVIATION; от 0 до 200
       double COVER_RATIO; от 0 до 1 (с шагом 0.001)

    int KERNEL_ERO_SIZE; от 1 до 10
    int KERNEL_DIL_SIZE; от 1 до 10
    bool ERODE;  - 0 / 1
    bool DILATE; 0 / 1

    int THRESHOLD; 0 до 255
    int DELAY; от 0 до 100

    bool PRO_SETTINGS_MODE; вкл / выкл */


    QPalette p = palette();
    p.setBrush(backgroundRole(),Qt::cyan);
    setPalette(p);



    m_areaWidth = new QSlider(Qt::Horizontal);
    m_areaWidth->setRange(10, 200);
    m_areaHeight  = new QSlider(Qt::Horizontal);
    m_areaHeight->setRange(10, 200);
    m_shiftFromBorder = new QSlider(Qt::Horizontal);
    m_shiftFromBorder->setRange(10, 100);
    m_maxDeviation = new QSlider(Qt::Horizontal);
    m_maxDeviation->setRange(0, 200);
    m_coverRatio = new QSlider(Qt::Horizontal);
    m_coverRatio->setRange(0, 1000);
    m_kernelEroSize = new QSlider(Qt::Horizontal);
    m_kernelEroSize->setRange(1, 30);
    m_kernelDilSize = new QSlider(Qt::Horizontal);
    m_kernelDilSize->setRange(1, 30);
    m_threshold= new QSlider(Qt::Horizontal);
    m_threshold->setRange(0, 255);
    m_delay= new QSlider(Qt::Horizontal);
    m_delay->setRange(0, 100);


    m_sliders = new QGroupBox;
    m_sliders->setTitle("Pro Settings");
    m_checkBoxes = new QGroupBox;


    m_erode = new QCheckBox;
    m_erode->setText("Erode");
    m_dilate = new QCheckBox;
    m_dilate->setText("Dilate");
    m_proSettingsMode  = new QCheckBox;
    m_proSettingsMode->setText("Pro Settings Mode");

    QPushButton* backBut=new  Button(QRect(15,500,87,27), QPixmap(), this);
    backBut->setText("НАЗАД");

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(m_erode);
    vLayout->addWidget(m_dilate);
    vLayout->addWidget(m_proSettingsMode);
    vLayout->addWidget(backBut);
    m_checkBoxes->setLayout(vLayout);



    QLabel* areaWidth = new QLabel("Area Width");
    QLabel* areaHeight  = new QLabel("Area Height");
    QLabel* shiftFromBorder = new QLabel("Shift From Border");
    QLabel* maxDeviation = new QLabel("Max Deviation");
    QLabel* coverRatio = new QLabel("Cover Ratio");
    QLabel* kernelEroSize = new QLabel("Kernel EroSize");
    QLabel* kernelDilSize = new QLabel("Kkernel DilSize");
    QLabel* threshold= new QLabel("Threshold");
    QLabel* delay= new QLabel("Delay");


    QLabel* areaWidthVal = new QLabel;
    QLabel* areaHeightVal  = new QLabel;
    QLabel* shiftFromBorderVal = new QLabel;
    QLabel* maxDeviationVal = new QLabel;
    QLabel* coverRatioVal = new QLabel;
    QLabel* kernelEroSizeVal = new QLabel;
    QLabel* kernelDilSizeVal = new QLabel;
    QLabel* thresholdVal = new QLabel;
    QLabel* delayVal = new QLabel;


    QGridLayout* gridLayout = new QGridLayout;
    QHBoxLayout* areaWidthL = new QHBoxLayout;
    areaWidthL->addWidget(areaWidth);
    areaWidthL->addWidget(areaWidthVal);
    areaWidthVal->setNum(15);
    gridLayout->addLayout(areaWidthL, 0, 0);
    gridLayout->addWidget(m_areaWidth, 1, 0);



    QHBoxLayout* areaHeightL = new QHBoxLayout;
    areaHeightL->addWidget(areaHeight);
    areaHeightL->addWidget(areaHeightVal);
    gridLayout->addLayout(areaHeightL, 2, 0);
    gridLayout->addWidget(m_areaHeight, 3, 0);

    QHBoxLayout* shiftFromBorderL = new QHBoxLayout;
    shiftFromBorderL->addWidget(shiftFromBorder);
    shiftFromBorderL->addWidget(shiftFromBorderVal);
    gridLayout->addLayout(shiftFromBorderL, 4, 0);
    gridLayout->addWidget(m_shiftFromBorder, 5, 0);


    QHBoxLayout* maxDeviationL = new QHBoxLayout;
    maxDeviationL->addWidget(maxDeviation);
    maxDeviationL->addWidget(maxDeviationVal);
    gridLayout->addLayout(maxDeviationL, 6, 0);
    gridLayout->addWidget(m_maxDeviation, 7, 0);

    QHBoxLayout* coverRatioL = new QHBoxLayout;
    coverRatioL->addWidget(coverRatio);
    coverRatioL->addWidget(coverRatioVal);
    gridLayout->addLayout(coverRatioL, 8, 0);
    gridLayout->addWidget(m_coverRatio, 9, 0);

    QHBoxLayout* kernelEroSizeL = new QHBoxLayout;
    kernelEroSizeL->addWidget(kernelEroSize);
    kernelEroSizeL->addWidget(kernelEroSizeVal);
    gridLayout->addLayout(kernelEroSizeL, 0, 1);
    gridLayout->addWidget(m_kernelEroSize, 1, 1);

    QHBoxLayout* kernelDilSizeL = new QHBoxLayout;
    kernelDilSizeL->addWidget(kernelDilSize);
    kernelDilSizeL->addWidget(kernelDilSizeVal);
    gridLayout->addLayout(kernelDilSizeL, 2, 1);
    gridLayout->addWidget(m_kernelDilSize, 3, 1);

    QHBoxLayout* thresholdL = new QHBoxLayout;
    thresholdL->addWidget(threshold);
    thresholdL->addWidget(thresholdVal);
    gridLayout->addLayout(thresholdL, 4, 1);
    gridLayout->addWidget(m_threshold, 5, 1);


    QHBoxLayout* delayL = new QHBoxLayout;
    delayL->addWidget(delay);
    delayL->addWidget(delayVal);
    gridLayout->addLayout(delayL, 6, 1);
    gridLayout->addWidget(m_delay, 7, 1);


    m_sliders->setLayout(gridLayout);

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_checkBoxes);
    mainLayout->addWidget(m_sliders);

    setLayout(mainLayout);
    setAutoFillBackground(true);

    QObject::connect(m_areaWidth, SIGNAL(valueChanged(int)), areaWidthVal, SLOT(setNum(int)));
    QObject::connect(m_areaHeight,SIGNAL(valueChanged(int)),areaHeightVal,SLOT(setNum(int)));
    QObject::connect(m_shiftFromBorder,SIGNAL(valueChanged(int)),shiftFromBorderVal,SLOT(setNum(int)));
    QObject::connect(m_maxDeviation,SIGNAL(valueChanged(int)),maxDeviationVal,SLOT(setNum(int)));
    QObject::connect(m_coverRatio,SIGNAL(valueChanged(int)),coverRatioVal,SLOT(setNum(int)));
    QObject::connect(m_kernelEroSize,SIGNAL(valueChanged(int)),kernelEroSizeVal,SLOT(setNum(int)));
    QObject::connect(m_kernelDilSize,SIGNAL(valueChanged(int)),kernelDilSizeVal,SLOT(setNum(int)));
    QObject::connect(m_threshold,SIGNAL(valueChanged(int)),thresholdVal,SLOT(setNum(int)));
    QObject::connect(m_delay,SIGNAL(valueChanged(int)),delayVal,SLOT(setNum(int)));

    QObject::connect(backBut,SIGNAL(clicked()),this,SLOT(setBack()));
}

SettingsWidget::~SettingsWidget()
{

}


void SettingsWidget::setBack()
{
    emit static_cast<QStackedWidget*>(parent())->setCurrentIndex(1);
}
