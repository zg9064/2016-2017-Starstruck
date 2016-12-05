#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    rightClawPot,   sensorPotentiometer)
#pragma config(Motor,  port1,           rightClaw,     tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           LDriveBase,    tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           RDriveBase,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           LFrontDriveBase, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           RFrontDriveBase, tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port6,           leftLift,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           leftClaw,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port8,           rightMidLift,  tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port9,           rightLift,     tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port10,          leftMidLift,   tmotorVex393_HBridge, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

#define LOOP_SPEED              25
#define MAX_POWER              127
#define MIN_POWER             -127


#define SAFETY_DELAY				200


// final motor drive
long            motor_driveR;            /// RIGHT
long            motor_driveL;            /// LEFT


/*///////////////////////////////////////////////////////////
/////                     __ ___  _  __                 /////
/////                    / /|__ \| |/ /                 /////
/////                   / /_   ) | ' /                  /////
/////                  | '_ \ / /|  <                   /////
/////                  | (_) / /_| . \                  /////
/////                   \___/____|_|\_\                 /////
/////                                                   /////
///// Team 62K Robot                                    /////
///// Main Code                                         /////
///// Authors: Abner Benitez                            /////
///// Last Modified: Dec. 4, 2016                      /////
*////////////////////////////////////////////////////////////

/*
To Do List
1. Add slew control
*/

#warning "setters"
//universal setters
void
setSensorVal()
{
	//don't set potentiometer values here

}


//setters for Autonomous
void
setLDriveBase( int valueL, int time )
{
	motor[ LDriveBase ] = valueL/2;
	delay( SAFETY_DELAY );

	motor[ LDriveBase ] = valueL;
	delay( time );
}


void
setRDriveBase( int valueR, int time )
{
	motor[ RDriveBase ] = valueR/2;
	delay( SAFETY_DELAY );

	motor[ RDriveBase ] = valueR;
	delay( time );
}



//setters for TeleOp
void
setLDriveBase( int valueL )
{
	motor[ LDriveBase ] = valueL;
}


void
setRDriveBase( int valueR )
{
	motor[ RDriveBase ] = valueR;
}


#warning "action methods"
//action methods for Autonomous
void
move( int time, int left, int right )
{
	setLDriveBase( left, time );
	setRDriveBase( right, time );

	setLDriveBase( left, 0 );
	setRDriveBase( right, 0 );
}


void
setLift( int time, int power )
{
	motor[ leftMidLift ] = power/2;
	motor[ leftLift ] = power/2;
	motor[ rightMidLift ] = power/2;
	motor[ rightLift ] = power/2;
	delay( SAFETY_DELAY );

	motor[ leftMidLift ] = power;
	motor[ leftLift ] = power;
	motor[ rightMidLift ] = power;
	motor[ rightLift ] = power;
	delay( time );

	motor[ leftMidLift ] = 0;
	motor[ leftLift ] = 0;
	motor[ rightMidLift ] = 0;
	motor[ rightLift ] = 0;
	//delay(100);
}


void
setClaw( int time, int power )
{
	motor[ leftClaw ] = power;
  motor[ rightClaw ] = power;
	delay( time );
}



//action methods for TeleOp
void
move( int left, int right )
{
	setLDriveBase( left );
	setRDriveBase( right );
}


void
setLift( int power )
{
	motor[ leftMidLift ] = power;
	motor[ leftLift ] = power;
	motor[ rightMidLift ] = power;
	motor[ rightLift ] = power;
}


void
setClaw( int power )
{
	motor[ leftClaw ] = power;
	motor[ rightClaw ] = power;

}


#warning "stopAll"
//stops everything
void
allStop()
{
	move( 1000, 0, 0 );
	setLift( 1000, 0 );
	setClaw( 1000, 0 );
}

#warning "PID Controller"
task PIDcontroller()
{

}


#warning "pre-auton"
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

	setSensorVal();
}


#warning "autonomous"
task autonomous()
{
	// Remove this function call once you have "real" code.
	AutonomousCodePlaceholderForTesting();
}


#warning "usercontrol"
task usercontrol()
{
	setSensorVal();
	while (1)
	{
		//drive base
		setLDriveBase(abs(vexRT[ Ch3 ]) > 20 ? vexRT[ Ch3 ] : 0); //mess with deadbands
		setRDriveBase(abs(vexRT[ Ch2 ]) > 20 ? vexRT[ Ch2 ] : 0);



	  //lift
		setLift((vexRT[ Btn6U ] - vexRT[ Btn6D ]) * -127);

		/*
		// keep the lift up when holding stars
		if(vexRT[ Btn5U ] || vexRT[ Btn6U ]) //test with == 1
		 setArms(10);
		*/


		//claw
		setClaw((vexRT[ Btn5U ] - vexRT[ Btn5D ]) * -127);

		//if potentiometer meets condition && buttons for claw are not pressed -> keep low constant power to claw
		if(SensorValue[ rightClawPot ] < 800 && (vexRT[ Btn5U ] + vexRT[ Btn5D ] == 0))
			setClaw(-20);


		wait1Msec(20); //don't hog the CPU :)
	}
}
