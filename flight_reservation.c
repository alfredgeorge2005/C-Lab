#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 5
#define MAX_SEATS 50

typedef struct {
    int flightID;
    char destination[30];
    int availableSeats;
    int totalSeats;
} Flight;

Flight flights[MAX_FLIGHTS];

void initializeFlights() {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].flightID = i + 1;
        sprintf(flights[i].destination, "City_%d", i + 1);
        flights[i].availableSeats = MAX_SEATS;
        flights[i].totalSeats = MAX_SEATS;
    }
}

void displayFlights() {
    printf("\nAvailable Flights:\n");
    printf("------------------------------------------------\n");
    printf("Flight ID  | Destination   | Available Seats\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("   %d       | %-14s | %d/%d\n", 
               flights[i].flightID, flights[i].destination, 
               flights[i].availableSeats, flights[i].totalSeats);
    }
    printf("------------------------------------------------\n");
}

void bookSeat(int flightID) {
    if (flightID <= 0 || flightID > MAX_FLIGHTS) {
        printf("Invalid Flight ID. Please try again.\n");
        return;
    }

    if (flights[flightID - 1].availableSeats > 0) {
        flights[flightID - 1].availableSeats--;
        printf("You've successfully booked a seat on Flight ID %d to %s.\n", 
               flightID, flights[flightID - 1].destination);
    } else {
        printf("No available seats on Flight ID %d. Please choose another flight.\n", flightID);
    }
}

void cancelReservation(int flightID) {
    if (flightID <= 0 || flightID > MAX_FLIGHTS) {
        printf("Invalid Flight ID. Please enter a valid Flight ID to cancel.\n");
        return;
    }

    if (flights[flightID - 1].availableSeats < flights[flightID - 1].totalSeats) {
        flights[flightID - 1].availableSeats++;
        printf("Your reservation for Flight ID %d to %s has been canceled.\n", 
               flightID, flights[flightID - 1].destination);
    } else {
        printf("There are no reservations to cancel for Flight ID %d.\n", flightID);
    }
}

int main() {
    int choice, flightID;

    initializeFlights();

    printf("Welcome to the Flight Reservation System!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. View Available Flights\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlights();
                break;
            case 2:
                printf("Enter the Flight ID to book a seat: ");
                scanf("%d", &flightID);
                bookSeat(flightID);
                break;
            case 3:
                printf("Enter the Flight ID to cancel your reservation: ");
                scanf("%d", &flightID);
                cancelReservation(flightID);
                break;
            case 4:
                printf("Thank you for using the Flight Reservation System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
