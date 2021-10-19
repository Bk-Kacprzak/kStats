#include "kStats_view.h"
#include <QMainWindow>
#include <iostream>
#include "../controller/kStatsController.h"
kStatsController ApplicationController;

kStatsView::kStatsView(QMainWindow *parent) {
    setupUi(this);
    this->show();
}

void Ui_MainWindow::on_homeButton_clicked()
{
    stackedWidget->setCurrentIndex(0);
}

void Ui_MainWindow::on_cpuButton_clicked()
{
    stackedWidget->setCurrentIndex(1);
}

void Ui_MainWindow::on_fansButton_clicked()
{
    stackedWidget->setCurrentIndex(2);
}

void Ui_MainWindow::on_networkButton_clicked()
{
    stackedWidget->setCurrentIndex(3);
}

void Ui_MainWindow::on_hardwareButton_clicked()
{
    stackedWidget->setCurrentIndex(4);
}

void Ui_MainWindow::on_statisticsButton_clicked()
{
    stackedWidget->setCurrentIndex(5);
    statsTableWidget->verticalHeader()->setVisible(true);
}

void Ui_MainWindow::on_fanLeftChangeSpeedButton_clicked()
{

}

void Ui_MainWindow::on_fanLeftSetAutoSpeedButton_clicked()
{

}

void Ui_MainWindow::on_fanLeftSetMaxSpeedButton_clicked()
{

}

void Ui_MainWindow::on_fanRightChangeSpeedButton_clicked()
{

}

void Ui_MainWindow::on_fanRightSetAutoSpeedButton_clicked()
{

}

void Ui_MainWindow::on_fanRightSetMaxSpeedButton_clicked()
{

}

void Ui_MainWindow::on_testConnectionSpeedButton_clicked()
{
    threadPool.push([=] {if(!ApplicationController.isTestingConnection()) {
        ApplicationController.testConnectionSpeed();
//        std::this_thread::sleep_for(std::chrono::seconds(3));
        const ConnectionStats& network = ApplicationController.getConnectionsStats();
        std::cout<<"network speed download: " <<network.download_speed<<std::endl;
    }});

}
