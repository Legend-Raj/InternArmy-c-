#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void addEvent(map<string, vector<string>>& events);
void editEvent(map<string, vector<string>>& events);
void deleteEvent(map<string, vector<string>>& events);
void viewCalendar(const map<string, vector<string>>& events);

int main() {
    map<string, vector<string>> events;
    int choice;

    do {
        cout << "\nSimple Calendar Application\n";
        cout << "1. Add Event\n";
        cout << "2. Edit Event\n";
        cout << "3. Delete Event\n";
        cout << "4. View Calendar\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEvent(events);
                break;
            case 2:
                editEvent(events);
                break;
            case 3:
                deleteEvent(events);
                break;
            case 4:
                viewCalendar(events);
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

void addEvent(map<string, vector<string>>& events) {
    string date, event;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter event: ";
    cin.ignore(); 
    getline(cin, event);

    events[date].push_back(event);

    cout << "Event added successfully.\n";
}

void editEvent(map<string, vector<string>>& events) {
    string date;
    cout << "Enter date (YYYY-MM-DD) to edit events: ";
    cin >> date;

    if (events.find(date) != events.end()) {
        cout << "Events on " << date << ":\n";
        for (const string& event : events[date]) {
            cout << "- " << event << "\n";
        }

        int eventIndex;
        cout << "Enter the index of the event to edit: ";
        cin >> eventIndex;

        if (eventIndex >= 0 && eventIndex < events[date].size()) {
            cout << "Enter the updated event: ";
            cin.ignore();
            getline(cin, events[date][eventIndex]);
            cout << "Event updated successfully.\n";
        } else {
            cout << "Invalid event index.\n";
        }
    } else {
        cout << "No events found on " << date << ".\n";
    }
}

void deleteEvent(map<string, vector<string>>& events) {
    string date;
    cout << "Enter date (YYYY-MM-DD) to delete events: ";
    cin >> date;

    if (events.find(date) != events.end()) {
        cout << "Events on " << date << ":\n";
        for (const string& event : events[date]) {
            cout << "- " << event << "\n";
        }

        int eventIndex;
        cout << "Enter the index of the event to delete: ";
        cin >> eventIndex;

        if (eventIndex >= 0 && eventIndex < events[date].size()) {
            events[date].erase(events[date].begin() + eventIndex);
            cout << "Event deleted successfully.\n";
        } else {
            cout << "Invalid event index.\n";
        }
    } else {
        cout << "No events found on " << date << ".\n";
    }
}

void viewCalendar(const map<string, vector<string>>& events) {
    if (events.empty()) {
        cout << "No events found.\n";
        return;
    }

    cout << "Calendar:\n";
    for (const auto& entry : events) {
        cout << entry.first << ":\n";
        for (const string& event : entry.second) {
            cout << "- " << event << "\n";
        }
    }
}
