#pragma config(Sensor, dgtl2,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//const int BASEDIST = 720;
void forward(){
	motor[rightMotor] = 127;
  motor[leftmotor] = 127;
  wait1Msec(1000);
}
void wait(){
	motor[rightMotor] = 0;
  motor[leftmotor] = 0;
  wait1Msec(500);
}
void endir(){
	motor[rightMotor] = 0;
  motor[leftmotor] = 0;
}
void turn(int deg,bool LorR){
	int ondeg = 3;
	int turning =(LorR) ? (-1):(1);
  SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  while (abs(SensorValue[rightEncoder])<ondeg*deg) // While the right encoder is less than distance:
  {
    motor[rightMotor] = 63*turning;
    motor[leftmotor] = -63*turning;/* Run both motors        */
             /* forward at half speed. */
  }

  motor[rightMotor] = 0;
  motor[leftmotor] = 0;
}

bool myarray[14] ={true,false,false,true,true,false,true,true,false,true,true,false,false,true};

task main()
{
	for(int i = 0;i < 13; i++){
	forward();
  turn(90,myarray[i]);
  wait();
}
	forward();
	endir();
}
