# Bank Management System 🏦

A robust **Bank Management System** console application developed in C++ utilizing Object-Oriented Programming (OOP) principles. This project was built as a Project-Based Learning (PBL) assignment to demonstrate real-world banking operations, polymorphism, file handling concepts, and modular design.

---

## 🚀 Features

* **Account Management**: Create and manage distinct account types (Savings and Current Accounts).
* **Polymorphism & Inheritance**: Implements base `Account` class with derived `SavingsAccount` and `CurrentAccount` subclasses utilizing virtual functions and function overriding.
* **Core Banking Operations**: 
  * Deposit funds with validation.
  * Withdraw funds with custom business logic (e.g., maintaining minimum balance requirements for current accounts).
  * Calculate and credit interest for savings accounts.
* **Data Storage**: Local data saving structure for persistence.
* **Interactive CLI**: Easy-to-use numbered menu system for seamless navigation.

---

## 🛠️ Tech Stack & Concepts

* **Language**: C++
* **Paradigm**: Object-Oriented Programming (OOP)
  * Inheritance
  * Polymorphism (Virtual Functions & Overriding)
  * Encapsulation
* **Libraries Used**: `<iostream>`, `<fstream>`, `<string>`

---

## ⚙️ Getting Started & Installation

Follow these steps to run the project locally on your machine:

### Prerequisites
Make sure you have a C++ compiler installed (such as GCC/MinGW via MSYS2). You can verify your installation by running:
```bash
g++ --version
