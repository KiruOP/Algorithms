#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    double weight;
    double value;
    double ratio;
} Item;
int compare(const void *a, const void *b)
{
    const Item *itemA = (const Item *)a;
    const Item *itemB = (const Item *)b;
    return (itemB->ratio - itemA->ratio);
}
double fractionalKnapsack(int capacity, Item items[], int numItems)
{

    qsort(items, numItems, sizeof(Item), compare);
    double totalValue = 0.0;
    int i;
    for (i = 0; i < numItems; i++)
    {
        if (capacity <= 0)
            break;
        if (items[i].weight <= capacity)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            double fraction = (double)capacity / items[i].weight;
            totalValue += (fraction * items[i].value);
            break;
        }
    }
    return totalValue;
}
int main()
{
    int capacity = 50;
    int numItems = 3;
    Item items[] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };
    int numItems = sizeof(items) / sizeof(items[0]);
    for (int i = 0; i < numItems; i++)
    {
        items[i].ratio = items[i].value / items[i].weight;
    }
    double maxValue = fractionalKnapsack(capacity, items, numItems);
    printf("Maximum value in the knapsack = %.2lf\n", maxValue);
    return 0;
}