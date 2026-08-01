param(
    [string]$Message = ""
)

# 检查是否有改动
$status = git status --porcelain
if (-not $status) {
    Write-Host "No changes to commit" -ForegroundColor Yellow
    exit 0
}

# 生成提交说明
if ([string]::IsNullOrWhiteSpace($Message)) {
    $date = Get-Date -Format "yyyy-MM-dd"
    $Message = "Update algorithm practice - $date"
}

# 提交
git add .
git commit -m $Message

# 推送（失败自动重试3次）
$retry = 0
$maxRetry = 3
while ($retry -lt $maxRetry) {
    git push origin main 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Host "Push succeeded!" -ForegroundColor Green
        exit 0
    }
    $retry++
    if ($retry -lt $maxRetry) {
        Write-Host "Push failed, retry $retry..." -ForegroundColor Yellow
        Start-Sleep -Seconds 5
    }
}

Write-Host "Push failed, please run manually: git push origin main" -ForegroundColor Red