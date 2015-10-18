#include<iostream>

using namespace std;

class Element {
private:
	int value;
public:
	void setValue(int v) {
		value = v;
	}
	int getValue() {
		return value;
	}
};

class VectorBase {
private:
	int capacity;
protected:
	int size;
	Element * elements;
public:
	VectorBase() {
		capacity = 100;
	    elements = new Element[capacity];
	    size = 0;
    }
	int getSize() {
		return size;
	}
	int getCapacity() {
		return capacity;
	}
	~VectorBase() {
		delete elements;
	}
};

class Vector: public VectorBase {
    public:
    void add(Element e);
    void add(int index,Element e);
    int capacity();
    void clear();
    bool contains(Element e);
    Element elementAt(int index);
    Element firstElement();
    Element get(int index);
    int indexOf(Element e);
    void insertElementAt(Element obj,int index);
    bool isEmpty();
    Element lastElement();
    int lastIndexOf(Element o);
    Element remove(int index);
    bool remove(Element o);
    void removeAllElements();
    void removeElementAt(int index);
    Element set(int index,Element element);
    int Size();
    string toString();
    void print(); // This function is only for showing the elements in main function
};

void Vector::add(Element e)
{
    elements[size] = e;
    size++;
}

void Vector::add(int index,Element e)
{
    if(index <= size && index > -1){
        for(int i = size;i > index; i--){
            elements[i] = elements[i-1];
        }
        elements[index] = e;
        size++;
    }

}

int Vector::capacity()
{
    return getCapacity();
}
void Vector::clear()
{

    for(int i = 0; i < size; i++){
        elements[i].setValue(0);
    }
    size = 0;
}

bool Vector::contains(Element e)
{
    for(int i = 0; i < size; i++){
        if(elements[i].getValue() == e.getValue()) return true;
    }
    return false;
}

Element Vector::elementAt(int index)
{
    if(index < size && index > -1)return elements[index];
}
Element Vector :: firstElement()
{
    return elements[0];
}

Element Vector::get(int index)
{
    if(index < size && index > -1)return elements[index];
}

int Vector :: indexOf(Element e)
{
    for(int i = 0; i < size; i++){
        if(elements[i].getValue() == e.getValue()) return i;
    }
    return -1;
}
void Vector::insertElementAt(Element obj,int index)
{
    if(index <= size && index > -1){
        for(int i = size;i > index; i--){
            elements[i] = elements[i-1];
        }
        elements[index] = obj;
        size++;
    }

}
bool Vector::isEmpty()
{
    if(size == 0)return true;
    return false;
}

Element Vector::lastElement()
{
    return elements[size-1];
}
int Vector::lastIndexOf(Element o)
{
    int i,occurence = 0,index;
    for(i = 0; i < size; i++){
        if(elements[i].getValue() == o.getValue()){
            occurence++;
            index = i;
        }
    }
    if(occurence == 0)return -1;
    return index;
}

Element Vector::remove(int index)
{
    if(index < size && index > -1){
        for(int i = index + 1;i < size; i++){
            elements[i-1] = elements[i];
        }
        size--;
    }

}
bool Vector::remove(Element o)
{
    for(int i = 0; i < size; i++){
        if(elements[i].getValue() == o.getValue()){
            for(int j = i + 1;j < size; j++){
                elements[j-1] = elements[j];
            }
            size--;
        return true;
        }
    }
    return false;
}
void Vector::removeAllElements()
{
    for(int i = 0; i < size; i++){
        elements[i].setValue(0);
    }
    size = 0;
}
void Vector::removeElementAt(int index)
{
    if(index < size && index > -1){
        for(int i = index + 1;i < size; i++){
            elements[i-1] = elements[i];
        }
        size--;
    }
}
Element Vector::set(int index,Element element)
{
    if(index > -1 && index < size){
        elements[index] = element;
        return elements[index];
    }
}
int Vector::Size()
{
    return size;
}
string Vector::toString()
{
    int i = 0,n,j = 0;
    char ara[50];
    while(i < size)
    {
        int a = elements[i].getValue();
        int k = -1;
        string ara1;
        while(a != 0){
            n = a%10;
            a = a/10;
            k++;
            ara1[k] = n + 48;
        }
        while(k != -1)
        {
            ara[j] = ara1[k];
            k--;
            j++;
        }
        ara[j] =',';
        j++;
        i++;
    }
    return ara;
}

void Vector::print() //this function is only for showing the elements in main function
{
    for(int i = 0; i < size;i++){
        cout << elements[i].getValue() << " ";
    }
    cout << endl;
}

// a very simple main
int main() {
	Vector v;
	Element e0,e1,e2,e3,e4,e5,e6;
	e0.setValue(10);
	v.add(e0);
	e1.setValue(30);
	v.add(e1);
	e2.setValue(70);
	v.add(e2);
	e3.setValue(50);
	v.add(1,e3);
	e4.setValue(20);
	v.add(e4);
    v.print();
    cout << v.capacity() << endl;
    cout <<v.contains(e2) << endl;
    cout <<v.elementAt(2).getValue()<<endl;
    cout <<v.firstElement().getValue() <<endl;
    cout <<v.get(3).getValue() <<endl;
    cout <<v.indexOf(e5) << endl;
    e5.setValue(35);
    v.insertElementAt(e5,3);
    v.print();
    cout << v.isEmpty() << endl;
    cout <<v.lastElement().getValue() << endl;
    cout<<v.lastIndexOf(e2)<<endl;
    v.remove(2);
    v.print();
    v.remove(e3);
    v.print();
    v.removeElementAt(1);
    v.print();
    v.set(1,e4);
    v.print();
    cout << v.Size()<<endl;
    e5.setValue(27);
    v.add(e5);
    e6.setValue(14);
    v.add(e6);
    cout <<v.toString()<<endl;
    v.removeAllElements();
    v.print();
    e5.setValue(27);
    v.add(e5);
    e6.setValue(14);
    v.add(e6);
    v.print();
    v.clear();
    v.print();
	cout << v.getSize() << endl;
	return 0;
}

