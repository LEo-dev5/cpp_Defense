# 1단계: 빌드 환경 (버전을 명시한 debian 사용)
FROM gcc:13.2 AS builder
COPY . /app
WORKDIR /app
# 정적 빌드를 하면 라이브러리 의존성 문제를 피할 수 있어 방산에서 선호하기도 합니다.
RUN g++ -o hello_defense main.cpp -static-libstdc++ -static-libgcc

# 2단계: 실행 환경 (빌드 환경과 같은 계열의 최신 데비안 사용)
FROM debian:bookworm-slim
WORKDIR /app
COPY --from=builder /app/hello_defense .
CMD ["./hello_defense"]