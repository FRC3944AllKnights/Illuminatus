#ifndef WHEELSPINNIES_H
#define WHEELSPINNIES_H

#include <ctre/Phoenix.h>

class WheelSpinnies{
    public:
        WheelSpinnies();
        void init();
        void spinrev(bool start, bool stop);
    
    private:
        WPI_TalonSRX spinnymotorLeft{14};
        WPI_TalonSRX spinnymotorRight{15};
};
#endif