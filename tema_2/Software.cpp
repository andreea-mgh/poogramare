#include "Software.h"

Software::Software (std::string name_, std::string product_id_, std::string developer_, std::string version_, std::string os_, float price_, int quantity_) :
    Product(name_, product_id_, price_, quantity_), developer(developer_), version(version_), os(os_) { }

Software::Software (std::string name_, std::string product_id_, float price_, int quantity_) :
    Product(name_, product_id_, price_, quantity_) { }

Software::Software (std::string name_, std::string product_id_, float price_) :
    Product(name_, product_id_, price_) { }

Software::Software () : Product(), developer(""), version(""), os("") { }

Software::Software(const Software &s) : Product(s), developer(s.developer), version(s.version), os(s.os) { }

Software::~Software() { }

std::string Software::get_developer() const {
    return developer;
}
std::string Software::get_version() const {
    return version;
}
std::string Software::get_os() const {
    return os;
}
void Software::set_developer(std::string developer_) {
    developer = developer_;
}
void Software::set_version(std::string version_) {
    version = version_;
}
void Software::set_os(std::string os_) {
    os = os_;
}

std::string Software::get_category() {
    return "Software";
}

Software& Software::operator=(const Software& s) {
    Product::operator=(s);
    this->developer = s.developer;
    this->version = s.version;
    this->os = s.os;
    return *this;
}

std::istream& operator>>(std::istream& is, Software& s) {
    is >> dynamic_cast<Product&>(s);
    std::cout<< "Developer: ";
    std::getline(is, s.developer);
    std::cout << "Versiune: ";
    std::getline(is, s.version);
    std::cout << "OS: ";
    std::getline(is, s.os);
    return is;
}

std::ostream& operator<<(std::ostream& os, Software& s) {
    os << dynamic_cast<const Product&>(s);
    os << "Developer: " << s.developer << std::endl;
    os << "Versiune: " << s.version << std::endl;
    os << "OS: " << s.os << std::endl;
    return os;
}