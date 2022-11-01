#include<iostream>
#include<cstring>

using namespace std;

class Roman {
    private:
        int value;
        char* numeral;

        char* int_to_rom(int val) {
            int len = 0;
            char result[16];
            
            while(val>1000) {
                result[len]='M';
                len++;
                val-=1000;
            }

            switch (val/100) {
            case 1:
                result[len]='C';
                len++;
                val%=100;
                break;
            case 2:
                result[len]  ='C';
                result[len+1]='C';
                len+=2;
                val%=100;
                break;
            case 3:
                result[len]  ='C';
                result[len+1]='C';
                result[len+2]='C';
                len+=3;
                val%=100;
                break;
            case 4:
                result[len]  ='C';
                result[len+1]='D';
                len+=2;
                val%=100;
                break;
            case 5:
                result[len]='D';
                len++;
                val%=100;
                break;
            case 6:
                result[len]='D';
                result[len+1]='C';
                len+=2;
                val%=100;
                break;
            case 7:
                result[len]='D';
                result[len+1]='C';
                result[len+2]='C';
                len+=3;
                val%=100;
                break;
            case 8:
                result[len]='D';
                result[len+1]='C';
                result[len+2]='C';
                result[len+3]='C';
                len+=4;
                val%=100;
                break;
            case 9:
                result[len]='C';
                result[len+1]='M';
                len+=2;
                val%=100;
                break;
            default:
                break;
            }

            switch (val/10) {
            case 1:
                result[len]='X';
                len++;
                val%=10;
                break;
            case 2:
                result[len]  ='X';
                result[len+1]='X';
                len+=2;
                val%=10;
                break;
            case 3:
                result[len]  ='X';
                result[len+1]='X';
                result[len+2]='X';
                len+=3;
                val%=10;
                break;
            case 4:
                result[len]  ='X';
                result[len+1]='L';
                len+=2;
                val%=10;
                break;
            case 5:
                result[len]='L';
                len++;
                val%=10;
                break;
            case 6:
                result[len]='L';
                result[len+1]='X';
                len+=2;
                val%=10;
                break;
            case 7:
                result[len]='L';
                result[len+1]='X';
                result[len+2]='X';
                len+=3;
                val%=10;
                break;
            case 8:
                result[len]='L';
                result[len+1]='X';
                result[len+2]='X';
                result[len+3]='X';
                len+=4;
                val%=10;
                break;
            case 9:
                result[len]='X';
                result[len+1]='C';
                len+=2;
                val%=10;
                break;
            default:
                break;
            }

            switch (val) {
            case 1:
                result[len]='I';
                len++;
                break;
            case 2:
                result[len]  ='I';
                result[len+1]='I';
                len+=2;
                break;
            case 3:
                result[len]  ='I';
                result[len+1]='I';
                result[len+2]='I';
                len+=3;
                break;
            case 4:
                result[len]  ='I';
                result[len+1]='V';
                len+=2;
                break;
            case 5:
                result[len]='V';
                len++;
                break;
            case 6:
                result[len]='V';
                result[len+1]='I';
                len+=2;
                break;
            case 7:
                result[len]='V';
                result[len+1]='I';
                result[len+2]='I';
                len+=3;
                break;
            case 8:
                result[len]='V';
                result[len+1]='I';
                result[len+2]='I';
                result[len+3]='I';
                len+=4;
                break;
            case 9:
                result[len]='I';
                result[len+1]='X';
                len+=2;
                break;
            default:
                break;
            }
            char* rom = (char*)malloc(len*sizeof(char*));
            strcpy(rom, result);
            return rom;
        }
        int rom_to_int(const char* rom) {
            int len = strlen(rom);
            int val = 0;
            for(int i=0; i<len; i++) {
                //M
                if(rom[i] == 'M' || rom[i] == 'm') {
                    val += 1000;
                }

                //D
                else if(rom[i] == 'D' || rom[i] == 'd') {
                    val += 500;
                }

                //C
                else if(rom[i] == 'C' || rom[i] == 'c') {
                    if(i!=len-1) 
                        if(rom[i+1] == 'M' || rom[i+1] == 'm') {
                            val += 900;
                            i++;
                        }
                        else if(rom[i+1] == 'D' || rom[i+1] == 'd') {
                            val += 400;
                            i++;
                        }
                        else val += 100;
                    else val += 100;
                }

                //L
                else if(rom[i] == 'L' || rom[i] == 'l') {
                    val += 50;
                }

                //X
                else if(rom[i] == 'X' || rom[i] == 'x') {
                    if(i!=len-1) 
                        if(rom[i+1] == 'C' || rom[i+1] == 'c') {
                            val += 90;
                            i++;
                        }
                        else if(rom[i+1] == 'L' || rom[i+1] == 'l') {
                            val += 40;
                            i++;
                        }
                        else val += 10;
                    else val += 10;
                }

                //V
                else if(rom[i] == 'V' || rom[i] == 'v') {
                    val += 5;
                }

                //I
                else if(rom[i] == 'I' || rom[i] == 'i') {
                    if(i!=len-1) 
                        if(rom[i+1] == 'X' || rom[i+1] == 'x') {
                            val += 9;
                            i++;
                        }
                        else if(rom[i+1] == 'V' || rom[i+1] == 'v') {
                            val += 4;
                            i++;
                        }
                        else val += 1;
                    else val += 1;
                }
            }
            return val;
        }

    public:
        Roman() {
            value = 0;
        }
        Roman(int value) {
            this->value = value;

            //const char* result = int_to_rom(value);
            //this->numeral = new char[strlen(result)+1];
            setRoman(int_to_rom(value));
        }
        Roman(const char* numeral) {
            this->value = rom_to_int(numeral);
            
            //this->numeral = new char[strlen(numeral)+1];
            setRoman(numeral);
        }
        Roman(const Roman &r) {
            this->value = r.value;

            //this->numeral = new char[strlen(r.numeral)+1];
            setRoman(r.numeral);
        }

        ~Roman() {
            delete[] numeral;
        }
        
        int getValue() const {
            return this->value;
        }
        char* getRoman() const {
            return this->numeral;
        }

        void setRoman(const char* rom) {
            this->value = rom_to_int(rom);
            this->numeral = new char[strlen(rom)];
            for(int i=0; i<strlen(rom); i++) this->numeral[i]=toupper(rom[i]);
        }
        void setValue(const int val) {
            this->value = val;
            const char* rom = int_to_rom(val);
            this->numeral = new char[strlen(rom)];
            strcpy(this->numeral, rom);
        }

        Roman operator+=(const Roman &rhs) {
            this->value = this->value + rhs.value;
            strcpy(this->numeral, int_to_rom(this->value));
            return *this;
        }
        Roman operator+=(const char* rhs) {
            this->value = this->value + rom_to_int(rhs);
            strcpy(this->numeral, int_to_rom(this->value));
            return *this;
        }
        Roman operator+=(const int rhs) {
            this->value = this->value + rhs;
            strcpy(this->numeral, int_to_rom(this->value));
            return *this;
        }
        Roman operator-=(const Roman &rhs) {
            this->value = this->value - rhs.value;
            strcpy(this->numeral, int_to_rom(this->value));
            return *this;
        }
        Roman operator-=(const char* rhs) {
            this->value = this->value - rom_to_int(rhs);
            strcpy(this->numeral, int_to_rom(this->value));
            return *this;
        }
        Roman operator-=(const int rhs) {
            this->value = this->value - rhs;
            strcpy(this->numeral, int_to_rom(this->value));
            return *this;
        }

        Roman& operator=(const Roman &rhs) {
            if(this != &rhs) {
                setValue(rhs.value);
            }
            return *this;
        }

        bool operator==(const Roman &rhs) const {
            return this->value == rhs.value;
        }
        bool operator!=(const Roman &rhs) const {
            return this->value != rhs.value;
        }
        
        void afisare() {
            std::cout << this->numeral << endl;
        }

        friend std::istream& operator>>(std::istream &is, Roman &s) {

            char buf[100];
            is >> buf;
            s.setRoman(buf);

            return is;
        }
        friend std::ostream& operator<<(std::ostream &os, Roman &s) {

            os << s.getRoman();

            return os;
        }
};

int main() {
    int n;
    Roman* r;

    std::cout << "Câte numere vrei să citești?" <<endl;
    std::cin>>n;

    r = new Roman[n];

    for(int i=0; i<n; i++) {
        std::cin >> r[i];
    }

    while(true) {
        std::cout << endl
        << "1: afișare" << endl
        << "2: modificare" << endl
        << "3: adăugare element" << endl
        << "4: ștergere element" << endl
        << "5: adunare" << endl
        << "6: scădere" << endl
        << "7: ieșire" << endl
        << "> ";

        int input;
        std::cin>>input;
        if(input==1) {
            int a, b;
            std::cout<<"numere: "; std::cin>>a>>b;
            if(b>n || a>b || a<1) std::cout<<"nu se poate face afișarea"<<endl;
            else for(int i=a-1; i<b; i++) {
                std::cout<<r[i]<<endl;
            }
        }
        else if(input==2) {
            int a, b;
            std::cout<<"numere: "; std::cin>>a>>b;
            if(b>n || a>b || a<1) std::cout<<"nu se poate face modificarea"<<endl;
            else for(int i=a-1; i<b; i++) {
                std::cout<<"valoare nouă pentru numărul "<<i+1<<": ";
                std::cin>>r[i];
            }
        }
        else if(input==3) {
            int a;
            Roman r_ins;
            std::cout<<"după elementul: "; std::cin>>a;
            std::cout<<"element inserat: "; std::cin>>r_ins;

            if(a<1 || a>n) std::cout<<"poziția nu se află în listă";
            else {
                Roman* r_aux;
                r_aux = new Roman[n+1];
                for(int i=0; i<a; i++) r_aux[i] = r[i];
                r_aux[a] = r_ins;
                for(int i=a+1; i<=n; i++) r_aux[i] = r[i-1];

                delete[] r;
                r = r_aux;
                n++;
            }
        }
        else if(input==4) {
            int a;
            std::cout<<"elementul: "; std::cin>>a;

            if(a<1 || a>n) std::cout<<"poziția nu se află în listă";
            else {
                Roman* r_aux;
                r_aux = new Roman[n-1];
                for(int i=0; i<a-1; i++) r_aux[i] = r[i];
                for(int i=a-1; i<n-1; i++) r_aux[i] = r[i+1];

                delete[] r;
                r = r_aux;
                n--;
            }
        }
        else if(input==5) {
            int a;
            std::cout<<"număr: "; std::cin>>a;
            if(a<1 || a>n) std::cout<<"poziția nu se află în listă";
            else {
                std::cout<<r[a-1]<< " + ";
                Roman rom;
                std::cin>>rom;
                r[a-1]+=rom;
            }
        }
        else if(input==6) {
            int a;
            std::cout<<"număr: "; std::cin>>a;
            if(a<1 || a>n) std::cout<<"poziția nu se află în listă";
            else {
                std::cout<<r[a-1]<< " - ";
                Roman rom;
                std::cin>>rom;
                r[a-1]-=rom;
            }
        }
        else if(input==7) {
            break;
        }
    }

    return 0;
}