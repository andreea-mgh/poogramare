#ifndef _SOFTWARE_H_
#define _SOFTWARE_H_

#include "Product.h"

class Software : public Product {
private:
    std::string developer;
    std::string version;
    std::string os;

public:
    Software (std::string name_, std::string product_id_, std::string developer_, std::string version_, std::string os_, float price_, int quantity_);

    Software (std::string name_, std::string product_id_, float price_, int quantity_);

    Software (std::string name_, std::string product_id_, float price_);
    
    Software ();
    
    Software(const Software &s);

    virtual ~Software();

    std::string get_developer() const;
    std::string get_version() const;
    std::string get_os() const;
    void set_developer(std::string developer_);
    void set_version(std::string version_);
    void set_os(std::string os_);

    std::string get_category();

    virtual void print_extra(std::ostream& os) const;

    Software& operator=(const Software& s);

    friend std::istream& operator>>(std::istream& is, Software& s);

    friend std::ostream& operator<<(std::ostream& os, Software& s);
};

#endif