/********************************************************************
Name: Alice Zhu (alicezhu@my.unt.edu)
Date: 23 June 2018
Description: Program for airline, with user able to input plane, 
crew members, and flight information. All information can be saved
and then loaded again.
*********************************************************************/

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class CrewMember;
class Crew;
class Plane;
class Planes;
class Flight;
class Flights;

void printCrew(Crew crew);
void printAllPlanes(Planes planes);
void printFlights(Flights flights);