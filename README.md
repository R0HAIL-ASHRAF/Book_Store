# OOP_Project
**User-Admin Access System With E-Commerce Functionality**

A desktop application built in **C++** using the **wxWidgets GUI Framework**. This system provides a unified login panel for the **Users**, **Store Managers** and **Admin** with role-base access control. It includes features such as
- Cart System
- Online Card Payment
- Product Management(book & stationery)
- Thread Workflow
- Weekly Reports
- Logging
- Exception Handlings

It showcases a comprehensive understanding of C++ programming, GUI development using wxWidgets. Hence, it is designed to function as **proof-of-concept desktop development application** suitable for learning, academic representations, and future development into a full-fledge commercial product.


## Architecture & Design

### Object-Oriented Structure
- Polymorphic and modular:
  - Base classes: `Person`, `Product`
  - Derived: `Book`, `Stationery`, `Customer`, `Admin`, etc.
- Custom collections using `MyVector`.
- File handling via overridden `writeToFile()` and `readFromFile()` methods.

### GUI Framework: wxWidgets
- Panels include:
  - `LoginPanel`, `SignupPanel`, `DashboardPanel`, `CartPanel`, etc.
- Interactivity via `wxTextCtrl`, `wxButton`, `wxListBox`.
- View switches handled with `MainFrame` routing functions like:
  ```cpp
  void MainFrame::SwitchToDashboard() const;
  void MainFrame::SwitchToBookPanel() const;


## Features at a Glance

|  Module          |  Features                                                                 |
|------------------|------------------------------------------------------------------------------|
| **Authentication** | Login, signup, file-based credential validation                            |
| **Product System** | Add, edit, remove books/stationery, view by category                       |
| **Shopping Cart** | Add/remove products, calculate totals, store in temporary cart files        |
| **Payment System**| Card validation, payment info binding, shipping & taxes                     |
| **Admin Panel**   | Manage multiple stores, assign store managers, view/edit customers/products |
| **Dashboard UX**  | Clean navigation using wxWidgets, dynamic panel switching                   |

---

# UML & Activity Diagrams
Click to view:
- [UML](WorkFLow/UML.pdf/)
- [LOGIN/SIGUP](WorkFLow/AD-Login_Signup.pdf)
- [AddBook](WorkFLow/AD-addBook.pdf)
- [EditProfile](WorkFLow/AD-EditProfile.pdf)
- [AddCart](WorkFLow/AD-add-to-cart.pdf)

# Tech Stack
| Layer         | Technology                    |
|---------------|-------------------------------|
| Language      | C++                           |
| GUI FrameWork | wxWidgets                     |
| File I/O      | Standard C++                  |
| Data Storage  | File System(No Database)      |


## Project Status
This is an ongoing project with active development, as a part of the semester project for **Object Oriented Programming(OOP)**.

# PreRequisites
- C++ Complier(GCC/Clang/MSVC)
- wxWidgets (1998) 
``` bash 
# Linux (Debian-based)
sudo apt install libwxgtk3.0-gtk3-dev

# install from
https://www.wxwidgets.org/downloads/
```
