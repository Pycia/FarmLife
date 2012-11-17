#include"Board.h"
#include<fstream>
/// Metody klasy Board.
using namespace std;

Field Board::GetTab(int x, int y)
{
	return this->tab[x][y];
}

void Board::SetAnimalOnTab(Position position, Animal *animal)
{
	tab[int(position.GetX()/50)][int(position.GetY()/50)].SetAnimal(animal);
}

bool Board::CanIwalkHere(Position &position, GroundType ground_type)
{
	double x=position.GetX();
	double y=position.GetY();
	x=(x/50);
	y=(y/50);
	return ground_type.CanIgoTo(tab[int(x)][int(y)].GetType());
}


void Board::Read()
{
	///Zmienna przechowujaca literkę reprezentującą daną powierzchnię.
	char a;				
	ifstream file ("Board" ,ios_base::in );
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			
			file>>a;
			tab[j][i].SetType(a);
		}
		///Ignorowanie endl;
		file.ignore(1);		
	}
}
void Board::Draw()
{
	al_draw_bitmap(image,0,0,0);
}

Board::Board(ALLEGRO_DISPLAY *display1)
{
	image=al_load_bitmap(background);
	display=display1;
	Read();
}
void Board::Clean()
{
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			tab[j][i].animal=NULL;	
}

