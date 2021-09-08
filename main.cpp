#include <stdio.h>
#include <chrono>
#include <thread>
#include "controller/cpu_controller.h"
#include "controller/cpu_device.h"

int main(int argc, char* argv[])
{
   char scale = 'C';
   int cpu = 0;
   int fan = 0;
   int gpu = 0;

   int c;
   while ((c = getopt(argc, argv, "CFcfgh?")) != -1) {
       switch (c) {
           case 'F':
           case 'C':
               scale = c;
               break;
           case 'c':
               cpu = 1;
               break;
           case 'f':
               fan = 1;
               break;
           case 'g':
               gpu = 1;
               break;
           case 'h':
           case '?':
               printf("usage: osx-cpu-temp <options>\n");
               printf("Options:\n");
               printf("  -F  Display temperatures in degrees Fahrenheit.\n");
               printf("  -C  Display temperatures in degrees Celsius (Default).\n");
               printf("  -c  Display CPU temperature (Default).\n");
               printf("  -g  Display GPU temperature.\n");
               printf("  -f  Display fan speeds.\n");
               printf("  -h  Display this help.\n");
               printf("\nIf more than one of -c, -f, or -g are specified, titles will be added\n");
               return -1;
       }
   }

   if (!fan && !gpu) {
       cpu = 1;
   }
    cpu =2;
   int show_title = fan + gpu + cpu > 1;

   SMCOpen();
   if (cpu) {
       while(true) {
           using namespace std::chrono_literals;
           std::this_thread::sleep_for(2000ms);
//           getFanSpeed(kNet::Keys::fan::LEFT);
//           getFanSpeed(kNet::Keys::fan::RIGHT);
//
//           getCpuTemp(scale, 1);
//           getCpuTemp(scale, 2);
//           getCpuTemp(scale, 3);
//           getCpuTemp(scale, 4);
//           getCpuTemp(scale, 5);
//           getCpuTemp(scale, 6);
//           getCpuTemp(scale, 7,"Average");

//            SMCGetPower(kNet::Keys::cpu::power[0]);

           SMCGetPower("#KEY");
           SMCGetPower("PDTR");
           SMCGetPower("TM0S");
//           SMCGetPower("PC4R");
//           SMCGetPower("PC5R");
//           SMCGetPower("BC2V");
//           SMCGetPower("BC3V");

            char buffer[5];
            buffer[2]=  0x03;
            buffer[3] = 0x9e;

           std::cout<<"\n\n************************************************\n\n";
       }
   }
   if (gpu) {
       readAndPrintGpuTemp(show_title, scale);
   }
   if (fan) {
       readAndPrintFanRPMs();
   }

   SMCClose();
   return 0;
}
