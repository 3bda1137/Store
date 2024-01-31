#include "Structs.c"

void GetProductFromUserToMoveFromCategory(int contOfCategoryInArray,Category **Categories)
{
    SetColor(14);
    if(contOfCategoryInArray>1)
    {
        printf("Enter Name of Category To Display Products:");
        char categoryNameFrom[30];
        scanf("%s",categoryNameFrom);
        int indexOfCategoryFrom =SearchAboutCategory(categoryNameFrom,contOfCategoryInArray,Categories);
        if(indexOfCategoryFrom!=-1)
        {
            DisplayProductsWithInCategory(Categories,indexOfCategoryFrom);
            printf("Enter Name of Product From Table To Move:");
            char productName[30];
            scanf("%s",productName);
            int indexOfProduct = SearchAboutProductInCategory(productName,Categories[indexOfCategoryFrom]);
            if(indexOfProduct!=-1)
            {
                printf("Enter Name of Category To MoveThe Prduct:");
                char categoryNameTo[30];
                scanf("%s",categoryNameTo);
                int indexOfCategoryTo =SearchAboutCategory(categoryNameTo,contOfCategoryInArray,Categories);
                if(indexOfCategoryTo!=-1)
                {
                    int productIsExist =  SearchAboutProductInCategory(productName,Categories[indexOfCategoryTo]);
                    if(productIsExist==-1)
                    {
                        MoveProduct(indexOfProduct,indexOfCategoryFrom,indexOfCategoryTo,Categories);
                    }
                    else
                    {
                        printf("Product Arealy Exist In Category %s\n",categoryNameTo);
                    }
                }
                else
                {
                    printf("\n*************Category %s NOT EXIST************\n",categoryNameTo);
                }
            }
            else
            {
                printf("\n*************Product NOT EXIST************\n");
            }
        }
        else
        {
            printf("\n*************Category %s NOT EXIST************\n",categoryNameFrom);
        }
    }
    else
    {
        printf("There is only one Category. Add another Category so you can move\n");
    }
}

void MoveProduct(int indexOfProduct,int indexOfCategoryFrom,int indexOfCategoryTo,Category **Categories)
{
    Product *product = GetProduct(indexOfProduct,indexOfCategoryFrom,Categories);
    if(Categories[indexOfCategoryTo]->ProductCount < Categories[indexOfCategoryTo]->MaxNumberOfProduct)
    {
        Categories[indexOfCategoryTo]->products[Categories[indexOfCategoryTo]->ProductCount]=product;
        Categories[indexOfCategoryTo]->ProductCount++;
        DeleteProduct(product->ProductName,Categories,indexOfCategoryFrom);
    }
    else
    {
        Categories[indexOfCategoryTo]->products =
            ExpandArrayOfProduct(&Categories[indexOfCategoryTo]->MaxNumberOfProduct, Categories[indexOfCategoryTo]->products);
        Categories[indexOfCategoryTo]->products[Categories[indexOfCategoryTo]->ProductCount]=product;
        Categories[indexOfCategoryTo]->ProductCount++;
        DeleteProduct(product->ProductName,Categories,indexOfCategoryFrom);
    }
}

void GetCategoryFromUserToUpdate(int contOfCategoryInArray,Category **Categories)
{
    char categoryNameToUpdate[30];
    printf("Enter Name of Category To Update :");
    scanf("%s",categoryNameToUpdate);
    int indexOfCategory =SearchAboutCategory(categoryNameToUpdate,contOfCategoryInArray,Categories);
    if(indexOfCategory!=-1)
    {
        char newCtegoryName[30];
        printf("Enter The New Name of Category :");
        scanf("%s",newCtegoryName);
        int indexOfNewCategory =SearchAboutCategory(newCtegoryName,contOfCategoryInArray,Categories);
        if(indexOfNewCategory ==-1)
        {
            UpdateCategory(newCtegoryName,indexOfCategory,Categories);
        }
        else
        {
            printf("\n************* Category %s Arealy Exist ************\n",newCtegoryName);
        }
    }
    else
    {
        printf("\n*************Category %s NOT EXIST************\n",categoryNameToUpdate);
    }
}

void UpdateCategory(char newCtegoryName[],int indexOfCategory,Category **Categories)
{
    strcpy(Categories[indexOfCategory]->CategoryName, newCtegoryName);
}

void GetNameOfProductToUpdate(int contOfCategoryInArray,Category **Categories)
{
    printf("enter Category Name To Display Product: ");
    char categorName[30];
    scanf("%s",categorName);
    int indexOfCategory = SearchAboutCategory(categorName,contOfCategoryInArray,Categories);
    if(indexOfCategory!=-1)
    {
        DisplayProductsWithInCategory(Categories,indexOfCategory);
        printf("Enter Name Of Product To Update: ");
        char productName[30];
        scanf("%s",productName);
        int productIsExist =  SearchAboutProductInCategory(productName,Categories[indexOfCategory]);
        if(productIsExist!=-1)
        {
            GetNewDetailsForProductToUpdate(indexOfCategory,productIsExist,Categories);
            DisplayProductsWithInCategory(Categories,indexOfCategory);
        }
        else
        {
            printf("Product '%s' Not Exist\n",productName);
        }
    }
    else
    {
        printf("Category '%s' not Exist\n",categorName);
    }
}
void GetNewDetailsForProductToUpdate(int indexOfCategory,int indexOfProdeuct,Category **Categories)
{
    char newProductName[30]="";
    float newProductPrice;
    int newProductQuantity;
    printf("update All Details of product[name,price,quantity]?(Y/N):");
    char ch=tolower(getche());
    printf("\n");
    if(ch=='y')
    {
        printf("Enter New Name Of Product: ");
        scanf("%s",newProductName);
        printf("Enter New Price Of Product: ");
        scanf("%f",&newProductPrice);
        printf("Enter New Quantity Of Product: ");
        scanf("%d",&newProductQuantity);
        int isExist = SearchAboutProductInCategory(newProductName,Categories[indexOfCategory]);
        if(isExist!=-1)
        {
            printf("Product Arealy Exist\n");
        }
        else
        {
            strcpy(Categories[indexOfCategory]->products[indexOfProdeuct]->ProductName,newProductName);
            Categories[indexOfCategory]->products[indexOfProdeuct]->ProductPrice = newProductPrice;
            Categories[indexOfCategory]->products[indexOfProdeuct]->ProductQuantity = newProductQuantity;
        }
    }
    else
    {
        printf("select Option From List\n");
        printf("1-Update Name.\n2-Update Price.\n3-Update Quantity.\n");
        printf("Enter Number Of Option: ");
        int numberOfOption;
        scanf("%d",&numberOfOption);
        switch(numberOfOption)
        {
        case 1:
            printf("Enter New Name Of Product: ");
            scanf("%s",newProductName);
            strcpy(Categories[indexOfCategory]->products[indexOfProdeuct]->ProductName,newProductName);
            break;
        case 2:
            printf("Enter New Price Of Product: ");
            scanf("%f",&newProductPrice);
            Categories[indexOfCategory]->products[indexOfProdeuct]->ProductPrice = newProductPrice;
            break;
        case 3:
            printf("Enter New Quantity Of Product: ");
            scanf("%d",&newProductQuantity);
            Categories[indexOfCategory]->products[indexOfProdeuct]->ProductQuantity = newProductQuantity;
            break;
        }
    }
}
