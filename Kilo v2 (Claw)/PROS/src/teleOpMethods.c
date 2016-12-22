//setters for TeleOp
void
setLDriveBase( int valueL )
{
	motorSet(2, valueL);
  motorSet(4, valueL);
}


void
setRDriveBase( int valueR )
{
	motorSet(3, valueR);
	motorSet(5, valueR);
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
  motorSet(6, power);
  motorSet(8, power);
  motorSet(9, power);
  motorSet(10, power);

}


void
setClaw( int power )
{
  motorSet(1, power);
  motorSet(7, power);
}
