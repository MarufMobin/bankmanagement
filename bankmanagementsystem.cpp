#include<bits/stdc++.h>
using namespace std;

class BankAccount{
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount( string account_holder, string address, int age, string password ){
        this->account_holder = account_holder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->account_number = rand()%1000000000;
        this->balance = 0;
        cout<<"Your account number is "<<this->account_number<<endl;
    }
    int show_balance( string password ){
        if( this->password == password ){
            return this->balance;
        }
        else{
            return -1;
        }
    }
    //Add money for make a Class Member
    void add_money( string password, int amount ){
        if( amount < 0 ) {
            cout<<"Invalid amount"<<endl;
            return;
        }
        if( this->password == password ){
            this->balance += amount;
            cout<<"Added Money Successfully"<<endl;
        }else{
            cout<<"Password didn't Match";
        }
    }
    void deposit_money( string password, int amount ){
        if( amount < 0 ) {
            cout<<"Invalid amount"<<endl;
            return;
        }

        if( this->balance < amount ){
            cout<<"Insufficient Balance "<<endl;
            return;
        }
        if( this->password == password ){
            this->balance -= amount;
        }else{
            cout<<"Password din't Match "<<endl;
        }
    }
    friend class MyCash;
};

class MyCash{

protected:
    int balance;
public:
    MyCash(){
        this->balance = 0;
    }
    void add_money_from_bank( BankAccount *myAccount, string password, int amount ){
        if( amount < 0 )
        {
            cout<<"Invalid Amount"<<endl;
            return;
        }
        if( myAccount->balance < amount ){
            cout<<"Insufficient Balance"<<endl;
            return;
        }
        if( myAccount->password == password ){
            this->balance += amount;
            myAccount->balance -= amount;
            cout<<"Add money from bank is Successful"<<endl;
        }else{
            cout<<"Password din't Match"<<endl;
        }
    }
    int show_balance(){
        return this->balance;
    }
};


BankAccount* create_account(){
    string account_holder, password, address;
    int age;
    cout<<"******Well Come Maruf's Bank********"<<endl;
    cout<<"_____________________________________"<<endl;
    cout<<endl;
    cout<<"         CREATE ACCOUNT              "<<endl;
    cout<<endl;
    cout<<"Please Enter Your Name : ";
    cin>>account_holder;
    cout<<"Please Enter Your Adderss : ";
    cin>>address;
    cout<<"Please Enter Your Age : ";
    cin>>age;
    cout<<"Please Enter Your Password : ";
    cin>>password;

    BankAccount *myAccount = new BankAccount(account_holder, address, age, password);
    return myAccount;
}


//Add Money Function
void add_money( BankAccount *myAccount ){
    string password;
    int amount;
    cout<<"ADD MONEY"<<endl;
    cout<<"Please Enter Your Password : ";
    cin>>password;
    cout<<"Please Enter Your Amount : ";
    cin>>amount;
    myAccount->add_money(password, amount);
    cout<<"Your Bank Balance is " << myAccount->show_balance("abc")<<endl;
}

void deposit_money( BankAccount *myAccount ){
    string password;
    int amount;
    cout<<"DEPOSIT MONEY"<<endl;
    cout<<"Please Enter Your Password : ";
    cin>>password;
    cout<<"Please Enter Your Amount : ";
    cin>>amount;
    myAccount->deposit_money( password, amount );
    cout<<"Your Bank Balance is " << myAccount->show_balance("abc")<<endl;
}

//Function For online App Account
void add_money_from_bank( MyCash *myCash, BankAccount *myAccount ){
    string password;
    int amount;
    cout<<"Add Money from Bank";
    cout<<"Enter Your Password : ";
    cin>>password;
    cout<<"Enter Your Amount : ";
    cin>>amount;
    myCash->add_money_from_bank(myAccount, password, amount);
    cout<<"Your Bank Balance is " << myAccount->show_balance("abc")<<endl;
    cout<<"MyCash Balance is "<<myCash->show_balance()<<endl;
}

int main(){
    BankAccount *myAccount = create_account();
    MyCash *myCash = new MyCash();
    flag:
        cout<<"************************************"<<endl;
        cout<<"* Select Option :                  *"<<endl;
        cout<<"* ---------------------------------*"<<endl;
        cout<<"* 1. Add Money to Bank             *"<<endl;
        cout<<"* ---------------------------------*"<<endl;
        cout<<"* 2. Deposit Money form Bank       *"<<endl;
        cout<<"* ---------------------------------*"<<endl;
        cout<<"* 3. Add Money to MyCash from Bank *"<<endl;
        cout<<"* ---------------------------------*"<<endl;
        cout<<"* 4. Finish Work ( Back )          *"<<endl;
        cout<<"* ---------------------------------*"<<endl;

        int option;
        cin>>option;
        if( option == 1 ){
            add_money(myAccount);
        }else if( option == 2 ){
            deposit_money(myAccount);
        }else if( option == 3 ){
            add_money_from_bank( myCash, myAccount);
        }else if( option == 4 ){
            return 0;
        }
        else{
            cout<<"Invalid option"<<endl;
        }
        goto flag;
    //Using While Loop for Control System
//    while(true){
//        cout<<"Select Option : "<<endl;
//        cout<<"1. Add Money to Bank"<<endl;
//        cout<<"2. Deposit Money form Bank"<<endl;
//        cout<<"3. Add Money to MyCash from Bank"<<endl;
//        cout<<"4. Finish Work ( Back ) "<<endl;
//        int option;
//        cin>>option;
//        if( option == 1 ){
//            add_money(myAccount);
//        }else if( option == 2 ){
//            deposit_money(myAccount);
//        }else if( option == 3 ){
//            add_money_from_bank( myCash, myAccount);
//        }else if( option == 4 ){
//            return 0;
//        }
//        else{
//            cout<<"Invalid option"<<endl;
//        }
//    }
    return 0;
}
