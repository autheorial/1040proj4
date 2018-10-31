#include <iostream>
#include "planes.h"

void Planes::add(Plane newPlane){

	planes.push_back(newPlane);

}

void Planes::remove(string ID){

	int i;

	for(i = 0; i < planes.size(); ++i){

		if(planes.at(i).GetID() == ID){

			break;

		}
	}

	planes.erase(planes.begin() + i);
}

bool Planes::SearchID(string searchID){

	bool found = false;

	for(int i = 0; i < planes.size(); ++i){

		if(planes.at(i).GetID() == searchID){

			found = true;
			break;

		}

	}

	if(found == true){
		return true;
	}
	else{
		return false;
	}


}

void Planes::EditMake(int i){
	planes.at(i).EditMake();
}

void Planes::EditModel(int i){
	planes.at(i).EditModel();
}

void Planes::EditSeatCount(int i){
	planes.at(i).EditSeatCount();
}

void Planes::EditRange(int i){
	planes.at(i).EditRange();
}

void Planes::EditStatus(int i){
	planes.at(i).EditStatus();
}

char Planes::GetStatus(string ID){

	int i;

	for(i = 0; i < planes.size(); ++i){

		if(planes.at(i).GetID() == ID){

			break;

		}
	}

	return planes.at(i).GetStatus();

}

int Planes::GetPassengerCount(string ID){

	int i;

	for(i = 0; i < planes.size(); ++i){

		if(planes.at(i).GetID() == ID){

			break;

		}
	}

	return planes.at(i).GetSeats();

}

void Planes::printSingle(string ID){

	int i;

	for(i = 0; i < planes.size(); ++i){

		if(planes.at(i).GetID() == ID){

			break;

		}
	}

	planes.at(i).printInfoSingle();

}

void Planes::printAll(){

	if(planes.size() == 0){
		cout << "No planes available." << endl;
	}

	else{

		cout.width(10); cout << "ID";
		cout.width(25); cout << "MAKE";
		cout.width(10); cout << "MODEL";
		cout.width(10); cout << "SEATS";
		cout.width(10); cout << "RANGE";
		cout.width(10); cout << "STATUS";
		cout << endl;
		for(int i = 0; i < 75; ++i){
			cout << "-";
		}
		cout << endl;
		for(int i = 0; i < planes.size(); ++i){

			planes.at(i).printInfoList();
			
		}

	}
}

void Planes::load(ifstream& ifs){

	Plane newPlane;
	newPlane.load(ifs);
	planes.push_back(newPlane);

	return;
}
void Planes::save(ofstream& ofs){

	for(int i = 0; i < planes.size(); ++i){
		planes.at(i).save(ofs);
	}

	return;
}