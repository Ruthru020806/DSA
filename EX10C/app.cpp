#include "header2.h"

void displayMenu() {
    cout << "\n--- Quadratic Probing Hash Table Menu ---\n";
    cout << "1. Insert  Data\n";
    cout << "2. Delete  Data by ID\n";
    cout << "3. Search  Data by ID\n";
    cout << "4. Display Hash Table\n";
    cout << "5. Make Hash Table Empty\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
  int tablesize;
  cout << "Enter the size of Hash Table: ";
  cin >> tablesize;
  while (tablesize <= 0) {
    cout << "Please enter a positive integer for table size: ";
    cin >> tablesize;
  }

  // selectedTech is hardcoded to QUADRATIC within the class implementation
  QuadraticProbingHashTable table(tablesize);
  int choice = 0;
  EmployeeData emp;
  int key;

  do
  {
    displayMenu();
    cin >> choice;

    if (cin.fail()) {
        cout << "Invalid input. Clearing input buffer and restarting menu.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }
    if (choice < 1 || choice > 6) {
      cout << "Invalid input; please enter a number between 1 and 6.\n";
      continue;
    }

    switch (choice)
    {
      case 1: {
        emp.get();
        int r = table.Insert(emp);
        if (r == 0) cout << " data inserted successfully.\n";
        else if (r == 1) cout << "Insert failed: Hash table is full.\n";
        else if (r == -2) cout << "Insert failed: ID already exists.\n";
        else if (r == -3) cout << "Insert failed: Invalid Employee ID.\n";
        break;
      }
      case 2: {
        cout << "Enter ID to delete: ";
        cin >> key;
        int r = table.Delete(key);
        if (r == 0) cout << " data deleted successfully.\n";
        else if (r == 1) cout << "Delete failed: Hash table is empty.\n";
        else if (r == -1) cout << "Delete failed: Employee ID not found.\n";
        break;
      }
      case 3: {
        cout << "Enter ID to search: ";
        cin >> key;
        int r = table.Search(key);
        if (r == 0) cout << "Contact found and displayed.\n";
        else if (r == 1) cout << "Search failed: Hash table is empty.\n";
        else if (r == -1) cout << " ID not found.\n";
        break;
      }
      case 4: {
        int r = table.Display();
        if (r == 1) cout << "Hash table is empty.\n";
        break;
      }
      case 5: {
        int r = table.MakeHashingEmpty();
        if (r == 0) cout << "Hash table emptied successfully.\n";
        else if (r == 1) cout << "Hash table is already empty.\n";
        break;
      }
      case 6:
        cout << "Exiting program.\n";
        break;
      default:
        cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 6);

  return 0;
}
