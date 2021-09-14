
#include <iostream>
#include "strutil.h"

using namespace std;

void test() {

	char strTest1[10] = "qwerty";
	char aTest1[10] = "ty";
	if (srtConteins(aTest1, strTest1) != 4)
		cout << "TEST 1 FAILD" << endl;
	else cout << "TEST 1 COMPLETED" << endl;

	char strTest2[10] = "asdfg";
	char aTest2[10] = "as";
	if (srtConteins(aTest2, strTest2) != 0)
		cout << "TEST 2 FAILD" << endl;
	else cout << "TEST 2 COMPLETED" << endl;

	char strTest3[10] = "123456789";
	char aTest3[10] = "4567";
	if (srtConteins(aTest3, strTest3) != 3)
		cout << "TEST 3 FAILD" << endl;
	else cout << "TEST 3 COMPLETED" << endl;

	char strTest4[10] = "qazwsxedc";
	char aTest4[10] = "1234";
	if (srtConteins(aTest4, strTest4) == -1)
		cout << "TEST 4 COMPLETED" << endl;
	else cout << "TEST 4 FAILD" << endl;

	char strTest5[10] = "srhsfjnfg";
	char aTest5[10] = "cv";
	if (srtConteins(aTest5, strTest5) == -1)
		cout << "TEST 5 COMPLETED" << endl;
	else cout << "TEST 5 FAILD" << endl;

}

int main()
{
	test();
	return 0;
}

