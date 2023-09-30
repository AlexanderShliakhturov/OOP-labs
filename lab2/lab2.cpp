#include <iostream>
#include <utility>
#include <math.h>
#include <string>
#include <cstring>
#include <typeinfo>

class DynamicArray
{
private:
    unsigned char *data;
    int size;
    int capacity;

public:
    DynamicArray() : data(nullptr), size(0), capacity(0) {}
    DynamicArray(std::string a) : data(nullptr), size(0), capacity(0)
    {
        for (int i = 0; i < a.length(); i++)
        {
            this->push_back(a[i]);
        }
    }
    DynamicArray(const std::initializer_list<unsigned char> &t) : data(nullptr), size(t.size()), capacity(t.size())
    {
        for (const unsigned char &value : t)
        {
            this->push_back(value);
        }
    }
    DynamicArray(const size_t &n, unsigned char t = 0) : data(nullptr), size(n), capacity(n)
    {
        for (int i = 0; i < n; i++)
        {
            this->push_back(t);
        }
    }

    DynamicArray(const DynamicArray &other) : data(nullptr), size(other.size), capacity(other.capacity)
    {
        data = new unsigned char[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray()
    {
        // delete[] data;
    }
    void push_front(unsigned char value)
    {
        if (capacity == size)
        {
            capacity += 1;
        }

        unsigned char *newData = new unsigned char[capacity + 1];

        for (int i = 0; i < size; i++)
        {
            newData[i + 1] = data[i];
        }

        newData[0] = value;

        delete[] data;
        data = newData;
        size++;
    }

    void del_front()
    {
        if (size <= 0)
        {
            return;
        }

        unsigned char *newData = new unsigned char[capacity];

        for (int i = 1; i < size; i++)
        {
            newData[i - 1] = data[i];
        }

        delete[] data;
        data = newData;
        size--;
    }

    void push_back(unsigned char value)
    {
        if (capacity == size)
        {
            capacity += 1;
        }

        unsigned char *newData = new unsigned char[capacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        data[size++] = value;
    }

    int get_size()
    {
        return size;
    }

    unsigned char &operator[](int index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    bool operator==(const DynamicArray &other) const
    {
        if (size != other.size)
            return false;

        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
                return false;
        }

        return true;
    }

    unsigned char *begin()
    {
        return data;
    }

    unsigned char *end()
    {
        return data + size;
    }
};

DynamicArray str_to_reverse_DynamicArray(const std::string &a)
{
    std::string res;
    res.resize(a.length());

    for (int i = 0; i <= a.length() - 1; i++)
    {
        res[i] = a[a.length() - i - 1];
    }
    DynamicArray result;
    for (char c : res)
    {
        result.push_back(static_cast<unsigned char>(c));
    }

    return result;
}

void do_equal_length(DynamicArray &a, DynamicArray &b)
{
    int delta = a.get_size() - b.get_size();
    if (delta > 0)
    {
        for (int i = 0; i < delta; i++)
        {
            b.push_back('0');
        }
    }
    else if (delta < 0)
    {
        for (int i = 0; i < -1 * delta; i++)
        {
            a.push_back('0');
        }
    }
}

class Octal
{
private:
    DynamicArray Array_value;

public:
    Octal(const std::string &mass)
    {
        for (unsigned char digit : mass)
        {
            if (digit < '0' || digit > '7')
            {
                throw std::invalid_argument("Invalid octal digit detected");
            }
        }

        Array_value = str_to_reverse_DynamicArray(mass);
    }

    void show()
    {
        for (int i = 0; i < this->Array_value.get_size(); i++)
        {
            std::cout << this->Array_value[i];
        }
        std::cout << std::endl;
    }

    std::string to_string()
    {
        std::string res(this->Array_value.get_size(), 0);
        for (int i = 0; i < this->Array_value.get_size(); i++)
        {
            res[i] = this->Array_value[i];
        }
        return res;
    }

    Octal sum(Octal num)
    {

        int len = std::max(this->Array_value.get_size(), num.Array_value.get_size()) + 1;
        std::string str(len, '0');
        Octal res_reverse(str);
        Octal res(str);
        do_equal_length(this->Array_value, num.Array_value);
        int carry = 0;
        for (int i = 0; i < len - 1; i++)
        {
            int sum = (this->Array_value[i] - '0' + num.Array_value[i] - '0') + carry;
            res_reverse.Array_value[i] = static_cast<unsigned char>((sum % 8) + '0');
            carry = sum / 8;
        }
        res_reverse.Array_value[len - 1] = static_cast<unsigned char>(carry + '0');
        for (int i = 0; i < res_reverse.Array_value.get_size(); i++)
        {
            res.Array_value[i] = res_reverse.Array_value[res_reverse.Array_value.get_size() - 1 - i];
        }

        if (res.Array_value[0] == '0')
        {
            res.Array_value.del_front();
        }

        return res;
    }
    Octal diff(Octal num)
    {
        if (this->less_than(num) == "TRUE")
        {
            throw std::invalid_argument("Result is negative");
        }

        int len = this->Array_value.get_size();
        std::string str(len, '0');
        Octal res_reverse(str);
        Octal res(str);
        do_equal_length(this->Array_value, num.Array_value);

        int borrow = 0;
        for (int i = 0; i < this->Array_value.get_size(); i++)
        {
            int diff = (this->Array_value[i] - '0') - (num.Array_value[i] - '0') - borrow;
            if (diff < 0)
            {
                diff += 8;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            res_reverse.Array_value[i] = (static_cast<unsigned char>(diff + '0'));
        }
        for (int i = 0; i < res_reverse.Array_value.get_size(); i++)
        {
            res.Array_value[i] = res_reverse.Array_value[res_reverse.Array_value.get_size() - 1 - i];
        }

        return res;
    }

    std::string less_than(Octal num)
    {
        if (this->equal(num) == "TRUE")
        {
            return "FALSE";
        }
        if (this->more_than(num) == "TRUE")
        {
            return "FALSE";
        }
        return "TRUE";
    }
    std::string more_than(Octal num)
    {
        int len = std::max(this->Array_value.get_size(), num.Array_value.get_size());
        do_equal_length(this->Array_value, num.Array_value);
        if (this->equal(num) == "TRUE")
        {
            return "FALSE";
        }

        for (int i = len - 1; i >= 0; i--)
        {
            if (this->Array_value[i] > num.Array_value[i])
            {
                return "TRUE";
            }
        }
        return "FALSE";
    }

    std::string equal(Octal num)
    {
        int len = std::max(this->Array_value.get_size(), num.Array_value.get_size());
        do_equal_length(this->Array_value, num.Array_value);
        for (int i = 0; i < len; i++)
        {
            if (this->Array_value[i] != num.Array_value[i])
            {
                return "FALSE";
            }
        }
        return "TRUE";
    }
};

std::string main_func(Octal first, char operand, Octal second)
{
    if (operand == '+')
    {
        return first.sum(second).to_string();
    }
    else if (operand == '-')
    {
        return first.diff(second).to_string();
    }
    else if (operand == '>')
    {
        return first.more_than(second);
    }
    else if (operand == '<')
    {
        return first.less_than(second);
    }
    if (operand == '=')
    {
        return first.equal(second);
    }
}

int main()
{
    // std::string first;
    // std::string second;
    // char operand;

    // std::cout << "ВВЕДИТЕ ПЕРВОЕ ЧИСЛО" << std::endl;
    // std::cin >> first;
    // std::cout << std::endl;

    // std::cout << "ВВЕДИТЕ ОПЕРАНД" << std::endl;
    // std::cin >> operand;
    // std::cout << std::endl;

    // std::cout << "ВВЕДИТЕ ВТОРОЕ ЧИСЛО" << std::endl;
    // std::cin >> second;
    // std::cout << std::endl;

    // std::cout << first << " " << operand << " " << second << " IS ";
    // std::cout << main_func(first, operand, second);
    // std::cout << std::endl;
    std::string first = "0";
    std::string second = "0";
    char operand = '>';
    // Act:
    std::string result = Octal(first).equal(Octal(second));
    std::cout << result;
    
    return 0;
}