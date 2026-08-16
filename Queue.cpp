#include <iostream>
using namespace std;

class LinearQueue
{
private:
    int arr[5];
    int frontIndex, rearIndex;
    int capacity;

public:
    LinearQueue()
    {
        capacity = 5;
        frontIndex = -1;
        rearIndex = -1;
    }

    void insertElement(int item)
    {
        if (rearIndex == capacity - 1)
        {
            cout << "Queue Overflow! Cannot insert element.\n";
            return;
        }

        if (frontIndex == -1)
            frontIndex = 0;

        arr[++rearIndex] = item;
        cout << "Element added successfully.\n";
    }

    void deleteElement()
    {
        if (frontIndex == -1 || frontIndex > rearIndex)
        {
            cout << "Queue Underflow! Queue is empty.\n";
            frontIndex = rearIndex = -1;
            return;
        }

        cout << "Removed Element: " << arr[frontIndex] << endl;
        frontIndex++;

        if (frontIndex > rearIndex)
        {
            frontIndex = rearIndex = -1;
        }
    }

    void displayQueue()
    {
        if (frontIndex == -1)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Current Queue: ";

        for (int i = frontIndex; i <= rearIndex; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void frontElement()
    {
        if (frontIndex == -1)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Front element is: " << arr[frontIndex] << endl;
    }
};

int main()
{
    LinearQueue queueObj;
    int option, number;

    do
    {
        cout << "\n========== LINEAR QUEUE ==========";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display Queue";
        cout << "\n4. Front Element";
        cout << "\n5. Exit";

        cout << "\nChoose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter value: ";
            cin >> number;
            queueObj.insertElement(number);
            break;

        case 2:
            queueObj.deleteElement();
            break;

        case 3:
            queueObj.displayQueue();
            break;

        case 4:
            queueObj.frontElement();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Please enter a valid choice.\n";
        }

    } while (option != 5);

    return 0;
}
