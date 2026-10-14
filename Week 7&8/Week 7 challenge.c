#include <stdio.h>
#include <string.h>

int main()
{
    char names[5][100];
    char emails[5][100];
    char phones[5][30];
    char towns[5][50];
    char searchName[100];
    int count = 0;    
    int choice;
    int found;

    do
    {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Lengths\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice)
        {
            case 1:
                if (count >= 5)
                {
                    printf("Supplier list is full (maximum 5).\n");
                }
                else
                {
                    printf("Enter supplier name: ");
                    fgets(names[count], sizeof(names[count]), stdin);
                    names[count][strcspn(names[count], "\n")] = '\0';

                    printf("Enter email: ");
                    fgets(emails[count], sizeof(emails[count]), stdin);
                    emails[count][strcspn(emails[count], "\n")] = '\0';

                    printf("Enter phone: ");
                    fgets(phones[count], sizeof(phones[count]), stdin);
                    phones[count][strcspn(phones[count], "\n")] = '\0';

                    printf("Enter town: ");
                    fgets(towns[count], sizeof(towns[count]), stdin);
                    towns[count][strcspn(towns[count], "\n")] = '\0';

                    count++;
                    printf("Supplier added.\n");
                }
                break;

            case 2:
                if (count == 0)
                {
                    printf("No suppliers added yet.\n");
                }
                for (int i = 0; i < count; i++)
                {
                    printf("\nSupplier %d\n", i + 1);
                    printf("Name : %s\n", names[i]);
                    printf("Email: %s\n", emails[i]);
                    printf("Phone: %s\n", phones[i]);
                    printf("Town : %s\n", towns[i]);
                }
                break;

            case 3:
                printf("Enter supplier name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                found = 0;
                for (int i = 0; i < count; i++)
                {
                    if (strcmp(searchName, names[i]) == 0)
                    {
                        found = 1;
                        printf("Supplier found at position %d.\n", i + 1);
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
                break;

            case 4:
                if (count == 0)
                {
                    printf("No suppliers added yet.\n");
                }
                for (int i = 0; i < count; i++)
                {
                    printf("%s: %zu characters\n", names[i], strlen(names[i]));
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
