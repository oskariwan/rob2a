#pragma config(Sensor, dgtl2,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)

//u = 540
const int BASEDIST = 540;

void drive(int dist,int backward_forward){
	while(abs(SensorValue[rightEncoder]) < dist)		// Creates an infinite loop, since "true" always evaluates to true
	{
		if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightMotor] = 80*backward_forward;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 80*backward_forward;		    // Left Motor is run at power level 80
		}
		else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightMotor] = 60*backward_forward;		    // Right Motor is run at power level 60
			motor[leftMotor]  = 80*backward_forward;		    // Left Motor is run at power level 80
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightMotor] = 80*backward_forward;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 60*backward_forward;		    // Left Motor is run at power level 60
		}
	}
}
void resetEncoder(){
	SensorValue[rightEncoder]=0;
	SensorValue[leftEncoder]=0;
}
task main()
{
resetEncoder();
for(int i = 1;i < 6;i++){

	drive(BASEDIST*i,1);
	resetEncoder();
	drive(BASEDIST*i,-1);
	resetEncoder();
}
}
