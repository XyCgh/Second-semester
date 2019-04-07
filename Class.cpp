#include "pch.h"
#include <iostream>
#include <string>;
using namespace std;


class Hero final
{

public:
	string name;
	int age;

	Hero(string n, int a)
	{
		name = n;
		age = a;
	}

	Hero(const Hero &hero)
	{
		cout <<"Copy constructor";
	}

	Hero(string n)
	{
		this->name = n; 
		this->age = 18;
	}

	void showParametrs()
	{
		std::cout << "Name: " << this->name << "\t Age: " << this->age << endl;
	}

	Hero()
	{
		name = "Bob";
		age = 18;
	}

	~Hero()
	{
		cout << "Destructor called for Hero " << name << endl;
	}

	void move()
	{
		cout << name << " is moving" << endl;
	}

};

class Monster
{
	friend void monster(Monster &);
	friend void setDamage(Monster &, int damage);
public:
	Monster(string monsterName, int monsterDamage)
	{
		name = monsterName;
		damage = monsterDamage;
	}
	string getName() { return name; }
	int getDamage() { return damage; }

private:
	string name;   
	int damage; 
};

void monster(Monster &a)
{
	cout << a.name << " Deals " << endl;
}
void setDamage(Monster &a, int damage)
{
	if (damage > 0)
		a.damage = damage;
};


class Counter
{
public:
	Counter(int sec)
	{
		seconds = sec;
	}
	void display()
	{
		std::cout <<"in "<< seconds << " seconds" << std::endl;
	}
	int seconds;
};

Counter operator + (Counter c1, Counter c2)
{
	return Counter(c1.seconds + c2.seconds);
};


class Mane_Hero
{
public:
	string name;
	int level;

	Mane_Hero(string n, int a) 
	{
		name = n;
		level = a;
	}
	void display()
	{
		cout << "Name: " << name << "\tLevel: " << level << endl;
	}

};

class Pet : public Mane_Hero
{
public:

	Pet(string n, int a, string m):Mane_Hero(n, a)
	{
		skills = m;
	}
	void display()
	{
		cout << "Name: " << name << "\tLevel: " << level << "\tSkills: " << skills << endl;
	}
private:
	string skills;
};


int main(int arge, const char * argv[])
{
	Hero tom("Tom", 22);
	cout << "Name: " << tom.name << "\tAge: " << tom.age << endl;
	Hero sam("Sam");
	cout << "Name: " << sam.name << "\tAge: " << sam.age << endl;
	Hero bob = Hero();
	cout << "Name: " << bob.name << "\tAge: " << bob.age << endl;
	Hero hCopy;

	Monster ogr("Ogr", 5000);
	monster(ogr);
	std::cout << ogr.getName() << " : " << ogr.getDamage() << endl;
	setDamage(ogr, 8000);
	std::cout << ogr.getName() << " : " << ogr.getDamage() << endl;

	Counter c1(10);
	Counter c2(10);
	Counter c3 = c1 + c2;
	c3.display();

	Mane_Hero rey("Rayn", 10);
	rey.display();
	class Pet leen("Leen", 10, "Attack Bonus");
	leen.display();

	return 0;
}