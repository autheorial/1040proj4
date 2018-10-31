#include <fstream>

class CoPilot : public CrewMember{
	public:
		void printInfoSingle();
		void printInfoList();
		void setInfo (string last, string first, int ID, char* rating, int hours){
			this->last = last;
			this->first = first;
			this->ID = ID;
			this->rating = rating;
			this->hours = hours;
			type = 'o';
		}
		void save(ofstream& ofs);
		void load(ifstream& ifs, char c);

	private:
		string rating;
		int hours;
};
