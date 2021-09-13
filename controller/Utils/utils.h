#ifndef CPUSTATS_UTILS_H
#define CPUSTATS_UTILS_H

class Utils {
public:

};


//timing benchmark

struct Timer{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    Timer() {
        start = std::chrono::high_resolution_clock::now(); //gives us the current time.
    }
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout<<"Timer took: "<< ms <<"ms "<<std::endl;
    }
};

#endif //CPUSTATS_UTILS_H
