#include <iostream>

using namespace std;


class ConfigReader{
public:
    
};

class BuyingSystem{
private:
    void LoadProducts(const string& filePath){
        ConfigReader configReader;
    }

public:
    BuyingSystem(const string& configFilePath){
        LoadProducts(configFilePath);
    }

    void ShowAll(){}
    void AddProduct(){}
    void Checkout(){}
    void CreateOrder(){}
    void ViewOrderHistory(){}

};


class CommandLineInterface{
private:
public:
    CommandLineInterface(){}

    void Commands(){
    string command;
    while (true) {
        cout << "Enter\n1)show all\n2)add product\n3)checkout\n4)create orders\n5)view order history\n6)exit\n";
        cin >> command;

        if (command == "show all"){
            printf("hello");

        } else if (command == "add product"){

        } else if (command == "checkout"){

        } else if (command == "create orders"){

        } else if (command == "view order history"){

        } else if (command == "exit"){
            break;
        } else{
            cout << "Invalid command" << endl;
        }

    }





}

};



int main() {
    BuyingSystem buyingSystem("/home/nastia/CLionProjects/OOPD_second/file.txt");
    CommandLineInterface interface;

    string start;
    cout << "Enter 'start': " << endl;
    cin >> start;

    if (start == "start"){
        interface.Commands();
    }

}
