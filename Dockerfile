# 1단계: 빌드 환경
FROM gcc:13.2 AS builder

RUN apt-get update && apt-get install -y libeigen3-dev

WORKDIR /app
COPY . .

# [수정] radar_test.cpp 대신 실제 존재하는 rader_test_app.cpp 로 변경
RUN g++ -o radar_app rader_test_app.cpp -static-libstdc++ -static-libgcc -I /usr/include/eigen3

# 2단계: 실행 환경
FROM debian:bookworm-slim
WORKDIR /app

# [수정] 실행 파일 이름을 radar_app으로 통일해서 가져옵니다.
COPY --from=builder /app/radar_app .

CMD ["./radar_app"]