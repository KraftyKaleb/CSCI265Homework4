#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
 * C++ portion of Project4
 * CSCI 265
 * Kaleb Gilson - kaleb.gilson@und.edu - 4/3/23
 */

//Function declarations
int findMaxScore(int scoreList[], int size);
int findMinScore(int scoreList[], int size);
bool hasPerfectScore(int scoresList[], int size);
double calcAverage(int scoresList[], int size);
double calcAverage(double avgList[], int size);
string findStudentWithMax(int scoresList[], string namesList[], int size);
int* mergeLists(int list1[], int size1, int list2[], int size2);
double standardDeviation(int scoresList[], int size);
int findInList(int scoresList[], int size, int valueToFind);
int findInList(int scoresList[], int size, int valueToFind, int startingIndex);

int main() {
    int scoreList[] = { 5, 10, 75, 80, 100, 30, 95, 100, 87 };
    string studentList[] = {"Bob", "Jess", "Kaleb", "Joe", "Tom", "Marissa", "Austin", "Lily", "Ben"};
    const int size = 9;

    //Print all students and their scores
    for (int i = 0; i < size; i++ ) {
        cout << studentList[i] << ": " << scoreList[i] << "\n";
    }

    // Calculate the maximum score
    cout <<"The maximum score was: " << findMaxScore(scoreList, size) << "\n";

    // Calculate the minimum score
    cout <<"The minimum score was: " << findMinScore(scoreList, size) << "\n";

    // Check if a student has a perfect score
    string output = hasPerfectScore(scoreList, size) ? "Someone has a perfect score!" : "No one has a perfect score.";
    cout << output << "\n";

    // Calculate the average score
    cout << "The average score was: " << calcAverage(scoreList, size) << "\n";

    // Find the student with the maximum score
    cout << "The student with the maximum score was: " << findStudentWithMax(scoreList, studentList, size) << "\n";

    // Merge some more scores to our original list
    int additionalScores[] = { 200, 150, 120 };
    int size2 = 3;
    int* mergedLists = mergeLists(scoreList, size, additionalScores, size2);

    cout << "After the additional scores were collected, here is the new score list: ";
    for (int i = 0; i < size2+size; i++) {
        if (i != 0) cout << ", ";
        cout << *mergedLists;
        mergedLists++;
    }
    cout << "\n";

    // Calculate the standard deviation of the scores
    cout << "The standard deviation of the scores is: " << standardDeviation(scoreList, size) << "\n";

    // Find students in the list by score
    string student95 = size != 0 ? studentList[findInList(scoreList, size, 95)] : "None"; // If there are no values in the list, return "None"
    string student100 = size != 0 ? studentList[findInList(scoreList, size,100, 5)] : "None"; // If there are no values in the list, return "None"
    cout << "A score of 95 was obtained by: " << student95 << "\n";
    cout <<"If we leave out Tom, a score of 100 was obtained by: " << student100 << "\n";
}

/**
 * Iterates through a provided array and finds the maximum value within the array.
 *
 * @param scoresList Array to iterate through
 * @return Maximum value within the array
 */
int findMaxScore(int scoresList[], int size) {
    if (size == 0) return -1;

    int max = scoresList[0];

    for (int i = 1; i < size; i++) {
        if (scoresList[i] > max) {
            max = scoresList[i];
        }
    }

    return max;
}

/**
 * Iterates through a provided array and finds the minimum value within the array.
 *
 * @param scoresList Array to iterate through
 * @return Minimum value within the array
 */
int findMinScore(int scoresList[], int size) {
    if (size == 0) return -1;
    int min = scoresList[0];

    for (int i = 1; i < size; i++) {
        if (scoresList[i] < min) {
            min = scoresList[i];
        }
    }

    return min;
}

/**
 * Iterates through a provided array and finds if the array has a value of 100 or greater.
 *
 * @param scoresList Array to iterate through
 * @return if the array has a value greater or equal to 100
 */
bool hasPerfectScore(int scoresList[], int size) {
    if (size == 0) return false;
    for (int i = 0; i < size; i++) {
        if (scoresList[i] >= 100) {
            return true;
        }
    }

    return false;
}

/**
 * Calculates the average value of the list given
 *
 * @param scoresList Array to iterate through
 * @return Average value of the array
 */
double calcAverage(int scoresList[], int size) {
    int allScores = 0;
    for (int i = 0; i < size; i++) {
        allScores+=scoresList[i];
    }

    if (size != 0) {
        return allScores/(double) size;
    } else return -1;
}

/**
 * Calculates the average value of the list given
 *
 * @param avgList Array to iterate through
 * @return Average value of the array
 */
double calcAverage(double avgList[], int size) {
    int allScores = 0;
    for (int i = 0; i < size; i++) {
        allScores+=avgList[i];
    }

    if (size != 0) {
        return allScores/(double) size;
    } else return -1;
}

/**
 * Finds the student name who has the maximum score
 *
 * @param scoresList Scores to iterate through
 * @param namesList Student name list
 * @return Student name who has the maximum score
 */
string findStudentWithMax(int scoresList[], string namesList[], int size) {
    if (size == 0) return "None";
    int max = scoresList[0];
    string maxStudent = namesList[0];

    for (int i = 1; i < size; i++) {
        if (scoresList[i] > max) {
            max = scoresList[i];
            maxStudent = namesList[i];
        }
    }

    return maxStudent;
}

/**
 * Merge two int arrays together
 *
 * @param list1 Array 1
 * @param list2 Array 2
 * @return Combined array
 */
int* mergeLists(int list1[], int size1, int list2[], int size2) {
    int* mergedArray = new int[size1 + size2];

    for (int i = 0; i < size1; i++) {
        mergedArray[i] = list1[i];
    }

    int j = size1;
    for (int i = 0; i < size2; i++) {
        mergedArray[j] = list2[i];
        j++;
    }

    return mergedArray;
}

/**
 * Calculates the standard deviation of the list given
 * @param scoresList List to iterate through
 * @return Standard deviation of the list (returns -1 if the list is empty)
 */
double standardDeviation(int scoresList[], int size) {
    if (size == 0) return -1;
    double average = calcAverage(scoresList, size);
    double difFromAverageSqrd[size];

    for (int i = 0; i < size; i++) {
        difFromAverageSqrd[i] = (scoresList[i]-average) * scoresList[i]-average;
    }

    double avgDifSqrd = calcAverage(difFromAverageSqrd, size);
    return sqrt(avgDifSqrd);
}

/**
 * Finds the index of a score in the list, starting from index 0
 * @param scoresList List to iterate through
 * @param valueToFind Value to locate in the list
 * @return The index of the value (returns -1 if the list is empty or if the value doesn't exist)
 */
int findInList(int scoresList[], int size, int valueToFind) {
    if (size == 0) return -1;
    return findInList(scoresList, size, valueToFind, 0);
}

/**
 * Finds the index of a score in the list, starting from a given index
 * @param scoresList List to iterate through
 * @param valueToFind Value to locate in the list
 * @param startingIndex Index to start from
 * @return The index of the value (returns -1 if the list is empty or if the value doesn't exist)
 */
int findInList(int scoresList[], int size, int valueToFind, int startingIndex) {
    if (size == 0) return -1;
    if (startingIndex >= size) return -1;

    for (int i = startingIndex; i < size; i++) {
        if (scoresList[i] == valueToFind) {
            return i;
        }
    }

    return -1;
}