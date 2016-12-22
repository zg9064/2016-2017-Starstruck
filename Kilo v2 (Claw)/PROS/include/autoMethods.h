#ifndef _AUTO_METHODS_
#define _AUTO_METHODS_

//setters for Autonomous
void
setLDriveBase( int valueL, int time );

void
setRDriveBase( int valueR, int time );


#warning "action methods"
//action methods for Autonomous
void
move( int time, int left, int right );


void
setLift( int time, int power );

void
setClaw( int time, int power );
#endif
