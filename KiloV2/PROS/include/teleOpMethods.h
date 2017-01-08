#ifndef _TELEOP_METHODS_
#define _TELEOP_METHODS_

//setters for TeleOp
void
setLDriveBase( int valueL );

void
setRDriveBase( int valueR );


//action methods for TeleOp
void
move( int left, int right );

void
setLift( int power );

void
setClaw( int power );
#endif
