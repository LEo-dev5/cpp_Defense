FROM gcc:13.2 AS builder
RUN apt-get update && apt-get install -y libeigen3-dev
WORKDIR /app
COPY . .
# 실행 파일 이름을 'drift_app'으로 명확히 바꿉니다.
RUN g++ moving_drift.cpp -o drift_app -I /usr/include/eigen3 -static-libstdc++ -static-libgcc

FROM debian:bookworm-slim
WORKDIR /app
COPY --from=builder /app/drift_app .
CMD ["./drift_app"]