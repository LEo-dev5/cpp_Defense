FROM gcc:13.2 AS builder
RUN apt-get update && apt-get install -y libeigen3-dev
WORKDIR /app
COPY . .
# 실행 파일 이름을 'moving_drift'으로 명확히 바꿉니다.
RUN g++ moving_drift.cpp -o moving_drift -I /usr/include/eigen3 -static-libstdc++ -static-libgcc

FROM debian:bookworm-slim
WORKDIR /app
COPY --from=builder /app/moving_drift .
CMD ["./moving_drift"]