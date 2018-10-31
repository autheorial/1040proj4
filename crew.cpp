#include "crew.h"
#include "pilot.h"
#include "copilot.h"
#include "cabin.h"

void Crew::add(CrewMember* Member){

	crew.push_back(Member);

}

void Crew::EditName(int i){
	crew.at(i)->EditName();
}


void Crew::EditType(int i){
	crew.at(i)->EditType();

}


void Crew::EditStatus(int i){
	crew.at(i)->EditStatus();

}

bool Crew::SearchID(int searchID){

	bool found = false;

	for(int i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == searchID){

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

bool Crew::CheckPilot(int searchID){

	bool found = false;

	for(int i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == searchID){

			if(crew.at(i)->GetType() == 'P'){
				found = true;
				break;
			}
		}
	}

	if(found == true){
		return true;
	}
	else{
		return false;
	}
}

bool Crew::CheckCoPilot(int searchID){

	bool found = false;

	for(int i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == searchID){

			if(crew.at(i)->GetType() == 'O'){
				found = true;
				break;
			}
		}
	}

	if(found == true){
		return true;
	}
	else{
		return false;
	}

}

bool Crew::CheckCabin(int searchID){

	bool found = false;

	for(int i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == searchID){

			if(crew.at(i)->GetType() == 'C'){
				found = true;
				break;
			}
		}
	}

	if(found == true){
		return true;
	}
	else{
		return false;
	}
}

bool Crew::CheckStatus(int searchID){

	bool available = true;

	for(int i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == searchID){

			if(crew.at(i)->GetStatus() != 'H'){
				available = false;
				break;
			}
		}
	}

	if(available == true){
		return true;
	}
	else{
		return false;
	}
}

int Crew::GetMemberID(int i){

	return crew.at(i)->GetID();
	
}

string Crew::GetName(int memberID){

	int i;

	for(i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == memberID){
			break;
		}
	}

	return crew.at(i)->GetName();

}

char Crew::GetType(int memberID){

	int i;

	for(i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == memberID){
			break;
		}
	}

	return crew.at(i)->GetType();

}

string Crew::GetTypeString(int memberID){

	int i;

	for(i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == memberID){
			break;
		}
	}

	if(crew.at(i)->GetType() == 'P'){
		return "PILOT";
	}
	else if(crew.at(i)->GetType() == 'O'){
		return "COPILOT";
	}
	else{
		return "CABIN";
	}
}

void Crew::remove(int ID){

	int i;

	for(i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == ID){

			break;

		}
	}

	crew.erase(crew.begin() + i);

}

void Crew::printSingle(int ID){

	int i;

	for(i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetID() == ID){

			break;

		}
	}

	crew.at(i)->printInfoSingle();

}

void Crew::printAll(){

	for(int i = 0; i < crew.size(); ++i){

		crew.at(i)->printInfoMembersList();
	}
}

void Crew::printPilots(){

	int count = 0;

	for(int i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetType() == 'i'){

			++count;
			crew.at(i)->printInfoList();
		}

	}

	if(count == 0){

		cout << "No pilots available." << endl << endl;
	}

}

void Crew::printCoPilots(){

	int count = 0;

	for(int i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetType() == 'o'){

			++count;
			crew.at(i)->printInfoList();
		}

	}

	if(count == 0){

		cout << "No copilots available." << endl << endl;
	}

}

void Crew::printCabin(){

	int count = 0;

	for(int i = 0; i < crew.size(); ++i){

		if(crew.at(i)->GetType() == 'c'){

			++count;
			crew.at(i)->printInfoList();
		}

	}

	if(count == 0){

		cout << "No cabin members available." << endl << endl;
	}

}

void Crew::load(ifstream& ifs){

	char type;

	ifs >> type;
	cout << type;

	if(type == 'i'){

		Pilot* newPilot = new Pilot;
		newPilot->load(ifs, type);
		crew.push_back(newPilot);
		delete newPilot;
	}

	if(type == 'o'){

		CoPilot* newCoPilot = new CoPilot;
		newCoPilot->load(ifs, type);
		crew.push_back(newCoPilot);
		delete newCoPilot;

	}

	if(type == 'c'){

		Cabin* newCabin = new Cabin;
		newCabin->load(ifs, type);
		crew.push_back(newCabin);
		delete newCabin;
	
	}

}

void Crew::save(ofstream& ofs){

	for(unsigned int i = 0; i < crew.size(); ++i){

		crew.at(i)->save(ofs);

	}

	return;
}