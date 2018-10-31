#include "main.h"

int main(){

	enum MENU{QUIT = 'q', FLIGHTS = 'a', PLANES = 'b', CREW = 'c', SAVE = 'd', LOAD = 'e'};
	Crew crew;
	Flights flights;
	Planes planes;
	char selection;

	cout 

	   << endl
	   << "    +-----------------------------------------------------------------+   " << endl
	   << "    |                Computer Science and Engineering                 |   " << endl
	   << "    |                CSCE 1040 - Computer Science II                  |   " << endl
	   << "    |            Alice Zhu  az0144  alicezhu@my.unt.edu               |   " << endl
	   << "    +-----------------------------------------------------------------+   " << endl
	   << endl
	   << "                            MEAN GREEN AIRLINES                           " << endl
	   << endl;

	   do{

	   cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl
	   	   << endl
	       << " [                               MAIN MENU                               ]" << endl 
		   << endl
		   << "Welcome to the Mean Green Airlines database." << endl 
		   << endl
		   << "(a) Flights" << endl
		   << "(b) Planes" << endl
		   << "(c) Crew" << endl
		   << "(d) Save" << endl
		   << "(e) Load" << endl << endl
		   << "Enter your selection ('q' to quit): ";

			cin >> selection;
			selection = tolower(selection);
			cout << endl;

			switch(selection){

				case QUIT:
					break;
				case FLIGHTS:
					FlightMenu(flights, planes, crew);
					break;
				case PLANES:
					PlanesMenu(planes, crew);
					break;
				case CREW:
					CrewMenu(crew);
					break;
				case SAVE:
					Save(flights, planes, crew);
					cout << endl << "Press any key to return to the menu, or 'q' to quit: ";
						cin >> selection;
					break;
				case LOAD:
					Load(flights, planes, crew);
					cout << endl << "Press any key to return to the menu, or 'q' to quit: ";
						cin >> selection;
					break;

				default:
					cout << "Invalid selection." << endl;
					break;

			}

			cout << endl;

		}while (selection != 'q');

	return 0;

}