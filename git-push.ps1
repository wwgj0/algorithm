<#
.SYNOPSIS
    算法练习 - 一键提交推送脚本
.USAGE
    .\git-push.ps1 "提交说明"
    .\git-push.ps1              # 不带说明则自动生成
#>

param(
    [string]$Message = ""
)

$repo = "d:\练习算法"

Set-Location $repo

# 检查是否有改动
$status = git status --porcelain
if (-not $status) {
    Write-Host "没有需要提交的改动" -ForegroundColor Yellow
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
        Write-Host "推送成功！" -ForegroundColor Green
        exit 0
    }
    $retry++
    if ($retry -lt $maxRetry) {
        Write-Host "推送失败，第 $retry 次重试..." -ForegroundColor Yellow
        Start-Sleep -Seconds 5
    }
}

Write-Host "推送失败，请检查网络后手动执行: git push origin main" -ForegroundColor Red
