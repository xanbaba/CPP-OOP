#include <iostream>

/*
class foo
{
public:
    foo() : public_field(), private_field(), protected_field()
    {
    }

    int public_field;

private:
    int private_field;

protected:
    int protected_field;
};

class bar_public : public foo
{
public:
    bar_public()
    {
        this->protected_field;
        this->public_field;
    }
};

class bar_protected : protected foo
{
public:
    bar_protected()
    {
        this->protected_field;
        this->public_field;
    }
};

class bar_private : foo
{
public:
    bar_private()
    {
        this->protected_field;
        this->public_field;
    }
};
*/


class vehicle
{
public:
    ~vehicle()
    {
        std::cout << "~vehicle() \n";
    }
    vehicle() : m_speed(), m_color(), m_weight()
    {
        std::cout << "vehicle() \n";
    }

    virtual void move() = 0;

    int get_speed()
    {
        return m_speed;
    }

protected:
    int m_speed;
    int m_color;
    int m_weight;
};

class bicycle : public vehicle
{
public:
    virtual void move() override
    {
        std::cout << "bicycle::move()\n";
        m_speed += 10;
    }
};

class car : public vehicle
{
public:
    virtual void move() override
    {
        std::cout << "car::move()\n";
        m_speed += 50;
    }
};

class motorcycle : public vehicle
{
public:
    virtual void move() override
    {
        std::cout << "motorcycle::move()\n";
        m_speed += 150;
    }
};

int main(int argc, char* argv[])
{
    vehicle* motorcycle_obj = new motorcycle;
    motorcycle_obj->move();
    delete motorcycle_obj;
    return 0;
}
