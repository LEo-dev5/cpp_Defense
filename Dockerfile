FROM gcc:13.2 AS builder
RUN apt-get update && apt-get install -y libeigen3-dev
WORKDIR /app
COPY . .
# 실행 파일 이름을 'vector_landmarks'으로 명확히 바꿉니다.
RUN g++ vector_landmarks.cpp -o vector_landmarks -I /usr/include/eigen3 -static-libstdc++ -static-libgcc

FROM debian:bookworm-slim
WORKDIR /app
COPY --from=builder /app/vector_landmarks .
CMD ["./vector_landmarks"]