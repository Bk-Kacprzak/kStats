#ifndef KSTATS_VIEW_H_KSTATS_VIEW_H
#define KSTATS_VIEW_H_KSTATS_VIEW_H

#include "qt_libraries.h"
#include <chrono>
#include <time.h>
#include <thread>
#import <QVBoxLayout>
#import <QHBoxLayout>
#include "animation.h"
#include <condition_variable>
#import <QString>
//#include "../controller/kStatsController.h"

QT_BEGIN_NAMESPACE
//kStatsController Controller;

class Ui_MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    //nav buttons
    void on_homeButton_clicked();
    void on_cpuButton_clicked();
    void on_fansButton_clicked();
    void on_networkButton_clicked();
    void on_hardwareButton_clicked();
    void on_statisticsButton_clicked();

    //fans
    void on_fanLeftChangeSpeedButton_clicked();
    void on_fanLeftSetAutoSpeedButton_clicked();
    void on_fanLeftSetMaxSpeedButton_clicked();
    void on_fanRightChangeSpeedButton_clicked();
    void on_fanRightSetAutoSpeedButton_clicked();
    void on_fanRightSetMaxSpeedButton_clicked();

    //internet
    void on_testConnectionSpeedButton_clicked();

private:
    //setup's
    void setupNetworkInfo();
    void setupHomeInfo();
    void setupCPU();
    void setupFanSpeed();
    void setupHardware();
    void setupGPU();
    void setupPeripherals();
    void addLabelAndPicture(const std::vector<std::string>& readDeviceNames,
                            const std::vector<QLabel*>& icons,
                            const std::vector<QLabel*>& labels,
                            const std::vector<QString>& deviceIconPath,
                            const std::vector<std::string>& deviceTypes,
                            const std::vector<std::string>& dataTypes);
    //loop functions
    template<typename containerType, typename inputType, size_t S>
    void displayValues(const std::array<containerType ,S> &,
                       std::function<const std::array<inputType,S>()>,
                       const QString &&,
                       const int &);
    template<typename containerType, typename inputType, size_t S>
    void displayValues(const std::array<containerType ,S> &,
                       std::function<const std::array<inputType,S>()>,
                       const QString &,
                       const int &,
                       QTableWidget* tableWidget);

    void displayBatteryTotalAmperage();
    void displayCPUTemperature();
    void displayFanSpeed();
    void displayBatteryVoltage();
    void displayBatteryCapacity();
    void displayAllTemperatures();
    void displayTotalAmperage();

    template<size_t S>
    std::array<QTableWidgetItem *, S> getLabels(short begin, short end);

protected:
    std::atomic<int> currentWidgetIndex;
    void initializeContent();

public:

    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarContainer;
    QFrame *applicationLogo;
    QLabel *label_11;
    QFrame *sidebar;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *homeButton;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *cpuButton;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *fansButton;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *networkButton;
    QHBoxLayout *horizontalLayout_25;
    QPushButton *hardwareButton;
    QHBoxLayout *horizontalLayout_28;
    QPushButton *statisticsButton;
    QVBoxLayout *verticalLayout_9;
    QFrame *contentContainer;
    QStackedWidget *stackedWidget;
    QWidget *homePage;
    QVBoxLayout *verticalLayout_11;
    QFrame *homePageContainer;
    QVBoxLayout *verticalLayout_14;
    QGridLayout *gridLayout_4;
    QFrame *deviceNameContainer;
    QVBoxLayout *verticalLayout_12;
    QGridLayout *gridLayout_8;
    QLabel *label_41;
    QLabel *label_24;
    QLabel *deviceName;
    QFrame *osContainer;
    QVBoxLayout *verticalLayout_15;
    QGridLayout *gridLayout_2;
    QLabel *label_40;
    QLabel *label_31;
    QLabel *osVersion;
    QFrame *frame_17;
    QFrame *memoryContainer;
    QGridLayout *gridLayout_5;
    QLabel *ramSize;
    QLabel *label_60;
    QLabel *label_28;
    QLabel *totalMassMemoryCount;
    QLabel *label_43;
    QLabel *label_62;
    QLabel *label_29;
    QFrame *processorModelContainer;
    QVBoxLayout *verticalLayout_17;
    QGridLayout *gridLayout_7;
    QLabel *label_51;
    QLabel *label_39;
    QLabel *processorModel;
    QFrame *ipAddressContainer;
    QVBoxLayout *verticalLayout_16;
    QGridLayout *gridLayout_3;
    QLabel *label_44;
    QLabel *label_33;
    QLabel *ipAddress;
    QFrame *frame_18;
    QFrame *frame_15;
    QSpacerItem *verticalSpacer;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_13;
    QFrame *graphicsContainer;
    QVBoxLayout *verticalLayout_21;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_37;
    QPushButton *graphicsLeftButton;
    QPushButton *graphicsRightButton;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *graphics_1;
    QLabel *graphicsIcon_1;
    QLabel *graphicsModel_1;
    QHBoxLayout *graphics_2;
    QLabel *graphicsIcon_2;
    QLabel *graphicsModel_2;
    QSpacerItem *horizontalSpacer;
    QFrame *peripheralsContainer;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_47;
    QPushButton *graphicsLeftButton_2;
    QPushButton *graphicsRightButton_2;
    QGridLayout *gridLayout;
    QVBoxLayout *peripheral_1;
    QLabel *peripheralIcon_1;
    QLabel *peripheralName_1;
    QVBoxLayout *peripheral_2;
    QLabel *peripheralIcon_2;
    QLabel *peripheralName_2;
    QVBoxLayout *peripheral_3;
    QLabel *peripheralIcon_3;
    QLabel *peripheralName_3;
    QVBoxLayout *peripheral_4;
    QLabel *peripheralIcon_4;
    QLabel *peripheralName_4;
    QWidget *cpuPage;
    QVBoxLayout *verticalLayout_13;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_21;
    QFrame *cpuAverageTemperatureContainer;
    QVBoxLayout *verticalLayout_32;
    QFrame *chart_container;
    QHBoxLayout *horizontalLayout_22;
    QFrame *circularProgressBarBase_4;
    QFrame *circuralProgressCpuAvgTemperature;
    QFrame *circuralBg_6;
    QFrame *circuralContainer_6;
    QVBoxLayout *verticalLayout_37;
    QLabel *cpuAverageTemperature;
    QLabel *label_84;
    QFrame *cpuUsageContainer;
    QVBoxLayout *verticalLayout_40;
    QFrame *chart_container_3;
    QHBoxLayout *horizontalLayout_23;
    QFrame *circularProgressBarBase_5;
    QFrame *circuralProgressCpuUsage;
    QFrame *circuralBg_7;
    QFrame *circuralContainer_7;
    QVBoxLayout *verticalLayout_39;
    QLabel *cpuUsage;
    QLabel *label_85;
    QFrame *cpuInformationContainer;
    QVBoxLayout *verticalLayout_29;
    QFrame *frame_19;
    QVBoxLayout *verticalLayout_44;
    QGridLayout *gridLayout_10;
    QVBoxLayout *cpuCacheContainer;
    QLabel *label_76;
    QLabel *cpuCache;
    QVBoxLayout *verticalLayout_25;
    QLabel *label_70;
    QLabel *label_72;
    QFrame *frame_21;
    QVBoxLayout *cpuThreadsContainer;
    QLabel *label_80;
    QLabel *cpuThreads;
    QVBoxLayout *cpuCoresContainer;
    QLabel *label_83;
    QLabel *cpuCores;
    QVBoxLayout *cpuClockMaxContainer;
    QLabel *label_74;
    QLabel *cpuClockMax;
    QVBoxLayout *cpuArchitecureContainer;
    QLabel *label_71;
    QLabel *cpuArchitecture;
    QFrame *frame_22;
    QFrame *frame_25;
    QFrame *frame_24;
    QFrame *frame_23;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_78;
    QSpacerItem *horizontalSpacer_7;
    QLabel *cpuModelName;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_35;
    QFrame *cpuTemperatureCoreContainer_1;
    QVBoxLayout *verticalLayout_33;
    QFrame *chart_container_6;
    QHBoxLayout *horizontalLayout_27;
    QFrame *circularProgressBarBase_10;
    QFrame *circuralProgressCpuTemperatureCore_1;
    QFrame *circuralBg_12;
    QFrame *circuralContainer_12;
    QVBoxLayout *verticalLayout_38;
    QLabel *cpuTemperatureCore_1;
    QLabel *label_90;
    QSpacerItem *horizontalSpacer_3;
    QFrame *cpuTemperatureCoreContainer_2;
    QVBoxLayout *verticalLayout_46;
    QFrame *chart_container_5;
    QHBoxLayout *horizontalLayout_26;
    QFrame *circularProgressBarBase_9;
    QFrame *circuralProgressCpuTemperatureCore_2;
    QFrame *circuralBg_11;
    QFrame *circuralContainer_11;
    QVBoxLayout *verticalLayout_47;
    QLabel *cpuTemperatureCore_2;
    QLabel *label_89;
    QSpacerItem *horizontalSpacer_4;
    QFrame *cpuTemperatureCoreContainer_3;
    QVBoxLayout *verticalLayout_48;
    QFrame *chart_container_7;
    QHBoxLayout *horizontalLayout_29;
    QFrame *circularProgressBarBase_11;
    QFrame *circuralProgressCpuTemperatureCore_3;
    QFrame *circuralBg_13;
    QFrame *circuralContainer_13;
    QVBoxLayout *verticalLayout_50;
    QLabel *cpuTemperatureCore_3;
    QLabel *label_91;
    QHBoxLayout *horizontalLayout_36;
    QFrame *cpuTemperatureCoreContainer_4;
    QVBoxLayout *verticalLayout_53;
    QFrame *chart_container_9;
    QHBoxLayout *horizontalLayout_31;
    QFrame *circularProgressBarBase_13;
    QFrame *circuralProgressCpuTemperatureCore_4;
    QFrame *circuralBg_15;
    QFrame *circuralContainer_15;
    QVBoxLayout *verticalLayout_55;
    QLabel *cpuTemperatureCore_4;
    QLabel *label_93;
    QSpacerItem *horizontalSpacer_5;
    QFrame *cpuTemperatureCoreContainer_5;
    QVBoxLayout *verticalLayout_57;
    QFrame *chart_container_10;
    QHBoxLayout *horizontalLayout_33;
    QFrame *circularProgressBarBase_14;
    QFrame *circuralProgressCpuTemperatureCore_5;
    QFrame *circuralBg_16;
    QFrame *circuralContainer_16;
    QVBoxLayout *verticalLayout_58;
    QLabel *cpuTemperatureCore_5;
    QLabel *label_94;
    QSpacerItem *horizontalSpacer_6;
    QFrame *cpuTemperatureCoreContainer_6;
    QVBoxLayout *verticalLayout_59;
    QFrame *chart_container_11;
    QHBoxLayout *horizontalLayout_34;
    QFrame *circularProgressBarBase_15;
    QFrame *circuralProgressCpuTemperatureCore_6;
    QFrame *circuralBg_17;
    QFrame *circuralContainer_17;
    QVBoxLayout *verticalLayout_60;
    QLabel *cpuTemperatureCore_6;
    QLabel *label_95;
    QFrame *cpuTemperaturePeciContainer;
    QVBoxLayout *verticalLayout_51;
    QFrame *chart_container_8;
    QHBoxLayout *horizontalLayout_30;
    QFrame *circularProgressBarBase_12;
    QFrame *circuralProgressCpuTemperatureCorePECI;
    QFrame *circuralBg_14;
    QFrame *circuralContainer_14;
    QVBoxLayout *verticalLayout_52;
    QLabel *cpuTemperaturePeci;
    QLabel *label_92;
    QWidget *fansPage;
    QVBoxLayout *verticalLayout_30;
    QFrame *fansPageContainer;
    QVBoxLayout *verticalLayout_43;
    QHBoxLayout *fanLeftContainer;
    QFrame *frame_28;
    QVBoxLayout *verticalLayout_41;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_31;
    QGridLayout *gridLayout_9;
    QLabel *label_86;
    QLabel *fanLeftMaximumSpeed;
    QLabel *label_77;
    QLabel *fanLeftMinimumSpeed;
    QLabel *label_38;
    QLabel *fanLeftCurrentSpeed;
    QFrame *frame_26;
    QLabel *label_87;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *fanLeftChangeSpeedButton;
    QPushButton *fanLeftSetAutoSpeedButton;
    QPushButton *fanLeftSetMaxSpeedButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_9;
    QFrame *frame_29;
    QVBoxLayout *verticalLayout_42;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_36;
    QGridLayout *gridLayout_11;
    QLabel *label_65;
    QFrame *frame_27;
    QLabel *label_96;
    QLabel *fanRightMinimumSpeed;
    QLabel *label_98;
    QLabel *fanRightCurrentSpeed;
    QLabel *fanRightMaximumSpeed;
    QLabel *label_97;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *fanRightChangeSpeedButton;
    QPushButton *fanRightSetAutoSpeedButton;
    QPushButton *fanRightSetMaxSpeedButton;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_4;
    QWidget *networkPage;
    QVBoxLayout *verticalLayout_49;
    QFrame *fansPageContainer_2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *NetworkContainer;
    QHBoxLayout *horizontalLayout_45;
    QLabel *label_99;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *ssidContainer;
    QLabel *networkIcon;
    QLabel *ssidName;
    QFrame *frame_30;
    QGridLayout *ipv4AddressContainer;
    QLabel *label_69;
    QLabel *ipv4Address;
    QFrame *frame_32;
    QGridLayout *ipv6AddressContainer;
    QLabel *label_101;
    QLabel *ipv6Address;
    QFrame *frame_33;
    QGridLayout *macAddressContainer;
    QLabel *label_104;
    QLabel *macAddress;
    QFrame *frame_34;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_106;
    QPushButton *testConnectionSpeedButton;
    QFrame *frame_35;
    QHBoxLayout *horizontalLayout_39;
    QHBoxLayout *horizontalLayout_37;
    QFrame *downloadSpeedContainer;
    QVBoxLayout *verticalLayout_68;
    QFrame *chart_container_2;
    QHBoxLayout *horizontalLayout_24;
    QFrame *circularProgressBarBase_6;
    QFrame *circuralProgressDownloadSpeed;
    QFrame *circuralBg_8;
    QFrame *circuralContainer_8;
    QVBoxLayout *verticalLayout_56;
    QLabel *downloadSpeed;
    QLabel *chart_percentage_20;
    QSpacerItem *horizontalSpacer_19;
    QFrame *UploadSpeedContainer;
    QVBoxLayout *verticalLayout_70;
    QFrame *chart_container_13;
    QHBoxLayout *horizontalLayout_38;
    QFrame *circularProgressBarBase_16;
    QFrame *circuralProgressUploadSpeed;
    QFrame *circuralBg_18;
    QFrame *circuralContainer_18;
    QVBoxLayout *verticalLayout_67;
    QLabel *uploadSpeed;
    QLabel *chart_percentage_23;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *networkInformationContainer;
    QGridLayout *networkServerContainer;
    QLabel *label_107;
    QLabel *networkServer;
    QFrame *frame_36;
    QGridLayout *downloadSpeedTableContainer;
    QLabel *label_112;
    QLabel *downloadSpeedTable;
    QFrame *frame_38;
    QGridLayout *uploadSpeedTableContainer;
    QLabel *label_114;
    QLabel *uploadSpeedTable;
    QFrame *frame_39;
    QGridLayout *connectionPingContainer;
    QLabel *label_116;
    QLabel *connectionPing;
    QFrame *frame_40;
    QWidget *hardwarePage;
    QVBoxLayout *verticalLayout_83;
    QFrame *fansPageContainer_3;
    QVBoxLayout *verticalLayout_64;
    QVBoxLayout *verticalLayout_63;
    QHBoxLayout *horizontalLayout_47;
    QLabel *label_131;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_20;
    QLabel *massMemoryModel;
    QFrame *frame_60;
    QGridLayout *massAvailableMemoryContainer;
    QLabel *label_129;
    QLabel *massAvailableMemory;
    QFrame *frame_55;
    QGridLayout *massTotalMemoryContainer;
    QLabel *label_149;
    QLabel *massTotalMemory;
    QFrame *frame_62;
    QGridLayout *massfileFormatContainer;
    QLabel *label_147;
    QLabel *massfileFormat;
    QFrame *frame_61;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_81;
    QVBoxLayout *verticalLayout_72;
    QLabel *label_119;
    QFrame *frame_56;
    QGridLayout *gridLayout_13;
    QLabel *label_120;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_32;
    QVBoxLayout *batteryCellVoltageContainer_1;
    QLabel *label_122;
    QLabel *batteryCellVoltage_1;
    QVBoxLayout *batteryCellCapacityContainer_1;
    QLabel *label_124;
    QLabel *batteryCellCapacity_1;
    QFrame *frame_57;
    QGridLayout *gridLayout_25;
    QLabel *label_121;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_40;
    QVBoxLayout *batteryCellVoltageContainer_2;
    QLabel *label_133;
    QLabel *batteryCellVoltage_2;
    QVBoxLayout *batteryCellCapacityContainer_2;
    QLabel *label_135;
    QLabel *batteryCellCapacity_2;
    QFrame *frame_58;
    QGridLayout *gridLayout_26;
    QLabel *label_137;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_41;
    QVBoxLayout *batteryCellVoltageContainer_3;
    QLabel *label_138;
    QLabel *batteryCellVoltage_3;
    QVBoxLayout *batteryCellCapacityContainer_3;
    QLabel *label_140;
    QLabel *batteryCellCapacity_3;
    QFrame *frame_59;
    QHBoxLayout *horizontalLayout_43;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_42;
    QVBoxLayout *batteryCycleCountContainer;
    QLabel *label_143;
    QLabel *batteryCycleCount;
    QVBoxLayout *batteryAmperageContainer;
    QLabel *label_145;
    QLabel *batteryAmperage;
    QWidget *statisticsPage;
    QVBoxLayout *verticalLayout_66;
    QFrame *fansPageContainer_4;
    QVBoxLayout *verticalLayout_61;
    QFrame *frame_37;
    QVBoxLayout *verticalLayout_62;
    QTableWidget *statsTableWidget;
    void setupUi(QMainWindow *kStatsView)
    {
        if (kStatsView->objectName().isEmpty())
            kStatsView->setObjectName(QString::fromUtf8("kStatsView"));
        kStatsView->resize(1200, 900);
        kStatsView->setMinimumSize(QSize(1000, 900));
        kStatsView->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(kStatsView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        sidebarContainer = new QFrame(centralwidget);
        sidebarContainer->setObjectName(QString::fromUtf8("sidebarContainer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sidebarContainer->sizePolicy().hasHeightForWidth());
        sidebarContainer->setSizePolicy(sizePolicy);
        sidebarContainer->setMinimumSize(QSize(220, 0));
        sidebarContainer->setMaximumSize(QSize(220, 16777215));
        sidebarContainer->setStyleSheet(QString::fromUtf8("background: #1a162e;"));
        sidebarContainer->setFrameShape(QFrame::NoFrame);
        sidebarContainer->setFrameShadow(QFrame::Plain);
        sidebarContainer->setLineWidth(0);
        applicationLogo = new QFrame(sidebarContainer);
        applicationLogo->setObjectName(QString::fromUtf8("applicationLogo"));
        applicationLogo->setGeometry(QRect(0, 10, 191, 81));
        applicationLogo->setFrameShape(QFrame::NoFrame);
        applicationLogo->setFrameShadow(QFrame::Raised);
        applicationLogo->setLineWidth(0);
        label_11 = new QLabel(applicationLogo);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 0, 211, 81));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/images/application-logo.svg);"));
        sidebar = new QFrame(sidebarContainer);
        sidebar->setObjectName(QString::fromUtf8("sidebar"));
        sidebar->setGeometry(QRect(10, 110, 201, 331));
        sidebar->setFrameShape(QFrame::NoFrame);
        sidebar->setFrameShadow(QFrame::Plain);
        sidebar->setLineWidth(0);
        verticalLayout_2 = new QVBoxLayout(sidebar);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));
        homeButton->setMinimumSize(QSize(190, 40));
        homeButton->setMaximumSize(QSize(190, 16777215));
        homeButton->setCursor(QCursor(Qt::PointingHandCursor));
        homeButton->setLayoutDirection(Qt::LeftToRight);
        homeButton->setAutoFillBackground(false);
        homeButton->setStyleSheet(QString::fromUtf8("\n "
                                                    "QPushButton::hover#homeButton\n "
                                                    "{\n "
                                                    "	border:none;\n "
                                                    " 	color: #ff3974;\n "
                                                    "	border-radius:10px;\n "
                                                    "font: 25 25pt \"Helvetica Neue\";\n "
                                                    "};\n "
                                                    "\n "
                                                    "background: #1a162e;\n "
                                                    "background-color: #1a162e;\n "
                                                    "border-radius: 10px;\n "
                                                    "font: 25 23pt \"Helvetica Neue\";\n "
                                                    "letter-spacing: 2px;\n "
                                                    "text-align:left\n "
                                                    ""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resoucres/images/home-icon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        homeButton->setIcon(icon);
        homeButton->setIconSize(QSize(25, 25));
        homeButton->setCheckable(false);
        homeButton->setAutoRepeatInterval(100);
        homeButton->setFlat(false);

        horizontalLayout_8->addWidget(homeButton);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        cpuButton = new QPushButton(sidebar);
        cpuButton->setObjectName(QString::fromUtf8("cpuButton"));
        cpuButton->setMinimumSize(QSize(190, 40));
        cpuButton->setMaximumSize(QSize(190, 16777215));
        cpuButton->setCursor(QCursor(Qt::PointingHandCursor));
        cpuButton->setLayoutDirection(Qt::LeftToRight);
        cpuButton->setAutoFillBackground(false);
        cpuButton->setStyleSheet(QString::fromUtf8("\n "
                                                   "QPushButton::hover#cpuButton\n "
                                                   "{\n "
                                                   "	border:none;\n "
                                                   " 	color: #ff3974;\n "
                                                   "	border-radius:10px;\n "
                                                   "font: 25 25pt \"Helvetica Neue\";\n "
                                                   "};\n "
                                                   "\n "
                                                   "background: #1a162e;\n "
                                                   "background-color: #1a162e;\n "
                                                   "border-radius: 10px;\n "
                                                   "font: 25 23pt \"Helvetica Neue\";\n "
                                                   "letter-spacing: 2px;\n "
                                                   "text-align:left\n "
                                                   ""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resoucres/images/cpu.svg"), QSize(), QIcon::Normal, QIcon::Off);
        cpuButton->setIcon(icon1);
        cpuButton->setIconSize(QSize(25, 25));
        cpuButton->setCheckable(false);
        cpuButton->setAutoRepeatInterval(100);
        cpuButton->setFlat(false);

        horizontalLayout_10->addWidget(cpuButton);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        fansButton = new QPushButton(sidebar);
        fansButton->setObjectName(QString::fromUtf8("fansButton"));
        fansButton->setMinimumSize(QSize(190, 40));
        fansButton->setMaximumSize(QSize(190, 16777215));
        fansButton->setCursor(QCursor(Qt::PointingHandCursor));
        fansButton->setLayoutDirection(Qt::LeftToRight);
        fansButton->setAutoFillBackground(false);
        fansButton->setStyleSheet(QString::fromUtf8("\n "
                                                    "QPushButton::hover#fansButton\n "
                                                    "{\n "
                                                    "	border:none;\n "
                                                    " 	color: #ff3974;\n "
                                                    "	border-radius:10px;\n "
                                                    "font: 25 25pt \"Helvetica Neue\";\n "
                                                    "};\n "
                                                    "\n "
                                                    "background: #1a162e;\n "
                                                    "background-color: #1a162e;\n "
                                                    "border-radius: 10px;\n "
                                                    "font: 25 23pt \"Helvetica Neue\";\n "
                                                    "letter-spacing: 2px;\n "
                                                    "text-align:left\n "
                                                    ""));
        fansButton->setIcon(icon1);
        fansButton->setIconSize(QSize(25, 25));
        fansButton->setCheckable(false);
        fansButton->setAutoRepeatInterval(100);
        fansButton->setFlat(false);

        horizontalLayout_15->addWidget(fansButton);


        verticalLayout_2->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        networkButton = new QPushButton(sidebar);
        networkButton->setObjectName(QString::fromUtf8("networkButton"));
        networkButton->setMinimumSize(QSize(190, 40));
        networkButton->setMaximumSize(QSize(190, 16777215));
        networkButton->setCursor(QCursor(Qt::PointingHandCursor));
        networkButton->setLayoutDirection(Qt::LeftToRight);
        networkButton->setAutoFillBackground(false);
        networkButton->setStyleSheet(QString::fromUtf8("\n "
                                                       "QPushButton::hover#networkButton\n "
                                                       "{\n "
                                                       "	border:none;\n "
                                                       " 	color: #ff3974;\n "
                                                       "	border-radius:10px;\n "
                                                       "font: 25 25pt \"Helvetica Neue\";\n "
                                                       "};\n "
                                                       "\n "
                                                       "background: #1a162e;\n "
                                                       "background-color: #1a162e;\n "
                                                       "border-radius: 10px;\n "
                                                       "font: 25 23pt \"Helvetica Neue\";\n "
                                                       "letter-spacing: 2px;\n "
                                                       "text-align:left\n "
                                                       ""));
        networkButton->setIcon(icon1);
        networkButton->setIconSize(QSize(25, 25));
        networkButton->setCheckable(false);
        networkButton->setAutoRepeatInterval(100);
        networkButton->setFlat(false);

        horizontalLayout_16->addWidget(networkButton);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        hardwareButton = new QPushButton(sidebar);
        hardwareButton->setObjectName(QString::fromUtf8("hardwareButton"));
        hardwareButton->setMinimumSize(QSize(200, 40));
        hardwareButton->setMaximumSize(QSize(190, 16777215));
        hardwareButton->setCursor(QCursor(Qt::PointingHandCursor));
        hardwareButton->setLayoutDirection(Qt::LeftToRight);
        hardwareButton->setAutoFillBackground(false);
        hardwareButton->setStyleSheet(QString::fromUtf8("\n "
                                                        "QPushButton::hover#hardwareButton\n "
                                                        "{\n "
                                                        "	border:none;\n "
                                                        " 	color: #ff3974;\n "
                                                        "	border-radius:10px;\n "
                                                        "font: 25 25pt \"Helvetica Neue\";\n "
                                                        "};\n "
                                                        "\n "
                                                        "background: #1a162e;\n "
                                                        "background-color: #1a162e;\n "
                                                        "border-radius: 10px;\n "
                                                        "font: 25 23pt \"Helvetica Neue\";\n "
                                                        "letter-spacing: 2px;\n "
                                                        "text-align:left\n "
                                                        ""));
        hardwareButton->setIcon(icon1);
        hardwareButton->setIconSize(QSize(25, 25));
        hardwareButton->setCheckable(false);
        hardwareButton->setAutoRepeatInterval(100);
        hardwareButton->setFlat(false);

        horizontalLayout_25->addWidget(hardwareButton);


        verticalLayout_2->addLayout(horizontalLayout_25);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        statisticsButton = new QPushButton(sidebar);
        statisticsButton->setObjectName(QString::fromUtf8("statisticsButton"));
        statisticsButton->setMinimumSize(QSize(190, 40));
        statisticsButton->setMaximumSize(QSize(190, 16777215));
        statisticsButton->setCursor(QCursor(Qt::PointingHandCursor));
        statisticsButton->setLayoutDirection(Qt::LeftToRight);
        statisticsButton->setAutoFillBackground(false);
        statisticsButton->setStyleSheet(QString::fromUtf8("\n "
                                                          "QPushButton::hover#statisticsButton\n "
                                                          "{\n "
                                                          "	border:none;\n "
                                                          " 	color: #ff3974;\n "
                                                          "	border-radius:10px;\n "
                                                          "font: 25 25pt \"Helvetica Neue\";\n "
                                                          "};\n "
                                                          "\n "
                                                          "background: #1a162e;\n "
                                                          "background-color: #1a162e;\n "
                                                          "border-radius: 10px;\n "
                                                          "font: 25 23pt \"Helvetica Neue\";\n "
                                                          "letter-spacing: 2px;\n "
                                                          "text-align:left\n "
                                                          ""));
        statisticsButton->setIcon(icon1);
        statisticsButton->setIconSize(QSize(25, 25));
        statisticsButton->setCheckable(false);
        statisticsButton->setAutoRepeatInterval(100);
        statisticsButton->setFlat(false);

        horizontalLayout_28->addWidget(statisticsButton);


        verticalLayout_2->addLayout(horizontalLayout_28);


        horizontalLayout->addWidget(sidebarContainer);

        contentContainer = new QFrame(centralwidget);
        contentContainer->setObjectName(QString::fromUtf8("contentContainer"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(24);
        contentContainer->setFont(font);
        contentContainer->setStyleSheet(QString::fromUtf8("background-image: url(:/images/background-image.png);"));
        contentContainer->setFrameShape(QFrame::NoFrame);
        contentContainer->setFrameShadow(QFrame::Plain);
        contentContainer->setLineWidth(0);
        verticalLayout_9 = new QVBoxLayout(contentContainer);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(contentContainer);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        homePage = new QWidget();
        homePage->setObjectName(QString::fromUtf8("homePage"));
        verticalLayout_11 = new QVBoxLayout(homePage);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        homePageContainer = new QFrame(homePage);
        homePageContainer->setObjectName(QString::fromUtf8("homePageContainer"));
        homePageContainer->setFrameShape(QFrame::NoFrame);
        homePageContainer->setFrameShadow(QFrame::Plain);
        verticalLayout_14 = new QVBoxLayout(homePageContainer);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(50, -1, 50, -1);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        deviceNameContainer = new QFrame(homePageContainer);
        deviceNameContainer->setObjectName(QString::fromUtf8("deviceNameContainer"));
        deviceNameContainer->setStyleSheet(QString::fromUtf8(""));
        deviceNameContainer->setFrameShape(QFrame::NoFrame);
        deviceNameContainer->setFrameShadow(QFrame::Plain);
        deviceNameContainer->setLineWidth(0);
        verticalLayout_12 = new QVBoxLayout(deviceNameContainer);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_41 = new QLabel(deviceNameContainer);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMinimumSize(QSize(45, 45));
        label_41->setMaximumSize(QSize(60, 60));
        label_41->setStyleSheet(QString::fromUtf8("image: url(:images/devices.svg);\n "
                                                  "image-width: 50px;\n "
                                                  "image-height: 50px;\n "
                                                  "background:none;\n "
                                                  ""));

        gridLayout_8->addWidget(label_41, 0, 0, 1, 1);

        label_24 = new QLabel(deviceNameContainer);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Helvetica Neue"));
        font1.setPointSize(32);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(3);
        label_24->setFont(font1);
        label_24->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));

        gridLayout_8->addWidget(label_24, 0, 1, 1, 1, Qt::AlignBottom);

        deviceName = new QLabel(deviceNameContainer);
        deviceName->setObjectName(QString::fromUtf8("deviceName"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier New"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        deviceName->setFont(font2);
        deviceName->setAutoFillBackground(false);
        deviceName->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                    "background-color:none;\n "
                                                    ""));
        deviceName->setMargin(10);

        gridLayout_8->addWidget(deviceName, 1, 1, 1, 1);


        verticalLayout_12->addLayout(gridLayout_8);


        gridLayout_4->addWidget(deviceNameContainer, 0, 0, 1, 1);

        osContainer = new QFrame(homePageContainer);
        osContainer->setObjectName(QString::fromUtf8("osContainer"));
        osContainer->setStyleSheet(QString::fromUtf8("background:none;"));
        osContainer->setFrameShape(QFrame::NoFrame);
        osContainer->setFrameShadow(QFrame::Plain);
        osContainer->setLineWidth(0);
        verticalLayout_15 = new QVBoxLayout(osContainer);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_40 = new QLabel(osContainer);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setMinimumSize(QSize(45, 45));
        label_40->setMaximumSize(QSize(60, 60));
        label_40->setStyleSheet(QString::fromUtf8("image: url(:/images/appleinc.svg);\n "
                                                  "background:none;"));

        gridLayout_2->addWidget(label_40, 0, 0, 1, 1);

        label_31 = new QLabel(osContainer);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font1);
        label_31->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));

        gridLayout_2->addWidget(label_31, 0, 1, 1, 1, Qt::AlignBottom);

        osVersion = new QLabel(osContainer);
        osVersion->setObjectName(QString::fromUtf8("osVersion"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(osVersion->sizePolicy().hasHeightForWidth());
        osVersion->setSizePolicy(sizePolicy2);
        osVersion->setFont(font2);
        osVersion->setAutoFillBackground(false);
        osVersion->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                   "background-color:none;"));
        osVersion->setMargin(10);

        gridLayout_2->addWidget(osVersion, 1, 1, 1, 1);


        verticalLayout_15->addLayout(gridLayout_2);


        gridLayout_4->addWidget(osContainer, 0, 1, 1, 1);

        frame_17 = new QFrame(homePageContainer);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setMaximumSize(QSize(16777215, 40));
        frame_17->setStyleSheet(QString::fromUtf8("border-bottom: 1px solid #747290;"));
        frame_17->setFrameShape(QFrame::NoFrame);
        frame_17->setFrameShadow(QFrame::Plain);

        gridLayout_4->addWidget(frame_17, 1, 0, 1, 2);

        memoryContainer = new QFrame(homePageContainer);
        memoryContainer->setObjectName(QString::fromUtf8("memoryContainer"));
        memoryContainer->setStyleSheet(QString::fromUtf8(""));
        memoryContainer->setFrameShape(QFrame::NoFrame);
        memoryContainer->setFrameShadow(QFrame::Plain);
        memoryContainer->setLineWidth(0);
        gridLayout_5 = new QGridLayout(memoryContainer);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(22, -1, -1, -1);
        ramSize = new QLabel(memoryContainer);
        ramSize->setObjectName(QString::fromUtf8("ramSize"));
        ramSize->setFont(font2);
        ramSize->setStyleSheet(QString::fromUtf8("letter-spacing: 3px;\n "
                                                  "background:none;"));
        ramSize->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(ramSize, 1, 3, 1, 1);

        label_60 = new QLabel(memoryContainer);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setFont(font1);
        label_60->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));

        gridLayout_5->addWidget(label_60, 0, 2, 1, 1);

        label_28 = new QLabel(memoryContainer);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font1);
        label_28->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));

        gridLayout_5->addWidget(label_28, 0, 1, 1, 1);

        totalMassMemoryCount = new QLabel(memoryContainer);
        totalMassMemoryCount->setObjectName(QString::fromUtf8("totalMassMemoryCount"));
        totalMassMemoryCount->setFont(font2);
        totalMassMemoryCount->setStyleSheet(QString::fromUtf8("letter-spacing: 3px;\n "
                                                              "background:none;"));

        gridLayout_5->addWidget(totalMassMemoryCount, 1, 2, 1, 1);

        label_43 = new QLabel(memoryContainer);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setMinimumSize(QSize(45, 45));
        label_43->setMaximumSize(QSize(60, 60));
        label_43->setStyleSheet(QString::fromUtf8("background:none;\n "
                                                  "image: url(:/images/memory.svg);\n "
                                                  ""));

        gridLayout_5->addWidget(label_43, 0, 0, 1, 1);

        label_62 = new QLabel(memoryContainer);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setFont(font1);
        label_62->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));

        gridLayout_5->addWidget(label_62, 0, 3, 1, 1);

        label_29 = new QLabel(memoryContainer);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                  "background-color:none;"));
        label_29->setMargin(10);

        gridLayout_5->addWidget(label_29, 1, 1, 1, 1);


        gridLayout_4->addWidget(memoryContainer, 4, 0, 1, 2);

        processorModelContainer = new QFrame(homePageContainer);
        processorModelContainer->setObjectName(QString::fromUtf8("processorModelContainer"));
        processorModelContainer->setStyleSheet(QString::fromUtf8(""));
        processorModelContainer->setFrameShape(QFrame::NoFrame);
        processorModelContainer->setFrameShadow(QFrame::Plain);
        processorModelContainer->setLineWidth(0);
        verticalLayout_17 = new QVBoxLayout(processorModelContainer);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(10, -1, -1, -1);
        label_51 = new QLabel(processorModelContainer);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMinimumSize(QSize(45, 45));
        label_51->setMaximumSize(QSize(60, 60));
        label_51->setStyleSheet(QString::fromUtf8("background:none;\n "
                                                  "image: url(:/images/processor.svg);\n "
                                                  ""));

        gridLayout_7->addWidget(label_51, 0, 0, 1, 1);

        label_39 = new QLabel(processorModelContainer);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font1);
        label_39->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));

        gridLayout_7->addWidget(label_39, 0, 1, 1, 1, Qt::AlignBottom);

        processorModel = new QLabel(processorModelContainer);
        processorModel->setObjectName(QString::fromUtf8("processorModel"));
        processorModel->setFont(font2);
        processorModel->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                        "background-color:none;"));
        processorModel->setMargin(10);

        gridLayout_7->addWidget(processorModel, 1, 1, 1, 1);


        verticalLayout_17->addLayout(gridLayout_7);


        gridLayout_4->addWidget(processorModelContainer, 2, 0, 1, 1);

        ipAddressContainer = new QFrame(homePageContainer);
        ipAddressContainer->setObjectName(QString::fromUtf8("ipAddressContainer"));
        ipAddressContainer->setStyleSheet(QString::fromUtf8("background:none;"));
        ipAddressContainer->setFrameShape(QFrame::NoFrame);
        ipAddressContainer->setFrameShadow(QFrame::Plain);
        ipAddressContainer->setLineWidth(0);
        verticalLayout_16 = new QVBoxLayout(ipAddressContainer);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_44 = new QLabel(ipAddressContainer);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setMinimumSize(QSize(45, 45));
        label_44->setMaximumSize(QSize(60, 60));
        label_44->setStyleSheet(QString::fromUtf8("background:none;\n "
                                                  "image: url(:/images/earth.svg);"));

        gridLayout_3->addWidget(label_44, 0, 0, 1, 1);

        label_33 = new QLabel(ipAddressContainer);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font1);
        label_33->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));

        gridLayout_3->addWidget(label_33, 0, 1, 1, 1, Qt::AlignBottom);

        ipAddress = new QLabel(ipAddressContainer);
        ipAddress->setObjectName(QString::fromUtf8("ipAddress"));
        ipAddress->setFont(font2);
        ipAddress->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                   "background-color:none;"));
        ipAddress->setMargin(10);

        gridLayout_3->addWidget(ipAddress, 1, 1, 1, 1);


        verticalLayout_16->addLayout(gridLayout_3);


        gridLayout_4->addWidget(ipAddressContainer, 2, 1, 1, 1);

        frame_18 = new QFrame(homePageContainer);
        frame_18->setObjectName(QString::fromUtf8("frame_18"));
        frame_18->setMaximumSize(QSize(16777215, 40));
        frame_18->setStyleSheet(QString::fromUtf8("border-bottom: 1px solid #747290;"));
        frame_18->setFrameShape(QFrame::NoFrame);
        frame_18->setFrameShadow(QFrame::Plain);

        gridLayout_4->addWidget(frame_18, 5, 0, 1, 2);

        frame_15 = new QFrame(homePageContainer);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setMaximumSize(QSize(16777215, 40));
        frame_15->setStyleSheet(QString::fromUtf8("border-bottom: 1px solid #747290;"));
        frame_15->setFrameShape(QFrame::NoFrame);
        frame_15->setFrameShadow(QFrame::Plain);

        gridLayout_4->addWidget(frame_15, 3, 0, 1, 2);

        gridLayout_4->setRowMinimumHeight(0, 1);
        gridLayout_4->setRowMinimumHeight(1, 1);
        gridLayout_4->setRowMinimumHeight(2, 1);
        gridLayout_4->setRowMinimumHeight(3, 1);
        gridLayout_4->setRowMinimumHeight(4, 1);
        gridLayout_4->setRowMinimumHeight(5, 1);

        verticalLayout_14->addLayout(gridLayout_4);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_14->addItem(verticalSpacer);

        frame_13 = new QFrame(homePageContainer);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_13->sizePolicy().hasHeightForWidth());
        frame_13->setSizePolicy(sizePolicy3);
        frame_13->setFrameShape(QFrame::NoFrame);
        frame_13->setFrameShadow(QFrame::Plain);
        horizontalLayout_13 = new QHBoxLayout(frame_13);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        graphicsContainer = new QFrame(frame_13);
        graphicsContainer->setObjectName(QString::fromUtf8("graphicsContainer"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(graphicsContainer->sizePolicy().hasHeightForWidth());
        graphicsContainer->setSizePolicy(sizePolicy4);
        graphicsContainer->setMaximumSize(QSize(800, 400));
        graphicsContainer->setStyleSheet(QString::fromUtf8("background: #1a172d;\n "
                                                           "border-radius: 20px;"));
        graphicsContainer->setFrameShape(QFrame::NoFrame);
        graphicsContainer->setFrameShadow(QFrame::Plain);
        verticalLayout_21 = new QVBoxLayout(graphicsContainer);
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(20, 20, -1, 20);
        label_37 = new QLabel(graphicsContainer);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy5);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Helvetica Neue"));
        font3.setPointSize(35);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(3);
        label_37->setFont(font3);
        label_37->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 35pt \"Helvetica Neue\";\n "
                                                  "letter-spacing: 1px;\n "
                                                  "background-color:none;"));

        horizontalLayout_14->addWidget(label_37);

        graphicsLeftButton = new QPushButton(graphicsContainer);
        graphicsLeftButton->setObjectName(QString::fromUtf8("graphicsLeftButton"));
        graphicsLeftButton->setMinimumSize(QSize(25, 25));
        graphicsLeftButton->setMaximumSize(QSize(25, 25));
        graphicsLeftButton->setCursor(QCursor(Qt::PointingHandCursor));
        graphicsLeftButton->setAutoFillBackground(false);
        graphicsLeftButton->setStyleSheet(QString::fromUtf8("image: url(:/resoucres/images/arrow-left.svg);\n "
                                                            "norder: 2px solid #303030;\n "
                                                            "border-color: rgb(70, 70, 70);\n "
                                                            "border-radius:20;\n "
                                                            "QPushButton:hover#graphicsLeftButton\n "
                                                            "{\n "
                                                            "  	 background-color:rgb(200,200,200,120);\n "
                                                            "	border-radius:20;\n "
                                                            "};\n "
                                                            "QPushButton:clicked#graphicsLeftButton{\n "
                                                            "	background-color:rgb(150,150,150,120);\n "
                                                            "};"));
        graphicsLeftButton->setIconSize(QSize(25, 25));
        graphicsLeftButton->setAutoRepeatDelay(0);
        graphicsLeftButton->setAutoRepeatInterval(0);
        graphicsLeftButton->setAutoDefault(false);
        graphicsLeftButton->setFlat(true);

        horizontalLayout_14->addWidget(graphicsLeftButton);

        graphicsRightButton = new QPushButton(graphicsContainer);
        graphicsRightButton->setObjectName(QString::fromUtf8("graphicsRightButton"));
        graphicsRightButton->setMinimumSize(QSize(25, 25));
        graphicsRightButton->setMaximumSize(QSize(25, 25));
        graphicsRightButton->setCursor(QCursor(Qt::PointingHandCursor));
        graphicsRightButton->setAutoFillBackground(false);
        graphicsRightButton->setStyleSheet(QString::fromUtf8("image: url(:/resoucres/images/arrow-right.svg);\n "
                                                             "norder: 2px solid #303030;\n "
                                                             "border-color: rgb(70, 70, 70);\n "
                                                             "border-radius:20;\n "
                                                             "QPushButton:hover#homeButton\n "
                                                             "{\n "
                                                             "  	 background-color:rgb(200,200,200,120);\n "
                                                             "	border-radius:20;\n "
                                                             "};\n "
                                                             "QPushButton:clicked#homeButton{\n "
                                                             "	background-color:rgb(150,150,150,120);\n "
                                                             "};"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resoucres/images/arrow-right.svg"), QSize(), QIcon::Normal, QIcon::Off);
        graphicsRightButton->setIcon(icon2);
        graphicsRightButton->setIconSize(QSize(25, 25));
        graphicsRightButton->setAutoRepeatDelay(0);
        graphicsRightButton->setAutoRepeatInterval(0);
        graphicsRightButton->setAutoDefault(false);
        graphicsRightButton->setFlat(true);

        horizontalLayout_14->addWidget(graphicsRightButton);


        verticalLayout_21->addLayout(horizontalLayout_14);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(10, 55, 10, 0);
        graphics_1 = new QHBoxLayout();
        graphics_1->setObjectName(QString::fromUtf8("graphics_1"));
        graphicsIcon_1 = new QLabel(graphicsContainer);
        graphicsIcon_1->setObjectName(QString::fromUtf8("graphicsIcon_1"));
        graphicsIcon_1->setMinimumSize(QSize(45, 45));
        graphicsIcon_1->setMaximumSize(QSize(60, 60));
        graphicsIcon_1->setStyleSheet(QString::fromUtf8("background:none;\n "
                                                        "image: url(:/images/amd.svg);\n "
                                                        "\n "
                                                        ""));

        graphics_1->addWidget(graphicsIcon_1);

        graphicsModel_1 = new QLabel(graphicsContainer);
        graphicsModel_1->setObjectName(QString::fromUtf8("graphicsModel_1"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Helvetica Neue"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(3);
        graphicsModel_1->setFont(font4);
        graphicsModel_1->setStyleSheet(QString::fromUtf8("\n "
                                                         "font: 25 20pt \"Helvetica Neue\";\n "
                                                         "letter-spacing: 1px;\n "
                                                         "background-color:none; margin-left: 10px"));
        graphicsModel_1->setWordWrap(true);

        graphics_1->addWidget(graphicsModel_1);


        verticalLayout_20->addLayout(graphics_1);

        graphics_2 = new QHBoxLayout();
        graphics_2->setObjectName(QString::fromUtf8("graphics_2"));
        graphicsIcon_2 = new QLabel(graphicsContainer);
        graphicsIcon_2->setObjectName(QString::fromUtf8("graphicsIcon_2"));
        graphicsIcon_2->setMinimumSize(QSize(45, 45));
        graphicsIcon_2->setMaximumSize(QSize(60, 60));
        graphicsIcon_2->setStyleSheet(QString::fromUtf8("background:none;\n "));

        graphics_2->addWidget(graphicsIcon_2);

        graphicsModel_2 = new QLabel(graphicsContainer);
        graphicsModel_2->setObjectName(QString::fromUtf8("graphicsModel_2"));
        graphicsModel_2->setFont(font4);
        graphicsModel_2->setStyleSheet(QString::fromUtf8("\n "
                                                         "font: 25 20pt \"Helvetica Neue\";\n "
                                                         "letter-spacing: 1px;\n "
                                                         "background-color:none; margin-left: 10px"));
        graphicsModel_2->setWordWrap(true);

        graphics_2->addWidget(graphicsModel_2);

        verticalLayout_20->addLayout(graphics_2);


        verticalLayout_21->addLayout(verticalLayout_20);


        horizontalLayout_13->addWidget(graphicsContainer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        peripheralsContainer = new QFrame(frame_13);
        peripheralsContainer->setObjectName(QString::fromUtf8("peripheralsContainer"));
        sizePolicy4.setHeightForWidth(peripheralsContainer->sizePolicy().hasHeightForWidth());
        peripheralsContainer->setSizePolicy(sizePolicy4);
        peripheralsContainer->setMaximumSize(QSize(800, 400));
        peripheralsContainer->setStyleSheet(QString::fromUtf8("background: #1a172d;\n "
                                                              "border-radius: 20px;"));
        peripheralsContainer->setFrameShape(QFrame::NoFrame);
        peripheralsContainer->setFrameShadow(QFrame::Plain);
        verticalLayout_18 = new QVBoxLayout(peripheralsContainer);
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(20, 20, -1, 20);
        label_47 = new QLabel(peripheralsContainer);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_47->sizePolicy().hasHeightForWidth());
        label_47->setSizePolicy(sizePolicy6);
        label_47->setFont(font3);
        label_47->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 35pt \"Helvetica Neue\";\n "
                                                  "letter-spacing: 1px;\n "
                                                  "background-color:none;"));

        horizontalLayout_17->addWidget(label_47);

        graphicsLeftButton_2 = new QPushButton(peripheralsContainer);
        graphicsLeftButton_2->setObjectName(QString::fromUtf8("graphicsLeftButton_2"));
        graphicsLeftButton_2->setMinimumSize(QSize(25, 25));
        graphicsLeftButton_2->setMaximumSize(QSize(25, 25));
        graphicsLeftButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        graphicsLeftButton_2->setAutoFillBackground(false);
        graphicsLeftButton_2->setStyleSheet(QString::fromUtf8("image: url(:/resoucres/images/arrow-left.svg);\n "
                                                              "norder: 2px solid #303030;\n "
                                                              "border-color: rgb(70, 70, 70);\n "
                                                              "border-radius:20;\n "
                                                              "QPushButton:hover#graphicsLeftButton\n "
                                                              "{\n "
                                                              "  	 background-color:rgb(200,200,200,120);\n "
                                                              "	border-radius:20;\n "
                                                              "};\n "
                                                              "QPushButton:clicked#graphicsLeftButton{\n "
                                                              "	background-color:rgb(150,150,150,120);\n "
                                                              "};"));
        graphicsLeftButton_2->setIconSize(QSize(25, 25));
        graphicsLeftButton_2->setAutoRepeatDelay(0);
        graphicsLeftButton_2->setAutoRepeatInterval(0);
        graphicsLeftButton_2->setAutoDefault(false);
        graphicsLeftButton_2->setFlat(true);

        horizontalLayout_17->addWidget(graphicsLeftButton_2);

        graphicsRightButton_2 = new QPushButton(peripheralsContainer);
        graphicsRightButton_2->setObjectName(QString::fromUtf8("graphicsRightButton_2"));
        graphicsRightButton_2->setMinimumSize(QSize(25, 25));
        graphicsRightButton_2->setMaximumSize(QSize(25, 25));
        graphicsRightButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        graphicsRightButton_2->setAutoFillBackground(false);
        graphicsRightButton_2->setStyleSheet(QString::fromUtf8("image: url(:/resoucres/images/arrow-right.svg);\n "
                                                               "norder: 2px solid #303030;\n "
                                                               "border-color: rgb(70, 70, 70);\n "
                                                               "border-radius:20;\n "
                                                               "QPushButton:hover#homeButton\n "
                                                               "{\n "
                                                               "  	 background-color:rgb(200,200,200,120);\n "
                                                               "	border-radius:20;\n "
                                                               "};\n "
                                                               "QPushButton:clicked#homeButton{\n "
                                                               "	background-color:rgb(150,150,150,120);\n "
                                                               "};"));
        graphicsRightButton_2->setIcon(icon2);
        graphicsRightButton_2->setIconSize(QSize(25, 25));
        graphicsRightButton_2->setAutoRepeatDelay(0);
        graphicsRightButton_2->setAutoRepeatInterval(0);
        graphicsRightButton_2->setAutoDefault(false);
        graphicsRightButton_2->setFlat(true);

        horizontalLayout_17->addWidget(graphicsRightButton_2);


        verticalLayout_18->addLayout(horizontalLayout_17);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        peripheral_1 = new QVBoxLayout();
        peripheral_1->setObjectName(QString::fromUtf8("peripheral_1"));
        peripheralIcon_1 = new QLabel(peripheralsContainer);
        peripheralIcon_1->setObjectName(QString::fromUtf8("peripheralIcon_1"));
        peripheralIcon_1->setMinimumSize(QSize(45, 45));
        peripheralIcon_1->setMaximumSize(QSize(60, 60));
        peripheralIcon_1->setStyleSheet(QString::fromUtf8("background:none;\n "));
        peripheralIcon_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        peripheral_1->addWidget(peripheralIcon_1, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        peripheralName_1 = new QLabel(peripheralsContainer);
        peripheralName_1->setObjectName(QString::fromUtf8("peripheralName_1"));
        peripheralName_1->setFont(font4);
        peripheralName_1->setStyleSheet(QString::fromUtf8("\n "
                                                          "font: 25 20pt \"Helvetica Neue\";\n "
                                                          "letter-spacing: 1px;\n "
                                                          "background-color:none;"));
        peripheralName_1->setWordWrap(true);

        peripheral_1->addWidget(peripheralName_1, 0, Qt::AlignHCenter);


        gridLayout->addLayout(peripheral_1, 0, 0, 1, 1);

        peripheral_2 = new QVBoxLayout();
        peripheral_2->setObjectName(QString::fromUtf8("peripheral_2"));
        peripheralIcon_2 = new QLabel(peripheralsContainer);
        peripheralIcon_2->setObjectName(QString::fromUtf8("peripheralIcon_2"));
        peripheralIcon_2->setMinimumSize(QSize(45, 45));
        peripheralIcon_2->setMaximumSize(QSize(60, 60));
        peripheralIcon_2->setStyleSheet(QString::fromUtf8("background:none;\n "));
        peripheral_2->addWidget(peripheralIcon_2, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        peripheralName_2 = new QLabel(peripheralsContainer);
        peripheralName_2->setObjectName(QString::fromUtf8("peripheralName_2"));
        peripheralName_2->setFont(font4);
        peripheralName_2->setStyleSheet(QString::fromUtf8("\n "
                                                          "font: 25 20pt \"Helvetica Neue\";\n "
                                                          "letter-spacing: 1px;\n "
                                                          "background-color:none;"));
        peripheralName_2->setWordWrap(true);

        peripheral_2->addWidget(peripheralName_2, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout->addLayout(peripheral_2, 1, 0, 1, 1);

        peripheral_3 = new QVBoxLayout();
        peripheral_3->setObjectName(QString::fromUtf8("peripheral_3"));
        peripheralIcon_3 = new QLabel(peripheralsContainer);
        peripheralIcon_3->setObjectName(QString::fromUtf8("peripheralIcon_3"));
        peripheralIcon_3->setMinimumSize(QSize(45, 45));
        peripheralIcon_3->setMaximumSize(QSize(60, 60));
        peripheralIcon_3->setStyleSheet(QString::fromUtf8("background:none;\n"));

        peripheral_3->addWidget(peripheralIcon_3, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        peripheralName_3 = new QLabel(peripheralsContainer);
        peripheralName_3->setObjectName(QString::fromUtf8("peripheralName_3"));
        peripheralName_3->setFont(font4);
        peripheralName_3->setStyleSheet(QString::fromUtf8("\n "
                                                          "font: 25 20pt \"Helvetica Neue\";\n "
                                                          "letter-spacing: 1px;\n "
                                                          "background-color:none;"));
        peripheralName_3->setWordWrap(true);

        peripheral_3->addWidget(peripheralName_3, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout->addLayout(peripheral_3, 0, 1, 1, 1);

        peripheral_4 = new QVBoxLayout();
        peripheral_4->setObjectName(QString::fromUtf8("peripheral_4"));
        peripheralIcon_4 = new QLabel(peripheralsContainer);
        peripheralIcon_4->setObjectName(QString::fromUtf8("peripheralIcon_4"));
        peripheralIcon_4->setMinimumSize(QSize(45, 45));
        peripheralIcon_4->setMaximumSize(QSize(60, 60));
//        peripheralIcon_4->setStyleSheet(QString::fromUtf8("background:none;\n "
//                                                          "image: url(:/images/headphones.svg);"));

        peripheral_4->addWidget(peripheralIcon_4, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        peripheralName_4 = new QLabel(peripheralsContainer);
        peripheralName_4->setObjectName(QString::fromUtf8("peripheralName_4"));
        peripheralName_4->setFont(font4);
        peripheralName_4->setStyleSheet(QString::fromUtf8("\n "
                                                          "font: 25 20pt \"Helvetica Neue\";\n "
                                                          "letter-spacing: 1px;\n "
                                                          "background-color:none;"));
        peripheralName_4->setWordWrap(true);

        peripheral_4->addWidget(peripheralName_4, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout->addLayout(peripheral_4, 1, 1, 1, 1);


        verticalLayout_18->addLayout(gridLayout);


        horizontalLayout_13->addWidget(peripheralsContainer);


        verticalLayout_14->addWidget(frame_13);


        verticalLayout_11->addWidget(homePageContainer);

        stackedWidget->addWidget(homePage);
        cpuPage = new QWidget();
        cpuPage->setObjectName(QString::fromUtf8("cpuPage"));
        verticalLayout_13 = new QVBoxLayout(cpuPage);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(30, -1, 30, -1);
        horizontalSpacer_2 = new QSpacerItem(48, 13, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        cpuAverageTemperatureContainer = new QFrame(cpuPage);
        cpuAverageTemperatureContainer->setObjectName(QString::fromUtf8("cpuAverageTemperatureContainer"));
        cpuAverageTemperatureContainer->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                        "border:none;"));
        cpuAverageTemperatureContainer->setFrameShape(QFrame::StyledPanel);
        cpuAverageTemperatureContainer->setFrameShadow(QFrame::Raised);
        verticalLayout_32 = new QVBoxLayout(cpuAverageTemperatureContainer);
        verticalLayout_32->setObjectName(QString::fromUtf8("verticalLayout_32"));
        chart_container = new QFrame(cpuAverageTemperatureContainer);
        chart_container->setObjectName(QString::fromUtf8("chart_container"));
        chart_container->setMaximumSize(QSize(16777215, 114));
        chart_container->setFrameShape(QFrame::NoFrame);
        chart_container->setFrameShadow(QFrame::Plain);
        chart_container->setLineWidth(0);
        horizontalLayout_22 = new QHBoxLayout(chart_container);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_4 = new QFrame(chart_container);
        circularProgressBarBase_4->setObjectName(QString::fromUtf8("circularProgressBarBase_4"));
        circularProgressBarBase_4->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_4->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_4->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_4->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_4->setLineWidth(0);
        circuralProgressCpuAvgTemperature = new QFrame(circularProgressBarBase_4);
        circuralProgressCpuAvgTemperature->setObjectName(QString::fromUtf8("circuralProgressCpuAvgTemperature"));
        circuralProgressCpuAvgTemperature->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuAvgTemperature->setMinimumSize(QSize(140, 140));
        circuralProgressCpuAvgTemperature->setMaximumSize(QSize(140, 140));
        circuralProgressCpuAvgTemperature->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuAvgTemperature->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuAvgTemperature->setFrameShadow(QFrame::Plain);
        circuralProgressCpuAvgTemperature->setLineWidth(0);
        circuralBg_6 = new QFrame(circularProgressBarBase_4);
        circuralBg_6->setObjectName(QString::fromUtf8("circuralBg_6"));
        circuralBg_6->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_6->setMinimumSize(QSize(140, 140));
        circuralBg_6->setMaximumSize(QSize(140, 140));
        circuralBg_6->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                      "	border-radius: 70px;\n "
                                                      "	background-color:  #1a172d;\n "
                                                      "}\n "
                                                      "\n "
                                                      ""));
        circuralBg_6->setFrameShape(QFrame::NoFrame);
        circuralBg_6->setFrameShadow(QFrame::Plain);
        circuralBg_6->setLineWidth(0);
        circuralContainer_6 = new QFrame(circularProgressBarBase_4);
        circuralContainer_6->setObjectName(QString::fromUtf8("circuralContainer_6"));
        circuralContainer_6->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_6->setMinimumSize(QSize(110, 110));
        circuralContainer_6->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                             " border-radius:65px;\n "
                                                             "	background: #1a172d;\n "
                                                             "}\n "
                                                             "\n "
                                                             "QFrame:hover {\n "
                                                             "	background-color: #2b283e;\n "
                                                             "}\n "
                                                             ""));
        circuralContainer_6->setFrameShape(QFrame::NoFrame);
        circuralContainer_6->setFrameShadow(QFrame::Plain);
        circuralContainer_6->setLineWidth(0);
        verticalLayout_37 = new QVBoxLayout(circuralContainer_6);
        verticalLayout_37->setSpacing(0);
        verticalLayout_37->setObjectName(QString::fromUtf8("verticalLayout_37"));
        verticalLayout_37->setContentsMargins(0, 0, 0, 0);
        cpuAverageTemperature = new QLabel(circuralContainer_6);
        cpuAverageTemperature->setObjectName(QString::fromUtf8("cpuAverageTemperature"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Courier New"));
        font5.setPointSize(36);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setWeight(50);
        font5.setStrikeOut(false);
        font5.setKerning(true);
        cpuAverageTemperature->setFont(font5);
        cpuAverageTemperature->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                               "color: #afafaf;\n "
                                                               "background:none;"));
        cpuAverageTemperature->setAlignment(Qt::AlignCenter);

        verticalLayout_37->addWidget(cpuAverageTemperature);

        circuralBg_6->raise();
        circuralProgressCpuAvgTemperature->raise();
        circuralContainer_6->raise();

        horizontalLayout_22->addWidget(circularProgressBarBase_4);


        verticalLayout_32->addWidget(chart_container);

        label_84 = new QLabel(cpuAverageTemperatureContainer);
        label_84->setObjectName(QString::fromUtf8("label_84"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_84->sizePolicy().hasHeightForWidth());
        label_84->setSizePolicy(sizePolicy7);
        label_84->setFont(font4);
        label_84->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_84->setAlignment(Qt::AlignCenter);

        verticalLayout_32->addWidget(label_84);


        horizontalLayout_21->addWidget(cpuAverageTemperatureContainer);

        cpuUsageContainer = new QFrame(cpuPage);
        cpuUsageContainer->setObjectName(QString::fromUtf8("cpuUsageContainer"));
        cpuUsageContainer->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                           "border:none;"));
        cpuUsageContainer->setFrameShape(QFrame::StyledPanel);
        cpuUsageContainer->setFrameShadow(QFrame::Raised);
        verticalLayout_40 = new QVBoxLayout(cpuUsageContainer);
        verticalLayout_40->setObjectName(QString::fromUtf8("verticalLayout_40"));
        chart_container_3 = new QFrame(cpuUsageContainer);
        chart_container_3->setObjectName(QString::fromUtf8("chart_container_3"));
        chart_container_3->setMaximumSize(QSize(16777215, 114));
        chart_container_3->setFrameShape(QFrame::NoFrame);
        chart_container_3->setFrameShadow(QFrame::Plain);
        chart_container_3->setLineWidth(0);
        horizontalLayout_23 = new QHBoxLayout(chart_container_3);
        horizontalLayout_23->setSpacing(0);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_5 = new QFrame(chart_container_3);
        circularProgressBarBase_5->setObjectName(QString::fromUtf8("circularProgressBarBase_5"));
        circularProgressBarBase_5->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_5->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_5->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_5->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_5->setLineWidth(0);
        circuralProgressCpuUsage = new QFrame(circularProgressBarBase_5);
        circuralProgressCpuUsage->setObjectName(QString::fromUtf8("circuralProgressCpuUsage"));
        circuralProgressCpuUsage->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuUsage->setMinimumSize(QSize(140, 140));
        circuralProgressCpuUsage->setMaximumSize(QSize(140, 140));
        circuralProgressCpuUsage->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuUsage->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuUsage->setFrameShadow(QFrame::Plain);
        circuralProgressCpuUsage->setLineWidth(0);
        circuralBg_7 = new QFrame(circularProgressBarBase_5);
        circuralBg_7->setObjectName(QString::fromUtf8("circuralBg_7"));
        circuralBg_7->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_7->setMinimumSize(QSize(140, 140));
        circuralBg_7->setMaximumSize(QSize(140, 140));
        circuralBg_7->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                      "	border-radius: 70px;\n "
                                                      "	background-color:  #1a172d;\n "
                                                      "}\n "
                                                      "\n "
                                                      ""));
        circuralBg_7->setFrameShape(QFrame::NoFrame);
        circuralBg_7->setFrameShadow(QFrame::Plain);
        circuralBg_7->setLineWidth(0);
        circuralContainer_7 = new QFrame(circularProgressBarBase_5);
        circuralContainer_7->setObjectName(QString::fromUtf8("circuralContainer_7"));
        circuralContainer_7->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_7->setMinimumSize(QSize(110, 110));
        circuralContainer_7->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                             " border-radius:65px;\n "
                                                             "	background: #1a172d;\n "
                                                             "}\n "
                                                             "\n "
                                                             "QFrame:hover {\n "
                                                             "	background-color: #2b283e;\n "
                                                             "}\n "
                                                             ""));
        circuralContainer_7->setFrameShape(QFrame::NoFrame);
        circuralContainer_7->setFrameShadow(QFrame::Plain);
        circuralContainer_7->setLineWidth(0);
        verticalLayout_39 = new QVBoxLayout(circuralContainer_7);
        verticalLayout_39->setSpacing(0);
        verticalLayout_39->setObjectName(QString::fromUtf8("verticalLayout_39"));
        verticalLayout_39->setContentsMargins(0, 0, 0, 0);
        cpuUsage = new QLabel(circuralContainer_7);
        cpuUsage->setObjectName(QString::fromUtf8("cpuUsage"));
        cpuUsage->setFont(font5);
        cpuUsage->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                  "color: #afafaf;\n "
                                                  "background:none;"));
        cpuUsage->setAlignment(Qt::AlignCenter);

        verticalLayout_39->addWidget(cpuUsage);

        circuralBg_7->raise();
        circuralProgressCpuUsage->raise();
        circuralContainer_7->raise();

        horizontalLayout_23->addWidget(circularProgressBarBase_5);


        verticalLayout_40->addWidget(chart_container_3);

        label_85 = new QLabel(cpuUsageContainer);
        label_85->setObjectName(QString::fromUtf8("label_85"));
        sizePolicy7.setHeightForWidth(label_85->sizePolicy().hasHeightForWidth());
        label_85->setSizePolicy(sizePolicy7);
        label_85->setFont(font4);
        label_85->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_85->setAlignment(Qt::AlignCenter);

        verticalLayout_40->addWidget(label_85);


        horizontalLayout_21->addWidget(cpuUsageContainer);


        gridLayout_6->addLayout(horizontalLayout_21, 3, 0, 1, 1);

        cpuInformationContainer = new QFrame(cpuPage);
        cpuInformationContainer->setObjectName(QString::fromUtf8("cpuInformationContainer"));
        sizePolicy4.setHeightForWidth(cpuInformationContainer->sizePolicy().hasHeightForWidth());
        cpuInformationContainer->setSizePolicy(sizePolicy4);
        cpuInformationContainer->setMaximumSize(QSize(800, 400));
        cpuInformationContainer->setStyleSheet(QString::fromUtf8("background: #1a172d; border-radius: 25px; "));
        cpuInformationContainer->setFrameShape(QFrame::NoFrame);
        cpuInformationContainer->setFrameShadow(QFrame::Plain);
        verticalLayout_29 = new QVBoxLayout(cpuInformationContainer);
        verticalLayout_29->setObjectName(QString::fromUtf8("verticalLayout_29"));
        frame_19 = new QFrame(cpuInformationContainer);
        frame_19->setObjectName(QString::fromUtf8("frame_19"));
        sizePolicy6.setHeightForWidth(frame_19->sizePolicy().hasHeightForWidth());
        frame_19->setSizePolicy(sizePolicy6);
        frame_19->setStyleSheet(QString::fromUtf8("border-radius: 0;\n "
                                                  "background:none;"));
        frame_19->setFrameShape(QFrame::NoFrame);
        frame_19->setFrameShadow(QFrame::Plain);
        frame_19->setLineWidth(0);
        verticalLayout_44 = new QVBoxLayout(frame_19);
        verticalLayout_44->setObjectName(QString::fromUtf8("verticalLayout_44"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        cpuCacheContainer = new QVBoxLayout();
        cpuCacheContainer->setObjectName(QString::fromUtf8("cpuCacheContainer"));
        label_76 = new QLabel(frame_19);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy8.setHorizontalStretch(200);
        sizePolicy8.setVerticalStretch(200);
        sizePolicy8.setHeightForWidth(label_76->sizePolicy().hasHeightForWidth());
        label_76->setSizePolicy(sizePolicy8);
        label_76->setFont(font4);
        label_76->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_76->setAlignment(Qt::AlignCenter);
        label_76->setWordWrap(true);

        cpuCacheContainer->addWidget(label_76);

        cpuCache = new QLabel(frame_19);
        cpuCache->setObjectName(QString::fromUtf8("cpuCache"));
        sizePolicy8.setHeightForWidth(cpuCache->sizePolicy().hasHeightForWidth());
        cpuCache->setSizePolicy(sizePolicy8);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Courier New"));
        font6.setPointSize(16);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        cpuCache->setFont(font6);
        cpuCache->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                  "background-color:none;\n "
                                                  "border:none;\n "
                                                  "margin-left: 10px;"));
        cpuCache->setAlignment(Qt::AlignCenter);
        cpuCache->setWordWrap(true);

        cpuCacheContainer->addWidget(cpuCache);


        gridLayout_10->addLayout(cpuCacheContainer, 0, 1, 1, 1);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        label_70 = new QLabel(frame_19);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        sizePolicy8.setHeightForWidth(label_70->sizePolicy().hasHeightForWidth());
        label_70->setSizePolicy(sizePolicy8);
        label_70->setFont(font4);
        label_70->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_70->setAlignment(Qt::AlignCenter);
        label_70->setWordWrap(true);

        verticalLayout_25->addWidget(label_70);

        label_72 = new QLabel(frame_19);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        sizePolicy8.setHeightForWidth(label_72->sizePolicy().hasHeightForWidth());
        label_72->setSizePolicy(sizePolicy8);
        label_72->setFont(font6);
        label_72->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                  "background-color:none;\n "
                                                  "border:none;\n "
                                                  "margin-left: 10px;"));
        label_72->setAlignment(Qt::AlignCenter);
        label_72->setWordWrap(true);

        verticalLayout_25->addWidget(label_72);


        gridLayout_10->addLayout(verticalLayout_25, 2, 0, 1, 1);

        frame_21 = new QFrame(frame_19);
        frame_21->setObjectName(QString::fromUtf8("frame_21"));
        frame_21->setMinimumSize(QSize(0, 2));
        frame_21->setMaximumSize(QSize(16777215, 10));
        frame_21->setStyleSheet(QString::fromUtf8("border-bottom: 1px solid #747290;"));
        frame_21->setFrameShape(QFrame::NoFrame);
        frame_21->setFrameShadow(QFrame::Plain);

        gridLayout_10->addWidget(frame_21, 3, 0, 1, 2);

        cpuThreadsContainer = new QVBoxLayout();
        cpuThreadsContainer->setObjectName(QString::fromUtf8("cpuThreadsContainer"));
        label_80 = new QLabel(frame_19);
        label_80->setObjectName(QString::fromUtf8("label_80"));
        sizePolicy8.setHeightForWidth(label_80->sizePolicy().hasHeightForWidth());
        label_80->setSizePolicy(sizePolicy8);
        label_80->setFont(font4);
        label_80->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_80->setAlignment(Qt::AlignCenter);
        label_80->setWordWrap(true);

        cpuThreadsContainer->addWidget(label_80);

        cpuThreads = new QLabel(frame_19);
        cpuThreads->setObjectName(QString::fromUtf8("cpuThreads"));
        sizePolicy8.setHeightForWidth(cpuThreads->sizePolicy().hasHeightForWidth());
        cpuThreads->setSizePolicy(sizePolicy8);
        cpuThreads->setFont(font6);
        cpuThreads->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                    "background-color:none;\n "
                                                    "border:none;\n "
                                                    "margin-left: 10px;"));
        cpuThreads->setAlignment(Qt::AlignCenter);
        cpuThreads->setWordWrap(true);

        cpuThreadsContainer->addWidget(cpuThreads);


        gridLayout_10->addLayout(cpuThreadsContainer, 2, 1, 1, 1);

        cpuCoresContainer = new QVBoxLayout();
        cpuCoresContainer->setObjectName(QString::fromUtf8("cpuCoresContainer"));
        label_83 = new QLabel(frame_19);
        label_83->setObjectName(QString::fromUtf8("label_83"));
        sizePolicy8.setHeightForWidth(label_83->sizePolicy().hasHeightForWidth());
        label_83->setSizePolicy(sizePolicy8);
        label_83->setFont(font4);
        label_83->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_83->setAlignment(Qt::AlignCenter);
        label_83->setWordWrap(true);

        cpuCoresContainer->addWidget(label_83);

        cpuCores = new QLabel(frame_19);
        cpuCores->setObjectName(QString::fromUtf8("cpuCores"));
        sizePolicy8.setHeightForWidth(cpuCores->sizePolicy().hasHeightForWidth());
        cpuCores->setSizePolicy(sizePolicy8);
        cpuCores->setFont(font6);
        cpuCores->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                  "background-color:none;\n "
                                                  "border:none;\n "
                                                  "margin-left: 10px;"));
        cpuCores->setAlignment(Qt::AlignCenter);
        cpuCores->setWordWrap(true);

        cpuCoresContainer->addWidget(cpuCores);


        gridLayout_10->addLayout(cpuCoresContainer, 4, 1, 1, 1);

        cpuClockMaxContainer = new QVBoxLayout();
        cpuClockMaxContainer->setObjectName(QString::fromUtf8("cpuClockMaxContainer"));
        label_74 = new QLabel(frame_19);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        sizePolicy8.setHeightForWidth(label_74->sizePolicy().hasHeightForWidth());
        label_74->setSizePolicy(sizePolicy8);
        label_74->setFont(font4);
        label_74->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_74->setAlignment(Qt::AlignCenter);
        label_74->setWordWrap(true);

        cpuClockMaxContainer->addWidget(label_74);

        cpuClockMax = new QLabel(frame_19);
        cpuClockMax->setObjectName(QString::fromUtf8("cpuClockMax"));
        sizePolicy8.setHeightForWidth(cpuClockMax->sizePolicy().hasHeightForWidth());
        cpuClockMax->setSizePolicy(sizePolicy8);
        cpuClockMax->setFont(font6);
        cpuClockMax->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                     "background-color:none;\n "
                                                     "border:none;\n "
                                                     "margin-left: 10px;"));
        cpuClockMax->setAlignment(Qt::AlignCenter);
        cpuClockMax->setWordWrap(true);

        cpuClockMaxContainer->addWidget(cpuClockMax);


        gridLayout_10->addLayout(cpuClockMaxContainer, 4, 0, 1, 1);

        cpuArchitecureContainer = new QVBoxLayout();
        cpuArchitecureContainer->setObjectName(QString::fromUtf8("cpuArchitecureContainer"));
        label_71 = new QLabel(frame_19);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        sizePolicy8.setHeightForWidth(label_71->sizePolicy().hasHeightForWidth());
        label_71->setSizePolicy(sizePolicy8);
        label_71->setFont(font4);
        label_71->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_71->setAlignment(Qt::AlignCenter);
        label_71->setWordWrap(true);

        cpuArchitecureContainer->addWidget(label_71);

        cpuArchitecture = new QLabel(frame_19);
        cpuArchitecture->setObjectName(QString::fromUtf8("cpuArchitecture"));
        sizePolicy8.setHeightForWidth(cpuArchitecture->sizePolicy().hasHeightForWidth());
        cpuArchitecture->setSizePolicy(sizePolicy8);
        cpuArchitecture->setFont(font6);
        cpuArchitecture->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                         "background-color:none;\n "
                                                         "border:none;\n "
                                                         "margin-left: 10px;"));
        cpuArchitecture->setAlignment(Qt::AlignCenter);
        cpuArchitecture->setWordWrap(true);

        cpuArchitecureContainer->addWidget(cpuArchitecture);


        gridLayout_10->addLayout(cpuArchitecureContainer, 0, 0, 1, 1);

        frame_22 = new QFrame(frame_19);
        frame_22->setObjectName(QString::fromUtf8("frame_22"));
        frame_22->setMinimumSize(QSize(0, 2));
        frame_22->setMaximumSize(QSize(16777215, 10));
        frame_22->setStyleSheet(QString::fromUtf8("border-bottom: 1px solid #747290;"));
        frame_22->setFrameShape(QFrame::NoFrame);
        frame_22->setFrameShadow(QFrame::Plain);

        gridLayout_10->addWidget(frame_22, 1, 0, 1, 2);


        verticalLayout_44->addLayout(gridLayout_10);


        verticalLayout_29->addWidget(frame_19);


        gridLayout_6->addWidget(cpuInformationContainer, 3, 2, 1, 1);

        frame_25 = new QFrame(cpuPage);
        frame_25->setObjectName(QString::fromUtf8("frame_25"));
        frame_25->setMaximumSize(QSize(16777215, 40));
        frame_25->setStyleSheet(QString::fromUtf8("border-bottom: 1px solid #747290; margin: 0 30px;"));
        frame_25->setFrameShape(QFrame::NoFrame);
        frame_25->setFrameShadow(QFrame::Plain);

        gridLayout_6->addWidget(frame_25, 4, 0, 1, 3);

        frame_24 = new QFrame(cpuPage);
        frame_24->setObjectName(QString::fromUtf8("frame_24"));
        frame_24->setMaximumSize(QSize(16777215, 40));
        frame_24->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; margin-left: 30px; margin-right: 30px;"));
        frame_24->setFrameShape(QFrame::NoFrame);
        frame_24->setFrameShadow(QFrame::Plain);

        gridLayout_6->addWidget(frame_24, 1, 0, 1, 2);

        frame_23 = new QFrame(cpuPage);
        frame_23->setObjectName(QString::fromUtf8("frame_23"));
        sizePolicy3.setHeightForWidth(frame_23->sizePolicy().hasHeightForWidth());
        frame_23->setSizePolicy(sizePolicy3);
        frame_23->setMinimumSize(QSize(0, 60));
        frame_23->setMaximumSize(QSize(16777215, 30));
        frame_23->setStyleSheet(QString::fromUtf8("background:none;\n "
                                                  "border-right: 1px solid #d1d0d8;"));
        frame_23->setFrameShape(QFrame::NoFrame);
        frame_23->setFrameShadow(QFrame::Plain);
        frame_23->setLineWidth(0);
        horizontalLayout_7 = new QHBoxLayout(frame_23);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(30, 0, 0, 0);
        label_78 = new QLabel(frame_23);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setMinimumSize(QSize(45, 45));
        label_78->setMaximumSize(QSize(60, 60));
        label_78->setStyleSheet(QString::fromUtf8("background:none;\n "
                                                  "\n "
                                                  "image: url(:/images/intel-logo.png);\n "
                                                  "\n "
                                                  "border:none;"));

        horizontalLayout_7->addWidget(label_78);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        cpuModelName = new QLabel(frame_23);
        cpuModelName->setObjectName(QString::fromUtf8("cpuModelName"));
        sizePolicy8.setHeightForWidth(cpuModelName->sizePolicy().hasHeightForWidth());
        cpuModelName->setSizePolicy(sizePolicy8);
        cpuModelName->setFont(font1);
        cpuModelName->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));
        cpuModelName->setWordWrap(true);

        horizontalLayout_7->addWidget(cpuModelName);


        gridLayout_6->addWidget(frame_23, 0, 0, 1, 3);


        verticalLayout_13->addLayout(gridLayout_6);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(20, 0, 30, -1);
        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        horizontalLayout_35->setContentsMargins(30, -1, -1, -1);
        cpuTemperatureCoreContainer_1 = new QFrame(cpuPage);
        cpuTemperatureCoreContainer_1->setObjectName(QString::fromUtf8("cpuTemperatureCoreContainer_1"));
        cpuTemperatureCoreContainer_1->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                       "border:none;"));
        cpuTemperatureCoreContainer_1->setFrameShape(QFrame::StyledPanel);
        cpuTemperatureCoreContainer_1->setFrameShadow(QFrame::Raised);
        verticalLayout_33 = new QVBoxLayout(cpuTemperatureCoreContainer_1);
        verticalLayout_33->setObjectName(QString::fromUtf8("verticalLayout_33"));
        chart_container_6 = new QFrame(cpuTemperatureCoreContainer_1);
        chart_container_6->setObjectName(QString::fromUtf8("chart_container_6"));
        chart_container_6->setMaximumSize(QSize(16777215, 114));
        chart_container_6->setFrameShape(QFrame::NoFrame);
        chart_container_6->setFrameShadow(QFrame::Plain);
        chart_container_6->setLineWidth(0);
        horizontalLayout_27 = new QHBoxLayout(chart_container_6);
        horizontalLayout_27->setSpacing(0);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_10 = new QFrame(chart_container_6);
        circularProgressBarBase_10->setObjectName(QString::fromUtf8("circularProgressBarBase_10"));
        circularProgressBarBase_10->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_10->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_10->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_10->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_10->setLineWidth(0);
        circuralProgressCpuTemperatureCore_1 = new QFrame(circularProgressBarBase_10);
        circuralProgressCpuTemperatureCore_1->setObjectName(QString::fromUtf8("circuralProgressCpuTemperatureCore_1"));
        circuralProgressCpuTemperatureCore_1->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuTemperatureCore_1->setMinimumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_1->setMaximumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_1->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuTemperatureCore_1->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuTemperatureCore_1->setFrameShadow(QFrame::Plain);
        circuralProgressCpuTemperatureCore_1->setLineWidth(0);
        circuralBg_12 = new QFrame(circularProgressBarBase_10);
        circuralBg_12->setObjectName(QString::fromUtf8("circuralBg_12"));
        circuralBg_12->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_12->setMinimumSize(QSize(140, 140));
        circuralBg_12->setMaximumSize(QSize(140, 140));
        circuralBg_12->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                       "	border-radius: 70px;\n "
                                                       "	background-color:  #1a172d;\n "
                                                       "}\n "
                                                       "\n "
                                                       ""));
        circuralBg_12->setFrameShape(QFrame::NoFrame);
        circuralBg_12->setFrameShadow(QFrame::Plain);
        circuralBg_12->setLineWidth(0);
        circuralContainer_12 = new QFrame(circularProgressBarBase_10);
        circuralContainer_12->setObjectName(QString::fromUtf8("circuralContainer_12"));
        circuralContainer_12->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_12->setMinimumSize(QSize(110, 110));
        circuralContainer_12->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                              " border-radius:65px;\n "
                                                              "	background: #1a172d;\n "
                                                              "}\n "
                                                              "\n "
                                                              "QFrame:hover {\n "
                                                              "	background-color: #2b283e;\n "
                                                              "}\n "
                                                              ""));
        circuralContainer_12->setFrameShape(QFrame::NoFrame);
        circuralContainer_12->setFrameShadow(QFrame::Plain);
        circuralContainer_12->setLineWidth(0);
        verticalLayout_38 = new QVBoxLayout(circuralContainer_12);
        verticalLayout_38->setSpacing(0);
        verticalLayout_38->setObjectName(QString::fromUtf8("verticalLayout_38"));
        verticalLayout_38->setContentsMargins(0, 0, 0, 0);
        cpuTemperatureCore_1 = new QLabel(circuralContainer_12);
        cpuTemperatureCore_1->setObjectName(QString::fromUtf8("cpuTemperatureCore_1"));
        cpuTemperatureCore_1->setFont(font5);
        cpuTemperatureCore_1->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                              "color: #afafaf;\n "
                                                              "background:none;"));
        cpuTemperatureCore_1->setAlignment(Qt::AlignCenter);

        verticalLayout_38->addWidget(cpuTemperatureCore_1);

        circuralBg_12->raise();
        circuralProgressCpuTemperatureCore_1->raise();
        circuralContainer_12->raise();

        horizontalLayout_27->addWidget(circularProgressBarBase_10);


        verticalLayout_33->addWidget(chart_container_6);

        label_90 = new QLabel(cpuTemperatureCoreContainer_1);
        label_90->setObjectName(QString::fromUtf8("label_90"));
        sizePolicy7.setHeightForWidth(label_90->sizePolicy().hasHeightForWidth());
        label_90->setSizePolicy(sizePolicy7);
        label_90->setFont(font4);
        label_90->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_90->setAlignment(Qt::AlignCenter);

        verticalLayout_33->addWidget(label_90);


        horizontalLayout_35->addWidget(cpuTemperatureCoreContainer_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_3);

        cpuTemperatureCoreContainer_2 = new QFrame(cpuPage);
        cpuTemperatureCoreContainer_2->setObjectName(QString::fromUtf8("cpuTemperatureCoreContainer_2"));
        cpuTemperatureCoreContainer_2->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                       "border:none;"));
        cpuTemperatureCoreContainer_2->setFrameShape(QFrame::StyledPanel);
        cpuTemperatureCoreContainer_2->setFrameShadow(QFrame::Raised);
        verticalLayout_46 = new QVBoxLayout(cpuTemperatureCoreContainer_2);
        verticalLayout_46->setObjectName(QString::fromUtf8("verticalLayout_46"));
        chart_container_5 = new QFrame(cpuTemperatureCoreContainer_2);
        chart_container_5->setObjectName(QString::fromUtf8("chart_container_5"));
        chart_container_5->setMaximumSize(QSize(16777215, 114));
        chart_container_5->setFrameShape(QFrame::NoFrame);
        chart_container_5->setFrameShadow(QFrame::Plain);
        chart_container_5->setLineWidth(0);
        horizontalLayout_26 = new QHBoxLayout(chart_container_5);
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_9 = new QFrame(chart_container_5);
        circularProgressBarBase_9->setObjectName(QString::fromUtf8("circularProgressBarBase_9"));
        circularProgressBarBase_9->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_9->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_9->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_9->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_9->setLineWidth(0);
        circuralProgressCpuTemperatureCore_2 = new QFrame(circularProgressBarBase_9);
        circuralProgressCpuTemperatureCore_2->setObjectName(QString::fromUtf8("circuralProgressCpuTemperatureCore_2"));
        circuralProgressCpuTemperatureCore_2->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuTemperatureCore_2->setMinimumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_2->setMaximumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_2->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuTemperatureCore_2->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuTemperatureCore_2->setFrameShadow(QFrame::Plain);
        circuralProgressCpuTemperatureCore_2->setLineWidth(0);
        circuralBg_11 = new QFrame(circularProgressBarBase_9);
        circuralBg_11->setObjectName(QString::fromUtf8("circuralBg_11"));
        circuralBg_11->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_11->setMinimumSize(QSize(140, 140));
        circuralBg_11->setMaximumSize(QSize(140, 140));
        circuralBg_11->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                       "	border-radius: 70px;\n "
                                                       "	background-color:  #1a172d;\n "
                                                       "}\n "
                                                       "\n "
                                                       ""));
        circuralBg_11->setFrameShape(QFrame::NoFrame);
        circuralBg_11->setFrameShadow(QFrame::Plain);
        circuralBg_11->setLineWidth(0);
        circuralContainer_11 = new QFrame(circularProgressBarBase_9);
        circuralContainer_11->setObjectName(QString::fromUtf8("circuralContainer_11"));
        circuralContainer_11->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_11->setMinimumSize(QSize(110, 110));
        circuralContainer_11->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                              " border-radius:65px;\n "
                                                              "	background: #1a172d;\n "
                                                              "}\n "
                                                              "\n "
                                                              "QFrame:hover {\n "
                                                              "	background-color: #2b283e;\n "
                                                              "}\n "
                                                              ""));
        circuralContainer_11->setFrameShape(QFrame::NoFrame);
        circuralContainer_11->setFrameShadow(QFrame::Plain);
        circuralContainer_11->setLineWidth(0);
        verticalLayout_47 = new QVBoxLayout(circuralContainer_11);
        verticalLayout_47->setSpacing(0);
        verticalLayout_47->setObjectName(QString::fromUtf8("verticalLayout_47"));
        verticalLayout_47->setContentsMargins(0, 0, 0, 0);
        cpuTemperatureCore_2 = new QLabel(circuralContainer_11);
        cpuTemperatureCore_2->setObjectName(QString::fromUtf8("cpuTemperatureCore_2"));
        cpuTemperatureCore_2->setFont(font5);
        cpuTemperatureCore_2->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                              "color: #afafaf;\n "
                                                              "background:none;"));
        cpuTemperatureCore_2->setAlignment(Qt::AlignCenter);

        verticalLayout_47->addWidget(cpuTemperatureCore_2);

        circuralBg_11->raise();
        circuralProgressCpuTemperatureCore_2->raise();
        circuralContainer_11->raise();

        horizontalLayout_26->addWidget(circularProgressBarBase_9);


        verticalLayout_46->addWidget(chart_container_5);

        label_89 = new QLabel(cpuTemperatureCoreContainer_2);
        label_89->setObjectName(QString::fromUtf8("label_89"));
        sizePolicy7.setHeightForWidth(label_89->sizePolicy().hasHeightForWidth());
        label_89->setSizePolicy(sizePolicy7);
        label_89->setFont(font4);
        label_89->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_89->setAlignment(Qt::AlignCenter);

        verticalLayout_46->addWidget(label_89);


        horizontalLayout_35->addWidget(cpuTemperatureCoreContainer_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_4);

        cpuTemperatureCoreContainer_3 = new QFrame(cpuPage);
        cpuTemperatureCoreContainer_3->setObjectName(QString::fromUtf8("cpuTemperatureCoreContainer_3"));
        cpuTemperatureCoreContainer_3->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                       "border:none;"));
        cpuTemperatureCoreContainer_3->setFrameShape(QFrame::StyledPanel);
        cpuTemperatureCoreContainer_3->setFrameShadow(QFrame::Raised);
        verticalLayout_48 = new QVBoxLayout(cpuTemperatureCoreContainer_3);
        verticalLayout_48->setObjectName(QString::fromUtf8("verticalLayout_48"));
        chart_container_7 = new QFrame(cpuTemperatureCoreContainer_3);
        chart_container_7->setObjectName(QString::fromUtf8("chart_container_7"));
        chart_container_7->setMaximumSize(QSize(16777215, 114));
        chart_container_7->setFrameShape(QFrame::NoFrame);
        chart_container_7->setFrameShadow(QFrame::Plain);
        chart_container_7->setLineWidth(0);
        horizontalLayout_29 = new QHBoxLayout(chart_container_7);
        horizontalLayout_29->setSpacing(0);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalLayout_29->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_11 = new QFrame(chart_container_7);
        circularProgressBarBase_11->setObjectName(QString::fromUtf8("circularProgressBarBase_11"));
        circularProgressBarBase_11->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_11->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_11->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_11->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_11->setLineWidth(0);
        circuralProgressCpuTemperatureCore_3 = new QFrame(circularProgressBarBase_11);
        circuralProgressCpuTemperatureCore_3->setObjectName(QString::fromUtf8("circuralProgressCpuTemperatureCore_3"));
        circuralProgressCpuTemperatureCore_3->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuTemperatureCore_3->setMinimumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_3->setMaximumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_3->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuTemperatureCore_3->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuTemperatureCore_3->setFrameShadow(QFrame::Plain);
        circuralProgressCpuTemperatureCore_3->setLineWidth(0);
        circuralBg_13 = new QFrame(circularProgressBarBase_11);
        circuralBg_13->setObjectName(QString::fromUtf8("circuralBg_13"));
        circuralBg_13->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_13->setMinimumSize(QSize(140, 140));
        circuralBg_13->setMaximumSize(QSize(140, 140));
        circuralBg_13->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                       "	border-radius: 70px;\n "
                                                       "	background-color:  #1a172d;\n "
                                                       "}\n "
                                                       "\n "
                                                       ""));
        circuralBg_13->setFrameShape(QFrame::NoFrame);
        circuralBg_13->setFrameShadow(QFrame::Plain);
        circuralBg_13->setLineWidth(0);
        circuralContainer_13 = new QFrame(circularProgressBarBase_11);
        circuralContainer_13->setObjectName(QString::fromUtf8("circuralContainer_13"));
        circuralContainer_13->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_13->setMinimumSize(QSize(110, 110));
        circuralContainer_13->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                              " border-radius:65px;\n "
                                                              "	background: #1a172d;\n "
                                                              "}\n "
                                                              "\n "
                                                              "QFrame:hover {\n "
                                                              "	background-color: #2b283e;\n "
                                                              "}\n "
                                                              ""));
        circuralContainer_13->setFrameShape(QFrame::NoFrame);
        circuralContainer_13->setFrameShadow(QFrame::Plain);
        circuralContainer_13->setLineWidth(0);
        verticalLayout_50 = new QVBoxLayout(circuralContainer_13);
        verticalLayout_50->setSpacing(0);
        verticalLayout_50->setObjectName(QString::fromUtf8("verticalLayout_50"));
        verticalLayout_50->setContentsMargins(0, 0, 0, 0);
        cpuTemperatureCore_3 = new QLabel(circuralContainer_13);
        cpuTemperatureCore_3->setObjectName(QString::fromUtf8("cpuTemperatureCore_3"));
        cpuTemperatureCore_3->setFont(font5);
        cpuTemperatureCore_3->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                              "color: #afafaf;\n "
                                                              "background:none;"));
        cpuTemperatureCore_3->setAlignment(Qt::AlignCenter);

        verticalLayout_50->addWidget(cpuTemperatureCore_3);

        circuralBg_13->raise();
        circuralProgressCpuTemperatureCore_3->raise();
        circuralContainer_13->raise();

        horizontalLayout_29->addWidget(circularProgressBarBase_11);


        verticalLayout_48->addWidget(chart_container_7);

        label_91 = new QLabel(cpuTemperatureCoreContainer_3);
        label_91->setObjectName(QString::fromUtf8("label_91"));
        sizePolicy7.setHeightForWidth(label_91->sizePolicy().hasHeightForWidth());
        label_91->setSizePolicy(sizePolicy7);
        label_91->setFont(font4);
        label_91->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_91->setAlignment(Qt::AlignCenter);

        verticalLayout_48->addWidget(label_91);


        horizontalLayout_35->addWidget(cpuTemperatureCoreContainer_3);


        gridLayout_12->addLayout(horizontalLayout_35, 0, 0, 1, 1);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        horizontalLayout_36->setContentsMargins(30, -1, -1, -1);
        cpuTemperatureCoreContainer_4 = new QFrame(cpuPage);
        cpuTemperatureCoreContainer_4->setObjectName(QString::fromUtf8("cpuTemperatureCoreContainer_4"));
        cpuTemperatureCoreContainer_4->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                       "border:none;"));
        cpuTemperatureCoreContainer_4->setFrameShape(QFrame::StyledPanel);
        cpuTemperatureCoreContainer_4->setFrameShadow(QFrame::Raised);
        verticalLayout_53 = new QVBoxLayout(cpuTemperatureCoreContainer_4);
        verticalLayout_53->setObjectName(QString::fromUtf8("verticalLayout_53"));
        chart_container_9 = new QFrame(cpuTemperatureCoreContainer_4);
        chart_container_9->setObjectName(QString::fromUtf8("chart_container_9"));
        chart_container_9->setMaximumSize(QSize(16777215, 114));
        chart_container_9->setFrameShape(QFrame::NoFrame);
        chart_container_9->setFrameShadow(QFrame::Plain);
        chart_container_9->setLineWidth(0);
        horizontalLayout_31 = new QHBoxLayout(chart_container_9);
        horizontalLayout_31->setSpacing(0);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_13 = new QFrame(chart_container_9);
        circularProgressBarBase_13->setObjectName(QString::fromUtf8("circularProgressBarBase_13"));
        circularProgressBarBase_13->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_13->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_13->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_13->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_13->setLineWidth(0);
        circuralProgressCpuTemperatureCore_4 = new QFrame(circularProgressBarBase_13);
        circuralProgressCpuTemperatureCore_4->setObjectName(QString::fromUtf8("circuralProgressCpuTemperatureCore_4"));
        circuralProgressCpuTemperatureCore_4->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuTemperatureCore_4->setMinimumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_4->setMaximumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_4->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuTemperatureCore_4->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuTemperatureCore_4->setFrameShadow(QFrame::Plain);
        circuralProgressCpuTemperatureCore_4->setLineWidth(0);
        circuralBg_15 = new QFrame(circularProgressBarBase_13);
        circuralBg_15->setObjectName(QString::fromUtf8("circuralBg_15"));
        circuralBg_15->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_15->setMinimumSize(QSize(140, 140));
        circuralBg_15->setMaximumSize(QSize(140, 140));
        circuralBg_15->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                       "	border-radius: 70px;\n "
                                                       "	background-color:  #1a172d;\n "
                                                       "}\n "
                                                       "\n "
                                                       ""));
        circuralBg_15->setFrameShape(QFrame::NoFrame);
        circuralBg_15->setFrameShadow(QFrame::Plain);
        circuralBg_15->setLineWidth(0);
        circuralContainer_15 = new QFrame(circularProgressBarBase_13);
        circuralContainer_15->setObjectName(QString::fromUtf8("circuralContainer_15"));
        circuralContainer_15->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_15->setMinimumSize(QSize(110, 110));
        circuralContainer_15->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                              " border-radius:65px;\n "
                                                              "	background: #1a172d;\n "
                                                              "}\n "
                                                              "\n "
                                                              "QFrame:hover {\n "
                                                              "	background-color: #2b283e;\n "
                                                              "}\n "
                                                              ""));
        circuralContainer_15->setFrameShape(QFrame::NoFrame);
        circuralContainer_15->setFrameShadow(QFrame::Plain);
        circuralContainer_15->setLineWidth(0);
        verticalLayout_55 = new QVBoxLayout(circuralContainer_15);
        verticalLayout_55->setSpacing(0);
        verticalLayout_55->setObjectName(QString::fromUtf8("verticalLayout_55"));
        verticalLayout_55->setContentsMargins(0, 0, 0, 0);
        cpuTemperatureCore_4 = new QLabel(circuralContainer_15);
        cpuTemperatureCore_4->setObjectName(QString::fromUtf8("cpuTemperatureCore_4"));
        cpuTemperatureCore_4->setFont(font5);
        cpuTemperatureCore_4->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                              "color: #afafaf;\n "
                                                              "background:none;"));
        cpuTemperatureCore_4->setAlignment(Qt::AlignCenter);

        verticalLayout_55->addWidget(cpuTemperatureCore_4);

        circuralBg_15->raise();
        circuralProgressCpuTemperatureCore_4->raise();
        circuralContainer_15->raise();

        horizontalLayout_31->addWidget(circularProgressBarBase_13);


        verticalLayout_53->addWidget(chart_container_9);

        label_93 = new QLabel(cpuTemperatureCoreContainer_4);
        label_93->setObjectName(QString::fromUtf8("label_93"));
        sizePolicy7.setHeightForWidth(label_93->sizePolicy().hasHeightForWidth());
        label_93->setSizePolicy(sizePolicy7);
        label_93->setFont(font4);
        label_93->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_93->setAlignment(Qt::AlignCenter);

        verticalLayout_53->addWidget(label_93);


        horizontalLayout_36->addWidget(cpuTemperatureCoreContainer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_5);

        cpuTemperatureCoreContainer_5 = new QFrame(cpuPage);
        cpuTemperatureCoreContainer_5->setObjectName(QString::fromUtf8("cpuTemperatureCoreContainer_5"));
        cpuTemperatureCoreContainer_5->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                       "border:none;"));
        cpuTemperatureCoreContainer_5->setFrameShape(QFrame::StyledPanel);
        cpuTemperatureCoreContainer_5->setFrameShadow(QFrame::Raised);
        verticalLayout_57 = new QVBoxLayout(cpuTemperatureCoreContainer_5);
        verticalLayout_57->setObjectName(QString::fromUtf8("verticalLayout_57"));
        chart_container_10 = new QFrame(cpuTemperatureCoreContainer_5);
        chart_container_10->setObjectName(QString::fromUtf8("chart_container_10"));
        chart_container_10->setMaximumSize(QSize(16777215, 114));
        chart_container_10->setFrameShape(QFrame::NoFrame);
        chart_container_10->setFrameShadow(QFrame::Plain);
        chart_container_10->setLineWidth(0);
        horizontalLayout_33 = new QHBoxLayout(chart_container_10);
        horizontalLayout_33->setSpacing(0);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_33->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_14 = new QFrame(chart_container_10);
        circularProgressBarBase_14->setObjectName(QString::fromUtf8("circularProgressBarBase_14"));
        circularProgressBarBase_14->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_14->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_14->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_14->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_14->setLineWidth(0);
        circuralProgressCpuTemperatureCore_5 = new QFrame(circularProgressBarBase_14);
        circuralProgressCpuTemperatureCore_5->setObjectName(QString::fromUtf8("circuralProgressCpuTemperatureCore_5"));
        circuralProgressCpuTemperatureCore_5->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuTemperatureCore_5->setMinimumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_5->setMaximumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_5->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuTemperatureCore_5->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuTemperatureCore_5->setFrameShadow(QFrame::Plain);
        circuralProgressCpuTemperatureCore_5->setLineWidth(0);
        circuralBg_16 = new QFrame(circularProgressBarBase_14);
        circuralBg_16->setObjectName(QString::fromUtf8("circuralBg_16"));
        circuralBg_16->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_16->setMinimumSize(QSize(140, 140));
        circuralBg_16->setMaximumSize(QSize(140, 140));
        circuralBg_16->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                       "	border-radius: 70px;\n "
                                                       "	background-color:  #1a172d;\n "
                                                       "}\n "
                                                       "\n "
                                                       ""));
        circuralBg_16->setFrameShape(QFrame::NoFrame);
        circuralBg_16->setFrameShadow(QFrame::Plain);
        circuralBg_16->setLineWidth(0);
        circuralContainer_16 = new QFrame(circularProgressBarBase_14);
        circuralContainer_16->setObjectName(QString::fromUtf8("circuralContainer_16"));
        circuralContainer_16->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_16->setMinimumSize(QSize(110, 110));
        circuralContainer_16->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                              " border-radius:65px;\n "
                                                              "	background: #1a172d;\n "
                                                              "}\n "
                                                              "\n "
                                                              "QFrame:hover {\n "
                                                              "	background-color: #2b283e;\n "
                                                              "}\n "
                                                              ""));
        circuralContainer_16->setFrameShape(QFrame::NoFrame);
        circuralContainer_16->setFrameShadow(QFrame::Plain);
        circuralContainer_16->setLineWidth(0);
        verticalLayout_58 = new QVBoxLayout(circuralContainer_16);
        verticalLayout_58->setSpacing(0);
        verticalLayout_58->setObjectName(QString::fromUtf8("verticalLayout_58"));
        verticalLayout_58->setContentsMargins(0, 0, 0, 0);
        cpuTemperatureCore_5 = new QLabel(circuralContainer_16);
        cpuTemperatureCore_5->setObjectName(QString::fromUtf8("cpuTemperatureCore_5"));
        cpuTemperatureCore_5->setFont(font5);
        cpuTemperatureCore_5->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                              "color: #afafaf;\n "
                                                              "background:none;"));
        cpuTemperatureCore_5->setAlignment(Qt::AlignCenter);

        verticalLayout_58->addWidget(cpuTemperatureCore_5);

        circuralBg_16->raise();
        circuralProgressCpuTemperatureCore_5->raise();
        circuralContainer_16->raise();

        horizontalLayout_33->addWidget(circularProgressBarBase_14);


        verticalLayout_57->addWidget(chart_container_10);

        label_94 = new QLabel(cpuTemperatureCoreContainer_5);
        label_94->setObjectName(QString::fromUtf8("label_94"));
        sizePolicy7.setHeightForWidth(label_94->sizePolicy().hasHeightForWidth());
        label_94->setSizePolicy(sizePolicy7);
        label_94->setFont(font4);
        label_94->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_94->setAlignment(Qt::AlignCenter);

        verticalLayout_57->addWidget(label_94);


        horizontalLayout_36->addWidget(cpuTemperatureCoreContainer_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_6);

        cpuTemperatureCoreContainer_6 = new QFrame(cpuPage);
        cpuTemperatureCoreContainer_6->setObjectName(QString::fromUtf8("cpuTemperatureCoreContainer_6"));
        cpuTemperatureCoreContainer_6->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                       "border:none;"));
        cpuTemperatureCoreContainer_6->setFrameShape(QFrame::StyledPanel);
        cpuTemperatureCoreContainer_6->setFrameShadow(QFrame::Raised);
        verticalLayout_59 = new QVBoxLayout(cpuTemperatureCoreContainer_6);
        verticalLayout_59->setObjectName(QString::fromUtf8("verticalLayout_59"));
        chart_container_11 = new QFrame(cpuTemperatureCoreContainer_6);
        chart_container_11->setObjectName(QString::fromUtf8("chart_container_11"));
        chart_container_11->setMaximumSize(QSize(16777215, 114));
        chart_container_11->setFrameShape(QFrame::NoFrame);
        chart_container_11->setFrameShadow(QFrame::Plain);
        chart_container_11->setLineWidth(0);
        horizontalLayout_34 = new QHBoxLayout(chart_container_11);
        horizontalLayout_34->setSpacing(0);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        horizontalLayout_34->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_15 = new QFrame(chart_container_11);
        circularProgressBarBase_15->setObjectName(QString::fromUtf8("circularProgressBarBase_15"));
        circularProgressBarBase_15->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_15->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_15->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_15->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_15->setLineWidth(0);
        circuralProgressCpuTemperatureCore_6 = new QFrame(circularProgressBarBase_15);
        circuralProgressCpuTemperatureCore_6->setObjectName(QString::fromUtf8("circuralProgressCpuTemperatureCore_6"));
        circuralProgressCpuTemperatureCore_6->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuTemperatureCore_6->setMinimumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_6->setMaximumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCore_6->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuTemperatureCore_6->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuTemperatureCore_6->setFrameShadow(QFrame::Plain);
        circuralProgressCpuTemperatureCore_6->setLineWidth(0);
        circuralBg_17 = new QFrame(circularProgressBarBase_15);
        circuralBg_17->setObjectName(QString::fromUtf8("circuralBg_17"));
        circuralBg_17->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_17->setMinimumSize(QSize(140, 140));
        circuralBg_17->setMaximumSize(QSize(140, 140));
        circuralBg_17->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                       "	border-radius: 70px;\n "
                                                       "	background-color:  #1a172d;\n "
                                                       "}\n "
                                                       "\n "
                                                       ""));
        circuralBg_17->setFrameShape(QFrame::NoFrame);
        circuralBg_17->setFrameShadow(QFrame::Plain);
        circuralBg_17->setLineWidth(0);
        circuralContainer_17 = new QFrame(circularProgressBarBase_15);
        circuralContainer_17->setObjectName(QString::fromUtf8("circuralContainer_17"));
        circuralContainer_17->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_17->setMinimumSize(QSize(110, 110));
        circuralContainer_17->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                              " border-radius:65px;\n "
                                                              "	background: #1a172d;\n "
                                                              "}\n "
                                                              "\n "
                                                              "QFrame:hover {\n "
                                                              "	background-color: #2b283e;\n "
                                                              "}\n "
                                                              ""));
        circuralContainer_17->setFrameShape(QFrame::NoFrame);
        circuralContainer_17->setFrameShadow(QFrame::Plain);
        circuralContainer_17->setLineWidth(0);
        verticalLayout_60 = new QVBoxLayout(circuralContainer_17);
        verticalLayout_60->setSpacing(0);
        verticalLayout_60->setObjectName(QString::fromUtf8("verticalLayout_60"));
        verticalLayout_60->setContentsMargins(0, 0, 0, 0);
        cpuTemperatureCore_6 = new QLabel(circuralContainer_17);
        cpuTemperatureCore_6->setObjectName(QString::fromUtf8("cpuTemperatureCore_6"));
        cpuTemperatureCore_6->setFont(font5);
        cpuTemperatureCore_6->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                              "color: #afafaf;\n "
                                                              "background:none;"));
        cpuTemperatureCore_6->setAlignment(Qt::AlignCenter);

        verticalLayout_60->addWidget(cpuTemperatureCore_6);

        circuralBg_17->raise();
        circuralProgressCpuTemperatureCore_6->raise();
        circuralContainer_17->raise();

        horizontalLayout_34->addWidget(circularProgressBarBase_15);


        verticalLayout_59->addWidget(chart_container_11);

        label_95 = new QLabel(cpuTemperatureCoreContainer_6);
        label_95->setObjectName(QString::fromUtf8("label_95"));
        sizePolicy7.setHeightForWidth(label_95->sizePolicy().hasHeightForWidth());
        label_95->setSizePolicy(sizePolicy7);
        label_95->setFont(font4);
        label_95->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_95->setAlignment(Qt::AlignCenter);

        verticalLayout_59->addWidget(label_95);


        horizontalLayout_36->addWidget(cpuTemperatureCoreContainer_6);


        gridLayout_12->addLayout(horizontalLayout_36, 1, 0, 1, 1);

        cpuTemperaturePeciContainer = new QFrame(cpuPage);
        cpuTemperaturePeciContainer->setObjectName(QString::fromUtf8("cpuTemperaturePeciContainer"));
        cpuTemperaturePeciContainer->setMaximumSize(QSize(16777215, 200));
        cpuTemperaturePeciContainer->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                     "border:none;"));
        cpuTemperaturePeciContainer->setFrameShape(QFrame::StyledPanel);
        cpuTemperaturePeciContainer->setFrameShadow(QFrame::Raised);
        verticalLayout_51 = new QVBoxLayout(cpuTemperaturePeciContainer);
        verticalLayout_51->setObjectName(QString::fromUtf8("verticalLayout_51"));
        chart_container_8 = new QFrame(cpuTemperaturePeciContainer);
        chart_container_8->setObjectName(QString::fromUtf8("chart_container_8"));
        chart_container_8->setMaximumSize(QSize(16777215, 114));
        chart_container_8->setFrameShape(QFrame::NoFrame);
        chart_container_8->setFrameShadow(QFrame::Plain);
        chart_container_8->setLineWidth(0);
        horizontalLayout_30 = new QHBoxLayout(chart_container_8);
        horizontalLayout_30->setSpacing(0);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        horizontalLayout_30->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_12 = new QFrame(chart_container_8);
        circularProgressBarBase_12->setObjectName(QString::fromUtf8("circularProgressBarBase_12"));
        circularProgressBarBase_12->setMinimumSize(QSize(140, 140));
        circularProgressBarBase_12->setMaximumSize(QSize(140, 140));
        circularProgressBarBase_12->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_12->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_12->setLineWidth(0);
        circuralProgressCpuTemperatureCorePECI = new QFrame(circularProgressBarBase_12);
        circuralProgressCpuTemperatureCorePECI->setObjectName(QString::fromUtf8("circuralProgressCpuTemperatureCorePECI"));
        circuralProgressCpuTemperatureCorePECI->setGeometry(QRect(0, 0, 140, 140));
        circuralProgressCpuTemperatureCorePECI->setMinimumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCorePECI->setMaximumSize(QSize(140, 140));
        circuralProgressCpuTemperatureCorePECI->setStyleSheet(QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n}"));
        circuralProgressCpuTemperatureCorePECI->setFrameShape(QFrame::NoFrame);
        circuralProgressCpuTemperatureCorePECI->setFrameShadow(QFrame::Plain);
        circuralProgressCpuTemperatureCorePECI->setLineWidth(0);
        circuralBg_14 = new QFrame(circularProgressBarBase_12);
        circuralBg_14->setObjectName(QString::fromUtf8("circuralBg_14"));
        circuralBg_14->setGeometry(QRect(0, 0, 140, 140));
        circuralBg_14->setMinimumSize(QSize(140, 140));
        circuralBg_14->setMaximumSize(QSize(140, 140));
        circuralBg_14->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                       "	border-radius: 70px;\n "
                                                       "	background-color:  #1a172d;\n "
                                                       "}\n "
                                                       "\n "
                                                       ""));
        circuralBg_14->setFrameShape(QFrame::NoFrame);
        circuralBg_14->setFrameShadow(QFrame::Plain);
        circuralBg_14->setLineWidth(0);
        circuralContainer_14 = new QFrame(circularProgressBarBase_12);
        circuralContainer_14->setObjectName(QString::fromUtf8("circuralContainer_14"));
        circuralContainer_14->setGeometry(QRect(5, 5, 130, 130));
        circuralContainer_14->setMinimumSize(QSize(110, 110));
        circuralContainer_14->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                              " border-radius:65px;\n "
                                                              "	background: #1a172d;\n "
                                                              "}\n "
                                                              "\n "
                                                              "QFrame:hover {\n "
                                                              "	background-color: #2b283e;\n "
                                                              "}\n "
                                                              ""));
        circuralContainer_14->setFrameShape(QFrame::NoFrame);
        circuralContainer_14->setFrameShadow(QFrame::Plain);
        circuralContainer_14->setLineWidth(0);
        verticalLayout_52 = new QVBoxLayout(circuralContainer_14);
        verticalLayout_52->setSpacing(0);
        verticalLayout_52->setObjectName(QString::fromUtf8("verticalLayout_52"));
        verticalLayout_52->setContentsMargins(0, 0, 0, 0);
        cpuTemperaturePeci = new QLabel(circuralContainer_14);
        cpuTemperaturePeci->setObjectName(QString::fromUtf8("cpuTemperaturePeci"));
        cpuTemperaturePeci->setFont(font5);
        cpuTemperaturePeci->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                            "color: #afafaf;\n "
                                                            "background:none;"));
        cpuTemperaturePeci->setAlignment(Qt::AlignCenter);

        verticalLayout_52->addWidget(cpuTemperaturePeci);

        circuralBg_14->raise();
        circuralProgressCpuTemperatureCorePECI->raise();
        circuralContainer_14->raise();

        horizontalLayout_30->addWidget(circularProgressBarBase_12);


        verticalLayout_51->addWidget(chart_container_8);

        label_92 = new QLabel(cpuTemperaturePeciContainer);
        label_92->setObjectName(QString::fromUtf8("label_92"));
        sizePolicy7.setHeightForWidth(label_92->sizePolicy().hasHeightForWidth());
        label_92->setSizePolicy(sizePolicy7);
        label_92->setFont(font4);
        label_92->setStyleSheet(QString::fromUtf8("border:none; \n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_92->setAlignment(Qt::AlignCenter);

        verticalLayout_51->addWidget(label_92);


        gridLayout_12->addWidget(cpuTemperaturePeciContainer, 0, 1, 2, 1);


        verticalLayout_13->addLayout(gridLayout_12);

        stackedWidget->addWidget(cpuPage);
        fansPage = new QWidget();
        fansPage->setObjectName(QString::fromUtf8("fansPage"));
        verticalLayout_30 = new QVBoxLayout(fansPage);
        verticalLayout_30->setObjectName(QString::fromUtf8("verticalLayout_30"));
        fansPageContainer = new QFrame(fansPage);
        fansPageContainer->setObjectName(QString::fromUtf8("fansPageContainer"));
        sizePolicy1.setHeightForWidth(fansPageContainer->sizePolicy().hasHeightForWidth());
        fansPageContainer->setSizePolicy(sizePolicy1);
        fansPageContainer->setFrameShape(QFrame::NoFrame);
        fansPageContainer->setFrameShadow(QFrame::Sunken);
        verticalLayout_43 = new QVBoxLayout(fansPageContainer);
        verticalLayout_43->setObjectName(QString::fromUtf8("verticalLayout_43"));
        verticalLayout_43->setContentsMargins(-1, 50, -1, -1);
        fanLeftContainer = new QHBoxLayout();
        fanLeftContainer->setObjectName(QString::fromUtf8("fanLeftContainer"));
        frame_28 = new QFrame(fansPageContainer);
        frame_28->setObjectName(QString::fromUtf8("frame_28"));
        frame_28->setFrameShape(QFrame::NoFrame);
        frame_28->setFrameShadow(QFrame::Plain);
        verticalLayout_41 = new QVBoxLayout(frame_28);
        verticalLayout_41->setObjectName(QString::fromUtf8("verticalLayout_41"));
        label_13 = new QLabel(frame_28);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(128, 128));
        label_13->setMaximumSize(QSize(128, 128));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/images/fan-icon128.png);\n "
                                                  "\n "
                                                  ""));
        label_13->setLineWidth(0);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_41->addWidget(label_13);


        fanLeftContainer->addWidget(frame_28);

        horizontalSpacer_10 = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        fanLeftContainer->addItem(horizontalSpacer_10);

        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));
        verticalLayout_31->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setVerticalSpacing(2);
        label_86 = new QLabel(fansPageContainer);
        label_86->setObjectName(QString::fromUtf8("label_86"));
        sizePolicy8.setHeightForWidth(label_86->sizePolicy().hasHeightForWidth());
        label_86->setSizePolicy(sizePolicy8);
        label_86->setMaximumSize(QSize(200, 50));
        label_86->setFont(font4);
        label_86->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_86->setAlignment(Qt::AlignCenter);
        label_86->setWordWrap(true);

        gridLayout_9->addWidget(label_86, 2, 2, 1, 1);

        fanLeftMaximumSpeed = new QLabel(fansPageContainer);
        fanLeftMaximumSpeed->setObjectName(QString::fromUtf8("fanLeftMaximumSpeed"));
        fanLeftMaximumSpeed->setFont(font2);
        fanLeftMaximumSpeed->setStyleSheet(QString::fromUtf8("letter-spacing: 3px;\n "
                                                             "background:none;"));
        fanLeftMaximumSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(fanLeftMaximumSpeed, 3, 2, 1, 1);

        label_77 = new QLabel(fansPageContainer);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        sizePolicy8.setHeightForWidth(label_77->sizePolicy().hasHeightForWidth());
        label_77->setSizePolicy(sizePolicy8);
        label_77->setMaximumSize(QSize(200, 50));
        label_77->setFont(font4);
        label_77->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_77->setAlignment(Qt::AlignCenter);
        label_77->setWordWrap(true);

        gridLayout_9->addWidget(label_77, 2, 1, 1, 1);

        fanLeftMinimumSpeed = new QLabel(fansPageContainer);
        fanLeftMinimumSpeed->setObjectName(QString::fromUtf8("fanLeftMinimumSpeed"));
        fanLeftMinimumSpeed->setFont(font2);
        fanLeftMinimumSpeed->setStyleSheet(QString::fromUtf8("letter-spacing: 3px;\n "
                                                             "background:none;"));
        fanLeftMinimumSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(fanLeftMinimumSpeed, 3, 1, 1, 1);

        label_38 = new QLabel(fansPageContainer);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        sizePolicy5.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy5);
        label_38->setFont(font3);
        label_38->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 35pt \"Helvetica Neue\";\n "
                                                  "letter-spacing: 1px;\n "
                                                  "background-color:none;"));
        label_38->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_38, 0, 0, 1, 1);

        fanLeftCurrentSpeed = new QLabel(fansPageContainer);
        fanLeftCurrentSpeed->setObjectName(QString::fromUtf8("fanLeftCurrentSpeed"));
        fanLeftCurrentSpeed->setFont(font2);
        fanLeftCurrentSpeed->setStyleSheet(QString::fromUtf8("letter-spacing: 3px;\n "
                                                             "background:none;"));
        fanLeftCurrentSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(fanLeftCurrentSpeed, 3, 0, 1, 1);

        frame_26 = new QFrame(fansPageContainer);
        frame_26->setObjectName(QString::fromUtf8("frame_26"));
        sizePolicy6.setHeightForWidth(frame_26->sizePolicy().hasHeightForWidth());
        frame_26->setSizePolicy(sizePolicy6);
        frame_26->setMinimumSize(QSize(200, 20));
        frame_26->setMaximumSize(QSize(16777215, 20));
        frame_26->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290;"));
        frame_26->setFrameShape(QFrame::NoFrame);
        frame_26->setFrameShadow(QFrame::Plain);

        gridLayout_9->addWidget(frame_26, 1, 0, 1, 3);

        label_87 = new QLabel(fansPageContainer);
        label_87->setObjectName(QString::fromUtf8("label_87"));
        sizePolicy8.setHeightForWidth(label_87->sizePolicy().hasHeightForWidth());
        label_87->setSizePolicy(sizePolicy8);
        label_87->setMaximumSize(QSize(200, 50));
        label_87->setFont(font4);
        label_87->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_87->setAlignment(Qt::AlignCenter);
        label_87->setWordWrap(true);

        gridLayout_9->addWidget(label_87, 2, 0, 1, 1);


        verticalLayout_31->addLayout(gridLayout_9);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(30);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        fanLeftChangeSpeedButton = new QPushButton(fansPageContainer);
        fanLeftChangeSpeedButton->setObjectName(QString::fromUtf8("fanLeftChangeSpeedButton"));
        sizePolicy5.setHeightForWidth(fanLeftChangeSpeedButton->sizePolicy().hasHeightForWidth());
        fanLeftChangeSpeedButton->setSizePolicy(sizePolicy5);
        fanLeftChangeSpeedButton->setMinimumSize(QSize(200, 40));
        fanLeftChangeSpeedButton->setMaximumSize(QSize(300, 50));
        fanLeftChangeSpeedButton->setCursor(QCursor(Qt::PointingHandCursor));
        fanLeftChangeSpeedButton->setStyleSheet(QString::fromUtf8("\n "
                                                                  "QPushButton:hover#fanLeftChangeSpeedButton\n "
                                                                  "{\n "
                                                                  "	border:none;\n "
                                                                  "  	background-color:rgb(200,200,200,120);\n "
                                                                  "	border-radius:10px;\n "
                                                                  "	\n "
                                                                  "};\n "
                                                                  "\n "
                                                                  "background:#f82f5f;\n "
                                                                  "border-radius: 10px;\n "
                                                                  "font:  22pt \"Helvetica Neue\";\\n letter-spacing: 1px;\\n background-color:none;"));
        fanLeftChangeSpeedButton->setIconSize(QSize(50, 50));

        horizontalLayout_18->addWidget(fanLeftChangeSpeedButton);

        fanLeftSetAutoSpeedButton = new QPushButton(fansPageContainer);
        fanLeftSetAutoSpeedButton->setObjectName(QString::fromUtf8("fanLeftSetAutoSpeedButton"));
        sizePolicy5.setHeightForWidth(fanLeftSetAutoSpeedButton->sizePolicy().hasHeightForWidth());
        fanLeftSetAutoSpeedButton->setSizePolicy(sizePolicy5);
        fanLeftSetAutoSpeedButton->setMinimumSize(QSize(200, 40));
        fanLeftSetAutoSpeedButton->setMaximumSize(QSize(300, 50));
        fanLeftSetAutoSpeedButton->setCursor(QCursor(Qt::PointingHandCursor));
        fanLeftSetAutoSpeedButton->setStyleSheet(QString::fromUtf8("\n "
                                                                   "QPushButton:hover#fanLeftSetAutoSpeedButton\n "
                                                                   "{\n "
                                                                   "	border:none;\n "
                                                                   "  	background-color:rgb(200,200,200,120);\n "
                                                                   "	border-radius:10px;\n "
                                                                   "	\n "
                                                                   "};\n "
                                                                   "\n "
                                                                   "background:#2576eb;\n "
                                                                   "border-radius: 10px;\n "
                                                                   "font:  22pt \"Helvetica Neue\";\\n letter-spacing: 1px;\\n background-color:none;\n "
                                                                   "\n "
                                                                   ""));
        fanLeftSetAutoSpeedButton->setIconSize(QSize(50, 50));

        horizontalLayout_18->addWidget(fanLeftSetAutoSpeedButton);

        fanLeftSetMaxSpeedButton = new QPushButton(fansPageContainer);
        fanLeftSetMaxSpeedButton->setObjectName(QString::fromUtf8("fanLeftSetMaxSpeedButton"));
        sizePolicy5.setHeightForWidth(fanLeftSetMaxSpeedButton->sizePolicy().hasHeightForWidth());
        fanLeftSetMaxSpeedButton->setSizePolicy(sizePolicy5);
        fanLeftSetMaxSpeedButton->setMinimumSize(QSize(250, 40));
        fanLeftSetMaxSpeedButton->setMaximumSize(QSize(300, 50));
        fanLeftSetMaxSpeedButton->setCursor(QCursor(Qt::PointingHandCursor));
        fanLeftSetMaxSpeedButton->setStyleSheet(QString::fromUtf8("\n "
                                                                  "QPushButton:hover#fanLeftSetMaxSpeedButton\n "
                                                                  "{\n "
                                                                  "	border:none;\n "
                                                                  "  	background-color:rgb(200,200,200,120);\n "
                                                                  "	border-radius:10px;\n "
                                                                  "};\n "
                                                                  "\n "
                                                                  "background:#f82f5f;\n "
                                                                  "border-radius: 10px;\n "
                                                                  "font:  22pt \"Helvetica Neue\";\\n letter-spacing: 1px;\\n background-color:none;"));
        fanLeftSetMaxSpeedButton->setIconSize(QSize(50, 50));

        horizontalLayout_18->addWidget(fanLeftSetMaxSpeedButton);


        verticalLayout_31->addLayout(horizontalLayout_18);


        fanLeftContainer->addLayout(verticalLayout_31);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        fanLeftContainer->addItem(horizontalSpacer_8);


        verticalLayout_43->addLayout(fanLeftContainer);

        verticalSpacer_5 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_43->addItem(verticalSpacer_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        frame_29 = new QFrame(fansPageContainer);
        frame_29->setObjectName(QString::fromUtf8("frame_29"));
        frame_29->setFrameShape(QFrame::NoFrame);
        frame_29->setFrameShadow(QFrame::Plain);
        verticalLayout_42 = new QVBoxLayout(frame_29);
        verticalLayout_42->setObjectName(QString::fromUtf8("verticalLayout_42"));
        label_14 = new QLabel(frame_29);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setMinimumSize(QSize(128, 128));
        label_14->setMaximumSize(QSize(128, 128));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/images/fan-icon128.png);\n "
                                                  "\n "
                                                  ""));
        label_14->setLineWidth(0);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_42->addWidget(label_14);


        horizontalLayout_9->addWidget(frame_29);

        horizontalSpacer_11 = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);

        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName(QString::fromUtf8("verticalLayout_36"));
        verticalLayout_36->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setVerticalSpacing(2);
        label_65 = new QLabel(fansPageContainer);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        sizePolicy5.setHeightForWidth(label_65->sizePolicy().hasHeightForWidth());
        label_65->setSizePolicy(sizePolicy5);
        label_65->setFont(font3);
        label_65->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 35pt \"Helvetica Neue\";\n "
                                                  "letter-spacing: 1px;\n "
                                                  "background-color:none;"));
        label_65->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_65, 0, 0, 1, 1);

        frame_27 = new QFrame(fansPageContainer);
        frame_27->setObjectName(QString::fromUtf8("frame_27"));
        sizePolicy6.setHeightForWidth(frame_27->sizePolicy().hasHeightForWidth());
        frame_27->setSizePolicy(sizePolicy6);
        frame_27->setMinimumSize(QSize(200, 20));
        frame_27->setMaximumSize(QSize(16777215, 20));
        frame_27->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290;"));
        frame_27->setFrameShape(QFrame::NoFrame);
        frame_27->setFrameShadow(QFrame::Plain);

        gridLayout_11->addWidget(frame_27, 1, 0, 1, 3);

        label_96 = new QLabel(fansPageContainer);
        label_96->setObjectName(QString::fromUtf8("label_96"));
        sizePolicy8.setHeightForWidth(label_96->sizePolicy().hasHeightForWidth());
        label_96->setSizePolicy(sizePolicy8);
        label_96->setMaximumSize(QSize(200, 50));
        label_96->setFont(font4);
        label_96->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_96->setAlignment(Qt::AlignCenter);
        label_96->setWordWrap(true);

        gridLayout_11->addWidget(label_96, 2, 2, 1, 1);

        fanRightMinimumSpeed = new QLabel(fansPageContainer);
        fanRightMinimumSpeed->setObjectName(QString::fromUtf8("fanRightMinimumSpeed"));
        fanRightMinimumSpeed->setFont(font2);
        fanRightMinimumSpeed->setStyleSheet(QString::fromUtf8("letter-spacing: 3px;\n "
                                                              "background:none;"));
        fanRightMinimumSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(fanRightMinimumSpeed, 3, 1, 1, 1);

        label_98 = new QLabel(fansPageContainer);
        label_98->setObjectName(QString::fromUtf8("label_98"));
        sizePolicy8.setHeightForWidth(label_98->sizePolicy().hasHeightForWidth());
        label_98->setSizePolicy(sizePolicy8);
        label_98->setMaximumSize(QSize(200, 50));
        label_98->setFont(font4);
        label_98->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_98->setAlignment(Qt::AlignCenter);
        label_98->setWordWrap(true);

        gridLayout_11->addWidget(label_98, 2, 0, 1, 1);

        fanRightCurrentSpeed = new QLabel(fansPageContainer);
        fanRightCurrentSpeed->setObjectName(QString::fromUtf8("fanRightCurrentSpeed"));
        fanRightCurrentSpeed->setFont(font2);
        fanRightCurrentSpeed->setStyleSheet(QString::fromUtf8("letter-spacing: 3px;\n "
                                                              "background:none;"));
        fanRightCurrentSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(fanRightCurrentSpeed, 3, 0, 1, 1);

        fanRightMaximumSpeed = new QLabel(fansPageContainer);
        fanRightMaximumSpeed->setObjectName(QString::fromUtf8("fanRightMaximumSpeed"));
        fanRightMaximumSpeed->setFont(font2);
        fanRightMaximumSpeed->setStyleSheet(QString::fromUtf8("letter-spacing: 3px;\n "
                                                              "background:none;"));
        fanRightMaximumSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(fanRightMaximumSpeed, 3, 2, 1, 1);

        label_97 = new QLabel(fansPageContainer);
        label_97->setObjectName(QString::fromUtf8("label_97"));
        sizePolicy8.setHeightForWidth(label_97->sizePolicy().hasHeightForWidth());
        label_97->setSizePolicy(sizePolicy8);
        label_97->setMaximumSize(QSize(200, 50));
        label_97->setFont(font4);
        label_97->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 20pt \"Helvetica Neue\";\n "
                                                  "\n "
                                                  "letter-spacing: 2px;\n "
                                                  " margin-bottom:10px;"));
        label_97->setAlignment(Qt::AlignCenter);
        label_97->setWordWrap(true);

        gridLayout_11->addWidget(label_97, 2, 1, 1, 1);


        verticalLayout_36->addLayout(gridLayout_11);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(30);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        fanRightChangeSpeedButton = new QPushButton(fansPageContainer);
        fanRightChangeSpeedButton->setObjectName(QString::fromUtf8("fanRightChangeSpeedButton"));
        sizePolicy5.setHeightForWidth(fanRightChangeSpeedButton->sizePolicy().hasHeightForWidth());
        fanRightChangeSpeedButton->setSizePolicy(sizePolicy5);
        fanRightChangeSpeedButton->setMinimumSize(QSize(200, 40));
        fanRightChangeSpeedButton->setMaximumSize(QSize(300, 50));
        fanRightChangeSpeedButton->setCursor(QCursor(Qt::PointingHandCursor));
        fanRightChangeSpeedButton->setStyleSheet(QString::fromUtf8("\n "
                                                                   "QPushButton:hover#fanRightChangeSpeedButton\n "
                                                                   "{\n "
                                                                   "	border:none;\n "
                                                                   "  	background-color:rgb(200,200,200, 120);\n "
                                                                   "	border-radius:10px;\n "
                                                                   "	\n "
                                                                   "};\n "
                                                                   "\n "
                                                                   "background:#f82f5f;\n "
                                                                   "border-radius: 10px;\n "
                                                                   "font:  22pt \"Helvetica Neue\";\\n letter-spacing: 1px;\\n background-color:none;"));
        fanRightChangeSpeedButton->setIconSize(QSize(50, 50));

        horizontalLayout_19->addWidget(fanRightChangeSpeedButton);

        fanRightSetAutoSpeedButton = new QPushButton(fansPageContainer);
        fanRightSetAutoSpeedButton->setObjectName(QString::fromUtf8("fanRightSetAutoSpeedButton"));
        sizePolicy5.setHeightForWidth(fanRightSetAutoSpeedButton->sizePolicy().hasHeightForWidth());
        fanRightSetAutoSpeedButton->setSizePolicy(sizePolicy5);
        fanRightSetAutoSpeedButton->setMinimumSize(QSize(200, 40));
        fanRightSetAutoSpeedButton->setMaximumSize(QSize(300, 50));
        fanRightSetAutoSpeedButton->setCursor(QCursor(Qt::PointingHandCursor));
        fanRightSetAutoSpeedButton->setStyleSheet(QString::fromUtf8("\n "
                                                                    "QPushButton:hover#fanRightSetAutoSpeedButton\n "
                                                                    "{\n "
                                                                    "	border:none;\n "
                                                                    "  	background-color:rgb(200,200,200,120);\n "
                                                                    "	border-radius:10px;\n "
                                                                    "	\n "
                                                                    "};\n "
                                                                    "\n "
                                                                    "background:#2576eb;\n "
                                                                    "border-radius: 10px;\n "
                                                                    "font:  22pt \"Helvetica Neue\";\\n letter-spacing: 1px;\\n background-color:none;\n "
                                                                    "\n "
                                                                    ""));
        fanRightSetAutoSpeedButton->setIconSize(QSize(50, 50));

        horizontalLayout_19->addWidget(fanRightSetAutoSpeedButton);

        fanRightSetMaxSpeedButton = new QPushButton(fansPageContainer);
        fanRightSetMaxSpeedButton->setObjectName(QString::fromUtf8("fanRightSetMaxSpeedButton"));
        sizePolicy5.setHeightForWidth(fanRightSetMaxSpeedButton->sizePolicy().hasHeightForWidth());
        fanRightSetMaxSpeedButton->setSizePolicy(sizePolicy5);
        fanRightSetMaxSpeedButton->setMinimumSize(QSize(250, 40));
        fanRightSetMaxSpeedButton->setMaximumSize(QSize(300, 50));
        fanRightSetMaxSpeedButton->setCursor(QCursor(Qt::PointingHandCursor));
        fanRightSetMaxSpeedButton->setStyleSheet(QString::fromUtf8("\n "
                                                                   "QPushButton:hover#fanRightSetMaxSpeedButton\n "
                                                                   "{\n "
                                                                   "	border:none;\n "
                                                                   "  	background-color:rgb(200,200,200,120);\n "
                                                                   "	border-radius:10px;\n "
                                                                   "	\n "
                                                                   "};\n "
                                                                   "\n "
                                                                   "background:#f82f5f;\n "
                                                                   "border-radius: 10px;\n "
                                                                   "font:  22pt \"Helvetica Neue\";\\n letter-spacing: 1px;\\n background-color:none;"));
        fanRightSetMaxSpeedButton->setIconSize(QSize(50, 50));

        horizontalLayout_19->addWidget(fanRightSetMaxSpeedButton);


        verticalLayout_36->addLayout(horizontalLayout_19);


        horizontalLayout_9->addLayout(verticalLayout_36);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_43->addLayout(horizontalLayout_9);

        verticalSpacer_4 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_43->addItem(verticalSpacer_4);


        verticalLayout_30->addWidget(fansPageContainer);

        stackedWidget->addWidget(fansPage);
        networkPage = new QWidget();
        networkPage->setObjectName(QString::fromUtf8("networkPage"));
        verticalLayout_49 = new QVBoxLayout(networkPage);
        verticalLayout_49->setObjectName(QString::fromUtf8("verticalLayout_49"));
        fansPageContainer_2 = new QFrame(networkPage);
        fansPageContainer_2->setObjectName(QString::fromUtf8("fansPageContainer_2"));
        sizePolicy1.setHeightForWidth(fansPageContainer_2->sizePolicy().hasHeightForWidth());
        fansPageContainer_2->setSizePolicy(sizePolicy1);
        fansPageContainer_2->setFrameShape(QFrame::NoFrame);
        fansPageContainer_2->setFrameShadow(QFrame::Sunken);
        verticalLayout_7 = new QVBoxLayout(fansPageContainer_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(40, 40, 40, -1);
        NetworkContainer = new QVBoxLayout();
        NetworkContainer->setObjectName(QString::fromUtf8("NetworkContainer"));
        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        label_99 = new QLabel(fansPageContainer_2);
        label_99->setObjectName(QString::fromUtf8("label_99"));
        QSizePolicy sizePolicy9(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
        sizePolicy9.setHorizontalStretch(200);
        sizePolicy9.setVerticalStretch(200);
        sizePolicy9.setHeightForWidth(label_99->sizePolicy().hasHeightForWidth());
        label_99->setSizePolicy(sizePolicy9);
        label_99->setMaximumSize(QSize(16777215, 40));
        label_99->setFont(font1);
        label_99->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));
        label_99->setWordWrap(true);

        horizontalLayout_45->addWidget(label_99);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_45->addItem(horizontalSpacer_12);

        ssidContainer = new QHBoxLayout();
        ssidContainer->setObjectName(QString::fromUtf8("ssidContainer"));
        networkIcon = new QLabel(fansPageContainer_2);
        networkIcon->setObjectName(QString::fromUtf8("networkIcon"));
        sizePolicy.setHeightForWidth(networkIcon->sizePolicy().hasHeightForWidth());
        networkIcon->setSizePolicy(sizePolicy);
        networkIcon->setMinimumSize(QSize(40, 40));
        networkIcon->setMaximumSize(QSize(40, 40));
        networkIcon->setStyleSheet(QString::fromUtf8("image: url(:/images/connection.svg);"));
        networkIcon->setLineWidth(0);
        networkIcon->setAlignment(Qt::AlignCenter);

        ssidContainer->addWidget(networkIcon);

        ssidName = new QLabel(fansPageContainer_2);
        ssidName->setObjectName(QString::fromUtf8("ssidName"));
        sizePolicy9.setHeightForWidth(ssidName->sizePolicy().hasHeightForWidth());
        ssidName->setSizePolicy(sizePolicy9);
        ssidName->setMaximumSize(QSize(16777215, 30));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Helvetica Neue"));
        font7.setPointSize(32);
        font7.setBold(false);
        font7.setItalic(false);
        font7.setWeight(50);
        ssidName->setFont(font7);
        ssidName->setStyleSheet(QString::fromUtf8("\n "
                                                  "font:  32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;\n "
                                                  "margin-left: 10px;"));
        ssidName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ssidName->setWordWrap(true);

        ssidContainer->addWidget(ssidName);


        horizontalLayout_45->addLayout(ssidContainer);


        NetworkContainer->addLayout(horizontalLayout_45);

        frame_30 = new QFrame(fansPageContainer_2);
        frame_30->setObjectName(QString::fromUtf8("frame_30"));
        sizePolicy6.setHeightForWidth(frame_30->sizePolicy().hasHeightForWidth());
        frame_30->setSizePolicy(sizePolicy6);
        frame_30->setMinimumSize(QSize(100, 10));
        frame_30->setMaximumSize(QSize(16777215, 10));
        frame_30->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_30->setFrameShape(QFrame::NoFrame);
        frame_30->setFrameShadow(QFrame::Plain);

        NetworkContainer->addWidget(frame_30);


        verticalLayout_7->addLayout(NetworkContainer);

        ipv4AddressContainer = new QGridLayout();
        ipv4AddressContainer->setObjectName(QString::fromUtf8("ipv4AddressContainer"));
        ipv4AddressContainer->setContentsMargins(15, -1, -1, -1);
        label_69 = new QLabel(fansPageContainer_2);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Helvetica Neue"));
        font8.setPointSize(22);
        font8.setBold(false);
        font8.setItalic(false);
        font8.setWeight(3);
        label_69->setFont(font8);
        label_69->setStyleSheet(QString::fromUtf8("\n "
                                                  "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                  "background:none;"));

        ipv4AddressContainer->addWidget(label_69, 0, 0, 1, 1);

        ipv4Address = new QLabel(fansPageContainer_2);
        ipv4Address->setObjectName(QString::fromUtf8("ipv4Address"));
        ipv4Address->setFont(font2);
        ipv4Address->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                     "background-color:none;"));
        ipv4Address->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ipv4Address->setMargin(10);

        ipv4AddressContainer->addWidget(ipv4Address, 0, 1, 1, 1);

        frame_32 = new QFrame(fansPageContainer_2);
        frame_32->setObjectName(QString::fromUtf8("frame_32"));
        frame_32->setMinimumSize(QSize(0, 10));
        frame_32->setMaximumSize(QSize(16777215, 10));
        frame_32->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_32->setFrameShape(QFrame::NoFrame);
        frame_32->setFrameShadow(QFrame::Plain);

        ipv4AddressContainer->addWidget(frame_32, 1, 0, 1, 2);


        verticalLayout_7->addLayout(ipv4AddressContainer);

        ipv6AddressContainer = new QGridLayout();
        ipv6AddressContainer->setObjectName(QString::fromUtf8("ipv6AddressContainer"));
        ipv6AddressContainer->setContentsMargins(15, -1, -1, -1);
        label_101 = new QLabel(fansPageContainer_2);
        label_101->setObjectName(QString::fromUtf8("label_101"));
        label_101->setFont(font8);
        label_101->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        ipv6AddressContainer->addWidget(label_101, 0, 0, 1, 1);

        ipv6Address = new QLabel(fansPageContainer_2);
        ipv6Address->setObjectName(QString::fromUtf8("ipv6Address"));
        ipv6Address->setFont(font2);
        ipv6Address->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                     "background-color:none;"));
        ipv6Address->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ipv6Address->setMargin(10);

        ipv6AddressContainer->addWidget(ipv6Address, 0, 1, 1, 1);

        frame_33 = new QFrame(fansPageContainer_2);
        frame_33->setObjectName(QString::fromUtf8("frame_33"));
        frame_33->setMinimumSize(QSize(0, 10));
        frame_33->setMaximumSize(QSize(16777215, 40));
        frame_33->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_33->setFrameShape(QFrame::NoFrame);
        frame_33->setFrameShadow(QFrame::Plain);

        ipv6AddressContainer->addWidget(frame_33, 1, 0, 1, 2);


        verticalLayout_7->addLayout(ipv6AddressContainer);

        macAddressContainer = new QGridLayout();
        macAddressContainer->setObjectName(QString::fromUtf8("macAddressContainer"));
        macAddressContainer->setContentsMargins(15, -1, -1, -1);
        label_104 = new QLabel(fansPageContainer_2);
        label_104->setObjectName(QString::fromUtf8("label_104"));
        label_104->setFont(font8);
        label_104->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        macAddressContainer->addWidget(label_104, 0, 0, 1, 1);

        macAddress = new QLabel(fansPageContainer_2);
        macAddress->setObjectName(QString::fromUtf8("macAddress"));
        macAddress->setFont(font2);
        macAddress->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                    "background-color:none;"));
        macAddress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        macAddress->setMargin(10);

        macAddressContainer->addWidget(macAddress, 0, 1, 1, 1);

        frame_34 = new QFrame(fansPageContainer_2);
        frame_34->setObjectName(QString::fromUtf8("frame_34"));
        frame_34->setMinimumSize(QSize(0, 10));
        frame_34->setMaximumSize(QSize(16777215, 40));
        frame_34->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_34->setFrameShape(QFrame::NoFrame);
        frame_34->setFrameShadow(QFrame::Plain);

        macAddressContainer->addWidget(frame_34, 1, 0, 1, 2);


        verticalLayout_7->addLayout(macAddressContainer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_7->addItem(verticalSpacer_2);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_106 = new QLabel(fansPageContainer_2);
        label_106->setObjectName(QString::fromUtf8("label_106"));
        sizePolicy9.setHeightForWidth(label_106->sizePolicy().hasHeightForWidth());
        label_106->setSizePolicy(sizePolicy9);
        label_106->setFont(font1);
        label_106->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));
        label_106->setWordWrap(true);

        horizontalLayout_44->addWidget(label_106);

        testConnectionSpeedButton = new QPushButton(fansPageContainer_2);
        testConnectionSpeedButton->setObjectName(QString::fromUtf8("testConnectionSpeedButton"));
        sizePolicy5.setHeightForWidth(testConnectionSpeedButton->sizePolicy().hasHeightForWidth());
        testConnectionSpeedButton->setSizePolicy(sizePolicy5);
        testConnectionSpeedButton->setMinimumSize(QSize(200, 40));
        testConnectionSpeedButton->setMaximumSize(QSize(300, 40));
        testConnectionSpeedButton->setCursor(QCursor(Qt::PointingHandCursor));
        testConnectionSpeedButton->setStyleSheet(QString::fromUtf8("\n "
                                                                   "\n "
                                                                   "QPushButton:hover#testConnectionSpeedButton\n "
                                                                   "{\n "
                                                                   "	border:none;\n "
                                                                   "  	background-color:rgb(200,200,200,120);\n "
                                                                   "	border-radius:10px;\n "
                                                                   "	\n "
                                                                   "};\n "
                                                                   "\n "
                                                                   "background:#2576eb;\n "
                                                                   "border-radius: 10px;\n "
                                                                   "font:  22pt \"Helvetica Neue\";\\n letter-spacing: 1px;\\n background-color:none;\n "
                                                                   ""));
        testConnectionSpeedButton->setIconSize(QSize(50, 50));

        horizontalLayout_44->addWidget(testConnectionSpeedButton);


        verticalLayout_7->addLayout(horizontalLayout_44);

        frame_35 = new QFrame(fansPageContainer_2);
        frame_35->setObjectName(QString::fromUtf8("frame_35"));
        sizePolicy1.setHeightForWidth(frame_35->sizePolicy().hasHeightForWidth());
        frame_35->setSizePolicy(sizePolicy1);
        frame_35->setMinimumSize(QSize(100, 10));
        frame_35->setMaximumSize(QSize(16777215, 40));
        frame_35->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_35->setFrameShape(QFrame::NoFrame);
        frame_35->setFrameShadow(QFrame::Plain);

        verticalLayout_7->addWidget(frame_35);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        downloadSpeedContainer = new QFrame(fansPageContainer_2);
        downloadSpeedContainer->setObjectName(QString::fromUtf8("downloadSpeedContainer"));
        downloadSpeedContainer->setMinimumSize(QSize(235, 250));
        downloadSpeedContainer->setMaximumSize(QSize(235, 400));
        downloadSpeedContainer->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                                "border:none;"));
        downloadSpeedContainer->setFrameShape(QFrame::NoFrame);
        downloadSpeedContainer->setFrameShadow(QFrame::Plain);
        downloadSpeedContainer->setLineWidth(0);
        verticalLayout_68 = new QVBoxLayout(downloadSpeedContainer);
        verticalLayout_68->setObjectName(QString::fromUtf8("verticalLayout_68"));
        chart_container_2 = new QFrame(downloadSpeedContainer);
        chart_container_2->setObjectName(QString::fromUtf8("chart_container_2"));
        chart_container_2->setMaximumSize(QSize(16777215, 162));
        chart_container_2->setFrameShape(QFrame::NoFrame);
        chart_container_2->setFrameShadow(QFrame::Plain);
        chart_container_2->setLineWidth(0);
        horizontalLayout_24 = new QHBoxLayout(chart_container_2);
        horizontalLayout_24->setSpacing(0);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_6 = new QFrame(chart_container_2);
        circularProgressBarBase_6->setObjectName(QString::fromUtf8("circularProgressBarBase_6"));
        circularProgressBarBase_6->setEnabled(true);
        circularProgressBarBase_6->setMinimumSize(QSize(200, 200));
        circularProgressBarBase_6->setMaximumSize(QSize(200, 200));
        circularProgressBarBase_6->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_6->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_6->setLineWidth(0);
        circuralProgressDownloadSpeed = new QFrame(circularProgressBarBase_6);
        circuralProgressDownloadSpeed->setObjectName(QString::fromUtf8("circuralProgressDownloadSpeed"));
        circuralProgressDownloadSpeed->setGeometry(QRect(0, 0, 200, 200));
        circuralProgressDownloadSpeed->setMinimumSize(QSize(200, 200));
        circuralProgressDownloadSpeed->setMaximumSize(QSize(200, 200));
        circuralProgressDownloadSpeed->setStyleSheet(QString::fromUtf8("QFrame { \n "
                                                            "	border-radius: 100px;\n "
                                                            "	background-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n "
                                                            "}"));

        circuralProgressDownloadSpeed->setFrameShape(QFrame::NoFrame);
        circuralProgressDownloadSpeed->setFrameShadow(QFrame::Plain);
        circuralProgressDownloadSpeed->setLineWidth(0);
        circuralBg_8 = new QFrame(circularProgressBarBase_6);
        circuralBg_8->setObjectName(QString::fromUtf8("circuralBg_8"));
        circuralBg_8->setGeometry(QRect(0, 0, 200, 200));
        circuralBg_8->setMinimumSize(QSize(200, 200));
        circuralBg_8->setMaximumSize(QSize(200, 200));
        circuralBg_8->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                      "	border-radius: 100px;\n "
                                                      "	background-image: url(:/images/background-image.png);\n "
                                                      "}\n "
                                                      "\n "
                                                      ""));
        circuralBg_8->setFrameShape(QFrame::NoFrame);
        circuralBg_8->setFrameShadow(QFrame::Plain);
        circuralBg_8->setLineWidth(0);
        circuralContainer_8 = new QFrame(circularProgressBarBase_6);
        circuralContainer_8->setObjectName(QString::fromUtf8("circuralContainer_8"));
        circuralContainer_8->setGeometry(QRect(5, 5, 190, 190));
        circuralContainer_8->setMinimumSize(QSize(190, 190));
        circuralContainer_8->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                             " border-radius:95px;\n "
                                                             "	background: #1a172d;\n "
                                                             "}\n "
                                                             "\n "
                                                             "QFrame:hover {\n "
                                                             "	background-color: #2b283e;\n "
                                                             "}\n "
                                                             ""));
        circuralContainer_8->setFrameShape(QFrame::NoFrame);
        circuralContainer_8->setFrameShadow(QFrame::Plain);
        circuralContainer_8->setLineWidth(0);
        verticalLayout_56 = new QVBoxLayout(circuralContainer_8);
        verticalLayout_56->setSpacing(0);
        verticalLayout_56->setObjectName(QString::fromUtf8("verticalLayout_56"));
        verticalLayout_56->setContentsMargins(0, 0, 0, 0);
        downloadSpeed = new QLabel(circuralContainer_8);
        downloadSpeed->setObjectName(QString::fromUtf8("downloadSpeed"));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Courier New"));
        font9.setPointSize(24);
        font9.setBold(false);
        font9.setItalic(false);
        font9.setUnderline(false);
        font9.setWeight(50);
        font9.setStrikeOut(false);
        font9.setKerning(true);
        downloadSpeed->setFont(font9);
        downloadSpeed->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                       "color: #afafaf;\n "
                                                       "background:none;"));
        downloadSpeed->setAlignment(Qt::AlignCenter);

        verticalLayout_56->addWidget(downloadSpeed);

        circuralBg_8->raise();
        circuralProgressDownloadSpeed->raise();
        circuralContainer_8->raise();

        horizontalLayout_24->addWidget(circularProgressBarBase_6);


        verticalLayout_68->addWidget(chart_container_2);

        chart_percentage_20 = new QLabel(downloadSpeedContainer);
        chart_percentage_20->setObjectName(QString::fromUtf8("chart_percentage_20"));
        chart_percentage_20->setFont(font9);
        chart_percentage_20->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                             "color: #afafaf;\n "
                                                             "background:none;"));
        chart_percentage_20->setAlignment(Qt::AlignCenter);

        verticalLayout_68->addWidget(chart_percentage_20);


        horizontalLayout_37->addWidget(downloadSpeedContainer);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_37->addItem(horizontalSpacer_19);

        UploadSpeedContainer = new QFrame(fansPageContainer_2);
        UploadSpeedContainer->setObjectName(QString::fromUtf8("UploadSpeedContainer"));
        UploadSpeedContainer->setMinimumSize(QSize(235, 250));
        UploadSpeedContainer->setMaximumSize(QSize(235, 400));
        UploadSpeedContainer->setStyleSheet(QString::fromUtf8("background: none;\n "
                                                              "border:none;"));
        UploadSpeedContainer->setFrameShape(QFrame::NoFrame);
        UploadSpeedContainer->setFrameShadow(QFrame::Plain);
        UploadSpeedContainer->setLineWidth(0);
        verticalLayout_70 = new QVBoxLayout(UploadSpeedContainer);
        verticalLayout_70->setObjectName(QString::fromUtf8("verticalLayout_70"));
        chart_container_13 = new QFrame(UploadSpeedContainer);
        chart_container_13->setObjectName(QString::fromUtf8("chart_container_13"));
        chart_container_13->setMaximumSize(QSize(16777215, 162));
        chart_container_13->setFrameShape(QFrame::NoFrame);
        chart_container_13->setFrameShadow(QFrame::Plain);
        chart_container_13->setLineWidth(0);
        horizontalLayout_38 = new QHBoxLayout(chart_container_13);
        horizontalLayout_38->setSpacing(0);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        horizontalLayout_38->setContentsMargins(0, 0, 0, 0);
        circularProgressBarBase_16 = new QFrame(chart_container_13);
        circularProgressBarBase_16->setObjectName(QString::fromUtf8("circularProgressBarBase_16"));
        circularProgressBarBase_16->setEnabled(true);
        circularProgressBarBase_16->setMinimumSize(QSize(200, 200));
        circularProgressBarBase_16->setMaximumSize(QSize(200, 200));
        circularProgressBarBase_16->setFrameShape(QFrame::NoFrame);
        circularProgressBarBase_16->setFrameShadow(QFrame::Plain);
        circularProgressBarBase_16->setLineWidth(0);
        circuralProgressUploadSpeed = new QFrame(circularProgressBarBase_16);
        circuralProgressUploadSpeed->setObjectName(QString::fromUtf8("circuralProgressUploadSpeed"));
        circuralProgressUploadSpeed->setGeometry(QRect(0, 0, 200, 200));
        circuralProgressUploadSpeed->setMinimumSize(QSize(200, 200));
        circuralProgressUploadSpeed->setMaximumSize(QSize(200, 200));
        circuralProgressUploadSpeed->setStyleSheet(QString::fromUtf8("QFrame { \n "
                                                             "	border-radius: 100px;\n "
                                                             "	background-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 #4798ff);\n "
                                                             "}"));
//        qconicalgradient(cx:0.5, cy:0.5, angle:-135, stop:0.749 rgba(255, 255, 255, 0), stop:1 #4798ff)
        circuralProgressUploadSpeed->setFrameShape(QFrame::NoFrame);
        circuralProgressUploadSpeed->setFrameShadow(QFrame::Plain);
        circuralProgressUploadSpeed->setLineWidth(0);
        circuralBg_18 = new QFrame(circularProgressBarBase_16);
        circuralBg_18->setObjectName(QString::fromUtf8("circuralBg_18"));
        circuralBg_18->setGeometry(QRect(0, 0, 200, 200));
        circuralBg_18->setMinimumSize(QSize(200, 200));
        circuralBg_18->setMaximumSize(QSize(200, 200));
        circuralBg_18->setStyleSheet(QString::fromUtf8("QFrame{\n "
                                                       "	border-radius: 100px;\n "
                                                       "	background-image: url(:/images/background-image.png);\n "
                                                       "}\n "
                                                       "\n "
                                                       ""));
        circuralBg_18->setFrameShape(QFrame::NoFrame);
        circuralBg_18->setFrameShadow(QFrame::Plain);
        circuralBg_18->setLineWidth(0);
        circuralContainer_18 = new QFrame(circularProgressBarBase_16);
        circuralContainer_18->setObjectName(QString::fromUtf8("circuralContainer_18"));
        circuralContainer_18->setGeometry(QRect(5, 5, 190, 190));
        circuralContainer_18->setMinimumSize(QSize(190, 190));
        circuralContainer_18->setStyleSheet(QString::fromUtf8("QFrame {\n "
                                                              " border-radius:95px;\n "
                                                              "	background: #1a172d;\n "
                                                              "}\n "
                                                              "\n "
                                                              "QFrame:hover {\n "
                                                              "	background-color: #2b283e;\n "
                                                              "}\n "
                                                              ""));
        circuralContainer_18->setFrameShape(QFrame::NoFrame);
        circuralContainer_18->setFrameShadow(QFrame::Plain);
        circuralContainer_18->setLineWidth(0);
        verticalLayout_67 = new QVBoxLayout(circuralContainer_18);
        verticalLayout_67->setSpacing(0);
        verticalLayout_67->setObjectName(QString::fromUtf8("verticalLayout_67"));
        verticalLayout_67->setContentsMargins(0, 0, 0, 0);
        uploadSpeed = new QLabel(circuralContainer_18);
        uploadSpeed->setObjectName(QString::fromUtf8("uploadSpeed"));
        uploadSpeed->setFont(font9);
        uploadSpeed->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                     "color: #afafaf;\n "
                                                     "background:none;"));
        uploadSpeed->setAlignment(Qt::AlignCenter);

        verticalLayout_67->addWidget(uploadSpeed);

        circuralBg_18->raise();
        circuralProgressUploadSpeed->raise();
        circuralContainer_18->raise();

        horizontalLayout_38->addWidget(circularProgressBarBase_16);


        verticalLayout_70->addWidget(chart_container_13);

        chart_percentage_23 = new QLabel(UploadSpeedContainer);
        chart_percentage_23->setObjectName(QString::fromUtf8("chart_percentage_23"));
        chart_percentage_23->setFont(font9);
        chart_percentage_23->setStyleSheet(QString::fromUtf8("border:none;\n "
                                                             "color: #afafaf;\n "
                                                             "background:none;"));
        chart_percentage_23->setAlignment(Qt::AlignCenter);

        verticalLayout_70->addWidget(chart_percentage_23);


        horizontalLayout_37->addWidget(UploadSpeedContainer);


        horizontalLayout_39->addLayout(horizontalLayout_37);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_13);

        networkInformationContainer = new QVBoxLayout();
        networkInformationContainer->setObjectName(QString::fromUtf8("networkInformationContainer"));
        networkServerContainer = new QGridLayout();
        networkServerContainer->setObjectName(QString::fromUtf8("networkServerContainer"));
        label_107 = new QLabel(fansPageContainer_2);
        label_107->setObjectName(QString::fromUtf8("label_107"));
        label_107->setFont(font8);
        label_107->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        networkServerContainer->addWidget(label_107, 0, 0, 1, 1);

        networkServer = new QLabel(fansPageContainer_2);
        networkServer->setObjectName(QString::fromUtf8("networkServer"));
        networkServer->setFont(font2);
        networkServer->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                       "background-color:none;"
                                                       "font-size: 17px"));
        networkServer->setTextFormat(Qt::RichText);
        networkServer->setScaledContents(false);
        networkServer->setMinimumWidth(350);
        networkServer->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        networkServer->setWordWrap(true);
        networkServer->setMargin(10);
        networkServer->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        networkServerContainer->addWidget(networkServer, 0, 1, 1, 1);

        frame_36 = new QFrame(fansPageContainer_2);
        frame_36->setObjectName(QString::fromUtf8("frame_36"));
        frame_36->setMaximumSize(QSize(16777215, 40));
        frame_36->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_36->setFrameShape(QFrame::NoFrame);
        frame_36->setFrameShadow(QFrame::Plain);

        networkServerContainer->addWidget(frame_36, 1, 0, 1, 2);


        networkInformationContainer->addLayout(networkServerContainer);

        downloadSpeedTableContainer = new QGridLayout();
        downloadSpeedTableContainer->setObjectName(QString::fromUtf8("downloadSpeedTableContainer"));
        label_112 = new QLabel(fansPageContainer_2);
        label_112->setObjectName(QString::fromUtf8("label_112"));
        label_112->setFont(font8);
        label_112->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        downloadSpeedTableContainer->addWidget(label_112, 0, 0, 1, 1);

        downloadSpeedTable = new QLabel(fansPageContainer_2);
        downloadSpeedTable->setObjectName(QString::fromUtf8("downloadSpeedTable"));
        downloadSpeedTable->setFont(font2);
        downloadSpeedTable->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                            "background-color:none;"));
        downloadSpeedTable->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        downloadSpeedTable->setMinimumWidth(200);

        downloadSpeedTable->setMargin(10);

        downloadSpeedTableContainer->addWidget(downloadSpeedTable, 0, 1, 1, 1);

        frame_38 = new QFrame(fansPageContainer_2);
        frame_38->setObjectName(QString::fromUtf8("frame_38"));
        frame_38->setMaximumSize(QSize(16777215, 40));
        frame_38->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_38->setFrameShape(QFrame::NoFrame);
        frame_38->setFrameShadow(QFrame::Plain);

        downloadSpeedTableContainer->addWidget(frame_38, 1, 0, 1, 2);


        networkInformationContainer->addLayout(downloadSpeedTableContainer);

        uploadSpeedTableContainer = new QGridLayout();
        uploadSpeedTableContainer->setObjectName(QString::fromUtf8("uploadSpeedTableContainer"));
        label_114 = new QLabel(fansPageContainer_2);
        label_114->setObjectName(QString::fromUtf8("label_114"));
        label_114->setFont(font8);
        label_114->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        uploadSpeedTableContainer->addWidget(label_114, 0, 0, 1, 1);

        uploadSpeedTable = new QLabel(fansPageContainer_2);
        uploadSpeedTable->setObjectName(QString::fromUtf8("uploadSpeedTable"));
        uploadSpeedTable->setFont(font2);
        uploadSpeedTable->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                          "background-color:none;"));
        uploadSpeedTable->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        uploadSpeedTable->setMinimumWidth(200);

        uploadSpeedTable->setMargin(10);

        uploadSpeedTableContainer->addWidget(uploadSpeedTable, 0, 1, 1, 1);

        frame_39 = new QFrame(fansPageContainer_2);
        frame_39->setObjectName(QString::fromUtf8("frame_39"));
        frame_39->setMaximumSize(QSize(16777215, 40));
        frame_39->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_39->setFrameShape(QFrame::NoFrame);
        frame_39->setFrameShadow(QFrame::Plain);

        uploadSpeedTableContainer->addWidget(frame_39, 1, 0, 1, 2);


        networkInformationContainer->addLayout(uploadSpeedTableContainer);

        connectionPingContainer = new QGridLayout();
        connectionPingContainer->setObjectName(QString::fromUtf8("connectionPingContainer"));
        label_116 = new QLabel(fansPageContainer_2);
        label_116->setObjectName(QString::fromUtf8("label_116"));
        label_116->setFont(font8);
        label_116->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        connectionPingContainer->addWidget(label_116, 0, 0, 1, 1);

        connectionPing = new QLabel(fansPageContainer_2);
        connectionPing->setObjectName(QString::fromUtf8("connectionPing"));
        connectionPing->setFont(font2);
        connectionPing->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                        "background-color:none;"));
        connectionPing->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        connectionPing->setMargin(10);

        connectionPingContainer->addWidget(connectionPing, 0, 1, 1, 1);

        frame_40 = new QFrame(fansPageContainer_2);
        frame_40->setObjectName(QString::fromUtf8("frame_40"));
        frame_40->setMaximumSize(QSize(16777215, 40));
        frame_40->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_40->setFrameShape(QFrame::NoFrame);
        frame_40->setFrameShadow(QFrame::Plain);

        connectionPingContainer->addWidget(frame_40, 1, 0, 1, 2);


        networkInformationContainer->addLayout(connectionPingContainer);


        horizontalLayout_39->addLayout(networkInformationContainer);


        verticalLayout_7->addLayout(horizontalLayout_39);


        verticalLayout_49->addWidget(fansPageContainer_2);

        stackedWidget->addWidget(networkPage);
        hardwarePage = new QWidget();
        hardwarePage->setObjectName(QString::fromUtf8("hardwarePage"));
        verticalLayout_83 = new QVBoxLayout(hardwarePage);
        verticalLayout_83->setObjectName(QString::fromUtf8("verticalLayout_83"));
        fansPageContainer_3 = new QFrame(hardwarePage);
        fansPageContainer_3->setObjectName(QString::fromUtf8("fansPageContainer_3"));
        sizePolicy1.setHeightForWidth(fansPageContainer_3->sizePolicy().hasHeightForWidth());
        fansPageContainer_3->setSizePolicy(sizePolicy1);
        fansPageContainer_3->setFrameShape(QFrame::NoFrame);
        fansPageContainer_3->setFrameShadow(QFrame::Sunken);
        verticalLayout_64 = new QVBoxLayout(fansPageContainer_3);
        verticalLayout_64->setObjectName(QString::fromUtf8("verticalLayout_64"));
        verticalLayout_64->setContentsMargins(40, 43, 40, 40);
        verticalLayout_63 = new QVBoxLayout();
        verticalLayout_63->setObjectName(QString::fromUtf8("verticalLayout_63"));
        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setObjectName(QString::fromUtf8("horizontalLayout_47"));
        label_131 = new QLabel(fansPageContainer_3);
        label_131->setObjectName(QString::fromUtf8("label_131"));
        sizePolicy9.setHeightForWidth(label_131->sizePolicy().hasHeightForWidth());
        label_131->setSizePolicy(sizePolicy9);
        label_131->setMaximumSize(QSize(16777215, 40));
        label_131->setFont(font1);
        label_131->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));
        label_131->setWordWrap(true);

        horizontalLayout_47->addWidget(label_131);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_47->addItem(horizontalSpacer_20);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        massMemoryModel = new QLabel(fansPageContainer_3);
        massMemoryModel->setObjectName(QString::fromUtf8("massMemoryModel"));
        sizePolicy9.setHeightForWidth(massMemoryModel->sizePolicy().hasHeightForWidth());
        massMemoryModel->setSizePolicy(sizePolicy9);
        massMemoryModel->setMaximumSize(QSize(16777215, 30));
        massMemoryModel->setFont(font7);
        massMemoryModel->setStyleSheet(QString::fromUtf8("\n "
                                                         "font:  32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                         "background:none;"));
        massMemoryModel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        massMemoryModel->setWordWrap(true);

        horizontalLayout_20->addWidget(massMemoryModel);


        horizontalLayout_47->addLayout(horizontalLayout_20);


        verticalLayout_63->addLayout(horizontalLayout_47);

        frame_60 = new QFrame(fansPageContainer_3);
        frame_60->setObjectName(QString::fromUtf8("frame_60"));
        sizePolicy6.setHeightForWidth(frame_60->sizePolicy().hasHeightForWidth());
        frame_60->setSizePolicy(sizePolicy6);
        frame_60->setMinimumSize(QSize(100, 10));
        frame_60->setMaximumSize(QSize(16777215, 10));
        frame_60->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_60->setFrameShape(QFrame::NoFrame);
        frame_60->setFrameShadow(QFrame::Plain);

        verticalLayout_63->addWidget(frame_60);


        verticalLayout_64->addLayout(verticalLayout_63);

        massAvailableMemoryContainer = new QGridLayout();
        massAvailableMemoryContainer->setObjectName(QString::fromUtf8("massAvailableMemoryContainer"));
        massAvailableMemoryContainer->setContentsMargins(15, -1, -1, -1);
        label_129 = new QLabel(fansPageContainer_3);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setFont(font8);
        label_129->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        massAvailableMemoryContainer->addWidget(label_129, 0, 0, 1, 1);

        massAvailableMemory = new QLabel(fansPageContainer_3);
        massAvailableMemory->setObjectName(QString::fromUtf8("massAvailableMemory"));
        massAvailableMemory->setFont(font2);
        massAvailableMemory->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                             "background-color:none;"));
        massAvailableMemory->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        massAvailableMemory->setMargin(10);

        massAvailableMemoryContainer->addWidget(massAvailableMemory, 0, 1, 1, 1);

        frame_55 = new QFrame(fansPageContainer_3);
        frame_55->setObjectName(QString::fromUtf8("frame_55"));
        frame_55->setMinimumSize(QSize(0, 10));
        frame_55->setMaximumSize(QSize(16777215, 10));
        frame_55->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_55->setFrameShape(QFrame::NoFrame);
        frame_55->setFrameShadow(QFrame::Plain);

        massAvailableMemoryContainer->addWidget(frame_55, 1, 0, 1, 2);


        verticalLayout_64->addLayout(massAvailableMemoryContainer);

        massTotalMemoryContainer = new QGridLayout();
        massTotalMemoryContainer->setObjectName(QString::fromUtf8("massTotalMemoryContainer"));
        massTotalMemoryContainer->setContentsMargins(15, -1, -1, -1);
        label_149 = new QLabel(fansPageContainer_3);
        label_149->setObjectName(QString::fromUtf8("label_149"));
        label_149->setFont(font8);
        label_149->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        massTotalMemoryContainer->addWidget(label_149, 0, 0, 1, 1);

        massTotalMemory = new QLabel(fansPageContainer_3);
        massTotalMemory->setObjectName(QString::fromUtf8("massTotalMemory"));
        massTotalMemory->setFont(font2);
        massTotalMemory->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                         "background-color:none;"));
        massTotalMemory->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        massTotalMemory->setMargin(10);

        massTotalMemoryContainer->addWidget(massTotalMemory, 0, 1, 1, 1);

        frame_62 = new QFrame(fansPageContainer_3);
        frame_62->setObjectName(QString::fromUtf8("frame_62"));
        frame_62->setMinimumSize(QSize(0, 10));
        frame_62->setMaximumSize(QSize(16777215, 40));
        frame_62->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_62->setFrameShape(QFrame::NoFrame);
        frame_62->setFrameShadow(QFrame::Plain);

        massTotalMemoryContainer->addWidget(frame_62, 1, 0, 1, 2);


        verticalLayout_64->addLayout(massTotalMemoryContainer);

        massfileFormatContainer = new QGridLayout();
        massfileFormatContainer->setObjectName(QString::fromUtf8("massfileFormatContainer"));
        massfileFormatContainer->setContentsMargins(15, -1, -1, -1);
        label_147 = new QLabel(fansPageContainer_3);
        label_147->setObjectName(QString::fromUtf8("label_147"));
        label_147->setFont(font8);
        label_147->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        massfileFormatContainer->addWidget(label_147, 0, 0, 1, 1);

        massfileFormat = new QLabel(fansPageContainer_3);
        massfileFormat->setObjectName(QString::fromUtf8("massfileFormat"));
        massfileFormat->setFont(font2);
        massfileFormat->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                        "background-color:none;"));
        massfileFormat->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        massfileFormat->setMargin(10);

        massfileFormatContainer->addWidget(massfileFormat, 0, 1, 1, 1);

        frame_61 = new QFrame(fansPageContainer_3);
        frame_61->setObjectName(QString::fromUtf8("frame_61"));
        frame_61->setMinimumSize(QSize(0, 10));
        frame_61->setMaximumSize(QSize(16777215, 40));
        frame_61->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_61->setFrameShape(QFrame::NoFrame);
        frame_61->setFrameShadow(QFrame::Plain);

        massfileFormatContainer->addWidget(frame_61, 1, 0, 1, 2);


        verticalLayout_64->addLayout(massfileFormatContainer);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_64->addItem(verticalSpacer_3);

        verticalLayout_81 = new QVBoxLayout();
        verticalLayout_81->setObjectName(QString::fromUtf8("verticalLayout_81"));
        verticalLayout_72 = new QVBoxLayout();
        verticalLayout_72->setObjectName(QString::fromUtf8("verticalLayout_72"));
        label_119 = new QLabel(fansPageContainer_3);
        label_119->setObjectName(QString::fromUtf8("label_119"));
        sizePolicy8.setHeightForWidth(label_119->sizePolicy().hasHeightForWidth());
        label_119->setSizePolicy(sizePolicy8);
        label_119->setFont(font1);
        label_119->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 32pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));
        label_119->setWordWrap(true);

        verticalLayout_72->addWidget(label_119);

        frame_56 = new QFrame(fansPageContainer_3);
        frame_56->setObjectName(QString::fromUtf8("frame_56"));
        sizePolicy6.setHeightForWidth(frame_56->sizePolicy().hasHeightForWidth());
        frame_56->setSizePolicy(sizePolicy6);
        frame_56->setMinimumSize(QSize(100, 10));
        frame_56->setMaximumSize(QSize(16777215, 40));
        frame_56->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_56->setFrameShape(QFrame::NoFrame);
        frame_56->setFrameShadow(QFrame::Plain);

        verticalLayout_72->addWidget(frame_56);


        verticalLayout_81->addLayout(verticalLayout_72);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(15, -1, -1, -1);
        label_120 = new QLabel(fansPageContainer_3);
        label_120->setObjectName(QString::fromUtf8("label_120"));
        label_120->setFont(font8);
        label_120->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        gridLayout_13->addWidget(label_120, 0, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_15, 0, 1, 1, 1);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        batteryCellVoltageContainer_1 = new QVBoxLayout();
        batteryCellVoltageContainer_1->setObjectName(QString::fromUtf8("batteryCellVoltageContainer_1"));
        label_122 = new QLabel(fansPageContainer_3);
        label_122->setObjectName(QString::fromUtf8("label_122"));
        sizePolicy8.setHeightForWidth(label_122->sizePolicy().hasHeightForWidth());
        label_122->setSizePolicy(sizePolicy8);
        label_122->setFont(font4);
        label_122->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 20pt \"Helvetica Neue\";\n "
                                                   "\n "
                                                   "letter-spacing: 2px;\n "
                                                   " margin-bottom:10px;"));
        label_122->setAlignment(Qt::AlignCenter);
        label_122->setWordWrap(true);

        batteryCellVoltageContainer_1->addWidget(label_122);

        batteryCellVoltage_1 = new QLabel(fansPageContainer_3);
        batteryCellVoltage_1->setObjectName(QString::fromUtf8("batteryCellVoltage_1"));
        sizePolicy8.setHeightForWidth(batteryCellVoltage_1->sizePolicy().hasHeightForWidth());
        batteryCellVoltage_1->setSizePolicy(sizePolicy8);
        batteryCellVoltage_1->setFont(font6);
        batteryCellVoltage_1->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                              "background-color:none;\n "
                                                              "border:none;\n "
                                                              "margin-left: 10px;"));
        batteryCellVoltage_1->setAlignment(Qt::AlignCenter);
        batteryCellVoltage_1->setWordWrap(true);

        batteryCellVoltageContainer_1->addWidget(batteryCellVoltage_1);


        horizontalLayout_32->addLayout(batteryCellVoltageContainer_1);

        batteryCellCapacityContainer_1 = new QVBoxLayout();
        batteryCellCapacityContainer_1->setObjectName(QString::fromUtf8("batteryCellCapacityContainer_1"));
        label_124 = new QLabel(fansPageContainer_3);
        label_124->setObjectName(QString::fromUtf8("label_124"));
        sizePolicy8.setHeightForWidth(label_124->sizePolicy().hasHeightForWidth());
        label_124->setSizePolicy(sizePolicy8);
        label_124->setFont(font4);
        label_124->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 20pt \"Helvetica Neue\";\n "
                                                   "\n "
                                                   "letter-spacing: 2px;\n "
                                                   " margin-bottom:10px;"));
        label_124->setAlignment(Qt::AlignCenter);
        label_124->setWordWrap(true);

        batteryCellCapacityContainer_1->addWidget(label_124);

        batteryCellCapacity_1 = new QLabel(fansPageContainer_3);
        batteryCellCapacity_1->setObjectName(QString::fromUtf8("batteryCellCapacity_1"));
        sizePolicy8.setHeightForWidth(batteryCellCapacity_1->sizePolicy().hasHeightForWidth());
        batteryCellCapacity_1->setSizePolicy(sizePolicy8);
        batteryCellCapacity_1->setFont(font6);
        batteryCellCapacity_1->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                               "background-color:none;\n "
                                                               "border:none;\n "
                                                               "margin-left: 10px;"));
        batteryCellCapacity_1->setAlignment(Qt::AlignCenter);
        batteryCellCapacity_1->setWordWrap(true);

        batteryCellCapacityContainer_1->addWidget(batteryCellCapacity_1);


        horizontalLayout_32->addLayout(batteryCellCapacityContainer_1);


        gridLayout_13->addLayout(horizontalLayout_32, 0, 2, 1, 1);

        frame_57 = new QFrame(fansPageContainer_3);
        frame_57->setObjectName(QString::fromUtf8("frame_57"));
        frame_57->setMinimumSize(QSize(0, 10));
        frame_57->setMaximumSize(QSize(16777215, 40));
        frame_57->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_57->setFrameShape(QFrame::NoFrame);
        frame_57->setFrameShadow(QFrame::Plain);

        gridLayout_13->addWidget(frame_57, 1, 0, 1, 3);


        verticalLayout_81->addLayout(gridLayout_13);

        gridLayout_25 = new QGridLayout();
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        gridLayout_25->setContentsMargins(15, -1, -1, -1);
        label_121 = new QLabel(fansPageContainer_3);
        label_121->setObjectName(QString::fromUtf8("label_121"));
        label_121->setFont(font8);
        label_121->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        gridLayout_25->addWidget(label_121, 0, 0, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_25->addItem(horizontalSpacer_16, 0, 1, 1, 1);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        batteryCellVoltageContainer_2 = new QVBoxLayout();
        batteryCellVoltageContainer_2->setObjectName(QString::fromUtf8("batteryCellVoltageContainer_2"));
        label_133 = new QLabel(fansPageContainer_3);
        label_133->setObjectName(QString::fromUtf8("label_133"));
        sizePolicy8.setHeightForWidth(label_133->sizePolicy().hasHeightForWidth());
        label_133->setSizePolicy(sizePolicy8);
        label_133->setFont(font4);
        label_133->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 20pt \"Helvetica Neue\";\n "
                                                   "\n "
                                                   "letter-spacing: 2px;\n "
                                                   " margin-bottom:10px;"));
        label_133->setAlignment(Qt::AlignCenter);
        label_133->setWordWrap(true);

        batteryCellVoltageContainer_2->addWidget(label_133);

        batteryCellVoltage_2 = new QLabel(fansPageContainer_3);
        batteryCellVoltage_2->setObjectName(QString::fromUtf8("batteryCellVoltage_2"));
        sizePolicy8.setHeightForWidth(batteryCellVoltage_2->sizePolicy().hasHeightForWidth());
        batteryCellVoltage_2->setSizePolicy(sizePolicy8);
        batteryCellVoltage_2->setFont(font6);
        batteryCellVoltage_2->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                              "background-color:none;\n "
                                                              "border:none;\n "
                                                              "margin-left: 10px;"));
        batteryCellVoltage_2->setAlignment(Qt::AlignCenter);
        batteryCellVoltage_2->setWordWrap(true);

        batteryCellVoltageContainer_2->addWidget(batteryCellVoltage_2);


        horizontalLayout_40->addLayout(batteryCellVoltageContainer_2);

        batteryCellCapacityContainer_2 = new QVBoxLayout();
        batteryCellCapacityContainer_2->setObjectName(QString::fromUtf8("batteryCellCapacityContainer_2"));
        label_135 = new QLabel(fansPageContainer_3);
        label_135->setObjectName(QString::fromUtf8("label_135"));
        sizePolicy8.setHeightForWidth(label_135->sizePolicy().hasHeightForWidth());
        label_135->setSizePolicy(sizePolicy8);
        label_135->setFont(font4);
        label_135->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 20pt \"Helvetica Neue\";\n "
                                                   "\n "
                                                   "letter-spacing: 2px;\n "
                                                   " margin-bottom:10px;"));
        label_135->setAlignment(Qt::AlignCenter);
        label_135->setWordWrap(true);

        batteryCellCapacityContainer_2->addWidget(label_135);

        batteryCellCapacity_2 = new QLabel(fansPageContainer_3);
        batteryCellCapacity_2->setObjectName(QString::fromUtf8("batteryCellCapacity_2"));
        sizePolicy8.setHeightForWidth(batteryCellCapacity_2->sizePolicy().hasHeightForWidth());
        batteryCellCapacity_2->setSizePolicy(sizePolicy8);
        batteryCellCapacity_2->setFont(font6);
        batteryCellCapacity_2->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                               "background-color:none;\n "
                                                               "border:none;\n "
                                                               "margin-left: 10px;"));
        batteryCellCapacity_2->setAlignment(Qt::AlignCenter);
        batteryCellCapacity_2->setWordWrap(true);

        batteryCellCapacityContainer_2->addWidget(batteryCellCapacity_2);


        horizontalLayout_40->addLayout(batteryCellCapacityContainer_2);


        gridLayout_25->addLayout(horizontalLayout_40, 0, 2, 1, 1);

        frame_58 = new QFrame(fansPageContainer_3);
        frame_58->setObjectName(QString::fromUtf8("frame_58"));
        frame_58->setMinimumSize(QSize(0, 10));
        frame_58->setMaximumSize(QSize(16777215, 40));
        frame_58->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_58->setFrameShape(QFrame::NoFrame);
        frame_58->setFrameShadow(QFrame::Plain);

        gridLayout_25->addWidget(frame_58, 1, 0, 1, 3);


        verticalLayout_81->addLayout(gridLayout_25);

        gridLayout_26 = new QGridLayout();
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_26->setContentsMargins(15, -1, -1, -1);
        label_137 = new QLabel(fansPageContainer_3);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        label_137->setFont(font8);
        label_137->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 22pt \"Helvetica Neue\"; letter-spacing: 3px;\n "
                                                   "background:none;"));

        gridLayout_26->addWidget(label_137, 0, 0, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_26->addItem(horizontalSpacer_17, 0, 1, 1, 1);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        batteryCellVoltageContainer_3 = new QVBoxLayout();
        batteryCellVoltageContainer_3->setObjectName(QString::fromUtf8("batteryCellVoltageContainer_3"));
        label_138 = new QLabel(fansPageContainer_3);
        label_138->setObjectName(QString::fromUtf8("label_138"));
        sizePolicy8.setHeightForWidth(label_138->sizePolicy().hasHeightForWidth());
        label_138->setSizePolicy(sizePolicy8);
        label_138->setFont(font4);
        label_138->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 20pt \"Helvetica Neue\";\n "
                                                   "\n "
                                                   "letter-spacing: 2px;\n "
                                                   " margin-bottom:10px;"));
        label_138->setAlignment(Qt::AlignCenter);
        label_138->setWordWrap(true);

        batteryCellVoltageContainer_3->addWidget(label_138);

        batteryCellVoltage_3 = new QLabel(fansPageContainer_3);
        batteryCellVoltage_3->setObjectName(QString::fromUtf8("batteryCellVoltage_3"));
        sizePolicy8.setHeightForWidth(batteryCellVoltage_3->sizePolicy().hasHeightForWidth());
        batteryCellVoltage_3->setSizePolicy(sizePolicy8);
        batteryCellVoltage_3->setFont(font6);
        batteryCellVoltage_3->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                              "background-color:none;\n "
                                                              "border:none;\n "
                                                              "margin-left: 10px;"));
        batteryCellVoltage_3->setAlignment(Qt::AlignCenter);
        batteryCellVoltage_3->setWordWrap(true);

        batteryCellVoltageContainer_3->addWidget(batteryCellVoltage_3);


        horizontalLayout_41->addLayout(batteryCellVoltageContainer_3);

        batteryCellCapacityContainer_3 = new QVBoxLayout();
        batteryCellCapacityContainer_3->setObjectName(QString::fromUtf8("batteryCellCapacityContainer_3"));
        label_140 = new QLabel(fansPageContainer_3);
        label_140->setObjectName(QString::fromUtf8("label_140"));
        sizePolicy8.setHeightForWidth(label_140->sizePolicy().hasHeightForWidth());
        label_140->setSizePolicy(sizePolicy8);
        label_140->setFont(font4);
        label_140->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 20pt \"Helvetica Neue\";\n "
                                                   "\n "
                                                   "letter-spacing: 2px;\n "
                                                   " margin-bottom:10px;"));
        label_140->setAlignment(Qt::AlignCenter);
        label_140->setWordWrap(true);

        batteryCellCapacityContainer_3->addWidget(label_140);

        batteryCellCapacity_3 = new QLabel(fansPageContainer_3);
        batteryCellCapacity_3->setObjectName(QString::fromUtf8("batteryCellCapacity_3"));
        sizePolicy8.setHeightForWidth(batteryCellCapacity_3->sizePolicy().hasHeightForWidth());
        batteryCellCapacity_3->setSizePolicy(sizePolicy8);
        batteryCellCapacity_3->setFont(font6);
        batteryCellCapacity_3->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                               "background-color:none;\n "
                                                               "border:none;\n "
                                                               "margin-left: 10px;"));
        batteryCellCapacity_3->setAlignment(Qt::AlignCenter);
        batteryCellCapacity_3->setWordWrap(true);

        batteryCellCapacityContainer_3->addWidget(batteryCellCapacity_3);


        horizontalLayout_41->addLayout(batteryCellCapacityContainer_3);


        gridLayout_26->addLayout(horizontalLayout_41, 0, 2, 1, 1);

        frame_59 = new QFrame(fansPageContainer_3);
        frame_59->setObjectName(QString::fromUtf8("frame_59"));
        frame_59->setMinimumSize(QSize(0, 10));
        frame_59->setMaximumSize(QSize(16777215, 40));
        frame_59->setStyleSheet(QString::fromUtf8("border-top: 1px solid #747290; "));
        frame_59->setFrameShape(QFrame::NoFrame);
        frame_59->setFrameShadow(QFrame::Plain);

        gridLayout_26->addWidget(frame_59, 1, 0, 1, 3);


        verticalLayout_81->addLayout(gridLayout_26);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        horizontalSpacer_18 = new QSpacerItem(478, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_43->addItem(horizontalSpacer_18);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        batteryCycleCountContainer = new QVBoxLayout();
        batteryCycleCountContainer->setObjectName(QString::fromUtf8("batteryCycleCountContainer"));
        label_143 = new QLabel(fansPageContainer_3);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        sizePolicy8.setHeightForWidth(label_143->sizePolicy().hasHeightForWidth());
        label_143->setSizePolicy(sizePolicy8);
        label_143->setFont(font4);
        label_143->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 20pt \"Helvetica Neue\";\n "
                                                   "\n "
                                                   "letter-spacing: 2px;\n "
                                                   " margin-bottom:10px;"));
        label_143->setAlignment(Qt::AlignCenter);
        label_143->setWordWrap(true);

        batteryCycleCountContainer->addWidget(label_143);

        batteryCycleCount = new QLabel(fansPageContainer_3);
        batteryCycleCount->setObjectName(QString::fromUtf8("batteryCycleCount"));
        sizePolicy8.setHeightForWidth(batteryCycleCount->sizePolicy().hasHeightForWidth());
        batteryCycleCount->setSizePolicy(sizePolicy8);
        batteryCycleCount->setFont(font6);
        batteryCycleCount->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                           "background-color:none;\n "
                                                           "border:none;\n "
                                                           "margin-left: 10px;"));
        batteryCycleCount->setAlignment(Qt::AlignCenter);
        batteryCycleCount->setWordWrap(true);

        batteryCycleCountContainer->addWidget(batteryCycleCount);


        horizontalLayout_42->addLayout(batteryCycleCountContainer);

        batteryAmperageContainer = new QVBoxLayout();
        batteryAmperageContainer->setObjectName(QString::fromUtf8("batteryAmperageContainer"));
        label_145 = new QLabel(fansPageContainer_3);
        label_145->setObjectName(QString::fromUtf8("label_145"));
        sizePolicy8.setHeightForWidth(label_145->sizePolicy().hasHeightForWidth());
        label_145->setSizePolicy(sizePolicy8);
        label_145->setFont(font4);
        label_145->setStyleSheet(QString::fromUtf8("\n "
                                                   "font: 25 20pt \"Helvetica Neue\";\n "
                                                   "\n "
                                                   "letter-spacing: 2px;\n "
                                                   " margin-bottom:10px;"));
        label_145->setAlignment(Qt::AlignCenter);
        label_145->setWordWrap(true);

        batteryAmperageContainer->addWidget(label_145);

        batteryAmperage = new QLabel(fansPageContainer_3);
        batteryAmperage->setObjectName(QString::fromUtf8("batteryAmperage"));
        sizePolicy8.setHeightForWidth(batteryAmperage->sizePolicy().hasHeightForWidth());
        batteryAmperage->setSizePolicy(sizePolicy8);
        batteryAmperage->setFont(font6);
        batteryAmperage->setStyleSheet(QString::fromUtf8("letter-spacing: 1px;\n "
                                                         "background-color:none;\n "
                                                         "border:none;\n "
                                                         "margin-left: 10px;"));
        batteryAmperage->setAlignment(Qt::AlignCenter);
        batteryAmperage->setWordWrap(true);

        batteryAmperageContainer->addWidget(batteryAmperage);


        horizontalLayout_42->addLayout(batteryAmperageContainer);


        horizontalLayout_43->addLayout(horizontalLayout_42);


        verticalLayout_81->addLayout(horizontalLayout_43);


        verticalLayout_64->addLayout(verticalLayout_81);


        verticalLayout_83->addWidget(fansPageContainer_3);

        stackedWidget->addWidget(hardwarePage);
        statisticsPage = new QWidget();
        statisticsPage->setObjectName(QString::fromUtf8("statisticsPage"));
        verticalLayout_66 = new QVBoxLayout(statisticsPage);
        verticalLayout_66->setObjectName(QString::fromUtf8("verticalLayout_66"));
        fansPageContainer_4 = new QFrame(statisticsPage);
        fansPageContainer_4->setObjectName(QString::fromUtf8("fansPageContainer_4"));
        sizePolicy1.setHeightForWidth(fansPageContainer_4->sizePolicy().hasHeightForWidth());
        fansPageContainer_4->setSizePolicy(sizePolicy1);
        fansPageContainer_4->setFrameShape(QFrame::NoFrame);
        fansPageContainer_4->setFrameShadow(QFrame::Sunken);
        verticalLayout_61 = new QVBoxLayout(fansPageContainer_4);
        verticalLayout_61->setObjectName(QString::fromUtf8("verticalLayout_61"));
        frame_37 = new QFrame(fansPageContainer_4);
        frame_37->setObjectName(QString::fromUtf8("frame_37"));
        frame_37->setAutoFillBackground(false);
        frame_37->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n "
                                                  "background: #1a162e;"));
        frame_37->setFrameShape(QFrame::StyledPanel);
        frame_37->setFrameShadow(QFrame::Raised);
        verticalLayout_62 = new QVBoxLayout(frame_37);
        verticalLayout_62->setObjectName(QString::fromUtf8("verticalLayout_62"));
        verticalLayout_62->setContentsMargins(25, 40, 25, 0);
        statsTableWidget = new QTableWidget(frame_37);
        if (statsTableWidget->columnCount() < 1)
            statsTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (statsTableWidget->rowCount() < 21)
            statsTableWidget->setRowCount(21);
        QFont font10;
        font10.setBold(true);
        font10.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font10);
        statsTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        statsTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem10->setFont(font10);
        statsTableWidget->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem17->setFont(font10);
        statsTableWidget->setVerticalHeaderItem(16, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(17, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(18, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(19, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        statsTableWidget->setVerticalHeaderItem(20, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(1, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(2, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(3, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(4, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(5, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(6, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(7, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(8, 0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(10, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(11, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(12, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(13, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(14, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(15, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(17, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(18, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(19, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignCenter);
        statsTableWidget->setItem(20, 0, __qtablewidgetitem39);
        statsTableWidget->setObjectName(QString::fromUtf8("statsTableWidget"));
        QFont font11;
        font11.setFamily(QString::fromUtf8("Helvetica Neue"));
        font11.setPointSize(20);
        font11.setBold(false);
        font11.setItalic(false);
        font11.setWeight(3);
        font11.setStyleStrategy(QFont::PreferDefault);
        statsTableWidget->setFont(font11);
        statsTableWidget->setFocusPolicy(Qt::NoFocus);
        statsTableWidget->setLayoutDirection(Qt::LeftToRight);
        statsTableWidget->setAutoFillBackground(false);
        statsTableWidget->setStyleSheet(QString::fromUtf8("font: 25 20pt \"Helvetica Neue\";\n "
                                                          "color: lightgray;\n "
                                                          "letter-spacing: 3px;\n "
                                                          "margin-bottom:10px;\n "
                                                          "alternate-background-color: none;\n "
                                                          "selection-color: #f82f5f;\n "
                                                          "selection-background-color:  #1a162e;\n "
                                                          "background-color: #1a162e;\n "
                                                          "border-radius: 5px;\n "
                                                          ""));
        statsTableWidget->setFrameShape(QFrame::NoFrame);
        statsTableWidget->setFrameShadow(QFrame::Plain);
        statsTableWidget->setLineWidth(0);
        statsTableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        statsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        statsTableWidget->setTabKeyNavigation(true);
        statsTableWidget->setProperty("showDropIndicator", QVariant(true));
        statsTableWidget->setDragDropOverwriteMode(false);
        statsTableWidget->setAlternatingRowColors(true);
        statsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        statsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        statsTableWidget->setTextElideMode(Qt::ElideMiddle);
        statsTableWidget->setShowGrid(false);
        statsTableWidget->setGridStyle(Qt::NoPen);
        statsTableWidget->setSortingEnabled(false);
        statsTableWidget->setWordWrap(false);
        statsTableWidget->setCornerButtonEnabled(false);
        statsTableWidget->setRowCount(21);
        statsTableWidget->setColumnCount(1);
        statsTableWidget->horizontalHeader()->setVisible(false);
        statsTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        statsTableWidget->horizontalHeader()->setMinimumSectionSize(50);
        statsTableWidget->horizontalHeader()->setDefaultSectionSize(300);
        statsTableWidget->horizontalHeader()->setHighlightSections(true);
        statsTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        statsTableWidget->horizontalHeader()->setStretchLastSection(true);
        statsTableWidget->verticalHeader()->setVisible(false);
        statsTableWidget->verticalHeader()->setCascadingSectionResizes(false);
        statsTableWidget->verticalHeader()->setMinimumSectionSize(35);
        statsTableWidget->verticalHeader()->setDefaultSectionSize(35);
        statsTableWidget->verticalHeader()->setHighlightSections(false);
        statsTableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        statsTableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_62->addWidget(statsTableWidget);


        verticalLayout_61->addWidget(frame_37);


        verticalLayout_66->addWidget(fansPageContainer_4);

        stackedWidget->addWidget(statisticsPage);

        verticalLayout_9->addWidget(stackedWidget);


        horizontalLayout->addWidget(contentContainer);


        verticalLayout->addLayout(horizontalLayout);

        kStatsView->setCentralWidget(centralwidget);
        stackedWidget->setCurrentIndex(0);

        retranslateUi(kStatsView);

        graphicsLeftButton->setDefault(false);
        graphicsRightButton->setDefault(false);
        graphicsLeftButton_2->setDefault(false);
        graphicsRightButton_2->setDefault(false);


        QMetaObject::connectSlotsByName(kStatsView);
    } // setupUi

    void retranslateUi(QMainWindow *kStatsView)
    {
        kStatsView->setWindowTitle(QCoreApplication::translate("kStatsView", "kStatsView", nullptr));
        label_11->setText(QString());
        homeButton->setText(QCoreApplication::translate("kStatsView", "   Home", nullptr));
        cpuButton->setText(QCoreApplication::translate("kStatsView", "   CPU", nullptr));
        fansButton->setText(QCoreApplication::translate("kStatsView", "   Fans", nullptr));
        networkButton->setText(QCoreApplication::translate("kStatsView", "   Network", nullptr));
        hardwareButton->setText(QCoreApplication::translate("kStatsView", "   Hardware", nullptr));
        statisticsButton->setText(QCoreApplication::translate("kStatsView", "   Statistics", nullptr));
        label_41->setText(QString());
        label_24->setText(QCoreApplication::translate("kStatsView", "Device ", nullptr));
        deviceName->setText(QCoreApplication::translate("kStatsView", "Unknown", nullptr));
        label_40->setText(QString());
        label_31->setText(QCoreApplication::translate("kStatsView", "Current OS", nullptr));
        osVersion->setText(QCoreApplication::translate("kStatsView", "Unknown", nullptr));
        ramSize->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        label_60->setText(QCoreApplication::translate("kStatsView", "Mass", nullptr));
        label_28->setText(QCoreApplication::translate("kStatsView", "Memory", nullptr));
        totalMassMemoryCount->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_43->setText(QString());
        label_62->setText(QCoreApplication::translate("kStatsView", "Random Access", nullptr));
        label_29->setText(QString());
        label_51->setText(QString());
        label_39->setText(QCoreApplication::translate("kStatsView", "Processor", nullptr));
        processorModel->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        label_44->setText(QString());
        label_33->setText(QCoreApplication::translate("kStatsView", "IP Address", nullptr));
        ipAddress->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        label_37->setText(QCoreApplication::translate("kStatsView", "Graphics", nullptr));
        graphicsLeftButton->setText(QString());
        graphicsRightButton->setText(QString());
        graphicsIcon_1->setText(QString());
        graphicsModel_1->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        graphicsIcon_2->setText(QString());
        graphicsModel_2->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        label_47->setText(QCoreApplication::translate("kStatsView", "Peripherals", nullptr));
//        graphicsLeftButton_2->setText(QString());
//        graphicsRightButton_2->setText(QString());
        peripheralIcon_1->setText(QString());
        peripheralName_1->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        peripheralIcon_2->setText(QString());
        peripheralName_2->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        peripheralIcon_3->setText(QString());
        peripheralName_3->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        peripheralIcon_4->setText(QString());
        peripheralName_4->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        cpuAverageTemperature->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_84->setText(QCoreApplication::translate("kStatsView", "Temperature", nullptr));
        cpuUsage->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_85->setText(QCoreApplication::translate("kStatsView", "Usage", nullptr));
        label_76->setText(QCoreApplication::translate("kStatsView", "Cache", nullptr));
        cpuCache->setText(QCoreApplication::translate("kStatsView", "12 MB", nullptr));
        label_70->setText(QCoreApplication::translate("kStatsView", "Clock min", nullptr));
        label_72->setText(QCoreApplication::translate("kStatsView", "2.60 Ghz", nullptr));
        label_80->setText(QCoreApplication::translate("kStatsView", "Threads", nullptr));
        cpuThreads->setText(QCoreApplication::translate("kStatsView", "12", nullptr));
        label_83->setText(QCoreApplication::translate("kStatsView", "Cores", nullptr));
        cpuCores->setText(QCoreApplication::translate("kStatsView", "6", nullptr));
        label_74->setText(QCoreApplication::translate("kStatsView", "Clock max", nullptr));
        cpuClockMax->setText(QCoreApplication::translate("kStatsView", "4.50 Ghz", nullptr));
        label_71->setText(QCoreApplication::translate("kStatsView", "Architecture", nullptr));
        cpuArchitecture->setText(QCoreApplication::translate("kStatsView", "x86_64", nullptr));
        label_78->setText(QString());
        cpuModelName->setText(QCoreApplication::translate("kStatsView", "<strong>Intel</strong> Core i7-9750H", nullptr));
        cpuTemperatureCore_1->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_90->setText(QCoreApplication::translate("kStatsView", "Core 1", nullptr));
        cpuTemperatureCore_2->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_89->setText(QCoreApplication::translate("kStatsView", "Core 2", nullptr));
        cpuTemperatureCore_3->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_91->setText(QCoreApplication::translate("kStatsView", "Core 3", nullptr));
        cpuTemperatureCore_4->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_93->setText(QCoreApplication::translate("kStatsView", "Core 4", nullptr));
        cpuTemperatureCore_5->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_94->setText(QCoreApplication::translate("kStatsView", "Core 5", nullptr));
        cpuTemperatureCore_6->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_95->setText(QCoreApplication::translate("kStatsView", "Core 6", nullptr));
        cpuTemperaturePeci->setText(QCoreApplication::translate("kStatsView", "35\302\260C", nullptr));
        label_92->setText(QCoreApplication::translate("kStatsView", "PECI", nullptr));
        label_13->setText(QString());
        label_86->setText(QCoreApplication::translate("kStatsView", "Max. speed", nullptr));
        fanLeftMaximumSpeed->setText(QCoreApplication::translate("kStatsView", "5927 RPM", nullptr));
        label_77->setText(QCoreApplication::translate("kStatsView", "Min. speed", nullptr));
        fanLeftMinimumSpeed->setText(QCoreApplication::translate("kStatsView", "2160 RPM", nullptr));
        label_38->setText(QCoreApplication::translate("kStatsView", "Fan left", nullptr));
        fanLeftCurrentSpeed->setText(QCoreApplication::translate("kStatsView", "3753 RPM", nullptr));
        label_87->setText(QCoreApplication::translate("kStatsView", "Current speed", nullptr));
        fanLeftChangeSpeedButton->setText(QCoreApplication::translate("kStatsView", "Change speed", nullptr));
        fanLeftSetAutoSpeedButton->setText(QCoreApplication::translate("kStatsView", "Set Auto Speed", nullptr));
        fanLeftSetMaxSpeedButton->setText(QCoreApplication::translate("kStatsView", "Set maximum speed", nullptr));
        label_14->setText(QString());
        label_65->setText(QCoreApplication::translate("kStatsView", "Fan Right", nullptr));
        label_96->setText(QCoreApplication::translate("kStatsView", "Max. speed", nullptr));
        fanRightMinimumSpeed->setText(QCoreApplication::translate("kStatsView", "2160 RPM", nullptr));
        label_98->setText(QCoreApplication::translate("kStatsView", "Current speed", nullptr));
        fanRightCurrentSpeed->setText(QCoreApplication::translate("kStatsView", "3753 RPM", nullptr));
        fanRightMaximumSpeed->setText(QCoreApplication::translate("kStatsView", "5927 RPM", nullptr));
        label_97->setText(QCoreApplication::translate("kStatsView", "Min. speed", nullptr));
        fanRightChangeSpeedButton->setText(QCoreApplication::translate("kStatsView", "Change speed", nullptr));
        fanRightSetAutoSpeedButton->setText(QCoreApplication::translate("kStatsView", "Set Auto Speed", nullptr));
        fanRightSetMaxSpeedButton->setText(QCoreApplication::translate("kStatsView", "Set maximum speed", nullptr));
        label_99->setText(QCoreApplication::translate("kStatsView", "Network", nullptr));
        networkIcon->setText(QString());
//        ssidName->setText(QCoreApplication::translate("kStatsView", "TP_LINK_BK", nullptr));
        label_69->setText(QCoreApplication::translate("kStatsView", "IPv4 Address", nullptr));
//        ipv4Address->setText(QCoreApplication::translate("kStatsView", "172.20.10.2", nullptr));
        label_101->setText(QCoreApplication::translate("kStatsView", "IPv6 Address", nullptr));
//        ipv6Address->setText(QCoreApplication::translate("kStatsView", "TP_LINK_BK", nullptr));
        label_104->setText(QCoreApplication::translate("kStatsView", "MAC Address", nullptr));
//        macAddress->setText(QCoreApplication::translate("kStatsView", "TP_LINK_BK", nullptr));
        label_106->setText(QCoreApplication::translate("kStatsView", "Connection speed", nullptr));
        testConnectionSpeedButton->setText(QCoreApplication::translate("kStatsView", "Test Connection", nullptr));
//        downloadSpeed->setText(QCoreApplication::translate("kStatsView", "102 MB/s", nullptr));
        chart_percentage_20->setText(QCoreApplication::translate("kStatsView", "<strong>Download</strong>\n "
                                                                               "\n "
                                                                               "", nullptr));
//        uploadSpeed->setText(QCoreApplication::translate("kStatsView", "102 MB/s", nullptr));
        chart_percentage_23->setText(QCoreApplication::translate("kStatsView", "<strong>Upload< /strong>\n "
                                                                               "\n "
                                                                               "", nullptr));
        label_107->setText(QCoreApplication::translate("kStatsView", "Server", nullptr));
        networkServer->setText(QCoreApplication::translate("kStatsView", "  ", nullptr));
        label_112->setText(QCoreApplication::translate("kStatsView", "Download speed", nullptr));
//        downloadSpeedTable->setText(QCoreApplication::translate("kStatsView", "43 Mb/s", nullptr));
        label_114->setText(QCoreApplication::translate("kStatsView", "Upload speed", nullptr));
//        uploadSpeedTable->setText(QCoreApplication::translate("kStatsView", "18 Mb/s", nullptr));
        label_116->setText(QCoreApplication::translate("kStatsView", "Ping", nullptr));
//        connectionPing->setText(QCoreApplication::translate("kStatsView", "43", nullptr));
        label_131->setText(QCoreApplication::translate("kStatsView", "Mass Memory", nullptr));
        massMemoryModel->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_129->setText(QCoreApplication::translate("kStatsView", "Available memory", nullptr));
        massAvailableMemory->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_149->setText(QCoreApplication::translate("kStatsView", "Total Memory", nullptr));
        massTotalMemory->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_147->setText(QCoreApplication::translate("kStatsView", "File Format", nullptr));
        massfileFormat->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_119->setText(QCoreApplication::translate("kStatsView", "Battery", nullptr));
        label_120->setText(QCoreApplication::translate("kStatsView", "Cell 1 ", nullptr));
        label_122->setText(QCoreApplication::translate("kStatsView", "Voltage", nullptr));
        batteryCellVoltage_1->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_124->setText(QCoreApplication::translate("kStatsView", "Capacity", nullptr));
        batteryCellCapacity_1->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_121->setText(QCoreApplication::translate("kStatsView", "Cell 2", nullptr));
        label_133->setText(QCoreApplication::translate("kStatsView", "Voltage", nullptr));
        batteryCellVoltage_2->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_135->setText(QCoreApplication::translate("kStatsView", "Capacity", nullptr));
        batteryCellCapacity_2->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_137->setText(QCoreApplication::translate("kStatsView", "Cell 3", nullptr));
        label_138->setText(QCoreApplication::translate("kStatsView", "Voltage", nullptr));
        batteryCellVoltage_3->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_140->setText(QCoreApplication::translate("kStatsView", "Capacity", nullptr));
        batteryCellCapacity_3->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_143->setText(QCoreApplication::translate("kStatsView", "Cycle count", nullptr));
        batteryCycleCount->setText(QCoreApplication::translate("kStatsView", " ", nullptr));
        label_145->setText(QCoreApplication::translate("kStatsView", "Total Amperage", nullptr));
        batteryAmperage->setText(QCoreApplication::translate("kStatsView", "0mA", nullptr));
        QTableWidgetItem *___qtablewidgetitem = statsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("kStatsView", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = statsTableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("kStatsView", "CPU", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = statsTableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("kStatsView", "CPU Average", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = statsTableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("kStatsView", "CPU PECI", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = statsTableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("kStatsView", "CPU Core 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = statsTableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("kStatsView", "CPU Core 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = statsTableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("kStatsView", "CPU Core 3", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = statsTableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("kStatsView", "CPU Core 4", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = statsTableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("kStatsView", "CPU Core 5", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = statsTableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("kStatsView", "CPU Core 6", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = statsTableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("kStatsView", "Battery", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = statsTableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("kStatsView", "Battery Cell 1 Voltage", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = statsTableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("kStatsView", "Battery Cell 2 Voltage", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = statsTableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("kStatsView", "Battery Cell 3 Voltage", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = statsTableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("kStatsView", "Battery Cell 1 Amperage", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = statsTableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("kStatsView", "Battery Cell 2 Amperage", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = statsTableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("kStatsView", "Battery Cell 3 Amperage", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = statsTableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("kStatsView", "GPU", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = statsTableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("kStatsView", "GPU Proximity", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = statsTableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("kStatsView", "GPU Heatsink", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = statsTableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("kStatsView", "GPU Intel ", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = statsTableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("kStatsView", "GPU Radeon", nullptr));

        const bool __sortingEnabled = statsTableWidget->isSortingEnabled();
        statsTableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem22 = statsTableWidget->item(1, 0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = statsTableWidget->item(2, 0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = statsTableWidget->item(3, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = statsTableWidget->item(4, 0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = statsTableWidget->item(5, 0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = statsTableWidget->item(6, 0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = statsTableWidget->item(7, 0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = statsTableWidget->item(8, 0);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = statsTableWidget->item(10, 0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = statsTableWidget->item(11, 0);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = statsTableWidget->item(12, 0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = statsTableWidget->item(13, 0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = statsTableWidget->item(14, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = statsTableWidget->item(15, 0);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = statsTableWidget->item(17, 0);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = statsTableWidget->item(18, 0);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = statsTableWidget->item(19, 0);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = statsTableWidget->item(20, 0);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("kStatsView", "", nullptr));
        statsTableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi
};

class kStatsView: public Ui_MainWindow {
public:
    kStatsView(QMainWindow * parent = nullptr);
private:
    QMainWindow *ui;
    void closeEvent(QCloseEvent *closeEvent);
};

QT_END_NAMESPACE


#endif //KSTATS_VIEW_H_KSTATS_VIEW_H
