#ifndef FIELD_H
#define FIELD_H

#include"GroundType.h"
class Animal;
/// Klasa przechowująca rodzaj podłoża.
class Field
{
	private:
		
		GroundType ground_type;
	public:
		Animal *animal;
		/// Metoda zamieniająca literkę reprezentującą typ podłoża na cały napis.
		void SetType (char a);
		/// Metoda zwracająca 1, gdy pole jest wolne, 0, gdy pole jest zajęte.
		bool IsFree();
		/// Metoda zwracająca rodzaj pola.
		char GetType();
		/// Metoda ustawiająca, jakie zwierzątko jest aktualnie na jakim polu.
		void SetAnimal(Animal *animal1);
		/// Metoda zwracająca wskaźnik do danego zwierzątka.
		Animal * GetAnimal();
		/// Konstruktor ustawiający wskaźnik na zwierzątko wartością NULL.
		Field();
};
#endif
