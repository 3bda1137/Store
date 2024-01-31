#include "Structs.c"
void SaveDataToFile( char *fileName, Category **categories, int contOfCategoryInArray)
{
    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    // Save categories
    fprintf(file, "%d\n", contOfCategoryInArray);
    for (int i = 0; i < contOfCategoryInArray; i++)
    {
        fprintf(file, "%s %d\n", categories[i]->CategoryName, categories[i]->ProductCount);
        for (int j = 0; j < categories[i]->ProductCount; j++)
        {
            fprintf(file, "%s %f %d\n", categories[i]->products[j]->ProductName,
                    categories[i]->products[j]->ProductPrice, categories[i]->products[j]->ProductQuantity);
        }
    }
    fclose(file);
}

void ReadDataFromFile(char *fileName, Category **categories, int *contOfCategoryInArray)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    // Read categories
    fscanf(file, "%d", contOfCategoryInArray);
    for (int i = 0; i < *contOfCategoryInArray; i++)
    {
        categories[i] = CreateNewCategory(-1);
        fscanf(file, "%s %d", categories[i]->CategoryName, &categories[i]->ProductCount);
        for (int j = 0; j < categories[i]->ProductCount; j++)
        {
            categories[i]->products[j] = malloc(sizeof(Product));
            fscanf(file, "%s %f %d", categories[i]->products[j]->ProductName,
                   &categories[i]->products[j]->ProductPrice, &categories[i]->products[j]->ProductQuantity);
        }
    }
    fclose(file);
}
