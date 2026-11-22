# STUDENT-FEEDBACK-SYSTEM

A menu-driven Student Feedback System developed using the C programming language. It allows students to submit course feedback and ratings, view submitted feedback, and calculate the average rating.

## Features

- Submit student feedback with name and course name
- Give a rating from 1 to 5
- Add comments about the course
- View all submitted feedback
- Calculate the average feedback rating
- Validate menu choices and ratings
- Store up to 100 feedback entries during a program run

## Requirements

- A C compiler such as GCC

## Compile

```bash
gcc -std=c11 -Wall -Wextra student_feedback.c -o student_feedback
```

## Run

On Linux or macOS:

```bash
./student_feedback
```

On Windows:

```bash
student_feedback.exe
```

## Menu Options

1. Submit Feedback
2. View All Feedback
3. Calculate Average Rating
4. Exit

## Concepts Used

- Structures
- Arrays
- Functions
- Loops and switch-case
- String handling
- Input validation using `fgets()` and `strtol()`
- Average calculation

## Note

This is an educational console application. Feedback is stored in memory while the program is running and is not saved permanently to a file or database. All feedback is lost when the program exits.
