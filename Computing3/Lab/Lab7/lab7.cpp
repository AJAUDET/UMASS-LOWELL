#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;
#undef debug

template<typename T>
class BSTNode {

 public:
	// Constructors, etc.
	BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
    BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
	BSTNode(BSTNode&); // copy constructor
    ~BSTNode(); // destructor
	BSTNode& operator= (BSTNode&); // copy assignment operator
	
	// ***** Your group will define/implement the insert function
	// ***** at about line 89 below...
	void insert(const T& data);
	
	// Accessor and mutator functions
    BSTNode<T>* getLeft() const { return _left; }
	BSTNode<T>* getRight() const { return _right; }
	T& getData() const { return _data; }
	void setData(const T& data) { _data = data; }

	// Display functions used by operator<<.
	// ***** Your group will define/implement the pre & post display functions
	// ***** at about lines 114 & 127 below...
	void inOrderDisplay(ostream&) const;
	void preOrderDisplay(ostream&) const;
	void postOrderDisplay(ostream&) const;
	
	// The insertion operator below uses in-order display.
	// ***** Change the implementation of this insertion operator
	// ***** in order to switch to pre- or post-order display
	friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
		{ b.preOrderDisplay(out); return out;};

    void listify(list<T>& p) const;
	
 private:
	T _data;
    BSTNode<T>* _left;
    BSTNode<T>* _right;
	
	// private "helper" functions
    void addLeft(const T& data) { _left = new BSTNode(data); }
	void addRight(const T& data) { _right = new BSTNode(data); }
};


template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
	if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
	cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
    delete _left;
	delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy assignment operator: ";
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
	return *this;
}


template<typename T>
void BSTNode<T>::insert(const T& data) {
	// comment out the next line when you've completed this function!
	// cout << "BSTNode<T>::insert called with data == " << data << endl;
	if (data < _data) {
        if (_left != nullptr) {
            _left->insert(data);  // Recurse on left child
        } else {
            addLeft(data);  // Create new left child
        }
    }
    else if (data > _data) {
        if (_right != nullptr) {
            _right->insert(data);  // Recurse on right child
        } else {
            addRight(data);  // Create new right child
        }
    }
}

template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
	if (_left != nullptr) {
	    out << ", ";
        _left->inOrderDisplay(out);
	}
	out << _data;
	if (_right != nullptr) {
	    out << ", ";
	    _right->inOrderDisplay(out);
	}
}


/**
 *  ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
	// comment out the next line when you've completed this function!
	// cout << "BSTNode<T>::preOrderDisplay called\n";
	
    // SLR
    out << _data;
    if (_left != nullptr) {
        out << ", ";
        _left->preOrderDisplay(out);
    }
    if (_right != nullptr) {
        out << ", ";
        _right->preOrderDisplay(out);
    }
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
	// comment out the next line when you've completed this function!
	// cout << "BSTNode<T>::postOrderDisplay called\n";
	
    // LRS
    if (_left != nullptr) {
        _left->postOrderDisplay(out);
        out << ", ";
    }
    if (_right != nullptr) {
        _right->postOrderDisplay(out);
        out << ", ";
    }
    out << _data;
}

template <typename T>
void BSTNode<T>::listify(list<T>& p) const {
	if (_left != nullptr) {
        _left->listify(p);
	}
    p.push_back(_data);
    if (_right != nullptr)
    {
        _right->listify(p);
    }
}

int main(void) {
	BSTNode<int> iroot(100);
	iroot.insert(10);
	iroot.insert(20);
	iroot.insert(200);
	iroot.insert(300);
	cout << "iroot == " << iroot << endl;
	
	BSTNode<string> sroot("Sunday");
	sroot.insert("Monday");
	sroot.insert("Tuesday");
	sroot.insert("Wednesday");
	sroot.insert("Thursday");
	sroot.insert("Friday");
	sroot.insert("Saturday");
	cout << "sroot == " << sroot << endl;

    list<int> iRootList;
    iroot.listify(iRootList);
    list<string> sRootList;
    sroot.listify(sRootList);

    // --- Forward iteraror ---
    cout << "iRootList (forward iterator) == ";
    for (auto p = iRootList.begin(); p != iRootList.end(); ++p)
    {
        cout << *p << " ";  // change iroot
    }
    cout << endl;

    // --- Reverse iteraror ---
    cout << "iRootList (reverse iterator) == ";
    for (auto rp = iRootList.rbegin(); rp != iRootList.rend(); ++rp)
    {
        cout << *rp << " ";  // change iroot
    }
    cout << endl;
    
	// --- Ranged For Loop ---
	cout << "iRootList (ranged for loop) == ";
	for(auto i : iRootList) {
		cout << i << " ";	
	}
    cout << endl;
	
    // --- Forward iteraror ---
    cout << "sRootList (forward iterator) == ";
    for (auto p = sRootList.begin(); p != sRootList.end(); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;

    // --- Reverse iteraror ---
    cout << "sRootList (reverse iterator) == ";
    for (auto rp = sRootList.rbegin(); rp != sRootList.rend(); ++rp)
    {
        cout << *rp << " ";
    }
    cout << endl;
    
	// --- Ranged For Loop ---
	cout << "sRootList (ranged for loop) == ";
	for(auto i : sRootList) {
		cout << i << " ";	
	}
    cout << endl;

	BSTNode<int> iroot4(1000);
	iroot4.insert(2000);
	iroot4.insert(3000);
	iroot4.insert(4000);
	iroot4.insert(5000);
	
	list<int> iRoot4List;
	iroot4.listify(iRoot4List);

	// Create a map
	map<string, list<int>> mi;
	mi["irootList"] = iRootList;
	mi["iroot4List"] = iRoot4List;

	// --- Ranged for loop ---
    cout << "Contents of map<string, list<int>> mi (using ranged for loops): " << endl;
    for (auto i : mi)
    {	
		const string& name = i.first;
		const list<int>& value = i.second;

		cout << name << ": ";
		for (auto r : value)
		    cout << r << " ";
		
    	cout << endl;
	}

	// --- Map Index Operator ---

	// TBA -----------
	

#ifdef debug	
	BSTNode<int> iroot2(iroot); // use copy constructor
	cout << "\nAfter copy constructor:\n";
	cout << "iroot2 == " << iroot2 << endl;
	
	BSTNode<int> iroot3;
	iroot3 = iroot2; // use copy assignment operator
	cout << "\nAfter copy assignment operator:\n";
	cout << "iroot3 == " << iroot3 << endl << endl;

#endif
	
	return 0;
}
