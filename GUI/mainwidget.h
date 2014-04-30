#ifndef WIDGET_H
#define WIDGET_H
#include <QGraphicsScene>
#include <QWidget>
#include <QStackedWidget>
#include <QSettings>
#include <QPainter>
#include <QPushButton>
#include "../ChannelAndDetection/Settings.h"

class recordsWidget;
class mainMenu;
class manageWidget;
class aboutWidget;
class SettingsWidget;
class Game;

class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    MainWidget(Settings* settings, QWidget *parent = 0);
    ~MainWidget();

protected:
    void resizeEvent(QResizeEvent * event);

private:

    static const int fieldH = 891;
    static const int fieldW = 1521;
    QGraphicsScene m_scene;
    QRect m_centralWidgetRect;
    Game* gameField;
    QStackedWidget* st;
    mainMenu* menu;
    manageWidget* manage;
    aboutWidget* about;
    recordsWidget* recordsView;
    SettingsWidget* m_settingsWidget;
    QSettings* settings;
    QPixmap* m_buttonPix1;
    QPixmap* m_buttonPix2;
    QPixmap* m_buttonMenuPix;
    bool isUpdated;
    void initStackedWidget();
    void initButtons();
    void saveSettings();
    void loadSettings();
    void resizeStackedWidgets(double dx, double dy);
    void resizeBackground();

signals:
    void pauseGame();
    void continueGame();

public slots:
    void setWolfPosition(int pos);
    void enterMenu();
    void goToRecords();
    void newGameStart();
};

#endif // WIDGET_H
