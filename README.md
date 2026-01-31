
This README.md provides a professional overview of your Contact Management System, detailing its features, structure, and usage instructions.

Contact Management System (with Blood Donation Tracking)
A lightweight, console-based application written in C to manage personal contacts with an integrated feature for tracking blood donation details. This system allows users to store contact information, search for individuals, and filter donors based on their blood group.

Features
CRUD Operations: Add, list, search, edit, and delete contacts seamlessly.

Blood Group Tracking: Store specific blood group information for each contact.

Donor Filtering: Quickly find potential donors by filtering the list by blood group.

Memory Management: Uses a structured array to manage up to 100 contacts.

Input Handling: Uses fgets and strcspn for robust string input, preventing common buffer issues associated with scanf.

Data Structure
The application centers around a Contact struct, which organizes the following data:

Field	Description
Name	Full name of the contact (up to 50 characters).
Phone Number	Primary contact number.
Email	Email address for communication.
Blood Group	A, B, AB, O (Positive/Negative).
Last Donation	The date of the last blood donation (YYYY-MM-DD).
How to Use
1. Prerequisites
You will need a C compiler (like gcc, clang, or MinGW) installed on your system.

2. Compilation
Open your terminal or command prompt and run:

Bash
gcc main.c -o contact_manager
3. Execution
Run the compiled executable:

Bash
./contact_manager
4. Menu Navigation
Upon running, you will be presented with a numbered menu:

Add: Enter new contact details.

List: View all currently saved contacts.

Search: Find a specific contact by their name.

Edit: Modify existing details for a contact.

Delete: Remove a contact from the registry.

Filter: Display only contacts matching a specific blood group.

Exit: Safely close the program.

Technical Considerations
Static Allocation: The system currently supports a maximum of 100 contacts defined by MAX_CONTACTS.

Case Sensitivity: Searches and edits are case-sensitive. "John" and "john" will be treated as different entries.

Data Persistence: This version stores data in RAM; information will be cleared once the program is closed.
