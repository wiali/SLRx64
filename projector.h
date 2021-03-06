#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QImage>
#include <QWidget>
#include <QLabel>
#include <QPicture>
#include <QPainter>

#include <QMainWindow>
#include <QObject>

class Projector : public QWidget
{
public:
    Projector(QWidget *parent, int scanW, int scanH, int projW, int projH, int xos, int yos);
    ~Projector();
    void showMatImg(cv::Mat img);
    void showImg(cv::Mat img);//直接利用窗口显示由Mat转换而来的Qt图像

    void displaySwitch(bool isWhite);
    void opencvWindow();
    void destoryWindow();//delete the projector window created by cv after showImg

    void setCrossVisable(bool flag);
    void paintEvent(QPaintEvent *event);

private:
    //    QLabel *label;

    QImage pshow;
    bool crossVisible;
    bool imageAva;
    int xoffset;
    int yoffset;
    int height;
    int width;
};

#endif // PROJECTOR_H
