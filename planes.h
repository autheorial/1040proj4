#include <vector>
#include "plane.h"
using namespace std;

class Planes{
	public:
		void add(Plane newPlane);
		void EditMake(int i);
		void EditModel(int i);
		void EditSeatCount(int i);
		void EditRange(int i);
		void EditStatus(int i);
		void remove(string ID);
		string GetPlaneID(int i){ return planes.at(i).GetID();};
		bool SearchID(string ID);
		int GetSize(){ return planes.size();};
		int GetPassengerCount(string ID);
		char GetStatus(string ID);
		void printAll();
		void printSingle(string ID);
		void save(ofstream& ofs);
		void load(ifstream& ifs);
	private:
		vector<Plane> planes;
};