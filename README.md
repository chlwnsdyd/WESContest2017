# WESContest2017
임베디드 소프트웨어 경진대회(자율주행부문)

https://www.youtube.com/watch?v=r35-caxBafQ&list=LL9x9HQMdi4q6v4voE_CWk3A&index=5&t=0s
<br>
# 1. SW 구조 <br>
<img width="400" src="https://user-images.githubusercontent.com/38127338/69896912-ced80e00-1387-11ea-981e-bda694e4e0f9.png">
<br>

# 2.사용된 알고리즘에 대한 설명. <br>
1. 차선 인식 및 주행<br>
   1) 직진    - Hough Transform을 사용하여 직진 구간에서 양측 차선을 검출해 낸다. 검출된 직선들의 중간점을 차량이 나아가야할 방향점으로 설정하여 모터를 제어한다.<br>
   2) 곡선    - 최소제곱법을 사용하여 차선의 기울기를 관찰한다. 한쪽 차선의 기울기만 검출되고, 해당 직선의 y절편이 일정 값 이하로 내려간다면 곡선구간이라 인지하고 서보모터를 제어하여 회전을 시작한다.<br>
   3) 2차선    - 영상의 일정 영역 안에서 차선의 개수를 검출하는 알고리즘을 사용한다. 2차선 구간에서는 차선이 양측 차선에 중앙선이 추가되어 있으므로 3개 이상의 차선이 검출되면 2차선이라 인식하고 우측차선에 붙어 차량이 주행할 수 있도록 차량의 진행방향을 설정한다.<br><br>
2. 수평/수직 주차<br>
  - 차량의 sensor 값들을 이용하여 알고리즘 구현.<br>
3. 돌발 장애물 코스<br>
  - 영상에서 빨간색을 검출한다. 전체 화면을 세로 10분할하여 한 줄당 가로 320픽셀 중 40픽셀 이상 빨간색이 검출되면 한 줄이 인식되었다고 판단한다. 총 4개 이상의 줄이 인식되면 장애물이 가까이 있다 판단하고 정지한다.<br>
4. 언덕 주행 코스<br>
  - 차선의 기울기가 증가해 최소제곱법으로 샘플링 시 픽셀 수가 적게 나타난다. 따라서 차선이 2개 검출되었고, 기울기가 직진구간 이상이지만, 픽셀값이 직진구간 이하라면 언덕이라 인식하고 카메라 조절을 통해 주행을 원활히 한다.<br>
5. 회전 교차로<br>
  - 차선이 나타나지 않는 교차로 구간의 특징으로 회전교차로를 인식한다. 인식 후 회전교차로 내부에 주행중인 외부차량과 충돌하지 않도록 적절히 거리 및 속도를 조절하여 코스를 주행한다. <br>주행 중 회전 교차로 탈출 조건에 부합하는 차선이 나타나면 회전교차로를 빠져나오고 해당 미션을 종료한다.<br>
6. 요철 코스<br>
  - 일반 직선구간과 같이 Hough Transform을 사용한 직선 검출을 수행한다. 다만 차량의 흔들림에 의한 차선 샘플링이 고르게 나타나지 않을 수 있으므로 최소제곱법을 사용한 차선검출 또한 같이 사용한다.<br>
7. 차로 추월 구간<br>

8. 신호등 분기점 코스<br>


9. 도착점 정지<br>
바닥 라인센서를 이용한 도착점 인식<br><br>

<img width="1000" src="https://user-images.githubusercontent.com/38127338/69896969-a6044880-1388-11ea-8394-3bd5aed35e27.png">
