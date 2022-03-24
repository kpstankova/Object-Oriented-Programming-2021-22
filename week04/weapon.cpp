#include <iostream>
#include <cstring>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

class Weapon
{
private:
    char name[20];
    int power;
    int durability;
public:
    void setName(const char* name)
    {
        strcpy(this->name,name);
    }
    void setPower(int power)
    {
        this->power = power;
    }
    void setDurability(int durability)
    {
        this->durability = durability;
    }

    const char* getName() const
    {
        return this->name;
    }

    int getPower() const
    {
        return this->power;
    }

    int getDurability() const
    {
        return this->durability;
    }

    Weapon()
    {
        setName(" ");
        setPower(0);
        setDurability(0);
    }

    Weapon(const char* name, int power, int durability)
    {
        setName(name);
        setPower(power);
        setDurability(durability);
    }

    void useWeapon() const
    {
        cout << "Boom" << endl;
    }

    void printWeapon()
    {
        cout << "\nWeapon name: " << name
            << "\nPower: " << power
            << "\nDurability: " << durability << endl;
    }  
};

class Fighter
{
private:
    char name[16];
    int strenght;
    int health;
    Weapon weapon;

public:
    void setName(const char* name)
    {
        strcpy(this->name,name);
    }
    void setStrenght(int strenght)
    {
        this->strenght = strenght;
    }
    void setHealth(int health)
    {
        this->health = health;
    }
    void setWeapon(Weapon weapon)
    {
        this->weapon = weapon;
    }

    const char* getName()const
    {
        return this->name;
    }

    int getStrenght()const
    {
        return this->strenght;
    }

    int getHealth()const
    {
        return this->health;
    }

    const Weapon& getWeapon() const
    {
        return this->weapon;
    }

    Fighter()
    {
        setName(" ");
        setStrenght(0);
        setHealth(100);
        setWeapon(Weapon());
    }

    Fighter(const char* name, int strenght, int health, Weapon weapon)
    {
        setName(name);
        setStrenght(strenght);
        setHealth(health);
        setWeapon(weapon);
    }

    bool isAlive()
    {
        return this->health;
    }

    void attack(Fighter& other)
    {
        other.health -= 20;
    }


};

int main()
{

}