#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <cmath>
#include <utility>


void maxGuestsAtHotel(int N, vector<int>& arrivals, vector<int>& departures) {
    vector<pair<int, int>> events;

    // Step 1: Store all arrival (+1) and departure (-1) events
    for (int i = 0; i < N; i++) {
        events.push_back({arrivals[i], 1});  // Arrival event
        events.push_back({departures[i], -1});  // Departure event
    }

    // Step 2: Sort events by time
    sort(events.begin(), events.end());

    // Step 3: Sweep through events to count guests
    int maxGuests = 0, currentGuests = 0;
    for (auto event : events) {
        currentGuests += event.second;  // +1 for arrival, -1 for departure
        maxGuests = max(maxGuests, currentGuests);
    }

    cout << maxGuests << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arrivals(N), departures(N);

        for (int i = 0; i < N; i++) cin >> arrivals[i];
        for (int i = 0; i < N; i++) cin >> departures[i];

        maxGuestsAtHotel(N, arrivals, departures);
    }

    return 0;
}
