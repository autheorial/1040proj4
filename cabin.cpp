#include <iostream>
#include "member.h"
#include "cabin.h"

void Cabin::printInfoSingle(){
	
	CrewMember::printInfoSingle();
	cout << "Position: ";

	if(position == 'b'){
		cout << "Business" << endl;
	}

	if(position == 'f'){
		cout << "First Class" << endl;
	}

	if(position == 'e'){
		cout << "Economy (front)" << endl;
	}

	if(position == 'r'){
		cout << "Economy (rear)" << endl;
	}

	if(position == 'l'){
		cout << "Lead" << endl;
	}

}

void Cabin::printInfoList(){
	
	CrewMember::printInfoList();
		cout.width(15); 

		if(position == 'b'){
			cout << "Business";
		}
		else if(position == 'f'){
			cout << "First Class";
		}
		else if(position == 'e'){
			cout << "Economy (front)";
		}
		else if(position == 'r'){
			cout << "Economy (rear)";
		}
		else if(position == 'l'){
			cout << "Lead";
		}

		cout.width(10); cout << status << endl;

}

void Cabin::save(ofstream& ofs){

	CrewMember::save(ofs);
	ofs << "\t" << position << endl;

}

void Cabin::load(ifstream& ifs, char c){

	CrewMember::load(ifs, c);
	ifs >> position;
}