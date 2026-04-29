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

# Edit the compiler path in .vscode/settings.json if gcc is not available on PATH.
& $CompilerPath -fdiagnostics-color=always -g @sourceFiles -o (Join-Path $workspaceRoot 'main.exe')