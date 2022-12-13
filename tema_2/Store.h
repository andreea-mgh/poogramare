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

    // const Product& get_product(std::string id) const;

    const int find_product(std::string id);

    int get_quantity(std::string id);

    float get_price(std::string id);

    std::string get_name(std::string id);

    std::vector<std::shared_ptr<Synth>> get_synths();

    std::vector<std::shared_ptr<Software>> get_software();

    void show_inventory();

    void show_sales();
};

#endif