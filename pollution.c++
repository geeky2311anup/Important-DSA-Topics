#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int peopleCount;
        cin >> peopleCount;

        int busEmission, carEmission;
        cin >> busEmission >> carEmission;

        int totalEmission = 0;

        // for full batches of 100 people
        int fullBuses = peopleCount / 100;
        int carsForFullBuses = fullBuses * 25;

        int emissionFromBuses = fullBuses * busEmission;
        int emissionFromCars = carsForFullBuses * carEmission;

        totalEmission = min(emissionFromBuses, emissionFromCars);

        peopleCount = peopleCount % 100;

        // for remaining people
        if (peopleCount > 0) {
            int carsForRemaining = ceil(peopleCount / 4.0);
            int emissionRemainingCars = carsForRemaining * carEmission;
            int emissionRemainingBus = busEmission;

            totalEmission += min(emissionRemainingBus, emissionRemainingCars);
        }

        cout << totalEmission << endl;
    }
    return 0;
}
