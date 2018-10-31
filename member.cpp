#include <iostream>
#include "member.h"

CrewMember::CrewMember(){
	
	last = "none";
	first = "none";
	ID = 0;
	status = 'H'; // h = healthy
	type = 'x';
	m = 'm';
	
}

string CrewMember::GetName(){

	string fullname = first + " " + last;

	return fullname;
}

void CrewMember::EditName(){

	cout << "Current Name: " << first << " " << last << endl;
	cout << "New last name: ";
	cin.ignore();
		getline(cin, last);

	last[0] = toupper(last[0]);

	cout << "New first name: ";
		getline(cin, first);

	first[0] = toupper(first[0]);
	return;

}

void CrewMember::EditType(){

	bool validType = false;

	cout << "Current Type: ";

		if (type == 'P'){

			cout << "Pilot" << endl;
		}

		else if (type == 'O'){

			cout << "Co-Pilot" << endl;
		}

		else{
			cout << "Cabin" << endl;
		}

	do{

		cout << "New type (i = pilot, o = copilot, c = cabin): ";
		cin >> type;

		type = toupper(type);

		if(type != 'i' && type != 'o' && type != 'c'){

				cout << "Invalid member type." << endl;
			}

		else{

			validType = true;
		}

	}while(validType == false);

}

void CrewMember::EditStatus(){

	bool validStatus = false;

	cout << "Current Status: ";

		if (status == 'L'){

			cout << "On Leave" << endl;
		}

		else if (status == 'S'){

			cout << "Sick" << endl;

		}

		else{

			cout << "Healthy" << endl;

		}

	do{

		cout << "New status (H = healthy, L = on leave, S = sick): ";
			cin >> status;

		status = toupper(status);

		if(status != 'H' && status != 'L' && status != 'S'){

			cout << "Invalid member status." << endl;
		}

		else{
			validStatus = true;
		}

	} while(validStatus == false);

}

void CrewMember::printInfoSingle(){

	cout << "Name: " << first << " " << last << endl
	<< "ID: "  << ID << endl
	<< "Status: " << status << endl;

	return;
}

void CrewMember::printInfoList(){

	cout.width(10); cout << ID;
		cout.width(20); cout << last;
		cout.width(20); cout << first;
}

void CrewMember::printInfoMembersList(){

	cout.width(10); cout << ID;
	cout.width(20); cout << last;
	cout.width(20); cout << first;
	cout.width(15);

	if(type == 'i'){
		cout << "Pilot";
	}
	else if(type == 'o'){
		cout << "Co-Pilot";
	}
	else{
		cout << "Cabin";
	}

	cout.width(10); cout << status << endl;

}

void CrewMember::save(ofstream& ofs){

	ofs << m << '\t' << type << '\t' << ID << '\t' << last << '\t' << first << '\t' << status << '\t';

}

void CrewMember::load(ifstream& ifs, char type){

	cout << type << endl;

	this->type = type;

	ifs >> ID;
	ifs.ignore();
	getline(ifs, last, '\t');
	getline(ifs, first, '\t');
	ifs >> status;

	return;

}