// associativeContainer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>
#include <map>
#include <set>
#include <vector>

int main()
{
  std::multiset<int> mySet{3, 1, 1, 2, 3, 4, 2, 1, 3, 8, 6, 4, 5, 3, 1, 3, 4, 1};
  for (auto e : mySet)
    std::cout << e << " ";
  std::cout << std::endl;
  mySet.insert(7);
  std::array<int, 5> myArr{10, 11, 12, 13, 14};
  mySet.insert(myArr.begin(), myArr.begin() + 3);
  mySet.insert({ 22,21,20 });
  for (auto e : mySet)
    std::cout << e << " ";
  std::cout << std::endl;
  mySet.erase(4);
  mySet.erase(mySet.lower_bound(5), mySet.upper_bound(15));
  for (auto e : mySet)
    std::cout << e << " ";
  std::cout << "\n\n";

  // 이 후의 내용도 확인하고 실행해 볼 것
  // 각 코드의 결과를 확인하고 원하는 대로 출력하기 위한 수정을 해볼 것
  return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
