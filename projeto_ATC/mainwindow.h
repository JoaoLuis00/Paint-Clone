#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <vector>
#include <QRubberBand>
#include "Bitmap.h"
#include "RedSelectionChannel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   void mousePressEvent(QMouseEvent *ev);
   void mouseReleaseEvent(QMouseEvent *ev);
   void mouseMoveEvent(QMouseEvent *ev);

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSaveas_triggered();

    void on_actionLine_triggered();

    void on_actionColor_triggered();

    void on_actionPen_triggered();

    void on_actionClose_triggered();

    void on_actionCrop_triggered();

    void on_actionCircle_triggered();

    void on_actionRedSelec_triggered();

    void on_actionUndo_triggered();

private:
    Ui::MainWindow *ui;


private: //variaveis
    QPoint start;
    QPoint end;

    Filter *filter;

    QPen pen;
    QPainter *painter;
    QRubberBand *rubberband;

    Bitmap bmp;
    Bitmap bmp_backup;

    //path do ficheiro para ler e guardar -> e convertido de QString para string no ficheiro cpp;
    std::string name;

    int backup_index;
    vector<QImage>backup_vector;

    QImage image;
    QImage img_backup;

};
#endif // MAINWINDOW_H
