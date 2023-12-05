#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>

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


    int GetID() const {
        return productID;
    }

    string GetName() const {
        return name;
    }

    int GetQuantityInStock() const {
        return quantityInStock;
    }

    float GetPrice() const {
        return price;
    }

    void SetName(const string& newName) {
       name = newName;
    }

    void SetPrice(float newPrice) {
        price = newPrice;
    }

    void SetQuantityInStock(int quantity) {
        quantityInStock = quantity;
    }

    float TotalCost() const {
        return price * quantityInStock;
    }

};


class Electronics : public Product{
private:
    string brand;
    string model;
    float powerConsumption;
public:
    Electronics(const int ProductID,string& name, float price, int quantityInStock, string& brand, string& model, float& powerConsumption)
            : Product(ProductID, name, price, quantityInStock), brand(brand), model(model), powerConsumption(powerConsumption){}

    void displayDetails() const override {
        cout << "Product ID: " << GetID() << ", Name: " << GetName() << ", Price: " << GetPrice()
             << "$, Quantity: " << GetQuantityInStock() << ", Brand: " << brand << ", Model: " << model
             << ", Power: " << powerConsumption << endl;
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
        cout << "Product ID: " << GetID() << ", Name: " << GetName() << ", Price: " << GetPrice()
             << "$, Quantity: " << GetQuantityInStock() << ", Author: " << author << ", Genre: "
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
        cout << "Product ID: " << GetID() << ", Name: " << GetName() << ", Price: " << GetPrice()
             << "$, Quantity: " << GetQuantityInStock() << ", Size: " << size << ", Color: "
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
    string orderStatus;
    vector<Product*> products;


public:
    OrderClass(const int orderID, string customer) : orderID(orderID), customer(customer),  TotalCost(0.0), orderStatus("-"){}

    int GetID() const {
        return orderID;
    }
    void AddProducts(Product& product){
        TotalCost += product.GetPrice();
        products.push_back(&product);
    };

    float CalculateTotalCost() const{
        return TotalCost;
    };

    void ChangeOrderStatus(const string& status){
        orderStatus = status;
    };
};


class ProductCatalogClass{
private:
    vector<unique_ptr<Product>> products;

public:
    ProductCatalogClass() = default;

    void AddNewProductToCatalog(unique_ptr<Product>& product){
        products.push_back(move(product));
    };

    vector<unique_ptr<Product>>& GetProducts(){
        return products;
    }

    void UpdateExistingProductDetails(const int id, string& name, float price, int quantity){
        for (auto& product : products) {
            if (product->GetID() == id) {
                product->SetName(name);
                product->SetPrice(price);
                product->SetQuantityInStock(quantity);
                break;
            }
        }
    };
    void RemoveProductFromCatalog();

    void changeQuantityProduct(Product& removeProduct) {
        for (auto iterator = products.begin(); iterator != products.end(); ++iterator) {
            if ((*iterator)->GetID() == removeProduct.GetID()) {
                cout << removeProduct.GetQuantityInStock() << endl;
                int q  = removeProduct.GetQuantityInStock() - 1;
                (*iterator)->SetQuantityInStock(q);
                break;
            }
        }
    }

    void ViewAllProductListInCatalog(){
        for (const auto& product : products) {
            cout << "Product ID: " << product->GetID() << ", Name: " << product->GetName()
                 << ", Price: " << product->GetPrice() << "$, Quantity: " << product->GetQuantityInStock() << endl;
        }
    };

    void viewCertainProduct(const string& criteria) {
        stringstream ss(criteria);
        string category, attribute;
        getline(ss, category, ' ');
        getline(ss, attribute);

        for (const auto& product : products) {
            if (category == "Electronics") {
                const auto* electronics = dynamic_cast<const Electronics*>(product.get());
                if (electronics && (attribute.empty() || electronics->GetName() == attribute ||
                                    electronics->GetModel() == attribute || electronics->GetBrand() == attribute)) {
                    electronics->displayDetails();
                }
            } else if (category == "Books" ) {
                const auto *book = dynamic_cast<const Books *>(product.get());
                if (book && (attribute.empty() || book->GetName() == attribute || book->GetAuthor() == attribute
                             || book->GetGenre() == attribute)) {
                    book->displayDetails();
                }
            } else if (category == "Clothing") {
                const auto* clothing = dynamic_cast<const Clothing*>(product.get());
                if (clothing &&( attribute.empty() || clothing->GetName() == attribute || clothing->GetColor() == attribute
                                 || clothing->GetSize() == attribute)) {
                    clothing->displayDetails();
                }
            }}

    }
};



class InventoryClass{
private:
    vector<Product*> products;
    int lowStockThreshold;
public:
    InventoryClass(const int& threshold) : lowStockThreshold(threshold){}
    void manageStockLevels(Product& product) {
        bool found = false;
        for (const auto& product1 : products) {
            if (product1->GetID() == product.GetID()) {
                cout << product1->GetQuantityInStock() << endl;
                int q = product1->GetQuantityInStock() - 1;
                product1->SetQuantityInStock(q);
                found = true;
                break;
            }
        }
        if (!found) {
            products.push_back(&product);
        }
    }


    void NotifyProductLowInStock() const {
        bool found = false;
        for (const auto& product : products) {
            if (product->GetQuantityInStock() < lowStockThreshold) {
                found = true;
                cout << "The product " << product->GetName() << " with productID " << product->GetID() << " low in stock." << endl;
            }
        }
        if (!found){
            cout << "No restocking required" << endl;
        }
    };
    vector<Product*> needRestocking() {
        vector<Product*> lowStockProducts;
        for (const auto& product : products) {
            if (product->GetQuantityInStock() < lowStockThreshold) {
                lowStockProducts.push_back(product);
            }
        }
        return lowStockProducts;
    }
};


class Customer {
private:
    string name;
    vector<Product*> shoppingCart;
    vector<OrderClass> orders;

public:
    Customer(const string& name) : name(name) {}

    void addToCart(Product& product) {
        this->shoppingCart.push_back(&product);
    }

    string getName() const{
        return this->name;
    }

    void checkout(const int& id) {
        if (this->shoppingCart.empty()) {
            cout << "Shopping cart is empty!" << endl;
            return;
        }

        OrderClass newOrder(id, name);
        for (auto& product : this->shoppingCart) {
            newOrder.AddProducts(*product);
        }

        newOrder.ChangeOrderStatus("in process");
        this->orders.push_back(move(newOrder));
        this->shoppingCart.clear();
        cout << "The order received!" << endl;
        cout << "Confirmation order ID: " << id << endl;
    }

    void viewOrderHistory() const {
        if (this->orders.empty()) {
            cout << "No order history available." << endl;
            return;
        }

        cout << "Order history for " << this->name << ":\n";
        for (const auto& order : this->orders) {
            cout << "Order ID: " << order.GetID() << " Total Cost: " << order.CalculateTotalCost() << endl;
        }
    }

    vector<Product*>& getShoppingCart() {
        return this->shoppingCart;
    }

};




class ConfigReader {
public:
    ConfigReader()= default;

    ProductCatalogClass readConfiguration(const string& filePath) {
        ifstream file(filePath);
        ProductCatalogClass catalog;
        string line;
        string type, name, brand, model, author, genre, isbn, size, color, material;
        int quantity;
        float price, power;
        int nextID = 123;

        if (!file.is_open()) {
            cout << "Unable to open the file. Try again." << endl;
            return catalog;
        }

        while (getline(file, line)){
            stringstream ss(line);
            getline(ss, type, ',');

            if (type == "Electronics") {
                ss.ignore(1, ',');
                getline(ss, name, ',');
                ss >> price;
                ss.ignore(1, ',');
                ss >> quantity;
                ss.ignore(1, ',');
                getline(ss, brand, ',');
                ss.ignore(1, ',');
                getline(ss, model, ',');
                ss.ignore(1, ',');
                ss >> power;
                auto electronic = make_unique<Electronics>(nextID++, name, price, quantity, brand, model, power);
                catalog.AddNewProductToCatalog((unique_ptr<Product> &) move(electronic));
            }
            else if (type == "Books") {
                ss.ignore(1, ',');
                getline(ss, name, ',');
                ss >> price;
                ss.ignore(1, ',');
                ss >> quantity;
                ss.ignore(1, ',');
                getline(ss, author, ',');
                ss.ignore(1, ',');
                getline(ss, genre, ',');
                ss.ignore(1, ',');
                getline(ss, isbn);
                auto book = make_unique<Books>(nextID++, name, price, quantity, author, genre, isbn);
                catalog.AddNewProductToCatalog((unique_ptr<Product> &) move(book));
            }
            else if (type == "Clothing") {
                ss.ignore(1, ',');
                getline(ss, name, ',');
                ss >> price;
                ss.ignore(1, ',');
                ss >> quantity;
                ss.ignore(1, ',');
                getline(ss, size, ',');
                ss.ignore(1, ',');
                getline(ss, color, ',');
                ss.ignore(1, ',');
                getline(ss, material);
                auto clothing = make_unique<Clothing>(nextID++, name, price, quantity, size, color, material);
                catalog.AddNewProductToCatalog((unique_ptr<Product> &) move(clothing));
            }
        }

        return catalog;
    }
};

class Shopping {
private:
    ProductCatalogClass catalog;
    InventoryClass inventory;
    vector<unique_ptr<Customer>> customers;
    int orderId = 1;

    void loadCatalog(const string& filePath) {
        ConfigReader reader;
        catalog = reader.readConfiguration(move(filePath));
    }

public:
    Shopping(string& catalogFilePath, int lowStockThreshold) : inventory(move(lowStockThreshold)) {
        loadCatalog(catalogFilePath);
        for (auto& product : catalog.GetProducts()) {
            inventory.manageStockLevels(*product);
        }
    }

    void showAll() {
        catalog.ViewAllProductListInCatalog();
    }

    void showCertain(string& criteria) {
        catalog.viewCertainProduct(criteria);
    }

    void addProduct() {
        string customerName;
        int productId;
        cout << "Enter your name and the product ID: " << endl;
        cin >> customerName >> productId;

        unique_ptr<Customer>* existingCustomer = nullptr;
        for (auto& customer : customers) {
            if (customer->getName() == customerName) {
                existingCustomer = &customer;
                break;
            }
        }

        if (!existingCustomer) {
            customers.push_back(make_unique<Customer>(customerName));
            existingCustomer = &customers.back();
        }

        bool productAdded = false;
        for (auto& product : catalog.GetProducts()) {
            if (product->GetID() == productId) {
                (*existingCustomer)->addToCart(*product);
                cout << "The product added to your cart successfully!" << endl;
                productAdded = true;
                break;
            }
        }

        if (!productAdded) {
            cout << "Product ID not found." << endl;
        }

        cin.ignore();
    }

    void showCart(){
        string customerName;
        cout << "Enter your name: " << endl;
        cin >> customerName;

        bool found = false;
        for (auto& customer : customers) {
            if (customer->getName() == customerName){
                found = true;
                for (auto& product : customer->getShoppingCart())
                {
                    cout << "Product ID: " << product->GetID() << ", Name: " << product->GetName() << ", Price: $" << product->GetPrice() << endl;
                }
                break;
            }
        }
        if (!found){
            cout << "Incorrect customer name." << endl;
        }
        cin.ignore();
    }

    void checkout() {
        string customerName;
        cout << "Enter your name: " << endl;
        cin >> customerName;

        bool found = false;
        for (auto& customer : customers) {
            if (customer->getName() == customerName){
                found = true;
                for (auto product : customer->getShoppingCart())
                {
                    inventory.manageStockLevels(*product);
                }
                customer->checkout(orderId);
                orderId++;
                break;
            }
        }
        if (!found){
            cout << "Incorrect customer name." << endl;
        }

        cout << "\n------ Notification ------" << endl;
        inventory.NotifyProductLowInStock();
        cout << "-----------------------------------" << endl;
        cin.ignore();
    }

    void viewOrderHistory() {
        string customerName;
        cout << "Enter your name: " << endl;
        cin >> customerName;

        bool found = false;
        for (auto& customer : customers) {
            if (customer->getName() == customerName){
                found = true;
                customer->viewOrderHistory();
                break;
            }
        }
        if (!found){
            cout << "Incorrect customer name." << endl;
        }
        cin.ignore();
    }

    void needRestocking() {
        auto productsToRestock = inventory.needRestocking();
        if (productsToRestock.empty()) {
            cout << "No items need restocking." << endl;
        } else {
            cout << "Items that need to be restocked: " << endl;
            for (const auto& product : productsToRestock) {
                cout << "Product ID: " << product->GetID()
                     << ", Name: " << product->GetName()
                     << ", Current Stock: " << product->GetQuantityInStock()
                     << endl;
            }
        }
    }
};



class ConsoleLogic{
private:
    Shopping shop;
    bool isRunning;

public:
    ConsoleLogic(string& filePath, int lowInStock) : shop(filePath, move(lowInStock)), isRunning(true) {};

    void run() {
        string command;
        while (isRunning) {
            cout << "\nAll commands:\n"
                 << " -show all;\n"
                 << " -show 'category attribute';\n"
                 << " -add a product;\n"
                 << " -check the cart;\n"
                 << " -checkout;\n"
                 << " -view order history;\n"
                 << " -need restocking;\n"
                 << " -exit;\n"
                 << "Enter command: " << endl;
            getline(cin, command);

            if (command == "show all") {
                shop.showAll();
            } else if (command.rfind("show ", 0) == 0) {
                std::string criteria = command.substr(5);
                shop.showCertain(criteria);
            } else if (command == "add a product") {
                shop.addProduct();
            } else if (command == "check the cart") {
                shop.showCart();
            } else if (command == "checkout") {
                shop.checkout();
            } else if (command == "view order history") {
                shop.viewOrderHistory();
            } else if (command == "need restocking") {
                shop.needRestocking();
            } else if (command == "exit") {
                isRunning = false;
            } else {
                cout << "Invalid command." << endl;
            }
        }
    }
};

int main() {
    string path = "/home/nastia/CLionProjects/OOPD_second/file.txt";
    ConsoleLogic console(path, 6);
    console.run();

    return 0;
}