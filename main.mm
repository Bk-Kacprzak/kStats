#include "model/Utils/utils.h"
#include "global.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    kStatsView ApplicationView;
    QApplication::exec();
    return 0;
}
