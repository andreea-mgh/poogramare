#ifndef _SYNTH_H_
#define _SYNTH_H_

#include "Product.h"

class Synth : public Product {
private:
    std::string brand;
    std::string model;
    std::string type;

public:
    Synth (std::string name_, std::string product_id_, std::string brand_, std::string model_, std::string type_, float price_, int quantity_);

    Synth(std::string name_, std::string product_id_, std::string brand_, std::string model_, float price_, int quantity_);

    Synth (std::string name_, std::string  product_id_, float price_, int quantity_);

    Synth (std::string name_, std::string  product_id_, float price_ );

    Synth(const Synth &s);

    Synth ();

    virtual ~Synth();

    std::string get_brand() const;
    std::string get_model() const;
    std::string get_type() const;
    void set_brand(std::string brand_);
    void set_model(std::string model_);
    void set_type(std::string type_);

    std::string get_category();

    Synth& operator=(const Synth& s);

    friend std::istream& operator>>(std::istream& is, Synth& s);

    friend std::ostream& operator<<(std::ostream& os, const Synth& s);

};

#endif