#include <stdio.h>
#include <stdlib.h>
#include "Structs.c"

void ExpandArrayOfProduct(int *size, Product **products)
{

    Product **newArrayOfProduct = malloc(*size*2 * sizeof(Product));
    for (int i = 0; i < (*size); i++)
    {
        newArrayOfProduct[i] = malloc(sizeof(Product));
        *newArrayOfProduct[i] = *products[i];
    }
    //free(products);
    products=newArrayOfProduct;
    *size = *size * 2;
    //return newArrayOfProduct;
}

void ExpandArrayOfCategory(int *sizeOfArrayCategorys, Category **Categories)
{

    Category **newArrayOfCategory = malloc(*sizeOfArrayCategorys*2 * sizeof(Category));
    for (int i = 0; i < (*sizeOfArrayCategorys); i++)
    {
        newArrayOfCategory[i] = CreateNewCategory(Categories[i]->MaxNumberOfProduct);
        //strcpy(newArrayOfCategory[i]->CategoryName,Categories[i]->CategoryName);
        *newArrayOfCategory[i] = *Categories[i];
    }
    //free(Categories);
    *sizeOfArrayCategorys *= 2;
    Categories = newArrayOfCategory;
    //return newArrayOfCategory;
}

int SearchAboutCategory(char categorName[],int contOfCategoryInArray,Category **Categories)
{
    for(int i=0; i<contOfCategoryInArray; i++)
    {
        if(strcmp(Categories[i]->CategoryName, categorName)==0)
        {
            return i;
        }
    }
    return -1;
}
int SearchAboutProductInCategory(char productName[],Category *category)
{
    for(int i=0 ; i<category->ProductCount; i++)
    {
        if(strcmp(category->products[i]->ProductName, productName)==0)
        {
            return i;
        }
    }
    return -1;
}
int SearchAboutProductInOrder(char productName[],Product **Orders,int *contOfOrder)
{
    for(int i=0 ; i<*contOfOrder; i++)
    {
        if(strcmp(Orders[i]->ProductName, productName)==0)
        {
            return i;
        }
    }
    return -1;
}
Product *GetProduct(int indexOfProduct,int indexOfCategoryInArray,Category **Categories)
{
    Product *product;
    product=Categories[indexOfCategoryInArray]->products[indexOfProduct];
    return product;
}

void CreateOrder(int *SizeOfOrders,int *contOfOrder,Product **Orders)
{
    if(*contOfOrder< *SizeOfOrders)
    {
        Orders[*contOfOrder]= malloc(1*sizeof(Product));

    }
    else
    {
        ExpandArrayOfProduct(SizeOfOrders,Orders);
        Orders[*contOfOrder] = malloc(1*sizeof(Product));

    }
}
void GetOrderFromUser(int *contOfOrder,int *SizeOfOrders,Product **Orders,int contOfCategoryInArray,Category **Categories)
{
    printf("enter Category Name To Display Products To Buy: ");
    char categorName[30];
    scanf("%s",categorName);
    int indexOfCategory = SearchAboutCategory(categorName,contOfCategoryInArray,Categories);
    if(indexOfCategory!=-1)
    {
        DisplayProductsWithInCategory(Categories,indexOfCategory);
        printf("Enter Name Of Product To Buy: ");
        char productName[30];
        scanf("%s",productName);
        int indexOfProduct =  SearchAboutProductInCategory(productName,Categories[indexOfCategory]);
        if(indexOfProduct!=-1)
        {
            printf("Enter Quantity Of Product: ");
            int quantityToBuy;
            scanf("%d",&quantityToBuy);
            int quantityOfProduct=Categories[indexOfCategory]->products[indexOfProduct]->ProductQuantity;
            if(quantityToBuy > quantityOfProduct)
            {
                printf("Max Quantity of this Product is '%d'\n",quantityOfProduct);
            }
            else
            {
                CreateOrder(SizeOfOrders,contOfOrder,Orders);
                int indexOfProductInOrder =  SearchAboutProductInOrder(productName,Orders,contOfOrder);
                if(indexOfProductInOrder==-1)
                {
                    strcpy(Orders[*contOfOrder]->ProductName, Categories[indexOfCategory]->products[indexOfProduct]->ProductName);
                    Orders[*contOfOrder]->ProductPrice=Categories[indexOfCategory]->products[indexOfProduct]->ProductPrice;
                    Orders[*contOfOrder]->ProductQuantity=quantityToBuy;
                    *contOfOrder+=1;
                }
                else
                {
                    Orders[indexOfProductInOrder]->ProductQuantity+=quantityToBuy;
                }
                Categories[indexOfCategory]->products[indexOfProduct]->ProductQuantity-=quantityToBuy;
                /*
                if(Categories[indexOfCategory]->products[indexOfProduct]->ProductQuantity==0)
                {
                    DeleteProduct(productName,Categories,indexOfCategory);
                }
                */
            }
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


void SearchAboutProductInAllCategories( char search[],int contOfCategoryInArray,Category **Categories)
{
    int y=7;
    if(contOfCategoryInArray>0)
    {
        for(int i=0; i<contOfCategoryInArray; i++)
        {
            gotoxy(5,y);
            y++;
            SetColor(2);
            printf("[%d]Category %s\n",i+1,Categories[i]->CategoryName);
            if(Categories[i]->ProductCount>0)
            {
                SetColor(7);
                gotoxy(10,y);
                printf("Product Name");
                gotoxy(30,y);
                printf("Product Price");
                gotoxy(50,y);
                printf("Product Quantity\n");
                y++;
                for(int j=1; j<=Categories[i]->ProductCount; j++)
                {
                    if(strstr(Categories[i]->products[j-1]->ProductName,search)!=NULL)
                    {
                        gotoxy(16,y);
                        printf("%s",Categories[i]->products[j-1]->ProductName);
                        gotoxy(36,y);
                        printf("%.2f",Categories[i]->products[j-1]->ProductPrice);
                        gotoxy(56,y);
                        printf("%d",Categories[i]->products[j-1]->ProductQuantity);
                        y++;
                    }
                }
            }
            else
            {
                gotoxy(20,y);
                SetColor(3);
                printf("No Product in This Category\n");
                y++;
            }
        }
    }
    else
    {
        printf("No Category\n");
    }
}

