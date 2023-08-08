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