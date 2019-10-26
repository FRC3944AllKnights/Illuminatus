#include "WheelSpinnies.h"

WheelSpinnies::WheelSpinnies(){
}

void WheelSpinnies::init(){
    spinnymotorRight.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 30);
	spinnymotorRight.SetSensorPhase(false);

	spinnymotorRight.Config_kF(0, 0.1097, 30);
	spinnymotorRight.Config_kP(0, 0.22, 30);
	spinnymotorRight.Config_kI(0, 0.0, 30);
	spinnymotorRight.Config_kD(0, 0.0, 30);
    
    spinnymotorLeft.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 30);
	spinnymotorLeft.SetSensorPhase(false);

	spinnymotorLeft.Config_kF(0, 0.1097, 30);
	spinnymotorLeft.Config_kP(0, 0.22, 30);
	spinnymotorLeft.Config_kI(0, 0.0, 30);
	spinnymotorLeft.Config_kD(0, 0.0, 30);
}

void WheelSpinnies::spinrev(bool start, bool stop){
    if (start){
        spinnymotorRight.Set(ControlMode::Velocity, -5000.0 * 4096 / 600);
        spinnymotorLeft.Set(ControlMode::Velocity, 5000.0 * 4096 / 600); 
    }
    else if (stop){
        spinnymotorRight.Set(ControlMode::Velocity, 0);
        spinnymotorLeft.Set(ControlMode::Velocity, 0);
    }
    else{
        spinnymotorRight.Set(ControlMode::PercentOutput, 0);
        spinnymotorLeft.Set(ControlMode::PercentOutput, 0);
    }
}
    