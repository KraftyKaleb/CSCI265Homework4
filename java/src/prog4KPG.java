/*
 * Java portion of Project4
 * CSCI 265
 * Kaleb Gilson - kaleb.gilson@und.edu - 4/3/23
 */

public class prog4KPG {
    public static void main(String[] args) {
        int[] scoreList = { 5, 10, 75, 80, 100, 30, 95, 100, 87 };
        String[] studentList = {"Bob", "Jess", "Kaleb", "Joe", "Tom", "Marissa", "Austin", "Lily", "Ben"};

        //Print all students and their scores
        for (int i = 0; i < scoreList.length; i++ ) {
            System.out.println(studentList[i] + ": " + scoreList[i]);
        }

        // Calculate the maximum score
        System.out.println("The maximum score was: " + findMaxScore(scoreList));

        // Calculate the minimum score
        System.out.println("The minimum score was: " + findMinScore(scoreList));

        // Calculate the average score
        System.out.println("The average score was: " + calcAverage(scoreList));

        // Find the student with the maximum score
        System.out.println("The student with the maximum score was: " + findStudentWithMax(scoreList, studentList));

        // Merge some more scores to our original list
        int[] additionalScores = { 200, 150, 120 };
        int[] mergedLists = mergeLists(scoreList, additionalScores);

        System.out.print("After the additional scores were collected, here is the new score list: ");
        for (int i = 0; i < mergedLists.length; i++) {
            if (i != 0) System.out.print(", ");
            System.out.print(mergedLists[i]);
        }
        System.out.println();

        // Calculate the standard deviation of the scores
        System.out.println("The standard deviation of the scores is: " + standardDeviation(scoreList));

        // Find students in the list by score
        String student95 = scoreList.length != 0 ? studentList[findInList(scoreList, 95)] : "None"; // If there are no values in the list, return "None"
        String student100 = scoreList.length != 0 ? studentList[findInList(scoreList, 100, 5)] : "None"; // If there are no values in the list, return "None"
        System.out.println("A score of 95 was obtained by: " + student95);
        System.out.println("If we leave out Tom, a score of 100 was obtained by: " + student100);
    }

    /**
     * Iterates through a provided array and finds the maximum value within the array.
     *
     * @param scoresList Array to iterate through
     * @return Maximum value within the array
     */
    private static int findMaxScore(int[] scoresList) {
        if (scoresList.length == 0) return -1;

        int max = scoresList[0];

        for (int i = 1; i < scoresList.length; i++) {
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
    private static int findMinScore(int[] scoresList) {
        if (scoresList.length == 0) return -1;
        int min = scoresList[0];

        for (int i = 1; i < scoresList.length; i++) {
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
    private static boolean hasPerfectScore(int[] scoresList) {
        if (scoresList.length == 0) return false;
        for (int i = 0; i < scoresList.length; i++) {
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
    private static double calcAverage(int[] scoresList) {
        int allScores = 0;
        for (int i = 0; i < scoresList.length; i++) {
            allScores+=scoresList[i];
        }

        if (scoresList.length != 0) {
            return allScores/(double) scoresList.length;
        } else return -1;
    }

    /**
     * Calculates the average value of the list given
     *
     * @param avgList Array to iterate through
     * @return Average value of the array
     */
    private static double calcAverage(double[] avgList) {
        int allScores = 0;
        for (int i = 0; i < avgList.length; i++) {
            allScores+=avgList[i];
        }

        if (avgList.length != 0) {
            return allScores/(double) avgList.length;
        } else return -1;
    }

    /**
     * Finds the student name who has the maximum score
     *
     * @param scoresList Scores to iterate through
     * @param namesList Student name list
     * @return Student name who has the maximum score
     */
    private static String findStudentWithMax(int[] scoresList, String[] namesList) {
        if (scoresList.length == 0) return "None";
        int max = scoresList[0];
        String maxStudent = namesList[0];

        for (int i = 1; i < scoresList.length; i++) {
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
    private static int[] mergeLists(int[] list1, int[] list2) {
        int[] mergedArray = new int[list1.length + list2.length];

        for (int i = 0; i < list1.length; i++) {
            mergedArray[i] = list1[i];
        }

        int j = list1.length;
        for (int i = 0; i < list2.length; i++) {
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
    private static double standardDeviation(int[] scoresList) {
        if (scoresList.length == 0) return -1;
        double average = calcAverage(scoresList);
        double[] difFromAverageSqrd = new double[scoresList.length];

        for (int i = 0; i < scoresList.length; i++) {
            difFromAverageSqrd[i] = Math.pow(scoresList[i]-average, 2);
        }

        double avgDifSqrd = calcAverage(difFromAverageSqrd);
        return Math.sqrt(avgDifSqrd);
    }

    /**
     * Finds the index of a score in the list, starting from index 0
     * @param scoresList List to iterate through
     * @param valueToFind Value to locate in the list
     * @return The index of the value (returns -1 if the list is empty or if the value doesn't exist)
     */
    private static int findInList(int[] scoresList, int valueToFind) {
        if (scoresList.length == 0) return -1;
        return findInList(scoresList, valueToFind, 0);
    }

    /**
     * Finds the index of a score in the list, starting from a given index
     * @param scoresList List to iterate through
     * @param valueToFind Value to locate in the list
     * @param startingIndex Index to start from
     * @return The index of the value (returns -1 if the list is empty or if the value doesn't exist)
     */
    private static int findInList(int[] scoresList, int valueToFind, int startingIndex) {
        if (scoresList.length == 0) return -1;
        if (startingIndex >= scoresList.length) return -1;

        for (int i = startingIndex; i < scoresList.length; i++) {
            if (scoresList[i] == valueToFind) {
                return i;
            }
        }

        return -1;
    }
}
