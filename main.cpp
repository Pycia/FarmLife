#include"Board.h"
#include<stdio.h>
#include"allegro5/allegro.h"
#include"allegro5/allegro_image.h"
#include<allegro5/allegro_primitives.h>
#include"allegro5/allegro_native_dialog.h"
#include<set>
#include"Animal.h"
#include<cmath>
using namespace std;
/// Funkcje.
/// Funkcja inicjalizująca elementy biblioteki graficznej.
int Init()
{
	srand (time(NULL));
	if(!al_init()) 
	{
		fprintf(stderr, "failed to init!\n");
		return 0;
	}

	if(!al_init_image_addon()) 
	{
		fprintf(stderr, "failed to init image!\n");
		return 0;
	}
	return 1;
}
/// Funkcja inicjalizująca elementy biblioteki graficznej.
int Init2(ALLEGRO_DISPLAY *&display, ALLEGRO_TIMER *&timer, ALLEGRO_EVENT_QUEUE *&event_queue)
{
	display = al_create_display(A, B);
	if(!display) 
  	{
      		fprintf(stderr, "failed to create display!\n");
      		return 0;
    	}
    	timer = al_create_timer(1.0 / F);
    	if(!timer) 
   	{
      		fprintf(stderr, "failed to create timer!\n");
      		return 0;
   	} 
   	event_queue = al_create_event_queue();
   	if(!event_queue) 
   	{
      		fprintf(stderr, "failed to create event_queue!\n");
      		return 0;
   	} 
    	return 1;
}
/// Funkcja rysująca zwierzątko na planszy.
void Draw(ALLEGRO_DISPLAY*display,Board &board, set<Animal*> &V,set<Animal*> &Trash, int &counter)
{
	al_set_target_bitmap(al_get_backbuffer(display));
	/// Narysowanie planszy.
	board.Draw();
	int dx;
	int dy;
	for(set<Animal*>::iterator i=V.begin(); i!=V.end(); i++)
	{
		(*i)->Draw(&Trash,counter);
		(*i)->Move();
			/// Pętla sprawdzająca, czy zwierzak nie wszedł na innego zwierzaka.
			for(set<Animal*>::iterator j=V.begin(); j!=V.end(); j++)
			{
				dx=(*j)->position.GetX()-(*i)->position.GetX();
				dy=(*j)->position.GetY()-(*i)->position.GetY();
				if(sqrt(dx*dx+dy*dy)/2<20)
					(*j)->Crash(*i, *j, display, counter);
					
			
			}			
	}
	al_flip_display();
}

void MakeAnimals(ALLEGRO_DISPLAY * display)
{
	
	for(int i=0; i<3; ++i)
	{
		new Animal(Animal::pig,display);
		new Animal(Animal::cow,display);
		new Animal(Animal::cow,display);
		new Animal(Animal::duck,display);
		new Animal(Animal::hen,display);
		new Animal(Animal::hen,display);
		new Animal(Animal::cock,display);
	}
}

int main()
{	
	/// Inicjalizowanie elementów biblioteki graficznej.
	int ok=Init();
	if(!ok) return 0;
	ALLEGRO_DISPLAY *display = NULL;
   	ALLEGRO_TIMER *timer = NULL;
  	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    	ok=Init2(display, timer, event_queue);
   	if(!ok) return 0;
   	Board board(display);
   	Animal::SetBoard(&board);
   	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_flip_display();
	al_start_timer(timer);
	ALLEGRO_EVENT event;
  	/// Stworzenie wektora zawierającego zwierzaki, którego używać będę przy renderowaniu klatki.
  	set<Animal*> V;
  	set<Animal*> Trash;
  	Animal::SetSets(&V,&Trash);
  	/// Stworzenie zwierzątek.
  	MakeAnimals(display);
  	/// Obsługa kolejki eventów.
  	int counter=0;
  	while(1)
 	{
 		al_wait_for_event(event_queue, &event);
 		if(event.type == ALLEGRO_EVENT_TIMER) 
 		{
        		Draw(display, board, V, Trash,counter);
        		for(set<Animal*>::iterator i=V.begin(); i!=V.end(); i++)
			{
				for(set<Animal*>::iterator j=Trash.begin(); j!=Trash.end(); j++)
				{
					if(*i==*j)
        					V.erase(*i);
        			}
        		}
        		board.Clean();
        		Trash.clear(); 
      		}
      		else 
      		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
        		 break;
	}
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);		
}


