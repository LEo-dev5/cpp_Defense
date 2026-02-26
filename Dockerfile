# 1단계: 빌드 환경
FROM gcc:13.2 AS builder

# [중요] 여기에 넣으세요! 
# 코드를 복사하기 전에 환경을 먼저 구축합니다.
RUN apt-get update && apt-get install -y libeigen3-dev

WORKDIR /app

# 이후에 코드를 복사합니다.
COPY . .

# 빌드 시 Eigen 헤더 위치를 알려주기 위해 -I /usr/include/eigen3 를 추가해야 할 수도 있습니다.
RUN g++ -o defense_monitor while_for.cpp -static-libstdc++ -static-libgcc -I /usr/include/eigen3

# 2단계: 실행 환경
FROM debian:bookworm-slim
WORKDIR /app

# 빌드 단계에서 생성된 바이너리 파일만 쏙 가져옵니다 (보안 및 용량 이점)
COPY --from=builder /app/defense_monitor .

# 실행 명령어 수정
CMD ["./defense_monitor"]