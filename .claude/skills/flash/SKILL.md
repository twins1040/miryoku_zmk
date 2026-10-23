---
name: flash
description: Corne 펌웨어를 GitHub Actions 로 빌드하고 좌/우 순서로 플래시한다. 사용자가 "플래시", "펌웨어 올려줘", "빌드해서 플래시" 라고 할 때 사용.
---

# Corne 플래시

`scripts/flash.sh` 하나로 빌드부터 플래시까지 진행한다. 부트로더 진입을 사용자가 직접 해야 하므로 Claude 가 실행하지 않고, 사용자 터미널에서 돌리도록 안내한다.

```bash
scripts/flash.sh
```

흐름:
1. 현재 브랜치 푸시 → `my` 워크플로 실행 → 완료 대기 → uf2 를 `build_artifacts/corne_{left,right}.uf2` 로 저장
2. 왼쪽 USB 연결 + 부트로더 진입 → 자동 플래시
3. 오른쪽 반복

## 전제

- 커밋되지 않은 변경이 있으면 스크립트가 중단된다. 먼저 커밋을 안내한다.
- 스크립트가 `git push` 를 하므로, 푸시해도 되는지 사용자에게 먼저 확인한다.
- 이미 받아 둔 uf2 만 쓸 때는 `scripts/flash.sh --no-build`.

## 부트로더 진입

- 왼쪽: BASE 에서 `Z+X+C` 콤보
- 오른쪽: NUM 레이어(BSPC 엄지 홀드) 오른쪽 위 끝 키
- 공통: 리셋 버튼 더블탭
