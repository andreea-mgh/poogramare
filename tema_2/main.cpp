#include "Product.h"
#include "Synth.h"
#include "Software.h"
#include "Store.h"


int main() {
    Store magazinul_meu("moog");

    // std::string boob;
    // std::getline(std::cin, boob);
    // std::cout<<boob;


    auto synth1 = new Synth("Sintetizator Analog Behringer TD-3-SB", "BEHTD3SB", "Behringer", "TD-3-SB", "analog", 510.30, 25);
    magazinul_meu.add_product(std::shared_ptr<Product>(synth1));
    auto synth2 = new Synth("Sintetizator Analog Behringer RD-6-BU", "BEHRD6BU", "Behringer", "RD-6-BU", "analog", 810.50, 10);
    magazinul_meu.add_product(std::shared_ptr<Product>(synth2));
    auto software1 = new Software("Guitar Rig 6 Pro", "GR6PRO", "Native Instruments", "6.0", "Windows", 1000.00, 100);
    magazinul_meu.add_product(std::shared_ptr<Product>(software1));
    auto software2 = new Software("Licenta FL Studio 21 - Fruity Edition", "FLS21FR", "Image Line Software", "21.0", "Windows", 500.00, 100);
    magazinul_meu.add_product(std::shared_ptr<Product>(software2));
    
    
    // magazinul_meu.add_product(Product("Muzicuta Meg", "MUZIMEG", 10.50, 100));

    // magazinul_meu.add_product(std::shared_ptr<Product>(Synth("Sintetizator Analog Behringer TD-3-GP", "BEHTD3GP", "Behringer", "TD-3-GP", "analog", 490.00, 25)));
    // magazinul_meu.add_product(Synth("Sintetizator Analog Behringer TD-3-SB", "BEHTD3SB", "Behringer", "TD-3-SB", "analog", 510.30, 25));
    // // magazinul_meu.add_product(Synth("Sintetizator Yamaha MX88 Black", "YMHMX88", "Yamaha", "MX88", "digital", 4360.00, 15));

    // magazinul_meu.add_product(Software("Licenta FL Studio 21 - Fruity Edition", "FLS21FR", "Image Line Software", "21.0", "Windows", 500.00, 100));
    // magazinul_meu.add_product(Software("Licenta FL Studio 21 - Producer Edition", "FLS21PR", "Image Line Software", "21.0", "Windows", 1000.00, 100));
    // magazinul_meu.add_product(Software("Licenta FL Studio 21 - Signature Bundle", "FLS21SB", "Image Line Software", "21.0", "Windows", 1500.00, 100));
    // magazinul_meu.add_product(Software("Licenta FL Studio 21 - All Plugins Bundle", "FLS21AP", "Image Line Software", "21.0", "Windows", 2500.00, 100));
    // magazinul_meu.add_product(Software("Guitar Rig 6 Pro", "GR6PRO", "Native Instruments", "6.0", "Windows", 1000.00, 100));

    // magazinul_meu.sell_product("BEHRD6BU", 5);
    // magazinul_meu.sell_product("BEHTD3GP", 8);
    // magazinul_meu.sell_product("FLS21PR", 1);



    // std::cout<< "Introduceti numarul de produse pe care doriti sa le adaugati: ";
    // int n;
    // std::cin >> n;
    // for(int i=0; i<n; i++) {
    //     int option;
    //     std::cout << "Ce produs doriti sa adaugati?" << std::endl;
    //     std::cout << "1. Sintetizator" << std::endl;
    //     std::cout << "2. Software" << std::endl;
    //     std::cout << "> "; std::cin >> option;

    //     if(option==1) {
    //         Synth* s = new Synth;
    //         std::cin >> *s;
    //         magazinul_meu.add_product(std::shared_ptr<Product>(s));
    //     }
    //     else if(option==2) {
    //         Software* s;
    //         std::cin >> *s;
    //         magazinul_meu.add_product(std::shared_ptr<Product>(s));
    //     }

    // }

    int option=1;
    while (option != 0)
    {
        std::cout << "1. Adauga produs" << std::endl;
        std::cout << "2. Sterge produs" << std::endl;
        std::cout << "3. Vanzare produs" << std::endl;
        std::cout << "4. Restocare produs" << std::endl;
        std::cout << "5. Afiseaza stoc" << std::endl;
        std::cout << "6. Afiseaza profit" << std::endl;
        std::cout << "0. Iesire" << std::endl;
        std::cout << "> " << std::endl;
        std::cin >> option;

        if (option == 1) {
            int o2;
            std::cout << "Ce produs doriti sa adaugati?" << std::endl;
            std::cout << "1. Sintetizator" << std::endl;
            std::cout << "2. Software" << std::endl;
            std::cout << "0. Anuleaza" << std::endl;
            std::cout << "> "; std::cin >> o2;
            
            if(o2==1) {
                Synth* s;
                std::cin >> *s;
                magazinul_meu.add_product(std::shared_ptr<Product>(s));
            }
            else if(o2==2) {
                Software* s;
                std::cin >> *s;
                magazinul_meu.add_product(std::shared_ptr<Product>(s));
            }
            else if(o2==0) {
                continue;
            }
        }
        else if (option == 2)
        {
            std::string id;
            std::cout << "Introduceti ID-ul produsului pe care doriti sa il stergeti: ";
            std::cin >> id;
            magazinul_meu.delete_product(id);
        }
        else if (option == 3)
        {
            std::string id;
            int quantity;
            std::cout << "Introduceti ID-ul produsului pe care doriti sa il vindeti: ";
            std::cin >> id;
            std::cout << "Introduceti cantitatea pe care doriti sa o vindeti: ";
            std::cin >> quantity;
            magazinul_meu.sell_product(id, quantity);
        }
        else if (option == 4)
        {
            std::string id;
            int quantity;
            std::cout << "Introduceti ID-ul produsului pe care doriti sa il restocati: ";
            std::cin >> id;
            std::cout << "Introduceti cantitatea pe care doriti sa o restocati: ";
            std::cin >> quantity;
            magazinul_meu.restock_product(id, quantity);
        }
        else if (option == 5)
        {
            magazinul_meu.show_inventory();
        }
        else if (option == 6)
        {
            magazinul_meu.show_sales();
        }
        else if (option == 0)
        {
            break;
        }
        else
        {
            std::cout << "Optiune invalida!" << std::endl;
        }

    }

    return 0;

}