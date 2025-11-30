#include <string>
using namespace std;

class DynamicStringArray {
 private:
  string* dynamicArray;
  int size;
 public:
  DynamicStringArray();
  DynamicStringArray(const DynamicStringArray& other);
  DynamicStringArray& operator=(const DynamicStringArray& other);
  ~DynamicStringArray();
  int getSize() const;
  void addEntry(const string& entry);
  bool deleteEntry(const string& entry);
  string* getEntry(int index);
};
