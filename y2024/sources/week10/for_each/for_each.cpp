﻿// for_each.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <execution>

template <typename T>
class ContainerInfo {
public:
  void operator()(T t) {
    num++;
    sum += t;
  }
  int getSum() const {
    return sum;
  }
  int getSize() const { return num; }
  double getMean() const {
    return static_cast<double>(sum) / static_cast<double>(num);
  }
private:
  T sum{ 0 };
  int num{0};
};

int main()
{
  std::vector<double> myVec{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  auto vecInfo = std::for_each(myVec.begin(), myVec.end(), ContainerInfo<double>());
  std::cout << "myVec.size(): " << myVec.size() << std::endl;
  std::cout << "vecInfo.getSum(): " << vecInfo.getSum() << std::endl;
  std::cout << "vecInfo.getSize(): " << vecInfo.getSize() << std::endl;
  std::cout << "vecInfo.getMean(): " << vecInfo.getMean() << std::endl;

  std::array<int, 100> myArr{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  auto arrInfo = std::for_each(myArr.begin(), myArr.end(), ContainerInfo<int>());
  std::cout << "myArr.size(): " << myArr.size() << std::endl;
  std::cout << "arrInfo.getSum(): " << arrInfo.getSum() << std::endl;
  std::cout << "arrInfo.getSize(): " << arrInfo.getSize() << std::endl;
  std::cout << "arrInfo.getMean(): " << arrInfo.getMean() << std::endl;
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
