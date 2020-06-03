#include "Map.h"
#include <iostream>

using namespace std;

int main()
{
	Map<string, int> testMap;

	testMap.insert("John", 234);
	testMap.printList();
	cout << "\n\n";
	testMap.insert("Jacob", 6546);
	testMap.printList();
	cout << "\n\n";
	testMap.insert("Russel", 2456);
	testMap.printList();
	cout << "\n\n";
	testMap.insert("Sam", 345246);
	testMap.printList();
	cout << "\n\n";
	string key = "Sam";
	cout << "\n\nRemoving " << key << ":" << endl;
	testMap.remove(key);
	testMap.printList();
	key = "John";
	cout << "\n\nElement " << key << " value: " << testMap.find(key) << endl;
	testMap.printList();
}