#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    rightClawPot,   sensorPotentiometer)
#pragma config(Sensor, I2C_1,  leftIEM,        sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightIEM,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           rightClaw,     tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           LDriveBase,    tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           RDriveBase,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port4,           LFrontDriveBase, tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port5,           RFrontDriveBase, tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port6,           leftLift,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           leftClaw,      tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port8,           rightMidLift,  tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port9,           rightLift,     tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port10,          leftMidLift,   tmotorVex393_HBridge, openLoop, reversed, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(1)
	{
		motor[ LDriveBase ] = vexRT[ Btn7U ] * 128;
		motor[ RDriveBase ] = vexRT[ Btn7R ] * 128;
		motor[ LFrontDriveBase ] = vexRT[ Btn7D ] * 128; //check
		motor[ RFrontDriveBase ] = vexRT[ Btn7L ] * 128; //check


		motor[ leftLift ] = vexRT[ Btn8U ] * 128; //check
		motor[ leftMidLift ] = vexRT[ Btn8R ] * 128; //check
		motor[ rightMidLift ] = vexRT[ Btn8D ] * 128; //check
		motor[ rightLift ] = vexRT[ Btn8L ] * 128; //check


		motor[ leftClaw ] = vexRT[ Btn5U ] * 128; //check
		motor[ rightClaw ] = vexRT[ Btn5D ] * 128; //check

		//extra buttons
		/*
		motor[  ] = vexRT[ Btn6U ] * 128;
		motor[  ] = vexRT[ Btn6D ] * 128;
		*/
	}
}