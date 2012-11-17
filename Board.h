#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_native_dialog.h"
#include"Field.h"
#include"Const.h"
#include"Position.h"
/// Klasa przechowująca planszę.

class Board
{
	private:
		/// Tablica przechowująca pola.
		Field tab[N][M];
		ALLEGRO_DISPLAY *display;
		ALLEGRO_BITMAP *image;
	public:
		/// Metoda zwracająca daną komórkę w tablicy.
		Field GetTab(int x, int y);
		/// Załadowanie tła (jednorazowe)
		Board(ALLEGRO_DISPLAY *display1);
		/// Metoda wczytująca z pliku planszę.
		void Read();
		/// Metoda rysująca planszę.
		void Draw();
		/// Metoda ustawiająca zwierzątko na planszy.
		void SetAnimalOnTab(Position position, Animal *animal);
		/// Metoda "czyszcząca" nieaktualne ustawienie zwierzątek na planszy.
		void Clean();
		/// Metoda mówiąca zwierzątku, czy może wejść na dany typ pola.
		bool CanIwalkHere(Position &position, GroundType ground_type);
		
};
#endif
