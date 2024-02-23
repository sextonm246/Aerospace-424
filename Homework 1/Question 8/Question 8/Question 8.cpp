// Michael Sexton
// Question 8

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <memory>
using namespace std;

class Plane {
private:
    double pos;
    double vel;
    double distance;
    bool at_SCE;
    string origin;
    string destination;
    map<pair<string, string>, int> flightdistance;
public:
    Plane(const string& from, const string& to) : origin(from), destination(to) {
        pos = 0;
        vel = 0;
        at_SCE = false;
        cout << "Plane Created with tail number " << this << endl;
        flightdistance[{ "SCE", "PHL" }] = 160;
        flightdistance[{ "SCE", "ORD" }] = 640;
        flightdistance[{ "SCE", "EWR" }] = 220;
        auto check = flightdistance.find({ origin, destination });
        if (check != flightdistance.end()) {
            distance = check->second;
        }
    }
    ~Plane() {
        cout << "Plane Destroyed" << endl;
    }
    void operate(double dt) {
        string dummy;
        if (pos < distance) {
            pos += vel * (dt / 3600);
            at_SCE = false;
        }
        else {
            if (destination == "SCE") {
                at_SCE = true;
            }
            dummy = origin;
            origin = destination;
            destination = dummy;
            pos = 0.0;
        }
    }
    double getpos() const {
        return pos;
    }
    double getvel() const {
        return vel;
    }
    void setvel(double velocity) {
        vel = velocity;
    }
    string getorigin() const {
        return origin;
    }
    string getdestination() const {
        return destination;
    }
    bool getatSCE() const {
        return at_SCE;
    }
};

class Pilot {
private:
    string name;
public:
    unique_ptr<Plane> myPlane; // Modern pointer style instead of classic style
    Pilot(const string& pilot_name) : name(pilot_name), myPlane(nullptr) {
        cout << "Pilot " << name << " with certificate number " << this << " is at the gate and ready to board the plane. \n";
    }
    ~Pilot() {
        cout << name << " is out of the plane. \n";
    }
    string getName() const {
        return name;
    }
};

int main() {
    Plane airplane("SCE", "PHL");
    double velocity = 425;
    airplane.setvel(velocity);
    Pilot pilot1("Alpha");
    Pilot pilot2("Bravo");
    string pilot = ("Alpha");
    string copilot = ("Bravo");
    auto pilotnumber = &pilot1;
    auto copilotnumber = &pilot2;
    cout << "Pilot " << pilot << " with certificate number " << pilotnumber << " is in control of a plane: " << &airplane << endl;
    cout << "Pilot " << copilot << " with certificate number " << copilotnumber << " is not in control of the airplane. \n";
    for (int i = 0; i <= 2000; i++) {
        double timestep = 20;
        airplane.operate(timestep);
        int time = timestep * i;
        if (airplane.getatSCE() == 1) {
            cout << "The plane " << &airplane << " is at SCE. \n";
            swap(pilot, copilot);
            swap(pilotnumber, copilotnumber);
            cout << "Pilot " << pilot << " with certificate number " << pilotnumber << " is in control of a plane: " << &airplane << endl;
            cout << "Pilot " << copilot << " with certificate number " << copilotnumber << " is not in control of the airplane. \n" << endl;
        }
    }
    return 0;
}
