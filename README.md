# LiDAR High-Intensity Filter (ROS 2 & PCL)
높은 intensity 값을 가진 포인트를 필터링 해주는 프로그램


## 실행 결과

### 1. 원본 환경
실제 도로 환경
<img width="484" alt="Original Image" src="https://github.com/user-attachments/assets/38cb28ce-0219-46c0-b198-5f53990fe784" />

### 2. 데이터 비교 (RViz2)
왼쪽은 모든 포인트가 포함된 원본 데이터이며, 오른쪽은 High-Intensity Filter가 적용된 결과

| 원본 포인트클라우드 (Raw Data) | 필터링된 결과 (High Intensity Only) |
| :---: | :---: |
| <img width="500" alt="Raw PCL" src="https://github.com/user-attachments/assets/67701ee0-0052-4d75-bf0d-937a341b5a80" /> | <img width="500" alt="Filtered PCL" src="https://github.com/user-attachments/assets/0e1c30bc-08cb-451e-8188-ac7dcb003349" /> |

중앙분리대, 표지판, 자동차 이외의 저반사 객체가 필터링된 결과를 확인할 수 있음.
