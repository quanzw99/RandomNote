// 实现一个内存可以扩容的数组

#include <iostream>
using namespace std;

// 数组实现
class Array
{
public:
    Array(int size = 10): mCur(0), mCap(size)
    {
        mpArr = new int[mCap]();
    }
    ~Array()
    {
        delete []mpArr;  // 释放指针指向的堆内存
        mpArr = nullptr; // 防止指针成为野指针
    }
public:
    // 末尾增加元素
    void push_back(int val)
    {
        if (mCur == mCap)
            expand(2 * mCap);
        mpArr[mCur++] = val;
    }
    // 末尾删除元素
    void pop_back()
    {
        if(mCur == 0)
        {
            return;
        }
        mCur--;
    }
    // 按位置增加元素
    void insert(int pos, int val)
    {
        // 插入位置不合法
        if (pos < 0 || pos > mCur)
        {
            return;
        }
        
        // 插入位置需要扩容
        if (mCur == mCap)
        {
            expand(2 * mCap);
        }
        
        // 元素后移
        for(int i = mCur-1; i >= pos; i--)
        {
            mpArr[i + 1] = mpArr[i];
        }

        mpArr[pos] = val;
        mCur++;
    }
    // 按位置删除
    void erase(int pos)
    {
        // 插入位置不合法
        if (pos < 0 || pos >= mCur)
        {
            return;
        }

        // 元素移动
        for(int i = pos; i < mCur-1; i++)
        {
            mpArr[i] = mpArr[i+1];
        }

        mCur--;
    }
    // 元素查询
    int find(int val)
    {
        for(int i = 0; i < mCur; i++)
        {
            if(mpArr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    // 打印
    void show()const
    {
        for(int i = 0; i < mCur; i++)
        {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }
private:
    void expand(int size)
    {
        // 1. 开辟新的内存，大小为原来的两倍大
        // 2. 拷贝数据
        // 3. 释放原来的内存

        int* p = new int[size];
        memcpy(p, mpArr, sizeof(int) * mCap);
        delete []mpArr;

        mpArr = p;
        mCap = size;
    }
private:
    int* mpArr; // 指向可扩容的数组内存
    int mCap;  // 数组的容量
    int mCur;   // 数组有效元素个数
};

int main()
{
    Array arr;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100);
    }

    arr.show();
    arr.pop_back();
    arr.show();

    arr.insert(0, 100);
    arr.show();

    arr.insert(10, 200);
    arr.show();

    int pos = arr.find(100);
    if (pos != -1)
    {
        arr.erase(pos);
    }
    arr.show();
}