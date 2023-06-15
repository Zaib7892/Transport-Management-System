#include "Service.h"

#include <cstring>

// Constructor
Service::Service(string src, string dest, float dist, Date bDate, mTime bTime, float stat, float fr, int cid, int did, int vid):
    distance(dist), bookingDate(bDate), bookingTime(bTime), status(stat),
    fuelrate(fr), cId(cid), dId(did), vId(vid)
{
    source = src;
    destination = dest;
    ServiceId++;
}

// Destructor
Service::~Service() {

}
int Service::prevService = 0;

int Service::getprevService()const
{
    return prevService;
}
void Service::setprevService(int Sid)
{
    prevService = Sid;
}


// Getters and setters
void Service::setServiceId(int Sid)
{
    ServiceId = Sid;
}
int Service::getServiceId()const {
    return ServiceId;
}
string Service::getSource() const {
    return source;
}
void Service::setSource(string src) {
    source = src;
}

string Service::getDestination() const {
    return destination;
}
void Service::setDestination(string dest) {
    destination = dest;
}

float Service::getDistance() const {
    return distance;
}
void Service::setDistance(float dist) {
    distance = dist;
}

Date Service::getBookingDate() const {
    return bookingDate;
}
void Service::setBookingDate(Date bDate) {
    bookingDate = bDate;
}

mTime Service::getBookingTime() const {
    return bookingTime;
}
void Service::setBookingTime(mTime bTime) {
    bookingTime = bTime;
}

float Service::getStatus() const {
    return status;
}
void Service::setStatus(float stat) {
    status = stat;
}

float Service::getFuelRate() const {
    return fuelrate;
}
void Service::setFuelRate(float fr) {
    fuelrate = fr;
}

int Service::getCustomerId() const {
    return cId;
}
void Service::setCustomerId(int cid) {
    cId = cid;
}

int Service::getDriverId() const {
    return dId;
}
void Service::setDriverId(int did) {
    dId = did;
}

int Service::getVehicleId() const {
    return vId;
}
void Service::setVehicleId(int vid) {
    vId = vid;
}

// Other member functions
float Service::calculateFare() const {
    return distance * fuelrate;
}

ostream& operator<<(ostream& os, const Service& service) {
    os << "Service Details: " << endl;
    os << "Service ID : " << service.ServiceId << endl;
    os << "Source: " << service.source << endl;
    os << "Destination: " << service.destination << endl;
    os << "Distance: " << service.distance << " km" << endl;
    os << "Booking Date: " << service.bookingDate << endl;
    os << "Booking Time: " << service.bookingTime << endl;
    os << "Service Status: ";
    if (service.status == 1)
        os << "Completed" << endl;
    else if (service.status == 2)
        os << "Not completed" << endl;
    else if (service.status == 3)
        os << "Cancelled" << endl;
    os << "Customer ID: " << service.cId << endl;
    os << "Driver ID: " << service.dId << endl;
    os << "Vehicle ID: " << service.vId << endl;
    os << "Fare: " << service.calculateFare() << endl;
    return os;
}

//////////////////////Ride Implementation////////////////////////////


Ride::Ride(string src, string dest, float dist, Date bDate, mTime bTime, float stat,
    float fr, int cid, int did, int vid,
    int pass,float dRank, float vRank) : //constructor chaining
    Service(src, dest, dist, bDate, bTime, stat, fr, cid, did, vid),
    noofPassengers(pass), driverRanking(dRank), vehicleRanking(vRank)
{
}

Ride::~Ride() {
   
}

int Ride::getNoOfPassengers() const {
    return noofPassengers;
}
void Ride::setNoOfPassengers(int pass) {
    noofPassengers = pass;
}

float Ride::getDriverRanking() const {
    return driverRanking;
}
void Ride::setDriverRanking(float dRank) {
    driverRanking = dRank;
}

float Ride::getVehicleRanking() const {
    return vehicleRanking;
}
void Ride::setVehicleRanking(float vRank) {
    vehicleRanking = vRank;
}

/////////////////////////////Delivery Implementation//////////////////////

Delivery::Delivery(string src, string dest, float dist, Date bDate, mTime bTime, float stat, float fr, int cid, int did, int vid,
    float weight, string type) : //Constructor chaining
    Service(src, dest, dist, bDate, bTime, stat, fr, cid, did, vid),
    goodsWeight(weight)
{
    goodsType =  type;
}

Delivery::~Delivery() {

}

float Delivery::getGoodsWeight() const {
    return goodsWeight;
}
void Delivery::setGoodsWeight(float weight) {
    goodsWeight = weight;
}

string Delivery::getGoodsType() const {
    return goodsType;
}
void Delivery::setGoodsType(string type) {
    goodsType = type;
}

//////////////////////Vehicle Implementation//////////////////////////////////
Vehicle::Vehicle() {
    vId = 0;
    registrationNo = 0;
    avgMileage = 0.0;
    LicenceType = "";
    status = 1;
    fueltype = "";
    overallRanking = 0.0f;
    manufacturingDate = Date();
    serviceHistory = new Service * [100]; // Assuming maximum 100 services
    numServices = 0;
}

Vehicle::Vehicle(int vId, int regNo, float mileage, string licenceType, int status, string fuelType,
    float overallRanking, const Date& manufacturingDate, int numFeatures)
    : vId(vId), registrationNo(regNo), avgMileage(mileage), status(status), overallRanking(overallRanking),
    manufacturingDate(manufacturingDate), numServices(0) {
    LicenceType = licenceType;

    this->fueltype = fuelType;


    
}

Vehicle::~Vehicle() {
    if (numServices == 0)
        return;
    delete[] serviceHistory;
}

int Vehicle::prevVcount = 0;

int Vehicle::getprevVcount()const
{
    return prevVcount;
}
void Vehicle::setprevVcount(int VID)
{
    prevVcount = VID;
}

int Vehicle::getVehicleId() const {
    return vId;
}

void Vehicle::setVehicleId(int vId) {
    this->vId = vId;
}

int Vehicle::getRegistrationNo() const {
    return registrationNo;
}

void Vehicle::setRegistrationNo(int regNo) {
    registrationNo = regNo;
}

float Vehicle::getAverageMileage() const {
    return avgMileage;
}

void Vehicle::setAverageMileage(float mileage) {
    avgMileage = mileage;
}

string Vehicle::getLicenceType() const {
    return LicenceType;
}

void Vehicle::setLicenceType(string licenceType) {
    LicenceType = licenceType;
}

int Vehicle::getStatus() const {
    return status;
}

void Vehicle::setStatus(int status) {
    this->status = status;
}

string Vehicle::getFuelType() const {
    return fueltype;
}

void Vehicle::setFuelType(string fuelType) {
    fueltype = fuelType;
}

float Vehicle::getOverallRanking() const {
    return overallRanking;
}

void Vehicle::setOverallRanking(float ranking) {
    overallRanking = ranking;
}

Date Vehicle::getManufacturingDate() const {
    return manufacturingDate;
}

void Vehicle::setManufacturingDate(const Date& manufacturingDate) {
    this->manufacturingDate = manufacturingDate;
}


void Vehicle::addService(Service* service) {
    Service** newHistory = new Service * [numServices + 1];
    for (int i = 0; i < numServices; i++) {
        newHistory[i] = serviceHistory[i];
    }
    newHistory[numServices] = service;
    delete[] serviceHistory;
    serviceHistory = newHistory;
    numServices++;
}

Service** Vehicle::getServiceHistory() const {
    return serviceHistory;
}

int Vehicle::getNumServices() const {
    return numServices;
}


ostream& operator<<(ostream& os, const Vehicle& vehicle)
{
    os << "Vehicle ID: " << vehicle.getVehicleId() << endl;
    os << "Registration No: " << vehicle.getRegistrationNo() << endl;
    os << "Average Mileage: " << vehicle.getAverageMileage() << endl;
    os << "License Type: " << vehicle.getLicenceType() << endl;
    os << "Status: " ;
    if (vehicle.getStatus() == 1) {
        os<<"Free" << endl;
    }
    else if (vehicle.getStatus() == 2) {
        os<< "Booked" << endl;
    }
    else if (vehicle.getStatus() == 3) {
        os << "Cancelled" << endl;
    }
    os << "Fuel Type: " << vehicle.getFuelType() << endl;
    os << "Overall Ranking: " << vehicle.getOverallRanking() << endl;
    os << "Manufacturing Date: " << vehicle.getManufacturingDate() << endl;


    return os;
}