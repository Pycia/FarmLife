#include"Field.h"
#include<cstdlib>
///Metody do klasy Field.

Animal * Field::GetAnimal()
{
	return this->animal;
}

bool Field::IsFree()
{
	if(animal==0)
		return 1;
	else
		return 0;
}
char Field::GetType()
{
	if(ground_type.M) 
		return 'M';
	else
	if(ground_type.G) 
		return 'G';
	else
	if(ground_type.P) 
		return 'P';
	else
	if(ground_type.F) 
		return 'F';
	else
		return 0;
}

void Field::SetType (char a)
{
	if(a=='G')
		ground_type.G=1;
	else
	if(a=='M')
		ground_type.M=1;
	else
	if(a=='P')
		ground_type.P=1;
	else
	if(a=='F')
		ground_type.F=0;
		
}

void Field::SetAnimal(Animal *animal1)
{
	this->animal=animal1;
}
Field::Field():animal(NULL){}
