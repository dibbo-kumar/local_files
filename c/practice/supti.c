#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

float prices[] = {249, 349, 449, 299, 499, 399, 699, 799, 599, 799, 499, 699};
float totalfoodbill = 0;

typedef struct {
    char name[50];
    char contact[15];
    char gender[10];
    float total;
    time_t check_in_time;
} Room;

typedef struct {
    Room Superior_Room[10];
    Room Business_class_Room[10];
    Room Junior_Suite[10];
    Room Executive_Suite[10];
    Room Royal_Suite[10];
    Room Presidential_Suite[10];
    Room Total_Room[60];
} Holder;

Holder hotel_ob;

void availability(int i);
void bookRoom(int roomType);
void takeFoodOrder();
int isValidItem(int itemNumber);
int getQuantity();
void calculateSubtotal(float *subtotal, float price, int quantity);
void displayOrderDetails(int itemNumber, int quantity, float subtotal);
void displaytotalfoodbill();
void displaytotalbill(int day);
// int bill(int day);

int main() {
    FILE *roomFile;
    FILE *Foodmenu;
    int choice, ch2, day;
    char wish;

    printf("\t\t\tWelcome to RADISSON ORG\n");
    printf("\t\t  View the City Skyline from Our Hotel\n");

    do {
        printf("\nEnter your choice\n");
        printf("1. Rooms details\n");
        printf("2. Rooms availability\n");
        printf("3. Room Booking\n");
        printf("4. Food order\n");
        printf("5. Checkout\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                roomFile = fopen("Room.txt", "r");
                if (roomFile == NULL) {
                    printf("Error opening file!\n");
                    return 1;
                }

                while (!feof(roomFile)) {
                    char Rooms = fgetc(roomFile);
                    printf("%c", Rooms);
                }
                fclose(roomFile);
                break;

            case 2:
                printf("\nEnter your choice\n");
                printf("1. Superior Room\n");
                printf("2. Business Class Room\n");
                printf("3. Junior Suite\n");
                printf("4. Executive Suite\n");
                printf("5. Royal Suite\n");
                printf("6. Presidential Suite\n");
                scanf("%d", &ch2);
                availability(ch2);
                break;

            case 3:
                roomFile = fopen("Room.txt", "r");
                if (roomFile == NULL) {
                    printf("Error opening file!\n");
                    return 1;
                }

                while (!feof(roomFile)) {
                    char Rooms = fgetc(roomFile);
                    printf("%c", Rooms);
                }
                printf("\nEnter your choice: ");
                scanf("%d", &ch2);
                bookRoom(ch2);
                fclose(roomFile);
                break;

            case 4:
                Foodmenu = fopen("Food.txt", "r");
                if (Foodmenu == NULL) {
                    printf("Error opening file!\n");
                    return 1;
                }

                while (!feof(Foodmenu)) {
                    char Foods = fgetc(Foodmenu);
                    printf("%c", Foods);
                }

                takeFoodOrder();
                fclose(Foodmenu);
                break;

            case 5:
                printf("\nCheckout Process\n");
                printf("Enter day: ");
                scanf("%d",&day);
                displaytotalbill(day);
                printf("\nPlease select a payment option:\n");
                printf("1. Cash\n");
                printf("2. Credit/Debit Card\n");
                int paymentOption;
                scanf("%d", &paymentOption);
                if(paymentOption==1) {
                    printf("Please pay %.2f BDT in cash.\n",totalfoodbill );
                } else if(paymentOption==2){
                    printf("Please proceed to the card payment terminal.\n");
                } else {
                    printf("Invalid payment option.\n");
                }
                printf("Thank you for choosing Radisson. Have a pleasant day!\n");
                exit(0);
                break;

            default:
                printf("Invalid option\n");
                break;
        }

        printf("\nContinue: (y/n)\n");
        scanf(" %c", &wish);

        if (!(wish == 'y' || wish == 'Y' || wish == 'n' || wish == 'N')) {
            printf("Invalid Option\n");
            printf("\nContinue: (y/n)\n");
            scanf(" %c", &wish);
        }
    } while (wish == 'y' || wish == 'Y');

    return 0;
}

void availability(int i) {
    int j, bookedCount = 0, availableCount = 0;
    int bookedRooms[10] = {0};
    int availableRooms[10] = {0};

    switch (i) {
        case 1:
            for (j = 0; j < 10; j++) {
                if (strlen(hotel_ob.Superior_Room[j].name) == 0) {
                    availableCount++;
                    availableRooms[availableCount - 1] = j + 1;
                } else {
                    bookedCount++;
                    bookedRooms[bookedCount - 1] = j + 1;
                }
            }
            printf("%d Rooms available in Superior Room.\n", availableCount);
            printf("Available rooms: ");
            for (j = 1; j < availableCount; j++) {
                printf("%d ", availableRooms[j]);
            }
            printf("\nBooked rooms: ");
            for (j = 1; j < bookedCount; j++) {
                printf("%d ", bookedRooms[j]);
            }
            printf("\nWith Free wifi, Coffee and tea facilities\n");
            printf("Total number of rooms not booked: %d\n", availableCount);
            break;
        case 2:
            for (j = 0; j < 10; j++) {
                if (strlen(hotel_ob.Business_class_Room[j].name) == 0) {
                    availableCount++;
                    availableRooms[availableCount - 1] = j + 1;
                } else {
                    bookedCount++;
                    bookedRooms[bookedCount - 1] = j + 1;
                }
            }
            printf("%d Rooms available in Business Class Room.\n", availableCount);
            printf("Available rooms: ");
            for (j = 11; j < availableCount; j++) {
                printf("%d ", availableRooms[j]);
            }
            printf("\nBooked rooms: ");
            for (j = 11; j < bookedCount; j++) {
                printf("%d ", bookedRooms[j]);
            }
            printf("\nWith Free wifi, Coffee and tea facilities\n");
            printf("Total number of rooms not booked: %d\n", availableCount);
            break;


        case 3:
              for (j = 0; j < 10; j++) {
                if (strlen(hotel_ob.Junior_Suite[j].name) == 0) {
                    availableCount++;
                    availableRooms[availableCount - 1] = j + 1;
                } else {
                    bookedCount++;
                    bookedRooms[bookedCount - 1] = j + 1;
                }
            }
            printf("%d Rooms available in Junior Suite.\n", availableCount);
            printf("Available rooms: ");
            for (j = 21; j < availableCount; j++) {
                printf("%d ", availableRooms[j]);
            }
            printf("\nBooked rooms: ");
            for (j = 21; j < bookedCount; j++) {
                printf("%d ", bookedRooms[j]);
            }
            printf("\nWith Free wifi, Coffee and tea facilities\n");
            printf("Total number of rooms not booked: %d\n", availableCount);
            break;


        case 4:
           for (j = 0; j < 10; j++) {
                if (strlen(hotel_ob.Executive_Suite[j].name) == 0) {
                    availableCount++;
                    availableRooms[availableCount - 1] = j + 1;
                } else {
                    bookedCount++;
                    bookedRooms[bookedCount - 1] = j + 1;
                }
            }
            printf("%d Rooms available in Executive Suite.\n", availableCount);
            printf("Available rooms: ");
            for (j = 31; j < availableCount; j++) {
                printf("%d ", availableRooms[j]);
            }
            printf("\nBooked rooms: ");
            for (j = 31; j < bookedCount; j++) {
                printf("%d ", bookedRooms[j]);
            }
            printf("\nWith Free wifi, Coffee and tea facilities\n");
            printf("Total number of rooms not booked: %d\n", availableCount);
            break;

        case 5:
             for (j = 0; j < 10; j++) {
                if (strlen(hotel_ob.Royal_Suite[j].name) == 0) {
                    availableCount++;
                    availableRooms[availableCount - 1] = j + 1;
                } else {
                    bookedCount++;
                    bookedRooms[bookedCount - 1] = j + 1;
                }
            }
            printf("%d Rooms available in Royal Suite.\n", availableCount);
            printf("Available rooms: ");
            for (j = 41; j < availableCount; j++) {
                printf("%d ", availableRooms[j]);
            }
            printf("\nBooked rooms: ");
            for (j = 41; j < bookedCount; j++) {
                printf("%d ", bookedRooms[j]);
            }
            printf("\nWith Free wifi, Coffee and tea facilities\n");
            printf("Total number of rooms not booked: %d\n", availableCount);
            break;

        case 6:
              for (j = 1; j < 10; j++) {
                if (strlen(hotel_ob.Presidential_Suite[j].name) == 0) {
                    availableCount++;
                    availableRooms[availableCount - 1] = j + 1;
                } else {
                    bookedCount++;
                    bookedRooms[bookedCount - 1] = j + 1;
                }
            }
            printf("%d Rooms available in Presidential Suite.\n", availableCount);
            printf("Available rooms: ");
            for (j = 51; j < availableCount; j++) {
                printf("%d ", availableRooms[j]);
            }
            printf("\nBooked rooms: ");
            for (j = 51; j < bookedCount; j++) {
                printf("%d ", bookedRooms[j]);
            }
            printf("\nWith Free wifi, Coffee and tea facilities\n");
            printf("Total number of rooms not booked: %d\n", availableCount);
            break;

        default:
            printf("Wrong option\n");
            break;
    }
}


void bookRoom(int roomType) {
    int roomNumber;
        if(roomType==1){
    printf("Enter the room number(1-10)you want to book: ");
    scanf("%d", &roomNumber);
    }
    else if(roomType==2){
    printf("Enter the room number(11-20)you want to book: ");
    scanf("%d", &roomNumber);
    }
    else if(roomType==3){
    printf("Enter the room number(21-30)you want to book: ");
    scanf("%d", &roomNumber);
    }
    else if(roomType==4){
    printf("Enter the room number(31-40)you want to book: ");
    scanf("%d", &roomNumber);
    }
    else if(roomType==5){
    printf("Enter the room number(41-50)you want to book: ");
    scanf("%d", &roomNumber);
    }
    else if(roomType==6){
    printf("Enter the room number(51-60)you want to book: ");
    scanf("%d", &roomNumber);
    }

    switch (roomType) {
        case 1:
            roomNumber--;
            break;
        case 2:
            roomNumber += 10;
            break;
        case 3:
            roomNumber += 20;
            break;
        case 4:
            roomNumber += 30;
            break;
        case 5:
            roomNumber += 40;
            break;
        case 6:
            roomNumber += 50;
            break;
        default:
            printf("Invalid room type\n");
            return;
    }

    if (strlen(hotel_ob.Total_Room[roomNumber].name) == 0) {
        printf("Enter your name: ");
        scanf("%s", hotel_ob.Total_Room[roomNumber].name);
        printf("Enter your contact number: ");
        scanf("%s", hotel_ob.Total_Room[roomNumber].contact);
        printf("Enter your gender: ");
        scanf("%s", hotel_ob.Total_Room[roomNumber].gender);
        hotel_ob.Total_Room[roomNumber].check_in_time = time(NULL);
        printf("Room booked successfully!\n");
    } else {
        printf("Room already booked\n");
    }
}

void takeFoodOrder() {
    int itemNumber, quantity;
    char choice;

    do {
        printf("\nEnter the item number to order (1-12): ");
        scanf("%d", &itemNumber);

        if (isValidItem(itemNumber)) {
            quantity = getQuantity();

            if (quantity > 0) {
                float subtotal;
                calculateSubtotal(&subtotal, prices[itemNumber - 1], quantity);
                totalfoodbill += subtotal;
                displayOrderDetails(itemNumber, quantity, subtotal);
            } else {
                printf("Invalid quantity.\n");
            }
        } else {
            printf("Invalid item number.\n");
        }

        printf("\nDo you want to add more items? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');


}

int isValidItem(int itemNumber) {
    return (itemNumber >= 1 && itemNumber <= 12);
}

int getQuantity() {
    int quantity;
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    return quantity;
}

void calculateSubtotal(float* subtotal, float price, int quantity) {
    *subtotal = price * quantity;
}

void displayOrderDetails(int itemNumber, int quantity, float subtotal) {
    printf("Ordered: Item %d x %d\n", itemNumber, quantity);

}

void displaytotalbill(int day) {
    int roomNumber;
    float hotelbill = 0;
    printf("Enter room number between 1 to 60 : ");
    scanf("%d", &roomNumber);

    if(roomNumber>=1 && roomNumber<=10) {
        hotelbill = day * 4999;
    }
    else if(roomNumber>=11 && roomNumber<=20) {
        hotelbill = day * 5999;
    }
    else if(roomNumber>=21 && roomNumber<=30) {
        hotelbill = day * 6999;
    }
    else if(roomNumber>=31 && roomNumber<=40) {
        hotelbill = day * 7999;
    }
    else if(roomNumber>=41 && roomNumber<=50) {
        hotelbill = day * 8999;
    }
    else if(roomNumber>=51 && roomNumber<=60) {
        hotelbill = day * 9999;
    }
    else {
        printf("Invalid room number\n");
        return;
    }

    float totalbill = hotelbill + totalfoodbill;
    printf("\nGuest name: %s", hotel_ob.Total_Room[roomNumber - 1].name);
    printf("\nGuest contact: %s", hotel_ob.Total_Room[roomNumber - 1].contact);
    printf("\nRestaurant bill: %.2f\n", totalfoodbill);
    printf("Hotel bill: %.2f\n", hotelbill);
    printf("\nTotal bill: %.2f\n", totalbill);

    int bill = totalbill;

}
