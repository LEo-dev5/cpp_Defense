FROM gcc:13.2 AS builder
RUN apt-get update && apt-get install -y libeigen3-dev
WORKDIR /app
COPY . .
# 실행 파일 이름을 'landmark_obs_app'으로 명확히 바꿉니다.
RUN g++ multi_landmark.cpp -o multi_landmark_app -I /usr/include/eigen3 -static-libstdc++ -static-libgcc

FROM debian:bookworm-slim
WORKDIR /app
COPY --from=builder /app/multi_landmark_app .
CMD ["./multi_landmark_app"]