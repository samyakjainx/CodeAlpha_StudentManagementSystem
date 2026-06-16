# Student Management System in C

A simple Student Management System developed in C as part of my CodeAlpha C Programming Internship.

This project demonstrates the use of structures, functions, and file handling to perform basic student record management operations through a menu-driven interface.

---

## Features

- Add Student
- Display Students
- Search Student
- Update Student
- Delete Student
- Total Students
- Show Topper
- Clear All Records

---

## Technologies Used

- C Programming
- Structures
- Functions
- File Handling
- GCC Compiler / CodeBlocks / VS Code

---

## Project Structure

```

CodeAlpha_StudentManagementSystem/

│── student_management_system.c
│── README.md
│── LICENSE
│── .gitignore
└── screenshots/
   │── menu.png
   │── add.png
   │── display.png
   │── search.png
   │── update.png
   │── delete.png
   │── total.png
   │── topper.png
   │── clear.png
   │── exit.png

```

---

## How to Run

### Compile

```

gcc student_management_system.c -o student_management_system

```

### Execute

```

./student_management_system

```

or on Windows

```

student_management_system.exe

```

---

## Menu

```

====================================
   STUDENT MANAGEMENT SYSTEM
====================================

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Total Students
7. Show Topper
8. Clear All Records
9. Exit

```

---

## Sample Output

### Add Student

```

Roll : 01
Name : Samyak Jain
Age : 20
Marks : 88

Student Added Successfully!

```

---

### Display Students

```

------------------------------------

Roll : 1
Name : Samyak Jain
Age : 20
Marks : 88.00

Roll : 2
Name : Aditya
Age : 21
Marks : 79.00

```

---

### Search Student

```

Enter Roll : 1

Student Found

Name : Samyak Jain
Age : 20
Marks : 88.00

```

---

### Show Topper

```

Topper Details

Roll : 1
Name : Samyak Jain
Marks : 88.00

```

---

## Concepts Practiced

- Structures
- Functions
- File Handling
- Menu Driven Programming
- Searching Algorithms
- Updating Records
- Deleting Records
- Binary File Operations

---

## File Handling

Student records are stored permanently using file handling, allowing data to remain available even after the program is closed.

The project uses:

- fopen()
- fread()
- fwrite()
- fclose()
- remove()
- rename()

---

## Learning Outcome

Working on this project helped me understand how structures and file handling can be combined to build a simple data management system in C. It also improved my understanding of modular programming and record manipulation.

---

## Future Improvements

- Sort Students by Marks
- Export Student Records
- Attendance Management
- Subject-wise Result Management

---

## Author

Samyak Jain

CodeAlpha C Programming Internship 2026
