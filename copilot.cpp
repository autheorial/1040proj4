#include <iostream>
#include "member.h"
#include "copilot.h"

void CoPilot::printInfoSingle(){

	CrewMember::printInfoSingle();
	
	cout << "Rating: " << rating << endl
	<< "Hours (as co-pilot): " << hours << " hours" << endl;

}

void CoPilot::printInfoList(){

	CrewMember::printInfoList();
	
		cout.width(10); cout << rating;
		cout.width(5); cout << hours;
		cout.width(10); cout << status << endl;

}

void CoPilot::save(ofstream& ofs){

	CrewMember::save(ofs);
	ofs << rating << "\t" << hours << "\t" << endl;

}

void CoPilot::load(ifstream& ifs, char c){

	CrewMember::load(ifs, c);
	ifs >> rating >> hours;
}