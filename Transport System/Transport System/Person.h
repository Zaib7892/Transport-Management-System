#pragma once
#include"Info.h"
#include"Service.h"
class Person {
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;

public:
	// Constructors
	Person();
	Person(Name name, Date dob,int age, int nid);
	Person(const Person& other);
	// Destructor
	~Person();

	// Getter and setter functions
	Name getName() const;
	void setName(Name name);

	Date getDOB() const;
	void setDOB(Date dob);

	int getAge() const;
	void setAge(int age);

	int getNid() const;
	void setNid(int nid);

	// Output operator overload
	friend ostream& operator<<(ostream& os, const Person& person);
};

///////////////////////////////////////////

class Customer : public Person {
private:
	static int prevCount;
	int cId;
	Service** bookingHistory;
	int noOfBookings;
public:
	Customer();
	Customer(Name name, Date dob,int age, int nid);
	Customer(const Customer& other);
	~Customer();

	//setters and getters
	int getprevCount() const;
	void setprevCount(int prevC);

	int getId() const;
	void setId(int cid);

	void addBooking(Service* booking);

	int getNoOfBookings() const;
	Service** getBookingHistory() const;

	friend ostream& operator<<(ostream& os, const Customer& customer);
};

////////////////////////////////////////////////////////////

class Driver : public Person {
private:
	static int prevCount;
	int dId;
	char** licencesList;
	int noOfLicences;
	float overallRanking;
	float salary;
	int experience;
	int status;// 1 for free, 2 if booked and 3 if canceled
	Service** serviceHistory;
	int noOfServices;
public:
	//constructors
	Driver();
	Driver(Name name, Date dob, int age, int nid, float salary, int experience);
	Driver(const Driver& other);

	//Destructor
	~Driver();

	//setter and getter
	int getprevCount() const;
	void setprevCount(int prevC);

	int getId() const;
	void setId(int did);
	char** getLicencesList() const;
	void addLicence(const char* licence);
	int getNoOfLicences() const;
	float getOverallRanking() const;
	void setOverallRanking(float ranking);
	float getSalary() const;
	void setSalary(float salary);
	int getExperience() const;
	void setExperience(int experience);
	int getStatus() const;
	void setStatus(int status);
	void addService(Service* service);
	int getNoOfServices() const;
	Service** getServiceHistory() const;


	friend ostream& operator<<(ostream& os, const Driver& driver);
};
