#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QLabel>
#include <QtCore>
#include <QtWidgets>
#include <QTime>
#include <QDate>
#include <QDir>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>


bool serach_db (int id);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QSqlDatabase db;
       db = QSqlDatabase::addDatabase("QSQLITE");  //establish cocntion to database file

       QString db_path = QDir::currentPath();

       db_path = db_path + QString("/farm_list.db"); //set address of database

       db.setDatabaseName(db_path);
       db.open();
       QSqlQuery q;
       QFile file(db_path);

       file.close();

       if (QFile::exists(db_path) == 1) //check if database file exit or not !
       {
           QLabel *status1 = new QLabel(this);
           status1->setText(" ->: conected to database successfully! "); //set status bar
           ui->statusbar->addWidget(status1);


       }
       else if (QFile::exists(db_path) == 0) //check if database file exit or not !
       {
           QLabel *status2 = new QLabel(this);
           status2->setText(" ->Status: Error ,database not found !"); //set status bar
           ui->statusbar->addWidget(status2);
       }


    setStyleSheet("background-color:#dadada;");
    setAutoFillBackground(true);

    setWindowIcon(QIcon(":/icons/icons/logo.png"));

   /* QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
    watch->reset();
    watch->start();*/

    QPixmap px(":/icons/icons/farmer.png");
    ui->label->setPixmap(px);
    ui->label->setGeometry(410,200,201,301);
    if(!px.isNull())
    {
    ui->label->setPixmap(px);
    ui->label->show();
    }

    QPixmap px2(":/icons/icons/welcome.png");
    ui->welcome->setPixmap(px2);
    ui->welcome->setGeometry(413,30,181,201);
    if(!px2.isNull())
    {
    ui->welcome->setPixmap(px2);
    ui->welcome->show();
    }

    QPixmap px1(":/icons/icons/money.png");
    ui->money_icon->setPixmap(px1);
    ui->money_icon->setGeometry(20,290,81,61);
    if(!px1.isNull())
    {
    ui->money_icon->setPixmap(px1);
    ui->money_icon->show();
    }
    ui->balance->setText("0");

db.close();
qDebug()<<serach_db(123)<<endl;
qDebug()<<serach_db(3012)<<endl;
qDebug()<<serach_db(1)<<endl;


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startStopTimer()
{
    if (watch->isRunning())
    {
        ui->startStopButton->setText("Restart");
        watch->pause();
    }
    else
    {
        ui->startStopButton->setText("Pause");
        watch->start();
    }
}


void MainWindow::resetTimer()
{
    ui->startStopButton->setText("Start");
    ui->hundredthsText->setText("00");
    ui->secondsText->setText("00");
    ui->minutesText->setText("00");
    watch->reset();
}

void MainWindow::update()
{
    if (watch->isRunning())
    {
        qint64 time = watch->getTime();
        int h = time / 1000 / 60 / 60;
        int m = (time / 1000 / 60) - (h * 60);
        int s = (time / 1000) - (m * 60);
        int ms = time - (s + (m + (h * 60)) * 60) * 1000;
        int ms_dis = ms / 10;
        if (ms_dis < 10)
        {
            ui->hundredthsText->setText(QStringLiteral("0%1").arg(ms_dis));
        }
        else
        {
            ui->hundredthsText->setText(QStringLiteral("%1").arg(ms_dis));
        }
        if (s < 10)
        {
            ui->secondsText->setText(QStringLiteral("0%1").arg(s));
        }
        else
        {
            ui->secondsText->setText(QStringLiteral("%1").arg(s));
        }
        if (m < 10)
        {
            ui->minutesText->setText(QStringLiteral("0%1").arg(m));
        }
        else
        {
            ui->minutesText->setText(QStringLiteral("%1").arg(m));
        }
    }
}

void MainWindow::on_startStopButton_clicked()
{
    QObject::connect(ui->startStopButton, &QPushButton::clicked,
                     this, &MainWindow::startStopTimer);
    QObject::connect(ui->resetButton, &QPushButton::clicked,
                     this, &MainWindow::resetTimer);

}


void MainWindow::on_creates_farm_clicked()
{
   // <br><font color='#C90'  ><b> Hover the mouse here to update white player score !!</b></font><br>
    QWidget *window = new QWidget;
    window->setWindowTitle("ایجاد مزرعه جدید  ");
    QGridLayout *Layout = new QGridLayout;
    QLabel *id_lbl = new QLabel(" <br><font color='#C90'  ><b>آی دی را وارد کنید </b></font><br>");
    QLineEdit *id = new QLineEdit;

id->setPlaceholderText("آی دی را وارد کنید ");

    QLabel *name_lbl = new QLabel("<br><font color='#C90'  ><b>نام دامداری را وارد کنید </b></font><br>  ");
     QLineEdit *name = new QLineEdit();
name->setPlaceholderText("نام دامداری را وارد کنید ");
    QLabel *cow_lbl = new QLabel("<br><font color='#C90'  ><b>تعداد گاو ها</b></font><br>  ");
    QLineEdit *cow= new QLineEdit;
cow->setPlaceholderText("تعداد گاو ها ");
    QLabel *sheep_lbl = new QLabel("<br><font color='#C90'  ><b>تعداد گوسفند ها </b></font><br>   ");
    QLineEdit *sheep = new QLineEdit;
sheep->setPlaceholderText("تعداد گوسفند ها  ");
    QLabel *hen_lbl = new QLabel("<br><font color='#C90'  ><b>تعداد مرغ ها </b></font><br>   ");
    QLineEdit *hen = new QLineEdit;
hen->setPlaceholderText("تعداد مرغ ها  ");
    QLabel *bos_lbl = new QLabel("<br><font color='#C90'  ><b>درصد تقویت کننده  </b></font><br>  ");
    QLineEdit *booster = new QLineEdit;
booster->setPlaceholderText("درصد تقویت کننده را وارد کنید ");

    QPushButton *button = new QPushButton("ذخیره و شروع بازی");

    QPixmap px2(":/icons/icons/farm.png");
    QLabel * lbl = new QLabel(window);
    lbl->setGeometry(25,25,462,449);
    if(!px2.isNull())
    {
    lbl->setPixmap(px2);
    lbl->show();
    }


    Layout->addWidget(id_lbl, 0, 0);
    Layout->addWidget(id, 0, 1);

    Layout->addWidget(name_lbl, 1, 0);
    Layout->addWidget(name, 1, 1);

    Layout->addWidget(cow_lbl, 2, 0);
    Layout->addWidget(cow, 2, 1);

    Layout->addWidget(sheep_lbl, 3, 0);
    Layout->addWidget(sheep, 3, 1);

    Layout->addWidget(hen_lbl, 4, 0);
    Layout->addWidget(hen, 4, 1);

    Layout->addWidget(bos_lbl,5, 0);
    Layout->addWidget(booster, 5, 1);

    Layout->addWidget(button, 6, 0, 1, 2);
    window->setLayout(Layout);
    window->setFixedSize(550, 550);

    window->show();

    connect(button, &QPushButton::clicked, this, [=]()
            {
        this->id = id->text();
        this->name = name->text();
        this->my_animal[0] =  cow->text().toInt();
        this->my_animal[1] =  sheep->text().toInt();
        this->my_animal[2] =  hen->text().toInt();
        this->my_animal[3] =  booster->text().toInt();

        QSqlDatabase db;
           db = QSqlDatabase::addDatabase("QSQLITE");  //establish cocntion to database file

           QString db_path = QDir::currentPath();

           db_path = db_path + QString("/farm_list.db"); //set address of database

           db.setDatabaseName(db_path);
           db.open();

           QSqlQuery q;
           QString query= "INSERT INTO farm (id,name,hen,cow,sheep,booster)VALUES("+id_lbl->text()+","+name_lbl->text()+cow_lbl->text()+","+sheep_lbl->text()+","+hen_lbl->text()+")";
        qDebug()<<name_lbl->text()<<endl;
         qDebug()<<id_lbl->text()<<endl;
          // q.exec("INSERT INTO farm (id,name,hen,cow,sheep,booster)VALUES(3,\"farm123\",10,20,30,40)");

         QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(update()));
            timer->start(10);
            watch->reset();
            watch->start();

                window->close();
            });
}

void MainWindow::on_creates_market_clicked()
{
    QWidget *window = new QWidget;
    window->setWindowTitle("فروشگاه ابزار و وسایل");
    QGridLayout *Layout = new QGridLayout;
    QLabel *name_lbl = new QLabel("نام دامداری  :");
    QLineEdit *name = new QLineEdit;
    QLabel *id_lbl = new QLabel("آی دی دامداری  :");
    QLineEdit *id = new QLineEdit;

   QSpinBox * water = new  QSpinBox();


     QSpinBox * cow_food = new   QSpinBox();
     QSpinBox * sheep_food = new  QSpinBox();
     QSpinBox * hen_food = new  QSpinBox();
     QSpinBox * booster = new  QSpinBox();
     booster->setRange(0,100);

     water->setToolTip("مقدار آب ");
       cow_food->setToolTip("مقدار غذای گاو ");
         sheep_food->setToolTip("مقدار غذای گوسفند ");
           hen_food->setToolTip("مقدار غذای مرغ ");
             booster->setToolTip("درصد تقویت در تولید محصولات  ");





    QPushButton *button = new QPushButton("نهایی کردن خرید ");

    Layout->addWidget(name_lbl, 0, 1);
    Layout->addWidget(name, 0,0);
    Layout->addWidget(id_lbl, 1,1);
    Layout->addWidget(id, 1, 0);
Layout->addWidget(water, 2, 0);
Layout->addWidget(cow_food, 2, 1);
Layout->addWidget(sheep_food, 2, 2);
Layout->addWidget(hen_food, 2, 3);
Layout->addWidget(booster, 2, 4);



    Layout->addWidget(button, 4, 0, 1, 2);

    window->setLayout(Layout);
    window->setFixedSize(470, 470);

    window->show();

    connect(button, &QPushButton::clicked, this, [=]()
            {

              long long int price =  (water->value() * 250) + (cow_food->value() * 3000) + (sheep_food->value() * 2000) + (hen_food->value() * 1000) + (booster->value() * 3000);
                      QMessageBox::StandardButton reply;

                      reply = QMessageBox::question(this, "پرداخت خرید ", QString::number(price) +"مبلغ کل محصولات شما به تومان  :  ",
                           QMessageBox::Discard | QMessageBox::Yes);


                      if (reply == QMessageBox::Discard)
                      {
                         window->close();

                      }
                      if(reply == QMessageBox::Yes)
                      {
                          QMessageBox msgBox1;
                          if (this->bal >= price)
                          {

                             msgBox1.setInformativeText(" <b>خرید با موفقیت انجام شد   !  </b> ");

                             this->bal = this->bal -  price;
                             msgBox1.show();
                              msgBox1.exec();
                             ui->balance->setText(QString::number(bal));
                                window->close();


                          }
                          else
                          {

                              msgBox1.setInformativeText(" <b>خطا : عدم موجودی کافی ! لطفا ابتدا موجودی را افزایش دهید    !  </b> ");
                              msgBox1.show();
                               msgBox1.exec();
                               window->close();

                          }
                      }

            });

}

void MainWindow::on_farm_list_clicked()
{

    QSqlDatabase db; //estalish new cocntion to read all record of movie to qtablewidget
      db = QSqlDatabase::addDatabase("QSQLITE");

      QString db_path = QDir::currentPath();

      db_path = db_path + QString("/farm_list.db");

      db.setDatabaseName(db_path);
      db.open();
      QSqlQuery q;
      QFile file(db_path);


          QWidget *window = new QWidget;
          window->setWindowTitle("لیست  دامداری ها ");
          QTableView * table = new QTableView(window);

          QGridLayout *Layout = new QGridLayout;
          QPushButton *button = new QPushButton("update list"); //update paly list from database button

          Layout->addWidget(table, 0, 0);

          Layout->addWidget(button, 3, 0, 1, 2);
          window->setLayout(Layout);
          window->setFixedSize(650, 750);
          q.exec("SELECT * FROM farm");

          QSqlQueryModel *mm=new QSqlQueryModel;
          mm->setQuery(q);

        table->setModel(mm);
            table->show();
          window->show();


          connect(button, &QPushButton::clicked, this, [&]()
                  {
              q.exec("SELECT * FROM farm");
   //  window->close();
                  });


}

void MainWindow::on_deposit_btn_clicked()
{

    QWidget *window = new QWidget;
    window->setWindowTitle("افزایش موجودی");
    QGridLayout *Layout = new QGridLayout;
    QLabel *label1 = new QLabel("مبلغ مورد نظر را وارد کنید :");
    QLineEdit *bal = new QLineEdit;
    QPushButton *button1 = new QPushButton("ذخیره و بازگشت");

    Layout->addWidget(label1, 0, 0);
    Layout->addWidget(bal, 0, 1);
    Layout->addWidget(button1, 3, 0, 1, 2);
    window->setLayout(Layout);
    window->setFixedSize(400, 400);

    window->show();


    connect(button1, &QPushButton::clicked, this, [=]()
            {
        if (bal->text().toFloat() > 0 )
        {

              this->bal += bal->text().toFloat();
           ui->balance->setText(QString::number(bal->text().toFloat()));
        QMessageBox msgBox;
        msgBox.setInformativeText(" <b>موجودی شما با موفقیت افزایش یافت  !  </b> ");
          msgBox.show(); //show Informative " about us" msg box
           msgBox.exec();

                window->close();
}
        else
        {
             QMessageBox msgBox1;
            msgBox1.setInformativeText(" <b>لطفا عدد مثبت وارد نمائید   !  </b> ");
              msgBox1.show(); //show Informative " about us" msg box
               msgBox1.exec();
                    window->close();
        }

            });
}

bool serach_db (int id)
{
    QSqlDatabase db;
       db = QSqlDatabase::addDatabase("QSQLITE");  //establish cocntion to database file

       QString db_path = QDir::currentPath();

       db_path = db_path + QString("/farm_list.db"); //set address of database

       db.setDatabaseName(db_path);
       db.open();
       QSqlQuery query;
    query.prepare("SELECT id FROM farm WHERE id = (:"+QString::number(id,10)+")""");
    query.bindValue(":id", id);

    if (query.exec())
    {
       if (query.next())
       {
        return 1;
       }
    }

    return 0;
}


void MainWindow::on_sell_products_clicked()
{

    QWidget *window = new QWidget;
    window->setWindowTitle("محصولات تولید شده ");
    QGridLayout *Layout = new QGridLayout;
this->my_product[0] =
            this->my_product[0] = my_animal[0] + my_animal[1] * ((watch->mTempTime/60000)%50);
            this->my_product[1] =  my_animal[0] + my_animal[1] * ((watch->mTempTime/60000)%50);
            this->my_product[2] =   my_animal[0] + my_animal[1] * ((watch->mTempTime/60000)%30);
            this->my_product[3] =  my_animal[0] + my_animal[1] * ((watch->mTempTime/60000)%40);
            this->my_product[4] =  my_animal[1] * ((watch->mTempTime/60000)%55);
            this->my_product[5] = my_animal[2] * ((watch->mTempTime/60000)%35);

    QLabel *butter = new QLabel(" : کره تولیدی " +  QString::number(my_product[0] )+ " قالب ");
    QLabel *Cheese = new QLabel("پنیر تولیدی : " +  QString::number(my_product[1] )+ " قالب ");
    QLabel *milk = new QLabel("شیر تولیدی : " +  QString::number(my_product[2] ) + " لیتر " );
    QLabel *Dough = new QLabel("دوغ تولیدی : " +  QString::number(my_product[3] ) + " لیتر " );
    QLabel *wool = new QLabel("پشم تولیدی : " + QString::number(my_product[4] )+ " کیلوگرم " );
    QLabel *egg = new QLabel("تخم مرغ تولیدی : " + QString::number(my_product[5] )   + " عدد " );

    QPushButton *button1 = new QPushButton("فروش همه محصولات ");

    Layout->addWidget(butter, 0, 0);
     Layout->addWidget(Cheese, 1, 0);
    Layout->addWidget(milk, 2, 0);
    Layout->addWidget(Dough, 3, 0);
    Layout->addWidget(wool, 4, 0);
    Layout->addWidget(egg, 5, 0);
        Layout->addWidget(button1, 6, 0,1,2);


    window->setLayout(Layout);
    window->setFixedSize(500, 500);

    window->show();


    connect(button1, &QPushButton::clicked, this, [=]()
            {
  long long int price = (  this->my_product[0] * 500) +   (this->my_product[1] *350)  +  (this->my_product[2] * 350)  + (this->my_product[3] * 350)  +  (this->my_product[4] * 700 ) +  (this->my_product[5] * 10);
  this->bal = this->bal + price ;
  ui->balance->setText(QString::number(bal));

  this->my_product[0]=0;
  this->my_product[1]=0;
  this->my_product[2]=0;
  this->my_product[3]=0;
  this->my_product[4]=0;
  this->my_product[5]=0;

  QMessageBox msgBox;
  msgBox.setInformativeText(" <b>محصولات شما فروخته شده اند   !  </b> ");
    msgBox.show(); //show Informative " about us" msg box
     msgBox.exec();

     window->close();
        });

}
