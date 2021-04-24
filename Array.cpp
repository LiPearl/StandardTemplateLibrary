//记录：（1）每一个函数只要实现其对应的功能即可
//(2)使用类模板时，要看清对象的类型
#include <iostream>
#include <string>
//编译的时候 不需重复load
//傻逼李珍珍
#ifndef _ARRAY
#define _ARRAY 1
using namespace std;
template<typename T>
class Array{
	T *data;
	size_t __length;
    size_t allocated;
public:
    Array(){
        data = new T[1];
        allocated = 1;
        __length  = 0;
    };
	Array(size_t len){
        data = new T[len];
        allocated = len;
		__length = len;
	};


    //拷贝构造函数

    Array(size_t len, const T& sample){
		__length = len;
        allocated = len;
        data = new T [allocated];
		for(size_t i=0;i<__length;i++){
            data[i] = sample;
        }  
	};

    void reallocate(size_t __allocate){
        T *tmp = new T[__allocate];
        for(size_t i=0;i<__length;i++){
            tmp[i] = data[i];
        }
        allocated = __allocate;
        delete [] data;
        data = tmp;
    }

	void insert(size_t index, const T &val){
        if (__length>=allocated)
            reallocate(allocated*2);
        for (size_t i=__length-1;i>index && __length!=0;i--){
            data[i] = data[i-1];
        }
        data[index] = val;
        __length = __length+1;
	}

    //delete
    void erase(size_t index){
        for(size_t i=index;i<__length-1;i++){
            data[i] = data[i+1];
        }
        __length--;   
    }

    size_t size() const {
        return __length;
    }

    //运算符[]重载
    T &operator[](size_t index) const {
        if (index>__length-1)
            throw "the index is out of the range!";
        return data[index];    
    }

    //类模板
    Array<T>& operator=(const Array<T> &right){
        reallocate(right.allocated);
        __length = right.__length;
        allocated = right.allocated;
        for(size_t i=0;i<__length;i++){
            data[i] = right.data[i];
        }      
        return *this;  
    }

    //从数组尾部插入数据
    void push_back(const T& data){
        insert(__length,data);
    }

    //从尾部移除数据
    void pop_back(){
        erase(__length-1);
    }

    //返回尾部内容
    T& back(){
        return data[__length-1];
    }


};
#endif