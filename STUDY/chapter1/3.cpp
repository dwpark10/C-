/* 3. char[12] 배열 메모리를 new 연산자로 동적 할당하고 해제하는 코드 예를 작성
 */

#include <iostream>

using namespace std;

int main()
{
    char* c_arr = new char[12];

    delete[] c_arr;
}
