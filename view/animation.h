#ifndef KSTATS_VIEW_H_ANIMATION_H
#define KSTATS_VIEW_H_ANIMATION_H
#include "qt_libraries.h"
#define MIN_TEMPERATURE 60
#define MAX_TEMPERATURE 80


constexpr QColor _blue(71,152,255);
constexpr QColor _orange(254, 148, 69);
constexpr QColor _red(248,47,95);

const auto blueStyleSheet = QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 ") + _blue.name() + QString(")};");
const auto orangeStyleSheet = QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 ") + _orange.name() + QString(")};");
const auto redStyleSheet = QString::fromUtf8("QFrame { \nborder-radius: 70px;\nbackground-color: qconicalgradient(cx:0.5 cy:0.5 angle:225, stop: 0.1 rgba(255, 255, 255, 0), stop:1 ") + _red.name() + QString(")};");

static class Animation {

public:
    static void circuralProgressAnimation(const std::array<QFrame *, 8> &charts, const std::array<float, 8> &temperatures) {
        QString styleSheet;
        for(int i = 0; i < charts.size(); i++)  {
            styleSheet = charts[i]->styleSheet();
            if(temperatures[i] <= MIN_TEMPERATURE) {
                if (!styleSheet.contains(_blue.name(), Qt::CaseInsensitive)) {
                    charts[i]->setStyleSheet(blueStyleSheet);
                }
            }
            else if(temperatures[i] > MIN_TEMPERATURE && temperatures[i] < MAX_TEMPERATURE) {
                if (!styleSheet.contains(_orange.name(), Qt::CaseInsensitive)) {
                    charts[i]->setStyleSheet(orangeStyleSheet);
                }
            } else
            if(!styleSheet.contains(_red.name(),Qt::CaseInsensitive)){
                charts[i]->setStyleSheet(redStyleSheet);
            }
        }
    }

    static void networkAnimation(QLabel* label, const QString& content) {
        using namespace std::chrono_literals;
        QString dot;
        while(content.isEmpty()) {
            dot="";

            for(int i = 0; i<3; i++) {
                dot+=".";
                if(content.isEmpty())
                    label->setText(dot);

                std::this_thread::sleep_for(500ms);
            }
        }
    }
};

#endif //KSTATS_VIEW_H_ANIMATION_H