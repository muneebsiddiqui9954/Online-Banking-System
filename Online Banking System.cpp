#include<iostream>
using namespace std;

    class Transaction {
    public:
        string type;
        int amount;
        string date;

        Transaction(){

        }

        Transaction(string t, double a, string d) : type(t), amount(a), date(d) {}

        void display(){
            cout << amount << " " << type << " on Date: " << date << endl; 
        }

    };

    class User {
    private:
        string name;
        string email;

    public:
    User(){

    }
        User(string n, string e) : name(n), email(e) {

        }

        string getName(){
            return name;
        }
        string getEmail(){ 
            return email;
        }

};

    class Account {
private:
    int accountNumber;
    int balance;
    User user;
    Transaction transactions[500];
    int track = 0;

public:

    Account(){

    }

    Account(int accNo, int initialBalance) : accountNumber(accNo), balance(initialBalance) {}

    int getAccountNumber(){
        return accountNumber;
    }
    double getBalance(){
        return balance;
    }

    void createAccount(){
        string name, email;
        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter your E-mail: ";
        cin >> email;

        User newUser(name, email);

        user = newUser;
        accountNumber = 12345;

        cout << endl << "Your Account is Created Successfully . . . !" << endl;
    }

    void deposit() {

        int amount; string date;
        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        cout << "Enter Date: ";
        cin >> date;

        if (amount <= 0) throw invalid_argument("Amount must be positive.");

        Transaction trans("Deposit", amount, date);
        balance = balance + amount;

        transactions[track] = trans;

        cout << "Your Amount is submitted Successfully . . . !" << endl;

        track++;

    }

    void withdraw() {
        
        int amount; string date;
        cout << "Enter Amount to withdraw: ";
        cin >> amount;

        cout << "Enter Date: ";
        cin >> date;

        if (amount <= 0) throw invalid_argument("Amount must be positive.");
        if (amount > balance) throw runtime_error("Insufficient funds.");

        Transaction trans("WithDrawl", amount, date);
        balance = balance - amount;

        transactions[track] = trans;
        cout << endl << "Your Amount is WithDrawl Successfully . . . !" << endl;

        track++;

    }

    void printTransactionHistory(){
        cout << endl << "Account No.: " << accountNumber << endl;
        cout << "User Name: " << user.getName() << endl;
        cout << "User E-mail: " << user.getEmail() << endl;
        cout << "Total Balance: " << balance << endl;
        cout << "Transaction History for Account " << accountNumber << endl << endl;
        for(int i=0; i<track; i++){

            cout << transactions[i].amount << " " << transactions[i].type << " on Date: " << transactions[i].date << endl;  

        }
        cout << endl;
    }
};


int main(){

    Account acc1;

    int choice;
        do {
            cout << endl << "\n=== Online Banking System ===\n";
            cout << "1. Create your Account\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. View Transaction History\n";
            cout << "0. Exit\n";
            

            try {

                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice){
                    case 1:
                        acc1.createAccount();
                        break;

                    case 2:
                        acc1.deposit();
                        break;

                    case 3:
                        acc1.withdraw();
                        break;

                    case 4:
                        acc1.printTransactionHistory();
                        break;

                    case 0:
                        cout << "Thanks for using this Program" << endl;
                        break;

                    default:
                        cout << "Enter correct choice" << endl;

                }


                
            } 
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        } while (choice != 0);


    return 0;
}