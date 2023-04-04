#
# Python portion of Project4
# CSCI 265
# Kaleb Gilson - kaleb.gilson@und.edu - 4/3/23
#
from math import sqrt


# Iterates through a provided array and finds the maximum value within the array.
def findMaxScore(scoresList):
    if len(scoresList) == 0:
        return -1
    maximum = scoresList[0]

    for j in range(len(scoresList)):
        if scoresList[j] > maximum:
            maximum = scoresList[j]
    return maximum


# Iterates through a provided array and finds the minimum value within the array.
def findMinScore(scoresList):
    if len(scoresList) == 0:
        return -1
    minimum = scoresList[0]

    for j in range(len(scoresList)):
        if scoresList[j] < minimum:
            minimum = scoresList[j]
    return minimum


# Iterates through a provided array and finds if the array has a value of 100 or greater.
def hasPerfectScore(scoresList):
    if len(scoresList) == 0:
        return False
    for j in range(len(scoresList)):
        if scoresList[j] >= 100:
            return True
    return False


# Calculates the average value of the list given
def calcAverage(scoresList):
    allScores = 0
    for j in range(len(scoresList)):
        allScores += scoresList[j]

    if len(scoresList) != 0:
        return allScores / len(scoresList)
    else:
        return -1


# Finds the student name who has the maximum score
def findStudentWithMax(scoresList, namesList):
    if (len(scoresList) == 0): return "None"
    maximum = scoresList[0]
    maxStudent = namesList[0]

    for j in range(len(scoresList)):
        if scoresList[j] > maximum:
            maximum = scoresList[j]
            maxStudent = namesList[j]

    return maxStudent


# Merge two int arrays together
def mergeLists(list1, list2):
    mergedArray = [0] * (len(list1) + len(list2))

    for j in range(len(list1)):
        mergedArray[j] = list1[j]

    k = len(list1)
    for j in range(len(list2)):
        mergedArray[k] = list2[j]
        k += 1

    return mergedArray


# Calculates the standard deviation of the list given
def standardDeviation(scoresList):
    if len(scoresList) == 0:
        return -1
    average = calcAverage(scoresList)
    difFromAverageSqrd = [0.0] * len(scoresList)

    for j in range(len(scoresList)):
        difFromAverageSqrd[j] = (scoresList[j] - average) * (scoresList[j] - average)
        avgDifSqrd = calcAverage(difFromAverageSqrd)
    return sqrt(avgDifSqrd)


# Finds the index of a score in the list, starting from a given index
def findInList(scoresList, valueToFind, startingIndex=0):
    if len(scoresList) == 0:
        return -1
    if startingIndex >= len(scoresList):
        return -1

    for j in range(startingIndex, len(scoresList)):
        if scoresList[j] == valueToFind:
            return j
    return -1


scoreList = [5, 10, 75, 80, 100, 30, 95, 100, 87]
studentList = ["Bob", "Jess", "Kaleb", "Joe", "Tom", "Marissa", "Austin", "Lily", "Ben"]

# Print all students and their scores
for i in range(len(scoreList)):
    print(studentList[i] + ": " + str(scoreList[i]))

# Calculate the maximum score
print("The maximum score was: " + str(findMaxScore(scoreList)))

# Calculate the minimum score
print("The minimum score was: " + str(findMinScore(scoreList)))

# Check if a student has a perfect score
print("Someone has a perfect score!" if hasPerfectScore(scoreList) else "No one has a perfect score.")

# Calculate the average score
print("The average score was: " + str(calcAverage(scoreList)))

# Find the student with the maximum score
print("The student with the maximum score was: " + findStudentWithMax(scoreList, studentList))

# Merge some more scores to our original list
additionalScores = [200, 150, 120]
mergedLists = mergeLists(scoreList, additionalScores)

print("After the additional scores were collected, here is the new score list: ")
for i in range(len(mergedLists)):
    if i != 0:
        print(", ", end='')
    print(mergedLists[i], end='')

# Calculate the standard deviation of the scores
print("\nThe standard deviation of the scores is: " + str(standardDeviation(scoreList)))

# Find students in the list by score
student95 = studentList[findInList(scoreList, 95)] if scoreList != 0 else "None" # If there are no values in the list, return "None"
student100 = studentList[findInList(scoreList, 100)] if scoreList != 0 else "None" # If there are no values in the list, return "None"
print("A score of 95 was obtained by: " + student95)
print("If we leave out Tom, a score of 100 was obtained by: " + student100)
