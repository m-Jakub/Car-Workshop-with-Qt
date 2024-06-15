# Car Workshop Management System

This desktop application is developed using C++ and Qt to help manage car repair tickets, estimates, and repair schedules efficiently. Project was developed as part of the Graphical User Interfaces (EGUI) course.

## Features

- **Ticket Management**: Add, update, delete, and display tickets for car repairs.
- **Estimate Management**: View and update repair estimates, including descriptions, expected costs, and client acceptance status.
- **Repair Scheduling**: Select and save repair time slots in a calendar view. Save schedules as PDF documents.

## Key Components

### DatabaseManager

- Manages database connections and operations.
- Executes SQL queries to add, remove, and update tickets and related data.

### Tickets

- Main interface for managing car repair tickets.
- Displays tickets in a `QTableWidget`.
- Provides functionalities to add, update, and delete tickets.
- Handles user interactions with the table and buttons.

### Estimate

- Manages repair estimates.
- Allows viewing and updating details like description, expected cost, and client acceptance status.

### Calendar

- Manages repair scheduling.
- Allows selecting time slots in a `QTableWidget`.
- Saves the selected schedule to a PDF document.

## Setup and Installation

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/m-Jakub/Car-Workshop-with-Qt.git
    cd Car-Workshop-with-Qt
    ```

2. **Install Qt**:
    - Ensure you have Qt installed on your system. You can download it from [Qt's official website](https://www.qt.io/download).

3. **Open Project in Qt Creator**:
    - Open Qt Creator.
    - Go to `File` -> `Open File or Project...`.
    - Navigate to the cloned repository and select the `lab1.pro` file.
    - Click `Configure Project` and follow the prompts to set up the build environment.

4. **Build and Run the Project**:
    - Click on the green play button (Run) on the left side of Qt Creator or press `Ctrl+R`.
    - Qt Creator will build the project and launch the application.

## Usage

### Ticket Management

- **Add Ticket**: Click on the "Add" button to open the dialog for adding a new ticket. Fill in the details and click "OK".
- **Update Ticket**: Select a ticket from the table, modify the details, and click "Update".
- **Delete Ticket**: Select a ticket and click "Delete". Confirm the deletion in the dialog that appears.

### Estimate Management

- **View/Update Estimate**: Select a ticket and click on the "Estimate" button to open the estimate dialog. Modify the details and click "Save".

### Repair Scheduling

- **Select Time Slots**: Click on the cells in the calendar to select time slots for repairs.
- **Save Schedule as PDF**: Click the "Save as PDF" button, choose a location, and save the schedule.

## Screenshots


![main_menu](https://github.com/m-Jakub/Car-Workshop-with-Qt/assets/133584402/6e81e089-3589-4d9e-8a4c-994d1c489622)

---
![calendar](https://github.com/m-Jakub/Car-Workshop-with-Qt/assets/133584402/859fadc5-28cd-4a5e-833a-1bf0034ecf8d)

---
![ticket_calendar](https://github.com/m-Jakub/Car-Workshop-with-Qt/assets/133584402/fd777493-aba6-4b26-b8fa-0ee6541134ab)

---
![parts](https://github.com/m-Jakub/Car-Workshop-with-Qt/assets/133584402/80c1134f-b6d9-4cd0-b724-df2dc02a5c29)

---
![assing_another_employee](https://github.com/m-Jakub/Car-Workshop-with-Qt/assets/133584402/49da5476-e22e-4010-859a-5b368bab1bad)
