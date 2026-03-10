FROM gcc:13.2 AS builder
RUN apt-get update && apt-get install -y libeigen3-dev
WORKDIR /app
COPY . .
# 실행 파일 이름을 'filter_update_app'으로 명확히 바꿉니다.
RUN g++ slam_loop.cpp -o slam_loop_app -I /usr/include/eigen3 -static-libstdc++ -static-libgcc

FROM debian:bookworm-slim
WORKDIR /app
COPY --from=builder /app/slam_loop_app .
CMD ["./slam_loop_app"]