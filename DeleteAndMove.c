#include <stdio.h>
#include <stdlib.h>
#include "Structs.c"

void DeleteProduct(char name[],Category **category,int index)
{

    for(int i=0;i<category[index]->ProductCount;i++)
    {
        if(strcmp(category[index]->products[i]->ProductName,name)==0)
        {
            //free(category[index]->products[i]);
            for(int j = i ; j < category[index]->ProductCount-1 ; j++)
            {
                category[index]->products[j]=category[index]->products[j+1];
            }
            //free(category[index]->products[category[index]->ProductCount-1]);
            category[index]->ProductCount--;
        }
    }
}
void DeletCategory(char name[],Category **category,int *contOfCategory)
{

    for(int i=0;i<*contOfCategory;i++)
    {
        if(strcmp(category[i]->CategoryName,name)==0)
        {
            for(int j=0;j<category[i]->ProductCount;j++)
            {
                free(category[i]->products[j]);
            }
            free(category[i]->products);
            for(int j = i ; j < *contOfCategory-1 ; j++)
            {
                category[j]=category[j+1];
            }
            *contOfCategory-=1;
        }
    }
}
