#include <iostream>
using namespace std;
double balance = 100000.00;
void cheacked_Blance()
{
    cout << "Current Blance: " << balance << endl;
}
void deposit()
{
    double deposit;
    cout << "Enter the amount to deposit: ";
    cin >> deposit;
    balance += deposit;

    cout << "Deposit Successfully! \n";
}
void withDraw()
{
    double amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    if (amount <= balance)
    {
        balance -= amount;
        cout << "Withdraw Successfull! \n";
    }
    else
    {
        cout << "Aw kat sa baher pahal chadar sara phee gaza waa!...";
    }
}

int main()
{
    int choices;
    do
    {
        cout << "\n1.Cheacked Blance.\n";
        cout << "2.Deposite\n";
        cout << "3.Withdraw\n";
        cout << "4.Exit\n";
        cout << "Enter choices here: ";
        cin >> choices;
        switch (choices)
        {
        case 1:
            cheacked_Blance();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withDraw();
            break;
        case 4:
            cout << "Thanks you";
            break;
        default:
            cout << "Invalid Choices";
            break;
        }
    } while (choices != 4);

    return 0;
}