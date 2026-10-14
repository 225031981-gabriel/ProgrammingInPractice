#include <stdio.h>
#include <string.h>

int main()
{
    char supplierName[100] = "";
    char email[100] = "";
    char phone[30] = "";
    char town[50] = "";
    char searchName[100];
    int choice;
    int hasSupplier = 0; 

    do
    {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');  

        switch (choice)
        {
            case 1:
                printf("Enter supplier name: ");
                fgets(supplierName, sizeof(supplierName), stdin);
                supplierName[strcspn(supplierName, "\n")] = '\0';

                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                printf("Enter phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0';

                printf("Enter town: ");
                fgets(town, sizeof(town), stdin);
                town[strcspn(town, "\n")] = '\0';

                hasSupplier = 1;
                printf("Supplier added.\n");
                break;

            case 2:
                if (hasSupplier == 0)
                {
                    printf("No supplier added yet.\n");
                }
                else
                {
                    printf("\nName : %s\n", supplierName);
                    printf("Email: %s\n", email);
                    printf("Phone: %s\n", phone);
                    printf("Town : %s\n", town);
                }
                break;

            case 3:
                if (hasSupplier == 0)
                {
                    printf("No supplier added yet.\n");
                }
                else
                {
                    printf("Enter supplier name to search: ");
                    fgets(searchName, sizeof(searchName), stdin);
                    searchName[strcspn(searchName, "\n")] = '\0';

                    if (strcmp(searchName, supplierName) == 0)
                    {
                        printf("Supplier found.\n");
                    }
                    else
                    {
                        printf("Supplier not found.\n");
                    }
                }
                break;

            case 4:
                if (hasSupplier == 0)
                {
                    printf("No supplier added yet.\n");
                }
                else
                {
                    printf("Name length: %zu\n", strlen(supplierName));
                }
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
