# 1단계: 빌드 환경 (공장이 있는 가방)
FROM gcc:13.2 AS builder

# 1. Eigen 라이브러리를 가방에 넣습니다 (가장 중요!)
RUN apt-get update && apt-get install -y libeigen3-dev

WORKDIR /app
COPY . .

# 2. 빌드 명령: 이제 eigen_transform.cpp를 빌드하라고 시킵니다.
# -I /usr/include/eigen3 옵션은 "Eigen 부품을 여기서 찾아라"라는 뜻입니다.
# 수정된 빌드 명령어
RUN g++ -I /usr/include/eigen3 eigen_transform.cpp -o eigen_app -static-libstdc++ -static-libgcc

# 2단계: 실행 환경 (가벼운 가방으로 옮기기)
FROM debian:bookworm-slim
WORKDIR /app

# 위에서 만든 완성품(eigen_app)만 쏙 가져옵니다.
COPY --from=builder /app/eigen_app .

# 3. 가방을 열자마자 실행할 명령
CMD ["./eigen_app"]