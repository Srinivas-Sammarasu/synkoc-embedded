# Bug log

## A3 — incorrect moving-average divisor

- **Bug:** Average calculation produced an incorrect value.
- **Cause:** The starter divided the sum by a fixed 5 even when fewer than five samples were stored.
- **Fix:** Changed `avg = sum / 5` to `avg = sum / count`.
- **Commit:** Replace with the actual Git commit hash before submission.
