#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& n, double p)
        : name(n), price(p) {}

    virtual double getPrice() const {
        return price;
    }

    string getName() const {
        return name;
    }

    virtual ~Product() {}
};

// ??????? (??'???-???????) ??? ?????????? ??????
class DiscountCalculator {
private:
    double percent;

public:
    DiscountCalculator(double p)
        : percent(p) {}

    double operator()(double basePrice) const {
        return basePrice * (1.0 - percent / 100.0);
    }
};

class DiscountedProduct : public Product {
private:
    double discountPrice;

public:
    DiscountedProduct(const string& n, double p)
        : Product(n, p), discountPrice(p) {}

    void applyDiscount(const DiscountCalculator& calc) {
        discountPrice = calc(price);
    }

    double getPrice() const {
        return discountPrice;
    }

    double getOriginalPrice() const {
        return price;
    }
};

int main() {
    vector<DiscountedProduct> products;

    products.push_back(DiscountedProduct("Hlib", 20.0));
    products.push_back(DiscountedProduct("Maslo", 50.0));
    products.push_back(DiscountedProduct("Syr", 80.0));

    DiscountCalculator discount10(10.0);

    for (size_t i = 0; i < products.size(); ++i) {
        products[i].applyDiscount(discount10);
    }

    cout << "Tovary zi znyzhkoyu:" << endl;
    for (size_t i = 0; i < products.size(); ++i) {
        cout << products[i].getName()
             << " | Pochatkova tsena: " << products[i].getOriginalPrice()
             << " | Tsena zi znyzhkoyu: " << products[i].getPrice()
             << endl;
    }

    return 0;
}

