This is a professional, comprehensive `README.md` file designed to serve as the homepage for your GitHub repository. It includes all technical specifications, a curriculum guide, and best practices for exception handling in C++11.

---

# CPP Hall of Exceptions 🛡️

Welcome to the **CPP Hall of Exceptions**! This repository is a curated curriculum designed to take you from C++ exception handling basics to advanced, real-world hierarchical architectures. All programs are strictly compatible with **C++11**, ensuring they run across all modern and legacy compilers.

[Place holder for a welcoming "Hello World" or Exception Flow GIF]

## 📋 About the Curriculum
Exception handling is the art of making software resilient. Instead of allowing a program to crash when it encounters an error (like a lost connection or a bad input), we use the `try-catch` mechanism to recover gracefully. This repository contains 16 progressive examples that cover:
* Fundamental syntax (`try`, `throw`, `catch`).
* Standard Library exception classes.
* Object-Oriented patterns (Inheritance, Polymorphism).
* Professional system design (Nested handlers and re-throwing).

## 🛠️ C++ Specification
* **Version:** C++11 (Standard)
* **Compatibility:** GCC, Clang, MSVC (Windows)
* **Focus:** Beginner-friendly, detailed commenting, and real-world CS scenarios.

---

## 🚀 Getting Started

### Cloning the Repository
Open your terminal or command prompt and run:

**Windows (PowerShell/CMD), macOS, and Linux:**
```bash
git clone https://github.com/kaniska-praba007/cpp-hall-of-exceptions.git
cd cpp-hall-of-exceptions
```

### Running Files in VS Code
1. Install the **C/C++ Extension** by Microsoft.
2. Open the repository folder in VS Code.
3. Open any `.cpp` file.
4. Press `Ctrl + F5` (Windows/Linux) or `Cmd + F5` (macOS) to run without debugging.
5. **Note:** Ensure your compiler is set to C++11. Most modern compilers do this by default, but you can manually compile in the terminal using:
   `g++ -std=c++11 filename.cpp -o output`

---

## 📚 Curriculum Path
The files are numbered `01` to `16` to guide your learning journey. 

| File | Concept | Focus |
| :--- | :--- | :--- |
| `01_Division-by-Zero.cpp` | Foundations | Handling math errors using string literals. |
| `02_Accessing-Memory.cpp` | Safety | Buffer safety using `std::out_of_range`. |
| `03_Invalid-argument.cpp` | Input Validation | Logic checks using `std::invalid_argument`. |
| `04_Memory-Allocation.cpp` | System Limits | Handling RAM exhaustion with `std::bad_alloc`. |
| `05_Unknown-Exception.cpp` | Safety Net | The catch-all `...` ellipsis block. |
| `06_Invoked-Function.cpp` | Propagation | How exceptions "bubble up" through function calls. |
| `07_Constructors-and-Destructors.cpp`| Cleanup | Stack Unwinding and automatic resource cleanup. |
| `08_Multi-level-Exception.cpp` | Delegation | Re-throwing exceptions with `throw;`. |
| `09_Function-Template.cpp` | Generics | Using templates for type-agnostic error handling. |
| `10_Restricting-Exceptions.cpp` | Optimization | The `noexcept` specifier for performance. |
| `11_Operator-Overloading.cpp` | Custom Logic | Handling errors within overloaded operators. |
| `12_Custom-Exception.cpp` | Specialization | Overriding `std::exception` for custom types. |
| `13_Inheritance.cpp` | Polymorphism | Catching derived errors by base-class reference. |
| `14_Uncaught-Exceptions.cpp` | Resilience | Using `std::set_terminate` for global recovery. |
| `15_Web_Server.cpp` | Architecture | Implementation of nested try-catch blocks. |
| `16_User-Account-System.cpp` | Final Project | Robust, real-world hierarchical exception handling. |

> **Note:** Every program includes a **Sample Output** commented at the bottom for reference.

---

## 🏛️ Standard Exception Hierarchy
C++ provides a rich hierarchy of exception classes. Understanding this structure is key to efficient catching.


* **std::exception**: The base class for all standard exceptions.
    * **std::logic_error**: Errors that could have been prevented by better logic (e.g., `invalid_argument`, `out_of_range`).
    * **std::runtime_error**: Errors that are difficult to predict before execution (e.g., `overflow_error`, `system_error`).

---

## 💡 Our Approach & Tips

* **Catch by Reference:** We prioritize `catch (const exception& e)` to avoid "object slicing" and keep the program memory-efficient.
* **Specifics First:** We always place specific catch blocks (e.g., `invalid_argument`) above general ones (`exception`) to ensure the correct handler is triggered.
* **RAII (Resource Acquisition Is Initialization):** We emphasize the use of destructors to ensure files and memory are cleaned up automatically during an exception jump.
* **The Persistence Rule:** In real-world apps like the User Account System, we wrap logic in loops to ensure the program "runs at all costs" until valid input is received.

---

## 🤝 Contributing
Feel free to fork this repo and add more CS-based scenarios! If you find a bug or a typo, pull requests are always welcome.

[Place holder for a "Thank You" or "Happy Coding" GIF]

---
*Created with ❤️ by kaniska-praba007*
