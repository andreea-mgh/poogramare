#ifndef _STORE_H_
#define _STORE_H_

#include "Synth.h"
#include "Software.h"

class Store {
private:
    std::string name;
    std::vector<std::shared_ptr<Product>> inventory;
    int sales;

public:
    Store (std::string name_);

    ~Store();

    void add_product(std::shared_ptr<Product> p);

    void delete_product(std::string id);

    void sell_product(std::string id, int q);

    void restock_product(std::string id, int q);

    Product& get_product(std::string id);

    int get_quantity(std::string id);

    void show_inventory();

    void show_sales();
};

#endif