#include "kStats_view.h"
#include <QMainWindow>
#include <iostream>
#include "../controller/kStatsController.h"
#include <QDebug>
#include <QPicture>
#include <chrono>
kStatsController ApplicationController;
//GPU
std::vector<std::string> GPUBrands{"intel", "amd","asus"};
std::vector<QString> GPUBrandIcons{"url(:/images/intel-logo.png)","url(:/images/amd.svg)","url(:/images/asus-logo.png)"};

//Peripherals
std::vector<std::string> peripheralTypes{"keyboard", "headphones", "mouse", "monitor"};
std::vector<QString> peripheralIcons{"url(:/images/keyboard.svg)","url(:/images/headphones.svg)","url(:/images/mouse.svg)","url(:/images/monitor.svg)"};


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
    if(stackedWidget->currentIndex() == 1)
        return;

    threadPool.push([=] {
        displayCPUTemperature();
    });
    stackedWidget->setCurrentIndex(1);
}

void Ui_MainWindow::on_fansButton_clicked()
{
    if(stackedWidget->currentIndex() == 2)
        return;

    threadPool.push([=] {
        setupFanSpeed();
        displayFanSpeed();
    });



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

void Ui_MainWindow::on_testConnectionSpeedButton_clicked() {
    if (!ApplicationController.isTestingConnection()) {

        //        std::this_thread::sleep_for(std::chrono::seconds(3));
        ApplicationController.lockConnectionSpeedTest();

        threadPool.push([=] {
        QString bestServer = QString::fromStdString(ApplicationController.getBestServer());
        networkServer->setText(bestServer);

        QString download_speed = QString::number(ApplicationController.getDownloadSpeed()) + " Mb/s";

        downloadSpeedTable->setText(download_speed);
        downloadSpeed->setText(download_speed);
        Animation::circuralProgressAnimation(circuralProgressDownloadSpeed);
        Animation::circuralProgressAnimation(circuralProgressUploadSpeed);

        QString upload_speed = QString::number(ApplicationController.getUploadSpeed()) + " Mb/s";

        uploadSpeedTable->setText(upload_speed);
        uploadSpeed->setText(upload_speed);
        connectionPing->setText(QString::number(ApplicationController.getLatency()));
        ApplicationController.closeConnectionSpeedTest();
        //networkServer->setText(QString::fromStdString());
        });
    }
}
//
//void Ui_MainWindow::setContainerContent(QLabel *&container ) {
//
//}
//
void Ui_MainWindow::setupNetworkInfo() {
    ssidName->setText(QString::fromStdString(ApplicationController.getWifiSSID()));
    ipv4Address->setText(QString::fromStdString(ApplicationController.getWifiIP()));
    ipv6Address->setText(QString::fromStdString(ApplicationController.getAddressIPv6()));
    macAddress->setText(QString::fromStdString(ApplicationController.getWifiMacAddress()));
}

void applyLabelAndPicture(const std::vector<std::string>& dataName,
                          const std::vector<QLabel*>& icons,
                          const std::vector<QLabel*>& labels,
                          const std::vector<QString>& deviceIconPath,
                          const std::vector<std::string>& deviceName,
                          const std::vector<std::string>& dataType = std::vector<std::string>()) {


    for(int i = 0; i < dataName.size(); i++) {
        std::string dataLowerCase;
        if (dataType.empty())
            dataLowerCase = dataName[i];
        else
            dataLowerCase = dataType[i];

        std::transform(dataLowerCase.begin(), dataLowerCase.end(), dataLowerCase.begin(), ::tolower);
        int iconIndex = -1;
        for(int j = 0; j< deviceName.size(); j++) {
            if (dataLowerCase.find(deviceName[j]) != std::string::npos) {
                iconIndex = j;
                break;
            }
        }

        if(iconIndex != -1) {
            icons[i]->setStyleSheet( "image: " + deviceIconPath[iconIndex]);
            labels[i]->setText(QString::fromStdString(dataName[i]));
        } else
            std::cout << "Unknown GPU BRAND: " << dataName[i] << std::endl;
    }
}
//
//void applyLabelAndPicture(const std::vector<std::string>& dataName,
//                          const std::vector<std::string>& dataType,
//                          const std::vector<QLabel*>& icons,
//                          const std::vector<QLabel*>& labels,
//                          const std::vector<QString>& deviceIconPath,
//                          const std::vector<std::string>& deviceName) {
//    for(int i = 0; i < dataType.size(); i++) {
//        auto dataLowerCase = dataType[i];
//        std::transform(dataLowerCase.begin(), dataLowerCase.end(), dataLowerCase.begin(), ::tolower);
//        int brandIndex = -1;
//        for(int j = 0; j< deviceName.size(); j++) {
//            if (dataLowerCase.find(deviceName[j]) != std::string::npos) {
//                brandIndex = j;
//                break;
//            }
//        }
//
//        if(brandIndex!=-1) {
//            icons[i]->setStyleSheet( "image: " + deviceIconPath[brandIndex]);
//            labels[i]->setText(QString::fromStdString(dataType[i]));
//        } else
//            std::cout<<"Unknown GPU BRAND: " << dataType[i]<<std::endl;
//    }
//}
void Ui_MainWindow::displayGPU() {

        std::vector<std::string> gpuNumber = ApplicationController.getEachGPUModelName();
        std::vector<QLabel*> graphicsIcon{graphicsIcon_1, graphicsIcon_2};
        std::vector<QLabel*> graphicsLabel{graphicsModel_1, graphicsModel_2};
        applyLabelAndPicture(gpuNumber, graphicsIcon, graphicsLabel,GPUBrandIcons, GPUBrands);
}

void Ui_MainWindow::displayPeripherals() {

        std::vector<GenericPeripheral> peripherals = ApplicationController.getDevices();
        std::vector<std::string> deviceNames = ApplicationController.getDeviceNames();
        std::vector<std::string> deviceTypes = ApplicationController.getDeviceTypes();
        for(auto x : peripherals)
            std::cout<<"here"<<x.deviceType()<<std::endl;

        std::cout<<deviceNames.capacity();
        std::vector<QLabel*> deviceIcon{peripheralIcon_1, peripheralIcon_2, peripheralIcon_3, peripheralIcon_4};
        std::vector<QLabel*> deviceLabel{peripheralName_1,peripheralName_2,peripheralName_3,peripheralName_4};
        applyLabelAndPicture(deviceNames, deviceIcon, deviceLabel, peripheralIcons, peripheralTypes, deviceTypes);
}

void Ui_MainWindow::setupHomeInfo() {
    //todo: write a function to retrieve modelName and osVersion
    threadPool.push([=] {
        processorModel->setText(QString::fromStdString(ApplicationController.getCPUProcessorModel()));
        totalMassMemoryCount->setText(QString::number(ApplicationController.getVolumeStorageTotalMemory()) + " GB");
    });

    threadPool.push([=] {
        displayGPU();
    });

    threadPool.push([=] {
        displayPeripherals();
    });
}

void Ui_MainWindow::setupCPU() {
    threadPool.push([=] {
        cpuModelName->setText(QString::fromStdString(ApplicationController.getCPUProcessorModel()));
        cpuArchitecture->setText(QString::fromStdString(ApplicationController.getCPUArchitecture()));
        cpuCache->setText(QString::number(ApplicationController.getCPUCacheSize()) + " MB");
        cpuCores->setText(QString::number(ApplicationController.getCPUPhysicalCoreCount()));
    });

    threadPool.push([=] {
        displayCPUTemperature();
    });
    //todo: create condition variable and mutex for View
}

void Ui_MainWindow::displayCPUTemperature() {
    std::vector<QLabel *> cpuTemperatureLabels{cpuTemperatureCore_1, cpuTemperatureCore_2, cpuTemperatureCore_3,
                                               cpuTemperatureCore_4, cpuTemperatureCore_5, cpuTemperatureCore_6,
                                               cpuAverageTemperature, cpuTemperaturePeci};
    std::array<float, 8> cpuTemperatures{0};

    do {
         cpuTemperatures = ApplicationController.getCPUTemperature();

        for (int i = 0; i < cpuTemperatures.size(); i++)
            cpuTemperatureLabels[i]->setText(QString::number(cpuTemperatures[i])+"\302\260C");

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    } while(stackedWidget->currentIndex() == 1);
}

void Ui_MainWindow::displayFanSpeed() {
    std::array<QLabel *, 2> fanCurrentSpeedLabels{fanLeftCurrentSpeed, fanRightCurrentSpeed};
    std::array<int, 2> fanCurrentSpeed{0};
    std::array<QLabel *, 4> fanMinMaxLabels = {fanLeftMinimumSpeed, fanLeftMaximumSpeed, fanRightMinimumSpeed, fanRightMaximumSpeed};

    std::array<int, 4> fanMinMaxSpeed = ApplicationController.getFansMinMaxSpeed();

    do {
        fanCurrentSpeed = ApplicationController.getFansCurrentSpeed();

        for (int i = 0; i < fanCurrentSpeed.size(); i++)
            fanCurrentSpeedLabels[i]->setText(QString::number(fanCurrentSpeed[i]) + " RPM");

//        for (int i = 0; i < fanMinMaxLabels.size(); i++) {
//            fanMinMaxLabels[i]->setText(QString::number(fanMinMaxSpeed[i]) + "");
//        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    } while (stackedWidget->currentIndex() == 2);
}

void Ui_MainWindow::setupFanSpeed() {
        std::array<QLabel *, 4> fanMinMaxLabels = {fanLeftMinimumSpeed, fanLeftMaximumSpeed, fanRightMinimumSpeed, fanRightMaximumSpeed};
        std::array<int, 4> fanMinMaxSpeed = ApplicationController.getFansMinMaxSpeed();
        for (int i = 0; i < fanMinMaxLabels.size(); i++) {
            fanMinMaxLabels[i]->setText(QString::number(fanMinMaxSpeed[i]) + "");
        }

}