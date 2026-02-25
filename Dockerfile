# 1단계: 빌드 환경
FROM gcc:13.2 AS builder

# 컨테이너 내부의 작업 디렉토리를 /app으로 설정
WORKDIR /app

# 현재 내 맥북의 c++_DEFENSE 폴더에 있는 모든 파일을 컨테이너 안의 /app으로 복사
COPY . .

# [수정포인트] main.cpp 대신 while_for.cpp를 빌드합니다.
# 출력물 이름도 프로젝트 성격에 맞춰 'defense_monitor'로 바꿔보겠습니다.
RUN g++ -o defense_monitor while_for.cpp -static-libstdc++ -static-libgcc

# 2단계: 실행 환경 (용량 최적화)
FROM debian:bookworm-slim
WORKDIR /app

# 빌드 단계에서 생성된 바이너리 파일만 쏙 가져옵니다 (보안 및 용량 이점)
COPY --from=builder /app/defense_monitor .

# 실행 명령어 수정
CMD ["./defense_monitor"]