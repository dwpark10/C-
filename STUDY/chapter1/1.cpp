/*  1. 자신의 이름과 나이를 입력받고 "나의 이름은 홍길동이고, 20살입니다."라고
 *     출력하는 프로그램을 작성하세요. 단 반드시 std::cout, std::cin을 이용해
 *     작성합니다.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int age;

    cout << "이름 입력 : ";
    cin >> name;

    cout << "나이 입력 : ";
    cin >> age;

    cout << "나의 이름은 " << name << "이고, " << age << "살입니다." << endl;

    return 0;
}
