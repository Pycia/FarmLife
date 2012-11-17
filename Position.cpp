#include"Position.h"
#include"Const.h"
#include<stdlib.h>
/// Metody klasy Position.
Position Position::operator+(Speed &speed)
{
	Move(speed);
	return *this;
}

/*Position Position::operator=(Position &position)
{
	position.x=this->x;
	position.y=this->y;
	return position;
}*/


void Position::Move(Speed &speed)
{
	if(speed.GetDirection()==Speed::n)
		this->y-=speed.GetSpeed();
	else
	if(speed.GetDirection()==Speed::nw)
	{
		this->x-=speed.GetSpeed();
		this->y-=speed.GetSpeed();
	}
	else
	if(speed.GetDirection()==Speed::w)
		this->x-=speed.GetSpeed();
	else
	if(speed.GetDirection()==Speed::sw)
	{
		this->x-=speed.GetSpeed();
		this->y+=speed.GetSpeed();
	}
	else
	if(speed.GetDirection()==Speed::s)
		this->y+=speed.GetSpeed();
	else
	if(speed.GetDirection()==Speed::se)
	{
		this->x+=speed.GetSpeed();
		this->y+=speed.GetSpeed();
	}
	else
	if(speed.GetDirection()==Speed::e)
		this->x+=speed.GetSpeed();
	else
	if(speed.GetDirection()==Speed::ne)
	{
		this->x+=speed.GetSpeed();
		this->y-=speed.GetSpeed();
	}
}

void Position::SetPosition(double x, double y)
{
	this->x=x;
	this->y=y;	
}

double Position::GetX()
{
	return this->x;
}

double Position::GetY()
{
	return this->y;
}
