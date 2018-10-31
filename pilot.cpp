#include <iostream>
#include "member.h"
#include "pilot.h"

void Pilot::printInfoSingle(){

	CrewMember::printInfoSingle();
	
	cout << "Rating: " << rating << endl
	<< "Hours (as pilot): " << hours << " hours" << endl;

}

void Pilot::printInfoList(){

	CrewMember::printInfoList();
		cout.width(10); cout << rating;
		cout.width(5); cout << hours;
		cout.width(10); cout << status << endl;

}

void Pilot::save(ofstream& ofs){

	CrewMember::save(ofs);
	ofs << rating << "\t" << hours << "\t" << endl;

}

void Pilot::load(ifstream& ifs, char c){

	CrewMember::load(ifs, c);
	ifs >> rating >> hours;
}