#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include<iostream>
#include<string>
#include<vector>
#include<memory>

class Product {
protected:
    std::string name;
    std::string product_id;
    float price;
    int quantity;

public:
    Product (std::string name_, std::string  product_id_, float price_, int quantity_);

    Product (std::string name_, std::string  product_id_, float price_ );

    Product(const Product &p);
    
    Product ();

    ~Product();

    virtual void set_quantity(int quantity_);
    virtual void set_price(float price_);
    virtual void set_name(std::string name_);
    virtual void set_product_id(std::string product_id_);
    virtual int get_quantity() const;
    virtual float get_price() const;
    virtual std::string get_name() const;
    virtual std::string get_product_id() const;

    virtual std::string get_category() = 0;
    virtual void print_extra(std::ostream& os) const = 0;

    int sell(int quantity_);
    void restock(int quantity_);

    Product& operator=(const Product& p);

    friend std::istream& operator>>(std::istream& is, Product& p);

    friend std::ostream& operator<<(std::ostream& os, const Product& p);
};

#endif