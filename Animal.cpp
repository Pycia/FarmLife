#include"Animal.h"
#include"allegro5/allegro.h"
#include"allegro5/allegro_image.h"
#include<allegro5/allegro_primitives.h>
#include"allegro5/allegro_native_dialog.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Const.h"
/// Metody klasy Animal.

set<Animal*> *Animal::V;
set<Animal*> *Animal::Trash;
Board * Animal::boa;

void Animal::Crash(Animal *animal1, Animal *animal2,ALLEGRO_DISPLAY * display, int &counter)
{
	if(((animal1->animal_type==cock)&&(animal2->animal_type==hen))||((animal1->animal_type==hen)&&(animal2->animal_type==cock)))
		counter++;
	if((((animal1->animal_type==cock)&&(animal2->animal_type==hen))||((animal1->animal_type==hen)&&(animal2->animal_type==cock)))&&counter>10)
	{
		Animal *h, *e, *he;
		h=new Animal(Animal::heart,display);
		h->position.SetPosition(this->position.GetX(),this->position.GetY());
		e=new Animal(Animal::egg,display);
		e->position.SetPosition(this->position.GetX(),this->position.GetY());
		he=new Animal(Animal::hen,display);
		he->position.SetPosition(this->position.GetX(),this->position.GetY());
		counter=0;
	}
	animal1->Contact();
	animal2->Contact();
}


/*
void Animal::ChangeDirection(Speed &speed)
{
	if(speed.GetDirection()==Speed::n)
		speed.SetDirection(5);
	else
	if(speed.GetDirection()==Speed::nw)
		speed.SetDirection(6);
	else
	if(speed.GetDirection()==Speed::ne)
		speed.SetDirection(4);
	else
	if(speed.GetDirection()==Speed::s)
		speed.SetDirection(1);
	else
	if(speed.GetDirection()==Speed::se)
		speed.SetDirection(2);
	else
	if(speed.GetDirection()==Speed::sw)
		speed.SetDirection(8);
	else
	if(speed.GetDirection()==Speed::w)
		speed.SetDirection(7);
	else
	if(speed.GetDirection()==Speed::e)
		speed.SetDirection(3);

}*/
void Animal::Contact()
{
	this->speed.SetDirection(WhereCanIgo());
	position=position+speed;
	boa->SetAnimalOnTab(position, this);
	Bounce(speed);
	//position=position+speed;
	//if(!(boa->CanIwalkHere(position, ground_type)))
	//	ChangeDirection(speed);	
}

/*Position Animal::GetPosition()
{
	return this->position;
}*/
bool Animal::Decision(int direction)
{
	Position position_copy;
	position_copy=this->position;
	this->speed.SetDirection(direction);
	position_copy=position_copy+speed;
	return boa->CanIwalkHere(position_copy, this->ground_type);	
}

int Animal::WhereCanIgo()
{
	int randomize;
	randomize=rand()%8+1;
	int counter=0;
	while((!this->Decision(randomize))&&(counter<9))
	{
		counter++;
		randomize++;
		if(randomize>8)
			randomize=randomize%8+1;
	}
	if(counter<9) return randomize;
	else
		return 9;
	/*if(this->Decision(1)) return 1; //n
	else 
	if(this->Decision(2)) return 2; //nw
	else
	if(this->Decision(3)) return 3; //w
	else
	if(this->Decision(4)) return 4; //sw
	else
	if(this->Decision(5)) return 5; //s
	else
	if(this->Decision(6)) return 6; //se
	else
	if(this->Decision(7)) return 7; //e
	else
	if(this->Decision(8)) return 8; //ne
	else
		return 9; */
}

void Animal::Bounce(Speed &speed)
{
	/// Sytuacja, gdy zwierzątko dojdzie do lewego rogu.
	if(position.GetX()<25)
	{
		if(this->Decision(1)) speed.SetDirection(1); //n
		else
		if(this->Decision(8)) speed.SetDirection(8); //ne
		else
		if(this->Decision(6)) speed.SetDirection(6); //se
		else
		if(this->Decision(5)) speed.SetDirection(5); //s
		else
			speed.SetDirection(7); //e	
	} else
	/// Sytuacja, gdy zwierzątko dojdzie do prawego rogu.
	if(position.GetX()>A-50)
	{
		if(this->Decision(1)) speed.SetDirection(1); //n
		else
		if(this->Decision(2)) speed.SetDirection(2); //nw
		else
		if(this->Decision(4)) speed.SetDirection(4); //sw
		else
		if(this->Decision(5)) speed.SetDirection(5); //s
		else
			speed.SetDirection(3); //w	
	} else
	/// Sytuacja, gdy zwierzątko dojdzie do górnego rogu.
	if(position.GetY()<25)
	{
		if(this->Decision(3)) speed.SetDirection(3); //w
		else
		if(this->Decision(4)) speed.SetDirection(4); //sw
		else
		if(this->Decision(5)) speed.SetDirection(5); //s
		else
		if(this->Decision(6)) speed.SetDirection(6); //se
		else
			speed.SetDirection(7); //e
	} else
	/// Sytuacja, gdy zwierzątko dojdzie do dolnego rogu.
	if(position.GetY()>B-50)
	{
		if(this->Decision(3)) speed.SetDirection(3); //w
		else
		if(this->Decision(2)) speed.SetDirection(2); //nw
		else
		if(this->Decision(1)) speed.SetDirection(1); //n
		else
		if(this->Decision(8)) speed.SetDirection(8); //ne
		else
			speed.SetDirection(7); //e
	} 
}

void Animal::Move()
{
	//this->speed.SetDirection(WhereCanIgo());
	position=position+speed;
	boa->SetAnimalOnTab(position, this);
	
	/*/// Sprawdzenie, czy zwierzak może wejść na to pole.
	if(!(boa->CanIwalkHere(position, ground_type)))
		ChangeDirection(speed);
	else
		Bounce(speed);	
	/// Wylosowanie szybkości.
	//if(rand()%100==0)speed.SetDirection(rand()%8+1);
	/// Ustawienie zwierzątka w tablicy Field.
	boa->SetAnimalOnTab(position, this);	
	/// Przesunięcie zwierzątka o wektor.
	position=position+speed; */
	
}

void Animal::SetSets(set<Animal*> *V1, set<Animal*> *Trash1)
{
	Animal::V=V1;
	Animal::Trash=Trash1;
}

void Animal::Draw(set<Animal*> *Trash, int &counter)
{
	al_draw_bitmap(image[index/10],this->position.GetX()-25, this->position.GetY()-25, 0);
	++index;
	index%=20;
	if((this->animal_type==heart)||(this->animal_type==egg))
		counter++;
	if(((this->animal_type==heart)||(this->animal_type==egg))&&(counter>5))
	{
		Trash->insert(this);
		counter=0;
	}
	
		
}

Animal::Animal(AnimalType animal_type, ALLEGRO_DISPLAY *display1)
{
	display=display1;
	index=0;
	double rand1=rand();
	rand1/=RAND_MAX;
	this->speed.SetSpeed(rand1+0.2);	
	double x=rand()*A;
	x/=RAND_MAX;
	double y=rand()*B;
	y/=RAND_MAX;
	if(animal_type==cow)
	{
		/// Załadowanie grafiki.
		image[0]=al_load_bitmap("../Animation/Cow/Cow1.png");
		image[1]=al_load_bitmap("../Animation/Cow/Cow2.png");
		/// Ustawienie po jakiej powierzchni może chodzić dane zwierzątko.
		this->ground_type.SetGroundType(0, 0, 1, 0);
		this->animal_type=cow;
	}
	else
	if(animal_type==pig)
	{
		image[0]=al_load_bitmap("../Animation/Pig/Pig1.png");
		image[1]=al_load_bitmap("../Animation/Pig/Pig2.png");
		this->ground_type.SetGroundType(1, 0, 0, 0);
		this->animal_type=pig;
	}
	else
	if(animal_type==cock)
	{
		image[0]=al_load_bitmap("../Animation/Cock/Cock1.png");
		image[1]=al_load_bitmap("../Animation/Cock/Cock2.png");
		this->ground_type.SetGroundType(0, 0, 1, 0);
		this->animal_type=cock;
	}
	else
	if(animal_type==hen)
	{
		image[0]=al_load_bitmap("../Animation/Hen/Hen1.png");
		image[1]=al_load_bitmap("../Animation/Hen/Hen2.png");
		this->ground_type.SetGroundType(0, 0, 1, 0);
		this->animal_type=hen;
	}
	else
	if(animal_type==duck)
	{
		image[0]=al_load_bitmap("../Animation/Duck/Duck1.png");
		image[1]=al_load_bitmap("../Animation/Duck/Duck2.png");
		this->ground_type.SetGroundType(0, 1, 0, 0);
		this->animal_type=duck;
	
	}
	else
	if(animal_type==heart)
	{
		image[0]=al_load_bitmap("../Animation/Heart/Heart.png");
		image[1]=al_load_bitmap("../Animation/Heart/Heart.png");
		this->ground_type.SetGroundType(0, 0, 1, 0);
		this->animal_type=heart;
	}
	else
	if(animal_type==egg)
	{
		image[0]=al_load_bitmap("../Animation/Egg/Egg1.png");
		image[1]=al_load_bitmap("../Animation/Egg/Egg2.png");
		this->ground_type.SetGroundType(0, 0, 1, 0);
		this->animal_type=egg;
	}
	/// Ustawienie współrzędnych pozycji.
	this->position.SetPosition(x,y);
	/// Zapytanie, czy dany zwierzak może mieć daną pozycję (czy jego wylosowane współrzędne spełniają dane kryteria po czym może chodzić)
	while(!(boa->CanIwalkHere(position, ground_type)))
	{
		x=rand()*A;
		x/=RAND_MAX;
		y=rand()*B;
		y/=RAND_MAX;
		this->position.SetPosition(x,y); 	
	}
	
	//int randomize;
	//randomize=rand()%8+1;
	/// Losowe ustawienie kierunku poruszania.
	this->speed.SetDirection(WhereCanIgo());
	/// Ustawienie zwierzątka w tablicy Field.
	boa->SetAnimalOnTab(position, this);
	/// Dodanie zwierzątka do wektoru setów.
	V->insert(this);	
}

Animal::~Animal()
{
	V->erase(this);
}

void Animal::SetBoard(Board*board)
{
	boa=board;
}
