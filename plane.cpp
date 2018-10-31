#include <iostream>
#include "plane.h"

Plane::Plane(){
	
	ID = "none";
	make = "none";
	model = 0;
	seatCount = 0;
	range = 0;
	status = 'I';
	p = 'p';

}

void Plane::setInfo(string ID, string make, int model, int seatCount, int range, char status){

	this->ID = ID;
	this->make = make;
	this->model = model;
	this->seatCount = seatCount;
	this->range = range;
	this->status = status;

}

void Plane::EditMake(){

	cout << "Current make: " << make << endl
		<< "New make: ";
		cin.ignore();
		getline(cin, make);

		return;

}

void Plane::EditModel(){

	cout << "Current model: " << model << endl
		<< "New model: ";
		cin >> model;
		return;
}

void Plane::EditSeatCount(){

	cout << "Current seat count: " << seatCount << endl
	<< "New seat count: ";
		cin >> seatCount;

	return;

}

void Plane::EditRange(){

	cout << "Current range: " << range << endl
	<< "New range: ";
		cin >> range;

	return;
}

void Plane::EditStatus(){

	bool validStatus = false;

	cout << "Current status: ";

	if(status == 'I'){
		cout << "In" << endl;
	}
	else if(status == 'R'){
		cout << "Repair" << endl;
	}
	else{
		cout << "Out" << endl;
	}
	do{

		cout << "New type (I = in, O = out, R = repair): ";
		cin >> status;

		status = toupper(status);

		if(status != 'I' && status != 'O' && status != 'R'){

				cout << "Invalid status." << endl;

			}

		else{

			validStatus = true;
		}

	}while(validStatus == false);

}

void Plane::printInfoSingle(){

	cout << "ID: " << ID << endl
		<< "Make: " << make << endl
		<< "Model: " << model << endl
		<< "Seat Count: " << seatCount << endl
		<< "Range (in miles): " << range << endl
		<< "Status: ";

	if(status == 'I'){
		cout << "In" << endl;
	}
	else if(status == 'R'){
		cout << "Repair" << endl;
	}
	else{
		cout << "Out" << endl;
	}
	cout << endl;
}

void Plane::printInfoList(){

	cout.width(10); cout << ID;
	cout.width(25); cout << make;
	cout.width(10); cout << model;
	cout.width(10); cout << seatCount;
	cout.width(10); cout << range;
	cout.width(10); 
	if(status == 'I'){
		cout << "In" << endl;
	}
	else if(status == 'R'){
		cout << "Repair" << endl;
	}
	else{
		cout << "Out" << endl;
	}

}

void Plane::save(ofstream& ofs){

	ofs << p << "\t" << ID << "\t" << make << "\t" << model << "\t" << seatCount << "\t" << range << "\t" << status << endl;

}

void Plane::load(ifstream& ifs){

	char* planeMake = new char[20];

	ifs >> ID;
	ifs.ignore();
	getline(ifs, make, '\t');
	ifs >> model >> seatCount >> range >> status;
}