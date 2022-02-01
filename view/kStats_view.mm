#include "kStats_view.h"
#include <QMainWindow>
#include <iostream>
#include "../controller/kStatsController.h"
#include <QDebug>
#include <QPicture>
#include <chrono>
#include <functional>
#include "../model/Utils/utils.h"

kStatsController ApplicationController;
//GPU
std::vector<std::string> GPUBrands{"intel", "amd","asus"};
std::vector<QString> GPUBrandIcons{"url(:/images/intel-logo.png)","url(:/images/amd.svg)","url(:/images/asus-logo.png)"};
//Peripherals
std::vector<std::string> peripheralTypes{"keyboard", "headphones", "mouse", "monitor"};
std::vector<QString> peripheralIcons{"url(:/images/keyboard.svg)","url(:/images/headphones.svg)","url(:/images/mouse.svg)","url(:/images/monitor.svg)"};



//add mutex everywhere when widget is clicked.
//add condition_variable -> when something is clicked - notify one and stop executing threads.
//if current index doesnt change - wait for 1 sec (create your own timer to do that, when something happens - stop executing)
//if current index changed - notify one, instantly change the widget, concurrently compute what specific thread had to, but don't freeze program for a second.

kStatsView::kStatsView(QMainWindow *parent) {
    setupUi(this);
    this->currentWidgetIndex = 0;
    this->show();
}

//ON_CLICKED EVENTS

void Ui_MainWindow::on_homeButton_clicked()
{
    currentWidgetIndex = 0;
    stackedWidget->setCurrentIndex(0);
}

void Ui_MainWindow::on_cpuButton_clicked()
{
    if(stackedWidget->currentIndex() == 1)
        return;

    currentWidgetIndex = 1;
    stackedWidget->setCurrentIndex(1);
    threadPool.push([=] {
        displayCPUTemperature();
    });
}

void Ui_MainWindow::on_fansButton_clicked()
{
    if(stackedWidget->currentIndex() == 2)
        return;

    currentWidgetIndex = 2;
    stackedWidget->setCurrentIndex(2);
    threadPool.push([=] {
        setupFanSpeed();
        displayFanSpeed();
    });
}

void Ui_MainWindow::on_networkButton_clicked()
{
    if(stackedWidget->currentIndex() == 3)
        return;

    currentWidgetIndex = 3;
    stackedWidget->setCurrentIndex(3);
}

void Ui_MainWindow::on_hardwareButton_clicked()
{
    if(stackedWidget->currentIndex() == 4)
        return;

    currentWidgetIndex = 4;
    stackedWidget->setCurrentIndex(4);

    threadPool.push([=] {
        setupHardware();
        displayBatteryVoltage();
    });
}

void Ui_MainWindow::on_statisticsButton_clicked()
{
    if(stackedWidget->currentIndex() == 5)
        return;

    currentWidgetIndex = 5;
    stackedWidget->setCurrentIndex(5);

    statsTableWidget->verticalHeader()->setVisible(true);
    threadPool.push([=] {
        displayAllTemperatures();
    });
}

//GENERIC DISPLAY METHODS

template<typename containerType, typename inputType, size_t S>
void Ui_MainWindow::displayValues(const std::array<containerType, S> &labels, std::function<const std::array<inputType, S>()>getterFunction,
                                  const QString && unit, const int &widgetIndex) {
    std::array<inputType,S> values{0};
    do {
        values = getterFunction();
        for (int i = 0; i < labels.size(); i++)
            labels[i]->setText(QString::number(values[i]) + unit);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    } while (widgetIndex == currentWidgetIndex);
}

template<typename containerType, typename inputType, size_t S>
void Ui_MainWindow::displayValues(const std::array<containerType, S> &labels, std::function<const std::array<inputType, S>()>getterFunction,
                                  const QString & unit, const int &widgetIndex, QTableWidget *tableWidget) {

    std::array<inputType,S> values{0};
    do {
        values = getterFunction();
        for (int i = 0; i < labels.size(); i++)
            labels[i]->setText(QString::number(values[i]) + unit);


        if (tableWidget)
                tableWidget->update();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    } while (widgetIndex == currentWidgetIndex);
}


void addLabelAndPicture(const std::vector<std::string>& dataName,
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
            std::cout << "Unknown Device brand: " << dataName[i] << std::endl;
    }
}

//INITIALIZING METHODS

void Ui_MainWindow::setupHomeInfo() {
    //todo: write a function to retrieve modelName and osVersion
    threadPool.push([=] {
        processorModel->setText(QString::fromStdString(ApplicationController.getCPUProcessorModel()));
        totalMassMemoryCount->setText(QString::number(ApplicationController.getVolumeStorageTotalMemory()) + " GB");
    });

    threadPool.push([=] {
        setupGPU();
    });

    threadPool.push([=] {
        setupPeripherals();
    });
}

void Ui_MainWindow::setupGPU() {
    std::vector<std::string> gpuNumber = ApplicationController.getEachGPUModelName();
    std::vector<QLabel*> graphicsIcon{graphicsIcon_1, graphicsIcon_2};
    std::vector<QLabel*> graphicsLabel{graphicsModel_1, graphicsModel_2};
    addLabelAndPicture(gpuNumber, graphicsIcon, graphicsLabel, GPUBrandIcons, GPUBrands);
}

void Ui_MainWindow::setupPeripherals() {

    std::vector<GenericPeripheral> peripherals = ApplicationController.getDevices();

    std::vector<std::string> deviceNames = ApplicationController.getDeviceNames();
    std::vector<std::string> deviceTypes = ApplicationController.getDeviceTypes();
    std::vector<QLabel*> deviceIcon{peripheralIcon_1, peripheralIcon_2, peripheralIcon_3, peripheralIcon_4};
    std::vector<QLabel*> deviceLabel{peripheralName_1,peripheralName_2,peripheralName_3,peripheralName_4};

    addLabelAndPicture(deviceNames, deviceIcon, deviceLabel, peripheralIcons, peripheralTypes, deviceTypes);
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
}

void Ui_MainWindow::setupNetworkInfo() {
    ssidName->setText(QString::fromStdString(ApplicationController.getWifiSSID()));
    ipv4Address->setText(QString::fromStdString(ApplicationController.getWifiIP()));
    ipv6Address->setText(QString::fromStdString(ApplicationController.getAddressIPv6()));
    macAddress->setText(QString::fromStdString(ApplicationController.getWifiMacAddress()));
}

//Loop METHODS

void Ui_MainWindow::displayCPUTemperature() {
    std::array<QLabel *, 8> cpuTemperatureLabels{cpuTemperatureCore_1, cpuTemperatureCore_2, cpuTemperatureCore_3,
                                               cpuTemperatureCore_4, cpuTemperatureCore_5, cpuTemperatureCore_6,
                                               cpuAverageTemperature, cpuTemperaturePeci};

    displayValues<QLabel*, float,8>(cpuTemperatureLabels, [&] {
        return ApplicationController.getCPUTemperature();
    },"\302\260C", 1);
}

void Ui_MainWindow::displayFanSpeed() {
    std::array<QLabel *, 2> fanCurrentSpeedLabels{fanLeftCurrentSpeed, fanRightCurrentSpeed};
    std::array<QLabel *, 4> fanMinMaxLabels = {fanLeftMinimumSpeed, fanLeftMaximumSpeed, fanRightMinimumSpeed, fanRightMaximumSpeed};
    std::array<int, 2> fanCurrentSpeed{0};
    std::array<int, 4> fanMinMaxSpeed = ApplicationController.getFansMinMaxSpeed();

    displayValues<QLabel*, int, 2>(fanCurrentSpeedLabels, [&] {
        return ApplicationController.getFansCurrentSpeed();
    }, " RPM", 2);
}

void Ui_MainWindow::setupFanSpeed() {
    std::array<QLabel *, 4> fanMinMaxLabels = {fanLeftMinimumSpeed, fanLeftMaximumSpeed, fanRightMinimumSpeed, fanRightMaximumSpeed};
    auto fanMinMaxSpeed = ApplicationController.getFansMinMaxSpeed();
    for (int i = 0; i < fanMinMaxLabels.size(); i++) {
        fanMinMaxLabels[i]->setText(QString::number(fanMinMaxSpeed[i]) + " RPM");
        std::cout<<fanMinMaxSpeed[i]<<std::endl;
    }
}

void Ui_MainWindow::on_testConnectionSpeedButton_clicked() {
    if (ApplicationController.isTestingConnection())
        return;

    ApplicationController.lockConnectionSpeedTest();
    threadPool.push([&] {
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
    });
}


void Ui_MainWindow::setupHardware() {
    massMemoryModel->setText(QString::fromStdString(ApplicationController.getVolumeStorageName()));
    massAvailableMemory->setText(QString::number(ApplicationController.getVolumeStorageFreeMemory()) +" GB");
    massTotalMemory->setText(QString::number(ApplicationController.getVolumeStorageTotalMemory()) + " GB");
    massfileFormat->setText(QString::fromStdString(ApplicationController.getVolumeStorageFormatDescription()));
    batteryCycleCount->setText(QString::number(ApplicationController.getCycleCount()));
}

void Ui_MainWindow::displayBatteryVoltage() {
    std::array<QLabel *, 3> batteryVoltageLabels{batteryCellVoltage_1, batteryCellVoltage_2,batteryCellVoltage_3};
    std::array<float , 3> batteryVoltage{0};
        displayValues<QLabel*, float,3>(batteryVoltageLabels, [&] {
            return ApplicationController.getEachBatteryVoltage();
        }," V", 4);
}



void Ui_MainWindow::displayAllTemperatures() {
    std::array<QTableWidgetItem*, 8>  cpuTempLabels = (getLabels<8>(1, 8));
    std::array<QTableWidgetItem*, 3>  batteryVoltageLabels = (getLabels<3>(10, 12));
    std::array<QTableWidgetItem*, 3>  batteryAmperageLabels = (getLabels<3>(13, 15));
    std::array<QTableWidgetItem*, 4>  gpuTempLabels = (getLabels<4>(17, 20));

    threadPool.push([=]{
        displayValues<QTableWidgetItem*, float,3>(batteryVoltageLabels, [&] {
            return ApplicationController.getEachBatteryVoltage();
        }," V", 5, statsTableWidget);
    });

    threadPool.push([=]{
        displayValues<QTableWidgetItem*, float ,8>(cpuTempLabels, [&] {
            return ApplicationController.getCPUTemperature();
        },"\302\260C ", 5, statsTableWidget);
    });
}

template<size_t S>
std::array<QTableWidgetItem *, S> Ui_MainWindow::getLabels(short begin, short end) {
    std::array<QTableWidgetItem *, S> labels{nullptr};

    int index = 0;
    for(int i = begin; i <= end; i++) {
        labels[index] = statsTableWidget->item(i,0);
        qDebug()<<labels[index]->text();
        index++;
    }
    return labels;
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





//void Ui_MainWindow::displayBatteryCapacity() {
//    std::array<QLabel *, 3> batteryCapacityLabels{batteryCellCapacity_1, batteryCellCapacity_2, batteryCellCapacity_3};
//    std::array<int, 3> batteryCapacity{0};
//
//        batteryCapacity = ApplicationController.getEachBatteryCapacity();
//        for (int i = 0; i < batteryCapacityLabels.size(); i++)
//            batteryCapacityLabels[i]->setText(QString::number(batteryCapacity[i]) + " Wh");
//
//}
