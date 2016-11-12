
// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

#define LOOP_SPEED              25
#define MAX_POWER              127
#define MIN_POWER             -127
#define PID_SENSOR_INDEX    myEncoder
#define PID_SENSOR_SCALE    1

#define PID_MOTOR_INDEX     myMotor
#define PID_MOTOR_SCALE     -1

#define PID_INTEGRAL_LIMIT  50

float  pid_Kp = 2.0;
float  pid_Ki = 0.04;
float  pid_Kd = 0.0;

static int   pidRunning = 1;
static float pidRequestedValue;

// final motor drive
long            motor_driveR;            /// RIGHT
long            motor_driveL;            /// LEFT


/*///////////////////////////////////////////////////////////
/////                      __ ___  ____                 /////
/////                     / /|__ \|  _ \                /////
/////                    / /_   ) | |_) |               /////
/////                   | '_ \ / /|  _ <                /////
/////                   | (_) / /_| |_) |               /////
/////                    \___/____|____/                /////
///// Team 62K Robot                                    /////
///// Main Code                                         /////
///// Authors: Abner Benitez                            /////
///// Since: Nov. 10, 2016                              /////
*////////////////////////////////////////////////////////////

/*
To Do List
1. Try an empty main()
2. what does it mean to have greater resolution in sensors?
3. startTask( ); gotta use this within tasks
4. nMotorEncoder[ ]
*/

//setters

void
setMotorL( int valueL )
{

}


void
setMotorR( int valueR )
{

}

//action methods
void
move( int time, int left, int right )
{
	setMotorL( left );
	setMotorR( right );
	delay(time);

	setMotorR(0);
	setMotorL(0);
}

//overload this method
void
setArms( int time, int power )
{

	delay(time);


	delay(100);
}


//stops everything
void
stopAll()
{

}

//PID control task
task pidController()
{
	/*
	float  pidSensorCurrentValue;

	float  pidError;
	float  pidLastError;
	float  pidIntegral;
	float  pidDerivative;
	float  pidDrive;

	// If we are using an encoder then clear it
	if( SensorType[ PID_SENSOR_INDEX ] == sensorQuadEncoder )
	SensorValue[ PID_SENSOR_INDEX ] = 0;

	// Init the variables - thanks Glenn :)
	pidLastError  = 0;
	pidIntegral   = 0;

	while( true )
	{
	// Is PID control active ?
	if( pidRunning )
	{
	// Read the sensor value and scale
	pidSensorCurrentValue = SensorValue[ PID_SENSOR_INDEX ] * PID_SENSOR_SCALE;

	// calculate error
	pidError = pidSensorCurrentValue - pidRequestedValue;

	// integral - if Ki is not 0
	if( pid_Ki != 0 )
	{
	// If we are inside controlable window then integrate the error
	if( abs(pidError) < PID_INTEGRAL_LIMIT )
	pidIntegral = pidIntegral + pidError;
	else
	pidIntegral = 0;
	}
	else
	pidIntegral = 0;

	// calculate the derivative
	pidDerivative = pidError - pidLastError;
	pidLastError  = pidError;

	// calculate drive
	pidDrive = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);

	// limit drive
	if( pidDrive > PID_DRIVE_MAX )
	pidDrive = PID_DRIVE_MAX;
	if( pidDrive < PID_DRIVE_MIN )
	pidDrive = PID_DRIVE_MIN;

	// send to motor
	motor[ PID_MOTOR_INDEX ] = pidDrive * PID_MOTOR_SCALE;
	}
	else
	{
	// clear all
	pidError      = 0;
	pidLastError  = 0;
	pidIntegral   = 0;
	pidDerivative = 0;
	motor[ PID_MOTOR_INDEX ] = 0;
	}

	// Run at 50Hz
	wait1Msec( 25 );
	}
	*/
}


void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


//tasks
task autonomous()
{
	// Remove this function call once you have "real" code.
	AutonomousCodePlaceholderForTesting();
}


task usercontrol()
{
	while (true)
	{
		wait1Msec(20); //don't hog the CPU :)
	}
}
