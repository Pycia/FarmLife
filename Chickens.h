#ifndef CHICKENS_H
#define CHICKENS_H

#include"Animal.h"
#include"Death.h"

/// Klasa opisująca kurki.

class Chickens:public Animal, public Death
{
	private:
		Sex sex;
	public:
		enum Sex {male, female}
		/// Metoda składająca jajka.
		void LyingEgg();
};
#endif
