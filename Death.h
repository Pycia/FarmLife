#ifndef DEATH_H
#define DEATH_H

/// Klasa przechowująca informacje o żywotności obiektu jajko i kurczak.

class Death
{
	private:
		/// Aktualny wiek obiektu (jajko lub kurczak).
		int age;
		/// Maksymalny wiek obiektu (jajko lub kurczak). Po przekroczeniu max wieku kurczak zostaje przerobiony na rosołek a z jajka wykluwa się nowy kurczak.
		int max_age;
	public:
};
#endif
