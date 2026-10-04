# Text-Based Attendance Management System

This is a text-based Attendance Management System developed using C programming.

## Technologies Used

- C Programming Language

## Major Concepts Used

- Structures
- Arrays
- Loops
- Strings
- String Functions
- File Handling
- Windows built-in commands
  - Used to detect text files present in the folder

## Options in Version 1

1. Add student names and roll numbers
2. View student names and roll numbers
3. Mark student attendance
4. View student attendance

## How It Works

- First, you have to add the names and roll numbers of the students.
  All this data will be stored in a file named `Students_list.txt`.

- Then, you can create attendance sheets.
  - You can create one attendance sheet for one subject and one date.
  - You only need to enter the subject name, and the text file will be created automatically.
  - The file will be named in the following format:
    `subject_date_month_year.txt`

- After creating the attendance sheet, you can mark attendance for the students added to the student list.
  - Select the subject file in which you want to enter the attendance.
  - Enter the date, month, and year that you want to display as the heading of the attendance sheet.

## Future Plans

- Integrate SQL for data management
- Add a Graphical User Interface (GUI)
