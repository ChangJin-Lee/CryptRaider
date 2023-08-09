# CryptRaider
Unreal Engine 5 Level design for dungeon

- Need to download medieval dungeon from Market place



--- 

### 루멘, 라이트 블리딩

- 루멘
    - 실시간 전역 조명 및 반사 엔진
    - Static(객체 설정 바뀌지 않음 베이), Staionary(객체는 바꿀 수 없는데 밝기  같은건 바꿀 수 있음.), Movable이 있는데, Movable로 했을 때 잘 적용 movalble은 모든 걸 변경 가능함.
    <img src="https://github.com/ChangJin-Lee/CryptRaider/assets/54494793/ef9b6325-87a3-4cd9-a2bf-60b0279f70cb" width = 70%>
- 부모 머터리얼
    - 부모 머터리얼에서 상속받은 머터리얼들을 새로운 머터리얼로 만들 수 있어요.
    - 마치 블루프린트와 같은 개념이에요
- 블리딩
    - 루멘 글로벌 일루미네이션은 디퓨즈 간접광을 해결해요. 예를 들어 표면에서 디퓨즈, 바운스되는 라이트는 해당 표면의 색을 띠고 주변 표면에 색이 들어간 라이트를 반사하여 컬러 블리딩(color bleeding)이라는 이펙트를 생성해요. 씬의 메시도 간접광을 차단하며 간접 섀도잉을 생성해요.

    <img src="https://github.com/ChangJin-Lee/CryptRaider/assets/54494793/d1c1d5a6-c195-408f-b6ae-62cad5af52d0" width = 70%>

    <img src="https://github.com/ChangJin-Lee/CryptRaider/assets/54494793/af9c8e50-c9fc-4063-97c5-c46dbbfb27f2" width = 70%>


### Level Lighting

- Shadow
    - Dyanamic Shadow
        - 디렉셔널 라이트 액터 전용 섀도잉 메서드인 Cascading Shadow Mapping (캐스케이드 섀도 매핑)을 통해 구워진 라이팅으로 동적인 섀도잉 효과를 내는 법을 확인할 수 있습니다. 미리 구워둔 그림자에 비할 때, 바람에 나부끼는 잎사귀 풍성한 나무같은 다이내믹 오브젝트에도 그림자를 드리워 훨씬 사실적인 씬을 만들 수 있다는 장점이 있습니다.
    - Static Shadow
        - 성능에 영향을 주지 않는 완벽한 정적 쉐도우
        
    <img src="https://github.com/ChangJin-Lee/ChangJin-Lee/assets/54494793/d6d9948a-9c2e-4091-8d3d-c5a1d0ebcc10" width = 50%>

- Intensity
    - 라이트가 뿜는 총 에너지입니다.

    <img src="https://github.com/ChangJin-Lee/ChangJin-Lee/assets/54494793/94021ebd-a78f-4cb0-a5c0-8b14a96aa5bb" width = 50%>

- Attenuation Radius
    - 라이트의 가시 영향력 범위입니다.

    <img src="https://github.com/ChangJin-Lee/ChangJin-Lee/assets/54494793/fb9ec162-f496-4013-8355-a0682a560524" width = 50%>


## 캐릭터 BP

- defulat 프로젝트로 게임모드를 설정하기

    <img width="1314" alt="스크린샷 2023-08-09 오후 9 09 09" src="https://github.com/ChangJin-Lee/ChangJin-Lee/assets/54494793/fbb72652-4328-4c63-8850-e9328b855112">

- 게임 모드에 디폴트 폰을 설정하기

- 게임에서 해당 폰이 스폰 됨

<img width="524" alt="스크린샷 2023-08-09 오후 9 08 15" src="https://github.com/ChangJin-Lee/ChangJin-Lee/assets/54494793/6afd7843-e727-4392-b6fb-739877320b79">

<img width="513" alt="스크린샷 2023-08-09 오후 9 05 10" src="https://github.com/ChangJin-Lee/ChangJin-Lee/assets/54494793/c8cf841c-b393-4396-ae08-c2b06df1c505">
