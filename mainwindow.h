#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stopwatch.h>
#include <QLabel>
#include <array>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void startStopTimer();
    void resetTimer();
    void update();

private slots:
    void on_startStopButton_clicked();

    void on_creates_farm_clicked();

    void on_creates_market_clicked();

    void on_farm_list_clicked();

    void on_deposit_btn_clicked();

    void on_sell_products_clicked();

private:
    float bal=0;
     QLabel *status = new QLabel(this);
    Stopwatch * watch;
     Ui::MainWindow *ui;
     QString name,id;
     std::array<int,4> my_animal={0};
       std::array<float,6> my_product={0};

};
#endif // MAINWINDOW_H



