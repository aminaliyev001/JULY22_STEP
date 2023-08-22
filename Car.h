#pragma once

class Car{
private:
    static int _ID;
    int id;
    string car_number;
    vector<Penalty*> cerimeler;
public:
    
    int getId() const { return id; }
    string getCarNumber() const { return car_number; }
    vector<Penalty*> getCerimeler() const { return cerimeler; }
    
    void displayCerimeler() const {
        if(cerimeler.size()>0){
            for(auto item:cerimeler){
                item->display();
            }
        } else cout << "BOSDUR";
    }
    void setCarNumber(string car_number) {
        if(car_number.length() == 7)
        this->car_number = car_number;
        else throw invalid_argument("Avtombil nomresi 7 simvoldan ibaret olmalidir: 10XX100");
    }
    void addPenalty(Penalty* penalty) {
        cerimeler.push_back(penalty);
    }
    Car() = delete;
    Car(string car_number) {
        setCarNumber(car_number);
        id = _ID++;
    }
    ~Car() {
            for (Penalty* penalty : cerimeler) {
                delete penalty;
            }
            cerimeler.clear();
        }
};
int Car::_ID = 0;
