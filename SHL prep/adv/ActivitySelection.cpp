#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
    int id; // To store original index
};

// Comparator function to sort activities by finish time
bool compareActivities(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to select activities
void activitySelection(vector<Activity>& activities) {
    if (activities.empty()) return;

    // 1. Sort activities by their finish time
    sort(activities.begin(), activities.end(), compareActivities);

    cout << "Selected Activities: " << endl;

    // 2. The first activity is always selected
    int lastSelectedSpecific = 0;
    cout << "Activity " << activities[0].id << " (" << activities[0].start << ", " << activities[0].finish << ")" << endl;

    // 3. Iterate through correct sorted activities
    for (size_t i = 1; i < activities.size(); i++) {
        // If this activity's start time is greater than or equal to the finish time of the last selected activity
        if (activities[i].start >= activities[lastSelectedSpecific].finish) {
            cout << "Activity " << activities[i].id << " (" << activities[i].start << ", " << activities[i].finish << ")" << endl;
            lastSelectedSpecific = i;
        }
    }
}

int main() {
    // Example usage
    // Activities with (start, finish) times
    vector<Activity> activities = {
        {5, 9, 1},
        {1, 2, 2},
        {3, 4, 3},
        {0, 6, 4},
        {5, 7, 5},
        {8, 9, 6}
    };

    cout << "Original Activities:" << endl;
    for(const auto& act : activities) {
        cout << "ID: " << act.id << " [" << act.start << ", " << act.finish << "]" << endl;
    }
    cout << endl;
    sort(activities.begin(), activities.end(), compareActivities);
    cout << "Sorted Activities (by finish time):" << endl;
    for(const auto& act : activities) {
        cout << "ID: " << act.id << " [" << act.start << ", " << act.finish << "]" << endl;
    }
    cout << endl;

    activitySelection(activities);

    return 0;
}
