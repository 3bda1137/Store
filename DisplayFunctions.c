#include <stdio.h>
#include <stdlib.h>
#include "Structs.c"

void DisplayCategories(int contOfCategoryInArray,Category **Categories,int indexOfCategory)
{
    SetColor(11);
    gotoxy(0,6);
    if(indexOfCategory==-1)
    {

        printf("  Categoreis\n");
        for(int i=0; i<contOfCategoryInArray; i++)
        {

            printf("[%d] %s\n",i+1,Categories[i]->CategoryName);
        }
    }
    else
    {
        printf("Name :%s\n",Categories[indexOfCategory]->CategoryName);
    }
}
void DisplayProductsWithInCategory(Category **category,int index)
{
    SetColor(11);
    printf("Product Name\tProduct Price \tProduct Quantity\n");
    SetColor(3);
    for(int j=0; j< category[index]->ProductCount; j++)
    {
        if(category[index]->products[j]->ProductQuantity !=0)
        {
            printf("%s\t\t",category[index]->products[j]->ProductName);
            printf("%.2f\t\t",category[index]->products[j]->ProductPrice);
            printf("%d\n",category[index]->products[j]->ProductQuantity);
        }
    }
}

void DisplayOrders(int *contOfOrder,Product **Orders)
{
    SetColor(11);
    float totalPrice=0;
    gotoxy(20,6);
    printf("Product Name");
    gotoxy(40,6);
    printf("Product Price");
    gotoxy(60,6);
    printf("Product Quantity\n");
    int i;
    for(i=0; i<*contOfOrder; i++)
    {
        gotoxy(26,7+i);
        printf("%s",Orders[i]->ProductName);
        gotoxy(46,7+i);
        printf("%.2f",Orders[i]->ProductPrice);
        gotoxy(66,7+i);
        printf("%d",Orders[i]->ProductQuantity);
        totalPrice+=Orders[i]->ProductPrice * Orders[i]->ProductQuantity;
    }
    gotoxy(20,7+i);
    printf("--------------------------------------------------------\n");
    gotoxy(40,8+i);
    printf("Total Price\t%.2f\n",totalPrice);
}
void DisplayAllProducts(int contOfCategoryInArray,Category **Categories)
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
                    gotoxy(16,y);
                    printf("%s",Categories[i]->products[j-1]->ProductName);
                    gotoxy(36,y);
                    printf("%.2f",Categories[i]->products[j-1]->ProductPrice);
                    gotoxy(56,y);
                    printf("%d",Categories[i]->products[j-1]->ProductQuantity);
                    y++;
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
void DisplayShapeOfHeader()
{
    for(int i=30; i<60; i++)
    {
        gotoxy(i,1);
        SetColor(9);
        printf("-");
    }
    for(int i=30; i<60; i++)
    {
        gotoxy(i,3);
        printf("-");
    }
    for(int i=1; i<4; i++)
    {
        gotoxy(30,i);
        printf("|");
    }
    for(int i=1; i<4; i++)
    {
        gotoxy(60,i);
        printf("|");
    }

    gotoxy(42,2);
    SetColor(14);
    printf("A.M Store\n");
}


void DisplayShapeOfBody()
{
    for(int i=25; i<65; i++)
    {
        gotoxy(i,1);
        SetColor(9);
        printf("-");
    }
    for(int i=25; i<65; i++)
    {
        gotoxy(i,22);
        printf("-");
    }
    for(int i=1; i<23; i++)
    {
        gotoxy(25,i);
        printf("|");
    }
    for(int i=1; i<23; i++)
    {
        gotoxy(65,i);
        printf("|");
    }
}


