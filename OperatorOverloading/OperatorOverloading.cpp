
#include <cstring>
#include <iostream>

class String
{
public:
    String()
    {
        mSize = 0;
        mData = new char[mSize + 1]{};
    }
    String(const char* aString)
    {
        mSize = static_cast<int>(strlen(aString));
        mData = new char[mSize + 1];
        std::memcpy(mData, aString, mSize + 1);
    }

    String(String&& aOther) noexcept
    {
        std::cout << "move constructor\n";
        mData = aOther.mData;
        mSize = aOther.mSize;
        aOther.mData = nullptr;
        aOther.mSize = 0;
    }

    String(const String& aOther)
    {
        CopyData(aOther);
    }
    ~String()
    {
        delete[] mData;
    }

    String& operator=(const String& aOther)
    {
        if (this != &aOther)
        {
            this->~String();
            CopyData(aOther);
        }

        return *this;
    }

    String& operator=(String&& aOther) noexcept
    {
        std::cout << "move assignment\n";
        if (this != &aOther)
        {
            this->~String();
            mData = aOther.mData;
            mSize = aOther.mSize;
            aOther.mData = nullptr;
            aOther.mSize = 0;
        }
        return *this;
    }

    String& operator*=(int aTimes)
    {
        int totalSize = (mSize * aTimes);
        char* data = new char[totalSize + 1]{};

        for (int i = 0; i < totalSize; ++i)
        {
            data[i] = mData[i % mSize];
        }

        this->~String();

        mSize = totalSize;
        mData = data;
        
        return *this;
    }

    String operator*(int aTimes)
    {
        int totalSize = (mSize * aTimes);
        char* data = new char[totalSize + 1]{};

        for (int i = 0; i < totalSize; ++i)
        {
            data[i] = mData[i % mSize];
        }

        return String{totalSize, data};
    }

    char& operator[](int aIndex)
    {
        return mData[aIndex];
    }

    const char* GetString()
    {
        return mData;
    }
private:
    char* mData;
    int mSize;

    String(int aSize, char* aData)
    {
        mSize = aSize;
        mData = aData;
    }
    
    void CopyData(const String& aOther)
    {
        mSize = aOther.mSize;
        mData = new char[mSize + 1];
        memcpy(mData, aOther.mData, mSize + 1);
    }
};

void f(String&& s)
{
    s *= 2;
    std::cout << s.GetString() << '\n';
}

int main(int argc, char* argv[])
{
    {
        String s1{"Hello"};
        String s2 = std::move(s1);
    }
    {
        String s1{"Hello"};
        String s2 = "C++";

        s2 = std::move(s1);
    }
    
    return 0;
}
