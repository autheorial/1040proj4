#include <fstream>

class Cabin : public CrewMember{
	public:
		void printInfoSingle();
		void printInfoList();
		void setInfo(string last, string first, int ID, char position){
			this->last = last;
			this->first = first;
			this->ID = ID;
			this->position = position;
			type = 'c';
		}
		char GetType(){ return type;};
		void save(ofstream& ofs);
		void load(ifstream& ifs, char c);

	private: 
		char position;
};