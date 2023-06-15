
#include"Person.h"
#include"Info.h"
#include "Service.h"

class TMS {
private:
    Customer** customers;
    int numCustomers;
    Driver** drivers;
    int numDrivers;
    Vehicle** vehicles;
    int numVehicles;
    Service** services;
    int numServices;

public:
    TMS();
    ~TMS();

    void addCustomer(const Customer& customer);
    void removeCustomer(int customerId);

    void addDriver(const Driver& driver);
    void removeDriver(int driverId);

    void addVehicle(const Vehicle& vehicle);
    void removeVehicle(int vehicleId);

    void printAllCustomers() const;
    void printAllDrivers() const;
    void printAllVehicles() const;

    void printVehicleDetails(int vehicleId) const;
    void printCustomerHistory(int customerId) const;
    void printDriverHistory(int driverId) const;

    void printHighlyRankedDrivers() const;
    void printMultiLicensedDrivers() const;

    void updateDriverSalary();

    void addServiceRequest(int customerId);
    void cancelService(int customerId);

    void completeService(int customerId);
    void rateDriver(int did);
    void rateVehicle(int vid);

    void printCustomersUsingVehicle(int vehicleId) const;
    void printPendingServicesByDriver(int driverId) const;

    void printCanceledServicesByCustomer(int customerId) const;

    void loadData();
    void SaveChanges();
};
