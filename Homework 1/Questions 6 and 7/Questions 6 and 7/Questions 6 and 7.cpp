// Michael Sexton
// Questions 6, 7

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;


// Class Plane is for Question 3
class Plane {
private:
    double pos; double vel; double distance;
    bool at_SCE;
    string origin; string destination;
    map<pair< string, string>, int>flightdistance; // Question 2
public:
    Plane(const string& from, const string& to) : origin(from), destination(to) {
        pos = 0; vel = 0; at_SCE = 0;
        cout << "Plane Created at " << this << endl;
        flightdistance[{"SCE", "PHL"}] = 160; // Question 2
        flightdistance[{"SCE", "ORD"}] = 640;
        flightdistance[{"SCE", "EWR"}] = 220;
        auto check = flightdistance.find({ origin, destination });
        if (check != flightdistance.end())
        {
            distance = check->second;
            cout << "Distance between " << origin << " and " << destination << ": " << distance << " miles" << endl;
        }
    }
    ~Plane() {
        cout << "Plane Destroyed" << endl;
    }
    void operate(double dt) {
        string dummy;
        if (pos < distance) {
            pos += vel * (dt / 3600);
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

// Class for Question 6
class Pilot {
private:
    string name;

public: 
    Pilot(const string& pilot_name, Plane* plane_pointer) : name(pilot_name), myPlane(plane_pointer) {
        cout << name << " is athe the gate and ready to board the plane. Memory address: " << this << endl;
    }
    ~Pilot() {
        cout << name << " is out of the plane. \n";
    }
    string getName() const {
        return name;
    }
    Plane* myPlane; // Pointer to plane object
};


int main()
{
    // Question 2:
    Plane airplane("SCE", "PHL");

    // Setting distances for each flight possibility
    double velocity = 425;

    airplane.setvel(velocity);

    for (int i = 0; i <= 1000; i++) {
        double timestep = 25;
        airplane.operate(timestep);
        int time = timestep * i;
        cout << "Time: " << time << " seconds. Position: " << airplane.getpos() << " miles." << endl;
    }
    return 0;
}