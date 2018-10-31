#include "header.h"
#include <string>
#include <fstream>
using namespace std;

class Flight{
	public:
		Flight();
		Flight(string planeID, int pilotID, int copilotID, string startPort, string endPort, char status);
		int GetFlightID(){ return flightID;};
		string GetPlaneID(){return planeID;};
		int GetPilotID(){return pilotID;};
		int GetCoPilotID(){return copilotID;};
		int GetCabinID(int index);
		tm* GetStartTime(){ return start;};
		tm* GetEndTime(){ return end;};
		string GetStartPort(){ return startPort;};
		string GetEndPort(){ return endPort;};
		int GetPassengerCount(){ return passengerCount;};
		char GetStatus(){ return status;};
		void SetFlightID(int count);
		void SetPlaneID(string planeID);
		void SetDate(tm* start, tm* end);
		void SetStartPort();
		void SetEndPort();
		void SetPilot(int pilotID);
		void SetCoPilot(int copilotID);
		void SetCabin(vector<int> crew);
		void SetPassengerCount(int passengers);
		void SetStatus(char status);
		void printInfoList();
		void printInfoSingle();
		void save(ofstream& ofs);
		void load(ifstream& ifs);
	private:
		char f;
		int flightID;
		string planeID;
		int pilotID;
		int copilotID;
		vector<int> crew;
		tm *start;
		tm *end;
		string startPort;
		string endPort;
		int passengerCount;
		char status;

};