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



// const Product& Store::get_product(std::string id) const{
//     for (std::shared_ptr<Product> p : inventory) {
//         if(id == p->get_product_id()) {
//             return *p;
//         }
//     }
//     return -1;
// }

const int Store::find_product(std::string id) {
    int pos = 0;
    for (std::shared_ptr<Product> p : inventory) {
        pos++;
        if(id == p->get_product_id()) {
            return pos;
            break;
        }
    }
    return -1;
}

int Store::get_quantity(std::string id) {
    for (std::shared_ptr<Product> p : inventory) {
        if(id == p->get_product_id()) {
            return p->get_quantity();
        }
    }
    return -1;
}

float Store::get_price(std::string id) {
    for (std::shared_ptr<Product> p : inventory) {
        if(id == p->get_product_id()) {
            return p->get_price();
        }
    }
    return -1;
}

std::string Store::get_name(std::string id) {
    for (std::shared_ptr<Product> p : inventory) {
        if(id == p->get_product_id()) {
            return p->get_name();
        }
    }
    return "";
}

std::vector<std::shared_ptr<Synth>> Store::get_synths() {
    std::vector<std::shared_ptr<Synth>> synths;
    for (std::shared_ptr<Product> p : inventory) {
        if(dynamic_cast<Synth*>(p.get())) {
            synths.push_back(std::dynamic_pointer_cast<Synth>(p));
        }
    }
    return synths;
}

std::vector<std::shared_ptr<Software>> Store::get_software() {
    std::vector<std::shared_ptr<Software>> software;
    for (std::shared_ptr<Product> p : inventory) {
        if(dynamic_cast<Software*>(p.get())) {
            software.push_back(std::dynamic_pointer_cast<Software>(p));
        }
    }
    return software;
}

void Store::show_inventory() {
    for (std::shared_ptr<Product> p : inventory) {
        std::cout << *p << std::endl;
    }
}

void Store::show_sales() {
    std::cout << "Vanzari: " << sales << " lei" << std::endl;
}