/**************************************************************************************************
 * TCES 203: Drone Fleet Management System
 * Names: Keith Smith
 * Autumn 2025
 * Instructor: Dr. Damiano Torre
 * 
 * Chosen Variations:
 * Variation 1A: Basic Console Menu
 * Variation 2B: Nearest Drone Finder
 **************************************************************************************************/

#include <stdio.h>
#include <string.h> // For string manipulation in search
#include <math.h>   // For Euclidean distance in Variation 2B

// =================================================================================================
// 1. CONSTANTS & GLOBAL DATA STRUCTURES
// =================================================================================================

// Define constants for maximum fleet size and model name length
#define MAX_FLEET_SIZE 100 // Example size, can be adjusted
#define MAX_NAME_LEN 50    // Example length for drone model names

// Global arrays to store drone data
int droneIDs[MAX_FLEET_SIZE];
char droneModels[MAX_FLEET_SIZE][MAX_NAME_LEN];
float droneBatteries[MAX_FLEET_SIZE];
float dronePositions[MAX_FLEET_SIZE][2]; // Stores [x, y] coordinates

// Global variable to keep track of the current number of drones in the fleet.
int currentDroneCount = 0;

// =================================================================================================
// 2. FUNCTION PROTOTYPES
// =================================================================================================

// --- Problem 1 Functions ---
void addDrone();
void displayDrones();

// --- Problem 2 Functions ---
void searchDroneByID();
void calculateAverageBattery();

// --- Variation 2B Function ---
void findNearestDrone();

// --- Helper Function ---
void displayMenu();


// =================================================================================================
// 3. MAIN FUNCTION (PROGRAM DRIVER)
// =================================================================================================

int main() {
    int choice = 0;

    // Loop to keep showing the menu until the user chooses to exit
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDrone();
                break;
            case 2:
                displayDrones();
                break;
            case 3:
                searchDroneByID();
                break;
            case 4:
                calculateAverageBattery();
                break;
            case 5:
                findNearestDrone(); // Corresponds to Variation 2B
                break;
            case 6:
                printf("Exiting Drone Fleet Management System. Goodbye! 🚁\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");

    } while (choice != 6);

    return 0;
}


// =================================================================================================
// 4. FUNCTION DEFINITIONS
// =================================================================================================

/**
 * @brief Displays the main menu options to the user.
 */
void displayMenu() {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║  Drone Fleet Management System 🚁     ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  1. Add a drone                        ║\n");
    printf("║  2. Display all drones                 ║\n");
    printf("║  3. Search by ID                       ║\n");
    printf("║  4. Show average battery               ║\n");
    printf("║  5. Find nearest drone                 ║\n");
    printf("║  6. Exit                               ║\n");
    printf("╚════════════════════════════════════════╝\n");
}

// -------------------------------------------------------------------------------------------------
// Problem 1: Core Setup and Drone Management
// -------------------------------------------------------------------------------------------------

/**
 * @brief Prompts the user for drone information, validates it, and adds it to the fleet arrays.
 * This function handles storing the ID, model, battery, and position.
 */
void addDrone() {
    // 1. Check if the fleet is full
    if (currentDroneCount >= MAX_FLEET_SIZE) {
        printf("❌ Fleet is full! Cannot add more drones.\n");
        return;
    }

    int id;
    char model[MAX_NAME_LEN];
    float battery, x, y;

    // 2. Prompt for drone ID
    printf("\n--- Add New Drone ---\n");
    printf("Enter Drone ID (positive integer): ");
    scanf("%d", &id);

    // 3. Validate ID (must be positive and unique)
    if (id <= 0) {
        printf("❌ Invalid ID. ID must be a positive integer.\n");
        return;
    }

    // Check for duplicate ID
    for (int i = 0; i < currentDroneCount; i++) {
        if (droneIDs[i] == id) {
            printf("❌ Drone with ID %d already exists!\n", id);
            return;
        }
    }

    // Prompt for model name
    printf("Enter Drone Model: ");
    scanf(" %[^\n]", model);  // Read string with spaces

    // Prompt for battery level
    printf("Enter Battery Level (0-100): ");
    scanf("%f", &battery);

    // Validate battery level
    if (battery < 0 || battery > 100) {
        printf("❌ Invalid battery level. Must be between 0 and 100.\n");
        return;
    }

    // Prompt for position coordinates
    printf("Enter Position X: ");
    scanf("%f", &x);
    printf("Enter Position Y: ");
    scanf("%f", &y);

    // 4. Store all data in global arrays
    droneIDs[currentDroneCount] = id;
    strcpy(droneModels[currentDroneCount], model);
    droneBatteries[currentDroneCount] = battery;
    dronePositions[currentDroneCount][0] = x;
    dronePositions[currentDroneCount][1] = y;

    currentDroneCount++;
    printf("✅ Drone added successfully! Total drones: %d\n", currentDroneCount);
}

/**
 * @brief Displays all drones currently in the fleet in a well-formatted table.
 * The table includes ID, Model, Battery, and X/Y coordinates.
 */
void displayDrones() {
    // Check if there are any drones
    if (currentDroneCount == 0) {
        printf("\n📭 No drones in the fleet.\n");
        return;
    }

    // 1. Print table header
    printf("\n--- Drone Fleet Status ---\n");
    printf("%-6s | %-20s | %-8s | %-8s | %-8s\n", "ID", "Model", "Battery", "X", "Y");
    printf("-------+----------------------+----------+----------+----------\n");

    // 2. Loop through all drones and display their information
    for (int i = 0; i < currentDroneCount; i++) {
        printf("%-6d | %-20s | %7.1f%% | %8.2f | %8.2f\n",
               droneIDs[i],
               droneModels[i],
               droneBatteries[i],
               dronePositions[i][0],
               dronePositions[i][1]);
    }

    printf("\nTotal Drones: %d\n", currentDroneCount);
}


// -------------------------------------------------------------------------------------------------
// Problem 2: Search, Calculations, and Robustness
// -------------------------------------------------------------------------------------------------

/**
 * @brief Prompts the user for a drone ID and searches for it in the fleet.
 * Displays the drone's details if found, otherwise prints a "not found" message.
 */
void searchDroneByID() {
    int searchID;
    int found = 0;

    // 1. Prompt user for drone ID
    printf("\nEnter Drone ID to search: ");
    scanf("%d", &searchID);

    // 2. Loop through the droneIDs array
    for (int i = 0; i < currentDroneCount; i++) {
        // 3. If matching ID is found, display drone details
        if (droneIDs[i] == searchID) {
            printf("\n✅ Drone Found!\n");
            printf("--- Drone Details ---\n");
            printf("ID:       %d\n", droneIDs[i]);
            printf("Model:    %s\n", droneModels[i]);
            printf("Battery:  %.1f%%\n", droneBatteries[i]);
            printf("Position: (%.2f, %.2f)\n", 
                   dronePositions[i][0], 
                   dronePositions[i][1]);
            found = 1;
            break;
        }
    }

    // 4. If no match found, print error message
    if (!found) {
        printf("❌ Drone with ID %d not found.\n", searchID);
    }
}

/**
 * @brief Calculates and displays the average battery level of all drones in the fleet.
 * If there are no drones, it displays an appropriate message.
 */
void calculateAverageBattery() {
    // 1. Check if there are any drones
    if (currentDroneCount == 0) {
        printf("\n📭 No drones available to calculate average.\n");
        return;
    }

    // 2. Loop through and sum all battery levels
    float sum = 0.0;
    for (int i = 0; i < currentDroneCount; i++) {
        sum += droneBatteries[i];
    }

    // 3. Calculate average
    float average = sum / currentDroneCount;

    // 4. Display result
    printf("\n--- Battery Statistics ---\n");
    printf("Total Drones: %d\n", currentDroneCount);
    printf("Average Battery Level: %.2f%%\n", average);

    // Additional: Show battery status
    if (average >= 75) {
        printf("Status: ✅ Fleet battery level is excellent!\n");
    } else if (average >= 50) {
        printf("Status: ⚠️  Fleet battery level is moderate.\n");
    } else if (average >= 25) {
        printf("Status: ⚠️  Fleet battery level is low.\n");
    } else {
        printf("Status: 🔴 Fleet battery level is critical!\n");
    }
}


// -------------------------------------------------------------------------------------------------
// Variation 2B: Nearest Drone Finder
// -------------------------------------------------------------------------------------------------

/**
 * @brief Prompts the user for an X and Y coordinate, then finds the drone closest to that point.
 * Uses the Euclidean distance formula to determine closeness.
 */
void findNearestDrone() {
    // Check if there are any drones
    if (currentDroneCount == 0) {
        printf("\n📭 No drones available to search.\n");
        return;
    }

    float targetX, targetY;

    // 1. Prompt user for target coordinates
    printf("\nEnter target X coordinate: ");
    scanf("%f", &targetX);
    printf("Enter target Y coordinate: ");
    scanf("%f", &targetY);

    // 2. Initialize tracking variables
    float minDistance = -1;
    int nearestIndex = -1;

    // 3. Loop through all drones
    for (int i = 0; i < currentDroneCount; i++) {
        // 4. Calculate Euclidean distance: sqrt((x2-x1)^2 + (y2-y1)^2)
        float dx = dronePositions[i][0] - targetX;
        float dy = dronePositions[i][1] - targetY;
        float distance = sqrt(dx * dx + dy * dy);

        // 5. Update minimum if this is the first drone or closer than current minimum
        if (minDistance < 0 || distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    // 6. Display the nearest drone details
    printf("\n🎯 Nearest Drone Found!\n");
    printf("--- Drone Details ---\n");
    printf("ID:       %d\n", droneIDs[nearestIndex]);
    printf("Model:    %s\n", droneModels[nearestIndex]);
    printf("Battery:  %.1f%%\n", droneBatteries[nearestIndex]);
    printf("Position: (%.2f, %.2f)\n", 
           dronePositions[nearestIndex][0], 
           dronePositions[nearestIndex][1]);
    printf("Distance: %.2f units from target (%.2f, %.2f)\n", 
           minDistance, targetX, targetY);
}