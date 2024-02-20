// Michael Sexton
// Questions 2, 3, 4, 5

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
    Plane(const string& from, const string& to) {
        distance = flightdistance[from][to];
        pos = 0; vel = 0; at_SCE = 0;
        cout << "Plane Created at " << this << endl;
    }
    ~Plane() {
        cout << "Plane Destroyed" << endl;
    }
    void operate(double dt);
    double getpos() const;
    double getvel() const;
    void setvel(double velocity);
    string getorigin() const;
    string getdestination() const;
    bool getatSCE() const;
};

void Plane::operate(double dt) {
    string dummy;
    if (pos < distance) {
        pos += vel * dt;
        at_SCE = 0;
    }
    else {
        if (destination == "SCE") {
            at_SCE = 1;

        }
        dummy = origin;
        origin = destination;
        destination = dummy;
        pos = 0.0;
    }
}
double Plane::getpos() const {
    return pos;
}
double Plane::getvel() const {
    return vel;
}
void Plane::setvel(double velocity) {
    vel = velocity;
}
string Plane::getorigin() const {
    return origin;
}
string Plane::getdestination() const {
    return destination;
}
bool Plane::getatSCE() const {
    return at_SCE;
}



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