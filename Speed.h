#ifndef SPEED_H
#define SPEED_H

/// Klasa do przechowywania informacji o prędkości zwierzątka i kierunku w jakim się porusza.

class Speed
{
	public:
		/// Kierunki poruszania: n-North, nw-NorthWest, w-West, sw-SouthWest, s-South, se-SouthEast, e-East, ne-NorthEast, o- Nic.
		enum Direction {n, nw, w, sw, s, se, e, ne, o};
		///Wyłuskanie szybkości.
		double GetSpeed();
		///Ustawienie szybkości.
		void SetSpeed(double speed);
		///Wyłuskanie kierunku poruszania.
		Direction GetDirection();
		///Ustawienie kierunku.
		void SetDirection(int randomize);
	private:
		Direction direction;
		double velocity;
		
		
};
#endif
