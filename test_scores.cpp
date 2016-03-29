/*
 * Zoe Wilson
 * March 29, 2016
 * Test Scores
 */

#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Sorts the student scores.
 */
void sort_scores(std::vector<int> &student_scores) {
    sort(student_scores.begin(), student_scores.end());
}

/*
 * Gets the average of all student scores.
 * @returns average.
 */
float get_average(std::vector<int> &student_scores, int num_students) {
    int avg = 0;
    for(int i = 0; i < num_students; i++) {
        avg += student_scores[i];
    }
    return (float) avg / (float) num_students;
}

int main() {
    std::vector<int> student_scores;
    int num_of_students;
    float student_avg = 0;

    // Gets the number of students from the user.
    std::cout << "What is the number of students? " << std::endl;
    std::cin >> num_of_students;

    // Resizes the container to be equal to the number of students.
    student_scores.resize(num_of_students);

    // Gets each student's score.
    for(int i = 0; i < num_of_students; i++) {
        std::cout << "Enter the score for student " << i + 1 << std::endl;
        std::cin >> student_scores[i];
        // Make sure the user does not enter a negative value.
        while(student_scores[i] < 0) {
            std::cout << "Must enter a score greater than 0. " << std::endl;
            std::cin >> student_scores[i];
        }
    }

    // Sorts scores.
    sort_scores(student_scores);

    // Gets average test score.
    student_avg = get_average(student_scores, num_of_students);

    // Prints Results.
    std::cout << "Student Scores: ";
    for(int i = 0; i < num_of_students; i++) {
        std::cout << " " << student_scores[i];
    }
    std::cout << std::endl;

    std::cout << "Student Average: " << student_avg << std::endl;

    return 0;
} 
