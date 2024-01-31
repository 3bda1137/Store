#include <stdio.h>
#include <stdlib.h>
#include "Structs.c"

Category* CreateNewCategory(int MaxNumberOfProduct)
{
    Category *category = malloc(sizeof(Category));
    category->ProductCount = 0;
    category->MaxNumberOfProduct=2;
    if(MaxNumberOfProduct==-1)
    {
        category->products = malloc(category->MaxNumberOfProduct*sizeof(Product));
    }
    else
    {
        category->products = malloc(MaxNumberOfProduct*sizeof(Product));
    }
    return category;
}

void AddCategories(int *sizeOfArrayCategorys,int *contOfCategoryInArray,Category **Categories)
{
    gotoxy(0,6);
    SetColor(14);
    char enterCategory;
    enterCategory = tolower('y');
    while (enterCategory == 'y')
    {
        if(*contOfCategoryInArray<*sizeOfArrayCategorys)
        {
            Category *newCategory= CreateNewCategory(-1);
            AddCategory(newCategory);
            Categories[*contOfCategoryInArray]=newCategory;
            *contOfCategoryInArray+=1;
        }
        else
        {
            ExpandArrayOfCategory(sizeOfArrayCategorys,Categories);

            Category *newCategory= CreateNewCategory(-1);
            AddCategory(newCategory);
            Categories[*contOfCategoryInArray]=newCategory;
            *contOfCategoryInArray+=1;
        }
        printf("Do you want to enter another Category? (Y/N): ");
        enterCategory = tolower(getche());
        printf("\n");
    }
}

void AddCategory(Category *category)
{
    printf("Enter The Name of Category: ");
    scanf("%s",category->CategoryName);

    printf("Do you want to enter  product? (Y/N):");
    char enterProduct;
    enterProduct = tolower(getche());
    printf("\n");
    while (enterProduct == 'y')
    {
        AddProduct(category);
        printf("Do you want to enter another product? (Y/N): ");
        enterProduct = tolower(getche());
        printf("\n");
    }
}

void AddProduct(Category *category)
{
    char productName[50];
    int Quantity;
    float price;
    if (category->ProductCount < category->MaxNumberOfProduct)
    {
        printf("Enter The Product Name: ");
        scanf(" %[^\n]",productName);
        printf("Enter The Product Price: ");
        int isValidPrice=scanf("%f",&price);
        while(isValidPrice==0||price<1)
        {
            if(isValidPrice==0)
            {
                printf("Enter price (without letters): ");
                while (getchar() != '\n');
                {
                    isValidPrice = scanf("%f",&price);
                }
            }
            else
            {
                if(price<1)
                {
                    printf("Enter price (Greater than 'ZERO'): ");
                    isValidPrice = scanf("%f",&price);
                }
            }
        }
        printf("Enter The Product Quantity: ");
        int isValid=scanf("%d",&Quantity);
        while (isValid == 0 || Quantity < 1)
        {
            if (isValid == 0)
            {
                printf("Enter Quantity (without letters): ");
                while (getchar() != '\n');

                {
                    isValid = scanf("%d", &Quantity);
                }
            }
            else
            {
                if (Quantity < 1)
                {
                    printf("Enter Quantity (Greater than 'ZERO'): ");
                    isValid = scanf("%d", &Quantity);
                }
            }
        }
        int isExist = SearchAboutProductInCategory(productName,category);
        if(isExist!=-1)
        {
            printf("Product Arealy Exist You Want Increase The Quantity Of product?(Y/N):");
            if(tolower(getche())=='y')
            {
                category->products[isExist]->ProductQuantity+=Quantity;
            }
            printf("\n");
        }
        else
        {
            category->products[category->ProductCount] = malloc(1*sizeof(Product));
            strcpy(category->products[category->ProductCount]->ProductName,productName);
            category->products[category->ProductCount]->ProductPrice=price;
            category->products[category->ProductCount]->ProductQuantity=Quantity;
            category->ProductCount++;
        }
    }
    else
    {
        ExpandArrayOfProduct(&category->MaxNumberOfProduct, category->products);
        printf("Enter The Product Name: ");
        scanf("%s",productName);
        printf("Enter The Product Price: ");
        int isValidPrice=scanf("%f",&price);
        while(isValidPrice==0||price<1)
        {
            if(isValidPrice==0)
            {
                printf("Enter price (without letters): ");
                while (getchar() != '\n');
                {
                    isValidPrice = scanf("%f",&price);
                }
            }
            else
            {
                if(price<1)
                {
                    printf("Enter price (Greater than 'ZERO'): ");
                    isValidPrice = scanf("%f",&price);
                }
            }
        }
        printf("Enter The Product Quantity: ");
        int isValid=scanf("%d",&Quantity);
        while (isValid == 0 || Quantity < 1)
        {
            if (isValid == 0)
            {
                printf("Enter Quantity (without letters): ");
                while (getchar() != '\n');

                {
                    isValid = scanf("%d", &Quantity);
                }
            }
            else
            {
                if (Quantity < 1)
                {
                    printf("Enter Quantity (Greater than 'ZERO'): ");
                    isValid = scanf("%d", &Quantity);
                }
            }
        }
        int isExist = SearchAboutProductInCategory(productName,category);
        if(isExist!=-1)
        {
            printf("Product Arealy Exist You Want Increase The Quantity Of product?(Y/N):");
            if(tolower(getche())=='y')
            {
                category->products[isExist]->ProductQuantity+=Quantity;
            }
            printf("\n");
        }
        else
        {
            category->products[category->ProductCount] = malloc(1*sizeof(Product));
            strcpy(category->products[category->ProductCount]->ProductName,productName);
            category->products[category->ProductCount]->ProductPrice=price;
            category->products[category->ProductCount]->ProductQuantity=Quantity;
            category->ProductCount++;
        }
    }
}
