#include <iostream>
#include <string>

class Karakter {
protected:
    std::string nama;
    std::string elemen;
public:
    Karakter() {}
    Karakter(const std::string& nama, const std::string& elemen)
        : nama(nama), elemen(elemen) {}

    void printKarakter() const {
        std::cout << "Nama Karakter: " << nama << std::endl;
        std::cout << "Elemen: " << elemen << std::endl;
    }
};

class BintangEmpat : virtual public Karakter {
public:
    BintangEmpat() {}
    BintangEmpat(const std::string& nama, const std::string& elemen)
        : Karakter(nama, elemen) {}
};

class BintangLima : virtual public Karakter {
public:
    BintangLima() {}
    BintangLima(const std::string& nama, const std::string& elemen)
        : Karakter(nama, elemen) {}
};

class WishResult : public BintangEmpat, public BintangLima {
    std::string idWish;
    int primogem;
    std::string status;
    int rarityFinal;
public:
    WishResult(const std::string& nama, const std::string& elemen, int rarity,
               const std::string& idWish, int primogem, const std::string& status)
        : Karakter(nama, elemen), BintangEmpat(nama, elemen), BintangLima(nama, elemen),
          idWish(idWish), primogem(primogem), status(status), rarityFinal(rarity) {}

    void printInfo() const {
        std::cout << "=== Wish Result ===" << std::endl;
        printKarakter();
        std::cout << "Rarity: " << rarityFinal << "★" << std::endl;
        std::cout << "ID Wish: " << idWish << std::endl;
        std::cout << "Primogem Digunakan: " << primogem << std::endl;
        std::cout << "Status: " << status << std::endl;
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string nama, elemen, idWish, status;
        int rarity, primogem;
        std::cin >> nama >> elemen >> rarity >> idWish >> primogem >> status;

        if (rarity != 4 && rarity != 5) {
            std::cout << "Input rarity hanya boleh 4 atau 5!" << std::endl;
            continue;
        }

        WishResult w(nama, elemen, rarity, idWish, primogem, status);
        w.printInfo();
    }
    return 0;
}
