#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flight{
public:
	int flightNum;
	int flightTime;
	string originCode;
	string destCode;
}

template <class T, class U>
vector<T> find(vector<T>& flights, U functor, T targetFlight){
   vector<T> fVec;
   for (T aFlight : flights)
       if (functor(aFlight, targetFlight))
           fVec.push_back(aFlight);
   return fVec;
}

class equalByDeparture{
public:
   bool operator()(Flight flight1, Flight flight2){
       if (flight1.departureCity == flight2.departureCity)
           return true;
       return false;
   }
};

class equalByDestination{
public:
   bool operator()(Flight flight1, Flight flight2){
       if (flight1.originCode == flight2.destCode)
           return true;
       return false;
   }
};

void maxOutdegree(vector<Flight>flights){
   int max = 0;
   string retFlight;
   equalByDeparture functor;
   for (Flight f : flights){
       vector<Flight> v = find(flights, functor, f);
       if (v.size() > max){
           max = v.size();
           retFlight = f.originCode;
       }
   }
   cout << "The city with the maximum outdegree is " << retFlight << ", with " << max << " departures." << endl;
}

If (vec.size > max)
		Max = vec.size
		City = f.depart	

int main(){
    vector<Flight>flights;
    ifstream ifs("HW3Data.txt");
	if (!ifs){
		cerr << "File could not be opened!" << endl;
		exit(1);
	}
    int flightNumber;
    string originCity;
    string destCity;
    int flightDuration;
    while (ifs >> flightNumber >> originCity >> destCity >> flightDuration){
        Flight newFlight;
        newFlight.flightNumber = flightNumber;
        newFlight.originCity = originCity;
        newFlight.destCity = destCity;
        newFlight.flightDuration = flightDuration;
        flights.push_back(newFlight);
    }
    maxOutdegree(flights);
}