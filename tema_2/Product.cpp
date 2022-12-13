#include "Product.h"

Product::Product (std::string name_, std::string  product_id_, float price_, int quantity_) :
    name(name_), product_id(product_id_), price(price_), quantity(quantity_) { }

Product::Product (std::string name_, std::string  product_id_, float price_ ) :  
    name(name_), product_id(product_id_), price(price_), quantity(1) { }

Product::Product () : name(""), product_id(""), price(0), quantity(0) { }

Product::Product(const Product &p) {
    name = p.name;
    product_id = p.product_id;
    price = p.price;
    quantity = p.quantity;
}

Product::~Product() { }

void Product::set_quantity(int quantity_) {
    quantity = quantity_;
}
void Product::set_price(float price_) {
    price = price_;
}
void Product::set_name(std::string name_) {
    name = name_;
}
void Product::set_product_id(std::string product_id_) {
    product_id = product_id_;
}
int Product::get_quantity() const {
    return quantity;
}
float Product::get_price() const {
    return price;
}
std::string Product::get_name() const {
    return name;
}
std::string Product::get_product_id() const {
    return product_id;
}

int Product::sell(int quantity_) {
    if (quantity_ > quantity) {
        std::cout << "Nu avem destule in stoc." << std::endl;
        return -1;
    }
    quantity -= quantity_;
    // std::cout << "vandut " << quantity_ << " ramas " << quantity << std::endl;
    return quantity_;
}
void Product::restock(int quantity_) {
    quantity += quantity_;
}

Product& Product::operator=(const Product& p) {
    name = p.name;
    product_id = p.product_id;
    price = p.price;
    quantity = p.quantity;
    return *this;
}

std::istream& operator>>(std::istream& is, Product& p) {
    std::cout << "Pret: ";
    is >> p.price;
    std::cout << "Cantitate: ";
    is >> p.quantity;
    std::cout << "Nume: ";
    std::getline(is, p.name);
    // is.getline(p.name, 100);
    std::cout << "ID: ";
    std::getline(is, p.product_id);
    // is.getline(p.product_id, 100);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Product& p) {
    os << "Pret: " << p.price << std::endl;
    os << "Cantitate: " << p.quantity << std::endl;
    os << "Nume: " << p.name << std::endl;
    os << "ID: " << p.product_id << std::endl;
    return os;
}
