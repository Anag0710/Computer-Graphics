<# build_all.ps1
   Build all C examples in the examples/ folder using gcc + freeglut.
   Run from the project root (PowerShell):
       .\build_all.ps1
#>
Write-Host "Building all examples in examples/ ..."
$examples = Get-ChildItem -Path .\examples -Filter *.c -Recurse
foreach ($f in $examples) {
    $src = $f.FullName
    $exe = Join-Path $f.DirectoryName ([IO.Path]::GetFileNameWithoutExtension($f.Name) + ".exe")
    Write-Host "Compiling $($f.Name) -> $exe"
    $cmd = "gcc `"$src`" -o `"$exe`" -lfreeglut -lopengl32 -lglu32"
    $out = & cmd /c $cmd 2>&1
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Build failed for $($f.Name):" -ForegroundColor Red
        Write-Host $out
    } else {
        Write-Host "Built $exe" -ForegroundColor Green
    }
}
Write-Host "Done. Executables are located next to their sources in examples/." 
