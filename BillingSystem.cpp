#include <iostream>
#include <vector>
using namespace std;

class Bill
{
private:
    int itemId;
    string itemName;
    int quantity;
    float price;

public:
    void addBill()
    {
        cout << "Enter Item ID: ";
        cin >> itemId;

        cout << "Enter Item Name: ";
        cin >> itemName;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: ";
        cin >> price;
    }

    void displayBill() const
    {
        cout << itemId << "\t"
             << itemName << "\t"
             << quantity << "\t"
             << price << "\n";
    }

    int getItemId() const
    {
        return itemId;
    }

    void updateBill()
    {
        cout << "Enter New Item Name: ";
        cin >> itemName;

        cout << "Enter New Quantity: ";
        cin >> quantity;

        cout << "Enter New Price: ";
        cin >> price;
    }
};

int main()
{
    vector<Bill> bills;
    int choice;

    do
    {
        cout << "\n--- Billing System ---\n";
        cout << "1. Add Bill\n";
        cout << "2. View Bills\n";
        cout << "3. Update Bill\n";
        cout << "4. Delete Bill\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Bill b;
            b.addBill();
            bills.push_back(b);
            cout << "Bill Added Successfully!\n";
        }
        else if (choice == 2)
        {
            cout << "ID\tName\tQty\tPrice\n";
            for (const auto &b : bills)
            {
                b.displayBill();
            }
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Item ID to Update: ";
            cin >> id;

            for (auto &b : bills)
            {
                if (b.getItemId() == id)
                {
                    b.updateBill();
                    cout << "Bill Updated Successfully!\n";
                    break;
                }
            }
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Item ID to Delete: ";
            cin >> id;

            for (auto it = bills.begin(); it != bills.end(); ++it)
            {
                if (it->getItemId() == id)
                {
                    bills.erase(it);
                    cout << "Bill Deleted Successfully!\n";
                    break;
                }
            }
        }

    } while (choice != 5);

    return 0;
}
