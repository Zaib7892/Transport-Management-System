#include <string>
#include<fstream>
#include"Info.h"
#include"Person.h"
#include"Service.h"
#include"TMS.h"
using namespace std;

const int MAX_CUSTOMERS = 15;
const int MAX_DRIVERS = 10;
const int MAX_VEHICLES = 20;
const int MAX_SERVICES = 30;


TMS::TMS() {
    customers = new Customer * [MAX_CUSTOMERS];
    numCustomers = 0;

    drivers = new Driver * [MAX_DRIVERS];
    numDrivers = 0;

    vehicles = new Vehicle * [MAX_VEHICLES];
    numVehicles = 0;

    services = new Service * [MAX_SERVICES];
    numServices = 0;
    loadData();
}

TMS ::~TMS() {
    for (int i = 0; i < numCustomers; i++)
        delete customers[i];
    delete[] customers;

    for (int i = 0; i < numDrivers; i++)
        delete drivers[i];
    delete[] drivers;

    for (int i = 0; i < numVehicles; i++)
        delete vehicles[i];
    delete[] vehicles;

    for (int i = 0; i < numServices; i++)
        delete services[i];
    delete[] services;
}

void TMS::addCustomer(const Customer& customer) {
    if (numCustomers >= MAX_CUSTOMERS) {
        Customer** temp = new Customer * [numCustomers + 1];
        for (int i = 0; i < numCustomers; i++) {
            temp[i] = customers[i];
        }

        temp[numCustomers] = new Customer(customer);
        delete[] customers;
        customers = temp;
        int prevId = customers[numCustomers]->getprevCount(); prevId++;
        customers[numCustomers]->setId(prevId);
        customers[numCustomers]->setprevCount(prevId);
        numCustomers++;
    }
    else {
        customers[numCustomers] = new Customer(customer);
        cout << "Customer added successfully." << endl;
        int prevId = customers[numCustomers]->getprevCount(); prevId++;
        customers[numCustomers]->setId(prevId);
        customers[numCustomers]->setprevCount(prevId);
        numCustomers++;
    }
}

void TMS::removeCustomer(int customerId) {
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i]->getId() == customerId) {
            delete customers[i];
            for (int j = i; j < numCustomers - 1; j++)
                customers[j] = customers[j + 1];
            numCustomers--;
            cout << "Customer removed successfully." << endl;
            return;
        }
    }
    cout << "Customer not found." << endl;
}

void TMS::addDriver(const Driver& driver) {
    if (numDrivers >= MAX_DRIVERS) {
        Driver** temp = new Driver * [numDrivers + 1];
        for (int i = 0; i < numCustomers; i++) {
            temp[i] = drivers[i];
        }

        temp[numDrivers] = new Driver(driver);
        cout << "Driver added successfully." << endl;
        delete[] drivers;
        drivers = temp;
        int prevId = drivers[numDrivers]->getprevCount(); prevId++;
        drivers[numDrivers]->setId(prevId);
        drivers[numDrivers]->setprevCount(prevId);
        numCustomers++;
        return;
    }
    else
    {
        drivers[numDrivers] = new Driver(driver);
        cout << "Driver added successfully." << endl;
        int prevId = drivers[numDrivers]->getprevCount(); prevId++;
        drivers[numDrivers]->setId(prevId);
        drivers[numDrivers]->setprevCount(prevId);
        numDrivers++;
    }
    
}

void TMS::removeDriver(int driverId) {
    for (int i = 0; i < numDrivers; i++) {
        if (drivers[i]->getId() == driverId && drivers[i]->getStatus()!=3) {
            delete drivers[i];
            for (int j = i; j < numDrivers - 1; j++)
                drivers[j] = drivers[j + 1];
            numDrivers--;
            cout << "Driver removed successfully." << endl;
            return;
        }
    }
    cout << "Driver not found OR Driver is Booked" << endl;
}

void TMS::addVehicle(const Vehicle& vehicle) {
    
    if (numVehicles >= MAX_VEHICLES) {
        Vehicle** temp = new Vehicle *[numVehicles + 1];
        for (int i = 0; i < numVehicles; i++) {
            temp[i] = vehicles[i];
        }

        temp[numVehicles] = new Vehicle(vehicle);
        cout << "Vehicle added successfully." << endl;
        delete[] drivers;
        vehicles = temp;
        int prevId = vehicles[numVehicles]->getprevVcount(); prevId++;
        vehicles[numVehicles]->setVehicleId(prevId);
        vehicles[numVehicles]->setprevVcount(prevId);
        numVehicles++;
        return;
    }
    vehicles[numVehicles] = new Vehicle(vehicle);
    cout << "Vehicle added successfully." << endl;
    int prevId = vehicles[numVehicles]->getprevVcount(); prevId++;
    vehicles[numVehicles]->setVehicleId(prevId);
    vehicles[numVehicles]->setprevVcount(prevId);
    numVehicles++;
}

void TMS::removeVehicle(int vehicleId) {
    for (int i = 0; i < numVehicles; i++) {
        if (vehicles[i]->getVehicleId() == vehicleId && !vehicles[i]->getStatus()) {
            delete vehicles[i];
            for (int j = i; j < numVehicles - 1; j++)
                vehicles[j] = vehicles[j + 1];
            numVehicles--;
            cout << "Vehicle removed successfully." << endl;
            return;
        }
    }
    cout << "Vehicle not found OR Vehicle is Booked " << endl;
}

void TMS::printAllCustomers() const {
    if (numCustomers == 0) {
        cout << "No customers found." << endl;
        return;
    }

    cout << "-----------------------" << endl;
    cout << "    All Customers" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < numCustomers; i++)
        cout << *(customers[i]) << endl;
}

void TMS::printAllDrivers() const {
    if (numDrivers == 0) {
        cout << "No drivers found." << endl;
        return;
    }

    cout << "-----------------------" << endl;
    cout << "    All Drivers" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < numDrivers; i++)
        cout << *(drivers[i]) << endl;
}

void TMS::printAllVehicles() const {
    if (numVehicles == 0) {
        cout << "No vehicles found." << endl;
        return;
    }

    cout << "-----------------------" << endl;
    cout << "    All Vehicles" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < numVehicles; i++)
        cout << *(vehicles[i]) << endl;
}

void TMS::printVehicleDetails(int vehicleId) const {
    Service** temp;
    for (int i = 0; i < numVehicles; i++) {
        if (vehicles[i]->getVehicleId() == vehicleId) {
            cout << "------Vehicle Details ------" << endl;
            cout << *(vehicles[i]) << endl;
            cout << "----- Service History ------";
            temp = vehicles[i]->getServiceHistory();
            for (int j = 0; j < vehicles[i]->getNumServices(); j++)
            {
                cout << *(temp[i]);
            }
            delete[]temp;
            return;
        }
    }
    cout << "Vehicle not found." << endl;
}

void TMS::printCustomerHistory(int customerId) const {
    cout << "----- Customer History -------" << endl;
    bool found = false;
    for (int i = 0; i < numServices; i++) {
        if (services[i]->getCustomerId() == customerId) {
            
            cout << *(services[i]);
            found = true;
        }
    }
    if (!found)
        cout << "Customer not found." << endl;
}

void TMS::printDriverHistory(int driverId) const {
    bool found = false;
    cout << "------ Driver History ---------" << endl;
    for (int i = 0; i < numServices; i++) {
        if (services[i]->getDriverId() == driverId) {  
            cout << *(services[i]);
            found = true;
        }
    }
    if (!found)
        cout << "Driver not found." << endl;
}

void TMS::printHighlyRankedDrivers() const {
    cout << "Highly Ranked Drivers (Above 4.5):" << endl;
    for (int i = 0; i < numDrivers; i++) {
        if (drivers[i]->getOverallRanking() > 4.5)
            cout << *(drivers[i]) << endl;
    }
}

void TMS::printMultiLicensedDrivers() const {
    cout << "Multi-Licensed Drivers:" << endl;
    for (int i = 0; i < numDrivers; i++) {
        if (drivers[i]->getNoOfLicences() > 1) {
            cout << "Driver: " << *(drivers[i]) << endl;
            cout << "Licences: ";
            char** licences = drivers[i]->getLicencesList();
            int numLicences = drivers[i]->getNoOfLicences();
            for (int j = 0; j < numLicences; j++)
                cout << licences[j] << " ";
            cout << endl;
        }
    }
}

void TMS::updateDriverSalary() {
    for (int i = 0; i < numDrivers; i++) {
        float ranking = drivers[i]->getOverallRanking();
        float salary = drivers[i]->getSalary();
        if (ranking > 4.5) {
            float bonus = 0.15 * salary;
            drivers[i]->setSalary(salary + bonus);
            cout << "Updated Salary of a Driver : " << drivers[i]->getName() << endl;
            cout << "Salary : " << drivers[i]->getSalary() << endl;
        }
    }
    cout << "Driver salaries updated successfully." << endl;
}

void TMS::addServiceRequest(int customerId) {

    if (numServices >= MAX_SERVICES)
    {
        Service** temp = new Service * [numServices + 1];
        for (int i = 0; i < numServices; i++) {
            temp[i] = services[i];
        }
        services = temp;
    }
    for (int i = 0; i < numCustomers; i++) {
        
        if (customers[i]->getId() == customerId) 
        {
            
            Vehicle** availableVehicles = new Vehicle * [numVehicles];
            int numAvailableVehicles = 0;
            for (int j = 0; j < numVehicles; j++) {
                if (vehicles[j]->getStatus()==1) {
                    availableVehicles[numAvailableVehicles] = vehicles[j];
                    numAvailableVehicles++;
                }
            }

            Driver** availableDrivers = new Driver * [numDrivers];
            int numAvailableDrivers = 0;
            for (int j = 0; j < numDrivers; j++) {
                if (drivers[j]->getStatus()==1) {
                    availableDrivers[numAvailableDrivers] = drivers[j];
                    numAvailableDrivers++;
                }
            }

            if (numAvailableVehicles == 0 || numAvailableDrivers == 0) {
                cout << "No available vehicles or drivers found." << endl;
                delete[] availableVehicles;
                delete[] availableDrivers;
                return;
            }

                // Let the customer choose a vehicle and driver
            int vehicleIndex, driverIndex;
            cout << "Choose a vehicle:" << endl;
            for (int j = 0; j < numAvailableVehicles; j++)
                cout << "[" << j + 1 << "] " << *(availableVehicles[j]) << endl;
            cin >> vehicleIndex;
            while (cin.fail() || vehicleIndex<1 || vehicleIndex>(numAvailableVehicles))
            {
                cout << "Choose Correct Number : ";
                cin.clear();
                cin.ignore();
                cin >> vehicleIndex;
            }
            vehicleIndex--;

            cout << "Choose a driver:" << endl;
            for (int j = 0; j < numAvailableDrivers; j++)
                cout << "[" << j + 1 << "] " << *(availableDrivers[j]) << endl;
            cin >> driverIndex;
            while (cin.fail() || driverIndex<1 || driverIndex>(numAvailableDrivers))
            {
                
                cout << "Choose Correct Number : ";
                cin.clear();
                cin.ignore();
                cin >> driverIndex;
            }
            driverIndex--;

            Vehicle* selectedVehicle = availableVehicles[vehicleIndex];
            Driver* selectedDriver = availableDrivers[driverIndex];

            delete[] availableVehicles;
            delete[] availableDrivers;
            string type, src, dst;
            float dist, fuelP;
            int d, m, y, min, hour;

            cout << "Enter Source :";
            cin.ignore();
            getline(cin,src);
            cout << "Enter Destination : ";
            getline(cin,dst);

            cout << "Enter Distance in KM : ";
            cin >> dist;
            while (cin.fail() || dist < 0)
            {
                cout << "Enter again : ";
                cin.clear();
                cin.ignore();
                cin >> dist;
            }
            cout << "Enter Fuel Price : ";
            cin >> fuelP;
            while (cin.fail() || fuelP < 0)
            {
                cout << "Enter again : ";
                cin.clear();
                cin.ignore();
                cin >> fuelP;
            }
            cout << "Enter booking date" << endl;
            do {
                
                cout << "Enter day: ";
                cin.clear();
                cin.ignore();
                cin >> d;
                cout << "Enter month: ";
                cin >> m;
                cout << "Enter year: ";
                cin >> y;
            } while (cin.fail() || d < 0 || d>31 || m < 0 || m>12 || y < 0);
            Date date(d, m, y);
            do {
                
                cout << "Enter booking time " << endl;
                cout << "Enter hour: ";
                cin.clear();
                cin.ignore();
                cin >> hour;
                cout << "Enter minute: ";
                cin >> min;
            } while (cin.fail() || min < 0 || min>60 || hour < 0 || hour >12);
            mTime time(hour, min, 30);
        t:
            cout << "Enter Service Type D(Delivery) or R(Ride): ";
            cin >> type;
                
            Service* service;
            if (type == "D" || type == "d")
            {
                float gWeight; string g_t;
                cout << "Enter Goods Type : ";
                cin >> g_t;
                cout << "Enter Goods Weight : ";
                cin >> gWeight;
                service = new Delivery(src, dst, dist, date, time, 2, fuelP, customers[i]->getId(), selectedDriver->getId(), selectedVehicle->getVehicleId(), gWeight, g_t);
            }
            else if (type == "R" || type == "r")
            {
                int n_o_p;
                cout << "Enter Number of passengers : ";
                cin >> n_o_p;
                service = new Ride(src, dst, dist, date, time, 2, fuelP, customers[i]->getId(), selectedDriver->getId(), selectedVehicle->getVehicleId(), n_o_p, selectedDriver->getOverallRanking(), selectedVehicle->getOverallRanking());
            }
            else {
                cout << "Wrong Entry Try Again " << endl;
                goto t;
            }
                
            service->setStatus(2);
            services[numServices] = service;
            int prevS = services[numServices]->getprevService(); prevS++;
            services[numServices]->setServiceId(prevS);
            services[numServices]->setprevService(prevS);
            numServices++;
            customers[i]->addBooking(service);
            selectedDriver->addService(service);
            selectedVehicle->addService(service);
            selectedDriver->setStatus(2);
            selectedVehicle->setStatus(2);
            cout << "Service request added successfully." << endl;


            return;
        }
    }
        cout << "Customer not found." << endl;
}

void TMS::cancelService(int customerId) {
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i]->getId() == customerId) {
            Service** bookings = customers[i]->getBookingHistory();
            int numBookings = customers[i]->getNoOfBookings();
            cout << "-----------------------" << endl;
            cout << "    Booking Details" << endl;
            cout << "-----------------------" << endl;
            for (int j = 0; j < numBookings; j++)
            {
                cout << *(bookings[i]);
            }
            int serviceId;
            cout << "Enter Service ID which you want to cancel : ";
            cin >> serviceId;
            for (int j = 0; j < numBookings; j++) {
                if (bookings[j]->getServiceId() == serviceId && bookings[j]->getStatus() == 2) {
                    float cancellationFee = 0.05 * bookings[j]->calculateFare();
                    bookings[j]->setStatus(3);
                    
                    for (int i = 0; i < numServices; i++)
                    {
                        if (services[i]->getServiceId() == bookings[j]->getServiceId())
                        {
                            services[i]->setStatus(3);//3 for cancelled
                        }
                    }

                    int did = bookings[j]->getDriverId();
                    for (int i = 0; i < numDrivers; i++)
                    {
                        if (drivers[i]->getId() == did)
                        {
                            drivers[i]->setStatus(3);//3 for cancelled
                        }
                    }
                    int vid = bookings[j]->getVehicleId();
                    for (int i = 0; i < numVehicles; i++)
                    {
                        if (vehicles[i]->getVehicleId() == vid)
                        {
                            vehicles[i]->setStatus(3);
                        }

                    }
                    cout << "Service canceled successfully. Cancellation fee: " << cancellationFee << endl;
                    return;
                }
            }
            cout << "Pending Service not found" << endl;
            return;
        }
    }
    cout << "Customer not found." << endl;
}

void TMS::completeService(int customerId) {

    for (int i = 0; i < numCustomers; i++) {
        if (customers[i]->getId() == customerId) {
            Service** bookings = customers[i]->getBookingHistory();
            int numBookings = customers[i]->getNoOfBookings();
            cout << "-----------------------" << endl;
            cout << "    Booking Details" << endl;
            cout << "-----------------------" << endl;
            for (int j = 0; j < numBookings; j++)
            {
                cout << *(bookings[i]);
            }
            int serviceId;
            cout << "Enter Service ID which you want to Complete : ";
            cin >> serviceId;
            for (int j = 0; j < numBookings; j++) {
                if (bookings[j]->getServiceId() == serviceId && bookings[j]->getStatus() == 2) {
                    float serviceCost = 100*bookings[j]->getDistance();
                    bookings[j]->setStatus(1);

                    for (int i = 0; i < numServices; i++)
                    {
                        if (services[i]->getServiceId() == bookings[j]->getServiceId())
                        {
                            services[i]->setStatus(1);
                        }
                    }

                    int did = bookings[j]->getDriverId();

                    for (int i = 0; i < numDrivers; i++)
                    {
                        if (drivers[i]->getId() == did)
                        {
                            drivers[i]->setStatus(1);
                        }
                    }
                    int vid = bookings[j]->getVehicleId();
                    for (int i = 0; i < numVehicles; i++)
                    {
                        if (vehicles[i]->getVehicleId() == vid)
                        {
                            vehicles[i]->setStatus(1);
                        }

                    }
                    delete bookings[j];
                    for (int k = j; k < numBookings - 1; k++)
                        bookings[k] = bookings[k + 1];
                    numServices--;
                    cout << "Service Completed successfully. Service fee: " << serviceCost << endl;
                    return;
                }
            }
            cout << "Pendibg Service not found." << endl;
            return;
        }
    }
    cout << "Customer not found." << endl;
}

void TMS::rateDriver(int did) {
    float rate;
    for (int i = 0; i < numDrivers; i++) {
        if (drivers[i]->getId() == did)
        {
            do {
                cout << "Enter Rating (0 -5 ) : ";
                cin >> rate;
            } while (rate < 0 || rate >5);
            drivers[i]->setOverallRanking(rate);
            return;
        }
    }
    cout << "Driver Not found" << endl;

}

void TMS::rateVehicle(int vid) {
    float rate;
    for (int i = 0; i < numVehicles; i++) {
        if (vehicles[i]->getVehicleId() == vid)
        {
            do {
                cout << "Enter Rating (0 -5 ) : ";
                cin >> rate;
            } while (rate < 0 || rate >5);
            vehicles[i]->setOverallRanking(rate);
            return;
        }
    }
    cout << "Vehicle Not found" << endl;
}

void TMS::printCustomersUsingVehicle(int vehicleId) const {
    cout << "Customers who used Vehicle " << vehicleId << " in a ride service:" << endl;
    for (int i = 0; i < numServices; i++) {
        if (services[i]->getVehicleId() == vehicleId)
            for (int j = 0; j < numCustomers; j++)
            {
                if (services[i]->getVehicleId() == vehicles[j]->getVehicleId())
                {
                    cout << *(vehicles[i]);
                }
            }
    }
}


void TMS::printPendingServicesByDriver(int driverId) const {
    cout << "Pending services for Driver " << driverId << ":" << endl;
    for (int i = 0; i < numServices; i++) {
        if (services[i]->getDriverId() == driverId && services[i]->getStatus() == 2)
        {
            cout << *(services[i]) << endl;
            
            return;
        }
    }
    cout << "Driver not found." << endl;
}

void TMS::printCanceledServicesByCustomer(int customerId) const {
    cout << "Cancelled services By customer " << customerId << ":" << endl;
    for (int i = 0; i < numServices; i++) {
        if (services[i]->getCustomerId() == customerId && services[i]->getStatus() == 3)
        {
            cout << *(services[i]) << endl;

            return;
        }
    }
    cout << "Customer not found." << endl;
}
void TMS::loadData()
{
    Customer cus; Vehicle v;
    int customerId, driverId, vehicleId,ServiceId;
    int serviceType;
    float rating,mil;
    string fN, lN; string lis_t, fu_t;
    Date date;
    mTime time;
    Name name;
    int d, m, y;
    int age,nid,n_o_l,sal,exp,stat,reg,dist;
    string lis,fuelT,src,dst,type;
    ifstream s_customer, s_driver, s_vehicle, s_service;

    s_customer.open("Customer.txt"); s_driver.open("Driver.txt"); s_vehicle.open("Vehicle.txt"); s_service.open("Service.txt");
    if (!s_customer.is_open() || !s_driver.is_open() || !s_vehicle.is_open() || !s_service.is_open())
    {
        cout << "Cannot Open Files" << endl;
        system("cls");
        return;
    }
    static int prev = 0;//check for duplicate values
    //loading customer data
    while (!s_customer.eof())
    {
        s_customer >> customerId;
        if (customerId == prev)
        {
            continue;
        }
        s_customer >> fN;
        name.setFirstName(fN);
        s_customer >> lN;
        name.setLastName(lN);
        cus.setName(name);
        s_customer >> d;
        date.setDay(d);
        s_customer >> m;
        date.setMonth(m);
        s_customer >> y;
        date.setYear(y);
        cus.setDOB(date);
        s_customer >> age;
        cus.setAge(age);
        s_customer >> nid;
        cus.setNid(nid);
        addCustomer(cus);
        prev = customerId;
    }
    prev = 0;
    driverId = 0;
    //loading Vehicle data
    while (!s_driver.eof())
    {
        Driver dr;
        s_driver >> driverId; 
        if (driverId == prev)
        {
            continue;
        }
        s_driver >> fN;
        name.setFirstName(fN);
        s_driver >> lN;
        name.setLastName(lN);
        dr.setName(name);
        s_driver >> n_o_l;
        for (int i = 0; i < n_o_l; i++)
        {
            s_driver >> lis;
            dr.addLicence(lis.c_str());
        }
        s_driver >> d;
        date.setDay(d);
        s_driver >> m;
        date.setMonth(m);
        s_driver >> y;
        date.setYear(y);
        dr.setDOB(date);
        
        
        s_driver >> age;
        dr.setAge(age);
        
        s_driver >> rating;
        dr.setOverallRanking(rating);
        
        s_driver >> sal;
        dr.setSalary(sal);
        
        s_driver >> exp;
        dr.setExperience(exp);
        
        s_driver >> stat;
        dr.setStatus(stat);

        s_driver >> nid;
        dr.setNid(nid);

        addDriver(dr);
        prev = driverId;
    }
    prev = 0;
    vehicleId = 0;

    while (!s_vehicle.eof())
    {
        s_vehicle >> vehicleId;
        if (vehicleId == prev)
        {
            continue;
        }
        s_vehicle >> reg;
        v.setRegistrationNo(reg);
        s_vehicle >> mil;
        v.setAverageMileage(mil);
        s_vehicle >> lis;
        v.setLicenceType(lis);
        s_vehicle >> stat;
        v.setStatus(stat);
        s_vehicle >> fuelT;
        v.setFuelType(fuelT);
        s_vehicle >> rating;
        v.setOverallRanking(rating);
        s_vehicle >> d; s_vehicle >> m; s_vehicle >> y;
        date.setDay(d); date.setMonth(m); date.setYear(y);
        v.setManufacturingDate(date);
        addVehicle(v);
        prev = vehicleId;
    }
    prev = 0;
    ServiceId = 0;
    int min, h, s, fare; float fr;
    //loading services
    while (!s_service.eof())
    {
        s_service >> ServiceId;
        if (prev == ServiceId)
            continue;
        s_service >> src;
        s_service >> dst;
        s_service >> dist;
        s_service >> d; s_service >> m; s_service >> y;
        Date dt(d, m, y);
        s_service >> h; s_service >> min; s_service >> s;
        mTime time(h, min, s);
        s_service >> stat;
        s_service >> customerId; s_service >> driverId; s_service >> vehicleId;
        s_service >> fare;
        s_service >> fr;
        Service* service = new Service(src, dst, dist, dt, time, stat, fr, customerId, driverId, vehicleId);
        services[numServices] = service;
        int prevS = services[numServices]->getprevService(); prevS++;
        services[numServices]->setServiceId(prevS);
        services[numServices]->setprevService(prevS);
        numServices++;
        prev = ServiceId;

    }
    for (int i = 0; i < numServices; i++)
    {
        //addiing service to customer's Service history
        for (int j = 0; j < numCustomers; j++)
        {
            if (customers[j]->getId() == services[i]->getCustomerId())
                customers[j]->addBooking(services[i]);
        }
        //addiing service to driver's Service history
        for (int j = 0; j < numDrivers; j++)
        {
            if (drivers[j]->getId() == services[i]->getDriverId())
                drivers[j]->addService(services[i]);
        }
        //addiing service to vehicle's Service history
        for (int j = 0; j < numVehicles; j++)
        {
            if (vehicles[j]->getVehicleId() == services[i]->getVehicleId())
                vehicles[j]->addService(services[i]);
        }
    }
    system("cls");
}
void TMS::SaveChanges() 
{
    ofstream s_customer,s_driver,s_vehicle,s_service;

    s_customer.open("Customer.txt"); s_driver.open("Driver.txt"); s_vehicle.open("Vehicle.txt"); s_service.open("Service.txt");
    if (!s_customer.is_open()|| !s_driver.is_open() || !s_vehicle.is_open() || !s_service.is_open())
    {
        cout << "Cannot Open Files" << endl;
        return;
    }
    //Saving Customers
    for (int i = 0; i < numCustomers; i++)
    {
        s_customer << customers[i]->getId() << endl;
        Name n = customers[i]->getName();
        Date dt = customers[i]->getDOB();
        s_customer << n.getFirstName() << " " << n.getLastName() << endl;
        s_customer << dt.getDay() << " " << dt.getMonth() << " " << dt.getYear() << endl;
        s_customer << customers[i]->getAge() << endl;
        s_customer << customers[i]->getNid() << endl;

    }
    
    s_customer.close();
    //saving Driver
    for (int i = 0; i < numDrivers; i++)
    {
        Name n = drivers[i]->getName();
        Date dt = drivers[i]->getDOB();
        s_driver << drivers[i]->getId() << endl;
        s_driver << n.getFirstName() << " " << n.getLastName() << endl;
        s_driver ;
        char** licencesList = drivers[i]->getLicencesList();
        int n_o_l = drivers[i]->getNoOfLicences();
        s_driver << n_o_l<<endl;
        for (int i = 0; i < n_o_l; i++) {
            s_driver << licencesList[i] << " ";
        }
        s_driver << endl;
        s_driver << dt.getDay() << " " << dt.getMonth() << " " << dt.getYear() << endl;
        s_driver << drivers[i]->getAge() << endl;
        s_driver << drivers[i]->getOverallRanking() << endl;
        s_driver << drivers[i]->getSalary() << endl;
        s_driver << drivers[i]->getExperience() << endl;
        s_driver << drivers[i]->getStatus() << endl;
        s_driver << drivers[i]->getNid() << endl;
    }
    //saving Vehicle

    for (int i = 0; i < numVehicles; i++)
    {
        s_vehicle << vehicles[i]->getVehicleId() << endl;
        s_vehicle << vehicles[i]->getRegistrationNo() << endl;
        s_vehicle << vehicles[i]->getAverageMileage() << endl;
        s_vehicle << vehicles[i]->getLicenceType() << endl;
        s_vehicle << vehicles[i]->getStatus() << endl;
        s_vehicle << vehicles[i]->getFuelType() << endl;
        s_vehicle << vehicles[i]->getOverallRanking() << endl;
        Date dt = vehicles[i]->getManufacturingDate();
        s_vehicle << dt.getDay() << " " << dt.getMonth() << " " << dt.getYear() << endl;
        
    }

    //saving Services

    for (int i = 0; i < numServices; i++)
    {
        s_service << services[i]->getServiceId() << endl;
        s_service << services[i]->getSource() << endl;
        s_service << services[i]->getDestination() << endl;
        s_service << services[i]->getDistance() << endl;
        Date dt = services[i]->getBookingDate();
        s_service << dt.getDay() << " " << dt.getMonth() << " " << dt.getYear() << endl;
        mTime t = services[i]->getBookingTime();
        s_service << t.getHour() << " " << t.getMin() << " " << t.getSec() << endl;
        s_service << services[i]->getStatus() << endl;
        s_service << services[i]->getCustomerId() << endl;
        s_service << services[i]->getDriverId() << endl;
        s_service << services[i]->getVehicleId() << endl;
        s_service << services[i]->calculateFare() << endl;
        s_service << services[i]->getFuelRate() << endl;
    }
}
