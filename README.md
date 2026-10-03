# ⚙️ C++ Assembly Line Simulation

A C++ application that simulates an assembly line where customer orders move through a sequence of workstations and are filled based on available inventory.

This project was developed as part of my **Object-Oriented Programming coursework at Seneca Polytechnic** and focuses on applying modern C++ concepts in a multi-class application.

---

## ☕ About the Project

The application simulates the operation of an assembly line consisting of multiple workstations.

Customer orders move through the assembly line, where each workstation attempts to fill a specific item in the order based on available inventory. Orders continue through the line until they are either successfully completed or identified as incomplete.

The assembly line is configured dynamically using input files, allowing the sequence of workstations and inventory information to be loaded at runtime.

---

## ✨ Features

- Loads workstation information from external data files
- Dynamically configures the assembly line
- Processes multiple customer orders
- Moves orders between interconnected workstations
- Fills requested items based on available inventory
- Updates workstation inventory during processing
- Tracks completed and incomplete customer orders
- Parses structured input data using reusable utility functions
- Includes tester files and sample outputs for validation

---

## 🧠 C++ Concepts Used

`Object-Oriented Programming` `STL` `Move Semantics` `File I/O` `Dynamic Memory`

The project applies concepts including:

- Classes and encapsulation
- Object relationships
- STL containers
- STL algorithms
- Move semantics
- Dynamic memory management
- File input and parsing
- Lambda expressions
- Modular program design

---

## 🗂️ Project Structure

```text
cpp-assembly-line/
│
├── src/
│   ├── CustomerOrder.cpp
│   ├── CustomerOrder.h
│   ├── LineManager.cpp
│   ├── LineManager.h
│   ├── Station.cpp
│   ├── Station.h
│   ├── Utilities.cpp
│   ├── Utilities.h
│   ├── Workstation.cpp
│   └── Workstation.h
│
├── data/
│   ├── Stations1.txt
│   ├── Stations2.txt
│   └── AssemblyLine.txt
│
├── tests/
│   ├── tester_1.cpp
│   ├── tester_1_sample_output.txt
│   ├── tester_2.cpp
│   ├── tester_2_sample_output.txt
│   ├── tester_3.cpp
│   └── tester_3_sample_output.txt
│
└── README.md
```

---

## 🧩 Main Components

### `Station`

Represents an individual station in the assembly line.

Each station stores information about the item it handles, including its name, serial number, quantity, and description.

### `CustomerOrder`

Represents an individual customer's order and the items requested by that customer.

It manages the filling status of each item and keeps track of whether an order has been completely filled.

### `Workstation`

Represents an active station in the assembly line.

It processes customer orders, attempts to fill requested items, and moves orders to the next workstation when appropriate.

### `LineManager`

Controls the overall assembly line.

It configures the order of the workstations and manages the movement of customer orders through the line until they are completed or identified as incomplete.

### `Utilities`

Provides reusable functionality for parsing structured input data used to initialize the application.

---

## 🔄 How It Works

```text
Input Files
     ↓
Load Station Data
     ↓
Configure Assembly Line
     ↓
Load Customer Orders
     ↓
Process Orders
     ↓
Move Between Workstations
     ↓
Completed / Incomplete Orders
```

Each customer order enters the assembly line and moves through its configured workstations.

At each workstation, the program checks whether the customer requires the item handled by that station. If inventory is available, the item is filled and the inventory is updated.

The order then continues through the line until processing is complete.

---

## 🧪 Testing

The repository includes tester programs and corresponding sample outputs for validating different stages of the application.

```text
tests/
├── tester_1.cpp
├── tester_1_sample_output.txt
├── tester_2.cpp
├── tester_2_sample_output.txt
├── tester_3.cpp
└── tester_3_sample_output.txt
```

The testers cover the individual components as well as the complete assembly-line workflow.

---

## 🛠️ Technologies

![C++](https://img.shields.io/badge/C++-596579?style=flat&logo=cplusplus&logoColor=F8E7D2)
![OOP](https://img.shields.io/badge/OOP-6E5C73?style=flat&logoColor=F8E7D2)
![STL](https://img.shields.io/badge/STL-66766B?style=flat&logoColor=F8E7D2)
![File I/O](https://img.shields.io/badge/File_I%2FO-8B6F73?style=flat&logoColor=F8E7D2)
![Move Semantics](https://img.shields.io/badge/Move_Semantics-596579?style=flat&logoColor=F8E7D2)

---

## 🌱 What I Learned

Through this project, I gained experience building a larger C++ application where multiple classes work together to model a complete workflow.

The project helped me strengthen my understanding of:

- Designing and organizing multiple related classes
- Managing object ownership and resources
- Using move semantics efficiently
- Working with STL containers and algorithms
- Processing structured data from files
- Managing dynamic memory
- Building reusable parsing functionality
- Testing individual components and complete program behaviour

---

<div align="center">

### ⚙️ C++ · OOP · STL

*Built as part of my Object-Oriented Programming coursework.*

</div>
