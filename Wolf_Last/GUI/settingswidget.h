#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QSlider>
#include <QCheckBox>
#include "button.h"
#include "updatedwidget.h"
#include "../ChannelAndDetection/Settings.h"

class SettingsWidget : public UpdatedWidget
{
    Q_OBJECT

public:
    SettingsWidget(QRect& rect, Settings* settings, QWidget *parent = 0);
    ~SettingsWidget();
public slots:

    void setBack();


private:

    Settings* m_settings;
    QGroupBox* m_sliders;
    QGroupBox* m_checkBoxes;
    QSlider* m_areaWidth;
    QSlider* m_areaHeight;
    QSlider* m_shiftFromBorder;
    QSlider* m_maxDeviation;
    QSlider* m_coverRatio;
    QSlider* m_kernelEroSize;
    QSlider* m_kernelDilSize;
    QCheckBox* m_erode;
    QCheckBox* m_dilate;
    QCheckBox* m_proSettingsMode;
    QSlider* m_threshold;
    QSlider* m_delay;







};


#endif // SETTINGSWIDGET_H
