#include"Speed.h"
///Metody klasy speed.

double Speed::GetSpeed()
{
	return this->velocity;
}

void Speed::SetSpeed(double speed)
{
	this->velocity=speed;
}

Speed::Direction Speed::GetDirection()
{
	return this->direction;
}

void Speed::SetDirection(int randomize)
{
	if(randomize==1)
		this->direction=n;
	else
	if(randomize==2)
		this->direction=nw;
	else
	if(randomize==3)
		this->direction=w;
	else
	if(randomize==4)
		this->direction=sw;
	else
	if(randomize==5)
		this->direction=s;
	else
	if(randomize==6)
		this->direction=se;
	else
	if(randomize==7)
		this->direction=e;
	else
	if(randomize==8)
		this->direction=ne;
}
