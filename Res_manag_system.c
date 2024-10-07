#include <stdio.h>
#include <stdlib.h>

#define MENU_ITEMS 10
// Structure to store menu item
struct MenuItem {
    char name[30];
    float price;
};
//Function prototype
void takeOrder(struct MenuItem menu[], float *total);
void displayMenu(struct MenuItem menu[]);

//Start Main program
int main() 
{
    struct MenuItem menu[MENU_ITEMS] = {
        {"Pizza",     120.00},
        {"Burger",    99.00},
        {"Pasta",     70.00},
        {"Fries",     70.00},
        {"Salad",     50.00},
        {"Ice Cream", 110.00},
        {"Coffee",    60.00},
        {"Tea",       15.00},
        {"Juice",     30.00},
        {"Milk",      20.00}
    };
    
    float total = 0;
    int choice;

    printf("Welcome to the Restaurant Management System\n");
    
    while (1) 
    {
        displayMenu(menu);
        takeOrder(menu, &total);

        printf("Do you want to order more? (1-Yes, 0-No): ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
    }

    printf("\nTotal bill: Rs%.2f\n", total);
    printf("Thank you for dining with us!\n");
    
    return 0;
}

// Function to display the menu
void displayMenu(struct MenuItem menu[]) 
{
	int i;
    printf("\n------- Restaurant Menu -------\n");
    for (i = 0; i < MENU_ITEMS; i++) {
        printf("%d. %s - Rs%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("-------------------------------\n");
}

// Function to take order from user
void takeOrder(struct MenuItem menu[], float *total) 
{
    int choice, quantity;
    printf("\nEnter the item number to order (1-%d) or 0 to finish: ", MENU_ITEMS);
    scanf("%d", &choice);
    
    if (choice > 0 && choice <= MENU_ITEMS) 
    {
        printf("Enter quantity for %s: ", menu[choice-1].name);
        scanf("%d", &quantity);
        *total += menu[choice-1].price * quantity;
        printf("Total quantity %d for %s added to the order. Total so far: Rs%.2f\n", quantity, menu[choice-1].name, *total);
    } 
    else if (choice == 0) {
        printf("Order completed.\n");
    } 
    else {
        printf("Invalid choice! Try again.\n");
    }
}

