#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include "wolf.h"
#include "egg.h"
#include <QTimer>
#include <QLabel>
#include <QLCDNumber>
#include <QGraphicsPixmapItem>
#include "dialogrecs.h"

class Game : public QGraphicsView
{
    Q_OBJECT

signals:
    void replaceWolf(Wolf::WolfPosition);
    void startHen(int);
    void endGame();
    void recStart();

public:
    Game(QRect& rect, QGraphicsScene* scene,QWidget* parent=0);
    ~Game();
    bool getPauseVal(){return isPaused;}
    void setWolfPosition(int pos);
    void update(double dx, double dy);
    std::multimap<int,QString>& getRecords(){return records;}
protected:
    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QRect m_initRect;
    QGraphicsScene* m_scene;
    Wolf* m_wolf;
    QTimer* amountTimer;
    QTimer* speedTimer;
    int speed;
    int amount;
    Egg* m_egg;
    QLabel* lbl[2];
    QLabel* hens[4];
    QList<Egg*> m_eggs;
    int score;
    int chScore;
    QLCDNumber* lcd;

    void resizeBackground();
    void initHens();
    void addChickScore();
    void initChicks();
    QLabel* chicks[3];
    void speedCorrection();
    bool isPaused;
    QGraphicsPixmapItem* endpix;
    QGraphicsPixmapItem* pausepix;
    bool vendGame;
    QPixmap pixend;
    QPixmap pixpause;
    QPixmap m_background;
    QPixmap m_chickenScore;
    dialogRecs* recsd;
    std::multimap<int,QString> records;
    QRect m_lcdInitRect;
    QRect m_lblRect[2];
    QRect m_hensRect[4];
    QRect m_chicksRect[3];
    double m_dx;
    double m_dy;
    QMovie* m_leftHens;
    QMovie* m_rightHens;
    QSize m_initHensSize;
    QSize m_initChickSize;

public slots:
    void catchControl();
    void startAnimation(Egg* o);
    void finishAnimation();
    void eggFactory();
    void animeHen(int n);
    void wolfLeftUp(){emit replaceWolf(Wolf::WolfPosition::leftUp);}
    void wolfRightUp(){emit replaceWolf(Wolf::WolfPosition::rightUp);}
    void wolfLeftDown(){emit replaceWolf(Wolf::WolfPosition::leftDown);}
    void wolfRightDown(){emit replaceWolf(Wolf::WolfPosition::rightDown);}
    void pauseGame();
    void newGame();
    void endGameProc();
    void procRecord(QString name);


};

#endif // GAME_H
