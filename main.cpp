#include <iostream>

class phoneNumber
{
private:
    std::string name;
    std::string number
    int qty=0;
public:
    phoneNumber(std::string name, std::string number)
    {
        this->name=name;
        pNums[0]=new int[10];
        for(int i=0;i<10;i++)
        {
            *(pNums[0]+i)=number[i];
        }
        qty++;
    }

    void addNumber(int number[10])
    {
        pNums[qty]=new int[10];
        for(int i=0;i<10;i++)
        {
            *(pNums[qty]+i)=number[i];
        }
        qty++;
    }

    void showName()
    {
        std::cout << name;
    }

    int getQty()
    {
        return qty;
    }

    int* getNumber(int n)
    {
        return pNums[n];
    }
};

class phone
{
private:
    phoneNumber contacts;
public:

};

int main()
{
    phoneNumber Jeka("Jeka", 9213055969);
    Jeka.addNumber(9112848784);

    std::cout << Jeka.getQty() << " " << Jeka.getNumber(0) << Jeka.getNumber(1);
}
