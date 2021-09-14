  
// 2 Вариант
#include <iostream>

using namespace std;

int variant (int number, int variants){
    int n = number%variants;
    if (n == 0) n = variants;
    return n;
}

int variantTask2 (char name[30], int variants){
    return variant(name[0],variants);
}

int main()
{
    int number, variants;
    char name[30];
    cin >> name >> variants;
    cout << variantTask2(name, variants) << endl;
    return 0;
}