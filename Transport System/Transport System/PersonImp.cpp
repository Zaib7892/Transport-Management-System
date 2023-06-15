#include "Person.h"
// Destructor
Person::~Person() {}

// Default Constructor
Person::Person() {
pName = Name();
DOB = Date();
Age = 0;
Nid = 0;
}

// Parameterized Constructor
Person::Person(Name name, Date dob, int age, int nid) : pName(name), DOB(dob), Age(age), Nid(nid) {}

// Copy Constructor
Person::Person(const Person& p) : pName(p.pName), DOB(p.DOB), Age(p.Age), Nid(p.Nid) {}

// Getter and Setter for Name
Name Person::getName() const {
return pName;
}
void Person::setName(Name name) {
pName = name;
}

// Getter and Setter for Date of Birth
Date Person::getDOB() const {
return DOB;
}
void Person::setDOB(Date dob) {
DOB = dob;
}

// Getter and Setter for Age
int Person::getAge() const {
return Age;
}
void Person::setAge(int age) {
Age = age;
}

// Getter and Setter for NID
int Person::getNid() const {
return Nid;
}
void Person::setNid(int nid) {
Nid = nid;
}

// Output operator
ostream& operator<<(ostream& os, const Person& p) {
os << "Name: " << p.pName << endl;
os << "Date of Birth: " << p.DOB << endl;
os << "Age: " << p.Age << endl;
os << "NID: " << p.Nid << endl;
return os;
}

/////////////////////Customer///////////////////////

Customer::Customer() :
	bookingHistory(nullptr),
	noOfBookings(0)
{
	bookingHistory = new Service * [100];
}

int Customer::prevCount = 0;

Customer::Customer(Name name, Date dob, int age, int nid) :
	Person(name, dob, age, nid),
	noOfBookings(0)
{
	bookingHistory = new Service * [100];
}

Customer::Customer(const Customer& other) :
	Person(other),
	noOfBookings(other.noOfBookings)
{
	cId = other.cId;
	if (other.bookingHistory != nullptr) {
		bookingHistory = new Service * [noOfBookings];
		for (int i = 0; i < noOfBookings; i++) {
			bookingHistory[i] = other.bookingHistory[i];
		}
	}
	else {
		bookingHistory = nullptr;
	}
}

Customer::~Customer() {
	delete[] bookingHistory;
}

int Customer::getprevCount() const 
{
	return prevCount;
}
void Customer::setprevCount(int prevC)
{
	prevCount=prevC;
}


int Customer::getId() const {
	return cId;
}

void Customer::setId(int cid) {
	cId = cid;
}

void Customer::addBooking(Service* booking) {
	Service** temp = new Service * [noOfBookings + 1];
	for (int i = 0; i < noOfBookings; i++) {
		temp[i] = bookingHistory[i];
	}
	temp[noOfBookings] = booking;
	delete[] bookingHistory;
	bookingHistory = temp;
	noOfBookings++;
}

int Customer::getNoOfBookings() const {
	return noOfBookings;
}

Service** Customer::getBookingHistory() const {
	return bookingHistory;
}

ostream& operator<<(ostream& os, const Customer& customer) {
	os << "Customer ID: " << customer.getId() << endl;
	os << "Name: " << customer.getName()<< endl;
	os << "Date of Birth: " << customer.getDOB()<< endl;
	os << "Age: " << customer.getAge() << endl;
	os << "National ID: " << customer.getNid() << endl;
	os << "Booking History: " << endl;
	Service** bookings = customer.getBookingHistory();
	for (int i = 0; i < customer.getNoOfBookings(); i++) {
		os << *(bookings[i]) << endl;
	}
	return os;
}


////////////////////Driver////////////////////

int Driver::prevCount = 0;

Driver::Driver() :
	licencesList(nullptr),
	noOfLicences(0),
	overallRanking(0),
	salary(0),
	experience(0),
	status(1),
	serviceHistory(nullptr),
	noOfServices(0)
{
}

Driver::Driver(Name name, Date dob, int age, int nid, float salary, int experience) :
	Person(name, dob, age, nid),
	licencesList(nullptr),
	noOfLicences(0),
	overallRanking(0),
	salary(salary),
	experience(experience),
	status(1),
	serviceHistory(nullptr),
	noOfServices(0)
{}
//Copy Constructor
Driver::Driver(const Driver& other) :
	Person(other),
	noOfLicences(other.noOfLicences),
	overallRanking(other.overallRanking),
	salary(other.salary),
	experience(other.experience),
	status(other.status),
	noOfServices(other.noOfServices)
{
	dId = other.dId;
	if (other.licencesList != nullptr) {
		licencesList = new char* [noOfLicences];
		for (int i = 0; i < noOfLicences; i++) {
			licencesList[i] = new char[strlen(other.licencesList[i]) + 1];
			strcpy_s(licencesList[i], strlen(other.licencesList[i]) + 1, other.licencesList[i]);
		}
	}
	else {
		licencesList = nullptr;
	}
	if (other.serviceHistory != nullptr) {
		serviceHistory = new Service * [noOfServices];
		for (int i = 0; i < noOfServices; i++) {
			serviceHistory[i] = other.serviceHistory[i];
		}
	}
	else {
		serviceHistory = nullptr;
	}
}

Driver::~Driver() {
	for (int i = 0; i < noOfLicences; i++) {
		delete[] licencesList[i];
	}
	delete[] licencesList;
	delete[] serviceHistory;
}


int Driver::getprevCount() const
{
	return prevCount;
}
void Driver::setprevCount(int prevC)
{
	prevCount = prevC;
}


int Driver::getId() const {
	return dId;
}

void Driver::setId(int did) {
	dId = did;
}

char** Driver::getLicencesList() const {
	return licencesList;
}

void Driver::addLicence(const char* licence) {
	char** newList = new char* [noOfLicences + 1];
	for (int i = 0; i < noOfLicences; i++) {
		newList[i] = licencesList[i];
	}
	newList[noOfLicences] = new char[strlen(licence) + 1];
	strcpy_s(newList[noOfLicences], strlen(licence) + 1, licence);
	delete[] licencesList;
	licencesList = newList;
	noOfLicences++;
}

int Driver::getNoOfLicences() const {
	return noOfLicences;
}

float Driver::getOverallRanking() const {
	return overallRanking;
}

void Driver::setOverallRanking(float ranking) {
	overallRanking = ranking;
}

float Driver::getSalary() const {
	return salary;
}

void Driver::setSalary(float salary) {
	this->salary = salary;
}

int Driver::getExperience() const {
	return experience;
}

void Driver::setExperience(int experience) {
	this->experience = experience;
}

int Driver::getStatus() const {
	return status;
}

void Driver::setStatus(int status) {
	this->status = status;
}

void Driver::addService(Service* service) {
	Service** newHistory = new Service * [noOfServices + 1];
	for (int i = 0; i < noOfServices; i++) {
		newHistory[i] = serviceHistory[i];
	}
	newHistory[noOfServices] = service;
	delete[] serviceHistory;
	serviceHistory = newHistory;
	noOfServices++;
}

int Driver::getNoOfServices() const {
	return noOfServices;
}

Service** Driver::getServiceHistory() const {
	return serviceHistory;
}

ostream& operator<<(ostream& os, const Driver& driver) {
	os << "Driver: " << driver.getName() << endl;
	os << "ID: " << driver.getId() << endl;
	os << "Licences: ";
	char** licencesList = driver.getLicencesList();
	for (int i = 0; i < driver.getNoOfLicences(); i++) {
		os << licencesList[i] << " ";
	}
	os << endl;
	os << "Overall Ranking: " << driver.getOverallRanking() << endl;
	os << "Salary: " << driver.getSalary() << endl;
	os << "Experience: " << driver.getExperience() << " years" << endl;
	os << "Service History: " << endl;
	Service** serviceHistory = driver.getServiceHistory();
	for (int i = 0; i < driver.getNoOfServices(); i++) {
		os << "  " << i + 1 << ". " << *serviceHistory[i] << endl;
	}
	return os;
}
