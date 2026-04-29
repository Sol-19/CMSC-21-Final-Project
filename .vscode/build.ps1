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

$exePath = Join-Path $workspaceRoot 'main.exe'

 $resolvedCompiler = (Get-Command $CompilerPath).Source
 $compilerDirectory = Split-Path -Parent $resolvedCompiler
 $previousLocation = Get-Location

try {
    if (-not [string]::IsNullOrWhiteSpace($compilerDirectory)) {
        Set-Location $compilerDirectory
    }

    & $resolvedCompiler -fdiagnostics-color=always -g @sourceFiles -o $exePath
}
finally {
    Set-Location $previousLocation
}

if (Test-Path $exePath) {
    $info = Get-Item $exePath
    Write-Host "Built: $($info.FullName) — $($info.Length) bytes — $($info.LastWriteTime)"
} else {
    Write-Host 'Build failed: main.exe was not created.'
    exit 1
}