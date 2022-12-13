#include "Synth.h"


Synth::Synth (std::string name_, std::string product_id_, std::string brand_, std::string model_, std::string type_, float price_, int quantity_) :
    Product(name_, product_id_, price_, quantity_), brand(brand_), model(model_), type(type_) { }

Synth::Synth(std::string name_, std::string product_id_, std::string brand_, std::string model_, float price_, int quantity_) :
    Product(name_, product_id_, price_, quantity_), brand(brand_), model(model_) { }

Synth::Synth (std::string name_, std::string  product_id_, float price_, int quantity_) : 
    Product(name_, product_id_, price_, quantity_) { }

Synth::Synth (std::string name_, std::string  product_id_, float price_ ) : 
    Product(name_, product_id_, price_) { }

Synth::Synth () : Product(), brand(""), model(""), type("") { }

Synth::Synth(const Synth &s) : Product(s) {
    brand = s.brand;
    model = s.model;
    type = s.type;
}

Synth::~Synth() { }

std::string Synth::get_brand() const {
    return brand;
}
std::string Synth::get_model() const {
    return model;
}
std::string Synth::get_type() const {
    return type;
}
void Synth::set_brand(std::string brand_) {
    brand = brand_;
}
void Synth::set_model(std::string model_) {
    model = model_;
}
void Synth::set_type(std::string type_) {
    type = type_;
}

std::string Synth::get_category() {
    return "Sintetizator";
}

Synth& Synth::operator=(const Synth& s) {
    Product::operator=(s);
    brand = s.brand;
    model = s.model;
    type = s.type;
    return *this;
}

std::istream& operator>>(std::istream& is, Synth& s) {
    is >> dynamic_cast<Product&>(s);
    std::cout << "Brand: ";
    std::getline(is, s.brand);
    std::cout << "Model: ";
    std::getline(is, s.model);
    std::cout<< "Tip: ";
    std::getline(is, s.type);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Synth& s) {
    os << dynamic_cast<const Product&>(s);
    os << "Brand: " << s.brand << std::endl;
    os << "Model: " << s.model << std::endl;
    os << "Tip: " << s.type << std::endl;
    return os;
}
