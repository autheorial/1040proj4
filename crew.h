#include <vector>
#include "header.h"
#include "member.h"
using namespace std;

class Crew{
	public:
		void add(CrewMember* Member);
		void EditName(int i);
		void EditType(int i);
		void EditStatus(int i);
		void remove(int ID);
		void printAll();
		void printSingle(int ID);
		void printPilots();
		void printCoPilots();
		void printCabin();
		bool SearchID(int searchID);
		bool CheckPilot(int searchID);
		bool CheckCoPilot(int searchID);
		bool CheckCabin(int searchID);
		bool CheckStatus(int searchID);
		string GetName(int ID);
		string GetTypeString(int ID);
		char GetType(int ID);
		int GetMemberID(int i);
		int GetSize(){ return crew.size();};
		void save(ofstream& ofs);
		void load(ifstream& ifs);
	private:
		vector<CrewMember*> crew;
};