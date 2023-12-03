
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

int main(int argc, char* argv[])
{
    auto s = String{"1000abc"};
    auto s2 = s;
    auto s3 = s2;
    s3 *= 2;
    s3[0] = '2';
    std::cout << (s3 * 3).GetString();
    return 0;
}
