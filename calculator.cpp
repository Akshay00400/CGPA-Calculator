#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Function to map grade to GPA on a 4.0 scale
float getGPA(string grade) {
    map<string, float> gradeMap = {
        {"A+", 4.0}, {"A", 4.0}, {"B+", 3.5}, {"B", 3.0},
        {"C+", 2.5}, {"C", 2.0}, {"D", 1.0}, {"F", 0.0}
    };
    
    // Return GPA corresponding to the grade, or 0.0 if the grade is invalid
    if (gradeMap.find(grade) != gradeMap.end()) {
        return gradeMap[grade];
    } else {
        return 0.0;
    }
}

int main() {
    int numSubjects;
    
    // Ask user for the number of subjects
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    float totalCredits = 0;
    float weightedGradePoints = 0;

    // Loop through each subject and get the credits and grade
    for (int i = 0; i < numSubjects; ++i) {
        string subjectName;
        int creditHours;
        string grade;

        cout << "\nEnter details for subject " << i + 1 << ":\n";
        
        cout << "Subject Name: ";
        cin.ignore();  // To consume the newline left by the previous input
        getline(cin, subjectName);
        
        cout << "Credit Hours: ";
        cin >> creditHours;

        cout << "Grade (e.g., A, B+, C, etc.): ";
        cin >> grade;

        // Calculate GPA for the subject
        float gpa = getGPA(grade);

        if (gpa == 0.0) {
            cout << "Invalid grade input. Please ensure your grade is valid.\n";
            return 1;  // Exit program if invalid grade is provided
        }

        // Calculate weighted grade points
        weightedGradePoints += gpa * creditHours;
        totalCredits += creditHours;
    }

    // Calculate CGPA
    if (totalCredits == 0) {
        cout << "Total credits cannot be zero. Exiting...\n";
        return 1;
    }

    float cgpa = weightedGradePoints / totalCredits;

    // Output the CGPA result
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}
