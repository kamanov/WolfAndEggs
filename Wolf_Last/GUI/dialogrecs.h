#ifndef DIALOGRECS_H
#define DIALOGRECS_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
class Game;

class dialogRecs : public QWidget
{
    Q_OBJECT

public:
friend class Game;
    dialogRecs(int n, double dx, double dy, QWidget *parent = 0);
    ~dialogRecs();
signals:
    void runRecProc(QString name);
private:
    QLineEdit* ledit;
    QPushButton* newGame;
    QPushButton* save;
    int m_score;
public slots:
    void saveRec();
};

#endif // DIALOGRECS_H
