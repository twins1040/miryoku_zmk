#!/usr/bin/env bash
# 현재 브랜치를 GitHub Actions 로 빌드하고, 좌/우 순서로 부트로더 볼륨을 기다려 플래시한다.
#   scripts/flash.sh            빌드 + 플래시
#   scripts/flash.sh --no-build 받아 둔 build_artifacts/*.uf2 로 플래시만
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
FIRMWARE_DIR="$ROOT/build_artifacts"
VOLUME="${BOOTLOADER_VOLUME:-/Volumes/NICENANO}"
WORKFLOW="my"

build() {
    cd "$ROOT"
    if [[ -n "$(git status --porcelain --untracked-files=no)" ]]; then
        echo "커밋되지 않은 변경이 있습니다. 커밋 후 다시 실행하세요." >&2
        exit 1
    fi

    local branch
    branch="$(git rev-parse --abbrev-ref HEAD)"
    echo "[build] $branch 푸시 및 워크플로 실행"
    git push origin "$branch"
    gh workflow run "$WORKFLOW" --ref "$branch"

    local run_id=""
    until [[ -n "$run_id" ]]; do
        sleep 3
        run_id="$(gh run list --workflow "$WORKFLOW" --branch "$branch" --limit 1 \
            --json databaseId,status --jq '.[] | select(.status != "completed") | .databaseId')"
    done
    gh run watch "$run_id" --exit-status

    local dir
    dir="$(mktemp -d)"
    gh run download "$run_id" -D "$dir"
    mkdir -p "$FIRMWARE_DIR"
    for side in left right; do
        cp "$dir"/*corne_"${side}"_*/zmk.uf2 "$FIRMWARE_DIR/corne_${side}.uf2"
    done
    rm -rf "$dir"
}

flash_side() {
    local side="$1"
    local uf2="$FIRMWARE_DIR/corne_${side}.uf2"
    [[ -f "$uf2" ]] || { echo "없음: $uf2" >&2; exit 1; }

    echo "[$side] USB 연결 후 부트로더 모드 진입 대기..."
    while [[ ! -d "$VOLUME" ]]; do sleep 0.5; done

    echo "[$side] 플래시 중..."
    cp "$uf2" "$VOLUME/" 2>/dev/null || true
    while [[ -d "$VOLUME" ]]; do sleep 0.5; done
    echo "[$side] 완료"
}

[[ "${1:-}" == "--no-build" ]] || build
flash_side left
flash_side right
echo "모두 완료"
