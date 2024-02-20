// Michael Sexton
// Question 2, 3, 

#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
using namespace std;

using flightdistances = unordered_map<string, int>; // Container for Question 2
using airportmap = unordered_map<string, flightdistances>; // Container for Question 2

// Class Plane is for Question 3
class Plane {
private:
    double pos; double vel; double distance;
    bool at_SCE;
    string origin; string destination;
    airportmap flightdistance;
public:
    Plane(const string& from, const string& to);
    ~Plane();
    void operate(double dt);
    double getpos() const;
    double getvel() const;
    void setvel(double velocity);
    string getorigin() const;
    string getdestingation() const;
    bool getatSCE() const;
};

int main()
{
    // Question 2:

    airportmap flightdistance;

    // Setting distances for each flight possibility
    flightdistance["SCE"] = { {"PHL", 160}, {"ORD", 640}, {"EWR", 220} };
    flightdistance["PHL"] = { {"SCE", 160} };
    flightdistance["ORD"] = { {"SCE", 640} };
    flightdistance["EWR"] = { {"SCE", 220} };

    return 0;
}