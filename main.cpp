#include <iostream>
#include <string>

using namespace std;



class Product {
private:
    int productID;
    string name;
    float price;
    int quantityInStock;

public:
    Product(const int productID, string& name, float price, int quantityInStock)
            : productID(productID), name(name), price(price), quantityInStock(quantityInStock) {}

    virtual void displayDetails() const = 0;


    int getID() const {
        return productID;
    }

    string getName() const {
        return name;
    }

    int getQuantityInStock() const {
        return quantityInStock;
    }

    float getPrice() const {
        return price;
    }

    void setName(const string& newName) {
       name = newName;
    }

    void setPrice(float newPrice) {
        price = newPrice;
    }

    void setQuantityInStock(int quantity) {
        quantityInStock = quantity;
    }

    float totalCost() const {
        return price * quantityInStock;
    }

    ~Product() = default;
};


class Electronics : public Product{
private:
    string brand;
    string model;
    float powerConsumption;
public:
    Electronics(const int ProductID,string& name, float price, int quantityInStock, string& brand, string& model, float powerConsumption)
            : Product(ProductID, name, price, quantityInStock), brand(brand), model(model), powerConsumption(powerConsumption){}

    void displayDetails() const override {
        cout << "Product ID: " << getID() << ", Name: " << getName() << ", Price: " << getPrice()
             << "$, Quantity: " << getQuantityInStock() << ", Brand: " << brand << ", Model: " << model
             << ", Power: " << powerConsumption << " Watts" << endl;
    }

    string GetBrand() const {
        return brand;
    }

    string GetModel() const {
        return model;
    }

    float GetPowerConsumption() const {
        return powerConsumption;
    }
};

class Books : public Product{
private:
    string author;
    string genre;
    string ISBN;
public:
    Books(const int ProductID,string& name, float price, int quantityInStock, string& author, string& genre, string& ISBN)
            : Product(ProductID, name, price, quantityInStock), author(author), genre(genre), ISBN(ISBN){}

    void displayDetails() const override {
        cout << "Product ID: " << getID() << ", Name: " << getName() << ", Price: " << getPrice()
             << "$, Quantity: " << getQuantityInStock() << ", Author: " << author << ", Genre: "
             << genre<< ", ISBN: " << ISBN << endl;
    }

    string GetAuthor() const {
        return author;
    }

    string GetGenre() const {
        return genre;
    }

    string GetISBN() const {
        return ISBN;
    }



};

class Clothing: public Product{
private:
    string size;
    string color;
    string material;
public:
    Clothing(const int ProductID,string& name, float price, int quantityInStock, string& size, string& color, string& material)
            : Product(ProductID, name, price, quantityInStock), size(size), color(color), material(material){}


    void displayDetails() const override {
        cout << "Product ID: " << getID() << ", Name: " << getName() << ", Price: " << getPrice()
             << "$, Quantity: " << getQuantityInStock() << ", Size: " << size << ", Color: "
             << color << ", Material: " << material << endl;
    }

    string GetSize() const {
        return size;
    }

    string GetColor() const {
        return color;
    }

    string GetMaterial() const {
        return material;
    }
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