#include<bits/stdc++.h>
using namespace std;
class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;
public:
    Restaurant( int n, int *food_item_codes, string *food_item_names, int *food_item_prices ){
        for( int i = 0; i < n; i++ ){
            this->food_item_codes[i] = food_item_codes[i];
            this->food_item_names[i]  = food_item_names[i];
            this->food_item_prices[i] = food_item_prices[i];
        }
    }
};

//Set User Given Value in a Object
Restaurant* create_restaurant( int n ){
    int food_item_codes[n];
    string food_item_names[n];
    int food_item_prices[n];
    for( int i = 0; i < n; i++ ){
        cin>>food_item_codes[i];
        getchar();
        getline(cin,food_item_names[i]);
        cin>>food_item_prices[i];
    }
    Restaurant* restaurantObj = new Restaurant( n, food_item_codes, food_item_names, food_item_prices );
    return restaurantObj;
}
// Showing Restaurant Menu
void getShowMenu( Restaurant* restaurantObj, int n ){
    cout<<" ***************** RESTAURANT MENU LIST ***************** "<<endl;
    cout<<" _________________________________________________________"<<endl<<endl;
    cout<<" SL:\tCODES:\tFOOD NAME:\t\t\tFOOD PRICE: "<<endl<<endl;
    for( int i = 0; i < n; i++ ){
        cout<<" "<<i+1<<"\t";
        cout<<restaurantObj->food_item_codes[i]<<"\t";
        cout<<restaurantObj->food_item_names[i]<<"\t\t";
        cout<<restaurantObj->food_item_prices[i];
        cout<<endl;
        cout<<endl;
    }
}
void showOrder( Restaurant* restaurantObj,int foodCode, int foodquantity ){
    for( int i = 0; i < 12; i++ ){
        if( restaurantObj->food_item_codes[i] == foodCode ){
            cout<<" * "<<foodCode<<"\t\t"<<restaurantObj->food_item_names[i]<< "\t\t" <<foodquantity<<"\t\t\t"<<restaurantObj->food_item_prices[i]<<"\t\t\t"<<restaurantObj->food_item_prices[i]*foodquantity<<"\t\t"<<endl;
        }
    }
}

void getOrder( Restaurant* restaurantObj ){
    int tableNum, itemNum;
    cout<<" Please Give me Your Table Number : ";
    cin>>tableNum;
    cout<<" Please Enter Your Food item Number: ";
    cin>>itemNum;
    int foodCode[itemNum], foodquantity[itemNum];
    for( int i = 0; i < itemNum; i++ ){
        cout<<" Please Give me your "<<i+1<<" Food Code Number : ";
        cin>>foodCode[i];
        cout<<" Please add your Quantity : ";
        cin>>foodquantity[i];
    }
    cout<<" **********************************************************************************************************"<<endl;
    cout<<" ********************************************** BILL SUMMARY **********************************************"<<endl;
    cout<<" **********************************************************************************************************"<<endl;
    cout<<" FOOD CODE:\tFOOD NAME:\t\t\tFOOD QUENTITY:\t\tFOOD PRICE:\t\tTOTAL PRICE"<<endl;
    cout<<" **********************************************************************************************************"<<endl;
    for( int i = 0; i < itemNum; i++ ){
        showOrder( restaurantObj, foodCode[i], foodquantity[i] );
    }
    cout<<" __________________________________________________________________________________________________________"<<endl;
    cout<<" TOTAL AMOUNT USING TAX                                                                       =";
}

int main(){
    int n;
    cin>>n;
    Restaurant* restaurantObj;
    restaurantObj = create_restaurant(n);
    getShowMenu( restaurantObj, n );
    getOrder( restaurantObj );
    return 0;
}
