#include <stdio.h>
#include <stdlib.h>
#include "Structs.c"

int sizeOfArrayCategorys=2;
int contOfCategoryInArray=0;
int SizeOfOrders=2;
int contOfOrder=0;
Category **Categories;
Product **Orders;
int main()
{
    char* filePath = "store_data.txt";
    Categories = malloc(sizeOfArrayCategorys*sizeof(Category));
    Orders = malloc(SizeOfOrders*sizeof(Product));
    ReadDataFromFile(filePath,Categories,&contOfCategoryInArray);
    DisplayShapeOfHeader();
    int sizeOfMenu=13;
    char arr[][30]=
    {
        "Add New Category.",    //0
        "Add New Product.",     //1
        "Display Categories.",  //2
        "Display Products.",    //3
        "Search Product.",      //4
        "Edit Product.",        //5
        "Edit Category.",       //6
        "Move Product.",        //7
        "Delete Category.",     //8
        "Delete Product.",      //9
        "Buy a Product.",       //10
        "Display Order.",       //11
        "Exit."                 //12
    };
    while(1)
    {
        char ch;
        int selectedColor,enterd=0;
        ch = getch();
        if(ch==13)
        {
            enterd=1;
        }

        else if(ch==-32)
        {
            if(ch==-32)
            {
                ch = getch();

                switch(ch)
                {
                case 72:
                    if(selectedColor==0)
                    {
                        selectedColor=sizeOfMenu-1;
                    }
                    else
                    {
                        selectedColor--;
                    }
                    break;
                case 71:
                    selectedColor=0;
                    break;
                case 79:
                    selectedColor=sizeOfMenu-1;
                    break;
                case 80:
                    if(selectedColor==sizeOfMenu-1)
                    {
                        selectedColor=0;
                    }
                    else
                    {
                        selectedColor++;
                    }
                    break;
                }
            }
        }
        else
        {
            enterd=0;
            system("cls");
            DisplayShapeOfHeader();
        }

        if(enterd==1)
        {
            system("cls");
            DisplayShapeOfHeader();
            switch(selectedColor)
            {
            case 0:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Add Category\n");
                AddCategories(&sizeOfArrayCategorys,&contOfCategoryInArray,Categories);
                break;
            case 1:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Add Product\n");
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                printf("Enter Name of Category To Display Products:");
                char categoryName[30];
                scanf("%s",categoryName);
                int indexOfCategory =SearchAboutCategory(categoryName,contOfCategoryInArray,Categories);
                if(indexOfCategory!=-1)
                {
                    Category *category=Categories[indexOfCategory];
                    char enterCategory;
                    enterCategory = tolower('y');
                    while (enterCategory == 'y')
                    {
                        AddProduct(category);
                        printf("enter another Product?(Y/N): ");
                        enterCategory = tolower(getche());
                        printf("\n");
                    }
                }
                break;
            case 2:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/All Categories\n");
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                break;
            case 3:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/All Products\n");
                DisplayAllProducts(contOfCategoryInArray,Categories);
                break;
            case 4:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Search Products\n");
                printf("Enter The Name of Product To Search :");
                char search[30];
                scanf("%s",search);
                SearchAboutProductInAllCategories(search,contOfCategoryInArray,Categories);
                break;
            case 5:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Update Product\n");
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                GetNameOfProductToUpdate(contOfCategoryInArray,Categories);
                break;
            case 6:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Update Category\n");
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                GetCategoryFromUserToUpdate(contOfCategoryInArray,Categories);
                break;
            case 7:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Move Products\n");
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                GetProductFromUserToMoveFromCategory(contOfCategoryInArray,Categories);
                break;
            case 8:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Delete Category\n");
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                categoryName[30];
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                printf("Enter Name of Category To Delete: ");
                scanf("%s",categoryName);
                indexOfCategory =SearchAboutCategory(categoryName,contOfCategoryInArray,Categories);
                if(indexOfCategory!=-1)
                {
                    DeletCategory(categoryName,Categories,&contOfCategoryInArray);
                }
                break;
            case 9:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Delete Product\n");
                categoryName[30];
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                printf("Enter Name of Category To Display Product:");
                scanf("%s",categoryName);
                indexOfCategory =SearchAboutCategory(categoryName,contOfCategoryInArray,Categories);
                if(indexOfCategory!=-1)
                {
                    char productName[30];
                    DisplayProductsWithInCategory(Categories,indexOfCategory);
                    printf("Enter The Name of Product :");
                    scanf("%s",productName);
                    int productIsExist =  SearchAboutProductInCategory(productName,Categories[indexOfCategory]);
                    if(productIsExist!=-1)
                    {
                        printf("Delete this Product?(Y/N):");
                        if(tolower(getche())=='y')
                        {
                            DeleteProduct(productName,Categories,indexOfCategory);
                            printf("\nDelete\n");
                        }
                    }
                }
                break;

            case 10:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Shopping\n");
                DisplayCategories(contOfCategoryInArray,Categories,-1);
                GetOrderFromUser(&contOfOrder,&SizeOfOrders,Orders,contOfCategoryInArray,Categories);
                char enterCategory;
                 printf("enter another Product To Cart?(Y/N): ");
                enterCategory = tolower(getche());
                printf("\n");
                while (enterCategory == 'y')
                {
                     GetOrderFromUser(&contOfOrder,&SizeOfOrders,Orders,contOfCategoryInArray,Categories);
                    printf("enter another Product To Cart?(Y/N): ");
                    enterCategory = tolower(getche());
                    printf("\n");
                }
                break;
            case 11:
                gotoxy(37,4);
                SetColor(4);
                printf("Home/Order\n");
                DisplayOrders(&contOfOrder,Orders);
                break;
            case 12:
                system("cls");
                gotoxy(20,2);
                SetColor(10);
                printf("Thanks For Use A.M Store\n");
                SetColor(8);
                SaveDataToFile(filePath, Categories, contOfCategoryInArray);
                return 0;
                break;
            }
        }
        else
        {
            DisplayShapeOfBody();
            for(int i=0; i<sizeOfMenu; i++)
            {
                gotoxy(35,6+i);
                if(i==selectedColor)
                {
                    SetColor(10);
                    puts(arr[i]);
                }
                else
                {
                    SetColor(15);
                    puts(arr[i]);
                }
            }
        }
    }

    SaveDataToFile(filePath, Categories, contOfCategoryInArray);
    return 0;
}
