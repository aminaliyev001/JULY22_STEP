#pragma once

class Penalty {
private:
    static int _ID;
    int id;
    
    string text;
    string datetime;
    double price;
    string car_number;
    
public:
    int getId() const {
        return id;
        
    }
    string getText() const {
        return text;
        
    }
    string getDatetime() const {
        return datetime;
        
    }
    string getCarnumber() const{
        return car_number;
    }
    double getPrice() const {
        return price;
    }

    void setText(string text) {
        if(!text.empty())
        this->text = text;
        else throw invalid_argument("Text bos qala bilmez");
    }
    void setDatetime(string datetime) {
        if(datetime.length() == 10)
        this->datetime = datetime;
        else throw invalid_argument("Datetime 10 simvoldan ibaret olmalidir: 22-07-2022");
    }
    void setCarNumber(string carnumber) {
        if(!carnumber.empty())
        this->car_number = carnumber;
        else throw invalid_argument("carNumber bos qala bilmez");
    }
    void setPrice(double price) {
        if(price >= 10)
        this->price = price;
        else throw invalid_argument("Cerimenin qiymeti minimum 10 azn ola biler");
    }
    
    Penalty()  = delete;
    Penalty(string text, string datetime, double price, string car_number) {
        setText(text);
        setDatetime(datetime);
        setPrice(price);
        setCarNumber(car_number);
        id = _ID++;
    }
    void display() const {
        cout << endl << "ID: " << getId();
        cout << endl << "Text: " << getText();
        cout << endl << "Datetime: " << getDatetime();
        cout << endl << "Price: " << getPrice();
        cout << endl << "Car Number: " << getCarnumber();
    }
    friend ostream& operator<<(ostream &os, const Penalty &p) {
            os << "ID: " << p.getId();
            os << "Text: " << p.getText();
            os << "Datetime: " << p.getDatetime();
            os << "Price: " << p.getPrice();
            os << "Car Number: " << p.getCarnumber();
            return os;
        }
};
int Penalty::_ID = 1;
