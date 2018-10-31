#include <string>
#include <fstream>
using namespace std;

class Plane{
	public:
		Plane();
		string GetID(){ return ID;};
		char GetStatus(){ return status;};
		int GetSeats(){ return seatCount;};
		void setInfo(string ID, string make, int model, int seatCount, int range, char status);
		void EditMake();
		void EditModel();
		void EditSeatCount();
		void EditRange();
		void EditStatus();
		void printInfoSingle();
		void printInfoList();
		void save(ofstream& ofs);
		void load(ifstream& ifs);
	private:
		char p;
		string ID; // aka tail number
		string make;
		int model;
		int seatCount;
		int range;
		char status;

};