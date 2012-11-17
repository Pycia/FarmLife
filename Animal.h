#ifndef ANIMAL_H
#define ANIMAL_H
#include"Board.h"
#include"Speed.h"
#include"GroundType.h"
#include"Position.h"
#include<set>
#include"allegro5/allegro.h"
#include"allegro5/allegro_image.h"
#include<allegro5/allegro_primitives.h>
#include"allegro5/allegro_native_dialog.h"
using namespace std;
/// Klasa przechowująca informacje o typie zwierzątka, powierzchni po jakiej może chodzić i prędkości.
class Animal
{
	private:
		Speed speed;
		
		GroundType ground_type;
		static set<Animal*> * V;
		static set<Animal*> * Trash;
		static Board * boa;
		ALLEGRO_DISPLAY *display;
		ALLEGRO_BITMAP *image[2];
		int index;	
		bool event;	
	public:
		enum AnimalType {cow, pig, duck, hen, cock, egg, heart};
		AnimalType animal_type;
		~Animal();
		Position position;
		///Konstruktor, który tworząc zwierzątko dodaje je do wektora V.
		Animal(AnimalType animal_type, ALLEGRO_DISPLAY *display1);
		/// Metoda zmieniająca kierunek zwierzątek, które na siebie naszły.
		void Contact();
		/// Metoda "poruszająca" zwierzątkiem.
		void Move();
		/// Metoda rysujaca zwierzątko.
		void Draw(set<Animal*> *Trash1, int &counter);
		/// Metoda przesuwająca zwierzątko.
		void Move(Speed &speed);
	//	Position GetPosition();
		/// Metoda wybierająca kierunek poruszania.
		int WhereCanIgo();
		/// Metoda zmieniająca kierunek poruszania się zwierzaków, gdy wejdą na kraniec planszy.
		void Bounce(Speed &speed);
		bool Decision(int direction);
		/// Metoda zmieniająca kierunek poruszania się zweirzaków na przeciwny.
	//	void ChangeDirection(Speed &speed);
		/// Metoda obsługujaca zderzenia zwierzątek.
		void Crash(Animal *animal1, Animal *animal2,ALLEGRO_DISPLAY * display, int &counter);
		static void SetSets(set<Animal*> *V, set<Animal*> *Trash);
		// Metoda ustawiająca wskaźnik na board.
		static void SetBoard(Board *board);
		
};

#endif
