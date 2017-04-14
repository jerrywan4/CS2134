/*
Programmer: Jerry Wan
N12474893
HW01.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Combolock{
	int c1;
	int c2;
	int c3;
	bool state;
	Combolock(const Combolock& copy);
public:
	Combolock(int c1, int c2, int c3, bool state) : c1(c1), c2(c2), c3(c3), state(false){}
		
	~Combolock(){}

	bool open(int a, int b, int c){
		if(a == c1 && b == c2 && c == c2){
			state = true;
		}
		return state;
	}

	void changeCombo(int a, int b, int c){
		c1 = a;
		c2 = b;
		c3 = c;
	}
};


template <class T> class DynArray{
	T* data;
	int numOfElements;
	int sizeOfData;
	bool brackets;
public:
	DynArray() :data(new T[5]), sizeOfData(5), numOfElements(0){}
	~DynArray(){ delete[] data; }
	
	T size()const { return numOfElements; }
	T capacity() const{ return sizeOfData; }



	void push_back(T item){
	if (brackets == true){return;}
	if (sizeOfData == numOfElements)
		resize(sizeOfData * 2);
	data[numOfElements++] = item;
	}

	T pop_back(){
	T retval;
	if (numOfElements > 0){
		retval = data[--numOfElements];
	}
	return retval;
	}

	void resize(T newSize){
	T * temp = new int[newSize];
	if (newSize < numOfElements)
		numOfElements = newSize;
	for (T i = 0; i < numOfElements; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
	sizeOfData = newSize;
	}

	T operator[](int indexVal){
		T temp;
		for (int i=0; i < numOfElements; i++){
			if(i == indexVal){
			temp = data[i];
			brackets = true;
			}
		}
		return temp;
	}
};


double costCalculator(map<int,double> fileMap , vector<int> items ){
    int n = (int)items.size();
    double cost = 0.0;
    for(int i=0;i<n;i++){
        int curr_item_no = items[i];
        double curr_price = fileMap[curr_item_no];
        cost = cost + curr_price;
    }
    return cost;
}

int main(){
    map<int,double> fileMap;
    vector<int> items;
    
    int itemNum;
    double price;
    ifstream ifs("HW1data.txt");
    while(ifs>>itemNum>>price){
        fileMap[itemNum] = price;
    }
    items.push_back(1);
    items.push_back(99);
    items.push_back(47);
    items.push_back(22);
    double totalcost = costCalculator(fileMap,items);
    cout<<"Total Cost: "<<totalcost<<endl;
    ifs.close();
}