#pragma once
#include "Info.h"
class Service {
private:
    static int prevService;
    int ServiceId;
    string source;
    string destination;
    float distance;
    Date bookingDate;
    mTime bookingTime;
    float status; // 2 for pending, 1 if complete,3 if cancelled
    float fuelrate;
    int cId; // Customer Id who booked the ride
    int dId; // Driver Id
    int vId; // vehicle Id

public:
    // Constructor
    Service(string src, string dest, float dist, Date bDate, mTime bTime, float stat, float fr, int cid, int did, int vid);

    // Destructor
    ~Service();

    // Getters and setters

    int getprevService()const;
    void setprevService(int Sid);

    int getServiceId()const;
    void setServiceId(int Sid);

    string getSource() const;
    void setSource(string src);

    string getDestination() const;
    void setDestination(string dest);

    float getDistance() const;
    void setDistance(float dist);

    Date getBookingDate() const;
    void setBookingDate(Date bDate);

    mTime getBookingTime() const;
    void setBookingTime(mTime bTime);

    float getStatus() const;
    void setStatus(float stat);

    float getFuelRate() const;
    void setFuelRate(float fr);

    int getCustomerId() const;
    void setCustomerId(int cid);

    int getDriverId() const;
    void setDriverId(int did);

    int getVehicleId() const;
    void setVehicleId(int vid);
    //function to calculate fare
    float calculateFare() const;

    
    friend ostream& operator<<(ostream& os, const Service& service);

};

/////////////////////////////////////////////////////////////

class Ride : public Service {
private:
    int noofPassengers;
    float driverRanking;
    float vehicleRanking;
public:
    //parametric constructor
    Ride(string src, string dest, float dist, Date bDate, mTime bTime, float stat,
        float fr, int cid, int did, int vid,
        int pass, float dRank, float vRank);
    // Drstructor   
    virtual ~Ride();

    //setter and getters
    int getNoOfPassengers() const;
    void setNoOfPassengers(int pass);
    float getDriverRanking() const;
    void setDriverRanking(float dRank);
    float getVehicleRanking() const;
    void setVehicleRanking(float vRank);


};
/////////////////////////////////////////////////////

class Delivery : public Service {
private:
    float goodsWeight;
    string goodsType;

public:
    Delivery(string src, string dest, float dist, Date bDate, mTime bTime, float stat, 
        float fr, int cid, int did, int vid,
        float weight, string type);
    
    ~Delivery();
    
    //stters and getters

    float getGoodsWeight() const;
    void setGoodsWeight(float weight);

    string getGoodsType() const;
    void setGoodsType(string type);
};

////////////////////////////////////

class Vehicle {
protected:
    static int prevVcount;
    int vId;
    int registrationNo;
    float avgMileage;
    string LicenceType;
    int status;
    string fueltype;
    float overallRanking;
    Date manufacturingDate;
    Service** serviceHistory;
    int numServices;

public:
    Vehicle();
    Vehicle(int vId, int regNo, float mileage, string licenceType, int status, string fuelType,
        float overallRanking, const Date& manufacturingDate, int numFeatures);
    virtual ~Vehicle();
    
    int getprevVcount()const;
    void setprevVcount(int VID);

    int getVehicleId() const;
    void setVehicleId(int vId);

    int getRegistrationNo() const;
    void setRegistrationNo(int regNo);

    float getAverageMileage() const;
    void setAverageMileage(float mileage);

    string getLicenceType() const;
    void setLicenceType(string licenceType);

    int getStatus() const;
    void setStatus(int status);

    string getFuelType() const;
    void setFuelType(string fuelType);

    float getOverallRanking() const;
    void setOverallRanking(float ranking);

    Date getManufacturingDate() const;
    void setManufacturingDate(const Date& manufacturingDate);

    void addService(Service* service);
    Service** getServiceHistory() const;
    int getNumServices() const;
    friend ostream& operator<<(ostream& os, const Vehicle& vehicle);
};
class Bike : public Vehicle {
public:
    Bike(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Rickshaw : public Vehicle {
public:
    Rickshaw(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Car : public Vehicle {
public:
    Car(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Scooter : public Vehicle {
public:
    Scooter(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Van : public Vehicle {
public:
    Van(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Bus : public Vehicle {
public:
    Bus(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class APV : public Vehicle {
public:
    APV(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Campervan : public Vehicle {
public:
    Campervan(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Caravan : public Vehicle {
public:
    Caravan(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Shahzor : public Vehicle {
public:
    Shahzor(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class MazdaTitan : public Vehicle {
public:
    MazdaTitan(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class Truck : public Vehicle {
public:
    Truck(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class TractorTrailer : public Vehicle {
public:
    TractorTrailer(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class CarTransporter : public Vehicle {
public:
    CarTransporter(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};

class TankerTruck : public Vehicle {
public:
    TankerTruck(int vId, int regNo, float mileage, string licenceType, bool status, string fuelType,
        float overallRanking, const Date& manufacturingDate);
};