#!/bin/bash
# RPN tester — usage: ./test_rpn.sh [path_to_binary]   (default: ./RPN)
#
# - "ok" tests:   stdout must be exactly the expected number.
# - "err" tests:  output (stdout or stderr) must contain "Error" (any case).
# - "info" tests: design-dependent; output is shown, never counted as a failure.
# A crash (segfault, floating point exception...) is always reported as a failure.

BIN="${1:-./RPN}"
PASS=0
FAIL=0
GREEN="\033[32m"; RED="\033[31m"; YELLOW="\033[33m"; BOLD="\033[1m"; RESET="\033[0m"

if [ ! -x "$BIN" ]; then
    echo "Binary '$BIN' not found or not executable"
    exit 1
fi

section() { printf "\n${BOLD}== %s ==${RESET}\n" "$1"; }

# run <args...> -> sets OUT, ERR, CODE
run() {
    local tmp_out tmp_err
    tmp_out=$(mktemp); tmp_err=$(mktemp)
    timeout 5 "$BIN" "$@" >"$tmp_out" 2>"$tmp_err"
    CODE=$?
    OUT=$(cat "$tmp_out"); ERR=$(cat "$tmp_err")
    rm -f "$tmp_out" "$tmp_err"
}

crashed() { [ "$CODE" -ge 124 ]; }   # 124 = timeout, >=128 = killed by a signal

pass() { PASS=$((PASS + 1)); printf "${GREEN}[OK]${RESET}   %s\n" "$1"; }
fail() { FAIL=$((FAIL + 1)); printf "${RED}[FAIL]${RESET} %s\n       %s\n" "$1" "$2"; }

ok() {
    local expr="$1" expected="$2"
    run "$expr"
    if crashed; then
        fail "\"$expr\"" "crashed/timed out (exit code $CODE), expected $expected"
    elif [ "$OUT" = "$expected" ]; then
        pass "\"$expr\" -> $expected"
    else
        fail "\"$expr\"" "expected '$expected', got stdout='$OUT' stderr='$ERR'"
    fi
}

err() {
    local expr="$1"
    run "$expr"
    if crashed; then
        fail "\"$expr\"" "crashed/timed out (exit code $CODE), expected an Error message"
    elif printf "%s\n%s" "$OUT" "$ERR" | grep -qi "error"; then
        pass "\"$expr\" -> Error"
    else
        fail "\"$expr\"" "expected Error, got stdout='$OUT' stderr='$ERR'"
    fi
}

info() {
    local expr="$1" note="$2"
    run "$expr"
    if crashed; then
        fail "\"$expr\"" "crashed/timed out (exit code $CODE) — must never crash"
    else
        printf "${YELLOW}[INFO]${RESET} \"%s\" -> stdout='%s' stderr='%s'   (%s)\n" "$expr" "$OUT" "$ERR" "$note"
    fi
}

# ---------------------------------------------------------------------------
section "Subject examples"
ok  "8 9 * 9 - 9 - 9 - 4 - 1 +" 42
ok  "7 7 * 7 -" 42
ok  "1 2 * 2 / 2 * 2 4 - +" 0
err "(1 + 1)"

section "Single operations"
ok "1 1 +" 2
ok "9 9 +" 18
ok "0 0 +" 0
ok "5 3 -" 2
ok "9 9 -" 0
ok "0 9 -" -9
ok "3 4 *" 12
ok "9 9 *" 81
ok "0 9 *" 0
ok "9 0 *" 0
ok "8 2 /" 4
ok "9 3 /" 3
ok "0 5 /" 0
ok "9 1 /" 9

section "Operand order (left op right)"
ok "9 1 -" 8
ok "1 9 -" -8
ok "8 2 /" 4
ok "2 8 /" 0
ok "6 3 /" 2
ok "3 6 /" 0

section "Integer division (truncates toward zero)"
ok "7 2 /" 3
ok "9 4 /" 2
ok "1 3 /" 0
ok "0 7 - 2 /" -3
ok "0 9 - 4 /" -2
ok "7 0 2 - /" -3
ok "0 7 - 0 2 - /" 3

section "Single number"
ok "5" 5
ok "0" 0
ok "9" 9

section "Deep stack (many values waiting)"
ok "1 2 3 4 + + +" 10
ok "1 2 3 4 5 6 7 8 9 + + + + + + + +" 45
ok "9 8 7 6 5 4 3 2 1 * * * * * * * *" 362880
ok "1 2 3 4 - - -" -2
ok "9 8 7 6 - - -" 2
ok "8 4 2 / /" 4
ok "1 1 1 1 1 1 1 1 1 + + + + + + + +" 9
ok "2 3 4 5 * * *" 120
ok "9 1 2 3 4 + + + -" -1

section "Mixed expressions"
ok "3 4 + 2 *" 14
ok "2 3 4 * +" 14
ok "2 3 + 4 *" 20
ok "5 1 2 + 4 * + 3 -" 14
ok "4 2 + 3 5 1 - * +" 18
ok "9 2 * 3 / 4 +" 10
ok "1 2 + 3 4 + *" 21
ok "9 9 * 9 9 * -" 0
ok "9 8 - 7 6 - *" 1
ok "5 9 8 + 4 6 * * 7 + *" 2075
ok "2 2 2 2 2 * * * * 1 -" 31
ok "9 3 / 3 / 1 -" 0
ok "0 1 - 0 1 - *" 1
ok "0 1 - 0 1 - 0 1 - * *" -1

section "Large but valid results (fit in int)"
ok "9 9 * 9 * 9 * 9 * 9 * 9 * 9 *" 43046721
ok "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" 387420489
ok "0 9 - 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" -387420489
ok "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 5 *" 1937102445

section "Division by zero"
err "1 0 /"
err "0 0 /"
err "9 5 5 - /"
err "1 2 + 3 3 - /"

section "Not enough operands"
err "+"
err "-"
err "*"
err "/"
err "1 +"
err "+ 1"
err "+ 1 1"
err "1 + 1"
err "1 2 + +"
err "1 2 * *"
err "1 2 3 + + +"

section "Too many operands (more than one value left)"
err "1 2"
err "1 2 3"
err "1 2 3 +"
err "1 2 + 3"
err "9 8 7 6 5 + + +"

section "Empty / blank input"
err ""
err " "
err "     "

section "Invalid characters and tokens"
err "1 a +"
err "a"
err "1 2 %"
err "1 2 ^"
err "1.5 2 +"
err "1,2 +"
err "1 2 x"
err "1 2 = "
err "[1 2 +]"
err "1 2 +a"

section "Numbers >= 10 and negative literals (input must be single digits)"
err "10 1 +"
err "12 3 +"
err "1 99 +"
err "-1 2 +"
err "1 -2 +"

section "Tokens not separated by spaces"
err "12+"
err "1 2+"
err "1 2 ++"
err "1 2 +3"
err "1 2 3 *+"

section "Overflow (your design: result outside int must be Error)"
err "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
err "0 9 - 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
err "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 6 *"
err "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 5 * 9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * +"
err "0 9 - 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 5 * 9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * -"

# ---------------------------------------------------------------------------
section "Argument count"
run
if crashed; then fail "no argument" "crashed (exit code $CODE)"
elif printf "%s\n%s" "$OUT" "$ERR" | grep -qi "error"; then pass "no argument -> Error"
else fail "no argument" "expected Error, got stdout='$OUT' stderr='$ERR'"; fi

run "1 1 +" "2 2 +"
if crashed; then fail "two arguments" "crashed (exit code $CODE)"
elif printf "%s\n%s" "$OUT" "$ERR" | grep -qi "error"; then pass "two arguments -> Error"
else fail "two arguments" "expected Error, got stdout='$OUT' stderr='$ERR'"; fi

# ---------------------------------------------------------------------------
section "Design-dependent (shown only, not counted)"
info " 1 2 +"   "leading space: accept (3) or reject, your choice"
info "1 2 + "   "trailing space"
info "1  2 +"   "double space"
info $'1\t2 +'  "tab as separator"
info "0 9 - 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 0 *" "overflow in the middle, final result 0"

# ---------------------------------------------------------------------------
printf "\n${BOLD}Result: ${GREEN}%d passed${RESET}${BOLD}, ${RED}%d failed${RESET}\n" "$PASS" "$FAIL"
[ "$FAIL" -eq 0 ]