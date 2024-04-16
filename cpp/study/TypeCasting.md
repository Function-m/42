
## 형변환 (Type Casting)

- **C-스타일 형변환**
가장 기본적이며 간단하지만, 타입 안전성이 보장되지 않는 방법입니다.
<br>

- **static_cast**
컴파일 시간에 형변환을 수행하며, 기본 데이터 타입, 클래스 객체 등 대부분의 형변환에 사용됩니다. 타입 안전성을 제공합니다.
  ```cpp
  double pi = 3.14159;
  int integerPart = static_cast<int>(pi); // double을 int로 형변환
  ```
<br>

- **dynamic_cast**
런타임에 형변환을 수행하며, 주로 상속 관계에 있는 클래스 사이의 형변환에 사용됩니다. 타입 체크를 수행하기 때문에, 실패할 경우 nullptr을 반환합니다.
  ```cpp
  class Base { virtual void dummy() {} };
  class Derived: public Base { int a; };

  Base* basePtr = new Derived;
  Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // 런타임에 안전하게 다운캐스팅
  ```
  ***잘못된 사용***
  ```cpp
  class Base {};
  class Derived: public Base {};  

  Base* basePtr = new Base;
  Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Base 객체를 Derived 타입으로 다운캐스팅 시도
  ```
<br>

- **const_cast**
상수성(constness)을 추가하거나 제거할 때 사용됩니다.
  ```cpp
  const int val = 10;
  const int* valPtr = &val;
  int* modifiablePtr = const_cast<int*>(valPtr);
  *modifiablePtr = 20; // const 속성 제거
  ```
<br>

- **reinterpret_cast**
거의 모든 포인터 또는 참조 타입 간의 형변환을 허용하지만, 타입 안전성이 전혀 보장되지 않으므로 매우 주의해서 사용해야 합니다.
  ```cpp
  long p = 5328;
  void* vp = reinterpret_cast<void*>(p); // 정수를 포인터 타입으로 형변환
  ```
  ***잘못된 사용***
  ```cpp
  int* intPtr = new int(10);
  char* charPtr = reinterpret_cast<char*>(intPtr); // int 포인터를 char 포인터로 잘못 형변환
  ```
