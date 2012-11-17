#ifndef GroundType_H
#define GroundType_H

///Klasa do przechowywania informacji po jakim terenie może chodzić dane zwierzątko.

class GroundType
{
	public:
		bool M;		///Mud.
		bool P;		///Pond.
		bool G;		///Grass.
		bool F;		///Fency.
		GroundType();
		/// Metoda ustawiająca typ powierzchni, po której może poruszać się dany zwierzak.
		void SetGroundType(bool M1, bool P1, bool G1, bool F1);
		/// Metoda mówiąca zwierzakowi, czy może wejść na dane pole.
		bool CanIgoTo(char type);
		
};

#endif
