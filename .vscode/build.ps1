param(
    [string]$CompilerPath = 'gcc'
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$workspaceRoot = Split-Path -Parent $PSScriptRoot
$sourceFiles = Get-ChildItem -Path $workspaceRoot -Recurse -Filter *.c |
    Sort-Object FullName |
    ForEach-Object { $_.FullName }

if (-not $sourceFiles) {
    throw 'No C source files were found to build.'
}

# If CompilerPath is empty or whitespace, fall back to 'gcc' so users with gcc/g++
# on PATH don't need to edit settings.
if ([string]::IsNullOrWhiteSpace($CompilerPath)) {
    Write-Host "chess.compilerPath not set; falling back to 'gcc' on PATH"
    $CompilerPath = 'gcc'
}

Write-Host "Compiling with: $CompilerPath"
Write-Host "Source files:"
$sourceFiles | ForEach-Object { Write-Host "  $_" }

# Ensure we don't accidentally run an old binary: remove existing exe before compiling.
$exePath = Join-Path $workspaceRoot 'main.exe'
if (Test-Path $exePath) {
    Write-Host "Removing existing executable: $exePath"
    Remove-Item $exePath -Force -ErrorAction SilentlyContinue
}

# Edit the compiler path in .vscode/settings.json if a full path is required.
& $CompilerPath -fdiagnostics-color=always -g @sourceFiles -o $exePath

if (Test-Path $exePath) {
    $info = Get-Item $exePath
    Write-Host "Built: $($info.FullName) — $($info.Length) bytes — $($info.LastWriteTime)"
} else {
    Write-Host 'Build failed: main.exe was not created.'
    exit 1
}