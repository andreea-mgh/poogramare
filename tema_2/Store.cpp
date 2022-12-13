#include "Store.h"

Store::Store (std::string name_) : name(name_) { sales = 0; }

void Store::add_product(std::shared_ptr<Product> p) {
    inventory.push_back(p);
}

void Store::delete_product(std::string id) {
    int pos = 0;
    for (std::shared_ptr<Product> p : inventory) {
        pos++;
        if(id == p->get_product_id()) {
            inventory.erase(inventory.begin()+pos);
            break;
        }
    }
}

Store::~Store() {
    inventory.clear();
}

void Store::sell_product(std::string id, int q) {
    for (std::shared_ptr<Product> p : inventory) {
        if(id == p->get_product_id()) {
            if(p->sell(q)!=-1)
                sales += p->get_price() * q;
            break;
        }
    }
}

void Store::restock_product(std::string id, int q) {
    for (std::shared_ptr<Product> p : inventory) {
        if(id == p->get_product_id()) {
            p->restock(q);
            break;
        }
    }
}

Product& Store::get_product(std::string id) {
    for (std::shared_ptr<Product> p : inventory) {
        if(id == p->get_product_id()) {
            return *p;
        }
    }
}

int Store::get_quantity(std::string id) {
    for (std::shared_ptr<Product> p : inventory) {
        if(id == p->get_product_id()) {
            return p->get_quantity();
            break;
        }
    }
}

void Store::show_inventory() {
    for (std::shared_ptr<Product> p : inventory) {
        std::cout << *p << std::endl;
    }
}

void Store::show_sales() {
    std::cout << "Vanzari: " << sales << " lei" << std::endl;
}