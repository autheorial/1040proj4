#include "header.h"
#include "flight.h"
#include "crew.h"
#include "planes.h"
using namespace std;

class Flights{
	public:
		Flights();
		void add(Flight newFlight);
		void addTemp(Flight newFlight);
		void EditStatus(int flightID, Planes planes, Crew crew);
		void EditMultiple(int flightID, Planes planes, Crew crew);
		void RemoveCancelled();
		void RemoveCompleted();
		void RemoveSingle(int flightID);
		int PlaneFlights(string planeID);
		int CrewMemberFlights (int memberID, char type);
		int GetPilotID(int index){ return flights.at(index).GetPilotID();};
		int GetCoPilotID(int index){ return flights.at(index).GetCoPilotID();};
		int GetCabinID(int index, int cabinDex){ return flights.at(index).GetCabinID(cabinDex);};
		string GetPlaneID(int index){ return flights.at(index).GetPlaneID();};
		bool IsMemberID(int memberID, int index);
		bool MemberIDSearch(int memberID, char type);
		bool PlaneSearch(string planeID);
		bool FlightSearch(int flightID);
		void find();
		void printSched();
		void ViewActive();
		void ViewComplete();
		void ViewCancelled();
		void ViewAll();
		void save(ofstream& ofs);
		void load (ifstream& ifs);
		int GetFlightCount(){ return flights.size();}
		Flight FlightAt(int index){ return flights.at(index);}
		Flight GetFlightByMember(int memberID, char type);
		Flight GetFlightByPlane(string planeID);
		void clear(){ flights.clear();}
	private:
		vector<Flight> flights;
		int count;
		int statusCount;
};