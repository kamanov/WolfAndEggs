#include "mainwidget.h"
#include <QDebug>
#include "game.h"
#include <QPushButton>
#include <QBitmap>
#include <QKeyEvent>
#include "mainmenu.h"
#include "managewidget.h"
#include "aboutwidget.h"
#include "recordswidget.h"
#include <QDebug>
#include <QVBoxLayout>
#include "button.h"
#include "settingswidget.h"


MainWidget::MainWidget(Settings *settings, QWidget *parent)
    : QWidget(parent)
    , m_settings(settings)
    , m_scene(-105, -175, 808, 533)
    , m_centralWidgetRect(355, 176, 808, 533)
    , gameField(new Game(m_centralWidgetRect, &m_scene))
    , about(new aboutWidget(m_centralWidgetRect))
    , menu(new mainMenu(m_centralWidgetRect))
    , manage(new manageWidget(m_centralWidgetRect))
    , st(new  QStackedWidget(this))
    , recordsView(new recordsWidget(m_centralWidgetRect))
    , m_settingsWidget(new SettingsWidget(m_centralWidgetRect, settings))
    , settings(new QSettings("karama", "WolfAndEggs", this))
    , isUpdated(false)
{
    loadSettings();
    recordsView->printRecords(gameField->getRecords());
    setWindowFlags(Qt::FramelessWindowHint);
    initStackedWidget();
    initButtons();
    showMaximized();

    QObject::connect(this,SIGNAL(pauseGame()),gameField,SLOT(pauseGame()));
    QObject::connect(recordsView->newBut,SIGNAL(clicked()),this,SLOT(newGameStart()));
}

void MainWidget::setWolfPosition(int pos)
{
    gameField->setWolfPosition(pos);
}

MainWidget::~MainWidget()
{
    saveSettings();
    delete m_buttonMenuPix;
    delete m_buttonPix1;
    delete m_buttonPix2;
}

void MainWidget::loadSettings()
{
    QStringList keys = settings->allKeys();
    foreach (QString key, keys) {
       gameField->getRecords().insert(std::pair<int,QString>(key.toInt(),settings->value(key).toString()));
    }
}

void MainWidget::resizeEvent(QResizeEvent *event)
{

    if (size().width() < 200)
        return;

    if (isUpdated)
        return;
    resizeBackground();
    double dy = (double)size().height() / fieldH;
    double dx = (double)size().width() / fieldW;
    resizeStackedWidgets(dx, dy);
    QList<Button*> ls = this->findChildren<Button*>();
    foreach (Button* w, ls) {
        w->update(dx, dy);
    }
    isUpdated = true;
    QWidget::resizeEvent(event);
}

void MainWidget::initStackedWidget()
{
    st->addWidget(gameField);
    st->addWidget(menu);
    st->addWidget(m_settingsWidget);
    //st->addWidget(manage);
    //st->addWidget(about);
    //st->addWidget(recordsView);
}

void MainWidget::saveSettings()
{
    settings->clear();
    std::multimap<int,QString>::iterator it = gameField->getRecords().begin();
    int sz = gameField->getRecords().size();
    for(int i = 0; i < sz; i++)
    {
        settings->setValue(QString::number((*it).first), (*it).second);
        ++it;
    }

}

void MainWidget::resizeStackedWidgets(double dx, double dy)
{
    UpdatedWidget* w;
    Game* g = (Game*)st->widget(0);
    g->update(dx, dy);
    for (int i = 1; i < st->count(); i++) {
        w = (UpdatedWidget*)st->widget(i);
        w->update(dx, dy);
    }
    st->setGeometry(355 * dx, 176 * dy, 808 * dx, 533 * dy);
    st->updateGeometry();
}

void MainWidget::resizeBackground()
{
    QPixmap pixmap(":/background1.png");
    QPalette p = palette();
    p.setBrush(backgroundRole(), QBrush(pixmap.scaled(size())));
    setPalette(p);
}

void MainWidget::initButtons()
{
    m_buttonPix1 = new QPixmap(":/but1.png");
    m_buttonPix2 = new QPixmap(":/but2.png");
    m_buttonMenuPix = new QPixmap(":/menubut.png");

    QPushButton* menuBut = new Button(QRect(691, 828, 136, 46), *m_buttonMenuPix, this);
    QPushButton* newGame = new Button(QRect(1297, 64, 95, 67), *m_buttonPix1, this);
    menuBut->setText("МЕНЮ");
    QPushButton* pauseGame = new Button(QRect(1297, 170, 95, 67), *m_buttonPix1, this);
    QPushButton* endGame = new Button(QRect(1297, 275, 95, 67), *m_buttonPix1, this);
    QPushButton* rightUp = new Button(QRect(1328, 586, 86, 78), *m_buttonPix2, this);
    QPushButton* rightDown = new Button(QRect(1328, 738, 90, 73), *m_buttonPix2, this);
    QPushButton* leftDown = new Button(QRect(108, 736, 86, 78), *m_buttonPix2, this);
    QPushButton* leftUp = new Button(QRect(108, 586, 86, 78), *m_buttonPix2, this);


    QObject::connect(menuBut,SIGNAL(clicked()),this,SLOT(enterMenu()));
   // QObject::connect(newGame,SIGNAL(clicked()),gameField,SLOT(newGame()));
    QObject::connect(pauseGame,SIGNAL(clicked()),gameField,SLOT(pauseGame()));
    QObject::connect(endGame,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(endGame,SIGNAL(clicked()), this, SLOT(endGameSlot()));
    QObject::connect(leftUp,SIGNAL(clicked()),gameField,SLOT(wolfLeftUp()));
    QObject::connect(rightUp,SIGNAL(clicked()),gameField,SLOT(wolfRightUp()));
    QObject::connect(leftDown,SIGNAL(clicked()),gameField,SLOT(wolfLeftDown()));
    QObject::connect(rightDown,SIGNAL(clicked()),gameField,SLOT(wolfRightDown()));
    QObject::connect(pauseGame,SIGNAL(released()),gameField,SLOT(setFocus()));
    //QObject::connect(newGame,SIGNAL(released()),gameField,SLOT(setFocus()));
    QObject::connect(menuBut,SIGNAL(released()),gameField,SLOT(setFocus()));
    QObject::connect(leftUp,SIGNAL(released()),gameField,SLOT(setFocus()));
    QObject::connect(rightUp,SIGNAL(released()),gameField,SLOT(setFocus()));
    QObject::connect(leftDown,SIGNAL(released()),gameField,SLOT(setFocus()));
    QObject::connect(rightDown,SIGNAL(released()),gameField,SLOT(setFocus()));
    QObject::connect(gameField,SIGNAL(recStart()),this,SLOT(goToRecords()));
}




void MainWidget::enterMenu()
{
    setFocus();
    if(st->currentIndex() != 0) {
        st->setCurrentIndex(0);
    } else {
        st->setCurrentIndex(1);
        if(!gameField->getPauseVal())
            gameField->pauseGame();
    }
}

void MainWidget::goToRecords()
{
    st->setCurrentIndex(4);
    recordsView->printRecords(gameField->getRecords());
}

void MainWidget::newGameStart()
{
     st->setCurrentIndex(0);
     gameField->newGame();
}


void MainWidget::endGameSlot()
{
    m_settings->STOP = true;
    emit endSig();
}

