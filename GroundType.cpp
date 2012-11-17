#include"GroundType.h"
///Metody klasy GroundType
///Zainicjalizowanie konstruktora zerami (Zwierzątko nie może na niczym chodzić)
GroundType::GroundType():M(0),P(0),F(0),G(0){}		

void GroundType::SetGroundType(bool M1, bool P1, bool G1, bool F1)
{
	this->M=M1;
	this->P=P1;
	this->G=G1;
	this->F=F1;
}

bool GroundType::CanIgoTo(char type)
{
	if(type=='M')
		return this->M;
	else
	if(type=='P')
		return this->P;
	else
	if(type=='G')
		return this->G;
	else
	if(type=='F')
		return this->F;
	else
		return 0;
}

