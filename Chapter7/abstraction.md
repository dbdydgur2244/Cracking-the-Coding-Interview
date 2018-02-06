# Chapter 7 : Object-Oriented Design

**Object-Oriented design** 관련 질문에서는 **technical problem**이나 실생활 **object**에 대해서 class랑 method를 스케칭하는 것을 요구함.

Design pattern 보다는 성능에 중점을 둔다고 함.

그리고 design하는 과정을 다음과 같이 크게 4단계로 분리해서 한다고 한다.



## Object-Oriented Design

### STEP 1: handle Ambiguity

우선 문제를 잘 이해해야한다. 

OOD 관련 질문을 받으면 보통 누가 사용할지, 또, 어떻게 사용할 지 고민하는게 중요하다.

질문에 따라서 육하원칙을 고려할 필요가 있다.



### STEP 2: Define the Core Object

System에서 필요한 **core object**를 정의해야 한다.

책의 예시를 따르면 coffee maker class를 작성한다고 하면 `Table`, `Guest`, `Party`, `Order`, `Meal`, `Employee`, `Server`, `Host`가 있을 수 있다.



### STEP 3: Analyze Relationships

위의 단계에서 정한 object간에 **relationship**을 분석해야한다. 다음과 같은 것이 있을 수 있다.

- 어떤 object가 다른 object의 멤버인가
- 어떤 object가 다른 것들을 상속 받을 것인가
- many-to-many인가 one-to-many 관계인가

등등이 있을 수 있다.

이 단계에서 신중히 해야한다.



### STEP 4: Investigate Actions

이 전까지 했다면 기본적인 class의 outline은 정해졌고 이제 object의 key action을 정해야한다.



## Design Pattern

보통 인터뷰에서는 많이 쓰이는 design pattern으로 **Singleton class**와 **Factory Method** 정도는 아는 것이 좋다.



## Singleton class

### Singleton class의 정의

해당클래스의 인스턴스가 하나만 만들어지고, 어디서든지 그 인스턴스에 접근할 수 있도록 하기 위한 패턴이다.

[^1]: http://ngostar.tistory.com/entry/Singleton-Pattern?category=262762

인스턴스를 두 개 이상 만들면 Race condition이 발생한다든가, 리소스를 불필요하게 더 먹는다는가 하는 좋지 않은 상황 혹은 에러 상황들이 발생할 수 있는 경우에 주로 사용한다. 이러한 문제를 예방하기 위해 이렇게 하나만 있어야 되는(or 하나만 있어도 되는) 객체를 싱글턴 패턴을 통해 디자인 한다.

그 예로는 스레드풀, 캐시, 사용자 설정, 레지스트리 설정을 처리하는 객체, 로그 기록용 객체, 프린터와 그래픽 카드 드라이버, 기타 디바이스 드라이버등이 있다.



### Singleton class의 종류

[^1]: c++ 기준으로 작성하였습니다.

1. **Basic Singleton**
2. **Dynacmic Singleton**
3. **Static local Singleton**
4. **Phoenix Singleton**

가 존재한다.



## Factory Method

[^1]: http://jdm.kr/blog/180와 http://ngostar.tistory.com/entry/Factory-Pattern를 참고하였습니다 .

객체를 만들어내는 부분을 **sub-class**에서 하는 방법으로 **객체를 만들어내는 공장(Factory class)을 만드는 방법**이라고 생각하면 된다. 즉, 사용되는 서브클래스에 따라 생산되는 객체 인스턴스가 결정된다.

**Factory Method**를 사용하는 이유는 class간의 **결합도**를 낮추기 위한 것이다. 결합도라는 것은 간단히 말해 **class의 변경점이 생겼을 때 얼마나 다른 class에도 영향을 주는가**이다. 이 방법을 통해직접 객체를 생성해 사용하는 것을 방지하고 서브 클래스에 위임함으로써 보다 효율적인 코드 제어를 할 수 있고 의존성을 제거한다.  또한 이를 통해 부모(상위) class 코드에 구체(concrete) class 이름을 감추기 위한 방법으로도 사용한다. 

주의해야 할 점은 **Factory Method**가 중첩되기 시작하면 굉장히 복잡해 질 수 있다는 것이다. 또한 상속을 사용하지만 부모(상위) class를 전혀 확장하지 않는다. 따라서 이 패턴은 extends 관계를 잘못 이용한 것으로 볼 수 있다. extends 관계를 남발하게 되면 프로그램의 엔트로피가 높아질 수 있으므로 **Factory Method** 패턴의 사용을 주의해야 한다.



