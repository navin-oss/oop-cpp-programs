#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

double calculateAverage(const vector<int>& marks) {
    int sum = 0;
    for (int i = 0; i < marks.size(); i++) {
        sum += marks[i];
    }
    return sum / 3.0;};

int main() {
    map<string, vector<int>> students;  
    string name;
    vector<int> marks(3);
    char choice;

    do {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }

        students[name] = marks;  

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nStudent Records:\n";
    for (auto it = students.begin(); it != students.end(); it++) {
        double avg = calculateAverage(it->second);  
        cout << "Student: " << it->first << ", Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << it->second[i] << " "; 
        }
        cout << ", Average: " << avg << endl;  
    }

    string topperName;
    double highestAvg = -1;

    for (auto it = students.begin(); it != students.end(); it++) {
        double avg = calculateAverage(it->second);
        if (avg > highestAvg) {
            highestAvg = avg;
            topperName = it->first; 
    }

    cout << "\nTopper: " << topperName << " with average " << highestAvg << endl;

    return 0;
}
}


