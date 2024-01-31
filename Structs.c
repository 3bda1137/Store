#include <stdio.h>
#include <stdlib.h>

typedef  struct  Category Category;
typedef  struct  Product Product;

struct Category
{
    char CategoryName[50];
    Product **products;
    int ProductCount;
    int MaxNumberOfProduct;
};

struct Product
{
    char ProductName[50];
    float ProductPrice;
    int ProductQuantity;
};
