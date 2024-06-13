#include "mainwindow.h"
#include "ui_mainwindow.h"


//func auxiliares//////////////////////////////////////
void load_qimage(QImage& image,Bitmap& bmp) //func auxiliar para carregar o obj
                                //QImage com os dados do vetor do bmp
{
    int width = bmp.imgWidth();
    int height = bmp.imgHeight();
    int i_atual=0;

    for (int row=0;row<height;row++)
    {
        for (int col=0;col<width;col++)
        {
            i_atual= row*width+col;

           //como os bmp sao guardados invertidos temos de fazer estas contas para cada pixel ficar na posição correta//

            image.setPixel(col,height - row - 1,qRgb((int)bmp[i_atual].getr(),(int)bmp[i_atual].getg(),(int)bmp[i_atual].getb()));
        }
    }
}
void load_bmap(QImage& image,Bitmap& bmp) //func auxiliar para carregar o obj
                                //QImage com os dados do vetor do bmp
{
    int width = image.size().width();
    int height = image.size().height();
    int i_atual=0;

    for (int row=0;row<height;row++)
    {
        for (int col=0;col<width;col++)
        {
            i_atual= row*width+col;

            //como os bmp sao guardados invertidos temos de fazer estas contas para cada pixel ficar na posição correta//
            //ordem inversa da funçao load_qimage;

            QRgb value=image.pixel(col,height-row-1);

            bmp[i_atual].setr((uint8_t)qRed(value));
            bmp[i_atual].setg((uint8_t)qGreen(value));
            bmp[i_atual].setb((uint8_t)qBlue(value));
        }
    }
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    painter = new QPainter();
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    backup_index=0;

    ui->label->setMouseTracking(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}




//Button Actions////////////////////////////////////////

void MainWindow::on_actionOpen_triggered()
{
    QString filter="(*.all)All files, (*.bmp)Bmp files";
    QString file_name = QFileDialog::getOpenFileName(this, "Open File",QDir::homePath(),filter);

    //conversao de QString para string normal
    name = file_name.toUtf8().constData();

    //inicializaçao do bitmap principal e do backup(usos futuros)
    bmp.open(name); bmp_backup.open(name);
    bmp.read(); bmp_backup.read();
    bmp.close(); bmp_backup.close();

    //Da load as imagens para depois dar print para a label
    image.load(file_name);
    img_backup.load(file_name);

    //Da print a label
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->adjustSize();
    ui->label->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->label->setScaledContents(0);
    ui->label->setMouseTracking(false);

}

void MainWindow::on_actionSave_triggered()
{
     bmp.save(name);
}

void MainWindow::on_actionSaveas_triggered()
{
    if(image.size().width()<=0)
        return;
    QString file_name = QFileDialog::getSaveFileName(this,"Save File",QDir::homePath());
    std::string name1 = file_name.toUtf8().constData();
    load_bmap(image,bmp);
    bmp.save(name1);
}

void MainWindow::on_actionClose_triggered()
{

    ui->label->clear();
    ui->label->setMouseTracking(false);
    image = QImage();
    img_backup=image;
}

void MainWindow::on_actionPen_triggered()
{
    if(ui->actionPen->isChecked())
        ui->statusbar->showMessage("Pen draw active...Click on the image");
    else
        ui->statusbar->clearMessage();
}

void MainWindow::on_actionLine_triggered()
{
    if(ui->actionLine->isChecked())
        ui->statusbar->showMessage("Line draw active...Click on the image and drag the mouse");
    else
         ui->statusbar->clearMessage();
}

void MainWindow::on_actionCrop_triggered()
{
    if(ui->actionCrop->isChecked())
        ui->statusbar->showMessage("Crop function active...Select a portion of the image");
    else
        ui->statusbar->clearMessage();
}

void MainWindow::on_actionCircle_triggered()
{
    //
}

void MainWindow::on_actionColor_triggered()
{
  QColor color=QColorDialog::getColor(Qt::black,this,"Choose the color");
  pen.setColor(color);
}


//DEFINIR AQUI AS FUNÇOES DOS FILTROS

void MainWindow::on_actionRedSelec_triggered()
{
    filter = new RedSelectionChannel();
    filter->apply(bmp);
    img_backup=image;
    load_qimage(image,bmp);
    ui->label->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_actionUndo_triggered()
{
    backup_index--;
    if(backup_index<0)
        backup_index=0;

    img_backup= QImage();
    image= QImage();
    image=backup_vector[backup_index];


    ui->label->clear();
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->adjustSize();
}










//MOUSE/////////////////////////////////////////////////

void MainWindow::MainWindow::mousePressEvent(QMouseEvent *ev)
{
        QPoint mouse_pos = ui->label->mapFrom(this, ev->pos());
        start=mouse_pos;
        if(ev->button()== Qt::LeftButton)
        {
            if(mouse_pos.x() <= ui->label->size().width() && mouse_pos.y() <= ui->label->size().height())
            {
                if(mouse_pos.x()>0 && mouse_pos.y()>0)
                {
                    if(ui->actionPen->isChecked())
                    {
                        if(painter->isActive())
                            painter->end();

                         painter->begin(&image);
                         painter->setPen(pen);
                         painter->drawPoint(mouse_pos);
                    }
                    else if(ui->actionCrop->isChecked())
                              {
                                rubberband = new QRubberBand(QRubberBand::Rectangle, ui->label);
                                rubberband->setGeometry(QRect(start,QSize()));
                                rubberband->show();

                              }
                }
            }
        }
        backup_vector.push_back(img_backup);
        backup_index++;

        img_backup=image;

}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint mouse_pos = ui->label->mapFrom(this, ev->pos());
    if(mouse_pos.x() <= ui->label->size().width() && mouse_pos.y() <= ui->label->size().height())
    {
        if(mouse_pos.x()<0 && mouse_pos.y()<0)
        {
            return;
        }
    }

    if(ui->actionPen->isChecked())
    {
        if(painter->isActive())
            painter->end();

        painter->begin(&image);
        painter->setPen(pen);
        painter->drawPoint(mouse_pos);

    }
   else if(ui->actionLine->isChecked())
          {
            if(painter->isActive())
                painter->end();

            image=img_backup;
            painter->begin(&image);

            painter->setPen(pen);
            QLineF line(start,mouse_pos);
            painter->drawLine(line);

          }
    else if (ui->actionSquare->isChecked())
          {
            if(painter->isActive())
                painter->end();

            image=img_backup;
            painter->begin(&image);

            painter->setPen(pen);
            QRectF rect(start,mouse_pos);
            painter->drawRect(rect);

          }
    else if(ui->actionCircle->isChecked())
          {
            if(painter->isActive())
                painter->end();

            image=img_backup;
            painter->begin(&image);

            painter->setPen(pen);
            QRectF rect(start,mouse_pos);
            painter->drawEllipse(rect);

          }
    else if(ui->actionCrop->isChecked())
          {
            if (mouse_pos.x() < (ui->label->size().width()-1) && mouse_pos.y() < (ui->label->size().height()-1))
            {

                rubberband->setGeometry(QRect(start,mouse_pos).normalized());
                end=mouse_pos;
            }
          }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    QPoint mouse_pos = ui->label->mapFrom(this, ev->pos());
          if(ui->actionPen->isChecked())
          {
              backup_vector.push_back(image);
               backup_index++;
          }
         else if(ui->actionSquare->isChecked())
          {
              backup_vector.push_back(img_backup);
               backup_index++;
          }
         else if(ui->actionLine->isChecked())
          {
              backup_vector.push_back(img_backup);
               backup_index++;
          }

         else if(ui->actionCircle->isChecked())
          {
              backup_vector.push_back(img_backup);
               backup_index++;
          }


         else if(ui->actionCrop->isChecked())
              {
                if (mouse_pos.x() < (ui->label->size().width()-1) && mouse_pos.y() < (ui->label->size().height()-1))
                     end=mouse_pos;

                rubberband->hide();
                backup_vector.push_back(img_backup);
                backup_index++;
                img_backup=image;
                image=image.copy(QRect(start,end));
                ui->label->setPixmap(QPixmap::fromImage(image));
                ui->label->adjustSize();
              }

}

