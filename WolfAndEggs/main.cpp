#include <QApplication>

#include <iostream>
#include <QThread>
#include <QApplication>
#include <QWidget>
#include <QFont>
#include <QPushButton>
#include <QTime>

#include <string>

#include "cfirst.h"


#include <imgproc\imgproc.hpp>
#include <highgui.h>

void sleep(int msec) {
    QTime tt;
    tt.start();
    while(tt.elapsed() < msec);
}

 int main(int argc, char *argv[])
 {

     // задаём высоту и ширину картинки
             int height = 620;
             int width = 440;
             // задаём точку для вывода текста
             CvPoint pt = cvPoint( height/4, width/2 );
             // Создаёи 8-битную, 3-канальную картинку
             IplImage* hw = cvCreateImage(cvSize(height, width), 8, 3);
             // заливаем картинку чёрным цветом
             cvSet(hw,cvScalar(0,0,0));
             // инициализация шрифта
             CvFont font;
             cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,1.0, 1.0, 0, 1, CV_AA);
             // используя шрифт выводим на картинку текст
             cvPutText(hw, "OpenCV Step By Step", pt, &font, CV_RGB(150, 0, 150) );

             // создаём окошко
             cvNamedWindow("Hello World", 0);
             // показываем картинку в созданном окне
             cvShowImage("Hello World", hw);
             // ждём нажатия клавиши
             cvWaitKey(0);

             // освобождаем ресурсы
             cvReleaseImage(&hw);
             cvDestroyWindow("Hello World");




     QApplication app(argc, argv);

     QWidget window;
     window.resize(200, 120);
     QPushButton quit("Quit", &window);
     quit.setFont(QFont("Times", 18, QFont::Bold));
     quit.setGeometry(10, 40, 180, 40);
     QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
     window.show();


     CFirst* first= new CFirst();
     QThread* thread = new QThread;
     first->moveToThread(thread);


     QObject::connect(thread, SIGNAL(started()), first, SLOT(process()));
     QObject::connect(first, SIGNAL(finished()), thread, SLOT(quit()));
     QObject::connect(first, SIGNAL(finished()), first, SLOT(deleteLater()));
     QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));


     thread->start();


     for(int i=0; i!=1000; ++i)
        std::cout << "0";


     return app.exec();
}
