#include"Info.h"
#include"Person.h"
#include"Service.h"
#include"TMS.h"
#include<string>


using namespace std;
int isValidAge()
{
    int age;
    cout << "Enter Age : ";
    cin >> age;
    while (cin.fail() || age < 12 || age > 120 )
    {
        cout << "Wrong Input Enter again " << endl;
        cin.clear();
        cin.ignore();
        cin >> age;
    }
    return age;
}
bool isDateValid(int day, int month, int year)
{
    if (year < 1900 || year > 9999)
    {
        cout << "Enter Valid Data" << endl;
        return false;
    }

    if (month < 1 || month > 12) {
        cout << "Enter Valid Data" << endl;
        return false;
    }
    int maxDays = 31;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDays = 30;
    else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            maxDays = 29;
        else
            maxDays = 28;
    }

    if (day < 1 || day > maxDays)
    {
        cout << "Enter Valid Data" << endl;
        return false;
    }

    return true;

}

bool isValidTime(int hours, int minutes, int seconds) {
    if (hours < 0 || hours > 23) {
        cout << "Enter Valid Data" << endl;
        return false;
    }

    else if (minutes < 0 || minutes > 59) {
        cout << "Enter Valid Data" << endl;
        return false;
    }
    else if (seconds < 0 || seconds > 59) {
        cout << "Enter Valid Data" << endl;
        return false;
    }
    return true;
}
bool isValidName(const string& firstName, const string& secondName) {
    for (char c : firstName) {
        if (!isalpha(c)) {
            cout << "Enter Valid Data" << endl;
            return false;
        }
    }

    for (char c : secondName) {
        if (!isalpha(c)) {
            cout << "Enter Valid Data" << endl;
            return false;
        }
    }

    return true;
}

////////////////////////////////Driver Programm/////////////////////////////////
int main() {
    TMS tms;
    Customer cus; Driver dr; Vehicle v;
    int choice;
    int customerId, driverId, vehicleId;
    int serviceType;
    float rating;
    string fN, lN; string lis_t, fu_t;
    Date date;
    mTime time;
    Name name;
    int d, m, y;
    int age;
    while (true) {
    MAIN:
        system("pause");
        system("cls");
        cout << "-------------------------------------------------" << endl;
        cout << "**********| Transport Management System |********" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1) Add a new Customer" << endl;
        cout << "2) Add or remove a Driver" << endl;
        cout << "3) Add or remove a Vehicle" << endl;
        cout << "4) Print List of All Customers" << endl;
        cout << "5) Print List of All Drivers" << endl;
        cout << "6) Print List of All Vehicles" << endl;
        cout << "7) Print complete details and service history of a particular vehicle" << endl;
        cout << "8) Print complete history of a particular customer" << endl;
        cout << "9) Print complete history of a driver including services" << endl;
        cout << "10) Print list of all drivers who have ranking above 4.5" << endl;
        cout << "11) Print list of all drivers who have multiple licenses and their license information too" << endl;
        cout << "12) Print updated salary of all drivers based on their updated ranking" << endl;
        cout << "13) Add a Service request (ride or delivery) for a customer" << endl;
        cout << "14) Cancel a booking" << endl;
        cout << "15) Complete a service" << endl;
        cout << "16) Rate a driver" << endl;
        cout << "17) Rate a vehicle" << endl;
        cout << "18) Print details of all pending services of a particular driver" << endl;
        cout << "19) Print details of all canceled services by a customer" << endl;
        cout << "20) Save Changes" << endl;
        cout << "0) Exit" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        try
        {
            cin >> choice;
            if (cin.fail())
            {
                throw 1;
            }
        }
        catch (int a)
        {
            cout << "Wrong Input Enter again " << endl;
            cin.clear();
            cin.ignore();
            system("pause");
            goto MAIN;
        }

        switch (choice) {
        case 0:
            std::cout << "Exiting the program..." << std::endl;
            return 0;
        case 1:
            do {
                cin.ignore();
                cout << "Enter First Name : ";
                getline(cin, fN);
                cout << "Enter Last Name : ";
                getline(cin, lN);
            } while (!isValidName(fN, lN));
            name.setFirstName(fN);
            name.setLastName(lN);
            do {
                cout << "------ Date Of Birth--------" << endl;
                cout << "Enter Day : ";
                cin >> d;
                cout << "Enter Month : ";
                cin >> m;
                cout << "Enter Year : ";
                cin >> y;
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Enter Day : ";
                    cin >> d;
                    cout << "Enter Month : ";
                    cin >> m;
                    cout << "Enter Year : ";
                    cin >> y;
                }
            } while (!isDateValid(d, m, y));
            age = isValidAge();
            date.setDay(d); date.setMonth(m); date.setYear(y);
            /*cout << "Enter Customer ID : ";
            cin >> customerId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again " << endl;
                cin.clear();
                cin.ignore();
                cin>> customerId;
            }*/
            cus.setName(name); cus.setDOB(date); cus.setAge(age); //cus.setId(customerId);
            ;
            tms.addCustomer(cus);
            break;
        case 2:
            int ch;
            cout << "Want to Add or Remove Driver? \n Press 1 to Add \n Press 2 to Remove \n Enter choice : ";
            cin >> ch;
            while (cin.fail() || ch < 0 || ch>2)
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> ch;
            }
            if (ch == 1)
            {
                do {
                    cin.ignore();
                    cout << "Enter First Name : ";
                    getline(cin, fN);
                    cout << "Enter Last Name : ";
                    getline(cin, lN);
                } while (!isValidName(fN, lN));
                name.setFirstName(fN);
                name.setLastName(lN);
                do {
                    cout << "------ Date Of Birth--------" << endl;
                    cout << "Enter Day : ";
                    cin >> d;
                    cout << "Enter Month : ";
                    cin >> m;
                    cout << "Enter Year : ";
                    cin >> y;
                    while (cin.fail())
                    {

                        cout << "Please Enter valid data" << endl;
                        cin.clear();
                        cin.ignore();
                        cout << "Enter Day : ";
                        cin >> d;
                        cout << "Enter Month : ";
                        cin >> m;
                        cout << "Enter Year : ";
                        cin >> y;
                    }
                } while (!isDateValid(d, m, y));
                age = isValidAge();
                date.setDay(d); date.setMonth(m); date.setYear(y);
                dr.setName(name); dr.setDOB(date); dr.setAge(age);
                dr.addLicence("LTV"); dr.addLicence("PSV"); dr.setStatus(1);
                int sal, exp;
                cout << "Enter Salary( Rs ) : ";
                cin >> sal;
                while (cin.fail() || sal < 1000)
                {
                    cout << "Wrong Input Enter again : " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> sal;
                }
                dr.setSalary(sal);
                cout << "Enter Ecperience (1 - 10)";
                cin >> exp;
                while (cin.fail() ||exp<1||exp>10)
                {
                    cout << "Wrong Input Enter again : " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> exp;
                }
                dr.setExperience(exp);
                tms.addDriver(dr);
            }
            else
            {
                tms.printAllDrivers();
                cout << "Enter Driver ID to Remove : ";
                cin >> driverId;
                while (cin.fail())
                {
                    cout << "Wrong Input Enter again : " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> driverId;
                }
                tms.removeDriver(driverId);

            }
            break;
        case 3:
            int ch1; float mileage,ranking;
            
            cout << "Want to Add or Remove Vehicle? \n Press 1 to Add \n Press 2 to Remove \n Enter choice : ";
            cin >> ch1;
            while (cin.fail() || ch1 < 0 || ch1>2)
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> ch1;
            }
            if (ch1 == 1)
            {
                int reg;
                cout << "Enter Vehicle Registeration Number : ";
                cin >> reg;
                while (cin.fail())
                {
                    cout << "Wrong Input Enter again : " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> reg;
                }
                v.setRegistrationNo(reg);

                cout << "Enter Mileage : ";
                cin >> mileage;
                while (cin.fail())
                {
                    cout << "Wrong Input Enter again : " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> mileage;
                }
                v.setAverageMileage(mileage);

                cout << "Enter Overall Ranking : ";
                cin >> ranking;
                while (cin.fail())
                {
                    cout << "Wrong Input Enter again : " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> ranking;
                }
                v.setOverallRanking(ranking);
                do {
                    
                    cout << "Enter fuel type : ";
                    cin.ignore();
                    getline(cin, fu_t);
                    cout << "Enter liscence Type: ";
                    getline(cin, lis_t);
                } while (!isValidName(fu_t, lis_t));
                v.setFuelType(fu_t);
                v.setLicenceType(lis_t);
                v.setStatus(1);
                tms.addVehicle(v);
            }
            else
            {
                tms.printAllVehicles();
                cout << "Enter Vehicle ID to Remove : ";
                cin >> vehicleId;
                while (cin.fail())
                {
                    cout << "Wrong Input Enter again : " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> vehicleId;
                }
                tms.removeVehicle(vehicleId);

            }
            break;
        case 4:
            tms.printAllCustomers();
            break;
        case 5:
            tms.printAllDrivers();
            break;
        case 6:
            tms.printAllVehicles();
            break;
        case 7:
            cout << "Enter Vehicle ID to See All details and Services : ";
            cin >> vehicleId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> vehicleId;
            }
            tms.printVehicleDetails(vehicleId);
            break;
        case 8:
            tms.printAllCustomers();
            cout << "Enter Customer ID to See Service History : ";
            cin >> customerId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> customerId;
            }
            tms.printCustomerHistory(customerId);
            break;
        case 9:
            tms.printAllDrivers();
            cout << "Enter Driver ID to See Service History : ";
            cin >> driverId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> driverId;
            }
            tms.printDriverHistory(driverId);
            break;
        case 10:
            tms.printHighlyRankedDrivers();
            break;
        case 11:
            tms.printMultiLicensedDrivers();
            break;
        case 12:
            tms.updateDriverSalary();
            break;
        case 13:
            tms.printAllCustomers();
            cout << "Enter Customer ID to Add Service : ";
            cin >> customerId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> customerId;
            }
            tms.addServiceRequest(customerId);
            break;
        case 14:
            tms.printAllCustomers();
            cout << "Enter Customer ID to Cancel Service : ";
            cin >> customerId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> customerId;
            }
            tms.cancelService(customerId);
            break;
        case 15:
            tms.printAllCustomers();
            cout << "Enter Customer ID to Complete Service : ";
            cin >> customerId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> customerId;
            }
            tms.completeService(customerId);
            break;
        case 16:
            tms.printAllDrivers();
            cout << "Enter Driver ID to Rate : ";
            cin >> driverId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> driverId;
            }
            tms.rateDriver(driverId);
            break;
        case 17:
            tms.printAllVehicles();
            
            cout << "Enter Vehicle ID to Rate : ";
            cin >> vehicleId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> vehicleId;
            }
            tms.rateVehicle(vehicleId);
            break;
        case 18:
            tms.printAllDrivers();
            cout << "Enter Driver ID to See Pending Services : ";
            cin >> driverId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> driverId;
            }
            tms.printPendingServicesByDriver(driverId);
            break;
        case 19:
            tms.printAllCustomers();
            cout << "Enter Customer ID to see pending Services : ";
            cin >> customerId;
            while (cin.fail())
            {
                cout << "Wrong Input Enter again : " << endl;
                cin.clear();
                cin.ignore();
                cin >> customerId;
            }
            tms.printCanceledServicesByCustomer(customerId);
            break;
        case 20:
            tms.SaveChanges();
            cout << "Changes Saved to the file" << endl;
            break;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
    }

    return 0;
}