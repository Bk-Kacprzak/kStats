#ifndef KSTATS_VIEW_H_ANIMATION_H
#define KSTATS_VIEW_H_ANIMATION_H

#include "qt_libraries.h"

#define MIN_TEMPERATURE 60
#define MAX_TEMPERATURE 80

//constexpr std::array<double, 3> blue{71,152,255};
//constexpr std::array<double, 3> red{248,47,95};
//constexpr std::array<double, 3> incrementIndex{(red[0] - blue[0])/(MAX_TEMPERATURE-MIN_TEMPERATURE),
//                                             (red[1] - blue[1])/(MAX_TEMPERATURE-MIN_TEMPERATURE),
//                                             (red[2] - blue[2])/(MAX_TEMPERATURE-MIN_TEMPERATURE)};


constexpr QColor _blue(71,152,255);
constexpr QColor _orange(254, 148, 69);
constexpr QColor _red(248,47,95);

const auto blueStyleSheet = QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 ") + _blue.name() + QString(")};");
const auto orangeStyleSheet = QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 ") + _orange.name() + QString(")};");
const auto redStyleSheet = QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 ") + _red.name() + QString(")};");

static std::mutex animationMtx;

static class Animation {

public:
    static void circuralProgressAnimation(const std::array<QFrame *, 8> &charts, const std::array<float, 8> &temperatures) {
        QString styleSheet;
        for(int i = 0; i < charts.size(); i++)  {
            styleSheet = charts[i]->styleSheet();
            if(temperatures[i] <= MIN_TEMPERATURE) {
                if (!styleSheet.contains(_blue.name(), Qt::CaseInsensitive)) {
                    std::lock_guard<std::mutex> mtx(animationMtx);
                    charts[i]->setStyleSheet(blueStyleSheet);
                }
            }
            else if(temperatures[i] > MIN_TEMPERATURE && temperatures[i] < MAX_TEMPERATURE) {
                if (!styleSheet.contains(_orange.name(), Qt::CaseInsensitive)) {
                    std::lock_guard<std::mutex> mtx(animationMtx);
                    charts[i]->setStyleSheet(orangeStyleSheet);
                }
            } else
            if(!styleSheet.contains(_red.name(),Qt::CaseInsensitive)){
                charts[i]->setStyleSheet(redStyleSheet);
            }
        }
    }
};

#endif //KSTATS_VIEW_H_ANIMATION_H