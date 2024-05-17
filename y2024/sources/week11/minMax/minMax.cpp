// minMax.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::string toString(int i) {
  std::stringstream buff;
  buff.str("");
  buff << i;
  std::string val = buff.str();
  return val;
}

int toInt(const std::string s) {
  std::stringstream buff;
  buff.str("");
  buff << s;
  int value;
  buff >> value;
  return value;
}

int main()
{
  std::vector<int> myInts;
  std::vector<std::string> myStrings{ "94", "5", "39", "-4", "-49", "1001", "-7",
                                      "23", "0", "84", "59", "96", "6", "-94", "87"};
  std::transform(myStrings.begin(), myStrings.end(), std::back_inserter(myInts), toInt);
  std::cout << "String to Integers myInts values : " << std::endl;
  for (auto i : myInts) std::cout << i << " ";
  std::cout << std::endl;

  auto paInt = std::minmax_element(myInts.begin(), myInts.end());
  std::cout << "std::minmax_element(myInts.begin(), myInts.end()) : "
    << "(" << *paInt.first << ", " << *paInt.second << ")" << std::endl;

  auto paStr = std::minmax_element(myStrings.begin(), myStrings.end());
  std::cout << "std::minmax_element(myStrings.begin(), myStrings.end()) : "
    << "(" << *paStr.first << ", " << *paStr.second << ")" << std::endl;
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
