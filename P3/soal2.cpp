#include <iostream>
#include <string>

class Komponen {
protected:
    std::string nama;
    std::string merk;
    int harga;
public:
    Komponen(const std::string& nama, const std::string& merk, int harga)
        : nama(nama), merk(merk), harga(harga) {}
};

class Prosesor : virtual public Komponen {
protected:
    std::string tipe;
public:
    Prosesor(const std::string& nama, const std::string& tipe, const std::string& merk, int harga)
        : Komponen(nama, merk, harga), tipe(tipe) {}
};

class VGA : virtual public Komponen {
protected:
    std::string tipe;
public:
    VGA(const std::string& nama, const std::string& tipe, const std::string& merk, int harga)
        : Komponen(nama, merk, harga), tipe(tipe) {}
};

class PCRakitan : public Prosesor, public VGA {
public:
    PCRakitan(const std::string& namaProsesor, const std::string& tipeProsesor, const std::string& merkProsesor, int hargaProsesor,
              const std::string& namaVGA, const std::string& tipeVGA, const std::string& merkVGA, int hargaVGA)
        : Komponen("", "", 0),
          Prosesor(namaProsesor, tipeProsesor, merkProsesor, hargaProsesor),
          VGA(namaVGA, tipeVGA, merkVGA, hargaVGA),
          namaProsesor_(namaProsesor), tipeProsesor_(tipeProsesor), merkProsesor_(merkProsesor), hargaProsesor_(hargaProsesor),
          namaVGA_(namaVGA), tipeVGA_(tipeVGA), merkVGA_(merkVGA), hargaVGA_(hargaVGA) {}

    void tampilkanInfo() {
        std::cout << "Prosesor: " << namaProsesor_ << ", Tipe: " << tipeProsesor_ << ", Merk: " << merkProsesor_ << ", Harga: " << hargaProsesor_ << std::endl;
        std::cout << "VGA: " << namaVGA_ << ", Tipe: " << tipeVGA_ << ", Merk: " << merkVGA_ << ", Harga: " << hargaVGA_ << std::endl;
        std::cout << "Total Harga: " << (hargaProsesor_ + hargaVGA_) << std::endl;
    }
private:
    std::string namaProsesor_, tipeProsesor_, merkProsesor_;
    int hargaProsesor_;
    std::string namaVGA_, tipeVGA_, merkVGA_;
    int hargaVGA_;
};

int main() {
     for (int i = 0; i <=1; ++i) {
        std::string namaProsesor, tipeProsesor, merkProsesor;
        int hargaProsesor;
        std::string namaVGA, tipeVGA, merkVGA;
        int hargaVGA;
        std::cout << "Masukkan nama prosesor, tipe, merk, dan harga prosesor: ";
        std::cin >> namaProsesor >> tipeProsesor >> merkProsesor >> hargaProsesor;
        std::cout << "Masukkan nama VGA, tipe, merk, dan harga VGA: ";
        std::cin >> namaVGA >> tipeVGA >> merkVGA >> hargaVGA;
        
        PCRakitan rakitan(namaProsesor, tipeProsesor, merkProsesor, hargaProsesor, namaVGA, tipeVGA, merkVGA, hargaVGA);

       
        rakitan.tampilkanInfo();
     }
}
