#include <stdio.h>
#include <stdlib.h>

#define MENU_ITEMS 10  // Number of items on the menu

int main() 
{
	
    // Structure to represent a menu item with name and price
    struct MenuItem {
        char name[30];  // Name of the menu item
        float price;    // Price of the menu item
    };
    
    // Array of 10 menu items with their names and corresponding prices
    struct MenuItem menu[MENU_ITEMS] = {
        {"Pizza",     120.00},   // Item 1
        {"Burger",    99.00},    // Item 2
        {"Pasta",     70.00},    // Item 3
        {"Fries",     70.00},    // Item 4
        {"Salad",     50.00},    // Item 5
        {"Ice Cream", 110.00},   // Item 6
        {"Coffee",    60.00},    // Item 7
        {"Tea",       15.00},    // Item 8
        {"Juice",     30.00},    // Item 9
        {"Milk",      20.00}     // Item 10
    };
    
    // Variable to store the total bill amount, initialized to zero
    float total = 0;
    
    // Variables to hold the choice of the item and quantity ordered
    int choice,i;
    int quantity;

    // Displaying welcome message
    printf("Welcome to the Restaurant Management System\n");
    printf("You can place your order by selecting from the menu below.\n");

    // Loop to continue ordering until the user chooses to finish
    while (1) 
    {
        // Display the menu
        printf("\n------- Restaurant Menu -------\n");
        
        // Loop to print each menu item with its corresponding price
        for (i = 0; i < MENU_ITEMS; i++) {
            // Printing the menu item number, name, and price
            printf("%d. %s - Rs%.2f\n", i + 1, menu[i].name, menu[i].price);
        }
        
        // Ending line for menu display
        printf("-------------------------------\n");

        // Prompting the user to select an item from the menu
        printf("\nEnter the item number to order (1-%d) or 0 to finish: ", MENU_ITEMS);
        scanf("%d", &choice);  // Reading the user's choice of menu item

        // Check if the user entered a valid choice between 1 and 10
        if (choice > 0 && choice <= MENU_ITEMS) 
        {
            // Asking for the quantity of the selected item
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &quantity);  // Reading the quantity input
            
            // Calculate and add the price of the selected item times the quantity to the total
            total += menu[choice - 1].price * quantity;
            
            // Displaying the added item and updated total
            printf("Total quantity %d for %s added to the order.\n", quantity, menu[choice - 1].name);
            printf("Current total so far: Rs%.2f\n", total);
        } 
        else if (choice == 0)  // If user entered 0, they want to finish ordering
        {
            // Message indicating that the order is complete
            printf("Order completed.\n");
            break;  // Exit the loop as no more items are being ordered
        } 
        else  // If an invalid choice was entered
        {
            // Error message for invalid menu item choice
            printf("Invalid choice! Please try again.\n");
        }

        // Asking the user if they want to continue ordering more items
        printf("Do you want to order more? (1-Yes, 0-No): ");
        scanf("%d", &choice);  // Reading the user's decision
        
        // Check if the user chooses to exit by entering 0
        if (choice == 0) {
            break;  // Exit the loop if the user doesn't want to order more
        }
    }

    // Displaying the final bill after all orders are placed
    printf("\nThank you for your order!\n");
    printf("Your total bill is: Rs%.2f\n", total);  // Print the total amount
    
    // Thanking the user for dining
    printf("We hope to serve you again!\n");

    // Return statement indicating successful execution of the program
    return 0;
}
