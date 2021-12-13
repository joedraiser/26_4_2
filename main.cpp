#include <iostream>
#include <vector>

class phoneNumber
{
private:
    std::string name;
    std::string number;
public:
    phoneNumber()
    {
    }

    phoneNumber(std::string name, std::string number)
    {
        this->name=name;
        this->number=number;
    }

    std::string getName()
    {
        return name;
    }

    std::string getNumber()
    {
        return number;
    }
};

class phoneList
{
private:
    std::vector<phoneNumber> contacts;
public:
    phoneList()
    {
    }

    void add()
    {
        std::string name, number;
        std:: cout << "Input name: ";
        std::cin >> name;
        while(true)
        {
            std::cout << "Input number: ";
            std::cin >> number;
            if(number.length()!=12)
                std::cout << "Not valid number\n";
            else if(number[0]!='+'||number[1]!='7')
                std::cout << "Number doesnt start with +7\n";
            else if (number.substr(2,10)!=std::to_string(std::stoll(number.substr(2,10))) )
                std::cout << "Invalid number\n";
            else
                break;
        }
        contacts.push_back(phoneNumber (name, number));
    }

    void call()
    {
        std::string input;
        std::cout << "Type name or number to call from contacts list: ";
        std::cin >> input;

        for(int i=0;i<contacts.size();i++)
        {
            if(contacts[i].getName()==input)
            {
                std::cout << "Calling " << contacts[i].getNumber() << std::endl;
                return;
            }
        }

        std::cout << "Calling " << input << std::endl;
    }

    void sms()
    {
        std::string name, text;
        std::cout << "Type name or number to text from contacts list: ";
        std::cin >> name;
        std::cin.get();
        std::cout << "Type text to send: ";
        std::getline(std::cin, text);

        for(int i=0;i<contacts.size();i++)
        {
            if(contacts[i].getName()==name)
            {
                std::cout << "Sending sms to " << contacts[i].getNumber() << std::endl;
                std::cout << "Message: " << text << std::endl;
                return;
            }
        }

        std::cout << "Sending sms to " << name << std::endl;
        std::cout << "Message: " << text << std::endl;
    }
};

int main()
{
    phoneList list;
    std::string input;

    do
    {
        std::cout << "Type command: ";
        std::cin >> input;

        if(input=="add")
            list.add();
        else if(input=="call")
            list.call();
        else if(input=="sms")
            list.sms();
    }
    while(input!="exit");
    return 0;
}
