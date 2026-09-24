#include <iostream>
#include <cmath>
const int CAPACITY = 20;
using namespace std;
struct ArrayList
{
    int data[CAPACITY];
    int size = 0;
};

bool insertEnd(ArrayList &list, int value)
{
    if (list.size >= CAPACITY)
        return false;

    list.data[list.size] = value;
    list.size++;
    return true;
}

bool insertAtBeginning(ArrayList &list, int value)
{
    if (list.size >= CAPACITY)
        return false;

    for (int i = list.size; i > 0; i--)
    {
        list.data[i] = list.data[i - 1];
    }

    list.data[0] = value;
    list.size++;
    return true;
}

bool deleteAtPosition(ArrayList &list, int position)
{
    if (position < 0 || position >= list.size)
        return false;

    for (int i = position; i < list.size - 1; i++)
    {
        list.data[i] = list.data[i + 1];
    }

    list.size--;
    return true;
}

void displayList(const ArrayList &list)
{
    for (int i = 0; i < list.size; i++)
    {
        cout << list.data[i];
        if (i < list.size - 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    ArrayList list;

    int *ptr = list.data;
    int *minPtr = list.data;
    int *maxPtr = list.data;
    int *medianPtr = list.data;
    int *closestPtr = list.data;

    int sum = 0;
    int closestPosition;

    double generalAverage;
    double specialAverage;
    double averageDifference;
    double finalScore;

    const int REG_NO_LAST_TWO = 14;

    insertEnd(list, 18);
    insertEnd(list, 7);
    insertEnd(list, 45);
    insertEnd(list, 11);
    insertEnd(list, 36);
    insertEnd(list, REG_NO_LAST_TWO);
    insertEnd(list, 21);
    insertEnd(list, 13);
    insertEnd(list, 29);

    cout << "Initial ArrayList: ";
    displayList(list);
    ptr = list.data;
    minPtr = list.data;
    maxPtr = list.data;
    sum = 0;

    for (int i = 0; i < list.size; i++)
    {
        sum += *ptr;

        if (*ptr < *minPtr)
            minPtr = ptr;

        if (*ptr > *maxPtr)
            maxPtr = ptr;

        ptr++;
    }

    cout << "Minimum Value: " << *minPtr << endl;
    cout << "Maximum Value: " << *maxPtr << endl;

    int temp[CAPACITY];
    for (int i = 0; i < list.size; i++)
        temp[i] = list.data[i];

    for (int i = 0; i < list.size - 1; i++)
    {
        for (int j = 0; j < list.size - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int swapValue = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swapValue;
            }
        }
    }

    int medianValue = temp[list.size / 2];

    medianPtr = list.data;
    for (int i = 0; i < list.size; i++)
    {
        if (*medianPtr == medianValue)
            break;
        medianPtr++;
    }

    cout << "Median Value: " << *medianPtr << endl;
    cout << "Sum: " << sum << endl;

    generalAverage = (double)sum / list.size;
    specialAverage = ((double)*minPtr + *medianPtr + *maxPtr) / 3.0;

    ptr = list.data;
    closestPtr = list.data;
    double smallestDifference = fabs(*ptr - specialAverage);

    for (int i = 0; i < list.size; i++)
    {
        double currentDifference = fabs(*ptr - specialAverage);

        if (currentDifference < smallestDifference)
        {
            smallestDifference = currentDifference;
            closestPtr = ptr;
        }
        ptr++;
    }
    closestPosition = closestPtr - list.data;

    cout << "General Average: " << generalAverage << endl;
    cout << "Special Average: " << specialAverage << endl;
    cout << "Closest Value: " << *closestPtr << endl;
    cout << "Position of Closest Value: " << closestPosition << endl;
    averageDifference = fabs(generalAverage - specialAverage);

    finalScore = fabs(*closestPtr - generalAverage)
               + fabs(*closestPtr - specialAverage)
               + averageDifference;

    cout << "Difference Between Averages: " << averageDifference << endl;
    cout << "Final Score: " << finalScore << endl;

    closestPosition = closestPtr - list.data;
    deleteAtPosition(list, closestPosition);

    cout << "ArrayList After Deletion: ";
    displayList(list);

    int roundedSpecialAverage = (int)round(specialAverage);
    insertAtBeginning(list, roundedSpecialAverage);

    cout << "Final ArrayList After Insertion: ";
    displayList(list);

    return 0;
}

