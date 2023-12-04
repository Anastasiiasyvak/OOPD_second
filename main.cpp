#include <iostream>

using namespace std;


class Product{
private:
    int ProductID;
    string name;
    float price;
    int quantityInStock;
public:
    Product(int ProductID,string name, float price, int quantityInStock){};

    float TotalCost(){
        // method for calculating total cost
    };

    int GetProductID();
    string GetName();
    float GetPrice();
    int GetQuantityInStock();
    void setName(string name);
    void setPrice(float price);
    void setQuantityInStock(int quantityInStock);
};


class Electronics : public Product{
private:
    string brand;
    string model;
    float powerConsumption;
public:
    Electronics(int ProductID,string name, float price, int quantityInStock, string brand, string model, float powerConsumption)
    : Product(ProductID, name, price, quantityInStock), brand(move(brand)), model(move(model)), powerConsumption(move(powerConsumption)){}

};

class Books : public Product{
private:
    string author;
    string genre;
    string ISBN;
public:
    Books(int ProductID,string name, float price, int quantityInStock, string author, string genre, string ISBN)
    : Product(ProductID, name, price, quantityInStock), author(move(author)), genre(move(genre)), ISBN(move(ISBN)){}

};

class Clothing: public Product{
private:
    string size;
    string color;
    string material;
public:
    Clothing(int ProductID,string name, float price, int quantityInStock, string size, string color, string material)
    : Product(ProductID, name, price, quantityInStock), size(move(size)), color(move(color)), material(move(material)){}


};


class OrderClass{
private:
    int orderID;
    string customer;
    float TotalCost;
    bool orderStatus;
    string products; // a list of product in the order
public:
    OrderClass(int orderID, string customer, float TotalCost, bool orderStatus, string products){}

    void AddProducts();
    void CalculateTotalCost();
    bool ChangeOrderStatus();
};


class ProductCatalogClass{
private:
    string products; // a list of all products available in the system
public:
    ProductCatalogClass(string products){}

    void AddNewProductToCatalog();
    void UpdateExistingProductDetails();
    void RemoveProductFromCatalog();
    void ViewAllProductListInCatalog();
};

class InventoryClass{
private:
    string products; // list of products available in the inventory;
    int lowStockThreshold;
public:
    InventoryClass(string products){}
    void ManageStockLevel(); // add and subtract quantities
    void NotifyProductLowInStock();
    void GenerateListProductNeedRestocking();
};


class ConfigReader{
public:

};

class Customer{};

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
    string path = ("/home/nastia/CLionProjects/OOPD_second/file.txt");
    CommandLineInterface interface;

    string start;
    cout << "Enter 'start': " << endl;
    cin >> start;

    if (start == "start"){
        interface.Commands();
    }

}