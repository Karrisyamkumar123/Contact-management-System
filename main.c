#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phoneNumber[20];
    char email[50];
    char bloodGroup[5];
    char lastDonationDate[20]; // Just for demonstration (e.g., "2024-12-01")
};

struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[numContacts].name, 50, stdin);
    contacts[numContacts].name[strcspn(contacts[numContacts].name, "\n")] = 0;

    printf("Enter phone number: ");
    fgets(contacts[numContacts].phoneNumber, 20, stdin);
    contacts[numContacts].phoneNumber[strcspn(contacts[numContacts].phoneNumber, "\n")] = 0;

    printf("Enter email: ");
    fgets(contacts[numContacts].email, 50, stdin);
    contacts[numContacts].email[strcspn(contacts[numContacts].email, "\n")] = 0;

    printf("Enter blood group: ");
    fgets(contacts[numContacts].bloodGroup, 5, stdin);
    contacts[numContacts].bloodGroup[strcspn(contacts[numContacts].bloodGroup, "\n")] = 0;

    printf("Enter last blood donation date (YYYY-MM-DD): ");
    fgets(contacts[numContacts].lastDonationDate, 20, stdin);
    contacts[numContacts].lastDonationDate[strcspn(contacts[numContacts].lastDonationDate, "\n")] = 0;

    numContacts++;
    printf("Contact added successfully.\n");
}

void listContacts() {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Contact List:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone Number: %s\n", contacts[i].phoneNumber);
        printf("Email: %s\n", contacts[i].email);
        printf("Blood Group: %s\n", contacts[i].bloodGroup);
        printf("Last Donation Date: %s\n\n", contacts[i].lastDonationDate);
    }
}

void searchContact() {
    char searchName[50];
    printf("Enter name to search: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact Found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phoneNumber);
            printf("Email: %s\n", contacts[i].email);
            printf("Blood Group: %s\n", contacts[i].bloodGroup);
            printf("Last Donation Date: %s\n\n", contacts[i].lastDonationDate);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void editContact() {
    char searchName[50];
    printf("Enter name to edit: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Enter new name: ");
            fgets(contacts[i].name, 50, stdin);
            contacts[i].name[strcspn(contacts[i].name, "\n")] = 0;

            printf("Enter new phone number: ");
            fgets(contacts[i].phoneNumber, 20, stdin);
            contacts[i].phoneNumber[strcspn(contacts[i].phoneNumber, "\n")] = 0;

            printf("Enter new email: ");
            fgets(contacts[i].email, 50, stdin);
            contacts[i].email[strcspn(contacts[i].email, "\n")] = 0;

            printf("Enter new blood group: ");
            fgets(contacts[i].bloodGroup, 5, stdin);
            contacts[i].bloodGroup[strcspn(contacts[i].bloodGroup, "\n")] = 0;

            printf("Enter new last donation date: ");
            fgets(contacts[i].lastDonationDate, 20, stdin);
            contacts[i].lastDonationDate[strcspn(contacts[i].lastDonationDate, "\n")] = 0;

            printf("Contact edited successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    char searchName[50];
    printf("Enter name to delete: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            for (int j = i; j < numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            numContacts--;
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void listBloodDonorsByGroup() {
    char group[5];
    printf("Enter blood group to filter: ");
    fgets(group, 5, stdin);
    group[strcspn(group, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].bloodGroup, group) == 0) {
            printf("Donor: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phoneNumber);
            printf("Email: %s\n", contacts[i].email);
            printf("Last Donation: %s\n\n", contacts[i].lastDonationDate);
            found = 1;
        }
    }

    if (!found) {
        printf("No donors found with that blood group.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nContact Management System with Blood Donation\n");
        printf("1. Add a new Contact\n");
        printf("2. List all Contacts\n");
        printf("3. Search for contact\n");
        printf("4. Edit a Contact\n");
        printf("5. Delete a Contact\n");
        printf("6. List Blood Donors by Group\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                editContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                listBloodDonorsByGroup();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
