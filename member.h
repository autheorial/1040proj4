#include <string>
#include <fstream>
using namespace std;

class CrewMember{
	public:
		CrewMember();
		string GetName();
		int GetID(){ return ID;};
		char GetStatus(){ return status;};
		char GetType(){ return type;};
		void EditName();
		void EditType();
		void EditStatus();
		virtual void printInfoSingle();
		virtual void printInfoList();
		void printInfoMembersList();
		virtual void save(ofstream& ofs);
		virtual void load(ifstream& ifs, char type);
	protected:
		char m;
		char type;
		string last;
		string first;
		int ID;
		char status;
};