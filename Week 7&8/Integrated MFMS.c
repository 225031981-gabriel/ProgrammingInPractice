#include <stdio.h>
#include <string.h>

char names[5][100];
char emails[5][100];
char phones[5][30];
char towns[5][50];
int supplierCount = 0;

void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main()
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int choice, id, position;
    float amount, basic, housing, transport, revenue, expenses, balance;

    do
    {
        displayMenu();
        scanf("%d", &choice);
        while (getchar() != '\n');  

        switch (choice)
        {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;
            case 5:
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;
            case 6:
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);
                if (balance > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }
                break;
            case 7:
                printf("Enter employee ID: ");
                scanf("%d", &id);
                position = searchEmployee(id, employeeIDs, 5);
                if (position == -1)
                {
                    printf("Employee not found.\n");
                }
                else
                {
                    printf("Employee found at position %d.\n", position);
                }
                break;
            case 8:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}

void displayMenu()
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Search Employee\n");
    printf("8. Exit\n");
    printf("Enter choice: ");
}

void addSupplier()
{
    if (supplierCount >= 5)
    {
        printf("Supplier list is full (maximum 5).\n");
        return;
    }

    printf("Enter supplier name: ");
    fgets(names[supplierCount], sizeof(names[supplierCount]), stdin);
    names[supplierCount][strcspn(names[supplierCount], "\n")] = '\0';

    printf("Enter email: ");
    fgets(emails[supplierCount], sizeof(emails[supplierCount]), stdin);
    emails[supplierCount][strcspn(emails[supplierCount], "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phones[supplierCount], sizeof(phones[supplierCount]), stdin);
    phones[supplierCount][strcspn(phones[supplierCount], "\n")] = '\0';

    printf("Enter town: ");
    fgets(towns[supplierCount], sizeof(towns[supplierCount]), stdin);
    towns[supplierCount][strcspn(towns[supplierCount], "\n")] = '\0';

    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier()
{
    if (supplierCount == 0)
    {
        printf("No suppliers added yet.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Name : %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town : %s\n", towns[i]);
    }
}

void searchSupplier()
{
    char searchName[100];
    int found = 0;

    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(searchName, names[i]) == 0)
        {
            found = 1;
            printf("Supplier found.\n");
            printf("Email: %s\n", emails[i]);
            printf("Phone: %s\n", phones[i]);
            printf("Town : %s\n", towns[i]);
            break;
        }
    }

    if (!found)
    {
        printf("Supplier not found.\n");
    }
}

float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}
