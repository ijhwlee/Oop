// cp20Console.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
  std::cout << "Current path: " << fs::current_path() << std::endl;
  std::string dir = "sandbox/a/b";
  std::cout << "Creating directiry: " << dir << std::endl;
  fs::create_directories(dir);
  std::ofstream("sandbox/file1.txt");
  fs::path symPath = fs::current_path() /= "sandbox";
  symPath /= "syma";
  fs::path symPath1 = fs::current_path() /= "sandbox";
  symPath1 /= "a";
  fs::create_symlink("a", "sandbox/syma");
  std::cout << std::boolalpha;
  std::cout << "fs::is_directory(dir): " << fs::is_directory(dir) << std::endl;
  //std::cout << "fs::exists(symPath): " << fs::exists(symPath) << std::endl;
  std::cout << "fs::exists(symPath1): " << fs::exists(symPath1) << std::endl;
  std::cout << "fs::is_symlink(dir): " << fs::is_symlink(symPath) << std::endl;
  for (auto& p : fs::recursive_directory_iterator("sandbox"))
  {
    std::cout << p.path() << std::endl;
  }
  fs::remove_all("sandbox");
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
