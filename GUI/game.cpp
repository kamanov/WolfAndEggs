#include "game.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QMovie>
#include <QGraphicsObject>
#include <QQueue>
#include <QGraphicsPixmapItem>
#include <QStackedWidget>
#include "transformrect.h"


Game::Game(QRect &rect, QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene,parent)
    , m_initRect(rect)
    , m_scene(scene)
    , score(0)
    , lcd(new QLCDNumber)
    , chScore(0)
    , speedTimer(new QTimer)
    , amountTimer(new QTimer)
    , speed(10)
    , amount(1800)
    , isPaused(false)
    , endpix(0)
    , pausepix(0)
    , vendGame(false)
    , pixend(":/theend.png")
    , pixpause(":/pause.png")
    , m_background(":/back.png")
    , recsd(0)
    , m_lcdInitRect(-53,-275,100,50)
    , m_dx(1)
    , m_dy(1)
{
    setWindowFlags(Qt::FramelessWindowHint);
    //set background

    //setFixedSize(808, 533);
    QPalette p = palette();
    p.setBrush(backgroundRole(), QBrush(m_background));
    setPalette(p);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_wolf = new Wolf;
    m_scene->addItem(m_wolf);
    QObject::connect(this,SIGNAL(replaceWolf(Wolf::WolfPosition)),m_wolf,SLOT(changePos(Wolf::WolfPosition)));

    QObject::connect(amountTimer, SIGNAL(timeout()), this, SLOT(eggFactory()));
    amountTimer->start(amount);


    QObject::connect(speedTimer, SIGNAL(timeout()), this, SLOT(catchControl()));
    QObject::connect(this,SIGNAL(startHen(int)),this,SLOT(animeHen(int)));
    speedTimer->start(speed);
    lbl[0] = lbl[1] = 0;
    initHens();


    lcd->setGeometry(m_lcdInitRect);
    m_scene->addWidget(lcd);
    lcd->display(score);
    initChicks();
    setFocusPolicy(Qt::StrongFocus);

    setMouseTracking(true);
}

Game::~Game()
{
    delete amountTimer;
    delete speedTimer;
}

void Game::update(double dx, double dy)
{
    m_dx = dx;
    m_dy = dy;

    lcd->setGeometry(transformRect(m_lcdInitRect, dx, dy));
    for (int i = 0; i < 4; i++) {
        QSize newSize(m_initHensSize.width() * dx, m_initHensSize.height() * dy);
        QMovie* mov;
        if (i < 2)
            mov = new QMovie(":/hensLeft.gif");
        else
            mov = new QMovie(":/hensRight.gif");

            delete hens[i];
            hens[i]= new QLabel;
            mov->setScaledSize(newSize);
            hens[i]->setGeometry(transformRect(m_hensRect[i], dx, dy));
            hens[i]->setMovie(mov);
            //m_scene->addWidget(hens[i]);
            mov->start();
    }

    /*for (int i = 0; i < 3; i++) {
        if (chicks[i] != 0) {
            delete chicks[i];
            chicks[i]=new QLabel;
            chicks[i]->setPixmap(m_chickenScore.scaled(m_initChickSize.width() * dx, m_initChickSize.height() * dy));
            chicks[i]->setGeometry(transformRect(m_chicksRect[i], dx, dy));
            //m_scene->addWidget(chicks[i]);
        }
    } */
    m_wolf->update(dx, dy);
    setGeometry(transformRect(m_initRect, dx, dy));
    m_scene->setSceneRect(transformRect(QRect(-405, -275, 808, 533), dx, dy));
    resizeBackground();
    updateGeometry();

}

void Game::resizeBackground()
{
    QPalette p = palette();
    p.setBrush(backgroundRole(), QBrush(m_background.scaled(size())));
    setPalette(p);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(!vendGame){
        switch(event->nativeScanCode()) {
            case 30: emit replaceWolf(Wolf::leftUp);
                break;
            case 44:emit replaceWolf(Wolf::leftDown);
                break;
            case 37:emit replaceWolf(Wolf::rightUp);
                break;
            case 50:emit replaceWolf(Wolf::rightDown);
                break;
            default: QGraphicsView::keyPressEvent(event);
        }
    }
    else
        QGraphicsView::keyPressEvent(event);

}

void Game::initHens()
{
    for(int i = 0; i < 2; i++){
        hens[i] = new QLabel;

        m_leftHens = new QMovie(":/hensLeft.gif");
        m_initHensSize = QSize(100, 98);

        hens[i]->setMovie(m_leftHens);
        m_leftHens->start();
        m_scene->addWidget(hens[i]);
        if(i == 0) {
            m_hensRect[i] = QRect(-402, -225, 100, 98);
        } else {
            m_hensRect[i] = QRect(-402, -62, 100, 98);
        }
            hens[i]->setGeometry(m_hensRect[i]);
    }

    for(int i = 2; i < 4; i++){
        hens[i] = new QLabel;

        if(i == 2)
            m_hensRect[i] = QRect(300, -163, 100, 98);
        else
            m_hensRect[i] = QRect(300, -45, 100, 98);

        hens[i]->setGeometry(m_hensRect[i]);
        m_rightHens = new QMovie(":/hensRight.gif");
        hens[i]->setMovie(m_rightHens);
        m_rightHens->start();
        m_scene->addWidget(hens[i]);
    }
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(event->pos().y()> m_dy * 326){
        if(event->pos().x()> m_dx * 350)
            emit replaceWolf(Wolf::rightDown);
        else
            emit replaceWolf(Wolf::leftDown);
     } else if(event->pos().y()< m_dy * 321) {
        if (event->pos().x()> m_dx * 415)
            emit replaceWolf(Wolf::rightUp);
        else
            emit replaceWolf(Wolf::leftUp);
    }
}

void Game::addChickScore()
{
   /* if(chScore < 3){
        if(chicks[2 - chScore] != 0) {
            delete chicks[2 - chScore];
            chicks[2 - chScore] = 0;
        }
    }

    if(chScore == 2)
       endGameProc();

     chScore++;
*/

}

void Game::initChicks()
{
   /* m_initChickSize = QSize(50, 95);
    m_chickenScore = QPixmap(":/chickenscore.png");
    for(int i = 0;i < 3;i++){
        chicks[i] = new QLabel;
        chicks[i]->setPixmap(m_chickenScore);

        m_chicksRect[i] = QRect(150+i*50, -265, 50, 95);
        chicks[i]->setGeometry(m_chicksRect[i]);
        m_scene->addWidget(chicks[i]);
    }
*/
}

void Game::speedCorrection()
{
    if(speed > 6)
        speed -= 0.5;
    if(amount >= 650)
        amount -= 150;
    if(score > 200)
        amount -= 30;
    speedTimer->start(speed);
    amountTimer->start(amount);
}

void Game::catchControl()
{
    if(!m_eggs.empty()){
            foreach(Egg* m_egg,m_eggs){
                if (m_egg->collidesWithItem(m_wolf)){
                    m_scene->removeItem(m_egg);
                    m_eggs.removeOne(m_egg);
                    delete m_egg;
                    score++;
                    if(score%5 == 0)
                       speedCorrection();
                    lcd->display(score);
                 }
            }
      }
}

void Game::startAnimation(Egg* p)
{
    addChickScore();
    QString file_name;
    QRect geo;
    QLabel* label = new QLabel;
    if(p->getPos() == Egg::leftDown || p->getPos() == Egg::leftUp ) {
        file_name = ":/chick.gif";
        geo= transformRect(QRect(-403, 169, 290, 83), m_dx, m_dy);
        if(lbl[0] != 0)
            delete lbl[0];
            lbl[0] = label;

        } else {
            file_name = ":/chickRight.gif";
            geo = transformRect(QRect(112, 169, 290, 83), m_dx, m_dy);
            if(lbl[1] != 0)
                delete lbl[1];
            lbl[1] = label;
        }

     QMovie* mov = new QMovie(file_name);
     mov->setScaledSize(QSize(290 * m_dx, 83 * m_dy));
     label->setMovie(mov);
     mov->start();
     //m_scene->addWidget(label);
     label->setGeometry(geo);

     m_scene->removeItem(p);
     m_eggs.removeOne(p);
     delete p;
     QObject::connect(mov,SIGNAL(finished()),this,SLOT(finishAnimation()));
}

void Game::finishAnimation()
{
    if(lbl[0] != 0){
        if(lbl[0]->movie()->currentFrameNumber() == 18){
            delete lbl[0];
            lbl[0]=0;}
    }
    if(lbl[1] != 0){
        if(lbl[1]->movie()->currentFrameNumber() == 18){
            delete lbl[1];
            lbl[1] = 0;}
    }
}

void Game::eggFactory()
{
    static int last = 0;
    int n = qrand() % 4;
    if(n == last)
        n = (n + 1) % 4;
    last = n;
    emit startHen(n);
    Egg* e = new Egg(static_cast<Egg::EggPosition>(n), m_dx, m_dy);
    QObject::connect(speedTimer, SIGNAL(timeout()),e, SLOT(move()));
    QObject::connect(e, SIGNAL(runAnimation(Egg* )), this, SLOT(startAnimation(Egg*)));
    m_eggs.append(e);
    m_scene->addItem(e);
}

void Game::animeHen(int n)
{
    hens[n]->movie()->start();
}

void Game::pauseGame()
{
    if(!vendGame){
        if(!isPaused){
            pausepix = new QGraphicsPixmapItem;
            pausepix->setPos(-90 * m_dx,-135 * m_dy);
            QSize s = pixpause.size();
            pausepix->setPixmap(pixpause.scaled(s.width() * m_dx, s.height() * m_dy));
            m_scene->addItem(pausepix);
            speedTimer->stop();
            amountTimer->stop();
            isPaused = true;
            m_wolf->setAvaible(false);
        } else {
            if(pausepix!=0){
                m_scene->removeItem(pausepix);
                pausepix=0;
            }
            m_wolf->setAvaible(true);
            speedTimer->start(speed);
            amountTimer->start(amount);
            isPaused = false;
        }
    }

}

void Game::newGame()
{
   vendGame = false;
   score = chScore = 0;
   lcd->display(score);
   speed = 10;
   amount = 1800;
   speedTimer->start(speed);
   amountTimer->start(amount);
   for(int i = 0; i < 2; i++){
       if (lbl[i] != 0) {
               delete lbl[i];
               lbl[i] = 0;
        }
   }


   foreach(Egg* eg, m_eggs){
       m_scene->removeItem(eg);
       delete eg;
       m_eggs.removeOne(eg);
   }
   for(int i = 0; i < 3; i++)
   {
       if (chicks[i] != 0)
               delete chicks[i];
   }

   initChicks();
   if(pausepix != 0){
       m_scene->removeItem(pausepix);
      pausepix = 0;
   }
   if(endpix != 0){
       m_scene->removeItem(endpix);
       endpix = 0;
   }
   m_wolf->setAvaible(true);

   if(recsd != 0){
       recsd->deleteLater();
       recsd = 0;
   }
}

void Game::endGameProc()
{
   m_wolf->setAvaible(false);
   endpix = new QGraphicsPixmapItem;
   endpix->setPos(-250 * m_dx,-135 * m_dy);
   QSize s = pixend.size();
   endpix->setPixmap(pixend.scaled(s.width() * m_dx, s.height() * m_dy));
   m_scene->addItem(endpix);
   speedTimer->stop();\
   amountTimer->stop();
   vendGame=true;
   recsd=new dialogRecs(m_dx, m_dy, score);
   QRect wGeometry(-120,0,261,143);
   recsd->setGeometry(transformRect(wGeometry, m_dx, m_dy));
   m_scene->addWidget(recsd);
   QObject::connect(recsd->newGame,SIGNAL(clicked()),this,SLOT(newGame()));
   QObject::connect(recsd,SIGNAL(runRecProc(QString)),this,SLOT(procRecord(QString)));
   isPaused = false;

}

void Game::procRecord(QString name)
{
    records.insert(std::pair<int,QString>(score,name));
    if(records.size() > 10)
        records.erase(records.begin());
    emit recStart();
}
