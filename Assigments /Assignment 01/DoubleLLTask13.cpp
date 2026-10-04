#include <iostream>
using namespace std;

class Item
{
public:
    string name;
    Item* next;

    Item(string n)
    {
        name = n;
        next = NULL;
    }
};

class Section
{
public:
    string name;
    Section* next;
    Item* items;

    Section(string n)
    {
        name = n;
        next = NULL;
        items = NULL;
    }
};

class Store
{
public:
    string name;
    Store* next;
    Section* sections;

    Store(string n)
    {
        name = n;
        next = NULL;
        sections = NULL;
    }
};

Store* stores = NULL;

// Add a new store
void addStore(string name)
{
    Store* newStore = new Store(name);

    if (stores == NULL)
    {
        stores = newStore;
        return;
    }

    Store* temp = stores;

    // Move to the last store
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newStore;
}

// Add a section inside a store
void addSection(string storeName, string sectionName)
{
    Store* store = stores;

    // Find the required store
    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* newSection = new Section(sectionName);

    if (store->sections == NULL)
    {
        store->sections = newSection;
        return;
    }

    Section* temp = store->sections;

    // Move to the last section
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newSection;
}

// Add an item inside a section
void addItem(string storeName, string sectionName, string itemName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    // Find the required section
    while (section != NULL && section->name != sectionName)
        section = section->next;

    if (section == NULL)
        return;

    Item* newItem = new Item(itemName);

    if (section->items == NULL)
    {
        section->items = newItem;
        return;
    }

    Item* temp = section->items;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newItem;
}

// Remove an item from a section
void removeItem(string storeName, string sectionName, string itemName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    while (section != NULL && section->name != sectionName)
        section = section->next;

    if (section == NULL)
        return;

    // Check if the first item needs to be removed
    if (section->items != NULL &&
        section->items->name == itemName)
    {
        Item* temp = section->items;
        section->items = section->items->next;

        delete temp;
        return;
    }

    Item* current = section->items;

    while (current != NULL && current->next != NULL)
    {
        if (current->next->name == itemName)
        {
            // Remove the matching item
            Item* temp = current->next;
            current->next = temp->next;

            delete temp;
            return;
        }

        current = current->next;
    }
}

// Display all items of one section
void displaySection(string storeName, string sectionName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    while (section != NULL && section->name != sectionName)
        section = section->next;

    if (section == NULL)
        return;

    Item* item = section->items;

    cout << "Items in " << sectionName << ": ";

    while (item != NULL)
    {
        cout << item->name << " ";
        item = item->next;
    }

    cout << endl;
}

// Display all sections and items of a store
void displayStore(string storeName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    cout << "Items in " << storeName << ":\n";

    while (section != NULL)
    {
        cout << section->name << ": ";

        Item* item = section->items;

        while (item != NULL)
        {
            cout << item->name << " ";
            item = item->next;
        }

        cout << endl;

        section = section->next;
    }
}

int main()
{
    // Add a store
    addStore("Attock Store");

    // Add sections
    addSection("Attock Store", "Grocery");
    addSection("Attock Store", "Toys");

    // Add items
    addItem("Attock Store", "Grocery", "Milk");
    addItem("Attock Store", "Grocery", "Bread");
    addItem("Attock Store", "Toys", "Car");

    // Display one section
    displaySection("Attock Store", "Grocery");

    // Remove an item
    removeItem("Attock Store", "Grocery", "Bread");

    cout << "\nAfter removing Bread:\n";

    // Display the complete store
    displayStore("Attock Store");

    return 0;
}
