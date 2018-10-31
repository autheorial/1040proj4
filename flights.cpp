#include "flights.h"

Flights::Flights(){
	count = 0;
}

void Flights::ViewAll(){

	if(flights.size() == 0){
		cout << "No flights available." << endl;
	}
	else{

		cout << "You are viewing ALL flights: " << endl << endl;

	cout.width(10); cout << "FLIGHT ID";
	cout.width(10); cout << "PLANE#";

	cout.width(18); cout << "DEPARTURE DATE";
	
	cout.width(8); cout << "TIME";
	cout.width(5); cout << " ";
	cout.width(11); cout << "ARRIVAL DATE";
	cout.width(8); cout << "TIME";

	cout.width(10); cout << "FROM";
	cout.width(10); cout << "TO";
	cout.width(15); cout << "PASSENGERS";
	cout.width(15); cout << "STATUS";
	cout << endl;

	for (int i = 0; i < 121; ++i){
		cout << "-";
	}
	cout << endl;

		for(int i = 0; i < flights.size(); ++i){

			flights.at(i).printInfoList();

		}
	}
}

void Flights::add(Flight newFlight){

	newFlight.SetFlightID(count);
	flights.push_back(newFlight);
	++count;
}

void Flights::addTemp(Flight newFlight){

	flights.push_back(newFlight);
	
}

void Flights::EditStatus(int flightID, Planes planes, Crew crew){

	int i;
	char newStatus;

	for(i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetFlightID() == flightID){

			break;

		}
	}

	cout << "Current Status: ";

	if(flights.at(i).GetStatus() == 'A'){
		cout << "ACTIVE";
	}
	else if(flights.at(i).GetStatus() == 'C'){
		cout << "CANCELLED";
	}
	else if(flights.at(i).GetStatus() == 'F'){
		cout << "FINISHED";
	}

	do{

		cout << endl << "New Status (A = Active, C = Cancelled, F = Finish): ";
			cin >> newStatus;

		newStatus = toupper(newStatus);

		if(newStatus != 'A' && newStatus != 'C' && newStatus != 'F'){

			cout << "Invalid status" << endl;
		}

	}while(newStatus != 'A' && newStatus != 'C' && newStatus != 'F');

	flights.at(i).SetStatus(newStatus);

	return;
}

void Flights::EditMultiple(int flightID, Planes planes, Crew crew){

	int i;
	char selection;
	vector<int> temp(3);
	string newPlane;

	for(i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetFlightID() == flightID){

			break;
		}

	}

	cout << endl;
	flights.at(i).printInfoSingle();

	cout << endl << "What would you like to edit?" << endl << endl
		<< "(a) Times" << endl
		<< "(b) Arrival/Departure Ports" << endl
		<< "(c) Number of Passengers" << endl
		<< "(d) Pilot/Co-Pilot" << endl
		<< "(e) Cabin" << endl
		<< "(f) Plane" << endl << endl
		<< "Enter your selection: ";
			cin >> selection;

	struct tm* start = new tm;
	struct tm* end = new tm;

	switch(selection){

		case 'a':

			int month;

			cout << "NEW DEPARTURE" << endl;

			cout << "Month (1 = January to 12 = December): ";
				cin >> month;
				start->tm_mon = month;

			cout << "Day (1 to 31): ";
				cin >> start->tm_mday;

			cout << "Year: ";
				cin >> start->tm_year;

			cout << "Time (hour, 0 to 24): ";
				cin >> start->tm_hour;

			cout << "Time (mins): ";
				cin >> start->tm_min;

			cout << endl << "NEW ARRIVAL TIME" << endl;

			cout << "Month (1 = January to 12 = December): ";
				cin >> month;
				end->tm_mon = month;

			cout << "Day (1 to 31): ";
				cin >> end->tm_mday;

			cout << "Year: ";
				cin >> end->tm_year;

			cout << "Time (hour, 0 to 24): ";
				cin >> end->tm_hour;

			cout << "Time (mins): ";
				cin >> end->tm_min;

			cout << endl;

			flights.at(i).SetDate(start, end);
			break;

		case 'b':

			flights.at(i).SetStartPort();
			flights.at(i).SetEndPort();
			break;

		case 'c':

			int passengers;
			cout << "New # of passengers: ";
				cin >> passengers;
			flights.at(i).SetPassengerCount(passengers);
			break;

		case 'd':

			crew.printAll();

			int pilotID;
			cout << "Current Pilot ID#: " << flights.at(i).GetPilotID() << endl
			<< "New Pilot ID#: ";
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

					flights.at(i).SetPilot(pilotID);
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

						flights.at(i).SetCoPilot(copilotID);

					}

				}

				break;

		case 'e':

			int j;
			j = 0;

			printCrew(crew);

			bool validCabin;
			validCabin = true;

				while(j < 3){

					cout << "Cabin Member #" << j + 1 << " ID: ";
						cin >> temp.at(i);

					if(crew.SearchID(temp.at(i)) == false){
						cout << "Crew member does not exist." << endl;
					}

					else if(crew.CheckStatus(temp.at(i)) == false){
						cout << "Crew member is not available for this flight." << endl;
					}

					else if(crew.CheckCabin(temp.at(i) == false)){
						cout << "Crew member is not authorized for this position." << endl;
					}

					else{
						++j;
					}

				}

					flights.at(i).SetCabin(temp);

					temp.clear();
					break;

		case 'f':

			printAllPlanes(planes);

				cout << "New plane ID: ";
					cin >> newPlane;

				flights.at(i).SetPlaneID(newPlane);

			break;

		default:

			cout << "Invalid selection." << endl;
			break;


	}

	return;

}

void Flights::ViewActive(){

	int statusCount = 0;

	for(int i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetStatus() == 'A'){

			++statusCount;

		}
	}

	if(flights.size() == 0 || statusCount == 0){
		cout << "No flights available." << endl;
	}

	else{

		cout << "You are viewing all ACTIVE flights: " << endl << endl;

		cout.width(10); cout << "FLIGHT ID";
		cout.width(10); cout << "PLANE#";

		cout.width(18); cout << "DEPARTURE DATE";
		
		cout.width(8); cout << "TIME";
		cout.width(5); cout << " ";
		cout.width(11); cout << "ARRIVAL DATE";
		cout.width(8); cout << "TIME";

		cout.width(10); cout << "FROM";
		cout.width(10); cout << "TO";
		cout.width(15); cout << "PASSENGERS";
		cout.width(15); cout << "STATUS";
		cout << endl;

		for(int i = 0; i < 121; ++i){
			cout << "-";
		}

		cout << endl;

		for(int i = 0; i < flights.size(); ++i){

			if(flights.at(i).GetStatus() == 'A'){

				flights.at(i).printInfoList();

			}

		}

	}

	return;
}

void Flights::ViewComplete(){

	int statusCount = 0;

	for(int i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetStatus() == 'F'){

			++statusCount;

		}
	}

	if(flights.size() == 0 || statusCount == 0){
		cout << "No flights available." << endl;
	}

	else{

		cout << "You are viewing all COMPLETED flights: " << endl << endl;

		cout.width(10); cout << "FLIGHT ID";
		cout.width(10); cout << "PLANE#";

		cout.width(18); cout << "DEPARTURE DATE";
		
		cout.width(8); cout << "TIME";
		cout.width(5); cout << " ";
		cout.width(11); cout << "ARRIVAL DATE";
		cout.width(8); cout << "TIME";

		cout.width(10); cout << "FROM";
		cout.width(10); cout << "TO";
		cout.width(15); cout << "PASSENGERS";
		cout.width(15); cout << "STATUS";
		cout << endl;

		for (int i = 0; i < 121; ++i){
			cout << "-";
		}
		cout << endl;

		for(int i = 0; i < flights.size(); ++i){

			if(flights.at(i).GetStatus() == 'F'){

				flights.at(i).printInfoList();

			}

		}

	}

	return;
}

void Flights::ViewCancelled(){

	int statusCount = 0;

	for(int i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetStatus() == 'C'){

			++statusCount;

		}
	}

	if(flights.size() == 0 || statusCount == 0){
		cout << "No flights available." << endl;
	}

	else{

		cout << "You are viewing all " << statusCount << " CANCELLED flights: " << endl << endl;

		cout.width(10); cout << "FLIGHT ID";
		cout.width(10); cout << "PLANE#";

		cout.width(18); cout << "DEPARTURE DATE";
		
		cout.width(8); cout << "TIME";
		cout.width(5); cout << " ";
		cout.width(11); cout << "ARRIVAL DATE";
		cout.width(8); cout << "TIME";

		cout.width(10); cout << "FROM";
		cout.width(10); cout << "TO";
		cout.width(15); cout << "PASSENGERS";
		cout.width(15); cout << "STATUS";
		cout << endl;

		for (int i = 0; i < 105; ++i){
			cout << "-";
		}
		cout << endl;

		for(int i = 0; i < flights.size(); ++i){

			if(flights.at(i).GetStatus() == 'C'){

				flights.at(i).printInfoList();

			}

		}

	}

	return;
}

void Flights::RemoveCancelled(){
	
	for(int i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetStatus() == 'C'){

			flights.erase(flights.begin() + i);

		}

	}

	return;
}

void Flights::RemoveCompleted(){
	
	for(int i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetStatus() == 'F'){

			flights.erase(flights.begin() + i);

		}

	}

	return;
}

void Flights::RemoveSingle(int flightID){
	
	for(int i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetFlightID() == flightID){

			flights.erase(flights.begin() + i);
		}
	}

	return;
}

int Flights::CrewMemberFlights(int memberID, char type){

	int numFlights = 0;

	for(int i = 0; i < flights.size(); ++i){

		if(type == 'P'){

			if(flights.at(i).GetPilotID() == memberID){
			++numFlights;
			}

		}

		if(type == 'O'){

			if(flights.at(i).GetCoPilotID() == memberID){
			++numFlights;
			}

		}

		if(type == 'C'){

			for (int j = 0; j < 3; ++j){

				if(flights.at(i).GetCabinID(j) == memberID){
					++numFlights;
				}
			}

		}

	}

	return numFlights;

}

int Flights::PlaneFlights(string planeID){

	int numFlights = 0;

	for(int i = 0; i < flights.size(); ++i){

		if(flights.at(i).GetPlaneID() == planeID){

			++numFlights;

		}
	}

	return numFlights;
}

bool Flights::IsMemberID(int memberID, int index){

	bool found = false;

	if(flights.at(index).GetPilotID() == memberID){
		found = true;
	}
	else if (flights.at(index).GetPilotID() == memberID){
		found = true;
	}
	else{

		for(int i = 0; i < 3; ++i){

			if(flights.at(index).GetCabinID(i) == memberID){
				found = true;
				break;
			}
		}


	}

	return found;


}

bool Flights::MemberIDSearch(int memberID, char type){

	int numFlights = 0;
	bool found = false;

	for(int i = 0; i < flights.size(); ++i){

		if(type == 'P'){

			if(flights.at(i).GetPilotID() == memberID){
			found = true;
			break;
			}

		}

		if(type == 'O'){

			if(flights.at(i).GetCoPilotID() == memberID){
			found = true;
			break;
			}

		}

		if(type == 'C'){

			for (int j = 0; j < 3; ++j){

				if(flights.at(i).GetCabinID(j) == true){
					found = true;
					break;
				}
			}

		}

	}

	return found;

}

bool Flights::PlaneSearch(string planeID){

	bool found = false;

	for(int i = 0; i < flights.size(); ++i){

		if (flights.at(i).GetPlaneID() == planeID){
			found = true;
			break;
		}
	}

	return found;

}

bool Flights::FlightSearch(int flightID){

	bool found = false;

	for(int i = 0; i < flights.size(); ++i){

		if (flights.at(i).GetFlightID() == flightID){
			found = true;
			break;
		}
	}

	return found;

}

Flight Flights::GetFlightByMember(int memberID, char type){

	unsigned int i;

	for(i = 0; i < flights.size(); ++i){

		if(type == 'P'){

			if(flights.at(i).GetPilotID() == memberID){
			break;
			}

		}

		if(type == 'O'){

			if(flights.at(i).GetCoPilotID() == memberID){
			break;
			}

		}

		if(type == 'C'){

			for (int j = 0; j < 3; ++j){

				if(flights.at(i).GetCabinID(j) == true){
					break;
				}
			}

		}

	}

	return flights.at(i);


}

Flight Flights::GetFlightByPlane(string planeID){

	int i;

	for(i = 0; i < flights.size(); ++i){

		if (flights.at(i).GetPlaneID() == planeID){
			break;
		}
	}

	return flights.at(i);

}


void Flights::load(ifstream& ifs){

	Flight newFlight;
	newFlight.load(ifs);
	flights.push_back(newFlight);
	++count;

	return;
}

void Flights::save(ofstream& ofs){
	
	for(int i = 0; i < flights.size(); ++i){

		flights.at(i).save(ofs);
	}

	return;
}
