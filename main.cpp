#include <iostream>
#include <string>
#include<fstream>
#include<exception>
#include<vector>
using namespace std;

#include "Penalty.h"
#include "Car.h"

int main() {
    Car* masin1;
    try {
        masin1 = new Car("10AZ509");
    }
    catch(exception &e) {
        cout << e.what();
    }
    masin1->addPenalty(new Penalty("Birtərəfli hərəkət yollarında müəyyən edilmiş hərəkət istiqamətinin əksinə hərəkət etmə","22-07-2023",100,"10AZ509"));
    masin1->addPenalty(new Penalty("Sürücü tərəfindən piyadaya yol verilməməsinə","21-07-2023",50,"10AZ509"));
    
    masin1->displayCerimeler();
    
    
    Car* masin2;
    try {
        masin2 = new Car("10GY204");
    }
    catch(exception &e) {
        cout << e.what();
    }
    masin1->addPenalty(new Penalty("Yol nişanlarının və ya yolların hərəkət hissəsinin işarələrinin tələblərinə riayət edilməməsi","04-06-2023",40,"10GY204"));
    
    masin1->addPenalty(new Penalty("Giriş qadağandır yol nişanının tələbinin pozulması","06-02-2023",60,"10GY204"));
    
    masin1->displayCerimeler();
    
    
    return 0;
}
