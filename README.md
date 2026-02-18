Bank Project OOP
=================

Overview
--------

`Bank Project OOP` is a small, console-based banking system implemented in C++ using object-oriented programming concepts. The project demonstrates class design for users and clients, basic input validation, a login screen, and a simple interactive menu for banking operations.

Key Concepts
------------

- Encapsulation and class design
- Basic input validation and utilities
- Simple console user interface (login loop and menu)
- Date and string helper utilities

Features
--------

- User login screen (`clsLoginScreen`) with a loop in `Bank Project OOP.cpp`
- Bank user management (`clsBankUsers`)
- Bank client model (`clsBankClient`)
- Utility helpers: `clsUtil`, `clsString`, `clsDate`
- Input validation (`clsIsInputValidate`)
- Transaction and main menu screens (`clsTransactionMenue`, `clsMainScreen`)

Repository Structure
--------------------

- `Bank Project OOP.cpp` - program entry point, runs the login loop
- `clsLoginScreen.*` - login screen handling
- `clsBankUsers.*` - bank users management
- `clsBankClient.*` - client model and operations
- `clsTransactionMenue.*` - transaction menu UI
- `clsMainScreen.*` - main application menu
- `clsUtil.*`, `clsString.*`, `clsDate.*`, `clsIsInputValidate.*` - helper utilities

Requirements
------------

- C++ compiler (MSVC via Visual Studio or GCC/MinGW)
- Tested with Visual Studio (any recent version) and MSVC toolchain

Build and Run
-------------

Using Visual Studio (recommended):
1. Open the `.Bank Project OOP.cpp` solution in Visual Studio.
2. Build the solution (Ctrl+Shift+B).
3. Run (F5) or start without debugging (Ctrl+F5).
4.Enter credentials at the login screen and navigate the menus.
5.User Name `Admin` and Password `1234` are hardcoded for testing.
6.Clients Data is Recorded in Text File `Clients.txt` in the project directory. 
7.Users Login Information is Recorded in Text File `Users.txt` in the project directory.
7. You can add clients by using the `Add Client` option in the main menu after logging in.

Using g++ / MinGW (command line):
1. From the project directory, compile all `.cpp` files. Example (adjust file list):

`g++ -std=c++17 -O2 -Wall "Bank Project OOP.cpp" cls*.cpp -o BankApp.exe`

2. Run the produced executable: `./BankApp.exe` (or `BankApp.exe` on Windows).

Usage
-----

- The application starts at the login screen. Enter credentials to authenticate.
- After login, navigate the displayed menus to perform client/banking operations.
- The main loop will repeat the login screen until you choose to exit.

Extending the Project
---------------------

- Add persistent storage (file or database) to save clients and transactions.
- Implement more robust authentication and permission roles.
- Add unit tests for core logic and validation functions.

Contributing
------------

Contributions are welcome. Please fork the repository, make changes on a feature branch, and submit a pull request with a short description of your change.

License
-------

This repository does not include a license file. If you want to publish it on GitHub, consider adding an open-source license such as the MIT License.

Contact / Notes
---------------

This README is based on the current project sources visible in the workspace. Update the build line to include the exact `.cpp` files if you compile from the command line.