#include <time.h>
#include "flights.h"
#include "pilot.h"
#include "copilot.h"
#include "cabin.h"

/************************************************************************************************/
/******************************************* PLANES *********************************************/
/************************************************************************************************/

void printAllPlanes(Planes planes){

	cout << " [                                PLANES                                 ]" << endl << endl
	<< "You are viewing all " << planes.GetSize() << " planes." << endl << endl;

	planes.printAll();

}

void addPlane(Planes& planes){

	Plane newPlane;
	string ID;
	string make;
	int model;
	int seatCount;
	int range;
	char status;

	cout << " [                              ADD A PLANE                              ]" << endl << endl

		<< "Plane ID: ";
			cin >> ID;

	if (planes.SearchID(ID) == true){

		cout << "Plane already exists." << endl;

	}

	else{

		cout << "Make: ";
			cin.ignore();
			getline(cin, make);

		cout << "Model (as an integer): ";
			cin >> model;

		cout << "Number of seats: ";
			cin >> seatCount;

		cout << "Range in miles (as an integer): ";
			cin >> range;

		cout << "Status (I = in, O = out, R = repair): ";
			cin >> status;

		status = toupper(status);

			if(status != 'I' && status != 'O' && status != 'R'){

				cout << "Invalid status" << endl;
			
			}
			
			else{

				newPlane.setInfo(ID, make, model, seatCount, range, status);
				planes.add(newPlane);
			}

	}


}

void editPlane(Planes& planes, Crew crew){

	string ID;
	char selection;

		cout << " [                              EDIT A PLANE                             ]" << endl << endl;


	if(planes.GetSize() == 0){

		cout << "No planes available." << endl;
		
	}

	else{

		printAllPlanes(planes);

		cout << endl << "Plane ID: ";
			cin >> ID;

		if (planes.SearchID(ID) == false){

			cout << "Plane does not exist." << endl;

		}

		else{

			int i;

			for (i = 0; i < planes.GetSize(); ++i){

					if(planes.GetPlaneID(i) == ID){
						break;
					}

				}

			cout << "What would you like to edit?" << endl
			<< endl
			<< "(a) Make" << endl
			<< "(b) Model" << endl
			<< "(c) Seat Count" << endl
			<< "(d) Range" << endl
			<< "(e) Status" << endl
			<< endl
			<< "Enter your selection: ";

			cin >> selection;

			switch (selection){

				case 'a':
					planes.EditMake(i);
					break;

				case 'b':
					planes.EditModel(i);
					break;

				case 'c':
					planes.EditSeatCount(i);
					break;

				case 'd':
					planes.EditRange(i);
					break;

				case 'e':
					planes.EditStatus(i);
					break;

				default:

					cout << "Invalid selection." << endl;

			}

		}

	}
}

void removePlane(Planes& planes){

	string ID;

	cout << " [                            REMOVE A PLANE                             ]" << endl << endl;

	if(planes.GetSize() == 0){

		cout << "No planes available." << endl;
		
	}

	else{

		printAllPlanes(planes);

		cout << endl << "Plane ID: ";
			cin >> ID;

		if (planes.SearchID(ID) == false){

			cout << "Plane does not exist." << endl;

		}

		else if(planes.GetSize() == 0){

			cout << "No planes available." <<endl;

		}

		else{

			planes.remove(ID);
		}

	}

}

void printPlaneInfo(Planes planes){

	string ID;

	cout << " [                           VIEW PLANE INFO                             ]" << endl << endl;

	if(planes.GetSize() == 0){
		cout << "No planes available." << endl;
	}

	else{

		printAllPlanes(planes);

		cout << endl << "Plane ID: ";
			cin >> ID;

		if(planes.SearchID(ID) == false){
			cout << "Plane ID does not exist." << endl;
		}

		else{

			planes.printSingle(ID);

		}
	}

}

/************************************************************************************************/
/******************************************** CREW **********************************************/
/************************************************************************************************/

void printCrew(Crew crew){

	cout << " [                                  CREW                                 ]" << endl << endl;


	cout.width(10); cout << "ID";
	cout.width(20); cout << "LAST";
	cout.width(20); cout << "FIRST";
	cout.width(15); cout << "TYPE";
	cout.width(10); cout << "STATUS" << endl;
	for(int i = 0; i < 75; ++i){
		cout << "-";
	}
	cout << endl;
	crew.printAll();

}

void addCrewMember(Crew& crew){

	CrewMember* newMember;
	string last;
	string first;
	int ID;
	char type;

	cout << " [                             ADD A MEMBER                              ]" << endl << endl

		<< "Member ID#: ";
			cin >> ID;

	if (crew.SearchID(ID) == true){

		cout << "Member already exists." << endl;

	}
	else{

		cout << "Member type (i = pilot, o = copilot, c = cabin): ";
				cin >> type;
				type = tolower(type);

		if(type != 'i' && type != 'o' && type != 'c'){

			cout << "Invalid member type." << endl;
		}

		else if(type == 'i'){

			Pilot* newPilot = new Pilot;
			char rating[5];
			int hours;

			cout << "Last name: ";
					cin.ignore();
					getline(cin, last);
					last[0] = toupper(last[0]);

			cout << "First name: ";
					getline(cin, first);
					first[0] = toupper(first[0]);

			cout << "Rating (5 chars): ";
				cin >> rating;

			cout << "Hours: ";
				cin >> hours;

			newPilot->setInfo(last, first, ID, rating, hours);
			crew.add(newPilot);

		}

		else if(type == 'o'){

			CoPilot* newCoPilot = new CoPilot;
			char rating[4];
			int hours;

			cout << "Last name: ";
					cin.ignore();
					getline(cin, last);
					last[0] = toupper(last[0]);

			cout << "First name: ";
					getline(cin, first);
					first[0] = toupper(first[0]);

			cout << "Rating (4 chars): ";
				cin >> rating;

			cout << "Hours: ";
				cin >> hours;

			newCoPilot->setInfo(last, first, ID, rating, hours);
			crew.add(newCoPilot);

		}

		else if (type == 'c'){

			char position;

			cout << "Position (f = First Class, b = Business, e = Economy front, r = Economy rear, l = Lead) : ";
				cin >> position;

			if(position != 'f' && position != 'b' && position != 'e' && position != 'r' && position != 'l'){
				cout << "Invalid cabin type." << endl;
			}

			else{

				Cabin* newCabin = new Cabin;

				cout << "Last name: ";
						cin.ignore();
						getline(cin, last);
						last[0] = toupper(last[0]);

				cout << "First name: ";
						getline(cin, first);
						first[0] = toupper(first[0]);

				newCabin->setInfo(last, first, ID, position);
				crew.add(newCabin);
			}

		}

	}

	return;

}

void editCrewMember(Crew& crew){

	int ID;
	char selection;

	cout << " [                             EDIT A MEMBER                             ]" << endl << endl;

	if(crew.GetSize() == 0){
		cout << "No crew members available." << endl;
	}

	else{

		printCrew(crew);

		cout << endl << "Member ID#: ";
			cin >> ID;

		if (crew.SearchID(ID) == false){

			cout << "Member does not exist." << endl;

		}

		else{

			int i;

			for(i = 0; i < crew.GetSize(); ++i){

				if(crew.GetMemberID(i) == ID){
					break;
				}
			}

			cout << "What would you like to edit?" << endl
			<< endl
			<< "(a) Name" << endl
			<< "(b) Type (pilot, copilot, cabin)" << endl
			<< "(c) Status" << endl
			<< endl
			<< "Enter your selection: ";

			cin >> selection;

			switch (selection){

				case 'a':
					crew.EditName(i);
					break;

				case 'b':
					crew.EditType(i);
					break;

				case 'c':
					crew.EditStatus(i);
					break;

				default:

					cout << "Invalid selection." << endl;

			}

		}

	}

}


void removeCrewMember(Crew& crew){

	int ID;

	cout << " [                            REMOVE A MEMBER                             ]" << endl << endl;


	if(crew.GetSize() == 0){
		cout << "No crew members available." << endl;
	}	

	
	else{

		printCrew(crew);

		cout << endl << "Member ID#: ";
				cin >> ID;

				if (crew.SearchID(ID) == false){
						cout << "Member does not exist." << endl;
				}

				else{
					crew.remove(ID);
				}
	}

}

void printMemberInfo(Crew crew){

	int ID;

	cout << " [                            VIEW MEMBER INFO                           ]" << endl << endl;
	
	if(crew.GetSize() == 0){
		cout << "No crew members available." << endl;
	}	

	
	else{

		cout.width(10); cout << "ID";
	cout.width(20); cout << "LAST";
	cout.width(20); cout << "FIRST";
	cout.width(15); cout << "TYPE";
	cout.width(10); cout << "STATUS" << endl;
	for(int i = 0; i < 75; ++i){
		cout << "-";
	}
	cout << endl;
		crew.printAll();

		cout << endl << "Enter member ID#: ";
			cin >> ID;

		if(crew.SearchID(ID) == false){
			cout << "Member ID does not exist." << endl;
		}

		else{

			crew.printSingle(ID);

		}

	}

}

void printMemberType(Crew crew){

	char type;

	cout << " [                          VIEW MEMBER BY TYPE                          ]" << endl << endl
	<< "Available types: " << endl
	<< "(a) Pilot" << endl
	<< "(b) Co-Pilot" << endl
	<< "(c) Cabin" << endl << endl
	<< "Enter type you would like to view: ";
	cin >> type;

	if(type != 'a' && type != 'b' && type != 'c'){
		cout << "Invalid type." << endl << endl;
	}

	else if(type == 'a'){
		cout << endl;
		cout.width(10); cout << "ID";
		cout.width(20); cout << "LAST";
		cout.width(20); cout << "FIRST";
		cout.width(10); cout << "RATING";
		cout.width(5); cout << "HRS";
		cout.width(10); cout << "STATUS" << endl;
	for(int i = 0; i < 75; ++i){
		cout << "-";
	}
	cout << endl;
		crew.printPilots();
	}

	else if (type == 'b'){
		cout << endl;
		cout.width(10); cout << "ID";
		cout.width(20); cout << "LAST";
		cout.width(20); cout << "FIRST";
		cout.width(10); cout << "RATING";
		cout.width(5); cout << "HRS";
		cout.width(10); cout << "STATUS" << endl;
	for(int i = 0; i < 75; ++i){
		cout << "-";
	}
	cout << endl;
		crew.printCoPilots();
	}
	
	else if (type == 'c'){
		cout << endl;
		cout.width(10); cout << "ID";
	cout.width(20); cout << "LAST";
	cout.width(20); cout << "FIRST";
	cout.width(15); cout << "TYPE";
	cout.width(10); cout << "STATUS" << endl;
	for(int i = 0; i < 75; ++i){
		cout << "-";
	}
	cout << endl;
		crew.printCabin();
	}

	else{
		cout << "An error has occurred." << endl << endl;
	}


}

/************************************************************************************************/
/****************************************** FLIGHTS *********************************************/
/************************************************************************************************/

void addFlight(Flights& flights, Planes planes, Crew crew){

	Flight newFlight;
	string planeID;
	int month;
	struct tm* start = new tm;
	struct tm* end = new tm;

	cout << " [                             ADD A FLIGHT                              ]" << endl << endl;

	if(planes.GetSize() == 0){
		cout << "No planes available." << endl;
	}

	else if(crew.GetSize() == 0){
		cout << "No crew members available." << endl;
	}

	else{

		printAllPlanes(planes);

		cout << endl << "Plane ID: ";
		cin >> planeID;

		if(planes.SearchID(planeID) == false){
			cout << "Plane does not exist." << endl;
		}

		else if(planes.GetStatus(planeID) == 'O'){
			cout << "Plane is currently out." << endl;
		}

		else if(planes.GetStatus(planeID) == 'R'){
			cout << "Plane is currently in repair." << endl;
		}

		else{

			int passengers;

			cout << "Number of passengers: ";
				cin >> passengers;

			if(passengers > planes.GetPassengerCount(planeID)){
				cout << "# of passengers exceeds plane capacity." << endl;
			}

			else{

			int mon;
			int day;
			int yr;
			int hour;
			int min;

			cout << endl << "DEPARTURE" << endl;

				cout << "Month (1 = January to 12 = December): ";
					cin >> mon;
					start->tm_mon = mon;

				cout << "Day (1 to 31): ";
					cin >> start->tm_mday;

				cout << "Year: ";
					cin >> start->tm_year;

				cout << "Time (hour, 0 to 24): ";
					cin >> start->tm_hour;

				cout << "Time (mins): ";
					cin >> start->tm_min;

				cout << endl << "ARRIVAL" << endl;

				cout << "Month (1 = January to 12 = December): ";
					cin >> mon;
					end->tm_mon = mon;

				cout << "Day (1 to 31): ";
					cin >> end->tm_mday;

				cout << "Year: ";
					cin >> end->tm_year;

				cout << "Time (hour, 0 to 24): ";
					cin >> end->tm_hour;

				cout << "Time (mins): ";
					cin >> end->tm_min;

				cout << endl;

				newFlight.SetPassengerCount(passengers);
				newFlight.SetPlaneID(planeID);
				newFlight.SetDate(start, end);
				newFlight.SetStartPort();
				newFlight.SetEndPort();

				cout << endl;
				printCrew(crew);

				int pilotID;
				cout << endl << "Pilot ID#: ";
					cin >> pilotID;

					if(crew.SearchID(pilotID) == false){
							cout << "Crew member does not exist." << endl;
					}

					else if(crew.CheckPilot(pilotID) == false){
						cout << "Crew member is not authorized for this position." << endl;
					}

					else if(crew.CheckStatus(pilotID) == false){
						cout << "Crew member is not available for this flight." << endl;
					}
		
					else{

						int copilotID;

						newFlight.SetPilot(pilotID);
						cout << "Co-Pilot ID#: ";
							cin >> copilotID;

						if(crew.SearchID(copilotID) == false){
							cout << "Crew member does not exist." << endl;
						}

						else if(crew.CheckCoPilot(copilotID) == false){
							cout << "Crew member is not authorized for this position." << endl;
						}

						else if(crew.CheckStatus(copilotID) == false){
							cout << "Crew member is not available for this flight." << endl;
						}

						else{

							newFlight.SetCoPilot(copilotID);
							bool validCabin = true;;

							vector<int> temp(3);
							int i = 0;

							while(i < 3){

								cout << "Cabin Member #" << i + 1 << " ID: ";
									cin >> temp.at(i);

								if(crew.SearchID(temp.at(i)) == false){
									cout << "Crew member does not exist." << endl;
								}

								else if(crew.CheckStatus(temp.at(i)) == false){
									cout << "Crew member is not available for this flight." << endl;
								}

								else if(crew.CheckCabin(temp.at(i)) == false){
									cout << "Crew member is not authorized for this position." << endl;
								}

								else{
									++i;
								}

							}

							newFlight.SetCabin(temp);
							flights.add(newFlight);

							temp.clear();

						}

					
					}

				}

			}

		}

	// make sure plane has any empty seats
}

void editFlight(Flights& flights, Planes& planes, Crew& crew){

	cout << " [                              EDIT A FLIGHT                             ]" << endl << endl;

	if(flights.GetFlightCount() == 0){
		cout << "No flight available." << endl;
	}

	else{

		flights.ViewAll();

		char selection;
		int flightID;

		cout << endl << "Press 's' to manually edit a flight status; or 'm' to edit multiple information for a flight: ";
			cin >> selection;

		if(selection != 's' && selection != 'm'){
			cout << "Invalid selection." << endl;
		}

		else{

			cout << "Flight ID#: ";
				cin >> flightID;

			if(selection == 's'){
				flights.EditStatus(flightID, planes, crew);
			}

			if(selection == 'm'){
				flights.EditMultiple(flightID, planes, crew);
			}


		}

	}
	
}

void printSchedule(Flights flights, Planes planes, Crew crew){

	cout << " [                                SCHEDULE                               ]" << endl << endl;


	if(flights.GetFlightCount() == 0){
		cout << "No flights available." << endl;
	}

	else{

	char selection;

	cout << "Press 'c' to view a crew member's schedule, or 'a' to view an airplane's schedule: ";
		cin >> selection;

	if (selection != 'c' && selection != 'a'){
		cout << "Invalid selection." << endl;
	}

	else if(selection == 'c'){
		int memberID;
		cout << endl;
		printCrew(crew);

		cout << endl << "Member ID: ";
			cin >> memberID;

		char type;

		for(int i = 0; i < crew.GetSize(); ++i){

			if(crew.GetMemberID(i) == memberID){
				type = crew.GetType(memberID);
				break;
			}
		}

		if(crew.SearchID(memberID) == false){
			cout << "Member does not exist." << endl;
		}
		else if(flights.CrewMemberFlights(memberID, type) == 0){
			cout << "Member has no assigned flights." << endl;
		}
		else{

			cout << endl << "Schedule for " << crew.GetName(memberID) << " (" << crew.GetTypeString(memberID) << "): " << endl << endl;
			int numFlights = flights.CrewMemberFlights(memberID, type);
			Flights tempflights;

			for(int i = 0; i < flights.GetFlightCount(); ++i){

					if(type == 'P'){

						if(flights.GetPilotID(i) == memberID){

							tempflights.addTemp(flights.FlightAt(i));

						}
					}

					if(type == 'O'){

						if(flights.GetCoPilotID(i) == memberID){

							tempflights.addTemp(flights.FlightAt(i));
						}

					}

					
					if(type == 'C'){

						for(int j = 0; j < 3; ++j){

							if(flights.GetCabinID(i, j) == memberID){

								tempflights.addTemp(flights.FlightAt(i));
							}

						}

					}
				
				}

			tempflights.ViewAll();
			tempflights.clear();

		}
	}

	else if(selection == 'a'){

		string planeID;
		cout << endl;
		planes.printAll();

		cout << endl << "Plane ID: ";
			cin >> planeID;

		if(planes.SearchID(planeID) == false){
			cout << "Plane does not exist." << endl;
		}
		else if(flights.PlaneFlights(planeID) == 0){
			cout << "Plane has no assigned flights." << endl;
		}
		else{

			cout << endl << "Schedule for Plane " << planeID << ": " << endl << endl;
			Flights tempflights;

				for(int i = 0; i < flights.GetFlightCount(); ++i){

					if(flights.GetPlaneID(i) == planeID){

						tempflights.addTemp(flights.FlightAt(i));
					}
				
				}

			tempflights.ViewAll();
			tempflights.clear();

		}

	}
		
	}

}
void printAllFlights(Flights flights, Planes planes){

	cout << " [                                FLIGHTS                                ]" << endl << endl;

	if(planes.GetSize() == 0){
		cout << "No planes available." << endl;
	}

	else{

		char selection;

		cout << "What flights would you like to view?" << endl
		<< "(a) Active flights" << endl
		<< "(b) Completed flights" << endl
		<< "(c) Cancelled flights" << endl
		<< "(d) All flights" << endl << endl
		<< "Enter your selection: ";
			cin >> selection;
			cout << endl;

		if(selection != 'a' && selection != 'b' && selection != 'c' && selection != 'd'){
			cout << "Invalid selection." << endl;
		}
		else if(selection == 'a'){
			flights.ViewActive();
		}
		else if(selection == 'b'){
			flights.ViewComplete();
		}
		else if(selection == 'c'){
			flights.ViewCancelled();
		}
		else{
			flights.ViewAll();
		}
		cout << endl;

	}

	return;

}

void removeFlight(Flights& flights, Planes planes, Crew crew){

		cout << " [                            REMOVE FLIGHTS                             ]" << endl << endl;

	if(planes.GetSize() == 0){
		cout << "No planes available." << endl;
	}

	else{

		char selection;

		flights.ViewAll();

		cout << endl << "What flights would you like to remove?" << endl
			<< "(a) Cancelled" << endl
			<< "(b) Completed" << endl
			<< "(c) Single (specific)" << endl << endl
			<<"Enter your selection: ";

		cin >> selection;

		if(selection != 'a' && selection != 'b' && selection != 'c'){
			cout << "Invalid selection." << endl;
		}
		else if(selection == 'a'){
			flights.RemoveCancelled();
		}
		else if(selection == 'b'){
			flights.RemoveCompleted();
		}
		else if(selection == 'c'){

			int flightID;

			cout << endl;

			flights.ViewAll();

			cout << endl << "Enter Flight ID# to remove: ";
				cin >> flightID;

			if(flights.FlightSearch(flightID) == false){
				cout << "Flight does not exist." << endl;
			}

			else{

				flights.RemoveSingle(flightID);
				cout << "Flight #" << flightID << " removed." << endl;

			}
		}
		else{
			cout << "Invalid selection." << endl;
		}

	}

}

/************************************************************************************************/
/******************************************** MENUS *********************************************/
/************************************************************************************************/

void FlightMenu(Flights& flights, Planes& planes, Crew& crew){

	char selection;

	do{

		cout << "* * * * * * * * * * * * * * * * FLIGHT MENU * * * * * * * * * * * * * * * " << endl
			<< "a. Add flights" << endl
			<< "b. Edit flights" << endl
			<< "c. Remove flights" << endl
			<< "d. View flight schedule" << endl
			<< "e. View all flights" << endl << endl
			<< "Enter your selection ('m' to return to menu): ";
			cin >> selection;
			selection = tolower(selection);
			cout << endl;

			switch(selection){

				case 'a':

					addFlight(flights, planes, crew);
					break;

				case 'b':

					editFlight(flights, planes, crew);
					break;

				case 'c':

					removeFlight(flights, planes, crew);
					break;

				case 'd':

					printSchedule(flights, planes, crew);
					break;

				case 'e':

					printAllFlights(flights, planes);
					break;

				case 'm':
					break;

				default:
					cout << "Invalid selection." << endl;
					break;

			}

			if(selection != 'm'){
				cout << endl << "Enter any key to return to flight menu, or 'm' to go to the main menu: ";
					cin >> selection;
				cout << endl;
			}


	}while(selection != 'm');

	return;

}

void PlanesMenu(Planes& planes, Crew& crew){

	char selection;

	do{
		cout << "* * * * * * * * * * * * * * * * PLANE MENU * * * * * * * * * * * * * * * *" << endl
			<< "a. Add new plane" << endl
			<< "b. Edit plane information" << endl
			<< "c. Remove a plane" << endl
			<< "d. View plane information" << endl
			<< "e. View all planes" << endl << endl
			<< "Enter your selection ('m' to return to menu): ";
			cin >> selection;
			selection = tolower(selection);
			cout << endl;

			switch(selection){

				case 'a':

					addPlane(planes);
					break;

				case 'b':

					editPlane(planes, crew);
					break;

				case 'c':

					removePlane(planes);
					break;

				case 'd':

					printPlaneInfo(planes);
					break;

				case 'e':

					printAllPlanes(planes);
					break;

				case 'm':
					break;

				default:

					cout << "Invalid selection." << endl;
					break;

			}

			if(selection != 'm'){
				cout << endl << "Enter any key to return to plane menu, or 'm' to go to the main menu: ";
					cin >> selection;
				cout << endl;
			}


	}while(selection != 'm');

	return;

}

void CrewMenu(Crew& crew){

	char selection;

	do{

		cout << "* * * * * * * * * * * * * * * * CREW MENU * * * * * * * * * * * * * * * * " << endl
			<< "a. Add new member" << endl
			<< "b. Edit member information" << endl
			<< "c. Remove a member" << endl
			<< "d. View member information" << endl
			<< "e. View members by type" << endl
			<< "f. View all members" << endl << endl
			<< "Enter your selection ('m' to return to menu): ";
			cin >> selection;
			selection = tolower(selection);
			cout << endl;

			switch(selection){

				case 'a':

					addCrewMember(crew);
					break;

				case 'b':

					editCrewMember(crew);
					break;

				case 'c':

					removeCrewMember(crew);
					break;

				case 'd':

					printMemberInfo(crew);
					break;

				case 'e':

					printMemberType(crew);
					break;

				case 'f':

					printCrew(crew);
					break;

				case 'm':
					break;

				default:

					cout << "Invalid selection." << endl;
					break;

			}

			if(selection != 'm'){
				cout << endl << "Enter any key to return to crew menu, or 'm' to go to the main menu: ";
					cin >> selection;
				cout << endl;
			}

	}while(selection != 'm');

	return;

}

void Save(Flights flights, Planes planes, Crew crew){

	ofstream ofs;
	string filename;

	cout << "Save file as: ";
		cin >> filename;

	ofs.open(filename.c_str());
		if(!ofs){
			cout << "Error accessing database." << endl;
		}

		else{
			flights.save(ofs);
			planes.save(ofs);
			crew.save(ofs);
			cout << "Successfully saved your database." << endl;
		}

	ofs.close();

	return;

}
void Load(Flights& flights, Planes& planes, Crew& crew){

	ifstream ifs;
	string filename;
	char c;

	cout << "Enter file name: ";
		cin >> filename;

	ifs.open(filename.c_str());
		if(!ifs){
			cout << "Error accessing file." << endl;
		}

		else{

			while(ifs >> c){

				if(c == 'f'){

					flights.load(ifs);

				}

				if(c == 'p'){
				
					planes.load(ifs);

				}

				if(c == 'm'){

					crew.load(ifs);
				}

			}

			cout << "Successfully loaded your database." << endl;
			
		}

	ifs.close();

	return;
}