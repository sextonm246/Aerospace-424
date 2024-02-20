// Michael Sexton
// Question 1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double emptyweight; double eweightm; int frontseato; double frontseatm;
    int rearseato; double rearseatm; double gallonsfuel; double fuelweight; double newfuelweight; double fuelremoved;
    double fueltankm; double baggageweight; double baggagem;

    double grossweight; double cglocation; double excessfuel;
    // Input variables
    cout << "What is the empty weight of the aircraft? \n";
    cin >> emptyweight;
    cout << "What is the empty weight moment of the aircraft? \n";
    cin >> eweightm;
    cout << "What is the number of front seat occupants? \n";
    cin >> frontseato;
    double* frontseatw = new double[frontseato]; // Weight of each passenger in front seats
    double frontseatwsum = 0;
    for (int i = 0; i < frontseato; i++) {
        cout << "What is the weight of front seat occupant number " << i + 1 << "? \n";
        cin >> frontseatw[i];
        frontseatwsum = frontseatwsum + frontseatw[i];
    }
    cout << "What is the front seat moment arm? \n";
    cin >> frontseatm;
    cout << "What is the number of rear seat occupants? \n";
    cin >> rearseato;
    double* rearseatw = new double[rearseato]; // Weight of each passenger in rear seats
    double rearseatwsum = 0;
    for (int j = 0; j < rearseato; j++) {
        cout << "What is the weight of rear seat occupant number " << j + 1 << "? \n";
        cin >> rearseatw[j];
        rearseatwsum = rearseatwsum + rearseatw[j];
    }
    cout << "What is the rear seat moment arm? \n";
    cin >> rearseatm;
    cout << "How many gallons of fuel are on the aircraft? \n";
    cin >> gallonsfuel;
    cout << "How much does each gallon of fuel weight? \n";
    cin >> fuelweight;
    cout << "What is the fuel tank moment arm? \n";
    cin >> fueltankm;
    cout << "How much does the baggage weight? \n";
    cin >> baggageweight;
    cout << "What is the baggage moment arm? \n";
    cin >> baggagem;

    // Calculations
    grossweight = emptyweight + frontseatwsum + rearseatwsum + (gallonsfuel * fuelweight) + baggageweight;
    // Check gross weight
    while (grossweight > 2950) {
        excessfuel = (grossweight - 2950) / fuelweight; // Gallons of fuel to be removed
        cout << "The weight of " << grossweight << " pounds is too high. Please remove " << setprecision(3) << excessfuel << " gallons of fuel to reach the 2950 lb limit." << endl;
        cout << "How much fuel was removed?" << endl;
        cin >> fuelremoved;
        newfuelweight = (gallonsfuel - fuelremoved) * fuelweight;
        grossweight = emptyweight + frontseatwsum + rearseatwsum + newfuelweight + baggageweight;
    }
    cout << "The new gross weight of the aircraft is now " << grossweight << " lbs. \n";
    cglocation = ((eweightm)+(frontseatwsum * frontseatm) + (rearseatwsum * rearseatm) + (gallonsfuel * fuelweight * fueltankm) + (baggageweight * baggagem)) / grossweight;
    // Check CG location
    while (cglocation < 82.1 || cglocation > 84.7) {
        if (cglocation < 82.1) {
            excessfuel = ((grossweight * cglocation) - ((eweightm)+(frontseatwsum * frontseatm) + (rearseatwsum * rearseatm) + (baggageweight * baggagem))) / (fuelweight * fueltankm);
            cout << "The aircraft CG is not in a valid location, please change the amount of fuel by " << excessfuel << " gallons. \n";
            cout << "How much fuel was removed? \n";
            cin >> excessfuel;
        }
        else if (cglocation > 84.7) {
            excessfuel = ((grossweight * cglocation) - ((eweightm)+(frontseatwsum * frontseatm) + (rearseatwsum * rearseatm) + (baggageweight * baggagem))) / (fuelweight * fueltankm);
            cout << "The aircraft CG is not in a valid location, please change the amount of fuel by " << excessfuel << " gallons. \n";
            cout << "How much fuel was removed? \n";
            cin >> excessfuel;
        }
    }
    cout << "The location of the CG of the aircraft is " << cglocation << " inches. \n";
    // End of Question 1
    return 0;
}