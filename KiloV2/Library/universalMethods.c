#warning "setters"
//universal setters
void
setSensorVal()
{
	//don't set potentiometer values here

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
