#include "flight.h"

Flight::Flight(){
	flightID = 500000;
	f = 'f';
	status = 'A';
	passengerCount = 0;
	start = new tm;
	end = new tm;
}

int Flight::GetCabinID(int index){
	return crew.at(index);
}

void Flight::SetFlightID(int count){
	flightID = flightID + count;
}

void Flight::SetPlaneID(string planeID){
	this->planeID = planeID;
}

void Flight::SetDate(tm* start, tm* end){
	this->start = start;
	this->end = end;
}

void Flight::SetPassengerCount(int passengers){
	this->passengerCount = passengers;
}

void Flight::SetStartPort(){

	cout << "Enter starting airport code: ";
		cin >> startPort;

	int length = startPort.length();

	for(int i = 0; i < length; ++i){
		startPort.at(i) = toupper(startPort.at(i));
	}

}

void Flight::SetEndPort(){

	cout << "Enter ending airport code: ";
		cin >> endPort;

	int length = endPort.length();

	for(int i = 0; i < length; ++i){
		endPort.at(i) = toupper(endPort.at(i));
	}


}

void Flight::SetPilot(int pilotID){

	this->pilotID = pilotID;
	
}

void Flight::SetCoPilot(int copilotID){
	this->copilotID = copilotID;
}

void Flight::SetCabin(vector<int> crew){
	this->crew = crew;
}

void Flight::SetStatus(char newStatus){
	this->status = newStatus;
}

void Flight::printInfoList(){

	cout.width(10); cout << flightID;
	cout.width(10); cout << planeID;
	cout.width(8); cout << " ";
	cout.width(2); cout << start->tm_mon;
	cout.width(3); cout << start->tm_mday;
	cout.width(5); cout << start->tm_year;
	cout.width(3); cout << " ";
	cout.fill('0');
	cout.width(2); cout << start->tm_hour;
	cout << ":";
	cout.width(2); cout << start->tm_min;
	cout.fill(' ');
	cout.width(6); cout << " ";
	cout.width(3); cout << end->tm_mon;
	cout.width(3); cout << end->tm_mday;
	cout.width(5); cout << end->tm_year;
	cout.width(3); cout << " ";
	cout.fill('0');
	cout.width(2); cout << end->tm_hour;
	cout << ":";
	cout.width(2); cout << end->tm_min;
	cout.fill(' ');
	cout.width(10); cout << startPort;
	cout.width(10); cout << endPort;
	cout.width(15); cout << passengerCount;

	if(status == 'A'){
		cout.width(15); cout << "AVAILABLE";
	}
	if(status =='C'){
		cout.width(15); cout << "CANCELLED";
	}
	if(status =='F'){
		cout.width(15); cout << "COMPLETED";
	}

	cout << endl;

}

void Flight::printInfoSingle(){

	cout << "Flight ID: " << flightID << endl
	<< "Status: ";
	if(status == 'A'){
		cout << "AVAILABLE";
	}
	if(status =='C'){
		cout << "CANCELLED";
	}
	if(status =='F'){
		cout << "COMPLETED";
	}

	cout << endl
	<< "# of Passengers: " << passengerCount << endl
	<< "Departure: " << startPort << " " << start->tm_mon << "/" << start->tm_mday << "/" << start->tm_year << " " << start->tm_hour << ":" << start->tm_min << endl
	<< "Arrival: " << endPort << " " << end->tm_mon << "/" << end->tm_mday << "/" << end->tm_year << " " << end->tm_hour << ":" << end->tm_min << endl
	<< "Pilot ID#: " << pilotID << endl
	<< "Co-Pilot ID$: " << copilotID << endl;

	for(unsigned int i = 0; i < crew.size(); ++i){
		cout << "Cabin Member ID #" << i + 1 << ": " << crew.at(i) << endl;
	}

}

void Flight::save(ofstream& ofs){

	ofs.width(5); ofs << f;
	ofs.width(10); ofs << flightID;
	ofs.width(15); ofs << planeID;
	ofs.width(15); ofs << pilotID;
	ofs.width(15); ofs << copilotID;
	ofs.width(3); ofs << crew.size();

	for(int i = 0; i < crew.size(); ++i){
		ofs.width(15); ofs << crew.at(i);
	}

	ofs.width(5); ofs << start->tm_mon;
	ofs.width(5); ofs << start->tm_mday;
	ofs.width(5); ofs << start->tm_year;
	ofs.width(5); ofs << start->tm_hour;
	ofs.width(5); ofs << start->tm_min;
	ofs.width(5); ofs << end->tm_mon;
	ofs.width(5); ofs << end->tm_mday;
	ofs.width(5); ofs << end->tm_year;
	ofs.width(5); ofs << end->tm_hour;
	ofs.width(5); ofs << end->tm_min;
	ofs.width(10); ofs << startPort;
	ofs.width(10); ofs << endPort;
	ofs.width(5); ofs << passengerCount;
	ofs.width(5); ofs << status;
	ofs << endl;

}

void Flight::load(ifstream& ifs){

	int crewSize;
	int temp;

	ifs >> flightID >> planeID >> pilotID >> copilotID >> crewSize;

	for (int i = 0; i < crewSize; ++i){
		ifs >> temp;
		crew.push_back(temp);
	}

	ifs >> start->tm_mon >> start->tm_mday >> start->tm_year >> start->tm_hour >> start->tm_min
		>> end->tm_mon >> end->tm_mday >> end->tm_year >> end->tm_hour >> end->tm_min
		>> startPort >> endPort >> passengerCount >> status;

}