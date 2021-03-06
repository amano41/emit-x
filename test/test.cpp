#include "test.h"

TEST_CLASS(Class1) {
public:
  TEST_METHOD(lower) {
    Assert::AreEqual(::lower(L"FOOBAR").c_str(), L"foobar");
  }
  TEST_METHOD(translate1) {
    std::vector<std::wstring> v;
    Assert::IsTrue(::translate(L"emit-Alt-Ctrl-X.exe", &v));
    Assert::AreEqual(3, static_cast<int>(v.size()));
    Assert::AreEqual(L"alt", v[0].c_str());
    Assert::AreEqual(L"ctrl", v[1].c_str());
    Assert::AreEqual(L"x", v[2].c_str());
  }
  TEST_METHOD(translate2) {
    std::vector<std::wstring> v;
    Assert::IsTrue(::translate(L"emit-Win-PrtScr.exe", &v));
    Assert::AreEqual(2, static_cast<int>(v.size()));
    Assert::AreEqual(L"win", v[0].c_str());
    Assert::AreEqual(L"prtscr", v[1].c_str());
  } 
  TEST_METHOD(vk) {
    std::vector<std::wstring> v;
    Assert::IsTrue(::translate(L"emit-Enter-Del-BS-PrtScr.exe", &v));
    Assert::AreEqual(4, static_cast<int>(v.size()));
    Assert::AreEqual(L"enter", v[0].c_str());
    Assert::AreEqual(L"del", v[1].c_str());
    Assert::AreEqual(L"bs", v[2].c_str());
    Assert::AreEqual(L"prtscr", v[3].c_str());
    Assert::AreEqual(VK_RETURN, static_cast<int>(::vk(v[0])));
    Assert::AreEqual(VK_DELETE, static_cast<int>(::vk(v[1])));
    Assert::AreEqual(VK_BACK, static_cast<int>(::vk(v[2])));
    Assert::AreEqual(VK_SNAPSHOT, static_cast<int>(::vk(v[3])));
  }
  TEST_METHOD(leaf) {
    Assert::AreEqual(L"baz", ::leaf(L"foo\\bar\\baz").c_str());
  }
  TEST_METHOD(join) {
    Assert::AreEqual(L"foo\\bar", ::join(L"foo", L"bar").c_str());
  }
};
